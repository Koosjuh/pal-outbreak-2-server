import fs from 'node:fs';
import path from 'node:path';

/**
 * Validated configuration for the composed V2 server.
 *
 * Everything the process needs comes from the environment and from files the
 * operator controls. Nothing here has a protocol meaning: hosts, ports and paths
 * are deployment facts, and the one value that touches the wire - the SN@P host
 * and port the HTTP `lbs.jsp` response advertises - is required rather than
 * defaulted to an address invented here.
 *
 * Validation collects every problem before throwing. A half-configured process
 * that binds three of four listeners is worse than one that refuses to start,
 * so this is checked before anything opens a socket.
 */

export class ConfigurationError extends Error {
  constructor(problems) {
    super(`invalid configuration:\n  - ${problems.join('\n  - ')}`);
    this.name = 'ConfigurationError';
    this.code = 'INVALID_CONFIGURATION';
    this.problems = [...problems];
  }
}

const IPV4 = /^(\d{1,3})\.(\d{1,3})\.(\d{1,3})\.(\d{1,3})$/;

function isIpv4(value) {
  const match = IPV4.exec(String(value ?? ''));
  if (match == null) return false;
  return match.slice(1).every((octet) => {
    const number = Number(octet);
    return number >= 0 && number <= 255 && String(number) === octet.replace(/^0(?=\d)/, '');
  });
}

function readPort(problems, env, name, fallback) {
  const raw = env[name];
  if (raw == null || raw === '') return fallback;
  const port = Number(raw);
  // 0 means "let the kernel choose", which integration tests need and a
  // deployment behind a fixed reverse proxy may legitimately want.
  if (!Number.isSafeInteger(port) || port < 0 || port > 65535) {
    problems.push(`${name} must be a TCP/UDP port in 0..65535, got ${JSON.stringify(raw)}`);
    return fallback;
  }
  return port;
}

/** A bounded positive count. Refused when out of range, never clamped. */
function readCount(problems, env, name, fallback, { minimum, maximum }) {
  const raw = env[name];
  if (raw == null || String(raw).trim() === '') return fallback;
  const value = Number(raw);
  if (!Number.isSafeInteger(value) || value < minimum || value > maximum) {
    problems.push(
      `${name} must be an integer in ${minimum}..${maximum}, got ${JSON.stringify(raw)}`
    );
    return fallback;
  }
  return value;
}

function readRequired(problems, env, name) {
  const value = env[name];
  if (value == null || String(value).trim() === '') {
    problems.push(`${name} is required`);
    return null;
  }
  return String(value).trim();
}

function readDirectory(problems, env, name, { mustExist }) {
  const value = readRequired(problems, env, name);
  if (value == null) return null;
  const resolved = path.resolve(value);
  if (mustExist && !fs.existsSync(resolved)) {
    problems.push(`${name} points at ${resolved}, which does not exist`);
  }
  return resolved;
}

function readFilePath(problems, env, name) {
  const value = readRequired(problems, env, name);
  if (value == null) return null;
  const resolved = path.resolve(value);
  if (!fs.existsSync(resolved)) {
    problems.push(`${name} points at ${resolved}, which does not exist`);
  }
  return resolved;
}

/**
 * `PAL_V2_DNS_RECORDS` is `name=ipv4` pairs separated by commas or whitespace.
 * Wildcards are refused by the DNS codec; refuse them here too so the failure
 * arrives at startup with a readable message.
 */
function readDnsRecords(problems, env) {
  const raw = env.PAL_V2_DNS_RECORDS;
  if (raw == null || String(raw).trim() === '') return {};
  const records = {};
  for (const pair of String(raw).split(/[,\s]+/).filter(Boolean)) {
    const separator = pair.indexOf('=');
    if (separator < 1) {
      problems.push(`PAL_V2_DNS_RECORDS entry ${JSON.stringify(pair)} is not name=address`);
      continue;
    }
    const name = pair.slice(0, separator).trim().toLowerCase().replace(/\.$/, '');
    const address = pair.slice(separator + 1).trim();
    if (name === '' || name.includes('*')) {
      problems.push(`PAL_V2_DNS_RECORDS name ${JSON.stringify(name)} must be explicit and non-wildcard`);
      continue;
    }
    if (!isIpv4(address)) {
      problems.push(`PAL_V2_DNS_RECORDS address for ${name} must be IPv4, got ${JSON.stringify(address)}`);
      continue;
    }
    records[name] = address;
  }
  return records;
}

