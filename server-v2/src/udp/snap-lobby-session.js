import {
  FLAG_DATA,
  FLAG_SET,
  FLAG_STRING
} from '../protocol/snap-codec.js';
import { ReliableChannel, ReliableChannelError } from '../transport/reliable-channel.js';
import {
  COMPLETION_SELECTOR,
  LOBBY_OPCODE,
  buildAppKeepalivePayload,
  buildCompletionPayload,
  buildCreateRoomAcceptPayload,
  buildKeepalivePayload,
  buildMemberJoinPayload,
  buildNameQueryReplyPayload,
  buildRoomLimitsPayload,
  buildRoomListPayload,
  buildSuccessTransitionPayload,
  decodeCreateRoomRequest,
  decodeNameQuery,
  decodeMemberListRequest,
  decodeAreaCountRequest,
  decodeNamedChannelRequest,
  buildMemberListPayload,
  buildMemberListCount0Payload,
  buildRosterRecordPayload,
  buildPlayerInfoPayload,
  buildAreaCountReplyPayload,
  buildNamedChannelCompletionPayload,
  resolveRoomHandleBytes,
  AREA_COUNT_TAG_CURRENT,
  AREA_COUNT_TAG_MAXIMUM,
  decodeChatMessage,
  buildChatRelayPayload,
  CHAT_MINIMUM_BODY_BYTES,
  ROOM_ENTER_REQUEST_BYTES,
  ROOM_EVENT_SUB,
  decodeRoomEnterRequest,
  decodeRoomEvent,
  buildJoinConfirmPayload
} from './snap-lobby-codec.js';

/**
 * ONE client's post-selection SN@P session: the phase between the 566-byte bind
 * and a visible, surviving in-area lobby.
 *
 * ## What owns what
 *
 * This object owns exactly two things and can prove it. A `ReliableChannel`,
 * which owns the retransmit and gap timers under its OWN wheel-owner identity,
 * and one keepalive timer under this session's. `close()` releases both and
 * `assertDrained()` makes the wheel say so, which is how a teardown demonstrates
 * it leaked nothing rather than a reviewer having to notice.
 *
 * ## Identity is NOT the source address
 *
 * `loginIdentity` and `attachment` are handed in from the registration the
 * attachment nonce resolved (`udp/registration-nonces.js`). Nothing in this
 * phase carries a credential - the endpoint token is `(octet3 << 24) |
 * (octet4 << 16) | port` of the client's own LAN address, a routing hint anyone
 * behind the same two octets reproduces - so the address and port here are
 * transport addressing and are never consulted to decide WHO this is.
 *
 * ## The 840 watchdog, and the only thing that feeds it
 *
 * `conn+0x51c` is armed at `LC * 32 + 4000` ms and refreshed by exactly one
 * message: an inbound op-0x40, whose handler's first instruction is
 * `*(conn+0x7c) = *(conn+0x4fc)` (`FUN_001d9b6c`). Nothing else in the protocol
 * touches it. On expiry `FUN_001d94b0` pushes slot 0x1c with tag 0x27 and status
 * 0x14, and `0x14 + 0x334` is the number the player sees: **840**. So the
 * keepalive timer below is not a nicety; it is the entire difference between a
 * session that survives and every run this project has made so far.
 *
 * ## What used to be deliberately NOT here (SUPERSEDED 2026-08-08, RS1-B §4)
 *
 * V1 also sent a 296-byte op-0x28 selector-0x0a "member list" alongside the
 * op-0x0c completion (`game_udp_server.js`, archive OUT #12). The gap table
 * graded it "not proven required" - the completion alone advances the state
 * machine - and it was left out rather than copied on faith. RS1 then showed
 * what it was FOR: it is half of the member-info supply channel, and without
 * it (plus the op-0x10 sub-1 pushes) both RS1 consoles starved - the joiner
 * at "Getting information", the host in its own freshly created room. It is
 * back behind `SNAP_MEMBER_INFO` (config default ON), ported from the July
 * bytes; `memberInfo = false` restores the leave-it-out behaviour.
 */

/** Named reasons a session refused to do something. Never thrown at a peer. */
export const LOBBY_SESSION_REFUSAL = Object.freeze({
  CLOSED: 'the lobby session is closed',
  SEND_REFUSED: 'the reliable channel refused the send',
  UNHANDLED_OPCODE: 'no handler for this opcode in the post-selection phase',
  CREATE_WITHOUT_AREA: 'a room cannot be created from outside an area',
  CREATE_REFUSED: 'the room registry refused to open the room'
});

/**
 * The default room capacity when the create request does not settle one.
 *
 * FOUR, because the client's own roster table is four entries of `0x118` at
 * `0x6cdbe6` and its member counter `0x6cfb62` is capped at 4 - so a room this
 * server admitted a fifth player to would have a member the client cannot render.
 * The request's `+0x10` is Likely a ceiling but is not Confirmed as one
 * (`CORRECTIONS.md` C-4), so it is logged and NOT used to size the room.
 */
export const DEFAULT_ROOM_CAPACITY = 4;

/**
 * The name a created room carries when the request's title field is empty.
 *
 * It is empty in every run so far: `0x6CC01A` never received the typed title, and
 * whether that is a separate client bug or a consequence of `0x6ff2b1 = 0` is
 * Unknown. An empty name would render a blank row in the op-0x49 list, which is
 * indistinguishable from a broken list, so a stated placeholder ships instead of
 * a blank. Configurable, because it is content.
 */
export const DEFAULT_ROOM_NAME = 'ROOM';

/** Why an op-0x0c arrived. Both are answered; see `#classifyRoomQuery`. */
export const ROOM_QUERY_PURPOSE = Object.freeze({
  CONNECT_SCREEN: 'connect-screen',
  CREATE_PREPARE: 'create-prepare'
});

/** The archive's `a1 00 00 0c` is 260 bytes total, so 244 of payload. */
const CONNECT_SCREEN_ROOM_QUERY_PAYLOAD_BYTES = 260 - 16;

export class SnapLobbySessionError extends Error {
  constructor(code, message) {
    super(message);
    this.name = 'SnapLobbySessionError';
    this.code = code;
  }
}

function fail(code, message) {
  throw new SnapLobbySessionError(code, message);
}

/**
 * V1's period, and the only one with evidence behind it: the archive shows a
 * 5-second cadence sustained across 27 000 datagrams with an op-0x41 answer to
 * every one. Nothing shorter has ever been run (gap table U7). It is a default,
 * not a constant - the caller may set it, and the budget check below bounds what
 * it may set it to.
 */
export const DEFAULT_KEEPALIVE_PERIOD_MS = 5_000;

/**
 * The SN@P APPLICATION keepalive cadence (flag `SNAP_APP_KEEPALIVE`).
 *
 * A SECOND watchdog, not op-0x40's. The lobby overlay arms an
 * application-liveness watchdog at session establish (`FUN_005bdc70` sets
 * `cRam006febde`; the handler slot 0x13 it feeds through is installed at the
 * same moment by `FUN_005bc860`, so the vehicle below is valid on the lobby
 * floor and in rooms alike). Its budget is server-supplied via op-0x1a and
 * defaults to 1800 idle + 1800 probe-response ticks - ~145.7 s measured, the
 * exact ceiling of every observed voluntary op-0x02 self-close. It is reset by
 * ONE function, `FUN_005c7d00`, which every inbound lobby-overlay APPLICATION
 * message calls - and which op-0x40 never reaches, because op-0x40 is consumed
 * in the main-EE transport (`FUN_001d9b6c`, the 840 watchdog). So a client
 * that stops asking questions dies on schedule however perfect the transport
 * is: that is the ~145 s shot clock under every stall investigation.
 *
 * 30 s is the JP reference server's cadence for exactly this obligation - the
 * unsolicited `HEARTBEAT 0x6202` broadcast (`HeartBeatThread.java:53-55`) -
 * giving ~2.4x margin inside the 72.8 s idle half of the budget. The full
 * contract: `docs/design/v2-port/ROOM-WATCHDOG-RE.md` (commit d7f95db5).
 */
export const APP_KEEPALIVE_PERIOD_MS = 30_000;

/**
 * How much of the client's watchdog budget the keepalive period may consume.
 *
 * Two consecutive lost keepalives must still leave the watchdog unexpired, so
 * the period is required to be at most a third of the budget. With the observed
 * `LC = 1600` the budget is 55 200 ms and the ceiling is 18 400 ms, comfortably
 * above V1's 5 000.
 */
const KEEPALIVE_BUDGET_FRACTION = 3;

/**
 * How long a session may hear nothing before it is released.
 *
 * A client that vanishes - console powered off, cable pulled - sends no
 * shutdown of any kind, and its keepalive is UNRELIABLE, so nothing on the send
 * side ever fails. Without this the session and its 5-second timer outlive the
 * console indefinitely.
 *
 * 120 s is chosen against the CLIENT's own deadlines, not picked round: its
 * register watchdog is `LC*32+4000` = 55.2 s at the observed LC and its app
 * request watchdog is 3600 frames (about 72 s PAL). A client that has been
 * silent for twice the first and well past the second has already failed on its
 * own terms, so releasing it cannot cut short a session that was still working.
 */
export const DEFAULT_IDLE_TIMEOUT_MS = 120_000;

/**
 * How many refused sends OF ONE KIND are absorbed between journal lines.
 *
 * The op-0x48 poll is reply-independent and runs at about 25 Hz, so a full send
 * window turns every one of them into a refusal: the 2026-08-06 review measured
 * 223 warn lines in 12 seconds, about 18 a second, which buries the journal in
 * exactly the window where the cause has to be found. The reply's own docstring
 * already said this path must not log per send; the refusal branch did.
 *
 * The first of each kind is logged in full, then one rollup line per this many
 * with the running count - so nothing is hidden, the rate is bounded by the
 * number of distinct send kinds rather than by the poll, and a rig log still
 * shows the refusals happening rather than a silence. A COUNT rather than a time
 * window because a count is deterministic in tests and needs no clock here.
 */
const REFUSAL_LOG_INTERVAL = 100;

export class SnapLobbySession {
  #routingKey;
  #loginIdentity;
  #attachment;
  #endpointToken;
  #reliableWindow;

  #wheel;
  #channel;
  #logger;

  #areaDirectory;
  #playerCountFor;
  #roomListProvider;
  #relayChat;
  #relayGameBeacon;
  #gameRelay;
  #relayGameChannel;
  #gameBeaconEcho;
  #gameBeaconRelay;
  #exitCloseMirror;
  #onClientClose;
  #completionSeqEcho;
  #channelBitEcho;
  #joinLadder;
  #op10Relay;
  #op0aCount0;
  #memberInfo;
  #roomFlagsPublish;
  #roomStat;
  #memberIdToken;
  #rosterToJoiner;
  #hostReseat;
  #countPush;
  #pushAreaCount;
  #roomLifecycle;
  #slotAllocator;
  #broadcast;
  #relayRoomEvent;
  #onGameStart;

  #keepalivePayload;
  #keepalivePeriodMs;
  #watchdogBudgetMs;
  #keepaliveHandle = null;
  #keepalivesSent = 0;
  #keepaliveResponses = 0;

  #appKeepalive;
  #appKeepaliveHandle = null;
  #appKeepalivesSent = 0;

  #successTransitionEnabled;
  #successTransitionSent = false;

  #idleTimeoutMs;
  #idleHandle = null;
  #datagramsSinceIdleArm = 0;
  #onIdle;

  #nameQueryReplies = 0;
  /** In-game beacons consumed. A rig statistic: T37 carried 115 in one session. */
  #gameBeacons = 0;
  /** Reliable game-channel op-0x0F frames consumed (0x0400 clear; RS1-A §2). */
  #gameChannelFrames = 0;
  /** Refused sends per event name. The key of the rollup, and a rig statistic. */
  #sendRefusals = new Map();
  #closed = false;

  /**
   * WHERE THIS PLAYER IS - the presence registry and this session's record in it.
   *
   * `#enteredBoxId` used to live here: a location field on the session, written
   * only when an op-0x06 ENTER resolved. That is the right rule for the op-0x48
   * per-area count and wrong as a presence model, because four of the six places
   * the protocol asks for a count ask from a SHALLOWER depth and an EARLIER time
   * (`analysis/PRESENCE-AND-COUNTS-DESIGN.md` section 1.3). Location now lives in
   * exactly one place, at whatever depth the session has actually reached, and
   * everything else is a query over it.
   */
  #presence;
  #presenceRecord;

  #rooms;
  #roomName;
  #roomCapacity;
  /** The room this session created, if any. Diagnostics and the follow-up pushes. */
  #createdRoom = null;

