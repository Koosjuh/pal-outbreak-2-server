import { blowfishEcbEncrypt, createBlowfishKey } from '../crypto/blowfish.js';
import { GameSessionRegistry } from '../state/game-session.js';
import { LobbyRoomRegistry } from '../state/lobby-rooms.js';
import { PlayerProfileRegistry } from '../state/player-profile.js';
import { PresenceRegistry } from '../state/presence.js';
import { RoomLifecycleRegistry } from '../state/room-lifecycle.js';
import { SlotAllocator } from '../state/slot-allocator.js';
import {
  KEEPALIVE_PLAINTEXT_BYTES, LOBBY_OPCODE, buildRoomChatSub7Payload
} from './snap-lobby-codec.js';
import {
  DEFAULT_IDLE_TIMEOUT_MS,
  DEFAULT_KEEPALIVE_PERIOD_MS,
  SnapLobbySession
} from './snap-lobby-session.js';

/**
 * The owner of every live post-selection SN@P session.
 *
 * One instance holds the shared, expensive and dangerous things - the timing
 * wheel, the keepalive key schedule, the published area directory, the room
 * model - and hands each session a view of them. It is ALSO the only thing that
 * can answer "how many players are in area N", because that is a fact about the
 * set of sessions rather than about any one of them. There is no module-level
 * state and no singleton:
 * two instances with different directories can run side by side, which is what
 * makes the tests deterministic and what makes a second listener possible.
 *
 * ## The keepalive key, and the one place this project's evidence disagrees
 *
 * The body is Blowfish-ECB over `0x110` zero bytes. The KEY V1 shipped, and the
 * key in the golden flag set, is the nine literal ASCII bytes `SNAP-SWAN`
 * (`deploy/pi-env.d/zzz-op40-keepalive.conf`, `SNAP_OP40_KEY=SNAP-SWAN`), used
 * raw. Runtime backs it: the archive session sent 27 000 datagrams over that
 * keepalive and a real PS2 answered every one with an op-0x41 within 100 ms,
 * which it could not do if the body had decrypted to garbage lengths - that path
 * `memcpy`s four plaintext length words and overruns its stack.
 *
 * DISAGREEING EVIDENCE, recorded rather than smoothed over:
 * `docs/findings/protocol/UDP9090-REGISTER-RE-2026-08-03.md:34` states that
 * `blowfish_ecb_hashed_key` (0x001ea8e8, SHA-1 keyed) has exactly one caller and
 * it is `FUN_001d9b6c`, the op-0x40 path. If that reading is right, the client
 * decrypts under SHA-1(key) and the raw-key ciphertext should NOT have produced
 * zeros. Runtime outranks decompile in this project, so the proven bytes ship -
 * but the key is a REQUIRED, injected value with no default precisely so the
 * alternative can be tried by configuration rather than by editing a handler.
 * The ciphertext itself has never been captured; only its effect has.
 */

/**
 * `conn+0x51c = conn+0x510 * 32 + 4000`. `conn+0x510` is the `LC` TLV the client
 * puts in its own register and bind, so the budget is a per-session value that
 * the client declares - never a constant. With the observed `LC = 1600` it is
 * 55 200 ms.
 */
export function watchdogBudgetMsFromLatencyTicks(latencyTicks) {
  if (!Number.isSafeInteger(latencyTicks) || latencyTicks < 0) return null;
  return latencyTicks * 32 + 4000;
}

/** The register/bind TLV tag carrying `conn+0x510` (ELF string 0x259290). */
export const LATENCY_TLV_TAG = 'LC';

/** Read `LC` out of a decoded TLV list, or null when the client did not send it. */
export function latencyTicksFromTlvs(tlvs) {
  if (!Array.isArray(tlvs)) return null;
  const entry = tlvs.find((tlv) => tlv?.tag === LATENCY_TLV_TAG);
  return entry == null ? null : entry.value;
}

export class SnapLobbySessionsError extends Error {
  constructor(code, message) {
    super(message);
    this.name = 'SnapLobbySessionsError';
    this.code = code;
  }
}

function fail(code, message) {
  throw new SnapLobbySessionsError(code, message);
}

/** Bounded like every other table here: a full one refuses, it never evicts. */
const DEFAULT_MAXIMUM_SESSIONS = 4096;

export class SnapLobbySessions {
  #wheel;
  #areaDirectory;
  #keepaliveCiphertext;
  #keepalivePeriodMs;
  #idleTimeoutMs;
  #successTransition;
  #gameBeaconEcho;
  #gameBeaconRelay;
  #roomChatSub7;
  #gameRelay;
  #exitCloseMirror;
  #completionSeqEcho;
  #channelBitEcho;
  #joinLadder;
  #op10Relay;
  #op0aCount0;
  #memberInfo;
  #roomFlagsPublish;
  #roomStat;
  #reliableWindow;
  #memberIdToken;
  #rosterToJoiner;
  #hostReseat;
  #countPush;
  #appKeepalive;
  #rooms;
  #presence;
  #profiles;
  #roomLifecycle;
  #slotAllocator;
  #gameSessions;
  #serverEntryId;
  #logger;
  #maximum;
  #sessions = new Map();
  /**
   * `loginIdentity` -> the routing key its live session is open on.
   *
   * The transport layer's business, deliberately NOT a field on the presence
   * record. Presence is keyed on the identity the registration proved and knows
   * nothing about addresses - that is the property that lets a NAT rebind move a
   * player's address without moving the player, and it is worth keeping pure.
   * But displacement still has to find and close the OLD session, and only the
   * layer that owns `#sessions` should know where it lives. So the mapping sits
   * here, maintained alongside `#sessions` in `open()` and `close()`.
   */
  #routingKeyByIdentity = new Map();