function readBoolean(problems, env, name, fallback) {
  const raw = env[name];
  if (raw == null || raw === '') return fallback;
  const text = String(raw).trim().toLowerCase();
  if (['1', 'true', 'yes', 'on'].includes(text)) return true;
  if (['0', 'false', 'no', 'off'].includes(text)) return false;
  problems.push(`${name} must be a boolean, got ${JSON.stringify(raw)}`);
  return fallback;
}

const LOG_LEVELS = ['debug', 'info', 'warn', 'error'];

/**
 * Shown in the lbs.jsp response when the operator sets no message. Defined here,
 * where an operator reading the configuration can see it, rather than buried as
 * a renderer fallback - and deliberately not the string V1 sent.
 */
const DEFAULT_WELCOME_MESSAGE = 'Resident Evil Outbreak File #2 - V2 server.';

/**
 * How many lobby connections the TCP service will hold at once. Every player in
 * the lobby occupies exactly one, so this is the hard ceiling on how many
 * players this process can serve, whatever any other number says.
 */
const TCP_LOBBY_CONNECTION_CEILING = 256;

/**
 * MAXIMUM PLAYERS - the capacity this server COMMITS TO, and a live gate in the
 * client rather than a display value.
 *
 * The directory carries it as a record's `unknownWord1`, which lands at client
 * record `+0x12a`. `FUN_005c5060` returns the SELECTED entry's first record's
 * copy of it, and `FUN_005bc990` - the SN@P NAME reply handler - sums every
 * area's player count and refuses the lobby with status `0xd`, string `0x12`
 * "Server full. You cannot participate.", when that sum is not below it
 * (`docs/findings/protocol/SERVER-SELECT-SPEC-2026-08-05.md` D.2, Observation).
 * So it is not decorative: set it too low and real players are turned away by
 * their own console.
 *
 * The default is the connection ceiling above, because that is the number this
 * server can actually admit: one lobby connection per player, refused past 256
 * by the TCP service itself. Advertising more would promise capacity we then
 * refuse at the socket, with no client-side message for it; advertising less
 * would have the client refuse players this server would have taken.
 *
 * NOT derived from anything the client asserts, and deliberately not the rig's
 * previous 4 - which was V1's fixture value (`session6_trace.log:91`, see
 * `analysis/PATH-TO-LOBBY-GAP-TABLE.md` C-2) and would have refused the lobby at
 * four concurrent players.
 */
const DEFAULT_MAXIMUM_PLAYERS = TCP_LOBBY_CONNECTION_CEILING;

/**
 * Build the validated configuration.
 *
 * `PAL_V2_ENABLE_DNS` and `PAL_V2_ENABLE_DNAS` exist because both need
 * privileges or assets a bare checkout may not have: DNS binds port 53, and
 * DNAS needs the operator's certificate and key. Disabling one is an explicit
 * deployment decision recorded in the startup log, never a silent fallback.
 */