  constructor({
    routingKey,
    loginIdentity,
    attachment = null,
    endpointToken,
    wheel,
    transmit,
    areaDirectory,
    /*
     * REQUIRED, both of them, and deliberately without the `() => 0` / `() => []`
     * defaults they used to carry. Those defaults were what production ran on:
     * `SnapLobbySessions` was constructed without either, so op-0x48 published 0
     * players in every area and op-0x49 reported no rooms - not because that was
     * the state, but because nobody had wired the state. A missing seam now
     * refuses to construct a session instead of quietly publishing zeros.
     */
    playerCountFor,
    roomListProvider,
    relayChat = null,
    /*
     * THE BEACON EXPERIMENT (PORT-PLAN slice 2c-ii), both defaulting OFF.
     *
     * What the in-game beacon expects is Unknown; the JP reference's game server
     * was a dumb same-gamenumber relay, but solo JP relays nothing and PAL solo
     * still beacons - so a server ECHO is the live hypothesis and a room-scoped
     * RELAY is its 2-player sibling. Each is one rig flag flip to test and one
     * to retire; neither is reachable unless the composer turns it on.
     */
    gameBeaconEcho = false,
    gameBeaconRelay = false,
    /** The beacon fan-out seam, like `relayChat`. Only consulted when relaying. */
    relayGameBeacon = null,
    /*
     * SNAP_GAME_RELAY (2026-08-24): relay reliable game-channel op-0x0F
     * packets to the sender's room, except the sender - the bioserver
     * gameserver default-branch, openSNAP's game-packet model, and the fix for
     * the joiner starving at "Game to begin shortly" while the in-game host
     * pumps state. Session default OFF like every flag here.
     */
    gameRelay = false,
    /** The game-packet fan-out seam, like `relayChat`. */
    relayGameChannel = null,
    /*
     * B3 FIX 1 (PORT-PLAN slice 3), default OFF: answer the client's op-0x02
     * close by mirroring it back and releasing this session. The exit-contract
     * RE says the 0xb000 close is a bidirectional handshake the dispatcher
     * mirrors; what exact confirm shape writes the client's `0x6cbbe0 := 2` is
     * still needs-decompile (gap G1), hence the flag.
     */
    exitCloseMirror = false,
    /** Called after the mirrored close leaves, so the owner releases this session. */
    onClientClose = null,
    /*
     * B3 FIX 2 (PORT-PLAN slice 3), default OFF: extend the op-0x28 sel-6 and
     * sel-7 completion payloads from 8 to 0x10 bytes with the request's
     * send-seq echoed at +0xc - the only observed deviation from the RE'd
     * reply contract in the whole first-leave exchange (B3 doc §3). Off, the
     * builders emit byte-identical output: sel-6 is the rig-confirmed ENTER
     * accept and must not move without a flag.
     */
    completionSeqEcho = false,
    /*
     * C3 FIX (SESSION-LOG-2026-08-24 T1/T2), default OFF: the sel-7 LEAVE and
     * sel-8 STAT completions echo the REQUEST's DATA bit (0x1000) instead of
     * always setting it. Grounding: the in-room Exit sends op-0x07/op-0x08 on
     * the ROOM channel (who 0xA0xx, DATA clear — RS1 pcap frame 5185), and the
     * result dispatcher `FUN_001d9f78` case 6 routes BY that bit: DATA set ->
     * slot 0x23 (lobby-leave cb), so a 0xB0xx reply to a 0xA0xx leave fires the
     * wrong completion class and the client parks (the 144.8s park death).
     * The AM SNAP client documents the same &0x1000 split (ResultLeaveRoom vs
     * ResultLeaveLobby — openSNAP commands.py), and V1 answered op-0x07 with
     * BOTH classes (game_udp_server.js:2065, slots 0x23/0x24) — V2 dropped the
     * 0xA0 one. Off = byte-identical today: every rig-confirmed request on
     * these paths arrives with DATA set, so the echo changes nothing for them.
     * Flag `SNAP_CHANNEL_BIT_ECHO`.
     */
    channelBitEcho = false,
    /*
     * THE JOIN LADDER (PORT-PLAN slice 1b), flag `SNAP_JOIN_LADDER`. Session
     * default OFF so a directly constructed session keeps every previous byte;
     * the composed config defaults it ON for the coming rig run. On: the
     * DATA-clear room-ENTER form of op-0x06 routes through the slot-allocator
     * guards, and the op-0x10 app-sub-0x02 join-request is answered with the
     * rig-proven sub-0x0C join-confirm. Every push it adds is individually
     * emitted from a transition, never from a poll.
     */
    joinLadder = false,
    /*
     * The op-0x10 room-scoped relay (PORT-PLAN slice 2a), flag
     * `SNAP_OP10_RELAY`. Relay, never interpret: the payload is forwarded
     * verbatim to the sender's own room, except the sender - chat's scope
     * model. (The recipient-addressed reading of the body words is
     * SUPERSEDED, RS1-B §2: word1 is the sender's own handle.)
     */
    op10Relay = false,
    /*
     * RS1-B fix 1, flag `SNAP_OP0A_COUNT0` (config default ON; class default
     * OFF like every seam here): answer the op-0x0a member-list with July
     * V1's exact 12-byte count-0 body instead of the count-1/zero-blob reply
     * that starved two consoles (H-B, RS1-B §5). OFF keeps the previous
     * reply byte-identical.
     */
    op0aCount0 = false,
    /*
     * RS1-B fix 2, flag `SNAP_MEMBER_INFO` (config default ON; class default
     * OFF): the member-info supply channel V1's golden set ran and V2 lacked
     * (RS1-B §4). Three emissions, all ported from the July rig-validated
     * bytes: the op-28 sel-0x0a roster record alongside every op-0x0c
     * completion; the op-0x10 sub-1 player-info push on join acceptance; and
     * a sub-1 push in ANSWER to every inbound game-channel op-0x10 (V1
     * answered every single one - the client re-sends its op-10 until
     * satisfied, which is tonight's host retransmit signature). This channel
     * is the prime candidate for both the joiner's member-list starve and
     * the host's in-room self-close.
     */
    memberInfo = false,
    /*
     * PORT-PLAN slice 2b's wire half, flag `SNAP_ROOMFLAGS_PUBLISH`, default
     * OFF: surface the engine's authored room status in the op-0x49 record
     * flags word `+0x1c`. EVIDENCE-GATED - no console has ever rendered
     * non-zero flags (B2 doc H-B even suspects zeroed flags gate the join UI),
     * so the engine authors the status regardless and the wire keeps zeros
     * until a rig run shows what the client does with anything else.
     */
    roomFlagsPublish = false,
    /*
     * SNAP_ROOM_STAT (2026-08-24): capture the create optionsWord into the
     * room's op-0x49 +0x1c so joiners decode the host's real scenario
     * (scenario=(STAT>>1)&0xFF) instead of 0=Training. Default OFF.
     */
    roomStat = false,
    /*
     * SNAP_MEMBER_ID_TOKEN (T17): the op-06 record about a member carries the
     * RECIPIENT's endpoint token as memberId, so the host's sub-4 accept scan
     * matches and the 2-player start goes non-solo. Default OFF.
     */
    memberIdToken = false,
    /* SNAP_ROSTER_TO_JOINER (T19/seated-slot RE): op-06 each existing member to the joiner. */
    rosterToJoiner = false,
    /* SNAP_HOST_RESEAT (T20): re-seat the host on join so the start roster counts 2. */
    hostReseat = false,
    /*
     * RS1-C C2, flag `SNAP_COUNT_PUSH` (config default ON; class default OFF):
     * the lobby-header count is latched from ONE op-0x09 USER answer at entry
     * and nothing client-side ever re-queries it, so the other player's leave
     * is invisible until a screen rebuild. The JP server closes exactly this
     * gap with `broadcastAreaPlayerCnt` (PacketHandler.java:661, fired from
     * enter at :746 and exit at :1136). The PAL vehicle is an unsolicited
     * op-0x09 USER reply, grounded in the corpus rather than guessed:
     *
     *   - the entry query is the DATA-set reliable op-0x09 (RS1 wire 0xB018),
     *     whose send (`FUN_001dd840`-shaped) installs its reply cb via
     *     `FUN_001d4d24(1, 0x17, cb)` - a swap into the PERSISTENT conn+0x548
     *     dispatch table, not a per-txn arm;
     *   - dispatcher `FUN_001d9f78` case 6 invokes conn+0x5a4 (slot 0x17) on
     *     EVERY inbound DATA-set op-0x09 and never clears the slot;
     *   - the handler (`FUN_005bf740`) does NO transaction matching: it sweeps
     *     registry-A for reply word0 (`FUN_005bf280`), and on a hit with
     *     tag=='USER' commits word2 to the render struct `0x6ce5de` - so a
     *     push shaped exactly like the solicited answer re-renders the count.
     *
     * The push therefore reuses the solicited answer's bytes verbatim (who
     * 0xB0, `[BE32 area key]['USER'][BE32 count]`) and goes only to sessions
     * whose own presence is in the affected box - each recipient holds that
     * key in its registry-A, so the sweep hits.
     */
    countPush = false,
    /** The sessions table's count-push fan-out; scope from presence, never wire. */
    pushAreaCount = null,
    /*
     * THE APPLICATION KEEPALIVE, flag `SNAP_APP_KEEPALIVE` (config default ON;
     * class default OFF like every seam here): a 30 s op-0x10 who-0xA000 push
     * whose app-payload byte is 0x00 - a pure watchdog reset, because
     * `FUN_005bba20` resets the liveness watchdog unconditionally as its first
     * statement and its sub-selector switch has no default case. This is the
     * G12 fix for the ~145 s voluntary op-0x02 self-close; see
     * `APP_KEEPALIVE_PERIOD_MS` above for the full grounding. OFF = zero
     * pushes, byte-identical to every previous build.
     */
    appKeepalive = false,
    /** The room-status registry (state/room-lifecycle.js). The join guards read it. */
    roomLifecycle = null,
    /** The playernum/guard machine (state/slot-allocator.js). Owns the assignment. */
    slotAllocator = null,
    /** The sessions table's generalized fan-out. Scope from presence sets only. */
    broadcast = null,
    /** The sessions table's op-0x10 room-scoped fan-out (except the sender). */
    relayRoomEvent = null,
    /** Called on the op-0x0D body-1 barrier: the engine's room->BUSY transition. */
    onGameStart = null,
    /*
     * The presence registry and THIS session's record in it, both created by the
     * sessions table at bind-accept. Required together: a session that could hold
     * one without the other would be a session whose location has two possible
     * homes, which is the duplication the presence model exists to remove.
     */
    presence,
    presenceRecord,
    /** The room registry a create opens into. Required: op-0x04 mints into it. */
    rooms,
    roomName = DEFAULT_ROOM_NAME,
    roomCapacity = DEFAULT_ROOM_CAPACITY,
    keepaliveCiphertext,
    keepalivePeriodMs = DEFAULT_KEEPALIVE_PERIOD_MS,
    watchdogBudgetMs = null,
    successTransition = false,
    outboundSequence,
    /*
     * SNAP_RELIABLE_WINDOW (2026-08-25): max unacknowledged reliable messages before
     * the channel refuses (drops). Default 32; raising it makes the in-game
     * game-packet relay lossless for a higher-latency console (real PS2) whose
     * reliable window drains slower - the channel retransmits unacked, so a bigger
     * window queues instead of dropping. Confirmed cause of the ~38% emu->PS2 loss.
     */
    reliableWindow = 32,
    inboundReceiveBase = 0,
    idleTimeoutMs = DEFAULT_IDLE_TIMEOUT_MS,
    onIdle = null,
    logger = null,
    onTransportDead = null
  } = {}) {
    if (typeof routingKey !== 'string' || routingKey.length === 0) {
      fail('ROUTING_KEY_REQUIRED', 'a routing key is required');
    }
    if (typeof loginIdentity !== 'string' || loginIdentity.length === 0) {
      fail('IDENTITY_REQUIRED', 'a lobby session carries the identity its registration proved');
    }
    if (areaDirectory == null || typeof areaDirectory.records !== 'function') {
      fail('AREA_DIRECTORY_REQUIRED', 'an area directory is required to answer op-0x48');
    }
    if (typeof transmit !== 'function') fail('TRANSMIT_REQUIRED', 'transmit is required');
    if (typeof playerCountFor !== 'function') {
      fail('PLAYER_COUNT_REQUIRED', 'playerCountFor is required; op-0x48 must not publish zeros ' +
        'because a seam was left unwired');
    }
    if (relayChat !== null && typeof relayChat !== 'function') {
      fail('RELAY_CHAT_TYPE', 'relayChat must be a function when supplied');
    }
    if (relayGameBeacon !== null && typeof relayGameBeacon !== 'function') {
      fail('RELAY_BEACON_TYPE', 'relayGameBeacon must be a function when supplied');
    }
    if (gameBeaconRelay === true && relayGameBeacon === null) {
      // Asked to relay with nowhere to relay to is a wiring mistake, and a
      // silent no-op here would read on the rig as "the hypothesis failed".
      fail('RELAY_BEACON_UNWIRED', 'gameBeaconRelay needs the relayGameBeacon seam');
    }
    if (onClientClose !== null && typeof onClientClose !== 'function') {
      fail('CLIENT_CLOSE_TYPE', 'onClientClose must be a function when supplied');
    }
    if (exitCloseMirror === true && onClientClose === null) {
      // The fix is mirror AND release; a mirror whose session lives on would
      // collide with the client's own fresh register epoch.
      fail('CLIENT_CLOSE_UNWIRED', 'exitCloseMirror needs the onClientClose seam');
    }
    if (joinLadder === true &&
      (slotAllocator == null || roomLifecycle == null || typeof broadcast !== 'function')) {
      // The ladder without its engine would accept joins nothing accounts for;
      // an unwired flag is a composition mistake, not a degraded mode.
      fail('JOIN_LADDER_UNWIRED', 'joinLadder needs the slotAllocator, roomLifecycle and broadcast seams');
    }
    if (op10Relay === true && typeof relayRoomEvent !== 'function') {
      fail('OP10_RELAY_UNWIRED', 'op10Relay needs the relayRoomEvent seam');
    }
    if (countPush === true && typeof pushAreaCount !== 'function') {
      // A count push with nowhere to fan out would read on the rig as "the
      // push hypothesis failed" when the truth is a composition mistake.
      fail('COUNT_PUSH_UNWIRED', 'countPush needs the pushAreaCount seam');
    }
    if (roomFlagsPublish === true && roomLifecycle == null) {
      fail('ROOMFLAGS_UNWIRED', 'roomFlagsPublish needs the roomLifecycle seam; the status is authored there');
    }
    if (typeof roomListProvider !== 'function') {
      fail('ROOM_LIST_REQUIRED', 'roomListProvider is required; op-0x49 reports held room state');
    }
    if (presence == null || typeof presence.moveTo !== 'function' || presenceRecord == null) {
      fail(
        'PRESENCE_REQUIRED',
        'a lobby session holds a presence from the moment the bind is accepted; without one it ' +
        'is a player who is nowhere and counts towards nothing'
      );
    }
    if (rooms == null || typeof rooms.openFor !== 'function') {
      fail('ROOMS_REQUIRED', 'a room registry is required; op-0x04 mints a handle into it');
    }
    if (!Number.isSafeInteger(roomCapacity) || roomCapacity < 1 || roomCapacity > 0xff) {
      fail('ROOM_CAPACITY', 'roomCapacity must be 1..255');
    }
    if (!Number.isSafeInteger(keepalivePeriodMs) || keepalivePeriodMs < 1) {
      fail('KEEPALIVE_PERIOD', 'keepalivePeriodMs must be a positive whole number');
    }
    if (!Number.isSafeInteger(idleTimeoutMs) || idleTimeoutMs <= keepalivePeriodMs) {
      // Below one keepalive period the session would release itself between the
      // client's own polls, which is a self-inflicted disconnect rather than a
      // bound.
      fail(
        'IDLE_TIMEOUT',
        `idleTimeoutMs must be a whole number above the ${keepalivePeriodMs} ms keepalive period`
      );
    }
    if (watchdogBudgetMs != null) {
      if (!Number.isSafeInteger(watchdogBudgetMs) || watchdogBudgetMs < 1) {
        fail('WATCHDOG_BUDGET', 'watchdogBudgetMs must be a positive whole number or null');
      }
      if (keepalivePeriodMs * KEEPALIVE_BUDGET_FRACTION > watchdogBudgetMs) {
        // Fail closed at construction rather than clamp: a period the client's
        // own declared budget cannot absorb is a configuration error, and
        // quietly shortening it would hide that the client asked for something
        // this server was not set up to give.
        fail(
          'KEEPALIVE_PERIOD',
          `a ${keepalivePeriodMs} ms keepalive does not fit the client's ${watchdogBudgetMs} ms ` +
          `watchdog budget with ${KEEPALIVE_BUDGET_FRACTION}x headroom for lost datagrams`
        );
      }
    }

    this.#routingKey = routingKey;
    this.#loginIdentity = loginIdentity;
    this.#attachment = attachment;
    this.#endpointToken = endpointToken >>> 0;
    this.#reliableWindow = Number.isSafeInteger(reliableWindow) && reliableWindow >= 32
      ? reliableWindow : 32;
    this.#wheel = wheel;
    this.#logger = logger;
    this.#areaDirectory = areaDirectory;
    this.#playerCountFor = playerCountFor;
    this.#roomListProvider = roomListProvider;
    this.#relayChat = relayChat;
    this.#relayGameBeacon = relayGameBeacon;
    this.#gameRelay = gameRelay === true;
    this.#relayGameChannel = relayGameChannel;
    this.#gameBeaconEcho = gameBeaconEcho === true;
    this.#gameBeaconRelay = gameBeaconRelay === true;
    this.#exitCloseMirror = exitCloseMirror === true;
    this.#onClientClose = onClientClose;
    this.#completionSeqEcho = completionSeqEcho === true;
    this.#channelBitEcho = channelBitEcho === true;
    this.#joinLadder = joinLadder === true;
    this.#op10Relay = op10Relay === true;
    this.#op0aCount0 = op0aCount0 === true;
    this.#memberInfo = memberInfo === true;
    this.#roomFlagsPublish = roomFlagsPublish === true;
    this.#roomStat = roomStat === true;
    this.#memberIdToken = memberIdToken === true;
    this.#rosterToJoiner = rosterToJoiner === true;
    this.#hostReseat = hostReseat === true;
    this.#countPush = countPush === true;
    this.#pushAreaCount = pushAreaCount;
    this.#appKeepalive = appKeepalive === true;
    this.#roomLifecycle = roomLifecycle;
    this.#slotAllocator = slotAllocator;
    this.#broadcast = broadcast;
    this.#relayRoomEvent = relayRoomEvent;
    this.#onGameStart = onGameStart;
    this.#presence = presence;
    this.#presenceRecord = presenceRecord;
    this.#rooms = rooms;
    this.#roomName = roomName;
    this.#roomCapacity = roomCapacity;
    this.#keepalivePayload = buildKeepalivePayload(keepaliveCiphertext);
    this.#keepalivePeriodMs = keepalivePeriodMs;
    this.#watchdogBudgetMs = watchdogBudgetMs;
    this.#successTransitionEnabled = successTransition === true;
    this.#idleTimeoutMs = idleTimeoutMs;
    this.#onIdle = onIdle;

    this.#channel = new ReliableChannel({
      token: this.#endpointToken,
      wheel,
      transmit,
      onTransportDead,
      inboundReceiveBase,
      outboundSequence,
      maximumUnacknowledged: this.#reliableWindow,
      /*
       * V1's dedicated keepalive counter started at 1
       * (`game_udp_server.js:1361`, `s.kaSeq = (s.kaSeq || 0) + 1`), and that is
       * the stream a real PS2 answered. The client's test is `conn+0x10 <= seq`,
       * so 0 would also pass - this matches the proven bytes rather than
       * re-deriving an equivalent.
       */
      unreliableSequence: 1
    });
  }

  get routingKey() {
    return this.#routingKey;
  }

  get loginIdentity() {
    return this.#loginIdentity;
  }

  get attachment() {
    return this.#attachment;
  }

  /** The routing-hint token, readable so the op-0x10 relay can match it. */
  get endpointToken() {
    return this.#endpointToken;
  }

  get channel() {
    return this.#channel;
  }

  get closed() {
    return this.#closed;
  }

  /** The area box this session is in, or null. DERIVED from presence, never stored. */
  get enteredBoxId() {
    return this.#presenceRecord.boxId;
  }

  /** This session's presence record. Read-only from outside; only presence mutates it. */
  get presence() {
    return this.#presenceRecord;
  }

  /** The room this session created, or null. */
  get createdRoom() {
    return this.#createdRoom;
  }

  /** Counters a rig log can assert against. Diagnostics only. */
  stats() {
    return {
      nameQueryReplies: this.#nameQueryReplies,
      gameBeacons: this.#gameBeacons,
      gameChannelFrames: this.#gameChannelFrames,
      // The TOTAL, including everything the rollup suppressed - so a session that
      // was quietly refusing sends is visible at close even if it never reached
      // a rollup line.
      sendRefusals: [...this.#sendRefusals.values()].reduce((sum, count) => sum + count, 0),
      keepalivesSent: this.#keepalivesSent,
      keepaliveResponses: this.#keepaliveResponses,
      appKeepalivesSent: this.#appKeepalivesSent,
      successTransitionSent: this.#successTransitionSent,
      unacknowledged: this.#channel.unacknowledgedCount,
      nextStampedSequence: this.#channel.nextStampedSequence,
      receiveBase: this.#channel.receiveBase,
      watchdogBudgetMs: this.#watchdogBudgetMs,
      keepalivePeriodMs: this.#keepalivePeriodMs
    };
  }

  /**
   * Arm the op-0x40 keepalive.
   *
   * Sent immediately and then every period. Immediately, because the client's
   * watchdog is armed the moment the bind lands and the first period of silence
   * is budget spent for nothing; V1 waited for the first op-0x0c
   * (`game_udp_server.js:2367`) and that is later than it needs to be.
   */
  startKeepalive() {
    if (this.#closed) fail('SESSION_CLOSED', 'startKeepalive on a closed session');
    if (this.#keepaliveHandle !== null) return false;
    this.#sendKeepalive();
    this.#armKeepalive();
    /*
     * The APPLICATION keepalive starts at the same establish moment - slot
     * 0x13 is installed then, so the vehicle is valid from the first tick on
     * any screen. Armed, not sent immediately: `FUN_005bdc70` re-arms the
     * client's watchdog with its full 1800-tick idle budget at this exact
     * moment, so the first useful reset is one period out - and the
     * rig-confirmed establish-window byte stream stays untouched.
     */
    if (this.#appKeepalive) this.#armAppKeepalive();
    this.#armIdle();
    return true;
  }

  /**
   * Accept one datagram from this client.
   *
   * Never throws on peer input. The channel acknowledges every reliable inbound
   * message by the OUTER frame id and hands back what it delivered in order;
   * this dispatches the delivered messages and reports what it did.
   */
  accept(datagram) {
    if (this.#closed) {
      return { refusals: [{ code: 'CLOSED', detail: LOBBY_SESSION_REFUSAL.CLOSED }], handled: [] };
    }
    // A COUNTER, not a rearmed timer: this runs about 25 times a second on the
    // Area-Select poll, and cancelling and rescheduling a wheel entry that often
    // is work for nothing. A count rather than a timestamp because two events in
    // the same millisecond are ordinary here and a timestamp comparison cannot
    // tell them apart - which would release a session that was never idle.
    this.#datagramsSinceIdleArm += 1;
    const result = this.#channel.acceptDatagram(datagram);
    const handled = [];
    const refusals = [...(result.refusals ?? [])];
    for (const message of result.delivered) {
      /*
       * THE OUTERMOST GUARD, and it is not belt-and-braces.
       *
       * Every handler below parses peer bytes, and this class claims it never
       * throws on peer input. Review 2026-08-06 demonstrated that claim false:
       * a 16-byte datagram whose op-0x48 payload is under 8 bytes threw
       * NAME_QUERY_TOO_SHORT straight out of here, out of the UDP 'message'
       * listener, and into `bin/pal-server-v2.js`, which stops every listener
       * and exits 1. With `Restart=always` in the unit file that is a
       * drop-every-player restart loop triggered by ONE malformed datagram from
       * an unauthenticated source.
       *
       * The individual parser was fixed too, but the guard belongs here: the
       * property we need is "no peer bytes can kill the process", and proving
       * that handler by handler is a promise that a future handler breaks
       * silently. A throw becomes a refusal, the session survives, and the
       * datagram is dropped - which is what every other refusal path already
       * does.
       */
      try {
        handled.push(this.#dispatch(message));
      } catch (error) {
        refusals.push({
          code: 'HANDLER_THREW',
          detail: `${error.code ?? error.name}: ${error.message}`,
          opcode: message.opcode
        });
        this.#logger?.warn?.('snap-lobby handler-threw', {
          opcode: `0x${(message.opcode ?? 0).toString(16)}`,
          code: error.code ?? error.name,
          reason: error.message,
          note: 'peer input reached a handler that threw; dropped rather than propagated'
        });
      }
    }
    return { ...result, refusals, handled };
  }

  /**
   * Send the op-0x29 success transition.
   *
   * Public and explicit because it has NEVER been captured: it is reconstructed
   * from the disassembly at `1daf7c-1db01c` alone. The caller enables it, the
   * caller triggers it, and the default path does neither - the keepalive defers
   * 840 indefinitely and is the route the archive proves.
   */
  sendSuccessTransition() {
    if (this.#closed) fail('SESSION_CLOSED', 'sendSuccessTransition on a closed session');
    if (!this.#successTransitionEnabled) {
      // Refused, not ignored. A message reconstructed from disassembly alone
      // must not be reachable by accident, and a caller that asked for it
      // without enabling it has a configuration mistake worth being told about.
      fail(
        'SUCCESS_TRANSITION_DISABLED',
        'op-0x29 has never been captured and is disabled; enable it explicitly to send it'
      );
    }
    const payload = buildSuccessTransitionPayload({ endpointToken: this.#endpointToken });
    // who 0xa01c: RELIABLE | SET, and DATA deliberately CLEAR - the disassembled
    // form is `a0 1c 00 29`, and `FUN_001d6988` routes on the DATA bit.
    const sent = this.#send({
      opcode: LOBBY_OPCODE.SUCCESS_TRANSITION,
      subSelector: 0,
      payload,
      flags: FLAG_SET,
      event: 'success-transition'
    });
    if (sent) this.#successTransitionSent = true;
    return sent;
  }

  /** Cancel every timer this session owns and drop the channel. Idempotent. */
  close() {
    if (this.#closed) return 0;
    this.#closed = true;
    if (this.#keepaliveHandle !== null) {
      this.#wheel.cancel(this.#keepaliveHandle);
      this.#keepaliveHandle = null;
    }
    if (this.#appKeepaliveHandle !== null) {
      this.#wheel.cancel(this.#appKeepaliveHandle);
      this.#appKeepaliveHandle = null;
    }
    if (this.#idleHandle !== null) {
      this.#wheel.cancel(this.#idleHandle);
      this.#idleHandle = null;
    }
    return this.#channel.close();
  }

  /**
   * Throw unless the wheel holds nothing for either owner.
   *
   * Two owners, because the channel schedules under itself. Asserting only one
   * of them would pass while the other leaked, which is the exact failure this
   * facility exists to make impossible to miss.
   */
  assertDrained() {
    this.#wheel.assertOwnerDrained(this);
    this.#wheel.assertOwnerDrained(this.#channel);
  }

  /* ---- dispatch --------------------------------------------------------- */

  #dispatch(message) {
    switch (message.opcode) {
      case LOBBY_OPCODE.NAME_QUERY:
        return this.#onNameQuery(message);
      case LOBBY_OPCODE.ROOM_QUERY:
        return this.#onRoomQuery(message);
      case LOBBY_OPCODE.REENTRY_QUERY:
        return this.#onReentryQuery(message);
      case LOBBY_OPCODE.AREA_ENTER:
        /*
         * Inbound op-0x06 is more than one request. The rig-proven V1
         * discriminant (`server/game_udp_server.js:1649-1651`, the 2026-07-12
         * correction) is STRUCTURAL, never the DATA flag: room-ENTER = reliable
         * op-0x06 with declared inner length 0x28 (the fixed 0x18-byte
         * `FUN_001dcdfc` body) AND (room handle at body +0x00 non-zero OR name
         * at body +0x09 non-empty) - where the zero-handle-with-typed-title
         * case is the Vacant-slot CREATE form, because a create on a Vacant
         * slot transmits op-0x06 with handle 0 (`0x6fee68[idx]` unwritten) and
         * the typed title at wire +0x19 (Ghidra FUN_005c04f0). The DATA bit is
         * NOT part of V1's test: an earlier V2 revision routed on `!data`,
         * which swept the create form into the join ladder, where its zero
         * handle resolved to no room and the ENTER died as a silent
         * 'no-such-room' refusal (nora pre-deploy review, caveat 4).
         *
         * So ONLY the unambiguous join - len 0x28 with a NON-ZERO handle -
         * enters the ladder. The create form and everything else take exactly
         * the pre-branch path (the area accept, who 0xB0), keeping the create
         * screen's bytes unchanged from the rig-run builds (T35/T37 created
         * rooms against that reply). Area ENTER itself declares 0x14 with a
         * 4-byte body, so the length test alone already excludes it.
         *
         * Flag off: everything falls through to the area path, byte-identical
         * to every previous build.
         */
        if (this.#joinLadder && message.reliable &&
          message.innerLength === 0x10 + ROOM_ENTER_REQUEST_BYTES &&
          message.payload.length >= ROOM_ENTER_REQUEST_BYTES &&
          message.payload.readUInt32BE(0) !== 0) {
          return this.#onRoomEnter(message);
        }
        return this.#onAreaEnter(message);
      case LOBBY_OPCODE.ROOM_STATE:
        return this.#onRoomEvent(message);
      case LOBBY_OPCODE.AREA_LEAVE:
        return this.#onLeave(message);
      case LOBBY_OPCODE.CREATE_ROOM:
        return this.#onCreateRoom(message);
      case LOBBY_OPCODE.CHAT:
        /*
         * op-0x0F splits on the client's OWN discriminator: the 0x0400 flag.
         * `FUN_001d9f78` case 0xc routes 0x0400-SET frames to the chat parser
         * (slots 0x0B/0x0D) and 0x0400-CLEAR frames to the game module
         * (slot 0x12 reliable / slot 0x14 unreliable), regardless of the
         * reliable and DATA bits (`analysis/LOBBY-CHAT-AND-ACTIONS.md` §3.1;
         * RS1-A §6.2). Chat itself carries the bit (T35 `0xb422`, RS1
         * `0xb421`), and so does the area-name probe that shares the parser.
         *
         * SUPERSEDED (2026-08-08, RS1-A §2): the previous `!reliable && !data`
         * test. It only diverted the unreliable `0x2012` beacon, so the
         * RELIABLE game-module species - first captured 15:02:47.430 UTC,
         * flags `0xa03a`, a structured `06 00`-block body - fell into the
         * chat parser as `lobby-chat screenType 40` and went into the void.
         * The client's table says 0x0400, not the transport bits.
         */
        if ((message.flags & FLAG_STRING) === 0) return this.#onGameChannel(message);
        return this.#onChat(message);
      case LOBBY_OPCODE.MEMBER_LIST:
        return this.#onMemberList(message);
      case LOBBY_OPCODE.AREA_COUNT_QUERY:
        return this.#onAreaCountQuery(message);
      case LOBBY_OPCODE.NAMED_CHANNEL_QUERY:
        return this.#onNamedChannelQuery(message);
      case LOBBY_OPCODE.ROOM_LIST:
        return this.#onRoomList(message);
      case LOBBY_OPCODE.KEEPALIVE_RESPONSE:
        return this.#onKeepaliveResponse(message);
      case LOBBY_OPCODE.RTT_PROBE:
        return this.#onRttProbe(message);
      case LOBBY_OPCODE.SESSION_CLOSE:
        return this.#onSessionClose(message);
      default:
        return this.#onUnhandled(message);
    }
  }

  /** The pre-existing default: acked by the transport, logged, not answered. */
  #onUnhandled(message) {
    this.#logger?.info?.('udp9090 lobby-observed-message', {
      routingKey: this.#routingKey,
      loginIdentity: this.#loginIdentity,
      opcode: `0x${message.opcode.toString(16)}`,
      sequence: message.sequence,
      bytes: message.innerLength,
      note: LOBBY_SESSION_REFUSAL.UNHANDLED_OPCODE
    });
    return { opcode: message.opcode, answered: false };
  }

  /**
   * The op-0x02 session CLOSE - the client giving up on this session.
   *
   * ## What the wire shows (B3-LEAVE-TWICE-EVIDENCE.md §1, T37)
   *
   * On the second exit attempt the client's exit path degrades to the screen-6
   * teardown, which sends a reliable ZERO-body op-0x02 (`FUN_001dbd0c`,
   * `who = 0xb000` "type 2"). V2 acked it at the transport and answered
   * nothing; the client then parked ~7 s, gave up, and re-registered from
   * scratch - sometimes wedging the console for good ("leave twice").
   *
   * ## The fix behind SNAP_EXIT_CLOSE_MIRROR (default OFF)
   *
   * The exit-contract RE (xchain:29337) records the 0xb000 close as a
   * BIDIRECTIONAL handshake the dispatcher mirrors. So, flag on: keep the
   * transport ack the channel already sent, mirror a zero-body op-0x02 back -
   * reliable SET|DATA, wire word `0xb010`, stamped sequence - and then release
   * this server-side session so the client's follow-up register starts a clean
   * epoch (T37 proves that recovery path lands on a working Area Select).
   * Hypothesis until rig-confirmed: the exact confirm shape that writes the
   * client's `0x6cbbe0 := 2` is gap G1, which is why this is a flag and not a
   * default. Flag off: exactly the previous behaviour, the unhandled-opcode log.
   */
  #onSessionClose(message) {
    if (!this.#exitCloseMirror) return this.#onUnhandled(message);
    const answered = this.#send({
      opcode: LOBBY_OPCODE.SESSION_CLOSE,
      // Mirrored like every completion's: 0 in all three observed closes.
      subSelector: message.subSelector,
      payload: Buffer.alloc(0),
      event: 'exit-close-mirror',
      // One shot by nature: the session is released on the next line, so a
      // refused send here is gone for good and must be visible.
      everyRefusalMatters: true
    });
    this.#logger?.info?.('udp9090 lobby-session-close', {
      routingKey: this.#routingKey,
      loginIdentity: this.#loginIdentity,
      sequence: message.sequence,
      answered,
      note: 'client op-0x02 close; mirrored a zero-body op-0x02 (SNAP_EXIT_CLOSE_MIRROR) and ' +
        'releasing this session so the re-register epoch is clean'
    });
    // AFTER the mirror left: releasing first would close the channel under it.
    // The release closes this session, so nothing later in this datagram's
    // dispatch can send - which is correct: the client said goodbye.
    this.#onClientClose?.(this);
    return { opcode: message.opcode, answered, released: true };
  }

  /**
   * The NAME query, op-0x48. Answered with the area records.
   *
   * This is the message that both un-greys Area Select (`FUN_005c1220`, box by
   * the name's trailing digits) and gates it (`FUN_005bc990`, the population sum
   * against the TCP-10127 max). The client polls it at roughly 25 Hz once the
   * screen is up, reply-independently by design (gap table B4) - there is no
   * server value that quiets it, so the reply has to be cheap and must not log
   * per send.
   */
  #onNameQuery(message) {
    const query = decodeNameQuery(message.payload);
    const { records, population } = this.#areaDirectory.records(this.#playerCountFor);
    const payload = buildNameQueryReplyPayload({ tag: query.tag, statusWord: 0, records });
    const answered = this.#send({
      opcode: LOBBY_OPCODE.NAME_QUERY,
      // Echoed, never assumed: the archive's queries all carry 0, but "copy the
      // sub byte" is the rule the op-0x0c matcher proved
      // (`analysis/FOUR-UNKNOWNS-CLOSED.md` §2) and echoing is a superset of
      // V1's behaviour on every observed input.
      subSelector: message.subSelector,
      payload,
      event: 'name-query-reply'
    });
    this.#nameQueryReplies += 1;
    if (this.#nameQueryReplies === 1) {
      // ONCE per session at info. The poll is ~25/s; a per-reply info line is
      // 1500 lines a minute and would bury everything else in the journal.
      this.#logger?.info?.('udp9090 lobby-name-query', {
        routingKey: this.#routingKey,
        loginIdentity: this.#loginIdentity,
        tag: query.tag,
        queriedValues: query.entries.map((entry) => entry.value),
        records: records.length,
        population,
        note: 'the first op-0x48 of this session; the sum above is the "Server full" gate\'s ' +
          'left operand, against the TCP-10127 0x6504 max players'
      });
    }
    return { opcode: message.opcode, answered, records: records.length, population };
  }

  /**
   * The op-0x0c room/session query, 260 bytes.
   *
   * The ONLY match key is `wire+0x02`, copied verbatim. `conn+0x61f` is the
   * client's send generation, it is POST-incremented, and it is NOT reset by a
   * re-register - the archive shows subs 0, 1 and 2 within one UDP session. A
   * server that assumes 0 answers the first attempt and silently fails every
   * retry (`analysis/FOUR-UNKNOWNS-CLOSED.md` §2; the second half of the
   * so-called dual key is `FUN_005be9e0`, a stub returning its own argument, so
   * `0x21 == 0x21` by construction).
   */
  #onRoomQuery(message) {
    const purpose = this.#classifyRoomQuery(message);
    const answered = this.#send({
      opcode: LOBBY_OPCODE.COMPLETION,
      subSelector: message.subSelector,
      payload: buildCompletionPayload({ selector: COMPLETION_SELECTOR.ROOM_QUERY, status: 0 }),
      event: `room-query-completion:${purpose}`,
      // The create PREPARE is asked once and parked on with no timeout, exactly
      // like the accept it precedes. The connect-screen query is on a path with
      // its own retry, so only the create case is unabsorbable.
      everyRefusalMatters: purpose === ROOM_QUERY_PURPOSE.CREATE_PREPARE
    });
    /*
     * SNAP_MEMBER_INFO (RS1-B §4/§7.2): V1's July golden set answered EVERY
     * op-0x0c with the sel-0x0c completion PLUS an op-28 sel-0x0a roster
     * record (pkts 499+500 / 527+528), and that joiner proceeded down the
     * ladder. The record's members are the sender's room roster when it is in
     * one; outside a room V1 sent its synthetic single record ("PLAYER1",
     * id 1) for months of rig-validated creates and joins, so that exact
     * fallback ships rather than an invented one. Sub 0 on this frame - the
     * July wire byte (pkt 500 `b1 24 00 28`) - and the default SET|DATA flags
     * are the 0xB1xx who that reaches the count-setter slot.
     */
    if (this.#memberInfo && answered) {
      this.#send({
        opcode: LOBBY_OPCODE.COMPLETION,
        subSelector: 0,
        payload: buildRosterRecordPayload({ members: this.#rosterRecordMembers() }),
        event: `room-query-roster:${purpose}`
      });
    }
    this.#logger?.info?.('udp9090 lobby-room-query', {
      routingKey: this.#routingKey,
      loginIdentity: this.#loginIdentity,
      purpose,
      matchKey: `0x${message.subSelector.toString(16)}`,
      bytes: message.payload.length,
      sequence: message.sequence,
      answered,
      note: purpose === ROOM_QUERY_PURPOSE.CREATE_PREPARE
        ? 'op-0x28 selector 0x0c answering the CREATE PREPARE (func_0x001de470, cb slot 0x26 = ' +
          'FUN_005c39e0); it advances FUN_005c3490 step 0 -> step 1, which then sends op-0x04'
        : 'op-0x28 selector 0x0c answering the CONNECT-SCREEN query (cb slot 0x26 = ' +
          'FUN_005b52e0), the only exit from connect sub-state 7 step 0. The match key is ' +
          'wire+0x02, verbatim'
    });
    return { opcode: message.opcode, answered, purpose };
  }

  /**
   * Which op-0x0c this is - and an honest admission that the wire cannot say.
   *
   * TWO different client requests carry opcode `0x0c` and BOTH install their
   * callback at transport slot **0x26**:
   *
   *   the connect-screen room/session query, whose completion is the only exit
   *   from connect sub-state 7 step 0 (`FUN_005b52e0`); and
   *
   *   the CREATE PREPARE, sent by `func_0x001de470` from `FUN_005c3490` step 0
   *   with callback `FUN_005c39e0`, whose completion sets `0x6CBA7D = 1` and lets
   *   the pump send op-0x04.
   *
   * V2 answered "any op-0x0c" with selector `0x0c` and status 0, which satisfies
   * the create PREPARE **by accident** - the right bytes for the wrong reason.
   * That is fine until the two need different answers, at which point nothing in
   * the code records that there were ever two questions.
   *
   * So both are recognised and both are answered for their own stated reason.
   * The discriminator is NOT a wire field: no field has been established that
   * separates them, and inventing one would be exactly the guess this project
   * refuses. What IS known is the SERVER-side context - the create PREPARE can
   * only be sent from inside an area, because the create screen is reached from
   * the in-area lobby, whereas the connect-screen query happens before any ENTER.
   * That is Inference, it is stated as such, and the ANSWER IS IDENTICAL either
   * way, so a misclassification changes a log line and nothing on the wire.
   */
  #classifyRoomQuery(message) {
    if (this.#presenceRecord.boxId == null) return ROOM_QUERY_PURPOSE.CONNECT_SCREEN;
    // 260 bytes is the connect-screen query's observed size (`a1 00 00 0c`); the
    // create PREPARE carries the assembled config buffer. Recorded because it is
    // the only length ever captured, not because a size test is the mechanism.
    return message.payload.length === CONNECT_SCREEN_ROOM_QUERY_PAYLOAD_BYTES
      ? ROOM_QUERY_PURPOSE.CONNECT_SCREEN
      : ROOM_QUERY_PURPOSE.CREATE_PREPARE;
  }

  /**
   * The op-0x0d re-entry query.
   *
   * `FUN_005bcee0` installs its callback directly in the transport slot table, so
   * `FUN_005be120` is bypassed entirely and there is NO key match - only the
   * payload's `BE32 0x0000000D` matters. The sub byte is echoed for symmetry, not
   * because anything reads it. Beyond the brief, and implemented because without
   * it the SECOND trip to the lobby stalls with no other server obligation to
   * discharge (`analysis/FOUR-UNKNOWNS-CLOSED.md` §4).
   */
  #onReentryQuery(message) {
    const answered = this.#send({
      opcode: LOBBY_OPCODE.COMPLETION,
      subSelector: message.subSelector,
      payload: buildCompletionPayload({ selector: COMPLETION_SELECTOR.REENTRY, status: 0 }),
      event: 'reentry-completion'
    });
    /*
     * TWO op-0x0D uses, discriminated by the body value (B1 doc §1 B-ii, T37
     * pcap): body `00000001` is the GAME-START BARRIER - `FUN_005c4760` state 4
     * sends it as each member enters the game - and `f7e00001` is the post-game
     * session re-open. Both callbacks read only the status byte, so the reply
     * above is identical for both and DOES NOT CHANGE. The barrier additionally
     * drives the engine's bioserver `broadcastGetReady` half: gamenumber mint,
     * party snapshot, room -> BUSY (PORT-PLAN slice 2b). State only - nothing
     * extra leaves on the wire (op-0x49 publication of the status is a separate
     * flag, default OFF).
     */
    const barrier = message.payload.length >= 4 && message.payload.readUInt32BE(0) === 1;
    const gameSession = barrier && this.#onGameStart != null ? this.#onGameStart(this) : null;
    this.#logger?.info?.('udp9090 lobby-reentry-query', {
      routingKey: this.#routingKey,
      loginIdentity: this.#loginIdentity,
      answered,
      barrier,
      gamenumber: gameSession?.gamenumber ?? null,
      note: 'op-0x28 selector 0x0d; no key match exists on this path'
    });
    return { opcode: message.opcode, answered, barrier, gamenumber: gameSession?.gamenumber ?? null };
  }

  /**
   * Area ENTER, op-0x06. The accept is what puts the lobby on screen.
   *
   * The request carries the op-0x48 record's `+0x20` key at payload `+0x00`
   * (`FUN_005bfa70.c:19-24` passes `*(u32*)(areaIdx*0x24 + 0x6fec04)`), so it is
   * resolved against the directory and logged - a key that resolves to nothing
   * means the reply the client rendered from and the request it sent back
   * disagree, which is precisely the defect V1's all-zero keys hid.
   *
   * The reply is op-0x28 selector 6 status 0. `who` is `0xB0` - RELIABLE | SET |
   * DATA - which is what V1's rig-confirmed `SNAP_AREA_CONFIRM_REPLY` sent
   * (`game_udp_server.js:1984`, `push[0] = 0xB0`). NOTE: gap-table row C2 says
   * `0xA0` while citing that same flag; the flag's own code says `0xB0`, so the
   * shipped, rig-confirmed byte is used and the discrepancy is recorded here
   * rather than resolved by preference.
   */
  #onAreaEnter(message) {
    const key = message.payload.length >= 4 ? message.payload.readUInt32BE(0) : null;
    const area = key == null ? null : this.#areaDirectory.areaByKey(key);
    const before = this.#presenceRecord.location();
    // MUTATE FIRST, THEN EMIT (rule L1). Every count is a query over the presence
    // set, so any message built after this line is automatically correct - which
    // is the whole reason for deriving rather than storing them. Only when the
    // key resolved: a key that resolves to nothing leaves the player where they
    // were rather than putting them in a box the directory does not publish.
    if (area != null) this.#presence.moveTo(this.#presenceRecord, { boxId: area.boxId });
    if (area != null && this.#countPush) {
      /*
       * SNAP_COUNT_PUSH (RS1-C C2): the JP `broadcastAreaPlayerCnt` fires on
       * area JOIN too (PacketHandler.java:746). The EXISTING members' latched
       * count is now one short; this session itself is excluded because its
       * own op-0x09 query volley follows this ENTER and answers it fresher.
       * Pushed after the mutate (rule L1) so the fanned-out count is the
       * post-transition one; independent of `answered` because the presence
       * moved either way.
       */
      this.#pushAreaCount(area.boxId, this);
      if (before.boxId != null && before.boxId !== area.boxId) {
        this.#pushAreaCount(before.boxId, this);
      }
    }
    const answered = this.#send({
      opcode: LOBBY_OPCODE.COMPLETION,
      subSelector: message.subSelector,
      payload: buildCompletionPayload({
        selector: COMPLETION_SELECTOR.AREA_ENTER,
        status: 0,
        // B3 fix 2: the request's send-seq at +0xc, so FUN_005bfb40's dual-key
        // pool sweep matches in-message instead of reading past the datagram.
        // null keeps the payload byte-identical to the rig-confirmed 8-byte form.
        sendSeqEcho: this.#completionSeqEcho ? message.sequence : null
      }),
      event: 'area-enter-accept',
      // A refused ENTER is never a dropped poll: the client asks once, and an
      // unanswered ENTER is a lobby that never appears. It must be visible in
      // the journal every time, not absorbed into the op-0x48 rollup.
      everyRefusalMatters: true
    });
    const level = answered ? this.#logger?.info : this.#logger?.warn;
    level?.call(this.#logger, 'udp9090 lobby-area-enter', {
      routingKey: this.#routingKey,
      loginIdentity: this.#loginIdentity,
      requestedKey: key == null ? null : `0x${key.toString(16)}`,
      resolvedBox: area?.boxId ?? null,
      answered,
      note: !answered
        ? 'the ENTER accept was REFUSED by the reliable channel; this client asked once and its ' +
          'lobby will not appear'
        : area == null
          ? 'the ENTER key matches no published area; the op-0x48 keys and this request disagree'
          : 'op-0x28 selector 6 status 0 -> FUN_005ad9f0 -> FUN_005f74d0 -> cRam006c4b90 = 2'
    });
    return { opcode: message.opcode, answered, boxId: area?.boxId ?? null };
  }

  /**
   * The room ENTER - the JOIN half of op-0x06 (PORT-PLAN slice 1b step 5,
   * flag `SNAP_JOIN_LADDER`).
   *
   * ## The engine path (bioserver JOINGAME, contract §6)
   *
   * The handle resolves through the same opaque-bytes rule as every other
   * handle field (LE is the proven order: the client sends back the op-0x49
   * record's `+0x24` bytes verbatim). The slot allocator then runs the
   * reference guards in the reference order - BUSY -> full, not-GAMESET ->
   * not-possible, password - assigns the first free playernum of 2..4, and
   * moves the presence into the room (mutate first, rule L1).
   *
   * ## Guard failure = do-not-accept, NOT a wire reject
   *
   * No PAL join rejection has ever been captured (the only observed reject
   * vehicle is the op-0x27 opcode swap on CREATE); inventing one would be a
   * guess. So a refused join is logged and left unanswered - open rooms accept,
   * which is every case the coming rig run can produce (password rooms are
   * deferred with B5).
   *
   * ## The accept, ported from the July rig path
   *
   * op-0x28 selector 6, status 0, sub echoed, and who `0xA0` - DATA CLEAR,
   * which is the ONLY difference from the area accept and is what routes the
   * completion to slot 0x22 `FUN_005c05c0` (sets `0x6ff2b1=1`/`0x6ff2b2=1`,
   * unlocking the room) instead of the area slot 0x21. V1's
   * `SNAP_ROOM_ENTER_ACCEPT` shipped exactly these bytes on the rig
   * (`game_udp_server.js:1764-1775`).
   */
  #onRoomEnter(message) {
    let request;
    try {
      request = decodeRoomEnterRequest(message.payload);
    } catch (error) {
      return { opcode: message.opcode, answered: false, refusal: error.code ?? error.name };
    }
    const room = this.#roomForHandleBytes(request.handleBytes);
    const refuse = (reason) => {
      this.#logger?.warn?.('udp9090 lobby-room-enter-refused', {
        routingKey: this.#routingKey,
        loginIdentity: this.#loginIdentity,
        handle: `0x${request.handleBytes.toString('hex')}`,
        name: request.name,
        reason,
        note: 'no PAL join-rejection vehicle has been captured, so a refused join is logged and ' +
          'left unanswered rather than guessed onto the wire'
      });
      return { opcode: message.opcode, answered: false, joined: false, refused: reason };
    };
    if (room == null) return refuse('no-such-room');
    if (room.boxId !== this.#presenceRecord.boxId) {
      // The join ladder's step 1 is the AREA enter; a join into a room in an
      // area this session is not in cannot come from a healthy client and
      // would leave presence claiming a room outside its own area.
      return refuse('room-not-in-this-area');
    }
    const verdict = this.#slotAllocator.join({ room, presence: this.#presenceRecord });
    if (!verdict.ok) return refuse(verdict.reason);

    const answered = this.#send({
      opcode: LOBBY_OPCODE.COMPLETION,
      subSelector: message.subSelector,
      payload: buildCompletionPayload({ selector: COMPLETION_SELECTOR.AREA_ENTER, status: 0 }),
      // DATA deliberately CLEAR: who 0xA0 is what routes sel-6 to the
      // room-enter slot 0x22 instead of the area slot 0x21.
      flags: FLAG_SET,
      event: 'room-enter-accept',
      // Asked once, parked on. Same one-shot nature as the create accept.
      everyRefusalMatters: true
    });
    if (answered) this.#sendJoinFollowUps(room, verdict.playernum);
    const level = answered ? this.#logger?.info : this.#logger?.warn;
    level?.call(this.#logger, 'udp9090 lobby-room-enter', {
      routingKey: this.#routingKey,
      loginIdentity: this.#loginIdentity,
      handle: `0x${room.handle.toString(16)}`,
      playernum: verdict.playernum,
      members: room.current,
      answered,
      note: answered
        ? 'op-0x28 sel 6 who 0xA0 -> slot 0x22 FUN_005c05c0 -> 0x6ff2b1=1; member-JOIN + sub-5 ' +
          'fan-out followed from this transition'
        : 'the join ACCEPT was refused by the reliable channel; the joiner is in the room ' +
          'server-side but its screen never advances'
    });
    return {
      opcode: message.opcode, answered, joined: true, handle: room.handle,
      playernum: verdict.playernum
    };
  }

  /**
   * What a completed join pushes, and to whom - every one of them a DELTA from
   * THIS transition, never re-emitted from a poll (the op-0x06 accumulation
   * rule).
   *
   *   To the JOINER: its own member-JOIN record + the op-0x10 sub-5 limits -
   *   the exact pair the rig-confirmed create path sends its host
   *   (`#sendCreateFollowUps`), which V1's roster test also needed ("B sees B",
   *   `game_udp_server.js:1846-1852`).
   *
   *   To the EXISTING members, via the generalized broadcast: the joiner's
   *   member-JOIN record (bioserver PLAYERSTATBC 0x6503 - announce the joiner
   *   to the room; H-A of the B2 doc predicts this is exactly what the frozen
   *   room preview needs) + the sub-5 count refresh with the post-join counts.
   *
   * `memberId`/`characterId` = the playernum: distinct per member within the
   * room by construction, which is what the client's dedup `FUN_005b5ac0`
   * admits on (the create path's host record uses characterId 1 = the host
   * playernum, so this is the same scheme extended). Inference, stated: no
   * capture pins these two fields for a joiner record.
   */
  #sendJoinFollowUps(room, playernum) {
    const record = buildMemberJoinPayload({
      name: this.#loginIdentity.slice(0, 0x10),
      memberId: playernum,
      characterId: playernum
    });
    const limits = buildRoomLimitsPayload({ max: room.max, current: room.current });
    this.#send({
      opcode: LOBBY_OPCODE.MEMBER_JOIN,
      subSelector: 0,
      payload: record,
      flags: FLAG_SET,
      event: 'join-member-join',
      everyRefusalMatters: true
    });
    /*
     * SNAP_ROSTER_TO_JOINER (analysis/seated-slot-roster-RE-2026-08-25): the
     * joiner must ALSO receive an op-06 for every EXISTING member so it seats
     * them in ITS OWN 0x6c7c2c (FUN_005bb4d0 -> event 0x1f -> FUN_005b5ac0) -
     * without this the joiner's member list shows nobody but itself (owner:
     * "member data doesn't show the members who join"). Each existing member
     * gets a DISTINCT characterId (join-order index) so the seat dedup
     * (charstats +0xc8/+0xca in FUN_005b5ac0) does not collide on key 0.
     * Default OFF (byte-identical: no extra pushes).
     */
    if (this.#rosterToJoiner) {
      this.#membersOf(room).forEach((member, index) => {
        if (member.memberId === playernum) return; // not the joiner's own row
        const seatId = index + 0x10; // distinct, non-zero, != the joiner's playernum
        this.#send({
          opcode: LOBBY_OPCODE.MEMBER_JOIN,
          subSelector: 0,
          payload: buildMemberJoinPayload({
            name: String(member.name).slice(0, 0x10),
            memberId: member.memberId,
            characterId: seatId
          }),
          flags: FLAG_SET,
          event: `join-existing-member:${index}`,
          everyRefusalMatters: true
        });
      });
    }
    this.#send({
      opcode: LOBBY_OPCODE.ROOM_STATE,
      subSelector: 0,
      payload: limits,
      flags: FLAG_SET,
      event: 'join-room-limits',
      everyRefusalMatters: true
    });
    /*
     * SNAP_MEMBER_INFO, RS1-B §4 row 2: V1 followed the op-06 acceptance with
     * an `a3` op-0x10 sub-1 player-info push (July pkts 503-505: sel-6 accept
     * then the sub-1 push 200 us later), role 0 = joiner. V2 sent "sel-6
     * only (no op-10 sub-1 push anywhere)" - the missing half of the join
     * acceptance this flag restores.
     */
    if (this.#memberInfo) this.#sendPlayerInfo(0, 'join-player-info', true);
    const scope = { roomHandle: room.handle, except: this };
    /*
     * SNAP_MEMBER_ID_TOKEN (T17, wire-confirmed accept-scan fix): the record
     * pushed to each existing member R about this joiner carries R's OWN
     * endpoint token as the memberId. The host's start SM (FUN_005c6500 s6/7)
     * marks a member accepted only when a roster slot's memberId equals the
     * conn word on the relayed sub-4 accept - and that conn word is the
     * recipient's own token (we stamp the recipient on relay). memberId and the
     * header token are both writeUInt32BE and the client byteswaps both the
     * same way, so equal endpointToken => equal +0x10 bytes => the scan matches
     * and the joiner is admitted (0x6ff2b5[i]=1 -> 0x6ff2b3>=2 -> non-solo
     * start -> the joiner's barrier 0x6ff2af is set). OFF = the shared record
     * (memberId = playernum), byte-identical to today.
     */
    const joinFanout = this.#broadcast(scope, (peer) => {
      // SNAP_HOST_RESEAT (T20): re-seat the existing member FIRST so it holds
      // roster slot 0 (pre-accepted), then seat the joiner at slot 1 - the
      // order the non-solo start count needs.
      if (this.#hostReseat) peer.reseatSelf();
      const perPeer = this.#memberIdToken
        ? buildMemberJoinPayload({
          name: this.#loginIdentity.slice(0, 0x10),
          memberId: peer.endpointToken,
          characterId: playernum
        })
        : record;
      return peer.deliverRoomPush(LOBBY_OPCODE.MEMBER_JOIN, perPeer, 'member-join-fanout');
    });
    const limitsFanout = this.#broadcast(scope, (peer) =>
      peer.deliverRoomPush(LOBBY_OPCODE.ROOM_STATE, limits, 'room-limits-fanout'));
    this.#logger?.info?.('udp9090 lobby-join-fanout', {
      routingKey: this.#routingKey,
      loginIdentity: this.#loginIdentity,
      handle: `0x${room.handle.toString(16)}`,
      joinFanout,
      limitsFanout,
      note: 'the joiner\'s member-JOIN record + sub-5 counts pushed to the existing members ' +
        '(PLAYERSTATBC analogue; delta only from this transition)'
    });
  }

  /**
   * Push one already-built room-scoped record to THIS session, DATA clear
   * (who 0xA0 - the game-channel slot routing every op-0x06/op-0x10 push uses).
   * A full window is reported and skipped, exactly like chat.
   */
  deliverRoomPush(opcode, payload, event) {
    if (this.#closed) return false;
    return this.#send({ opcode, subSelector: 0, payload, flags: FLAG_SET, event });
  }

  /**
   * Push one unsolicited op-0x09 USER count to THIS session (SNAP_COUNT_PUSH).
   *
   * DEFAULT flags - FLAG_SET | FLAG_DATA, wire who 0xB0 - deliberately: that is
   * the byte-identical shape of the solicited answer (`#onAreaCountQuery`)
   * this client rendered on the rig, and DATA-set is what routes an inbound
   * op-0x09 to dispatch slot 0x17 (`FUN_001d9f78` case 6), where the entry
   * query left `FUN_005bf740` persistently installed. Sub 0: the sub byte does
   * not route this opcode, and no pending request exists to echo one from.
   */
  deliverAreaCountPush({ handleBytes, value }) {
    if (this.#closed) return false;
    return this.#send({
      opcode: LOBBY_OPCODE.AREA_COUNT_QUERY,
      subSelector: 0,
      payload: buildAreaCountReplyPayload({
        handleBytes, tag: AREA_COUNT_TAG_CURRENT, value
      }),
      event: 'area-count-push'
    });
  }

  /**
   * Inbound op-0x10 - the game channel.
   *
   * With both flags off this is EXACTLY the previous build: acked by the
   * transport, logged as an unhandled opcode, never answered. With them on:
   *
   *   app sub 0x02 (`SNAP_JOIN_LADDER`) is the joiner's JOIN-REQUEST, answered
   *   with the rig-proven sub-0x0C join-confirm - the V1 fix that released the
   *   joiner's major-5 wait (`SNAP_JOIN_OP10_SUBC`, Pi cead951e).
   *
   *   everything else (`SNAP_OP10_RELAY`) is RELAYED, never interpreted: the
   *   payload is forwarded verbatim to the sender's OWN room, except the
   *   sender (RS1-B §7.3 - body word1 is the sender's own handle, so nothing
   *   in the message addresses anybody). This is what carries the host-driven
   *   roster-SM bursts (sub-3..sub-8) on a multiplayer start - B1 §2 item 5.
   */
  #onRoomEvent(message) {
    if (!this.#joinLadder && !this.#op10Relay && !this.#memberInfo) {
      return this.#onUnhandled(message);
    }
    let event;
    try {
      event = decodeRoomEvent(message.payload);
    } catch (error) {
      this.#logger?.debug?.('udp9090 lobby-room-event-refused', {
        routingKey: this.#routingKey,
        loginIdentity: this.#loginIdentity,
        bytes: message.payload.length,
        code: error.code ?? error.name,
        reason: error.message
      });
      return { opcode: message.opcode, answered: false, refusal: error.code ?? error.name };
    }
    if (this.#joinLadder && event.sub === ROOM_EVENT_SUB.JOIN_REQUEST) {
      return this.#onJoinRequest(message, event);
    }
    /*
     * SNAP_MEMBER_INFO, RS1-B §4 row 4: V1 answered EVERY inbound
     * game-channel op-0x10 with the `a3` sub-1 player-info push, and the July
     * client re-sent its op-10 until satisfied. Tonight's host showed the
     * same signature - its sub-1 broadcast got a transport ack, no
     * application answer, and one application-level re-send 40 ms later
     * (RS1-B §2) - before it starved in its own room. The answer goes to the
     * SENDER; the relay below (its own flag) carries the payload to the room.
     */
    let answered = false;
    if (this.#memberInfo) {
      answered = this.#sendPlayerInfo(this.#playerInfoRole(), 'op10-player-info');
      this.#logger?.debug?.('udp9090 lobby-room-event-answered', {
        routingKey: this.#routingKey,
        loginIdentity: this.#loginIdentity,
        sub: `0x${event.sub.toString(16)}`,
        senderHandle: `0x${event.senderHandle.toString(16)}`,
        role: this.#playerInfoRole(),
        answered,
        note: 'op-0x10 answered with the sub-1 player-info push (V1 answered every one; the ' +
          'client re-sends its op-10 until satisfied - RS1-B §4)'
      });
    }
    if (this.#op10Relay) {
      const outcome = this.#onRoomEventRelay(message, event);
      return { ...outcome, answered };
    }
    if (this.#memberInfo) {
      return { opcode: message.opcode, answered, sub: event.sub };
    }
    return this.#onUnhandled(message);
  }

  /** The join-request -> join-confirm exchange, byte-ported from the V1 rig fix. */
  #onJoinRequest(message, event) {
    const at = this.#presenceRecord.location();
    // The count only sets the displayed member count; any non-zero value fires
    // the continuation. The real post-join room population is the honest value,
    // and 1 is the floor V1 also used when the registry had nothing.
    const count = at.roomHandle != null
      ? Math.max(1, this.#presence.countInRoom(at.roomHandle))
      : 1;
    const answered = this.#send({
      opcode: LOBBY_OPCODE.ROOM_STATE,
      subSelector: 0,
      payload: buildJoinConfirmPayload({
        // The request's own +0x04 word, echoed verbatim - V1's rig-proven form.
        requestEcho: message.payload.subarray(0x04, 0x08),
        count
      }),
      flags: FLAG_SET,
      event: 'join-confirm',
      // One shot: the SM stores one continuation and waits unbounded on it.
      everyRefusalMatters: true
    });
    this.#logger?.info?.('udp9090 lobby-join-confirm', {
      routingKey: this.#routingKey,
      loginIdentity: this.#loginIdentity,
      roomHandle: at.roomHandle == null ? null : `0x${at.roomHandle.toString(16)}`,
      count,
      answered,
      note: 'op-0x10 app sub 0x02 join-request answered with sub 0x0C (FUN_005bbe00 fires the ' +
        'stored continuation 0x601300: step->1, major 5->6, the room renders)'
    });
    return { opcode: message.opcode, answered, joinConfirm: true, count };
  }

  /**
   * The room-scoped relay: the payload goes VERBATIM to everyone in the
   * sender's own room except the sender - chat's proven scope model. Body
   * word1 is the sender's own handle (RS1-B §2), journalled for diagnostics
   * and never matched against anything.
   */
  #onRoomEventRelay(message, event) {
    const at = this.#presenceRecord.location();
    if (at.roomHandle == null) {
      this.#logger?.debug?.('udp9090 lobby-room-event-dropped', {
        routingKey: this.#routingKey,
        loginIdentity: this.#loginIdentity,
        senderHandle: `0x${event.senderHandle.toString(16)}`,
        note: 'op-0x10 from a sender in no room; there is no scope to relay into'
      });
      return { opcode: message.opcode, answered: false, relayed: 0, sub: event.sub };
    }
    const relayed = this.#relayRoomEvent(this, message.payload);
    this.#logger?.debug?.('udp9090 lobby-room-event-relayed', {
      routingKey: this.#routingKey,
      loginIdentity: this.#loginIdentity,
      roomHandle: `0x${at.roomHandle.toString(16)}`,
      sub: `0x${event.sub.toString(16)}`,
      senderHandle: `0x${event.senderHandle.toString(16)}`,
      relayed
    });
    return { opcode: message.opcode, answered: false, relayed, sub: event.sub };
  }

  /**
   * The room list, op-0x49. Content is the rooms held for THIS session's area.
   *
   * The area is the one the accepted ENTER resolved, never anything read out of
   * the request: the request's payload has not been decoded, and a lobby with no
   * rooms in it is a real state, so an empty list here means "none exist yet",
   * not "nothing was wired". See `state/lobby-rooms.js`.
   */
  /**
   * The op-0x04 CREATE, and the reply that unfreezes the cursor.
   *
   * ## The exact wall this closes
   *
   * From the online screen jumptable the live create path is `FUN_005f99c0`
   * (submit_room_entry) -> `FUN_005c0470` -> the async pump `FUN_005c3490`. Step 1
   * sends op-0x04 through `func_0x001dc508`, which installs `FUN_005c3a40` at
   * transport slot **0x1f**. Step 2 then spins on `0x6CBA7D`: 1 = accept, 2 =
   * reject, anything else = return. It has **no counter and no timeout exit**, and
   * the screen state it sits under (`0x6c4ba0 = 5` -> `0x005f9b88`) is
   * `jal FUN_005b6900` with the return DISCARDED. That is exactly the reported
   * symptom - music plays, background animates, cursor dead, no error, no dialog.
   *
   * V2 had no `0x04` case, so nothing ever wrote `0x6CBA7D`. This is the case.
   *
   * ## Why selector 4 and nothing else
   *
   * `FUN_001d9f78` cases on `(u16)(msg+0x2e) & 0x7f` - wire byte `0x03`. Wire
   * `0x28` reaches `case 0x25`, which byteswaps the first two payload words and
   * switches on `selector - 1`; entry 3 (selector **4**) loads `conn + 0x5C4`,
   * and `0x5C4 = 0x548 + 0x1f*4` is slot 0x1f. The same arithmetic gives selector
   * 6 -> slot 0x21 (the ENTER accept this file already ships, rig-confirmed) and
   * selector 7 -> slot 0x23 (`#onLeave`), so it is corroborated at three points.
   *
   * ## What ELSE the client is still blocked on, so this is not oversold
   *
   * `FUN_005fc400` does not inspect the status: ANY selector-4 completion, accept
   * or reject, advances `0x6c4ba0` and returns the cursor. Only the accept
   * additionally sets `0x6FF2B0 = 1`, stores the handle, and lets the pump set
   * `0x6FF2B1 = 1` one step later - which is the gate on editing the title and
   * password. The rules list and the scenario list have SEPARATE causes and are
   * not fixed here: see `state/area-table.js` for the mode masks, and the scenario
   * lock needs a savedata bitmap at `0x341AD0` that no server message can write.
   */
  /**
   * op-0x0F CHAT - relay the line to everyone else in scope.
   *
   * The client has been sending this since the first lobby run and we logged it
   * as an unhandled opcode. The owner's "chat is only local" is exactly what an
   * unrelayed op-0x0F looks like: `FUN_005C4AF0` writes the line into the
   * sender's own display block BEFORE transmitting, so the sender always sees it.
   *
   * SELECTOR 1 and 2 are NOT chat - they are the area-name probe, which shares
   * this opcode. One captured probe carries our own area-table version string,
   * so relaying blind would broadcast "OBAREA-V2" to the room as if a player had
   * typed it. There is no reply to a probe; it is consumed and acknowledged.
   */
  #onChat(message) {
    /*
     * THE SHORT VARIANT, and it is the common case rather than an error. T37 saw
     * 230 op-0x0F datagrams with a TWO-byte body and header flag `0x2000`, against
     * a handful of real chat lines. Treating them as malformed chat produced 115
     * warnings in one session for traffic that is simply not chat.
     *
     * What they are is Unknown - they were never answered before this handler
     * existed either, so ignoring them changes nothing on the wire. They are
     * consumed quietly and recorded at debug so the shape stays visible without
     * drowning the log.
     */
    if (message.payload.length < CHAT_MINIMUM_BODY_BYTES) {
      this.#logger?.debug?.('udp9090 lobby-chat-short-variant', {
        routingKey: this.#routingKey,
        loginIdentity: this.#loginIdentity,
        bytes: message.payload.length,
        body: message.payload.toString('hex'),
        note: 'op-0x0F with a body too short to be a chat line; not chat, not answered, and not ' +
          'answered before this handler existed either. Semantics Unknown.'
      });
      return { opcode: message.opcode, answered: true, shortVariant: true };
    }
    let chat;
    try {
      chat = decodeChatMessage(message.payload);
    } catch (error) {
      /*
       * Refused, not relayed, and this is the one place refusing is right: the
       * receiver memcpys both fields into fixed globals with no bounds check, so
       * forwarding an over-long line would corrupt memory on every OTHER console
       * in the room. Elsewhere on this path silence hangs the sender; here a bad
       * line can only harm people who did not send it.
       */
      this.#logger?.warn?.('udp9090 lobby-chat-refused', {
        routingKey: this.#routingKey,
        loginIdentity: this.#loginIdentity,
        code: error.code ?? error.name,
        reason: error.message
      });
      return { opcode: message.opcode, answered: false, refusal: error.code ?? error.name };
    }

    if (!chat.isChatText) {
      this.#logger?.debug?.('udp9090 lobby-chat-probe', {
        routingKey: this.#routingKey,
        loginIdentity: this.#loginIdentity,
        selector: chat.selector,
        text: chat.text.toString('latin1'),
        note: 'op-0x0F selector 1/2 is the area-name probe, not chat; not relayed'
      });
      return { opcode: message.opcode, answered: true, relayed: 0, probe: true };
    }

    const payload = buildChatRelayPayload({
      screenType: chat.screenType, name: chat.name, text: chat.text
    });
    // chat.text rides along so the sessions-level relay can re-vehicle ROOM
    // chat as op-0x10 sub-7 fragments (SNAP_ROOM_CHAT_SUB7) - the in-room
    // surface does not read the op-0x0F scrollback (ROOMCHAT-SCENARIO-WIRE §1).
    const relayed = this.#relayChat?.(this, payload, chat.text) ?? 0;
    this.#logger?.info?.('udp9090 lobby-chat', {
      routingKey: this.#routingKey,
      loginIdentity: this.#loginIdentity,
      from: chat.name.toString('latin1'),
      textBytes: chat.text.length,
      screenType: chat.screenType,
      relayed,
      note: 'op-0x0F relayed verbatim to the sender\'s room, or its area if it is in none; the sender is excluded because the client already echoed the line locally'
    });
    return { opcode: message.opcode, answered: true, relayed };
  }

  /**
   * Push one already-built chat relay to THIS session. Returns whether it left.
   *
   * A full send window is reported and skipped rather than thrown: one console
   * that has stopped acknowledging must not silence the whole room.
   *
   * ## The flags are the fix (RS1-C §C1, Conclusion grade)
   *
   * The relayed frame MUST carry `0x0400`: the client's dispatcher has no
   * branch at all for a `0x1000`-set/`0x0400`-clear op-0x0F, so the old
   * default `0xB0xx` relay was transport-acked (RS1 17:34:09.644) and then
   * dropped unrendered - `FUN_005BC590` never ran, the display block at
   * `0x6FC05A` was never written. "Chat doesn't work" with a clean ack on the
   * wire is exactly this. The DATA bit is the SCOPE half, taken from the same
   * presence decision `#relayChat` makes: `0xB4xx` area / `0xA4xx` room - the
   * datagrams the client itself emits (corpus relay spec
   * `LOBBY-CHAT-AND-ACTIONS.md` §1.1/§2.2) and the JP `broadcastChatOut`
   * equivalence.
   */
  deliverChat(payload, { roomScope = false } = {}) {
    if (this.#closed) return false;
    return this.#send({
      opcode: LOBBY_OPCODE.CHAT,
      subSelector: 0,
      payload,
      flags: FLAG_SET | FLAG_STRING | (roomScope ? 0 : FLAG_DATA),
      event: 'chat-relay'
    });
  }

  /**
   * The game-channel op-0x0F fork: everything with the 0x0400 flag CLEAR.
   *
   * The unreliable species is the 1 Hz beacon (below, with its flag-gated
   * echo/relay experiment). The RELIABLE species is new to the corpus - one
   * wire sample, 15:02:47.430 UTC 2026-08-08 (RS1-A §2): flags `0xa03a`, a
   * 42-byte structured body of `06 00`-length blocks around `04 14 02` /
   * `04 14 22`, sent 300 ms after the beacon echo. On a receiving client it
   * routes to handler slot 0x12. What it expects is Unknown (the game module
   * is outside the 2549-function lobby corpus), so it is CONSUMED at debug
   * with the RAW BODY HEX journalled - the 15:02 body was only recoverable
   * from the pcap because this path used to misfile it as chat (RS1-A §6.3).
   */
  #onGameChannel(message) {
    if (!message.reliable) return this.#onGameBeacon(message);
    this.#gameChannelFrames += 1;
    /*
     * SNAP_GAME_RELAY (GAME-START-WIRE §3 + SESSION-LOG T13): the reliable
     * game-channel op-0x0F stream is the in-game state the party runs on
     * (receiver = the in-game slot-0x12 GamePacketRUDP callback, named by the
     * AM/openSNAP table; slot-4 savestate imaged conn+0x590 holding it). The
     * server's role, triangulated from bioserver's GameServerPacketHandler
     * (broadcast raw bytes to the same gamenumber EXCLUDING the sender - no
     * parsing) and openSNAP's game-packet relay: byte-identical fan-out to
     * room members except the sender, each on the recipient's own reliable
     * seq. The sender's copy is already transport-acked by the channel; a
     * retransmit never reaches here (inbound window dedup), so a packet
     * relays exactly once. Flag OFF = the prior consume-at-debug behavior.
     */
    const relayed = (this.#gameRelay && this.#relayGameChannel != null)
      ? this.#relayGameChannel(this, message.payload)
      : 0;
    this.#logger?.debug?.('udp9090 lobby-game-channel-0f', {
      routingKey: this.#routingKey,
      loginIdentity: this.#loginIdentity,
      flags: `0x${message.flags.toString(16)}`,
      sequence: message.sequence,
      bytes: message.payload.length,
      body: message.payload.toString('hex'),
      frames: this.#gameChannelFrames,
      relayed,
      note: this.#gameRelay
        ? 'reliable op-0x0F game packet: relayed byte-identical to room members except the ' +
          'sender (SNAP_GAME_RELAY; bioserver GameServerPacketHandler default-branch analogue)'
        : 'reliable op-0x0F with 0x0400 clear: game-module traffic (client handler slot 0x12), ' +
          'not chat. Consumed; semantics Unknown - the raw body is the evidence a future RE needs'
    });
    return { opcode: message.opcode, answered: false, gameChannel: true };
  }

  /**
   * The in-game beacon: unreliable op-0x0F, flags `0x2012`, body `00 00`, 1 Hz.
   *
   * T37: after the game-module handoff the client sends this on its own sequence
   * counter for ~119 s, then aborts the scenario into the post-game meeting room.
   * Every one of the 115 was refused as `CHAT_RUNT` - a misfile, because it is
   * not chat: no reliable bit, no DATA flag, and the client's own dispatcher
   * sends this flag shape to slot 0x14, not the chat slots (B1 doc §4).
   *
   * WHAT IT EXPECTS IS UNKNOWN - the sender lives in the game module, outside
   * the 2549-function lobby corpus, and REOF2 stubs its network layer. Consuming
   * it here claims nothing about its semantics; it only stops classifying known
   * non-chat traffic as malformed chat. The echo and relay branches below are
   * the flag-gated EXPERIMENT of PORT-PLAN slice 2c(ii): the JP game server was
   * a dumb same-gamenumber relay, but solo JP relays nothing and PAL solo still
   * beacons - so a server echo is the live hypothesis, testable on the rig by
   * flipping one flag.
   */
  #onGameBeacon(message) {
    this.#gameBeacons += 1;
    /*
     * ECHO: the beacon back to its sender, verbatim in shape - same opcode, same
     * sub, same flags (SET only, DATA clear, unreliable), same 2-byte body. The
     * one thing that cannot be verbatim is the sequence: the channel owns the
     * unreliable counter (shared with the keepalive) and the client's test is
     * the monotonic `conn+0x10 <= seq`, so a stamped value is the correct form.
     */
    const echoed = this.#gameBeaconEcho
      ? this.#sendGameBeacon(message.payload, message.subSelector, message.flags)
      : false;
    // RELAY: room-scoped through the sessions table, never back to the sender.
    // Scope comes from the sender's presence, exactly like chat.
    const relayed = this.#gameBeaconRelay
      ? (this.#relayGameBeacon?.(this, message.payload, message.subSelector, message.flags) ?? 0)
      : 0;
    this.#logger?.debug?.('udp9090 lobby-game-beacon', {
      routingKey: this.#routingKey,
      loginIdentity: this.#loginIdentity,
      sequence: message.sequence,
      bytes: message.payload.length,
      body: message.payload.toString('hex'),
      beacons: this.#gameBeacons,
      echoed,
      relayed,
      note: 'unreliable op-0x0F with DATA clear: the in-game 1 Hz beacon, not chat. Consumed; ' +
        'semantics Unknown (game module, outside the lobby corpus)'
    });
    return { opcode: message.opcode, answered: echoed, gameBeacon: true, echoed, relayed };
  }

  /** Push one beacon to THIS session, preserving the observed unreliable shape. */
  deliverGameBeacon(payload, subSelector, flags) {
    if (this.#closed) return false;
    return this.#sendGameBeacon(payload, subSelector, flags);
  }

  /**
   * Push one relayed reliable game packet to THIS session (SNAP_GAME_RELAY).
   * Byte-identical payload, the sender's sub byte echoed, on this recipient's
   * own reliable sequence. Flags FLAG_SET alone = who 0xA0xx, the same
   * room-channel class the sender transmitted (0xA000 observed all night) and
   * the class the in-game slot-0x12 GamePacketRUDP callback receives.
   */
  deliverGamePacket(payload) {
    if (this.#closed) return false;
    return this.#send({
      opcode: LOBBY_OPCODE.CHAT,
      // sub 0, like every other room push (deliverRoomPush): echoing the
      // SENDER'S sub byte to a different recipient had no cited evidence and
      // the wire+0x02 byte is load-bearing elsewhere (nora caveat 6).
      subSelector: 0,
      payload,
      flags: FLAG_SET,
      event: 'game-packet-relay'
    });
  }

  #sendGameBeacon(payload, subSelector, flags) {
    try {
      this.#channel.sendUnreliable({
        opcode: LOBBY_OPCODE.CHAT,
        subSelector,
        payload,
        flags
      });
      return true;
    } catch (error) {
      if (!(error instanceof ReliableChannelError)) throw error;
      // A 1 Hz experiment losing one datagram is not worth a warn per second.
      this.#logger?.debug?.('udp9090 lobby-game-beacon-refused', {
        routingKey: this.#routingKey,
        code: error.code,
        reason: error.message
      });
      return false;
    }
  }

  /**
   * Resolve the room a screen-4 query names, accepting EITHER byte order.
   *
   * The handle round trip is byte-for-byte - the client stores the four bytes we
   * put at op-0x28 sel-4 body +0x04 and sends them straight back - so the correct
   * server behaviour is to not re-encode. But the one captured sample reads the
   * reverse of what we minted, from a console that had not created a room in that
   * window, so the attribution is Inference. Accepting both orders costs nothing
   * and removes an endianness bet from the critical path; the reply always echoes
   * the REQUEST's own bytes, so whichever order the client used, it gets it back.
   */
  #roomForHandleBytes(handleBytes) {
    const { forward, reversed } = resolveRoomHandleBytes(handleBytes);
    return this.#rooms.byHandle(forward) ?? this.#rooms.byHandle(reversed) ?? null;
  }

  /** The live members of a room, as member-list records. */
  #membersOf(room) {
    if (room == null) return [];
    return this.#presence.rosterOf(room.handle).map((entry, index) => ({
      name: entry.displayName || entry.userid || `P${index + 1}`,
      memberId: entry.presenceId ?? index + 1
    }));
  }

  /**
   * The members an op-28 sel-0x0a roster record declares (SNAP_MEMBER_INFO).
   *
   * In a room: the live roster, ids = 1-based JOIN ORDER - V1's scheme
   * (`buildRoomMemberListPacket`, `game_udp_server.js:1092`), NOT presenceId:
   * the RS1 collision hazard is exactly a presence id leaking into a
   * client-side id space. Outside a room: V1's synthetic single record,
   * unchanged from the months it ran on the rig.
   */
  #rosterRecordMembers() {
    const at = this.#presenceRecord.location();
    if (at.roomHandle != null) {
      const roster = this.#presence.rosterOf(at.roomHandle);
      if (roster.length > 0) {
        return roster.slice(0, 4).map((entry, index) => ({
          name: (entry.displayName || entry.userid || `PLAYER${index + 1}`).slice(0, 0x10),
          memberId: index + 1
        }));
      }
    }
    return [{ name: 'PLAYER1', memberId: 1 }];
  }

  /**
   * Push the op-0x10 sub-1 player-info to THIS session (SNAP_MEMBER_INFO).
   * who 0xA0/0xA3 - DATA and 0x0400 clear, the slot-0x13 routing; the July
   * frames are `a3 14 00 10` with the 0x304-byte body ported byte for byte.
   */
  #sendPlayerInfo(role, event, everyRefusalMatters = false) {
    return this.#send({
      opcode: LOBBY_OPCODE.ROOM_STATE,
      subSelector: 0,
      payload: buildPlayerInfoPayload({ role }),
      flags: FLAG_SET,
      event,
      everyRefusalMatters
    });
  }

  /**
   * The role byte of a sub-1 push for THIS session: 1 = host/creator (the
   * client's 0x6c5539 fork takes the STAT mint path), 0 = joiner. V1 keyed it
   * on its pending-create state; the durable equivalent is "this session
   * created the room it is in".
   */
  #playerInfoRole() {
    const at = this.#presenceRecord.location();
    return at.roomHandle != null && this.#createdRoom?.handle === at.roomHandle ? 1 : 0;
  }

  /**
   * op-0x0a MEMBER LIST - one of the three one-shot queries the client batches
   * after the create accept, and the selection query a joiner sends first.
   *
   * Answered DIRECT on opcode 0x0a with sub 0. Both are load-bearing: via op-0x28
   * the selector word would shift every field, and a non-zero sub makes
   * FUN_005c0ae0 return WITHOUT completing the task, which is a silent permanent
   * hang rather than a visible error.
   *
   * ## The reply content is the H-B discriminator (RS1-B §5, flag SNAP_OP0A_COUNT0)
   *
   * Every observed run splits on what this reply DECLARES: July V1 answered
   * `count 0`, 12 zero bytes, no records - and its joiner proceeded straight
   * down the ladder (op-06 ENTER, op-10 sub-2). V2's count-1 reply with a
   * zeroed 0xF0 charstats blob starved BOTH consoles that ever received it
   * ("Getting information", ~142 s, then a client op-0x02 close - T37 emulator
   * and RS1 PS2). Flag ON answers with the July shape, byte for byte,
   * including who 0xA0 (DATA clear - the routing `FUN_001d9f78` case 7
   * actually accepts for cmd 0x0a). Flag OFF keeps the previous count-1 reply
   * byte-identical.
   */
  #onMemberList(message) {
    let request;
    try {
      request = decodeMemberListRequest(message.payload);
    } catch (error) {
      return { opcode: message.opcode, answered: false, refusal: error.code ?? error.name };
    }
    const room = this.#roomForHandleBytes(request.handleBytes);
    if (this.#op0aCount0) {
      const answered = this.#send({
        opcode: LOBBY_OPCODE.MEMBER_LIST,
        subSelector: 0,
        payload: buildMemberListCount0Payload(),
        // who 0xA0: DATA deliberately CLEAR - the July wire byte (`a0 1c`) and
        // the only flag shape the client's cmd-0x0a dispatch routes to slot 0x18.
        flags: FLAG_SET,
        event: 'member-list'
      });
      this.#logger?.info?.('udp9090 lobby-member-list', {
        routingKey: this.#routingKey,
        loginIdentity: this.#loginIdentity,
        handle: `0x${request.handleBytes.toString('hex')}`,
        resolved: room != null,
        members: 0,
        answered,
        note: 'July V1 count-0 body (SNAP_OP0A_COUNT0): 12 zero bytes, who 0xA0 - the shape ' +
          'whose joiner proceeded; count-1-with-zeroed-blob starved two consoles (RS1-B H-B)'
      });
      return { opcode: message.opcode, answered, members: 0 };
    }
    const members = this.#membersOf(room);
    const answered = this.#send({
      opcode: LOBBY_OPCODE.MEMBER_LIST,
      subSelector: 0,
      payload: buildMemberListPayload({ handleBytes: request.handleBytes, members }),
      event: 'member-list'
    });
    this.#logger?.info?.('udp9090 lobby-member-list', {
      routingKey: this.#routingKey,
      loginIdentity: this.#loginIdentity,
      handle: `0x${request.handleBytes.toString('hex')}`,
      resolved: room != null,
      members: members.length,
      answered,
      note: 'direct opcode 0x0a, sub 0 -> FUN_001d8848 -> slot 0x18 FUN_005c0ae0; fills the ' +
        'DATA table at 0x6cdbe6, which is not the drawn roster'
    });
    return { opcode: message.opcode, answered, members: members.length };
  }

  /**
   * op-0x09 USER / MAXI - the current and maximum member counts.
   *
   * Both counts are DERIVED: USER is the live presence count in the room, MAXI is
   * the room's own capacity. Neither is stored and neither is incremented, so
   * they cannot drift from who is actually connected.
   *
   * An unknown tag is still answered. FUN_005c0060 stores nothing for one but
   * still completes the task, so refusing would convert a wrong number into a
   * hang - strictly worse.
   */
  #onAreaCountQuery(message) {
    let request;
    try {
      request = decodeAreaCountRequest(message.payload);
    } catch (error) {
      return { opcode: message.opcode, answered: false, refusal: error.code ?? error.name };
    }
    /*
     * THE FIRST FIELD IS A BOX ID, NOT A ROOM HANDLE. Corrected 2026-08-08 from
     * the T37 rig run, and it is worth stating how it went wrong.
     *
     * Every observed op-0x09 carries the id of the AREA the client is in: T35 sent
     * `00000001` and `00000005` while entering boxes 1 and 5; T37 sent `00000009`
     * while in box 9. The wire has never once carried a room handle here. I said
     * exactly that when I first extracted those bytes - then the subsystem spec
     * called the field a handle, and I implemented the spec over my own evidence.
     *
     * The cost was visible: resolving 9 as a room handle found nothing, so USER
     * answered 0 for every query, which is the "1/0p" - one player, zero maximum -
     * the owner saw in the room, and part of why Server Select read wrong.
     *
     * A room handle is still accepted as a FALLBACK, because a room-scoped variant
     * of this query is not ruled out and answering the wrong number is better than
     * answering nothing on a path with no client-side retry.
     */
    const boxId = request.handleBytes.readUInt32BE(0);
    const areaPopulation = this.#playerCountFor({ boxId });
    const room = this.#roomForHandleBytes(request.handleBytes);
    const isMaximum = request.tag.equals(AREA_COUNT_TAG_MAXIMUM);
    const isCurrent = request.tag.equals(AREA_COUNT_TAG_CURRENT);
    /*
     * MAXI is the room's capacity when this resolves to a room, otherwise the
     * advertised area capacity. UNCONFIRMED: the T37 run only ever issued USER, so
     * nothing has exercised MAXI on a real console yet.
     */
    const value = isMaximum
      ? (room?.max ?? this.#roomCapacity)
      : (isCurrent ? (room != null ? this.#presence.countInRoom(room.handle) : areaPopulation) : 0);
    const answered = this.#send({
      opcode: LOBBY_OPCODE.AREA_COUNT_QUERY,
      // Echoed: FUN_001d84cc matches the task on this byte.
      subSelector: message.subSelector,
      payload: buildAreaCountReplyPayload({
        handleBytes: request.handleBytes, tag: request.tag, value
      }),
      event: 'area-count'
    });
    this.#logger?.info?.('udp9090 lobby-area-count', {
      routingKey: this.#routingKey,
      loginIdentity: this.#loginIdentity,
      tag: request.tag.toString('latin1'),
      field: `0x${request.handleBytes.toString('hex')}`,
      asBoxId: boxId,
      areaPopulation,
      resolvedAsRoom: room != null,
      value,
      recognisedTag: isMaximum || isCurrent,
      answered,
      // CORRECTED this round (RS1 pcap + FUN_001d9f78 case 6): the entry query
      // is the DATA-set form (wire 0xB018) and routes to slot 0x17 FUN_005bf740;
      // the DATA-clear/seq-0 twin (0xA018, room-scoped USER+MAXI) is what lands
      // on slot 0x16 FUN_005c0060. Both echo-match and commit the same way.
      note: 'direct opcode 0x09 -> FUN_001d84cc -> slot 0x17 FUN_005bf740 (DATA set) / ' +
        'slot 0x16 FUN_005c0060 (DATA clear); counts are derived from presence, never stored'
    });
    return { opcode: message.opcode, answered, value };
  }

  /**
   * op-0x08 STAT - the named-channel query.
   *
   * This is NOT the exit button; that is op-0x07 and is handled separately. This
   * one is answered because its reply is the ONLY exit from the roster SM's single
   * unbounded wait (phase 1, driven by FUN_005c28f0(0, 0x5C6350)) - so silence
   * here is a permanent hang, not a slow path.
   *
   * op-0x28 selector 8 is the only route that reaches reply slot 0x25
   * (conn+0x5DC). Status is 0: FUN_005c29c0 completes on 0x27 too, but through
   * the FAILURE path.
   */
  #onNamedChannelQuery(message) {
    let request;
    try {
      request = decodeNamedChannelRequest(message.payload);
    } catch (error) {
      return { opcode: message.opcode, answered: false, refusal: error.code ?? error.name };
    }
    const answered = this.#send({
      opcode: LOBBY_OPCODE.COMPLETION,
      subSelector: message.subSelector,
      payload: buildNamedChannelCompletionPayload({ tag: request.tag }),
      event: 'named-channel-completion'
    });
    this.#logger?.info?.('udp9090 lobby-named-channel', {
      routingKey: this.#routingKey,
      loginIdentity: this.#loginIdentity,
      tag: request.tag.toString('latin1'),
      answered,
      note: 'op-0x28 selector 8 status 0 -> slot 0x25; the ONLY exit from the roster SM phase-1 ' +
        'wait, so silence here is a permanent hang'
    });
    return { opcode: message.opcode, answered, tag: request.tag.toString('latin1') };
  }

  #onCreateRoom(message) {
    const request = decodeCreateRoomRequest(message.payload);
    const boxId = this.#presenceRecord.boxId;
    if (boxId == null) {
      /*
       * REJECTED, not ignored. A create from a session with no area has nowhere
       * to put the room, and a silent drop is indistinguishable to the client
       * from a server that is not there - it would sit in step 2 forever, which
       * is the freeze this handler exists to remove. The reject still unfreezes
       * the cursor because `FUN_005fc400` ignores the status.
       */
      return this.#refuseCreate(message, LOBBY_SESSION_REFUSAL.CREATE_WITHOUT_AREA, request);
    }

    let room;
    try {
      // MUTATE FIRST: the room exists server-side, with its host inside it,
      // before the accept that carries its handle leaves. The reverse order would
      // hand the client a token for something that does not exist yet.
      room = this.#rooms.openFor({
        presence: this.#presence,
        host: this.#presenceRecord,
        boxId,
        name: request.name != null && request.name.length > 0 ? request.name : this.#roomName,
        max: this.#roomCapacity,
        /*
         * SNAP_ROOM_STAT (2026-08-24, analysis/op10-gamechannel-blobs-RE): the
         * create body's optionsWord (+0x28) IS the room STAT attribute the host
         * chose - scenario, rule locks, password and area packed. The joiner
         * reads it from the op-0x49 record +0x1c and computes scenario id =
         * (STAT>>1)&0xFF (arithmetic-proved: tonight's 0x020b0a10 -> 8 = the
         * host's ring value). Without it every joiner decodes 0 = Training.
         * flags=0 when the flag is off or the client sent no word (byte-inert).
         */
        flags: (this.#roomStat && request.optionsWord != null) ? request.optionsWord : 0
      });
    } catch (error) {
      return this.#refuseCreate(message, `${error.code ?? error.name}: ${error.message}`, request);
    }
    this.#createdRoom = room;
    this.#registerCreatedRoom(room);

    const answered = this.#send({
      opcode: LOBBY_OPCODE.COMPLETION,
      // Echoed. `FUN_005c3a40` reads only `0(s1)` so it does not consume this,
      // but the sub byte IS the match key on the op-0x0c path and echoing is a
      // superset of every observed input. Note the rule is path-specific: with
      // header bit 0x2000 set the transport forces these fields to 0 regardless.
      subSelector: message.subSelector,
      payload: buildCreateRoomAcceptPayload({ handle: room.handle }),
      event: 'create-room-accept',
      // The client asks ONCE and then parks with no timeout. A refused accept is
      // a permanently frozen cursor, not a dropped poll.
      everyRefusalMatters: true
    });

    if (answered) this.#sendCreateFollowUps(room);

    const level = answered ? this.#logger?.info : this.#logger?.warn;
    level?.call(this.#logger, 'udp9090 lobby-create-room', {
      routingKey: this.#routingKey,
      loginIdentity: this.#loginIdentity,
      boxId,
      handle: `0x${room.handle.toString(16)}`,
      name: room.name,
      requestedName: request.name,
      requestedMaximum: request.maximumPlayers,
      requestedOptions: request.optionsWord == null
        ? null
        : `0x${request.optionsWord.toString(16)}`,
      answered,
      note: answered
        ? 'op-0x28 selector 4 accept -> slot 0x1f FUN_005c3a40 -> 0x6CBA7D=1, 0x6FF2B0=1 -> the ' +
          'pump sets 0x6FF2B1=1 and the cursor moves'
        : 'the create accept was REFUSED by the reliable channel; this client is parked in ' +
          'FUN_005c3490 step 2 with no timeout exit'
    });
    return { opcode: message.opcode, answered, handle: room.handle, boxId };
  }

  /**
   * The engine bookkeeping of a created room - status + host attributes.
   * Wire-invisible, and it must NEVER block the rig-confirmed accept: a
   * refused lifecycle record is a logged engine defect, not a frozen cursor.
   *
   * INCREATE and GAMESET in one step, deliberately: bioserver's INCREATE
   * window is the create DIALOGUE, and PAL's op-0x04 arrives at that
   * dialogue's Finish (2026-07-25 decisive read: "op04 DOES mint on Finish"),
   * so by the time this runs the dialogue is over and the room is joinable -
   * which is also what the July rig joins required.
   */
  #registerCreatedRoom(room) {
    if (this.#roomLifecycle == null || this.#slotAllocator == null) return;
    try {
      this.#roomLifecycle.beginCreate(room.handle, { areaNumber: room.boxId });
      this.#roomLifecycle.completeCreate(room.handle, { nowMs: 0 });
      this.#slotAllocator.assignHost({ room, hostPresence: this.#presenceRecord });
    } catch (error) {
      this.#logger?.warn?.('udp9090 lobby-room-lifecycle-refused', {
        routingKey: this.#routingKey,
        loginIdentity: this.#loginIdentity,
        handle: `0x${room.handle.toString(16)}`,
        code: error.code ?? error.name,
        reason: error.message,
        note: 'the room exists and the accept still goes out; joins into it will be refused ' +
          'not-possible until the engine record exists'
      });
    }
  }

  /**
   * Refuse a create with wire opcode `0x27`, and ONLY `0x27`.
   *
   * `param_1` of every app callback is a LOCAL in `FUN_001d9f78`, zeroed in the
   * prologue and set to `0x27` at the `case 0x24` entry, which then falls through
   * into the identical selector dispatch. So the reject is an OPCODE change, not
   * a payload edit, and there is no status field to find.
   *
   * Wire `0x31` also sets that local but is NOT usable here: its own case body
   * dispatches to slot 0x1c and clears `conn+0x7c`/`conn+0x80` without ever
   * reaching the selector switch (`CORRECTIONS.md` C-8).
   */
  #refuseCreate(message, reason, request) {
    const answered = this.#send({
      opcode: LOBBY_OPCODE.COMPLETION_REJECT,
      subSelector: message.subSelector,
      // The handle is meaningless on a reject and `FUN_005c3a40` does not reach
      // the store on the 0x27 path, but the payload must still carry the selector
      // that routes it - the dispatch is identical.
      payload: buildCreateRoomAcceptPayload({ handle: 0 }),
      event: 'create-room-reject',
      everyRefusalMatters: true
    });
    this.#logger?.warn?.('udp9090 lobby-create-room-refused', {
      routingKey: this.#routingKey,
      loginIdentity: this.#loginIdentity,
      boxId: this.#presenceRecord.boxId,
      requestedName: request?.name ?? null,
      answered,
      reason,
      note: 'op-0x27 selector 4; the reject still unfreezes the cursor because FUN_005fc400 does ' +
        'not inspect the status - only the accept sets 0x6FF2B0/0x6FF2B1'
    });
    return { opcode: message.opcode, answered, handle: null, refused: reason };
  }

  /**
   * What the client needs immediately after the create accept, and nothing more.
   *
   * Two messages, both established - one by the corpus and rig, one by V1:
   *
   *   op-0x06 member-JOIN, as the FIRST in-window reliable after the accept. The
   *   drawn roster at `0x6c7c2c` is filled ONLY by this handler (`FUN_005bb4d0`),
   *   and the client's reorder gate acks an inbound reliable segment only if its
   *   sequence is at or above the live expected sequence - so emitted mid-burst
   *   it was dropped un-acked 12 times in 13, and emitted here, contiguous with
   *   the accept, it landed. `SNAP_MEMBER_JOIN_AT_ACCEPT`, rig-confirmed to
   *   populate row 0.
   *
   *   op-0x10 sub-5, the "MAX / CURRENT P" header. The client zeroes `0x6ff2b4`
   *   on every screen rebuild and this is its only non-zero writer.
   *   `SNAP_ROOM_LIMITS_OP10SUB5`, rig-confirmed to render.
   *
   * DELIBERATELY NOT SENT, and each for a stated reason rather than by omission:
   *
   *   The ~500 ms re-emit of the same op-0x06 (`SNAP_MEMBER_JOIN_SETTLE`). The
   *   corpus grades it "deployed, needs the confirming rig run" - it is the exact
   *   open test, not an established step, and it needs a timer whose delay has no
   *   evidence behind it.
   *
   *   op-0x28 selector 0x0a, the full roster. It is a POLL response; sending it
   *   unasked would be a push on a path the client drives.
   *
   *   op-0x10 sub-0x11, the member count. Redundant with sub-5's current byte for
   *   a one-member room, and its own consumer is a different display.
   */
  #sendCreateFollowUps(room) {
    const memberName = this.#loginIdentity.slice(0, 0x10);
    this.#send({
      opcode: LOBBY_OPCODE.MEMBER_JOIN,
      subSelector: 0,
      payload: buildMemberJoinPayload({
        name: memberName,
        memberId: room.handle,
        // Distinct from a joiner's, so the client's dedup (`FUN_005b5ac0`) admits
        // both rather than treating the second member as a repeat of the first.
        characterId: 1
      }),
      /*
       * who = 0xA0: RELIABLE | SET with DATA deliberately CLEAR. `FUN_001d6988`
       * routes on the DATA bit and the member-JOIN goes to slot 2; V1 shipped
       * 0xA0 here and it is the form that populated the roster.
       */
      flags: FLAG_SET,
      event: 'create-member-join',
      everyRefusalMatters: true
    });
    this.#send({
      opcode: LOBBY_OPCODE.ROOM_STATE,
      subSelector: 0,
      payload: buildRoomLimitsPayload({ max: room.max, current: room.current }),
      flags: FLAG_SET,
      event: 'create-room-limits',
      everyRefusalMatters: true
    });
  }

  /**
   * Re-seat THIS host in its own 0x6c7c2c (SNAP_HOST_RESEAT, T20).
   *
   * The host self-seats at create, but the screen rebuild when a joiner arrives
   * clears 0x6c7c2c (FUN_005aec20), leaving only the joiner's fresh seat - so
   * the start roster (0x6ff70d ← 0x6c7c2c) counts 1, not 2, and the solo
   * shortcut (0x6ff2b3 < 2) fires even though the joiner's accept matched
   * (RIG slot 4: 0x6ff2b5=01, count=1). Re-emitting the host's own op-06
   * BEFORE the joiner's fan-out puts the host back at slot 0 (pre-accepted at
   * SM state 0) and the joiner at slot 1 (accepted via its sub-4) → count 2 →
   * non-solo start. No-op for a non-host session.
   */
  reseatSelf() {
    if (this.#createdRoom == null) return false;
    return this.#send({
      opcode: LOBBY_OPCODE.MEMBER_JOIN,
      subSelector: 0,
      payload: buildMemberJoinPayload({
        name: this.#loginIdentity.slice(0, 0x10),
        memberId: this.#createdRoom.handle,
        characterId: 1
      }),
      flags: FLAG_SET,
      event: 'host-reseat',
      everyRefusalMatters: true
    });
  }

  /**
   * The op-0x07 LEAVE - backing out of a room or an area.
   *
   * ## The same shape as the create freeze, and the same kind of fix
   *
   * `snap_send_leave` (0x001dd07c) sends a ZERO-LENGTH reliable op-0x07 with
   * `who = 0xb000` and installs its callback at slot **0x23**. It is called from
   * `FUN_005bfe00`, which `FUN_005c1c80` invokes in step 2; step 3 is then a pure
   * wait on `cRam006cbb6d` with **no timeout branch and no other exit**.
   *
   * A savestate taken at the moment a back-out failed on the rig shows exactly
   * that: `0x6c4b90 = 2` (the in-area lobby is on screen), `0x6cbb6c = 1` (the SM
   * is armed), `0x6cbb68 = 3` (parked in the wait), `0x6cbb6d = 0` (no signal),
   * `0x6cbb4c = 0x5f81a0` (a live completion callback). The client sent op-0x07
   * and is waiting for a reply V2 never had a case for.
   *
   * ## Selector 7, derived not guessed
   *
   * `FUN_001d9f78`'s inner switch on `selector - 1`, entry 6, with the DATA flag
   * set, loads `conn + 0x5D4`; `0x5D4 = 0x548 + 0x23*4` = slot 0x23 - which is
   * precisely the slot `snap_send_leave` installs into. Two independent corpus
   * records agree, and the same arithmetic reproduces the two selectors already
   * proven on the rig.
   *
   * ## Presence
   *
   * One message covers both "leave this room" and "leave this area" - which of
   * the two it means is decided by which channels `FUN_005c1c80` step 2 found
   * occupied, and the server cannot see that. So the presence cursor rises by ONE
   * level, which matches the client's single message instead of guessing.
   */
  /**
   * The flag word for a completion reply: default `FLAG_SET | FLAG_DATA` (who
   * 0xB0xx — the rig-confirmed shape for every lobby-channel request), or,
   * under `channelBitEcho`, `FLAG_SET` plus the REQUEST's own DATA bit — so a
   * room-channel (0xA0xx, DATA clear) leave gets a room-channel completion and
   * `FUN_001d9f78` case 6 routes it to the callback slot the client armed.
   *
   * SCOPED TO THE SEL-7 LEAVE ONLY (nora pre-deploy review 2026-08-24,
   * caveat 1): room-query/re-entry/STAT also arrive DATA-clear (~17-27 replies
   * per session), their dispatch is single-slot so 0xB0xx cannot mis-route,
   * and their callbacks' reading of the header channel bit is UNREAD
   * (FUN_005b52e0 and the sub-8/sub-0x0d consumers). Widen only with that
   * evidence, or after a rig run proves the sel-7 flip and a second run covers
   * create + re-entry explicitly.
   */
  #completionChannelFlags(message) {
    if (!this.#channelBitEcho) return FLAG_SET | FLAG_DATA;
    return FLAG_SET | (message.flags & FLAG_DATA);
  }

  #onLeave(message) {
    const from = this.#presenceRecord.location();
    const depth = this.#presence.ascend(this.#presenceRecord);
    if (from.roomHandle != null && this.#createdRoom?.handle === from.roomHandle) {
      // The registry closes an emptied room through presence's own hook, so this
      // only forgets the session's reference to it.
      this.#createdRoom = null;
    }
    if (this.#countPush && from.boxId != null &&
        this.#presenceRecord.location().boxId !== from.boxId) {
      /*
       * SNAP_COUNT_PUSH (RS1-C C2): the JP `sendExitArea` -> `broadcastAreaPlayerCnt`
       * analogue. Only when this ascend actually LEFT the box - a room-level
       * ascend (depth 4 -> 2) keeps boxId and changes no area count, and
       * pushing there would be noise on the exact path C3 shows is fragile.
       */
      this.#pushAreaCount(from.boxId, this);
    }
    const answered = this.#send({
      opcode: LOBBY_OPCODE.COMPLETION,
      subSelector: message.subSelector,
      flags: this.#completionChannelFlags(message),
      payload: buildCompletionPayload({
        selector: COMPLETION_SELECTOR.AREA_LEAVE,
        status: 0,
        // B3 fix 2, as on the ENTER accept: FUN_005bfe90 latches (u16)payload+0xc
        // and the pool sweep needs it to equal the request's send-seq (B3 doc §3).
        sendSeqEcho: this.#completionSeqEcho ? message.sequence : null
      }),
      event: 'leave-accept',
      // Asked once, waited on forever. Identical to the ENTER and the create.
      everyRefusalMatters: true
    });
    const level = answered ? this.#logger?.info : this.#logger?.warn;
    level?.call(this.#logger, 'udp9090 lobby-leave', {
      routingKey: this.#routingKey,
      loginIdentity: this.#loginIdentity,
      from,
      depth,
      answered,
      note: answered
        ? 'op-0x28 selector 7 -> slot 0x23 FUN_005bfe90 -> FUN_005c1c80 step 3 releases'
        : 'the LEAVE accept was REFUSED; this client is parked in FUN_005c1c80 step 3 with no ' +
          'timeout exit and cannot back out'
    });
    return { opcode: message.opcode, answered, depth };
  }

  #onRoomList(message) {
    const rooms = this.#roomListProvider(this.#presenceRecord.boxId);
    /*
     * SNAP_ROOMFLAGS_PUBLISH (default OFF): surface the engine's authored
     * status in the record flags word `+0x1c`, raw (GAMESET=3 joinable,
     * BUSY=4 in-game). EVIDENCE-GATED, stated plainly: no console has ever
     * been shown non-zero values here, and the VALUE is a hypothesis - the
     * flag exists so one rig run can show what the client renders for it.
     * Off, the records are byte-identical to every previous build.
     */
    const published = this.#roomFlagsPublish
      ? rooms.map((room) => ({
        name: room.name,
        current: room.current,
        max: room.max,
        handle: room.handle,
        flags: this.#roomLifecycle.statusOf(room.handle)
      }))
      : rooms;
    const answered = this.#send({
      opcode: LOBBY_OPCODE.ROOM_LIST,
      subSelector: message.subSelector,
      payload: buildRoomListPayload({ rooms: published }),
      event: 'room-list-reply'
    });
    this.#logger?.info?.('udp9090 lobby-room-list', {
      routingKey: this.#routingKey,
      loginIdentity: this.#loginIdentity,
      boxId: this.#presenceRecord.boxId,
      rooms: rooms.length,
      answered,
      note: this.#presenceRecord.boxId == null
        ? 'this session has entered no area; an empty list is the only honest answer'
        : 'the rooms held for this area'
    });
    return { opcode: message.opcode, answered, rooms: rooms.length };
  }

  /**
   * The client's op-0x41.
   *
   * It is RELIABLE, so the acknowledgement the channel already sent is the whole
   * obligation - the archive shows V1 acking it and answering nothing else
   * (`SNAP_SUPPRESS_UNKNOWN_REPLY`). Counted, because a session whose keepalives
   * are going out and whose responses are not coming back has lost the return
   * path, and that is worth being able to see before 840 does the telling.
   */
  #onKeepaliveResponse(message) {
    this.#keepaliveResponses += 1;
    this.#logger?.debug?.('udp9090 lobby-keepalive-response', {
      routingKey: this.#routingKey,
      sequence: message.sequence,
      sent: this.#keepalivesSent,
      received: this.#keepaliveResponses
    });
    return { opcode: message.opcode, answered: false };
  }

  /**
   * The cmd-0x14 RTT/bandwidth probe: 68 bytes, non-reliable, `0x55` filler.
   *
   * `FUN_005bcc30` sends it once per re-entry, guarded by `cRam006ff2ac`, before
   * the op-0x0d status test. It arms no watchdog and nothing is known to consume
   * a reply, so it is absorbed at debug and answered with nothing. It is here as
   * a NAMED case rather than falling through so it never becomes log spam on a
   * path the client takes every time it comes back to the lobby.
   */
  #onRttProbe(message) {
    this.#logger?.debug?.('udp9090 lobby-rtt-probe', {
      routingKey: this.#routingKey,
      bytes: message.innerLength,
      note: 'FUN_005bcc30 bandwidth probe; absorbed, no reply is known to be expected'
    });
    return { opcode: message.opcode, answered: false };
  }

  /* ---- sending ---------------------------------------------------------- */

  /**
   * Every application reply in this phase is a WINDOWED reliable DATA message and
   * therefore STAMPS its own sequence.
   *
   * The split is the load-bearing one: the slot-0x1c push carries a CONSTANT
   * sequence (it is an out-of-band control push, the register service sends it,
   * and it is the epoch's first reliable message), and everything here stamps
   * from the session counter seeded one above it. V1 shipped this backwards in
   * both directions - once mirroring what should have stamped
   * (`game_udp_server.js:826-837`) and once stamping what should not have
   * (`:2991-3000`) - and the second produced "the following named-slot/cmd0c
   * reply landed at seq=2 > recvBase=1 -> buffered -> 840".
   */
  #send({
    opcode, subSelector, payload, flags = FLAG_SET | FLAG_DATA, event, everyRefusalMatters = false
  }) {
    try {
      this.#channel.sendReliable({ opcode, subSelector, payload, flags });
      return true;
    } catch (error) {
      if (!(error instanceof ReliableChannelError)) throw error;
      /*
       * The window is full, or the channel is dead. Reported, never retried here:
       * the channel already retransmits what is in flight, and a second copy on
       * a fresh sequence would put two live messages in front of the client for
       * one request.
       */
      this.#logRefusal(event, error, everyRefusalMatters);
      return false;
    }
  }

  /**
   * Journal a refused send: the first of its kind in full, then a bounded rollup.
   *
   * `everyRefusalMatters` marks the sends whose loss is not a dropped poll but a
   * dead end for the player - the ENTER accept above all, because the client
   * asks ONCE and a lobby that is never accepted never appears. Those are logged
   * every time, however many there are, because "however many" is one or two.
   */
  #logRefusal(event, error, everyRefusalMatters) {
    const refusals = (this.#sendRefusals.get(event) ?? 0) + 1;
    this.#sendRefusals.set(event, refusals);
    const first = refusals === 1;
    const rollup = refusals % REFUSAL_LOG_INTERVAL === 0;
    if (!everyRefusalMatters && !first && !rollup) return;
    this.#logger?.warn?.(`udp9090 lobby-${event}-refused`, {
      routingKey: this.#routingKey,
      loginIdentity: this.#loginIdentity,
      code: error.code,
      reason: error.message,
      unacknowledged: this.#channel.unacknowledgedCount,
      // The count is on every line, so a rollup never understates what happened
      // and the suppressed lines are accounted for rather than lost.
      refusals,
      suppressed: first || everyRefusalMatters ? 0 : REFUSAL_LOG_INTERVAL - 1,
      note: LOBBY_SESSION_REFUSAL.SEND_REFUSED
    });
  }

  #armKeepalive() {
    this.#keepaliveHandle = this.#wheel.schedule({
      delayMs: this.#keepalivePeriodMs,
      owner: this,
      name: 'op40-keepalive',
      callback: () => this.#onKeepaliveDue()
    });
  }

  #onKeepaliveDue() {
    this.#keepaliveHandle = null;
    if (this.#closed) return;
    this.#sendKeepalive();
    // Re-armed AFTER the send but unconditionally: a send that fails is a lost
    // datagram, not a reason to stop feeding a watchdog that will otherwise
    // expire into error 840.
    this.#armKeepalive();
  }

  #sendKeepalive() {
    try {
      // NON-reliable by construction: `who = 0x3000 | len`. Reliable would put it
      // in the client's ordered window, where one gap would stop every later
      // keepalive being delivered - and the watchdog it feeds is the one thing
      // that must never depend on the ordered stream making progress.
      this.#channel.sendUnreliable({
        opcode: LOBBY_OPCODE.KEEPALIVE,
        subSelector: 0,
        payload: this.#keepalivePayload,
        flags: FLAG_SET | FLAG_DATA
      });
      this.#keepalivesSent += 1;
    } catch (error) {
      if (!(error instanceof ReliableChannelError)) throw error;
      this.#logger?.warn?.('udp9090 lobby-keepalive-refused', {
        routingKey: this.#routingKey,
        loginIdentity: this.#loginIdentity,
        code: error.code,
        reason: error.message
      });
    }
  }

  #armAppKeepalive() {
    this.#appKeepaliveHandle = this.#wheel.schedule({
      delayMs: APP_KEEPALIVE_PERIOD_MS,
      owner: this,
      name: 'app-keepalive',
      callback: () => this.#onAppKeepaliveDue()
    });
  }

  #onAppKeepaliveDue() {
    this.#appKeepaliveHandle = null;
    if (this.#closed) return;
    this.#sendAppKeepalive();
    // Re-armed unconditionally, exactly like op-0x40: a refused send is one
    // missed reset inside a 72.8 s idle budget with 2.4x margin, not a reason
    // to stop feeding a watchdog whose expiry is the op-0x02 self-close.
    this.#armAppKeepalive();
  }

  /**
   * The application-liveness keepalive: op-0x10, who 0xA000, app payload 0x00.
   *
   * RELIABLE with `FLAG_SET` and DATA deliberately CLEAR - the same who-0xA0
   * form as the rig-proven sub-0x0C join-confirm push, because the client
   * dispatcher's case 0xd routes an op-0x10 to the slot-0x13 handler only when
   * `0x8000` is set and `0x1000`/`0x0400` are clear (a `0xB0xx` DATA-set frame
   * routes elsewhere and resets nothing). `FUN_005bba20` then calls
   * `FUN_005c7d00()` before its switch, which also cancels an outstanding
   * op-0x14 probe - so this one push is both halves of the liveness answer.
   *
   * The handle word is the session's room handle when it is in a room, 0 on
   * the lobby floor; the sub-0x00 path never consults it (`ROOM-WATCHDOG-RE.md`
   * §3.2). Read at send time from presence, never cached.
   */
  #sendAppKeepalive() {
    const handle = this.#presenceRecord.location().roomHandle ?? 0;
    const sent = this.#send({
      opcode: LOBBY_OPCODE.ROOM_STATE,
      subSelector: 0,
      payload: buildAppKeepalivePayload({ handle }),
      flags: FLAG_SET,
      event: 'app-keepalive'
    });
    if (sent) {
      this.#appKeepalivesSent += 1;
      // The rig-verification journal line (ROOM-WATCHDOG-RE.md §7): once per
      // 30 s per session, at debug like the op-0x41 counterpart.
      this.#logger?.debug?.('udp9090 lobby-app-keepalive', {
        routingKey: this.#routingKey,
        handle: `0x${handle.toString(16)}`,
        sent: this.#appKeepalivesSent
      });
    }
  }

  #armIdle() {
    this.#datagramsSinceIdleArm = 0;
    this.#idleHandle = this.#wheel.schedule({
      delayMs: this.#idleTimeoutMs,
      owner: this,
      name: 'idle-release',
      callback: () => this.#onIdleDue()
    });
  }

  #onIdleDue() {
    this.#idleHandle = null;
    if (this.#closed) return;
    if (this.#datagramsSinceIdleArm > 0) {
      // Traffic arrived since this was armed, so the session is alive. Re-arm
      // rather than re-arming per datagram: the release is at worst one timeout
      // period late, and that is a bound, not a deadline.
      this.#armIdle();
      return;
    }
    this.#logger?.warn?.('udp9090 lobby-session-idle', {
      routingKey: this.#routingKey,
      loginIdentity: this.#loginIdentity,
      idleTimeoutMs: this.#idleTimeoutMs,
      note: 'no datagram for longer than the client\'s own watchdogs; releasing the session ' +
        'and its keepalive timer'
    });
    this.#onIdle?.(this);
  }
}