  constructor({
    wheel,
    areaDirectory,
    /**
     * The keepalive key. Required, with NO default: a wrong key here does not
     * degrade the session, it overruns an unmodified retail client's stack.
     * Nothing should be able to get one by omission.
     */
    keepaliveKey,
    keepalivePeriodMs = DEFAULT_KEEPALIVE_PERIOD_MS,
    idleTimeoutMs = DEFAULT_IDLE_TIMEOUT_MS,
    successTransition = false,
    /*
     * The in-game beacon experiment (PORT-PLAN slice 2c-ii), both OFF by
     * default: `SNAP_GAME_BEACON_ECHO` echoes the flags-0x2012 op-0x0F back to
     * its sender verbatim; `SNAP_GAME_BEACON_RELAY` fans it out to the sender's
     * room. What the beacon expects is Unknown - these exist so the JP
     * dumb-relay hypothesis is one rig flag flip to test, not a code change.
     */
    gameBeaconEcho = false,
    gameBeaconRelay = false,
    /*
     * B3 fix 1 (PORT-PLAN slice 3), default OFF: mirror the client's op-0x02
     * close back (zero body, stamped seq) and release the session, per the
     * exit-contract RE's bidirectional-0xb000 note. Flag `SNAP_EXIT_CLOSE_MIRROR`.
     */
    exitCloseMirror = false,
    /*
     * B3 fix 2 (PORT-PLAN slice 3), default OFF: echo the request's send-seq
     * at completion payload +0xc on the sel-6/sel-7 accepts. Off = the
     * builders emit byte-identical 8-byte payloads. Flag `SNAP_COMPLETION_SEQ_ECHO`.
     */
    completionSeqEcho = false,
    /*
     * C3 fix (SESSION-LOG-2026-08-24): sel-7/sel-8 completions echo the
     * request's DATA bit. Flag `SNAP_CHANNEL_BIT_ECHO`, default OFF; the
     * session doc has the full grounding.
     */
    channelBitEcho = false,
    /*
     * 2026-08-24 fixes (ROOMCHAT-SCENARIO-WIRE / GAME-START-WIRE): re-vehicle
     * ROOM chat as op-0x10 sub-7 fragments, and relay reliable game-channel
     * op-0x0F packets to the room (bioserver gameserver default-branch).
     * Flags `SNAP_ROOM_CHAT_SUB7` / `SNAP_GAME_RELAY`, default OFF.
     */
    roomChatSub7 = false,
    gameRelay = false,
    /* SNAP_ROOM_STAT: op-0x49 +0x1c carries the create optionsWord. */
    roomStat = false,
    reliableWindow = 32,
    /* SNAP_MEMBER_ID_TOKEN: per-recipient memberId for the accept scan. */
    memberIdToken = false,
    rosterToJoiner = false,
    hostReseat = false,
    /*
     * PORT-PLAN slices 1b/2a/2b. Table defaults OFF like every other flag here;
     * the composed config (`SNAP_JOIN_LADDER`, `SNAP_OP10_RELAY`) turns the
     * first two ON for the coming rig run, and `SNAP_ROOMFLAGS_PUBLISH` stays
     * OFF until a rig run shows how the client renders non-zero record flags.
     */
    joinLadder = false,
    op10Relay = false,
    /*
     * RS1-B fix 1 (`SNAP_OP0A_COUNT0`, config default ON): the op-0x0a
     * member-list answers with July V1's 12-byte count-0 body. The count-1
     * zero-blob reply is the H-B starvation shape - both consoles that ever
     * received it parked on "Getting information" and closed (~142 s).
     */
    op0aCount0 = false,
    /*
     * RS1-B fix 2 (`SNAP_MEMBER_INFO`, config default ON): the member-info
     * supply channel - sel-0x0a roster records with the op-0x0c completion,
     * op-0x10 sub-1 player-info pushes on join acceptance and in answer to
     * every inbound game-channel op-0x10. V1's July golden set ran all
     * three; V2 lacked all three, and the two RS1 starvation deaths (the
     * joiner's member-list wait, the host's in-room silence) sit exactly on
     * this gap.
     */
    memberInfo = false,
    roomFlagsPublish = false,
    /*
     * RS1-C C2 (`SNAP_COUNT_PUSH`, config default ON): re-broadcast the
     * op-0x09 USER count to every session in an area whenever a presence
     * enters or leaves that area - the JP `broadcastAreaPlayerCnt` translated
     * to the PAL vehicle (the persistent slot-0x17 reply handler; the full
     * grounding is on the session option). Off = no unsolicited op-0x09 ever
     * leaves, byte-identical to the RS1 build.
     */
    countPush = false,
    /*
     * The 30 s SN@P APPLICATION keepalive (`SNAP_APP_KEEPALIVE`, config
     * default ON; table default OFF like every flag here): op-0x10 who-0xA000
     * with app-payload byte 0x00, per open session, the reset for the lobby
     * overlay's ~145.7 s liveness watchdog that op-0x40 never reaches. The
     * G12 fix for the voluntary op-0x02 self-close; grounding on the session
     * class (`APP_KEEPALIVE_PERIOD_MS`) and in ROOM-WATCHDOG-RE.md.
     */
    appKeepalive = false,
    /**
     * The room model behind op-0x49. Owned here when not supplied, and EMPTY -
     * see `state/lobby-rooms.js` for why the emptiness is a held state rather
     * than a `() => []` default. Injected when the composed application wants to
     * inspect it or open rooms in it.
     */
    rooms = null,
    /**
     * The presence registry. Owned here when not supplied, because presence is
     * created at BIND-ACCEPT and this is the object that accepts binds - putting
     * it anywhere else would reintroduce the ordering defect it exists to remove.
     * Injected when the composed application shares one across subsystems.
     */
    presence = null,
    /**
     * Which directory entry this listener IS. The key of the server-level bucket
     * and therefore of the `0x6510` "current players" count. A single string
     * rather than a derived value: the config requires at least two entries and
     * on the rig both may point at this same process, which is harmless, but two
     * entries must not be presented as two populations until something
     * distinguishes them.
     */
    serverEntryId = 'self',
    maximumSessions = DEFAULT_MAXIMUM_SESSIONS,
    logger = null
  } = {}) {
    if (wheel == null || typeof wheel.schedule !== 'function') {
      fail('WHEEL_REQUIRED', 'a timing wheel is required; sessions do not make their own timers');
    }
    if (areaDirectory == null || typeof areaDirectory.records !== 'function') {
      fail('AREA_DIRECTORY_REQUIRED', 'an area directory is required to answer op-0x48');
    }
    const keyIsUsable =
      typeof keepaliveKey === 'string' || Buffer.isBuffer(keepaliveKey);
    if (!keyIsUsable) {
      fail(
        'KEEPALIVE_KEY_REQUIRED',
        'the op-0x40 keepalive key must be supplied explicitly; the wrong key overruns the client'
      );
    }
    if (!Number.isSafeInteger(maximumSessions) || maximumSessions < 1) {
      fail('MAXIMUM_SESSIONS', 'maximumSessions must be a positive whole number');
    }
    if (typeof serverEntryId !== 'string' || serverEntryId.length === 0) {
      fail('SERVER_ENTRY_ID', 'serverEntryId names the directory entry this listener is');
    }
    /*
     * Constructed in this order and with these exact links, because the two
     * registries are mutually referential by design and neither may hold a copy
     * of the other's fact: rooms ask presence for their population, and presence
     * tells rooms when the last member left. `onRoomEmptied` is only ever invoked
     * later, so the forward reference is resolved by the time it can fire.
     */
    this.#presence = presence ?? new PresenceRegistry({
      maximumPresences: maximumSessions,
      onRoomEmptied: (handle) => {
        // A room's EXISTENCE is derived too: it is closed by the same transition
        // that removed its last member, so there is never a ghost for a sweeper
        // to find. The engine records (status, game session) go with it.
        this.#rooms.close(handle);
        this.releaseRoomState(handle);
      },
      logger
    });
    this.#rooms = rooms ?? new LobbyRoomRegistry({
      countInRoom: (handle) => this.#presence.countInRoom(handle)
    });
    if (typeof this.#rooms.roomsIn !== 'function' || typeof this.#rooms.openFor !== 'function') {
      fail('ROOMS_REQUIRED', 'rooms must be a room registry; op-0x49 reports held state');
    }
    /*
     * THE ENGINE (PORT-PLAN §A.1): the attribute half of the player, the
     * authored room status, the playernum/guard machine, and the gamenumber
     * bookkeeping. Owned here because this table already owns every other
     * shared registry; all four are transport-free `state/` modules, and none
     * of them touches the wire by existing - the dispatch flags decide that.
     */
    this.#profiles = new PlayerProfileRegistry({ maximumProfiles: maximumSessions });
    this.#roomLifecycle = new RoomLifecycleRegistry({ maximumRooms: maximumSessions });
    this.#slotAllocator = new SlotAllocator({
      presence: this.#presence,
      profiles: this.#profiles,
      lifecycle: this.#roomLifecycle
    });
    this.#gameSessions = new GameSessionRegistry();
    this.#serverEntryId = serverEntryId;

    this.#wheel = wheel;
    this.#areaDirectory = areaDirectory;
    // ONCE. The key schedule is 521 block encryptions and the plaintext never
    // changes, so the whole body is a constant for the life of the process; the
    // alternative is 521 encryptions per session per five seconds.
    this.#keepaliveCiphertext = blowfishEcbEncrypt(
      createBlowfishKey(keepaliveKey),
      Buffer.alloc(KEEPALIVE_PLAINTEXT_BYTES)
    );
    this.#keepalivePeriodMs = keepalivePeriodMs;
    this.#idleTimeoutMs = idleTimeoutMs;
    this.#successTransition = successTransition === true;
    this.#gameBeaconEcho = gameBeaconEcho === true;
    this.#gameBeaconRelay = gameBeaconRelay === true;
    this.#roomChatSub7 = roomChatSub7 === true;
    this.#gameRelay = gameRelay === true;
    this.#roomStat = roomStat === true;
    this.#reliableWindow = Number.isSafeInteger(reliableWindow) && reliableWindow >= 32 ? reliableWindow : 32;
    this.#memberIdToken = memberIdToken === true;
    this.#rosterToJoiner = rosterToJoiner === true;
    this.#hostReseat = hostReseat === true;
    this.#exitCloseMirror = exitCloseMirror === true;
    this.#completionSeqEcho = completionSeqEcho === true;
    this.#channelBitEcho = channelBitEcho === true;
    this.#joinLadder = joinLadder === true;
    this.#op10Relay = op10Relay === true;
    this.#op0aCount0 = op0aCount0 === true;
    this.#memberInfo = memberInfo === true;
    this.#roomFlagsPublish = roomFlagsPublish === true;
    this.#countPush = countPush === true;
    this.#appKeepalive = appKeepalive === true;
    this.#maximum = maximumSessions;
    this.#logger = logger;
  }

  get size() {
    return this.#sessions.size;
  }

  /** The room model op-0x49 reports. Exposed so a caller can open rooms in it. */
  get rooms() {
    return this.#rooms;
  }

  /** Where every live player is. The source every count in this phase queries. */
  get presence() {
    return this.#presence;
  }

  /** The attribute half of every player (playernum/hostflag/gamenumber). */
  get profiles() {
    return this.#profiles;
  }

  /** The authored room status machine the join guards read. */
  get roomLifecycle() {
    return this.#roomLifecycle;
  }

  /** The gamenumber bookkeeping (party snapshots, relay scope). */
  get gameSessions() {
    return this.#gameSessions;
  }

  /** The directory entry this listener is, and the key of its server-level count. */
  get serverEntryId() {
    return this.#serverEntryId;
  }

  /**
   * How many live sessions are in one area, which is what op-0x48 publishes at
   * record `+0x10`.
   *
   * THE SESSIONS ACTUALLY HELD, counted at send time. This replaces a
   * `playerCountFor = () => 0` default that the composed application never
   * overrode, so every area reported 0 players on the rig - which makes the
   * distinct `+0x20` keys pointless (nothing distinguishable is ever published
   * per box) and the "Server full" gate untestable, because `FUN_005bc990` sums
   * these and the sum was structurally always 0.
   *
   * A session counts towards the area its op-0x06 ENTER resolved and nowhere
   * before that - which is the right rule for THIS count and only this one. It
   * used to be an O(n) scan over every session, called ten times per op-0x48
   * reply on a poll that runs at about 25 Hz per player; that is O(n) per area
   * per poll, which is quadratic in players and is the G11 lesson reintroduced.
   * It is now one `Map.get().size`.
   */
  playersIn(boxId) {
    return this.#presence.countInArea(boxId);
  }

  /**
   * Fan one push out to every live session in ONE presence scope, and return
   * how many received it.
   *
   * THE generalized fan-out (PORT-PLAN §A.1, the `ClientList.broadcastIn*`
   * analogue), extracted from `#relayChat` - which stays byte-identical, proven
   * by the chat suite. Scope is ALWAYS derived from presence sets, never from
   * message content: a caller names a room handle or a box id it read off a
   * presence record, and a client cannot address a place it is not in because
   * no handler passes wire bytes here.
   *
   * `deliver` is called once per in-scope session and reports whether the send
   * left. A peer whose send window is full is skipped rather than allowed to
   * fail the whole fan-out - one blocked console must not silence the room.
   * `except` is the sender, excluded because every observed push of this kind
   * is "to the others" (the client echoes its own actions locally first).
   *
   * Area scope deliberately does NOT exclude peers who are inside a room in
   * that area - that is `#relayChat`'s original behaviour, preserved exactly:
   * only the SENDER's depth picks the scope.
   */
  broadcast({ roomHandle = null, boxId = null, except = null } = {}, deliver) {
    let delivered = 0;
    for (const session of this.#sessions.values()) {
      if (session === except) continue;
      const peer = session.presence?.location?.();
      if (peer == null) continue;
      const inScope = roomHandle != null
        ? peer.roomHandle === roomHandle
        : (boxId != null && peer.boxId === boxId);
      if (!inScope) continue;
      if (deliver(session)) delivered += 1;
    }
    return delivered;
  }

  /**
   * Push the fresh op-0x09 USER count of ONE box to every session in it
   * (SNAP_COUNT_PUSH, RS1-C C2 - the JP `broadcastAreaPlayerCnt` analogue).
   *
   * Word0 of the push body is the area's own `+0x20` KEY, not the box id: it
   * is the value each recipient queried with and the value its registry-A
   * sweep (`FUN_005bf280`) matches on. The count is derived at push time from
   * the same presence bucket every answer reads, so it cannot be stale.
   *
   * The JP broadcast also reaches Area Select; the PAL Area Select runs the
   * op-0x48 poll at ~25 Hz, which already carries live per-area populations,
   * so only the in-area sessions - the ones with no refresh stimulus - are
   * pushed here.
   */
  pushAreaCount(boxId, { except = null } = {}) {
    if (!this.#countPush || boxId == null) return 0;
    const area = this.#areaDirectory.areaByBox(boxId);
    if (area == null) return 0;
    const handleBytes = Buffer.alloc(4);
    handleBytes.writeUInt32BE(area.key >>> 0, 0);
    const value = this.#presence.countInArea(boxId);
    const delivered = this.broadcast(
      { boxId, except },
      (session) => session.deliverAreaCountPush({ handleBytes, value }) === true
    );
    this.#logger?.info?.('udp9090 lobby-count-push', {
      boxId,
      key: `0x${area.key.toString(16)}`,
      value,
      delivered,
      note: 'unsolicited op-0x09 USER re-broadcast on an area enter/leave (SNAP_COUNT_PUSH; ' +
        'JP broadcastAreaPlayerCnt analogue via the persistent slot-0x17 reply handler)'
    });
    return delivered;
  }

  /**
   * Fan one chat line out to everyone who should hear it, and return how many
   * received it.
   *
   * SCOPE IS THE SENDER'S OWN LOCATION, taken from presence and never from the
   * message. If the sender is in a room, the line goes to that room; otherwise to
   * everyone in the same area. A client cannot address a room it is not in, and
   * cannot reach the whole server by claiming a screen id.
   *
   * THE SENDER IS EXCLUDED, deliberately. `FUN_005C4AF0` writes the line into the
   * sender's own display block BEFORE transmitting, so echoing it back would show
   * every player their own messages twice. That is also why the owner saw chat as
   * "only local" and not as "chat missing": the local half always worked.
   */
  #relayChat(from, payload, text = null) {
    const at = from.presence?.location?.();
    if (at == null) return 0;
    const roomScope = at.roomHandle != null;
    const scope = roomScope
      ? { roomHandle: at.roomHandle }
      : (at.boxId != null ? { boxId: at.boxId } : null);
    if (scope == null) return 0;
    /*
     * SNAP_ROOM_CHAT_SUB7 (ROOMCHAT-SCENARIO-WIRE-2026-08-24 §1): the in-room
     * text surface reads op-0x10 sub-7 fragments (FUN_005bc1c0 into
     * 0x6fffd1+slot*0x114), NOT the op-0x0F scrollback - room chat relayed as
     * 0xA4xx was delivered and acked all night and never rendered. When the
     * flag is on, room-scope chat re-vehicles as a sub-7 push; the slot byte is
     * playernum-1 (the allocator's documented presence-slot identity). If the
     * sender has no allocated playernum (engine off / pre-join), fall through
     * to the op-0x0F relay rather than guess a slot.
     */
    if (roomScope && this.#roomChatSub7 && text != null && text.length > 0) {
      const playernum = this.#profiles.get(from.loginIdentity)?.playernum ?? 0;
      if (playernum >= 1 && playernum <= 4) {
        const sub7 = buildRoomChatSub7Payload({ slot: playernum - 1, text });
        return this.broadcast(
          { ...scope, except: from },
          (session) => session.deliverRoomPush(LOBBY_OPCODE.ROOM_STATE, sub7, 'room-chat-sub7')
        );
      }
    }
    // The scope decision is ALSO the relayed frame's DATA bit (RS1-C §C1):
    // area chat goes out 0xB4xx, room chat 0xA4xx - the client's own shapes.
    return this.broadcast(
      { ...scope, except: from },
      (session) => session.deliverChat(payload, { roomScope })
    );
  }

  /**
   * The reliable game-packet relay (SNAP_GAME_RELAY): bioserver
   * GameServerPacketHandler's default branch, translated - broadcast the raw
   * payload to every session in the sender's room EXCEPT the sender. openSNAP
   * documents the identical rule for AM. No parsing: the JP server never
   * looked inside these bytes and neither do we.
   */
  #relayGameChannel(from, payload) {
    const at = from.presence?.location?.();
    if (at?.roomHandle == null) return 0;
    return this.broadcast(
      { roomHandle: at.roomHandle, except: from },
      (session) => session.deliverGamePacket(payload)
    );
  }

  /**
   * Fan one in-game beacon out to the sender's ROOM, and only its room.
   *
   * Room scope, not area scope: the beacon fires after a game start, and the
   * party that started is the room's membership. (The engine's game-session
   * module will own this scope once a gamenumber exists on the wire path; until
   * that is wired, presence room scope is the same set for every observed
   * case - the T37 solo host is alone in its room.) The sender is excluded for
   * the same reason as chat: relay means "to the others".
   */
  #relayGameBeacon(from, payload, subSelector, flags) {
    const at = from.presence?.location?.();
    if (at?.roomHandle == null) return 0;
    return this.broadcast(
      { roomHandle: at.roomHandle, except: from },
      (session) => session.deliverGameBeacon(payload, subSelector, flags)
    );
  }

  /**
   * The op-0x10 room-event relay (PORT-PLAN slice 2a): fan the payload out
   * VERBATIM to the sender's own room, except the sender - `#relayChat`'s
   * proven scope model on the game channel, the bioserver dumb-relay.
   *
   * SUPERSEDED (2026-08-08, RS1-B §2/§6.2-6.3): the recipient-resolution
   * version of this method. It parsed body word1 as a recipient list and
   * matched it against roster `presenceId` / `endpointToken`, excluding
   * `target === from`. Both wire observations show word1 is the SENDER'S OWN
   * `0x6febe8` handle - so the only entity the word could ever name was the
   * excluded sender, and `relayed: 0` was structural (RS1 journal:
   * `lobby-room-event-relayed ... recipients:1 relayed:0`). Worse, the
   * presenceId match was a live cross-type collision hazard: RS1's PS2 held
   * presenceId 3 while room handle 3 existed, so a joiner in the roster would
   * have produced a FALSE match. No id from the message body routes anything
   * here any more - scope comes from presence alone.
   */
  #relayRoomEvent(from, payload) {
    const at = from.presence?.location?.();
    if (at?.roomHandle == null) return 0;
    return this.broadcast(
      { roomHandle: at.roomHandle, except: from },
      (session) => session.deliverRoomPush(LOBBY_OPCODE.ROOM_STATE, payload, 'op10-relay')
    );
  }

  /**
   * The op-0x0D body-1 barrier's engine half: bioserver `broadcastGetReady`
   * steps 1-2 (gamenumber mint-once, party snapshot, room -> BUSY). Sends
   * NOTHING - the PAL GETREADY is the host's own op-0x10 sub-3 (B1 §3).
   * Re-entrant by design: each member of a starting party sends the barrier,
   * and the second call reuses the minted number and the idempotent BUSY edge.
   */
  #onGameStartBarrier(from) {
    const at = from.presence?.location?.();
    if (at?.roomHandle == null) return null;
    const members = this.#presence.rosterOf(at.roomHandle)
      .map((member) => this.#profiles.get(member.accountSessionId))
      .filter((profile) => profile != null);
    if (members.length === 0) return null;
    try {
      const gameSession = this.#gameSessions.start({
        roomHandle: at.roomHandle,
        members,
        lifecycle: this.#roomLifecycle
      });
      this.#logger?.info?.('udp9090 lobby-game-start', {
        loginIdentity: from.loginIdentity,
        roomHandle: `0x${at.roomHandle.toString(16)}`,
        gamenumber: gameSession.gamenumber,
        party: gameSession.party,
        status: this.#roomLifecycle.statusOf(at.roomHandle),
        note: 'op-0x0D body-1 barrier: gamenumber minted/reused, party set, room BUSY ' +
          '(broadcastGetReady steps 1-2); nothing extra on the wire'
      });
      return gameSession;
    } catch (error) {
      // A barrier from a room the engine holds no GAMESET record for (or any
      // other refused transition) is logged, never thrown into the reply path -
      // the op-0x0D answer already left and must not be disturbed.
      this.#logger?.warn?.('udp9090 lobby-game-start-refused', {
        loginIdentity: from.loginIdentity,
        roomHandle: `0x${at.roomHandle.toString(16)}`,
        code: error.code ?? error.name,
        reason: error.message
      });
      return null;
    }
  }

  /**
   * Drop the engine-side records of a room that no longer exists. Called by
   * the emptied-room hook (owned presence) or by the composed application's
   * hook (injected presence). Idempotent.
   */
  releaseRoomState(handle) {
    const releasedLifecycle = this.#roomLifecycle.release(handle);
    const releasedGame = this.#gameSessions.clearRoom(handle);
    return releasedLifecycle || releasedGame;
  }

  /**
   * C4: everyone attached to this listener at ANY depth - the `0x6510` record
   * `+0x12c` "current players".
   *
   * This is the count that could never be non-zero under the old model, because
   * nothing existed above the area level to count. It is asked on the TCP-10127
   * ladder, before the player has selected anything.
   */
  playersOnServer() {
    return this.#presence.countInServer(this.#serverEntryId);
  }

  get(routingKey) {
    return this.#sessions.get(routingKey) ?? null;
  }

  /**
   * Open a session for a client that has just bound.
   *
   * `routingKey` is transport addressing - address:port - and is the map key
   * only. `loginIdentity` and `attachment` come from the registration the
   * attachment nonce resolved, so identity never derives from the source address
   * even though routing does.
   *
   * An existing session for the same routing key is CLOSED first. A re-register
   * resets the client's own sequence numbering to a fresh epoch (the archive's
   * `resetUdpSessionForRegister ... -> fresh epoch`), so continuing an old
   * channel would leave its receive base and retransmit window describing a
   * stream that no longer exists.
   */
  open({
    routingKey,
    loginIdentity,
    attachment = null,
    endpointToken,
    outboundSequence,
    inboundReceiveBase = 0,
    latencyTicks = null,
    transmit,
    onTransportDead = null
  }) {
    this.close(routingKey, 'replaced-by-a-fresh-epoch');
    if (this.#sessions.size >= this.#maximum) {
      // Fail closed: refusing a NEW session is a bounded loss, evicting a live
      // one hands an attacker a way to drop a player who is already in.
      this.#logger?.warn?.('udp9090 lobby-session-capacity', {
        routingKey,
        live: this.#sessions.size,
        maximum: this.#maximum,
        note: 'no lobby session opened; this client will not be answered past the bind'
      });
      return null;
    }

    const watchdogBudgetMs = watchdogBudgetMsFromLatencyTicks(latencyTicks);
    if (watchdogBudgetMs == null) {
      /*
       * The client did not declare `LC`, so its watchdog budget is unknown and
       * the period cannot be checked against it. The session is still opened at
       * the configured period: the alternative is no keepalive at all, which is
       * a GUARANTEED 840, where an unchecked 5 s period is only unsafe if a
       * client declares a budget below 15 s - which no observed client does.
       * Stated loudly rather than defaulted silently.
       */
      this.#logger?.warn?.('udp9090 lobby-watchdog-budget-unknown', {
        routingKey,
        loginIdentity,
        keepalivePeriodMs: this.#keepalivePeriodMs,
        note: 'no LC TLV in the register; the keepalive period could not be checked against ' +
          "the client's own conn+0x51c budget"
      });
    }

    /*
     * PRESENCE IS CREATED HERE - at bind-accept, S5 - and not at the op-0x06
     * ENTER. That single line is the ordering fix: four of the six count sites
     * are asked before any ENTER happens, so a model that only records location
     * at the deepest level makes every shallower count structurally zero.
     *
     * Keyed on the identity the registration proved, never on the routing key: a
     * NAT rebind changes the address while the player has not moved. Displacement
     * is DETACH-THEN-ATTACH in one synchronous block - the opposite order
     * momentarily double-counts, and an attach-first path that then removes "the
     * presence for this identity" can remove the new one.
     */
    const displaced = this.#presence.get(loginIdentity);
    if (displaced != null) {
      /*
       * CLOSE THE OLD SESSION, do not merely detach its presence.
       *
       * `close(routingKey)` above only reaches a session at the SAME address and
       * port. One account signing in from a second console - or the same console
       * after a NAT rebind - arrives on a different routing key, so before this
       * the old session stayed live while its presence record was detached. Two
       * consequences, one design and one fatal:
       *
       * - Design: the owner's rule is that one account on two devices disconnects
       *   the first, as every game does. A live orphan session is not that.
       * - Broken for that player: the orphan still routes datagrams. An op-0x06
       *   or op-0x07 on it reaches `PresenceRegistry.#requireLive`, which throws
       *   PRESENCE_DETACHED by design. The throw is CAUGHT - `snap-lobby-session`
       *   wraps `#dispatch` in try/catch and turns it into a HANDLER_THREW
       *   refusal - but it throws before `#send`, so that console gets no
       *   completion reply at all and stalls, which reads exactly like the old
       *   cursor lock. Reachable by one player with two consoles.
       *
       * CORRECTED 2026-08-07: an earlier version of this comment claimed the
       * throw escaped into `uncaughtException` and killed the whole process.
       * That was wrong - the handler guard predates this code (`0d15dbfe`) and
       * catches it. The bug is a stalled console, not a downed server. Recorded
       * rather than quietly reworded, because the wrong severity is what made
       * this look urgent enough to bundle into an unrelated commit.
       *
       * Closing first restores the invariant the presence registry assumes: a
       * detached record is never reachable from a live session.
       */
      const displacedRoutingKey = this.#routingKeyByIdentity.get(loginIdentity) ?? null;
      const closesAnOrphan = displacedRoutingKey != null && displacedRoutingKey !== routingKey;
      if (closesAnOrphan) {
        this.close(displacedRoutingKey, 'displaced-by-a-fresh-registration');
      }
      this.#presence.detach(displaced, 'displaced-by-a-fresh-registration');
      this.#logger?.info?.('udp9090 lobby-presence-displaced', {
        routingKey,
        loginIdentity,
        displacedRoutingKey,
        displacedSessionClosed: closesAnOrphan,
        note: 'the same identity registered again; the older session was closed and its presence ' +
          'detached before the new one attached, so no count sees both and no live session holds ' +
          'a detached record'
      });
    }
    let presenceRecord;
    try {
      presenceRecord = this.#presence.attach({
        accountSessionId: loginIdentity,
        userid: loginIdentity,
        displayName: loginIdentity,
        serverEntryId: this.#serverEntryId
      });
    } catch (error) {
      this.#logger?.warn?.('udp9090 lobby-presence-refused', {
        routingKey,
        loginIdentity,
        code: error.code ?? null,
        reason: error.message
      });
      return null;
    }

    /*
     * The attribute half of the player (bioserver `Client`): opened WITH the
     * presence, released with the session, keyed on the same proven identity.
     * A stale profile from a displaced session is released first so the
     * duplicate refusal cannot refuse a legitimate re-register. A refused
     * profile is logged and tolerated - the ladder's allocator REFUSES joins
     * for a profile-less session as a structured result (`JOIN_REFUSAL.
     * NO_PROFILE`, journalled as `lobby-room-enter-refused` reason
     * 'no-profile', nora pre-deploy fix 3 - it used to throw and land in the
     * journal as a misleading generic handler-threw), which is the bounded
     * loss.
     */
    if (this.#profiles.get(loginIdentity) != null) this.#profiles.release(loginIdentity);
    try {
      this.#profiles.open({ accountSessionId: loginIdentity, handle: loginIdentity });
    } catch (error) {
      this.#logger?.warn?.('udp9090 lobby-profile-refused', {
        routingKey,
        loginIdentity,
        code: error.code ?? null,
        reason: error.message
      });
    }

    let session;
    try {
      session = new SnapLobbySession({
        routingKey,
        loginIdentity,
        attachment,
        endpointToken,
        wheel: this.#wheel,
        transmit,
        areaDirectory: this.#areaDirectory,
        // Both seams read THIS table's live state at send time, so a reply can
        // never be stale and no session holds a copy of anything shared.
        playerCountFor: (area) => this.playersIn(area.boxId),
        roomListProvider: (boxId) => this.#rooms.roomsIn(boxId),
        /*
         * CHAT RELAY. A session can answer its own client but has no way to reach
         * anyone else, which is why chat was "only local" - the client echoes the
         * sender's own line locally before transmitting, so it always looked half
         * working. The fan-out belongs to this table, the only object that knows
         * every live session.
         *
         * Scope comes from the SENDER'S OWN LOCATION, never from anything in the
         * message: a client that claims to be in a room it is not in must not be
         * able to address that room. Room chat goes to the room; otherwise it goes
         * to the area.
         */
        relayChat: (from, payload, text) => this.#relayChat(from, payload, text),
        gameRelay: this.#gameRelay,
        roomStat: this.#roomStat,
        reliableWindow: this.#reliableWindow,
        memberIdToken: this.#memberIdToken,
        rosterToJoiner: this.#rosterToJoiner,
        hostReseat: this.#hostReseat,
        relayGameChannel: (from, payload) => this.#relayGameChannel(from, payload),
        gameBeaconEcho: this.#gameBeaconEcho,
        gameBeaconRelay: this.#gameBeaconRelay,
        relayGameBeacon: (from, payload, subSelector, flags) =>
          this.#relayGameBeacon(from, payload, subSelector, flags),
        exitCloseMirror: this.#exitCloseMirror,
        completionSeqEcho: this.#completionSeqEcho,
        channelBitEcho: this.#channelBitEcho,
        /*
         * The join ladder + op-0x10 relay seams (PORT-PLAN slices 1b/2a/2b).
         * All bound to THIS table's registries and fan-out, so scope and
         * assignment always read the shared live state.
         */
        joinLadder: this.#joinLadder,
        op10Relay: this.#op10Relay,
        op0aCount0: this.#op0aCount0,
        memberInfo: this.#memberInfo,
        roomFlagsPublish: this.#roomFlagsPublish,
        countPush: this.#countPush,
        appKeepalive: this.#appKeepalive,
        pushAreaCount: (boxId, except) => this.pushAreaCount(boxId, { except }),
        roomLifecycle: this.#roomLifecycle,
        slotAllocator: this.#slotAllocator,
        broadcast: (scope, deliver) => this.broadcast(scope, deliver),
        relayRoomEvent: (from, payload) => this.#relayRoomEvent(from, payload),
        onGameStart: (from) => this.#onGameStartBarrier(from),
        // The op-0x02 close said goodbye; releasing through the same close()
        // as idle and displacement keeps every teardown on the one proven path.
        onClientClose: () => this.close(routingKey, 'client-close'),
        presence: this.#presence,
        presenceRecord,
        rooms: this.#rooms,
        keepaliveCiphertext: this.#keepaliveCiphertext,
        keepalivePeriodMs: this.#keepalivePeriodMs,
        watchdogBudgetMs,
        successTransition: this.#successTransition,
        outboundSequence,
        inboundReceiveBase,
        idleTimeoutMs: this.#idleTimeoutMs,
        // A console that is switched off says nothing, and the keepalive is
        // unreliable so no send ever fails. This is the only thing that reclaims
        // such a session.
        onIdle: () => this.close(routingKey, 'idle'),
        logger: this.#logger,
        onTransportDead: (event) => {
          this.#logger?.warn?.('udp9090 lobby-transport-dead', {
            routingKey,
            loginIdentity,
            reason: event.reason,
            detail: event.detail
          });
          this.close(routingKey, event.reason);
          onTransportDead?.(event);
        }
      });
    } catch (error) {
      // The presence was created first, so it must be undone here or a refused
      // session leaves a player counted who has no way to be uncounted. The
      // profile came with it and goes with it.
      this.#presence.detach(presenceRecord, 'session-construction-refused');
      this.#profiles.release(loginIdentity);
      this.#logger?.error?.('udp9090 lobby-session-refused', {
        routingKey,
        loginIdentity,
        code: error.code ?? null,
        reason: error.message
      });
      return null;
    }

    this.#sessions.set(routingKey, session);
    /*
     * Written HERE, in lockstep with `#sessions`, and deleted in `close()`. A
     * previous commit declared this map and read it without ever writing it, so
     * displacement silently did nothing; the regression test below the read now
     * fails if that recurs.
     */
    this.#routingKeyByIdentity.set(loginIdentity, routingKey);
    /*
     * ARMED HERE, not by the caller. The client's `conn+0x51c` clock is already
     * running when this is reached, and op-0x40 is the only message that
     * refreshes it - so a session that exists without a keepalive is a session
     * that reaches error 840 on a timer. Making it impossible to open one is
     * worth more than the flexibility of a separate call.
     */
    session.startKeepalive();
    this.#logger?.info?.('udp9090 lobby-session-opened', {
      routingKey,
      loginIdentity,
      attachment: attachment?.reason ?? null,
      outboundSequence,
      inboundReceiveBase,
      latencyTicks,
      watchdogBudgetMs,
      keepalivePeriodMs: this.#keepalivePeriodMs,
      areaCount: this.#areaDirectory.areaCount,
      note: 'the post-selection SN@P phase; op-0x40 starts now and is the only thing ' +
        'holding off error 840'
    });
    return session;
  }

  /** Close and forget one session, proving its timers are gone. Idempotent. */
  close(routingKey, reason = 'closed') {
    const session = this.#sessions.get(routingKey);
    if (session == null) return false;
    this.#sessions.delete(routingKey);
    /*
     * ONLY if it still points at the key being closed.
     *
     * An unconditional delete is a footgun on every path that closes a session
     * the identity has already moved off - idle, transport-dead, closeAll, and
     * displacement itself. Worse in the other direction: a stale entry left
     * behind can make a LATER open() close a different player who happened to
     * inherit this address and port. The identity check makes both harmless.
     */
    if (this.#routingKeyByIdentity.get(session.loginIdentity) === routingKey) {
      this.#routingKeyByIdentity.delete(session.loginIdentity);
      // The profile's lifetime is the session's - but ONLY the current holder
      // of the identity may take it down, for exactly the routing-key reason
      // above: a displaced session must not delete its replacement's profile.
      this.#profiles.release(session.loginIdentity);
    }
    /*
     * DETACH BEFORE close(), so every count is already correct when the closing
     * log line is written and when anything downstream reacts. This is the only
     * reclaim for a console whose cable was pulled: UDP has no close event, the
     * keepalive is unreliable so no send ever fails, and the idle timer is what
     * gets us here.
     */
    const vacatedBox = session.presence?.location?.()?.boxId ?? null;
    this.#presence.detach(session.presence, reason);
    /*
     * SNAP_COUNT_PUSH: a teardown vacates a box exactly like an op-0x07 leave
     * does, and the RS1 idle-release at 17:50:34 is precisely the case the
     * owner watched go stale (the JP sendExitArea fires on disconnect too).
     * The session is already out of `#sessions`, so no `except` is needed;
     * with the flag off this is a no-op.
     */
    this.pushAreaCount(vacatedBox, {});
    session.close();
    // The assertion is the point: teardown DEMONSTRATES it left nothing behind.
    // A leak here is a defect in this file, never something a peer can cause, so
    // it is allowed to throw.
    session.assertDrained();
    this.#logger?.info?.('udp9090 lobby-session-closed', {
      routingKey,
      loginIdentity: session.loginIdentity,
      reason,
      ...session.stats()
    });
    return true;
  }

  /** Close every session. Used by shutdown; returns how many were closed. */
  closeAll(reason = 'shutdown') {
    let closed = 0;
    for (const routingKey of [...this.#sessions.keys()]) {
      if (this.close(routingKey, reason)) closed += 1;
    }
    return closed;
  }
}