export function loadServerConfig(env = process.env) {
  const problems = [];

  const dataDirectory = readDirectory(problems, env, 'PAL_V2_DATA_DIR', { mustExist: false });
  const bindHost = String(env.PAL_V2_BIND_HOST ?? '0.0.0.0').trim();

  const masterKey = env.PAL_V2_MASTER_KEY;
  if (masterKey == null || String(masterKey).trim() === '') {
    problems.push(
      'PAL_V2_MASTER_KEY is required; it seals the reversible compatibility secret at rest'
    );
  }

  const selfHost = readRequired(problems, env, 'PAL_V2_SELF_HOST');
  const snapHost = readRequired(problems, env, 'PAL_V2_SNAP_HOST');
  if (snapHost != null && !isIpv4(snapHost) && !/^[a-z0-9.-]+$/i.test(snapHost)) {
    problems.push('PAL_V2_SNAP_HOST must be an IPv4 address or a hostname');
  }

  const directoryFile = readFilePath(problems, env, 'PAL_V2_DIRECTORY_FILE');
  // Operator-owned display strings for the HTTP lbs.jsp response. Required so
  // that no V1 value can arrive as a default.
  const lobbyName = readRequired(problems, env, 'PAL_V2_LOBBY_NAME');
  const welcomeMessage =
    String(env.PAL_V2_WELCOME_MESSAGE ?? '').trim() || DEFAULT_WELCOME_MESSAGE;

  // Bounded by what the server can serve (the connection ceiling) at the top and
  // by the client's own gate at the bottom: a record's maximum of 0 makes
  // `sum >= max` true on the first player and the lobby is permanently full.
  const maximumPlayers = readCount(
    problems, env, 'PAL_V2_MAXIMUM_PLAYERS', DEFAULT_MAXIMUM_PLAYERS,
    { minimum: 1, maximum: TCP_LOBBY_CONNECTION_CEILING }
  );

  const enableDns = readBoolean(problems, env, 'PAL_V2_ENABLE_DNS', true);
  const enableDnas = readBoolean(problems, env, 'PAL_V2_ENABLE_DNAS', true);

  const dnsRecords = enableDns ? readDnsRecords(problems, env) : {};
  if (enableDns && Object.keys(dnsRecords).length === 0) {
    problems.push('PAL_V2_DNS_RECORDS must list at least one name=address while DNS is enabled');
  }

  let dnas = null;
  if (enableDnas) {
    dnas = {
      certificatePath: readFilePath(problems, env, 'PAL_V2_DNAS_CERT'),
      caCertificatePath: readFilePath(problems, env, 'PAL_V2_DNAS_CA_CERT'),
      privateKeyPath: readFilePath(problems, env, 'PAL_V2_DNAS_KEY'),
      packetDirectory: readDirectory(problems, env, 'PAL_V2_DNAS_PACKET_DIR', { mustExist: true }),
      port: readPort(problems, env, 'PAL_V2_DNAS_PORT', 443)
    };
  }

  // EXPERIMENT (OQ-023). V2 replays canned DNAS replies, so every console
  // receives the identical platform-session token and it identifies nobody
  // (T27). The client never validates the value, so the server may choose it -
  // but whether the DNAS reply carries an integrity check over that field is
  // UNKNOWN, so this is opt-in and reversible rather than the default.
  const enableDynamicDnasToken = readBoolean(
    problems,
    env,
    'PAL_V2_DYNAMIC_DNAS_TOKEN',
    false
  );

  const enableUdpRegister = readBoolean(problems, env, 'PAL_V2_ENABLE_UDP_REGISTER', true);
  // The register service cannot bind a wildcard. The client discards any reply
  // whose source IP:port is not exactly the serverIP:9090 it registered
  // against (FUN_001d72a8), and on a multi-homed host a 0.0.0.0 bind can answer
  // from a different address - which looks exactly like broken crypto. Default
  // to the SN@P host, which IS the address the client was told to dial, and
  // require an explicit IPv4 when that is a hostname.
  let udpBindAddress = String(env.PAL_V2_UDP_BIND_ADDRESS ?? '').trim();
  if (enableUdpRegister) {
    if (udpBindAddress === '' && snapHost != null && isIpv4(snapHost)) {
      udpBindAddress = snapHost;
    }
    if (!isIpv4(udpBindAddress)) {
      problems.push(
        'PAL_V2_UDP_BIND_ADDRESS must be the IPv4 address the client dials for UDP register; ' +
          'it cannot be a wildcard or a hostname, and it defaults to PAL_V2_SNAP_HOST only ' +
          'when that is itself an IPv4 address'
      );
    }
  }

  const logLevel = String(env.PAL_V2_LOG_LEVEL ?? 'info').trim().toLowerCase();
  if (!LOG_LEVELS.includes(logLevel)) {
    problems.push(`PAL_V2_LOG_LEVEL must be one of ${LOG_LEVELS.join(', ')}`);
  }

  const config = Object.freeze({
    bindHost,
    dataDirectory,
    masterKey: masterKey == null ? null : String(masterKey),
    selfHost,
    snapHost,
    snapPort: readPort(problems, env, 'PAL_V2_SNAP_PORT', 10127),
    descriptiveHexAddress: String(env.PAL_V2_DESCRIPTIVE_HEX ?? '000000000000').trim(),
    directoryFile,
    lobbyName,
    welcomeMessage,
    logLevel,
    // The capacity the directory must advertise for THIS server's own entries.
    // Cross-checked at startup in `app/application.js`, so the number the client
    // gates on cannot drift away from the number this process will admit.
    maximumPlayers,
    dns: Object.freeze({
      enabled: enableDns,
      port: readPort(problems, env, 'PAL_V2_DNS_PORT', 53),
      ttl: 60,
      records: Object.freeze(dnsRecords)
    }),
    dnas: dnas == null ? Object.freeze({ enabled: false }) : Object.freeze({
      enabled: true,
      dynamicToken: enableDynamicDnasToken,
      ...dnas
    }),
    http: Object.freeze({
      port: readPort(problems, env, 'PAL_V2_HTTP_PORT', 80)
    }),
    tcp: Object.freeze({
      port: readPort(problems, env, 'PAL_V2_TCP_PORT', 10127),
      maximumConnections: TCP_LOBBY_CONNECTION_CEILING
    }),
    udpRegister: Object.freeze({
      enabled: enableUdpRegister,
      port: readPort(problems, env, 'PAL_V2_UDP_REGISTER_PORT', 9090),
      bindAddress: udpBindAddress === '' ? null : udpBindAddress,
      /*
       * THE ATTACHMENT NONCE (T33), NOW ON BY DEFAULT.
       *
       * It was opt-in while the open question was whether an unmodified client
       * echoes the register reply's tail blob back in its bind. The rig run of
       * 2026-08-06 answered it: `captures/v2-live/t33-run11-nonce-echo.pcap`
       * frame 13 is a real PS2's bind carrying the exact 16 bytes minted for its
       * registration, and the journal records `matched: true`. The nonce byte
       * string occurs ONCE in that capture - in the bind, never in our reply,
       * because in our direction it travels inside the Blowfish body.
       *
       * The default changed because the nonce stopped being an experiment and
       * became the only proof a bind can offer: displacement of a live account
       * session requires it (D-2, `sessions/account-session.js`). Left off, no
       * bind can prove anything, so no player who restarts their console can
       * reclaim their own account session until it expires.
       *
       * Setting `PAL_V2_UDP_ATTACHMENT_NONCE=false` remains the rollback and
       * still emits tail length 0, byte-identical to V1.
       */
      attachmentNonce: readBoolean(problems, env, 'PAL_V2_UDP_ATTACHMENT_NONCE', true)
    }),
    /*
     * The SNAP_* experiment flags, following the V1 golden-flag naming
     * (`deploy/pi-env.d/`): each gates ONE unproven wire behaviour, defaults
     * OFF, and is retired - not defaulted on - once a rig run confirms it.
     */
    snapLobby: Object.freeze({
      /*
       * PORT-PLAN slice 2c-ii, the in-game beacon experiment: echo the
       * flags-0x2012 op-0x0F back to its sender / relay it to the sender's
       * room. What the beacon expects is Unknown (B1's single solo-start
       * blocker); these flags exist so the JP dumb-relay hypothesis is one
       * flag flip on the rig.
       *
       * ECHO RESULT, 2026-08-08 (RS1-A §2/§6.1): run twice on the rig, fatal
       * both times. The echo IS consumed (beaconing stops in under a second),
       * but the start dies faster and recovers worse than under silence -
       * ~120 s soft-fail with a meeting-room recovery becomes a <=13 s
       * hard-fail with none (one clean close, one hard hang). Default stays
       * FALSE and must stay false for owner-facing runs; the flag remains
       * only so the decompile arms of B1 gap #1 can re-test deliberately.
       */
      gameBeaconEcho: readBoolean(problems, env, 'SNAP_GAME_BEACON_ECHO', false),
      gameBeaconRelay: readBoolean(problems, env, 'SNAP_GAME_BEACON_RELAY', false),
      /*
       * B3 fix 1: mirror the client's op-0x02 close and release the session
       * (exit-contract RE: the 0xb000 close is a bidirectional handshake).
       * The exact close-confirm shape the client needs is gap G1 - hence OFF.
       */
      exitCloseMirror: readBoolean(problems, env, 'SNAP_EXIT_CLOSE_MIRROR', false),
      /*
       * B3 fix 2: echo the request's send-seq at op-0x28 sel-6/sel-7
       * completion payload +0xc (the RE'd reply contract's dual-key pool
       * match). OFF keeps the rig-confirmed 8-byte payloads byte-identical.
       */
      completionSeqEcho: readBoolean(problems, env, 'SNAP_COMPLETION_SEQ_ECHO', false),
      /*
       * C3 fix (SESSION-LOG-2026-08-24): sel-7/sel-8 completions echo the
       * request's DATA bit, so the room-channel (0xA0xx) in-room Exit gets a
       * room-channel completion. OFF keeps every reply byte-identical.
       */
      channelBitEcho: readBoolean(problems, env, 'SNAP_CHANNEL_BIT_ECHO', false),
      /*
       * 2026-08-24 wire fixes: room chat re-vehicled as op-0x10 sub-7 fragments
       * (the in-room text surface does not read the op-0x0F scrollback), and
       * the reliable game-packet relay (bioserver gameserver default-branch -
       * the fix for a joiner starving at "Game to begin shortly").
       */
      roomChatSub7: readBoolean(problems, env, 'SNAP_ROOM_CHAT_SUB7', false),
      gameRelay: readBoolean(problems, env, 'SNAP_GAME_RELAY', false),
      /* op-0x49 +0x1c = the create optionsWord (scenario/rules STAT). */
      roomStat: readBoolean(problems, env, 'SNAP_ROOM_STAT', false),
      /* max unacked reliable messages before the channel drops; raise for lossless in-game relay. */
      reliableWindow: readCount(problems, env, 'SNAP_RELIABLE_WINDOW', 32, { minimum: 32, maximum: 4096 }),
      /* op-06 memberId = the recipient's token, so the host's accept scan matches. */
      memberIdToken: readBoolean(problems, env, 'SNAP_MEMBER_ID_TOKEN', false),
      rosterToJoiner: readBoolean(problems, env, 'SNAP_ROSTER_TO_JOINER', false),
      hostReseat: readBoolean(problems, env, 'SNAP_HOST_RESEAT', false),
      /*
       * PORT-PLAN slice 1b, the JOIN ladder: the DATA-clear room-ENTER op-0x06
       * routes through the slot-allocator guards, and the op-0x10 app-sub-0x02
       * join-request is answered with the rig-proven sub-0x0C join-confirm
       * (V1 `SNAP_JOIN_OP10_SUBC`, Pi cead951e, 2-device). Default ON - a
       * stated deviation from the flags-start-OFF rule, by the owner's plan
       * for the coming rig run (PORT-PLAN slice 1b); rollback = set it false,
       * which restores every previous byte.
       */
      joinLadder: readBoolean(problems, env, 'SNAP_JOIN_LADDER', true),
      /*
       * PORT-PLAN slice 2a, the op-0x10 recipient-addressed relay (the
       * bioserver dumb-relay principle; carries the host-driven roster-SM
       * bursts on a 2-player start). Default ON for the same rig run; the
       * format is decompile-grounded and zero op-0x10 has ever been on the
       * wire, so the first 2-player start is also its verification.
       */
      op10Relay: readBoolean(problems, env, 'SNAP_OP10_RELAY', true),
      /*
       * RS1-B fix 1: answer the op-0x0a member-list with July V1's exact
       * 12-byte count-0 body (who 0xA0, twelve zero bytes) instead of the
       * count-1/zeroed-charstats reply. Two nights of wire (T37 emulator,
       * RS1 PS2) show the count-1 shape starving the client at "Getting
       * information" for ~142 s until it closes its own session; July's
       * count-0 joiner proceeded straight down the ladder (RS1-B §4/§5,
       * H-B). Default ON per the RS1-B fix list; rollback = set false,
       * which restores the count-1 reply byte-identically.
       */
      op0aCount0: readBoolean(problems, env, 'SNAP_OP0A_COUNT0', true),
      /*
       * RS1-B fix 2: the member-info supply channel V1's July golden set ran
       * and V2 dropped (RS1-B §4): op-28 sel-0x0a roster records alongside
       * every op-0x0c completion, and op-0x10 sub-1 player-info pushes on
       * join acceptance and in answer to EVERY inbound game-channel op-0x10.
       * The joiner's "Getting information" starve and the host's in-room
       * self-close both sit on this gap; the July client demonstrably
       * re-sent its op-10 until this answer arrived. Default ON per the
       * RS1-B fix list; rollback = set false (no roster records, no sub-1
       * pushes - byte-identical to the RS1 build).
       */
      memberInfo: readBoolean(problems, env, 'SNAP_MEMBER_INFO', true),
      /*
       * RS1-C C2: re-broadcast the op-0x09 USER count to an area's sessions on
       * every enter/leave of that area (the JP `broadcastAreaPlayerCnt`,
       * PacketHandler.java:661/746/1136). The owner-observed stale "2" is a
       * client-side latch with no refresh stimulus - the entry query's reply
       * handler (`FUN_005bf740`, dispatch slot 0x17) is installed persistently
       * and does no transaction matching, so a push byte-shaped like the
       * solicited answer re-renders the count (corpus-verified, this round).
       * Default ON per the RS1-C fix direction; rollback = set false, which
       * stops every unsolicited op-0x09 byte-identically.
       */
      countPush: readBoolean(problems, env, 'SNAP_COUNT_PUSH', true),
      /*
       * The SN@P APPLICATION keepalive (ROOM-WATCHDOG-RE.md, the ~145 s
       * op-0x02 self-close): the lobby overlay's liveness watchdog gives the
       * server 1800+1800 ticks (~145.7 s) of APPLICATION silence and is reset
       * only by lobby-overlay messages - op-0x40 feeds the other (840)
       * watchdog and never reaches it. The JP reference broadcasts HEARTBEAT
       * 0x6202 every 30 s for exactly this obligation; V2 sent no unsolicited
       * application traffic at all, so a client that stopped querying always
       * probed (op-0x14), heard nothing, and closed. ON = one op-0x10
       * who-0xA000 push with app-payload byte 0x00 (a pure watchdog reset -
       * the handler's switch has no case for it) every 30 s per established
       * session. Default ON (G12); rollback = set false, which stops every
       * push and is byte-identical otherwise.
       */
      appKeepalive: readBoolean(problems, env, 'SNAP_APP_KEEPALIVE', true),
      /*
       * PORT-PLAN slice 2b's wire half: publish the engine's authored room
       * status in the op-0x49 record flags word +0x1c. OFF - no console has
       * ever rendered non-zero flags and H-B suspects zeros gate the join UI.
       */
      roomFlagsPublish: readBoolean(problems, env, 'SNAP_ROOMFLAGS_PUBLISH', false),
      /*
       * The TCP create-config dialogue (BIOSERVER-CONTRACT §6 create rows:
       * CREATESLOT 0x6407 ... commit 0x6504), answered after the 0x1004 ladder
       * completion. Default ON, and that is safe for the rig-confirmed paths
       * because the RS1-20260808 inventory shows none of these USAGES in its
       * one session's post-completion window (0x6504 the command rides every
       * ladder and is answered there; the create-commit usage is what has not
       * been captured, and one session is not proof it never will be): until
       * the client sends one, the flag changes zero bytes on the wire.
       * Rollback = set it false, which restores the observed-not-answered
       * behaviour for those frames.
       */
      createConfig: readBoolean(problems, env, 'SNAP_CREATE_CONFIG', true),
      /*
       * The `+0x12fc` option-label table in the area blob (B5): ON serves the
       * table region as eleven zero records (version OBAREA-W4), which blanks
       * the stale-memory garbage labels; OFF serves the rig-confirmed OBAREA-W3
       * blob byte-identically. The record fields the client reads are additive
       * bytes past the old 0x1300 end, inside the client's own 0x2000 static
       * buffer (FUN_001c2f80: 0x361a70/0x363a70).
       *
       * Default OFF (nora, 2026-08-08 review): this is the one change in the
       * round that alters an 11-slice bulk transfer the rig has already
       * confirmed byte-for-byte, and it must not share a deploy with the
       * behavioural fixes - one suspect per change. Turn it ON deliberately,
       * on a run whose only variable is this table.
       */
      optionLabels: readBoolean(problems, env, 'SNAP_OPTION_LABELS', false),
      /*
       * The create-screen rule bytes (docs/design/v2-port/RULES-MASK-RE.md
       * §6.2): both `+0x16c`/`+0x1a8` parameter blocks carry `F3 E2` + the
       * per-area group-1 rule rows, `+0x16b = 0x03` (title/password settable),
       * `+0x03 = 0xFF` (all 8 base characters), `+0x04..0x13 = 0xFF` (extra
       * cast permitted, savedata-ANDed), and `+0x14`/`+0x18` = the full 0x7FF
       * SCENARIO ring on enabled areas - served as OBAREA-W5 (V6 if the
       * option-label flag is also on; the two are independent). This is what
       * makes rules, cast and scenario selectable on the create screen at all -
       * the previous blob rendered every row red (RIG-SESSION-1 R1). Default ON
       * (G12, the create-screen unlock); rollback = set false, which serves the
       * previous blob byte-identically under its previous version.
       */
      ruleMasksAuthentic: readBoolean(problems, env, 'SNAP_RULE_MASKS_AUTHENTIC', true),
      /*
       * The reference-ported lobby-button replies on TCP 10127 (G6/G7:
       * RANKINGS 0x6145, GETINFO 0x6801, BUDDYLIST 0x6707, CHECKBUDDY 0x6703),
       * answered after the ladder completes. Wire-inert today: the RS1 TCP
       * inventory proved none of these commands has ever arrived on TCP, so
       * until the client sends one the flag changes zero bytes on any
       * rig-confirmed path. Rollback = set it false (observed-not-answered).
       */
      lobbyButtons: readBoolean(problems, env, 'SNAP_LOBBY_BUTTONS', true)
    })
  });

  if (!/^[0-9a-f]{12}$/i.test(config.descriptiveHexAddress)) {
    problems.push('PAL_V2_DESCRIPTIVE_HEX must be twelve hex digits');
  }

  if (problems.length > 0) throw new ConfigurationError(problems);
  return config;
}

/** The environment variables a deployment must or may set, for the runbook. */
export const CONFIGURATION_KEYS = Object.freeze({
  required: Object.freeze([
    'PAL_V2_MASTER_KEY',
    'PAL_V2_DATA_DIR',
    'PAL_V2_SELF_HOST',
    'PAL_V2_SNAP_HOST',
    'PAL_V2_DIRECTORY_FILE',
    'PAL_V2_LOBBY_NAME'
  ]),
  optional: Object.freeze([
    'PAL_V2_BIND_HOST',
    'PAL_V2_LOG_LEVEL',
    'PAL_V2_HTTP_PORT',
    'PAL_V2_TCP_PORT',
    'PAL_V2_SNAP_PORT',
    'PAL_V2_DESCRIPTIVE_HEX',
    'PAL_V2_WELCOME_MESSAGE',
    'PAL_V2_MAXIMUM_PLAYERS',
    'PAL_V2_UDP_ATTACHMENT_NONCE',
    'SNAP_GAME_BEACON_ECHO',      // echo the flags-0x2012 in-game beacon to its sender (default false)
    'SNAP_GAME_BEACON_RELAY',     // fan the in-game beacon out to the sender's room (default false)
    'SNAP_EXIT_CLOSE_MIRROR',     // mirror the op-0x02 close and release the session (default false)
    'SNAP_COMPLETION_SEQ_ECHO',   // echo the request send-seq at completion +0xc (default false)
    'SNAP_CHANNEL_BIT_ECHO',      // sel-7 leave completion echoes the request's DATA bit (default false)
    'SNAP_ROOM_CHAT_SUB7',        // room chat relayed as op-0x10 sub-7 fragments (default false)
    'SNAP_GAME_RELAY',            // relay reliable game-channel op-0x0F to room members (default false)
    'SNAP_ROOM_STAT',             // op-0x49 +0x1c carries the create optionsWord so joiners see the scenario (default false)
    'SNAP_MEMBER_ID_TOKEN',       // op-06 memberId = recipient token, unblocks the 2-player game start (default false)
    'SNAP_ROSTER_TO_JOINER',      // push each existing member's op-06 to a joiner so its member list shows them (default false)
    'SNAP_HOST_RESEAT',           // re-seat the host on join so the start roster counts 2 (non-solo start) (default false)
    /*
     * The PORT-PLAN slice 1b/2a/2b flags. The first two default ON (the stated
     * deviation from flags-start-OFF, by the owner's plan for the rig run) -
     * which makes listing them here MANDATORY: their rollback story is "set it
     * false", and a runbook reader can only roll back a flag it can see
     * (nora pre-deploy review, caveat 3 / fix 4).
     */
    'SNAP_JOIN_LADDER',           // the op-0x06 room-ENTER join ladder + sub-0x0C confirm (default TRUE; rollback = set false)
    'SNAP_OP10_RELAY',            // the op-0x10 room-scoped except-sender relay (default TRUE; rollback = set false)
    'SNAP_OP0A_COUNT0',           // answer op-0x0a with July V1's 12-byte count-0 body (default TRUE; rollback = set false restores the count-1 reply)
    'SNAP_MEMBER_INFO',           // the V1 member-info supply channel: sel-0x0a roster records + op-0x10 sub-1 pushes (default TRUE; rollback = set false)
    'SNAP_COUNT_PUSH',            // re-broadcast the op-0x09 USER area count on every area enter/leave (default TRUE; rollback = set false stops every unsolicited op-0x09)
    'SNAP_APP_KEEPALIVE',         // the 30 s op-0x10 who-0xA000 app-liveness keepalive that holds off the client's ~145.7 s watchdog self-close (default TRUE; rollback = set false stops every push)
    'SNAP_ROOMFLAGS_PUBLISH',     // publish the authored room status in the op-0x49 flags word +0x1c (default false)
    'SNAP_CREATE_CONFIG',         // answer the TCP create-config rows 0x6407..0x6504 post-ladder (default TRUE; wire-inert until the client sends one there - unobserved in RS1's one session, not proven never; rollback = set false)
    'SNAP_OPTION_LABELS',         // serve the +0x12fc option-label table as zero records, version OBAREA-W4 (default FALSE - the 11-slice transfer must not share a deploy with anything else; true enables)
    'SNAP_RULE_MASKS_AUTHENTIC',  // serve the RULES-MASK-RE.md create-screen bytes (rule rows, cast, scenario ring) as OBAREA-W5/V6 (default TRUE; rollback = set false, byte-identical previous blob)
    'SNAP_LOBBY_BUTTONS',         // answer RANKINGS/GETINFO/BUDDYLIST/CHECKBUDDY post-ladder per the bioserver reference (default TRUE; wire-inert until the client sends one; rollback = set false)
    'PAL_V2_ENABLE_DNS',
    'PAL_V2_DNS_PORT',
    'PAL_V2_DNS_RECORDS',
    'PAL_V2_ENABLE_DNAS',
    'PAL_V2_DNAS_PORT',
    'PAL_V2_DNAS_CERT',
    'PAL_V2_DNAS_CA_CERT',
    'PAL_V2_DNAS_KEY',
    'PAL_V2_DNAS_PACKET_DIR'
  ])
});
