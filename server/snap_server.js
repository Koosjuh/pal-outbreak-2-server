/**
 * PAL Outbreak File #2 â€” SN@P server (Bio-Serv style architecture).
 *
 * Design notes (2026-05-14):
 * - Bio-Serv's command IDs (0x6101 LOGIN, 0x6203 AREACOUNT, ...) map directly
 *   to PAL handlers we decompiled from the EE binary at 0x1c5a20 (02 61 01),
 *   0x1c4960 (02 62 03), etc. See memory/project_re_outbreak_pal_server.md.
 * - PAL frame format (verified from captures + decompile):
 *      byte 0-1: 0x00 0x00      (always)
 *      byte 2  : direction      (01=CLIENT ask, 02=SERVER tell, 10=SERVER challenge)
 *      byte 3-4: cmd            (16-bit, big-endian â€” e.g. 61 01 = LOGIN)
 *      byte 5-7: 3 bytes        (small params/PID/err)
 *      byte 8+ : optional payload (read by EE handler via cursor, BIG-ENDIAN u32s)
 * - Handler payload reader: FUN_001c3b10 in EE reads BE u32 from cursor.
 * - State machine: BOOT_AUTH (initial 3 packets, then close)
 *                  â†’ LOBBY (game makes second connection after lbs.jsp arm)
 *                  â†’ DISPATCH (request/response loop until logout)
 */
'use strict';
const net = require('net');
const fs = require('fs');
const path = require('path');
const { RUN_ID } = require('./run_id');
const { HOST_IP, HOST_IP_BE } = require('./host_ip');
const { getPendingOnline, loadStore, saveStore } = require('./session_store');
const lobbyState = require('./lobby_state');
const { PineClient } = require('../tools/pine_client');

// Auto-inspect on SESSION_VERIFY — captures state[0x29] (hash length the LOGIN
// handler expects). Was running 2× 3MB EE RAM scans per SESSION_VERIFY which
// destabilized PCSX2 (D901 / crashes). DISABLED 2026-05-24 — use the passive
// tools/mem_watcher.js for memory diagnostics instead. To re-enable for a
// targeted test, set env var SNAP_AUTO_INSPECT=1.
let autoInspect = null;
let formatAutoReport = null;
if (process.env.SNAP_AUTO_INSPECT === '1') {
  try {
    const ai = require(path.resolve(__dirname, '..', 'tools', 'auto_inspect'));
    autoInspect = ai.inspectStateStruct;
    formatAutoReport = ai.formatReport;
    console.log('[snap] SNAP_AUTO_INSPECT=1 — heavy PINE scans enabled');
  } catch (e) {
    // module missing — feature disabled
  }
}

const PORT = 10127;
const ACTIVE_ROOT = path.resolve(__dirname, '..');
const CAPTURES_DIR = path.join(ACTIVE_ROOT, 'captures');
if (!fs.existsSync(CAPTURES_DIR)) fs.mkdirSync(CAPTURES_DIR);

// --- protocol constants ---
const DIR_CLIENT_ASK    = 0x01;
const DIR_SERVER_TELL   = 0x02;
const DIR_SERVER_CHALL  = 0x10;
const DIR_GAMESERVER    = 0x28;

// Bio-Serv commands we currently handle (PAL byte[3]:byte[4] = cmd hi:lo)
const CMD = {
  LOGIN          : 0x6101,
  // 2026-05-28: wire cmd 0x6103 was wrongly labeled CHECKVERSION (Codex
  // inherit). Ghidra dispatch-table dump (analysis/claude-dispatch-table-
  // 2026-05-26.txt) shows table idx 0x2e dir=02 cmd=0x6103 routes to
  // FUN_001c5f30 — the chunk-list-with-key MANIFEST parser. Our previous
  // 4-byte zero reply trivially advanced state via count=0 → sub=2.
  CHUNK_LIST_61  : 0x6103,
  // 2026-05-29: wire cmd 0x6105 — STATUS/MESSAGE TABLE manifest. Dispatch
  // table idx 0x32 (dir=02 cmd=0x6105) → FUN_001c63c0 parser. Populates
  // 0x00365bb0 (count), 0x00365bb4[] (codes), 0x00365bd4[] (metadata),
  // 0x00365bf4[] (per-entry buffer ptr = 0x35ccb8 + i*0x200). After parse
  // → state+0xd = 0x41 → game emits cmd 0x6320 chunk-fetch.
  // Reply shape: u16_be count (max 8) + per entry (u32_be code, u32_be meta).
  // This table is what FUN_00626730 callback gates against for press-X
  // success — but only matters if a 0x27 event push arrives. Empty/no-table
  // is also valid; the gate cRam0086f7e0 stays 0.
  STATUS_TABLE_61: 0x6105,
  // Status table chunk-fetch (dispatch idx 0x41/0x42 → FUN_001c8ae0)
  STATUS_FETCH_63: 0x6320,
  IDHNPAIRS      : 0x6131,
  HNSELECT       : 0x6132,
  CHARSELECT     : 0x6190,
  CONNCHECK      : 0x6001,
  SESSION_VERIFY : 0x6110,   // PAL-specific (game's reply after CONNCHECK challenge)
  HEARTBEAT      : 0x6202,
  AREACOUNT      : 0x6203,
  AREANAME       : 0x6204,
  AREAPLAYERCNT  : 0x6205,
  AREASTATUS     : 0x6206,
  AREASELECT    : 0x6207,
  ROOMSCOUNT     : 0x6301,
  SLOTCOUNT      : 0x6401,
  GO_ONLINE      : 0x6002,
  ENTERAGL       : 0x6210,
  LOBBY_INIT     : 0x1007,   // PAL TCP-10127 lobby/version/config exchange (Codex analysis/tcp10127-cmd1007.md)
  POST_LOBBY_ACK : 0x1004,   // Empty-success ACK after lobby walk (Codex analysis/tcp10127-cmd1004.md). EE stub at 0x1c8e90 is `jr ra; li v0,1`.
  LEAVEAGL       : 0x6211,   // Bio-Serv name; PAL repurposes in boot-lobby progression (Codex analysis/tcp10127-cmd6211.md). FUN_001c45f0 reads BE u32.
  AGLPLAYERCNT   : 0x6212,   // PAL aftergame-lobby player count (Codex analysis/tcp10127-cmd6212.md). FUN_001c4360 expects BE u32; moves lobby state to 0x10.
  AGLSTATS       : 0x6213,   // PAL aftergame-lobby stats (Codex: expects 8 BE u16 values)
  LOBBY_HEADER   : 0x6501,   // PAL "lobby header" per Ghidra export label (Codex analysis/tcp10127-cmd6501.md). FUN_001c6e80. Bio-Serv name CANCELSLOT but ignore.
  LOBBY_SLOT     : 0x6502,   // PAL "lobby slot" per Ghidra export label (Codex analysis/tcp10127-cmd6502.md). FUN_001c7680. Same mode-byte protocol as LOBBY_HEADER.
  LOBBY_HEADER_DETAILS: 0x6503, // PAL header/list detail population. FUN_001c70b0. Needed after LOBBY_HEADER mode=1.
  LOBBY_SLOT_DETAILS: 0x6504,// PAL slot-detail population (Codex analysis/tcp10127-cmd6504.md). FUN_001c7a70. Sets current_entry+0x365f78 (slot count read later by FUN_001c8790).
  // 2026-06-04: REVERTED to 0x6510 after 0x6505 caused MAJOR regression (game didn't
  // even pass 21% loading bar). Theory that dispatch table 0x2488F4 indexes by (cmd-0x6501)
  // is WRONG. 0x6510 IS the correct wire opcode. The handler at 0x1C8790 must be reached
  // through different indexing (table NOT contiguous, or cmd is masked differently).
  // See D:/projects/pal-outbreak-2-server/handoff/overnight-deep-re-2026-06-04.md
  LOBBY_LIST_CHUNK: 0x6510,
  // 2026-05-28: wire cmd 0x6104 is the chunk-fetch handler (FUN_001c6130 @
  // table idx 0x30). Game emits dir=01 cmd=0x6104 with u32 key + u32 offset
  // + u16 size. We reply dir=02 cmd=0x6104 with u32 key + u32 offset + u16
  // len + snapField(data).
  CHUNK_FETCH_61 : 0x6104,
  // 2026-05-28: chunk-list family for the "0x39/0x3b" path Codex described
  // is actually wire cmds 0x6401 / 0x6402 (table idx 0x3a / 0x3c). Same
  // shape as 0x6103/0x6104 except no per-entry key.
  CHUNK_LIST_64  : 0x6401,
  CHUNK_FETCH_64 : 0x6402,
};
const CMD_NAME = Object.fromEntries(Object.entries(CMD).map(([k,v]) => [v, k]));

// --- example area list (small, for POC) ---
const AREAS = [
  { name: 'PAL Lobby',    status: 0, playerCount: 0 },
  { name: 'Test Area',    status: 0, playerCount: 0 },
];

// === Area-list (0x6203 mode=0x01 -> 0x6204 blob) implementation ==============
// Evidence: docs/findings/protocol/AREA-LOBBY-FIELD-MAP-EVIDENCE-2026-06-30.md
// Gated behind SNAP_AREA_LIST=1 (default OFF -> golden mode=0x02 path).
// Area buffer (EE 0x361a70) holds 10 box records of 0x1e4 bytes. Per box:
//   +0x1c (24B) = NAME (drawn label), +0x4c (256B) = description,
//   +0x14c (byte) = status, +0x16c (stride 0x3c) = modifiers (left 0 for v1).
const AREA_LIST_ENABLED = process.env.SNAP_AREA_LIST === '1';
const AREA_PLAYERCNT_ENABLED = process.env.SNAP_AREA_PLAYERCNT === '1';
const AREA_REC_SIZE = 0x1e4;
const AREA_BOX_COUNT = 10;
const AREA_BLOB_SIZE = 0x1300;          // covers 10 records (0x12d8); must be <= 0x2000
const AREA_CHUNK = 0x2f2;               // EE FUN_001c4d40 chunk stride
const AREA_TAG = process.env.SNAP_AREA_TAG || 'OBAREA-V1';  // <=31 chars; must differ from cache
// Box record +0x14c status byte. Traced gate (PROVEN 2026-07-01, RUNTIME-confirmed):
//   blob+0x14c --(op48, FUN_005c1220)--> display status 0x6ce5f0[box]
//              --(detail build, FUN_005bf9e0)--> enable 0x6c386e[box]
//              --(select gate, FUN_005ad350)--> `if (enable != 3) return -1` (BUZZ).
// So the value MUST be 3 for a box to be selectable (un-greyed, no buzz, detail draws).
// Value 1 rendered but stayed grey/buzzed; value 3 = selectable (on-screen confirmed).
const AREA_STATUS = parseInt(process.env.SNAP_AREA_STATUS || '3', 0) & 0xff;
// Status byte values (bioserver Area.java:28-29): STATUS_ACTIVE=3 (selectable), STATUS_INACTIVE=0 (greyed).
const AREA_STATUS_INACTIVE = 0;
// SECRET area (#10) activation is a server-policy UNKNOWN (RULE-DATA-CATALOG §6 #8, needs-decompile).
// Reference DEFAULT = STATUS_INACTIVE — bioserv2 PacketHandler.java:105 `new Areas(Area.STATUS_INACTIVE)`.
// Overridable via env for when the activation condition is captured; do NOT fabricate an activation rule.
const SECRET_AREA_STATUS = parseInt(process.env.SNAP_SECRET_AREA_STATUS || '0', 0) & 0xff;
// The 10 boxes the area-select grid shows. Names <=23 chars (24B field, NUL-term).
// 2026-07-19 (G-area-data): replaced the previously-INVENTED label set
// (Free/Normal/Hard/Very Hard/Nightmare/Infinite/75% Healing/Double Damage/Infinite Ammo/No Healing)
// with the authentic File #2 area roster. Ground truth = bioserv2/Areas.java:35-44 (the JP Bioserver
// File#2 app protocol) + docs/findings/reference/RULE-DATA-CATALOG-2026-07-19.md §1.1 (grade: HIGH —
// reference-confirmed). File #1's 2-area set (East/West Town) is a DIFFERENT SKU and out of scope here
// (this server speaks File #2 / SLES-53319; catalog §1.3). An area = a rule PRESET + scenario set, NOT
// a fixed-difficulty box (catalog §1.2: there are no fixed-difficulty areas — that set was our invention).
// `mode` keys the per-area +0x16c ruleset (AREA_MODIFIER_BYTES, flag-gated). `status` overrides the
// default AREA_STATUS for the two non-active areas: #6 reserved = INACTIVE (HIGH, Areas.java:40) and
// #10 SECRET = SECRET_AREA_STATUS (reference default INACTIVE; activation condition is an UNKNOWN).
// Descriptions are the reference content (Areas.java) as plain text — the client-side rendering of
// bioserver's <BODY>/<SIZE>/<C> markup is unverified, so we ship the readable text only, not the tags.
const AREA_BOXES = [
  { name: 'Free Area',   desc: 'Join games or create your own',                mode: 'free' },
  { name: 'Nightmare',   desc: 'Nightmare mode is ON by default',              mode: 'nightmare' },
  { name: 'Survival',    desc: 'Friendly Fire is ON by default',              mode: 'survival' },
  { name: 'Panic',       desc: 'Nightmare mode and friendly fire is on!',      mode: 'panic' },
  { name: 'Infinity',    desc: 'Infinite bullets. Not considered for rankings!', mode: 'infinity' },
  { name: 'reserved',    desc: 'reserved',                                     mode: 'reserved', status: AREA_STATUS_INACTIVE },
  { name: 'TESTING',     desc: 'For tests. Expect problems and crashes, use at your own risk', mode: 'testing' },
  { name: 'Elimination', desc: 'Play scenarios elimination 1-3',               mode: 'elimination' },
  { name: 'Showdown',    desc: 'Play scenarios showdown 1-3',                  mode: 'showdown' },
  { name: 'SECRET Area', desc: '?????  Not considered for rankings!',          mode: 'secret', status: SECRET_AREA_STATUS },
];
// 2026-07-02 T10: +0x16c modifier/rule region (decoded — docs/specs/L3-app-protocol-spec.md §6).
// Per box, blob+0x16c: byte[0]=players field, byte[1]=wait-limit field (each: bits0-5 value where
// bits0-1 current/bits2-3 min/bits4-5 max, bit6 changeable, bit7 ENABLE), byte[2]=difficulty entry
// count (entries @+3 stride4 [idx,val,enable,attr]), byte[0x2b]=buffer entry count (@+0x2c). Decoder
// FUN_005c2f40/2bc0/2d70. GAP being tested: does seeding the area ruleset here populate the create
// RULE screen (scenario/rules/characters) — Model A — or is a per-slot scene-type query also needed
// (Model B). Conservative first iteration: enable the "No. of Players" group only (byte[0]), diff/
// buffer counts 0, so at most one clean option line renders and we observe the effect safely.
// Flag-gated SNAP_AREA_MODIFIERS=1 (default OFF -> byte region stays 0 = current golden behavior).
const AREA_MODIFIERS_ENABLED = process.env.SNAP_AREA_MODIFIERS === '1';
// 2026-07-11 G12: seed the per-box SCENARIO bitmask at area rec +0x03 (+0x04 hi) so the create/RULE
// screen's scenario array (FUN_005fe300 reads rec +0x03/+0x04) is NON-NULL — the RULE screen shows
// selectable scenarios instead of "(null)". Enter-safe (the area-enter gate FUN_005ad350 never reads
// +0x03/+0x04 — G8-createslot-handshake-RE §"Correction"). Discriminator for the op0c commit wall:
// does a valid (non-null) scenario let the create commit advance? Default OFF (golden byte-region 0).
const SCENARIO_ENABLED = process.env.SNAP_AREA_SCENARIO === '1';
const SCENARIO_BITS    = parseInt(process.env.SNAP_AREA_SCENARIO_BITS || '0x1f', 0) & 0xff;  // G8 test value
const SCENARIO_BITS_HI = parseInt(process.env.SNAP_AREA_SCENARIO_BITS_HI || '0', 0) & 0xff;
// Per-area +0x16c ruleset bytes (offsets +0x00..): byte0 players
// [(cur&3)|(min<<2)|(max<<4)|(chg<<6)|(en<<7)], byte1 wait [(val&7)|((count-1)<<3)|(chg<<6)|(en<<7)],
// byte2 diff-count, +0x03 diff entry [opt_index,value,enable,attribute]. (per-area-rulesets-RE-2026-07-02.md)
// Free = all changeable; Hard/Very Hard = difficulty line FIXED (attribute 0). Special-mode flag
// indices (Nightmare/Infinite/heal/dmg/ammo) need rig table-enumeration -> default to Free for now.
// 2026-07-02 REGRESSION NOTE: the per-area-rulesets-RE arrays (F3 E2 …) LOCKED the area-select
// advance — the players byte F3 encodes cur=3/max=3, an OUT-OF-RANGE index for the real (unvalidated)
// option table (agent flagged the indices as needing rig enumeration). Safe baseline = T10's proven
// value: players enable+changeable, min=0/max=2/cur=0 (index 0, in range) = 0xE0; no wait/difficulty
// entries yet. This ADVANCES + makes "number of players" selectable on the create RULE screen (Model
// A, T10-proven). The players-count and difficulty option INDICES are enumerated from here (vary
// SNAP_AREA_PLAYERS_MAX / a difficulty entry index, read the create-screen render) — the panel lives
// in the create flow (armed by FUN_005c0960), not area-select highlight.
// Per-area +0x16c rulesets, byte-exact from the disc option-table indices (per-area-rulesets-RE-2026-
// 07-02.md "OPTION TABLE INDICES"): players F0 (en|chg|max3|cur0 = 1-4 players), wait E2 (en|chg|
// 5 opts|10min), then [diff-count][entries...] each entry [opt_index, value, enable, attribute]
// (attr 1=changeable/0=fixed). Difficulty=opt1 (Easy0/Normal1/Hard2/VeryHard3), Nightmare=opt5,
// Infinity=opt6 (flag value 1=on). opt0 is the HEADER (out-of-range value there = the earlier lock).
// 2026-07-19 (G-area-data): re-keyed to the authentic File #2 area modes with the Bioserver-faithful
// per-area +0x16c bytes from RULE-DATA-CATALOG §1.4 (which supersedes the old invented free/normal/hard/
// veryhard keys and their 0xF0 players byte — catalog §1.4 flags 0xF0/1-player as WRONG for online).
// Encoding (format grade HIGH, byte VALUES grade MED): byte0=players, byte1=wait, byte2=diff-group
// entry-count, then N x [opt,val,en,attr] at +0x03. Difficulty=opt1 (val3=Very Hard, attr1=changeable);
// per-area fixed flags: FriendlyFire=opt2, Nightmare=opt5, Infinity=opt6 (val1=on, attr0=fixed).
//   area 2 Nightmare -> NM opt5 fixed on;  area 3 Survival -> FF opt2 fixed on;
//   area 4 Panic -> FF+NM both fixed on;   area 5 Infinity -> FF/NM changeable-off + INF opt6 fixed on.
// These per-area flag PRESETS are HIGH-confidence (RuleSet.java area switch, catalog §3).
// OPEN UNKNOWN (catalog §6 #4, needs-rig): the players min/max byte — 0xF7 (cur3|min1|max3) vs 0xE2
// (min0|max2|cur2). We ship the catalog's documented 0xF7; DO NOT treat it as rig-validated. This whole
// table only reaches the wire when SNAP_AREA_MODIFIERS=1 (default OFF => +0x16c stays 0 = golden), so
// the MED/unknown byte values never touch the validated golden path.
const AREA_MODIFIER_BYTES = {
  free:        [0xF7, 0xE2, 0x01, 0x01, 0x03, 0x01, 0x01],                                            // all changeable (default preset)
  nightmare:   [0xF7, 0xE2, 0x02, 0x01, 0x03, 0x01, 0x01, 0x05, 0x01, 0x01, 0x00],                    // + Nightmare fixed ON
  survival:    [0xF7, 0xE2, 0x02, 0x01, 0x03, 0x01, 0x01, 0x02, 0x01, 0x01, 0x00],                    // + Friendly Fire fixed ON
  panic:       [0xF7, 0xE2, 0x03, 0x01, 0x03, 0x01, 0x01, 0x02, 0x01, 0x01, 0x00, 0x05, 0x01, 0x01, 0x00], // FF + NM fixed ON
  infinity:    [0xF7, 0xE2, 0x04, 0x01, 0x03, 0x01, 0x01, 0x02, 0x00, 0x01, 0x01, 0x05, 0x00, 0x01, 0x01, 0x06, 0x01, 0x01, 0x00], // FF/NM changeable-off + Infinity fixed ON
  reserved:    [0xF7, 0xE2, 0x01, 0x01, 0x03, 0x01, 0x01],                                            // default preset (area is INACTIVE)
  testing:     [0xF7, 0xE2, 0x01, 0x01, 0x03, 0x01, 0x01],                                            // default preset (like Free)
  // Elimination (#8) / Showdown (#9): default RULE preset (HIGH). Their distinct SCENARIO SET lives in
  // the +0x04 bitmask whose exact bit positions are an UNKNOWN (catalog §2/§6 #2, needs-capture) — so
  // the scenario differentiation is deliberately NOT encoded here (only the rule preset is).
  elimination: [0xF7, 0xE2, 0x01, 0x01, 0x03, 0x01, 0x01],
  showdown:    [0xF7, 0xE2, 0x01, 0x01, 0x03, 0x01, 0x01],
  secret:      [0xF7, 0xE2, 0x01, 0x01, 0x03, 0x01, 0x01],                                            // default preset (area is INACTIVE by default)
};
function writeAreaModifiers(buf, rec, mode) {
  const bytes = AREA_MODIFIER_BYTES[mode] || AREA_MODIFIER_BYTES.free;  // unmapped -> default (Free) preset
  for (let i = 0; i < bytes.length; i++) buf[rec + 0x16c + i] = bytes[i];
}
function totalInAreaPlayerCount() {
  const ids = new Set();
  for (const [, set] of lobbyState.areaIndex) {
    for (const idKey of set) ids.add(idKey);
  }
  return ids.size;
}
function knownOnlinePlayerCount() {
  return Math.max(lobbyState.players.size, lobbyState.endpointIndex.size);
}
function areaPlayerCountForWire(fallbackCount) {
  if (!AREA_PLAYERCNT_ENABLED) return fallbackCount;
  // PAL UDP area-entry does not report the selected area; current registry wiring
  // records all in-area presence as area 1. The least-false TCP display is the
  // total in-area count for every area: correct when only one area is populated,
  // explicitly not proof of true per-area membership.
  return totalInAreaPlayerCount();
}
function serverSelectPlayerCountForWire(fallbackCount) {
  return AREA_PLAYERCNT_ENABLED ? knownOnlinePlayerCount() : fallbackCount;
}
function buildAreaBlob() {
  const buf = Buffer.alloc(AREA_BLOB_SIZE, 0);
  for (let i = 0; i < AREA_BOX_COUNT; i++) {
    const rec = i * AREA_REC_SIZE;
    const box = AREA_BOXES[i] || { name: `Area ${i + 1}`, desc: '' };
    writeFixedLatin1(buf, rec + 0x1c, 24, box.name);     // NAME (drawn label)
    if (box.desc) writeFixedLatin1(buf, rec + 0x4c, 256, box.desc); // description
    // status -> display 0x6ce5f0 (3=selectable, 0=greyed). Active areas follow AREA_STATUS; the two
    // non-active areas carry an explicit per-box override (#6 reserved=INACTIVE, #10 SECRET=policy).
    buf[rec + 0x14c] = (box.status !== undefined ? box.status : AREA_STATUS) & 0xff;
    if (SCENARIO_ENABLED) { buf[rec + 0x03] = SCENARIO_BITS; buf[rec + 0x04] = SCENARIO_BITS_HI; } // scenario array seed (enter-safe)
    if (AREA_MODIFIERS_ENABLED) writeAreaModifiers(buf, rec, box.mode);   // +0x16c per-area ruleset
  }
  return buf;
}

// === Packet class ============================================================
// PAL frame (verified from EE decompile, FUN_001c3880 lines 2557-2562):
//   bytes 0-1: payload length (BE u16) â€” NOT padding!
//   byte 2  : direction (01 client-query, 02 server-tell, 10 server-broadcast)
//   bytes 3-4: cmd (BE u16)
//   byte 5  : pid / sub-param
//   byte 6  : err flag â€” 0xFF here makes every EE handler take the error path
//             via `if (*(state[0xc]+6) == -1)` â†’ reset state, FIN.
//   byte 7  : padding / param
//   bytes 8+: payload (EE reads via FUN_001c3a60 / FUN_001c3b10 / FUN_001c3b90)
//
// The payload buffer cursor (state[0x40]) starts at 0 of the payload â€” NOT
// at byte 5. Bytes 5-7 are command-specific args inside the header, not
// payload. So `sub_cmd` reads happen against payload[0], i.e. packet[8].

class Packet {
  /**
   * @param {Buffer|null} raw  if given, parse it
   * @param {object} [opts]    if no raw, build from { dir, cmd, p5, p6, p7, payload }
   */
  constructor(raw, opts) {
    if (raw && raw.length >= 8) {
      this.payloadLen = raw.readUInt16BE(0);
      this.dir = raw[2];
      this.cmd = raw.readUInt16BE(3);
      this.p5  = raw[5];
      this.err = raw[6];                            // err flag (0xFF = error)
      this.p7  = raw[7];
      this.payload = raw.length > 8 ? raw.slice(8, 8 + this.payloadLen) : Buffer.alloc(0);
    } else if (opts) {
      this.dir = opts.dir ?? DIR_SERVER_TELL;
      this.cmd = opts.cmd ?? 0;
      this.p5  = opts.p5 ?? 0;
      this.err = opts.err ?? 0;                     // default OK
      this.p7  = opts.p7 ?? 0;
      this.payload = opts.payload ?? Buffer.alloc(0);
      this.payloadLen = this.payload.length;
    }
  }
  toBuffer() {
    const buf = Buffer.alloc(8 + this.payload.length);
    buf.writeUInt16BE(this.payload.length, 0);      // bytes 0-1 = payload length BE
    buf[2] = this.dir;
    buf.writeUInt16BE(this.cmd, 3);
    buf[5] = this.p5;
    buf[6] = this.err;                              // err flag (must be 0, NOT 0xFF)
    buf[7] = this.p7;
    if (this.payload.length) this.payload.copy(buf, 8);
    return buf;
  }
  toString() {
    const name = CMD_NAME[this.cmd] || `?`;
    return `dir=${this.dir.toString(16).padStart(2,'0')} cmd=0x${this.cmd.toString(16).padStart(4,'0')}(${name}) p5=${this.p5.toString(16)} err=${this.err.toString(16)} p7=${this.p7.toString(16)} payload=${this.payload.length}B`;
  }
}

// Helper builders for common payload encodings (BE per FUN_001c3b10)
function payloadBE(...u32s) {
  const buf = Buffer.alloc(u32s.length * 4);
  u32s.forEach((v, i) => buf.writeUInt32BE(v >>> 0, i * 4));
  return buf;
}
function payloadBE16(...u16s) {
  const buf = Buffer.alloc(u16s.length * 2);
  u16s.forEach((v, i) => buf.writeUInt16BE(v & 0xffff, i * 2));
  return buf;
}
function payloadStr(str, fixedLen) {
  const s = Buffer.from(str, 'latin1');
  if (fixedLen === undefined) return Buffer.concat([s, Buffer.from([0])]);
  const buf = Buffer.alloc(fixedLen, 0);
  s.copy(buf, 0, 0, Math.min(s.length, fixedLen));
  return buf;
}
function writeFixedLatin1(buf, offset, len, str) {
  const s = Buffer.from(str, 'latin1');
  s.copy(buf, offset, 0, Math.min(s.length, len - 1));
}

// === SN@P variable-length field encoder ======================================
// FUN_001c3b90 decoder spec â€” Codex analysis/tcp10127-fun-001c3b90-field-codec.md.
// Wire format per encoded field:
//   u16_be wire_len_plus_2     (= plain.length + 2)
//   u16_be checksum            (= (sum(plain) + p5*0x101) & 0x7fff)
//   encoded bytes[plain.length]
// Encoding: encoded[i] = plain[i] ^ key[i & 7] ^ ((salt + p5 + i) & 0xff)
// Key: ASCII "MINAMIOH" (decoded from base64 "TUlOQU1JT0g=" at 0x00248728).
// salt = EE TCP SN@P state+0x4c. Per Codex, start with salt=0; if 0x35ccd0
// gets populated but UI still d901s, the failure is salt/checksum and we'll
// need to sample state+0x4c live.
const SNAP_FIELD_KEY = Buffer.from('MINAMIOH', 'ascii');
function snapField(plain, maxLen, p5, salt = 0) {
  const buf = Buffer.isBuffer(plain) ? plain : Buffer.from(String(plain), 'latin1');
  if (buf.length > maxLen) throw new Error(`snapField: plain length ${buf.length} > maxLen ${maxLen}`);
  const encoded = Buffer.alloc(buf.length);
  let sum = 0;
  for (let i = 0; i < buf.length; i++) {
    const b = buf[i];
    sum += b;
    encoded[i] = b ^ SNAP_FIELD_KEY[i & 7] ^ ((salt + p5 + i) & 0xff);
  }
  const checksum = (sum + p5 * 0x101) & 0x7fff;
  const out = Buffer.alloc(4 + encoded.length);
  out.writeUInt16BE(buf.length + 2, 0);
  out.writeUInt16BE(checksum, 2);
  encoded.copy(out, 4);
  return out;
}

// === Hex helper ==============================================================
function hex(buf, maxBytes) {
  const slice = maxBytes ? buf.slice(0, maxBytes) : buf;
  const rows = [];
  for (let i = 0; i < slice.length; i += 16) {
    const chunk = slice.slice(i, i + 16);
    const hp = [...chunk].map(b => b.toString(16).padStart(2, '0')).join(' ').padEnd(47);
    const ap = [...chunk].map(b => (b >= 0x20 && b < 0x7f) ? String.fromCharCode(b) : '.').join('');
    rows.push(`  ${i.toString(16).padStart(4, '0')}  ${hp}  ${ap}`);
  }
  if (buf.length > (maxBytes || buf.length)) rows.push(`  ... (${buf.length - maxBytes} more bytes)`);
  return rows.join('\n');
}

// === Boot auth (this part already worked â€” leave alone) ======================
function bootPkt(b2, b3, b4) {
  return Buffer.from([0x00, 0x00, b2, b3, b4, 0x00, 0x00, 0x00]);
}
const BOOT_SEQUENCE = [
  bootPkt(0x02, 0x10, 0x01),
  bootPkt(0x02, 0x10, 0x02),
  bootPkt(0x02, 0x10, 0x04),
];

// === Per-connection state ====================================================
class Connection {
  constructor(socket, sessionId, isLobbyPhase, lobbyReason) {
    this.socket = socket;
    this.id = sessionId;
    this.isLobby = isLobbyPhase;
    this.reason = lobbyReason;
    this.t0 = Date.now();
    this.lastEvent = this.t0;
    this.seqIn = 0;
    this.seqOut = 0;
    this.totalBytes = 0;
    this.received = [];
    this.areaSelected = null;
    this.logFile = path.join(CAPTURES_DIR, `${RUN_ID}_snap_session${sessionId}_trace.log`);
    this.recvBuf = Buffer.alloc(0);
    // armedFrom: session_store's pendingOnlineState â€” used by 0x6110 handler to
    // branch between BOOT_AUTH login-seed reply and post-lobby SESSION_VERIFY
    // reply. Set from getPendingOnline() in the net.createServer factory.
    this.armedFrom = null;
    // Set true once the 0x1004 POST_LOBBY_ACK has been sent. Used at socket-close
    // to decide whether to re-arm for a session-verify second connection.
    this.sentPostLobbyAck = false;
  }
  log(line) {
    console.log(line);
    fs.appendFileSync(this.logFile, line + '\n');
  }
  dt() { return `+${String(Date.now() - this.t0).padStart(5)}ms`; }
  delta() { const d = Date.now() - this.lastEvent; this.lastEvent = Date.now(); return d; }

  sendPacket(p, label) {
    if (this.socket.destroyed) return;
    const buf = (p instanceof Packet) ? p.toBuffer() : p;
    this.seqOut++;
    // VERBATIM RAW-OUT first so the wire ordering is captured even if the
    // formatted log fails later. 2026-05-18: added for TCP 10127 lobby-phase RE.
    this.log(`[session ${this.id}] ${this.dt()}  RAW-OUT #${this.seqOut} ${buf.length}b ${buf.toString('hex')}`);
    this.socket.write(buf);
    const desc = (p instanceof Packet) ? p.toString() : `raw ${buf.length}B`;
    this.log(`[session ${this.id}] ${this.dt()}  Î”${String(this.delta()).padStart(5)}ms  OUT #${this.seqOut} (${buf.length}b)  ${buf.toString('hex')}${label ? '  ' + label : ''}`);
    this.log(hex(buf));
    this.log(`    decode: ${desc}`);
    saveCapture(`session${this.id}_out_${this.seqOut}`, buf);
  }
}

function saveCapture(tag, buf) {
  const ts = Date.now();
  const base = path.join(CAPTURES_DIR, `snap_${tag}_${ts}`);
  fs.writeFileSync(base + '.bin', buf);
  fs.writeFileSync(base + '.txt',
    `Tag  : ${tag}\nTime : ${new Date().toISOString()}\nBytes: ${buf.length}\n\n${hex(buf)}\n`);
}

// â”€â”€ PINE snapshot infrastructure for cmd 0x6504 diagnostics â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€
// Per Codex tcp10127-cmd6504.md "Request For Dynamic Snapshot": dump these
// four ranges pre/post the 0x6504 reply to prove whether the slot record
// reaches the record pool or exits through an earlier state branch.
const CMD6504_SNAPSHOT_DIR = path.join(ACTIVE_ROOT, '.codex', 'captures', 'cmd6504_snapshots');
if (!fs.existsSync(CMD6504_SNAPSHOT_DIR)) fs.mkdirSync(CMD6504_SNAPSHOT_DIR, { recursive: true });

const CMD6504_SNAPSHOT_ADDRESSES = [
  ['lobby state',         0x00365ac0, 0x120],  // state object â€” bytes near +0xc/+0xd/+0xdc/+0xe0
  ['slot/list globals',   0x00365e00, 0x280],  // uRam00365e0c..+0x1c, 0x365f78, pointer arrays
  ['slot owner map',      0x003619d0, 0x080],  // 64-entry u16 init=0xffff
  ['slot record pool',    0x0035ccd0, 0x280],  // detail records, stride 0x134
];

// 2026-06-01: default OFF — this opened a persistent PINE client on EVERY
// lobby session, blocking PINE-based test tools (pine_simulate_pressx.js,
// pine_check_25b78c.js, etc) with "timeout". Re-enable for targeted RE runs
// only via SNAP_LOBBY_DIAG=1.
const LOBBY_DIAG_ENABLED = process.env.SNAP_LOBBY_DIAG === '1';
const LOBBY_DIAG_DIR = path.join(ACTIVE_ROOT, '.codex', 'captures', 'lobby_diag');
if (!fs.existsSync(LOBBY_DIAG_DIR)) fs.mkdirSync(LOBBY_DIAG_DIR, { recursive: true });

// Keep the clean-walk path as default:
//   6501 mode=0 -> 6502 mode=1 -> 6504 -> 6510 -> 1004.
// Real-PS2 evidence showed full-header reaches 0x6503 but regresses to the
// server-busy/loading/D901 path. Hybrid leaves total_header_count at zero, so it
// can still show broken pagination, but it is the only path currently known to
// reach the clickable empty-lobby UI on real hardware. Keep full-header opt-in
// for targeted header-count tests.
const LOBBY_LIST_MODE = process.env.SNAP_LOBBY_LIST_MODE || 'hybrid';
// SNAP_LOBBY_SLOTS: number of server-select entries to publish through the
// 0x6501 mode=1 -> 0x6503 -> 0x6502 -> 0x6504 walk. The 0x6504 detail record
// (with HOST_IP) is written at (entry)*0x260+0x365f80; entry 0 -> 0x365f80,
// entry 1 -> 0x3661e0 (the capfix address). >=2 reproduces the join-capfix over
// the wire so server 2 gets a real connect descriptor instead of bed8=0/840.
// Decoded live in Ghidra 2026-06-14 from the SLES list-walk state machine
// (FUN_001c6e80/70b0/7680/7a70/8790). NOTE: this drives 0x6503 (the entry-count
// path), NOT 0x6510 (count=N in one chunk D901'd, 2026-06-13).
function lobbySlotCount() {
  return Math.max(1, Math.min(16, parseInt(process.env.SNAP_LOBBY_SLOTS || '1', 10)));
}
function useLegacyEmptyLobby() {
  return LOBBY_LIST_MODE === 'legacy-empty';
}
function useFullHeaderLobby() {
  // >=2 slots requires the 0x6503 header-count path to advance the walk past
  // entry 0, so imply full-header whenever multiple slots are requested.
  return LOBBY_LIST_MODE === 'full-header' || lobbySlotCount() >= 2;
}

// =====================================================================
// 2026-05-30: REVERTED — 0x6103/0x6104 chunks are SPRITE/IMAGE data,
//             NOT lobby-entry struct data.
// =====================================================================
// Confirmed via netwk.bin decompile line 71283: 0x365d34[i] is passed as
// an image pointer to FUN_005b7cd0 (sprite renderer) in the server-select
// screen render code (case 0x10/0x14). So the chunk buffer at
// 0x35ccc8 + 0x1000 + i*0x800 is the per-entry SPRITE/ICON, not the
// lobby-entry struct.
//
// The actual lobby-entry struct lives at *(u32*)(iRam0070d1c0+0x258 +
// i*0x14 + 0x10). That table is populated by FUN_0060e710 from a 105 KB
// buffer at iRam0070d1c0+0x1180, which is filled by FUN_00618230 — a
// state machine driven by SLES funcs 0x001f4xxx / 0x001f5xxx. Those are
// almost certainly disc-read calls (sceCd*) — the DEV9 trace shows
// matching DVD reads against NETBIO00.DAT (AFS entries #0 and #11)
// during press-X. So lobby entries come from disc, not from us.
//
// Reverting to the previous inert 24-byte record. We satisfy the parser
// shape (FUN_001c5f30 / FUN_001c6130) but ship nothing that pretends to
// be hostname/handle/mode data, because the game never reads them as
// struct fields.
const CHUNK_61_KEY    = 0x01234567;
const CHUNK_61_RECORD = Buffer.from('SLOT0001\0OPEN\0PAL Server\0', 'latin1');
// Length we declare in the 0x6103 manifest matches the buffer length.
const CHUNK_61_DECLARED_LENGTH = CHUNK_61_RECORD.length;
// Legacy "selector 0x39 / 0x2d" payloads — kept for the 0x6401 family that
// might be reached after a major-mode change.
const CHUNK_64_RECORD = Buffer.from('PAL Lobby\0OPEN\0SLOT0001\0', 'latin1');

// =====================================================================
// 2026-05-30: 0x6105 / 0x6320 status table — KEPT but inert.
// =====================================================================
// FUN_001c63c0 parser writes to 0x00365bb0/bb4/bd4/bf4. We can satisfy it
// with count=1 + code=1 + meta=0. Press-X success gate cRam0086f7e0
// stays at 0 by default (only the 0x27 event callback FUN_00626730 sets
// it), so populating the table is currently optional. Leaving handlers
// in place but with a minimal table to avoid surprises if a flow asks.
const STATUS_TABLE_ENTRIES = [[0x00000001, 0x00000000]];
const STATUS_TABLE_CHUNK   = Buffer.alloc(0x200, 0);

function clampChunkSlice(buf, offset, requested, hardMax) {
  const safeOffset = Number.isFinite(offset) ? Math.max(0, Math.min(offset, buf.length)) : 0;
  const safeRequested = Number.isFinite(requested) && requested > 0 ? requested : hardMax;
  const len = Math.max(0, Math.min(safeRequested, hardMax, buf.length - safeOffset));
  return { offset: safeOffset, data: buf.slice(safeOffset, safeOffset + len) };
}

function parseIndexOffsetSize(payload, defaultSize) {
  if (payload.length >= 8) {
    return {
      index: payload.readUInt16BE(0),
      offset: payload.readUInt32BE(2),
      size: payload.readUInt16BE(6) || defaultSize,
    };
  }
  if (payload.length >= 7) {
    return {
      index: payload[0],
      offset: payload.readUInt32BE(1),
      size: payload.readUInt16BE(5) || defaultSize,
    };
  }
  return { index: 0, offset: 0, size: defaultSize };
}

function parseKeyOffsetSize(payload, defaultSize) {
  if (payload.length >= 10) {
    return {
      key: payload.readUInt32BE(0),
      offset: payload.readUInt32BE(4),
      size: payload.readUInt16BE(8) || defaultSize,
    };
  }
  return { key: CHUNK_61_KEY, offset: 0, size: defaultSize };
}

const LOBBY_DIAG_FIELDS = [
  ['snap_state',          0x0036d7e0, 1],
  ['lobby_major',         0x00365acc, 1],
  ['lobby_substate',      0x00365acd, 1],
  ['lobby_terminal',      0x00365b9c, 4],
  ['slot_u32_b',          0x00365e00, 4],
  ['slot_u32_a',          0x00365e04, 4],
  ['lobby_slot_u32_a',    0x00365e08, 4],
  ['current_entry_idx',   0x00365e0c, 4],
  ['slot_chunk_idx',      0x00365e10, 4],
  ['pool_owner_cursor',   0x00365e12, 2],
  ['page_accumulator',    0x00365e18, 2],
  ['expected_batch',      0x00365e1a, 2],
  ['last_batch_count',    0x00365e1c, 1],
  ['header_count',        0x00365e1e, 2],
  ['entry_slot_count',    0x00365f78, 4],
  ['lobby_slot_u32_b',    0x00365f7c, 4],
  ['slot_ptr0_le',        0x00365f80, 4],
  ['owner_map_0_3',       0x003619d0, 8],
  ['slot_pool_record0',   0x0035ccd0, 0x80],
  ['slot_pool_trailing',  0x0035cdf8, 0x0c],
  ['room_count',          0x006c555e, 2],
  ['room_records',        0x006c5562, 0x80],
  ['ntgui_counter',       0x007152e1, 1],
];

let pineConn = null;
async function getPine() {
  if (pineConn) return pineConn;
  const c = new PineClient({ port: 28011, timeoutMs: 750 });
  await c.connect();
  pineConn = c;
  return c;
}

function snapHexLines(buf, baseAddr) {
  const lines = [];
  for (let i = 0; i < buf.length; i += 16) {
    const chunk = buf.slice(i, i + 16);
    const hp = [...chunk].map(b => b.toString(16).padStart(2, '0')).join(' ').padEnd(47);
    const ap = [...chunk].map(b => (b >= 0x20 && b < 0x7f) ? String.fromCharCode(b) : '.').join('');
    lines.push(`  0x${(baseAddr + i).toString(16).padStart(8, '0')}  ${hp}  ${ap}`);
  }
  return lines;
}

async function runCmd6504Snapshot(sessionFile, label, t0) {
  // DISABLED 2026-05-24 — these snapshots fired on every 0x6504 (3-4 times
  // per session) and contributed to PCSX2 PINE wedge / D901 / crashes. Use
  // tools/mem_watcher.js for passive memory diagnostics instead. To re-enable
  // for targeted tests, set env var SNAP_CMD6504_SNAPSHOTS=1.
  if (process.env.SNAP_CMD6504_SNAPSHOTS !== '1') return;
  const dt = t0 ? `[+${(Date.now() - t0).toString().padStart(5)}ms]` : '[       ]';
  const out = [`\n${dt} ${label}  ${new Date().toISOString()}`];
  try {
    const pine = await getPine();
    for (const [name, addr, len] of CMD6504_SNAPSHOT_ADDRESSES) {
      out.push(`[${name}] 0x${addr.toString(16).padStart(8, '0')} (${len}b):`);
      try {
        const buf = await pine.readBytes(addr, len);
        out.push(...snapHexLines(buf, addr));
      } catch (e) {
        out.push(`  read FAIL: ${e.message}`);
        try { pineConn?.close(); } catch {}
        pineConn = null;
      }
    }
  } catch (e) {
    out.push(`  PINE FAIL: ${e.message}`);
    try { pineConn?.close(); } catch {}
    pineConn = null;
  }
  fs.appendFileSync(sessionFile, out.join('\n') + '\n');
}

let cmd6504SnapshotQueue = Promise.resolve();
function enqueueCmd6504Snapshot(sessionFile, label, t0) {
  cmd6504SnapshotQueue = cmd6504SnapshotQueue
    .then(() => runCmd6504Snapshot(sessionFile, label, t0))
    .catch((e) => {
      fs.appendFileSync(sessionFile, `\n[SNAPSHOT QUEUE FAIL] ${label}: ${e.message}\n`);
    });
}

function makeLobbyDiagFile(conn) {
  if (!LOBBY_DIAG_ENABLED) return null;
  if (!conn.lobbyDiagFile) {
    const ts = Date.now();
    conn.lobbyDiagFile = path.join(LOBBY_DIAG_DIR, `lobby_diag_session${conn.id}_${ts}.jsonl`);
    fs.appendFileSync(conn.lobbyDiagFile, JSON.stringify({
      event: 'start',
      session: conn.id,
      iso: new Date(ts).toISOString(),
      reason: conn.reason,
      armedFrom: conn.armedFrom || null,
      trace: conn.logFile,
      fields: LOBBY_DIAG_FIELDS.map(([name, addr, len]) => ({ name, addr: `0x${addr.toString(16)}`, len })),
    }) + '\n');
    conn.log(`[session ${conn.id}] lobby diag: ${conn.lobbyDiagFile}`);
  }
  return conn.lobbyDiagFile;
}

async function captureLobbyDiag(conn, label, p = null) {
  const file = makeLobbyDiagFile(conn);
  if (!file) return;
  const entry = {
    event: 'sample',
    session: conn.id,
    ms: Date.now() - conn.t0,
    iso: new Date().toISOString(),
    label,
    cmd: p ? `0x${p.cmd.toString(16).padStart(4, '0')}` : null,
    p5: p ? `0x${p.p5.toString(16).padStart(2, '0')}` : null,
    payloadLen: p ? p.payload.length : null,
    payloadHex: p ? p.payload.toString('hex') : null,
    fields: {},
  };
  try {
    const pine = await getPine();
    for (const [name, addr, len] of LOBBY_DIAG_FIELDS) {
      try {
        const buf = await pine.readBytes(addr, len);
        entry.fields[name] = buf.toString('hex');
      } catch (e) {
        entry.fields[name] = { error: e.message };
        try { pineConn?.close(); } catch {}
        pineConn = null;
      }
    }
  } catch (e) {
    entry.pineError = e.message;
    try { pineConn?.close(); } catch {}
    pineConn = null;
  }
  fs.appendFileSync(file, JSON.stringify(entry) + '\n');
}

// === Lobby-entry table dump (PINE) ==========================================
// Per ChatGPT 2026-06-03 reframe: cmd 0x6510 populates a 64-entry table at
// 0x365F78, 608 bytes per entry. Our reply only fills ~10% of one entry.
// To find which OTHER opcode (or stage) fills the rest, dump entry 0 at the
// natural breakpoints and diff.
//
// Output: captures/lobby_entries/auto_entry0.log
// Each dump labeled with the trigger (e.g., "post-6504", "post-6510",
// "post-1004", "post-resume").
// 2026-06-03: TABLE starts at 0x365E20 per ee_lobby_handlers.txt:282
// (FUN_001c70b0 writes snapField #1 to (slot * 0x260) + 0x365e20). Previous
// value 0x365F78 was entry+0x158 (= status u16 read by 6510), not the entry
// start — so all dumps were of the late portion of each entry. Field map:
//   entry+0x000  62B snapField  (set by 6503)
//   entry+0x03F  15B snapField  (set by 6503)
//   entry+0x04F  8 raw bytes   (set by 6503)
//   entry+0x057  255B snapField (set by 6503)
//   entry+0x158  u16 status     (read by 6510)
//   entry+0x160  u32 ptr → 0x6504 detail block
const LOBBY_ENTRY_TABLE = 0x00365E20;
const LOBBY_ENTRY_SIZE = 0x260;
const LOBBY_ENTRY_DUMP_FILE = path.join(ACTIVE_ROOT, 'captures', 'lobby_entries', 'auto_entry0.log');
if (!fs.existsSync(path.dirname(LOBBY_ENTRY_DUMP_FILE))) fs.mkdirSync(path.dirname(LOBBY_ENTRY_DUMP_FILE), { recursive: true });

let lobbyEntryDumpQueue = Promise.resolve();
function dumpLobbyEntry(label, entryIdx = 0) {
  if (process.env.SNAP_LOBBY_ENTRY_DUMP === '0') return;
  const addr = LOBBY_ENTRY_TABLE + entryIdx * LOBBY_ENTRY_SIZE;
  lobbyEntryDumpQueue = lobbyEntryDumpQueue.then(async () => {
    try {
      const pine = await getPine();
      const buf = await pine.readBytes(addr, LOBBY_ENTRY_SIZE);
      const lines = [
        '',
        '=========================================================================',
        `LABEL: ${label}`,
        `TIME:  ${new Date().toISOString()}`,
        `ENTRY: ${entryIdx}  ADDR: 0x${addr.toString(16)}`,
        '=========================================================================',
      ];
      function hexLine(slice, base, i) {
        const hex = Array.from(slice).map(b => b.toString(16).padStart(2,'0')).join(' ').padEnd(47);
        const ascii = slice.toString('latin1').replace(/[^\x20-\x7e]/g, '.');
        return `  0x${(base + i).toString(16).padStart(8,'0')}  ${hex}  ${ascii}`;
      }
      for (let i = 0; i < buf.length; i += 16) {
        lines.push(hexLine(buf.slice(i, i + 16), addr, i));
      }
      // Follow the pointer at entry+0x08 (observed in earlier dumps as 0x0035CCD0).
      // If sane EE-RAM addr, dump 256 bytes there to see the real entry data.
      if (buf.length >= 12) {
        const ptr = buf.readUInt32LE(8);
        if (ptr >= 0x00100000 && ptr < 0x02000000) {
          try {
            const sub = await pine.readBytes(ptr, 0x100);
            lines.push(`  --- DEREF entry+0x08 → 0x${ptr.toString(16)} (256B) ---`);
            for (let i = 0; i < sub.length; i += 16) {
              lines.push(hexLine(sub.slice(i, i + 16), ptr, i));
            }
          } catch (e) {
            lines.push(`  --- DEREF FAIL: ${e.message}`);
          }
        } else {
          lines.push(`  --- entry+0x08 = 0x${ptr.toString(16)} (not a valid EE-RAM ptr; skip deref)`);
        }
      }
      fs.appendFileSync(LOBBY_ENTRY_DUMP_FILE, lines.join('\n') + '\n');
    } catch (e) {
      fs.appendFileSync(LOBBY_ENTRY_DUMP_FILE, `\n[${new Date().toISOString()}] ${label}: PINE FAIL: ${e.message}\n`);
      try { pineConn?.close(); } catch {}
      pineConn = null;
    }
  });
}

let lobbyDiagQueue = Promise.resolve();
function enqueueLobbyDiag(conn, label, p = null, delayMs = 0) {
  if (!LOBBY_DIAG_ENABLED || !conn.isLobby) return;
  const run = () => {
    lobbyDiagQueue = lobbyDiagQueue
      .then(() => captureLobbyDiag(conn, label, p))
      .catch(e => {
        const file = makeLobbyDiagFile(conn);
        if (file) fs.appendFileSync(file, JSON.stringify({
          event: 'diag_error',
          session: conn.id,
          ms: Date.now() - conn.t0,
          iso: new Date().toISOString(),
          label,
          error: e.message,
        }) + '\n');
      });
  };
  if (delayMs > 0) setTimeout(run, delayMs);
  else run();
}

// === Packet dispatcher (Bio-Serv style) =====================================
// Each handler receives (conn, incomingPacket). It can send 0 or more responses.
//
// Bio-Serv uses cmd-keyed dispatch from CLIENT/QUERY packets. PAL game uses
// direction byte = 0x01 for client-ask. We dispatch on cmd alone for now.

// LOGIN payload (decompiled from FUN_001c5a20 @ ee_lobby_handlers.txt:782):
//   payload[0]      = sub_cmd byte (FUN_001c3a60). MUST be 0x01 to take the
//                     auth path. 0x00 â†’ returns 0xFFFFFFC2 error â†’ game FINs.
//   payload[1..4]   = u32 BE token       â†’ state[0x2a]
//   payload[5..5+N] = N hash bytes (N = state[0x29], zero-init = 0)
//   payload[5+N..]  = u32 BE "final"     â†’ state[0x2c]. 0 â†’ state 0x19 (success).
function buildLoginSeedPayload() {
  // 1 byte sub_cmd + u32 BE token + 0 hash bytes + u32 BE final
  const buf = Buffer.alloc(9);
  buf[0] = 0x01;                  // sub_cmd = "auth"
  buf.writeUInt32BE(0, 1);        // token (state[0x29]=0 so any value works)
  buf.writeUInt32BE(0, 5);        // final = 0 â†’ game takes "state 0x19" branch
  return buf;
}

const HANDLERS = {
  // 0x6001 CONNCHECK â€” server-side keepalive; ACK with err=0
  [CMD.CONNCHECK]: (conn, p) => {
    conn.log(`[session ${conn.id}]     CONNCHECK from game`);
    conn.sendPacket(new Packet(null, {
      dir: DIR_SERVER_TELL, cmd: CMD.CONNCHECK, p5: p.p5, err: 0, p7: p.p7
    }), 'â†’ CONNCHECK ACK');
  },

  // 0x6110 SESSION_VERIFY (client â†’ server query)
  // Two phases produce this command:
  //   1. BOOT_AUTH path: game's FUN_001c92d0 handles our 10 60 01 CONNCHECK and
  //      queries us via 01 61 10 for a login seed. We reply 02 61 01 LOGIN seed.
  //   2. Post-lobby resume (Codex analysis/tcp10127-second-connection-session-verify.md):
  //      after a clean lobby walk + 0x1004 ACK + FIN, the game opens a second
  //      TCP 10127 connection and sends 01 61 10 expecting a 02 61 10
  //      SESSION_VERIFY reply at FUN_001c6840. Different cmd, different payload.
  //
  // We branch on conn.armedFrom which is set from session_store's
  // pendingOnlineState at session-open time.
  [CMD.SESSION_VERIFY]: (conn, p) => {
    conn.log(`[session ${conn.id}]     >> session-verify (${p.toString()})  armedFrom=${conn.armedFrom || '(boot)'}`);

    if (conn.armedFrom === 'post-lobby-resume') {
      // 02 61 10 reply per Codex spec â€” FUN_001c6840 reads:
      //   u16_be (port_or_timeout; 0 preserves init default of 100)
      //   snapField(maxLen=0xff) (empty preserves init URL "http://stage6.sega.com/mhweb/...")
      //   snapField(maxLen=0xff) (empty preserves init SNAP host "snap01.capcom.client.sf.yav4.com")
      // Empty fields advance state+0xd = 0x25 without disturbing client-side defaults.
      const SALT = 0;
      const payload = Buffer.concat([
        Buffer.from([0x00, 0x00]),                          // u16 BE = 0
        snapField(Buffer.alloc(0), 0xff, p.p5, SALT),       // empty URL field
        snapField(Buffer.alloc(0), 0xff, p.p5, SALT),       // empty host field
      ]);
      conn.sendPacket(new Packet(null, {
        dir: DIR_SERVER_TELL, cmd: CMD.SESSION_VERIFY, p5: p.p5, err: 0, p7: p.p7,
        payload,
      }), `â†’ SESSION_VERIFY (02 61 10) u16=0 + 2Ã—empty snapField (preserves defaults), payload ${payload.length}b`);
      return;
    }

    // BOOT_AUTH path (original behavior)
    conn.log(`[session ${conn.id}]     SEND LOGIN_SEED_V2 (17-byte frame, payload-len=9, err=0, sub_cmd=1)`);
    conn.sendPacket(new Packet(null, {
      dir: DIR_SERVER_TELL, cmd: CMD.LOGIN,
      p5: 0, err: 0, p7: 0,           // err=0 critical â€” game error-aborts on 0xFF
      payload: buildLoginSeedPayload()
    }), 'â†’ LOGIN seed (sub_cmd=1, token=0, hash_len=0, final=0)');

    // Auto-inspect: scan PCSX2 EE RAM for the per-conn state struct to read
    // state[0x29] (hash length) and state[0x28] (expected hash buffer). Runs
    // in parallel so we don't delay the LOGIN seed. Signature = the CONNCHECK
    // challenge bytes we sent earlier (still in state[0x30] buffer until the
    // game processes our LOGIN seed and overwrites it).
    if (autoInspect) {
      const challengeSig = Buffer.from([0x00, 0x00, 0x10, 0x60, 0x01, 0x01, 0x00, 0x00]);
      const loginSeedSig = Buffer.from([0x00, 0x09, 0x02, 0x61, 0x01, 0x00, 0x00, 0x00]);
      const logFn = (line) => conn.log(`[session ${conn.id}]   ${line}`);

      // Try both signatures so we catch the struct regardless of timing.
      Promise.all([
        autoInspect({ signature: challengeSig, log: logFn }).then(r => ({ sig: 'CONNCHECK', r })),
        autoInspect({ signature: loginSeedSig, log: logFn }).then(r => ({ sig: 'LOGIN_SEED', r })),
      ]).then(results => {
        for (const { sig, r } of results) {
          if (r.ok && r.candidates.length > 0) {
            conn.log(`[session ${conn.id}]   [auto-inspect] === ${sig} signature found ===`);
            formatAutoReport(r, logFn);
          } else if (!r.ok) {
            conn.log(`[session ${conn.id}]   [auto-inspect] ${sig}: ${r.err}`);
          }
        }
      }).catch(e => conn.log(`[session ${conn.id}]   [auto-inspect] threw: ${e.message}`));
    }
  },

  // 0x6101 LOGIN â€” if game ever queries us back, ACK
  [CMD.LOGIN]: (conn, p) => {
    conn.log(`[session ${conn.id}]     LOGIN from game`);
    conn.sendPacket(new Packet(null, {
      dir: DIR_SERVER_TELL, cmd: CMD.LOGIN, p5: 0, err: 0, p7: 0,
      payload: buildLoginSeedPayload()
    }), 'â†’ LOGIN OK');
  },

  // 0x6103 CHUNK_LIST_61 — chunk-list-with-key MANIFEST reply.
  // 2026-05-28: previously mislabeled as CHECKVERSION. Dispatch table dump
  // (analysis/claude-dispatch-table-2026-05-26.txt) confirms table idx 0x2e
  // (dir=02 cmd=0x6103) routes to FUN_001c5f30, the chunk-list-with-key
  // manifest parser. Reply parser shape:
  //   u16_be count (max 8; clamped)
  //   per entry: u32_be key, u32_be total_length
  // Side effects: writes 0x00365cf0 (count), 0x00365d34[i] (= 0x35ccc8 +
  // 0x1000 + i*0x800 chunk buffer base), 0x00365d74[i] (key),
  // 0x00365cf4[i] (length). On count==0 → state+0xd = 2; on count>0 →
  // state+0xd = 0x2b (chunk-fetch loop).
  //
  // Our previous 4-byte zero reply parsed as count=0 → "no chunks" path. The
  // game still advanced to 0x6212 etc, but 0x365cf0 stayed at 0, making the
  // runtime navigator wrap i8 ±128 against `0x365cf0 - 1 = 0xff = -1` (the
  // user-visible "-128 to 128 servers" bug on real PS2).
  //
  // The new reply sends count=1 + key + length, so the game enters the
  // chunk-fetch loop and ultimately populates 0x365d34[0] with our data.
  [CMD.CHUNK_LIST_61]: (conn, p) => {
    conn.log(`[session ${conn.id}]     CHUNK_LIST_61 (sprite manifest) p5=0x${p.p5.toString(16)} p7=0x${p.p7.toString(16)} payload=${p.payload.length}b`);
    // 2026-05-30: chunks are sprites (per FUN_005b7cd0 image-render call in
    // netwk.bin). Ship the minimal 24-byte record — the parser only needs
    // count + (key, length) per entry to set up 0x365cf0 etc. The actual
    // contents don't drive the lobby endpoint; that comes from disc.
    const payload = Buffer.concat([
      payloadBE16(1),                                          // count = 1
      payloadBE(CHUNK_61_KEY, CHUNK_61_DECLARED_LENGTH),       // u32 key + u32 length
    ]);
    conn.sendPacket(new Packet(null, {
      dir: DIR_SERVER_TELL, cmd: CMD.CHUNK_LIST_61, p5: p.p5, err: 0, p7: p.p7,
      payload,
    }), `→ CHUNK_LIST_61 count=1 key=0x${CHUNK_61_KEY.toString(16)} length=${CHUNK_61_DECLARED_LENGTH} (inert; populates 0x00365cf0)`);
  },

  // 0x6203 AREACOUNT â€” PAL version (overriding pre-PAL Bio-Serv handler).
  // Per Codex `analysis/tcp10127-cmd6203-areacount.md`: PAL handler FUN_001c4960
  // reads a one-byte MODE, not a raw count.
  //  0x00 = error/reset path (what the old Bio-Serv reply was inadvertently
  //         sending â€” reply payload[0] = high byte of areacount BE u32 = 0,
  //         which the EE read as mode=0 â†’ error â†’ instant FIN, "Go Online" UI).
  //  0x02 = minimal success â†’ lobby state 0x14, no more payload reads.
  //  0x01 = larger area-list/cache branch (would let us populate AREAS, but
  //         requires more payload bytes; skip until needed).
  // Mirror p5/p7 (Codex confirmed: client-requested PAL SERVER_TELL replies
  // mirror p5/p7 unless a handler proves otherwise).
  [CMD.AREACOUNT]: (conn, p) => {
    // 2026-05-19: mode=0x01 (PALAREA01 tag, count=1, size=0) regressed UI to
    // 9% â€” game FIN'd at +74ms WITHOUT proceeding to LEAVEAGL/AGLSTATS/etc.
    // Mode=0x01 with the spec'd shape is worse than mode=0x02 (which at least
    // reaches 16% via the full lobby chain). Reverting to mode=0x02 baseline
    // until Codex refines the mode=0x01 spec.
    conn.log(`[session ${conn.id}]     AREACOUNT (PAL mode-byte) p5=0x${p.p5.toString(16)} p7=0x${p.p7.toString(16)} payload=${p.payload.length}b`);
    if (AREA_LIST_ENABLED) {
      // mode=0x01 area-list branch (FUN_001c4960). PROVEN format:
      //   [u8 0x01][snapField tag, maxLen 0x1f][u16 count BE][count x u32 size BE]
      // tag is snapField-ENCODED (FUN_001c3b90) — the old raw-tag attempt failed here.
      // count=1 (one area buffer = the 10-box grid); size = blob length (<=0x2000).
      conn.areaCursor = 0;  // reset chunk cursor for the upcoming 0x6204 walk
      const SALT = 0;
      const payload = Buffer.concat([
        Buffer.from([0x01]),
        snapField(AREA_TAG, 0x1f, p.p5, SALT),
        payloadBE16(1),                  // u16 count = 1
        payloadBE(AREA_BLOB_SIZE),       // u32 area[0] size
      ]);
      conn.sendPacket(new Packet(null, {
        dir: DIR_SERVER_TELL, cmd: CMD.AREACOUNT, p5: p.p5, err: 0, p7: p.p7,
        payload,
      }), `â†’ AREACOUNT mode=0x01 area-list tag="${AREA_TAG}" count=1 size=0x${AREA_BLOB_SIZE.toString(16)} (-> state 0x12, expect 0x6204 requests)`);
      return;
    }
    conn.sendPacket(new Packet(null, {
      dir: DIR_SERVER_TELL, cmd: CMD.AREACOUNT, p5: p.p5, err: 0, p7: p.p7,
      payload: Buffer.from([0x02]),
    }), 'â†’ AREACOUNT mode=0x02 (minimal success; mode=0x01 spec regressed to 9%, reverted)');
  },

  // 0x6204 AREANAME â€” Bio-Serv reply with 32-byte fixed name string.
  // Restored after the mode=0x01 detour. Mirroring p5 from request.
  [CMD.AREANAME]: (conn, p) => {
    if (AREA_LIST_ENABLED) {
      // 0x6204 area-data chunk (EE FUN_001c4d40). Reply:
      //   [u16 area_index BE][u32 offset BE][snapField blob chunk]
      // EE validates idx==0x368421 (==0, count=1) and offset==0x368424 (sequential).
      // Chunk stride 0x2f2; last chunk = remaining bytes. We track conn.areaCursor.
      if (conn.areaCursor === undefined) conn.areaCursor = 0;
      const offset = conn.areaCursor;
      if (offset >= AREA_BLOB_SIZE) {
        conn.log(`[session ${conn.id}]     0x6204 past end offset=0x${offset.toString(16)} — ignored`);
        return;
      }
      const blob = buildAreaBlob();
      const chunkLen = Math.min(AREA_CHUNK, AREA_BLOB_SIZE - offset);
      const chunk = blob.slice(offset, offset + chunkLen);
      const SALT = 0;
      const payload = Buffer.concat([
        payloadBE16(0),                       // u16 area_index = 0
        payloadBE(offset),                    // u32 offset
        snapField(chunk, chunkLen, p.p5, SALT),
      ]);
      conn.log(`[session ${conn.id}]     0x6204 chunk idx=0 offset=0x${offset.toString(16)} len=0x${chunkLen.toString(16)} (query p5=0x${p.p5.toString(16)} qpayload=${p.payload.length}b ${p.payload.slice(0, 8).toString('hex')})`);
      conn.sendPacket(new Packet(null, {
        dir: DIR_SERVER_TELL, cmd: CMD.AREANAME, p5: p.p5, err: 0, p7: p.p7,
        payload,
      }), `â†’ area chunk offset=0x${offset.toString(16)} len=0x${chunkLen.toString(16)}`);
      conn.areaCursor = offset + AREA_CHUNK;
      return;
    }
    const idx = p.p5;
    const a = AREAS[idx];
    conn.log(`[session ${conn.id}]     AREANAME[${idx}]`);
    if (!a) return;
    conn.sendPacket(new Packet(null, {
      dir: DIR_SERVER_TELL, cmd: CMD.AREANAME, p5: idx, err: 0, p7: 0,
      payload: payloadStr(a.name, 32),
    }), `â†’ area[${idx}].name="${a.name}"`);
  },

  // 0x6205 AREAPLAYERCNT â€” game asks for area[N].playerCount
  [CMD.AREAPLAYERCNT]: (conn, p) => {
    const idx = p.p5;
    const a = AREAS[idx];
    conn.log(`[session ${conn.id}]     AREAPLAYERCNT[${idx}]`);
    if (!a) return;
    const playerCount = areaPlayerCountForWire(a.playerCount);
    conn.sendPacket(new Packet(null, {
      dir: DIR_SERVER_TELL, cmd: CMD.AREAPLAYERCNT, p5: idx, err: 0, p7: 0,
      payload: payloadBE(playerCount),
    }), `â†’ area[${idx}].players = ${playerCount}`);
  },

  // 0x6206 AREASTATUS â€” game asks for area[N].status (0=open, 3=locked)
  [CMD.AREASTATUS]: (conn, p) => {
    const idx = p.p5;
    const a = AREAS[idx];
    conn.log(`[session ${conn.id}]     AREASTATUS[${idx}]`);
    if (!a) return;
    conn.sendPacket(new Packet(null, {
      dir: DIR_SERVER_TELL, cmd: CMD.AREASTATUS, p5: idx, err: 0, p7: 0,
      payload: payloadBE(a.status),
    }), `â†’ area[${idx}].status = ${a.status}`);
  },

  // 0x1007 LOBBY_INIT â€” PAL TCP-10127 initial lobby/version/config exchange.
  // 2026-05-25 (Codex overnight gate-writer analysis): FUN_001c9030 is THE writer
  // of 0x00365dcc, the NTGUI data gate the lobby renderer waits on. Per
  // analysis/state-gate-writers-0x365dcc-0x365df8-2026-05-25.md, the C path is:
  //   mode = read_u8(packet);
  //   if (mode == 1) {
  //     detail = read_u8(packet);                     -> 0x00365dc4
  //     snapField(packet, *0x35CCC8,        0x13);    -> small buffer
  //     *0x365dc8 = *0x35CCC8;
  //     snapField(packet, *0x35CCC8 + 0x14, 0xfeb);   -> big buffer (max 4075b)
  //     *0x365dcc = *0x35CCC8 + 0x14;                 -> ★ GATE POPULATED
  //   }
  //   state->sub = 0x29;
  // Downstream NTGUI state-2 consumer at 0x00627040 then memcpys the big buffer
  // (0xfec bytes) into 0x0087f864 only if 0x365dcc is nonzero. It then
  // increments 0x007152e1 and sets 0x007152d0=1 even if the gate is still zero.
  // That means a malformed/empty mode=1 experiment can look "ready" while the
  // UI has no valid lobby buffer, which matches the newer straight connection
  // error regression.
  //
  // Mode 0 (single byte 0x00) was our prior reply â€” it took the "minimal success"
  // branch, set state.sub = 0x29 without populating the gate. NTGUI state-2 then
  // had nothing to memcpy, stayed stuck waiting for the gate, timed out into
  // D901 / 840 on real PS2 / PCSX2.
  //
  // Default = mode 1 (gate-populate path). Set SNAP_LOBBY_INIT_MODE=0 to revert
  // to the legacy single-byte reply.
  // SNAP_LOBBY_INIT_CURSOR_PAD defaults OFF (cursor=0 confirmed via FUN_001c3880);
  // set =1 only to re-test the falsified cursor=1 hypothesis.
  [CMD.LOBBY_INIT]: (conn, p) => {
    conn.log(`[session ${conn.id}]     LOBBY_INIT (cmd 0x1007) p5=0x${p.p5.toString(16)} p7=0x${p.p7.toString(16)}`);
    const mode = process.env.SNAP_LOBBY_INIT_MODE === '0' ? 0 : 1;
    if (mode === 0) {
      conn.sendPacket(new Packet(null, {
        dir: DIR_SERVER_TELL, cmd: CMD.LOBBY_INIT, p5: p.p5, err: 0, p7: p.p7,
        payload: Buffer.from([0x00]),
      }), 'â†’ lobby-init minimal success (payload[0]=0x00 â†’ state 0x29, gate NOT populated)');
      return;
    }
    // Mode=1: populate the 0x365dcc data gate.
    // Minimum-viable: detail=0, then two snapFields with minimal content. Both
    // get memcpy'd into pre-allocated scratch buffers; the second one ultimately
    // memcpys into the 0x0087f864 lobby-data buffer the renderer reads.
    const SALT = 0;
    const smallField = snapField(Buffer.alloc(0x10, 0x00), 0x13, p.p5, SALT);  // 16-byte zero buffer
    // 2026-05-30 EXPERIMENT: 16 × 16-byte ASCII names. Prior all-zero buffer
    // produced disc_table_count=0x10 (PINE confirmed) but all entries filtered
    // out by self-filter (0x874fc0). If "LOBBYxx" appears in renderer records
    // at 0x694700, we've found the per-entry name offset. If UI still empty,
    // entry layout is more than 16b/slot (likely 32 or 56).
    const bigBuf = Buffer.alloc(0x100, 0x00);
    for (let i = 0; i < 16; i++) {
      const name = `LOBBY${(i + 1).toString().padStart(2, '0')}`;
      bigBuf.write(name, i * 16, 'ascii');
    }
    const bigField   = snapField(bigBuf, 0xfeb, p.p5, SALT);
    // 2026-05-30: cursor=1 hypothesis FALSIFIED. Raw disasm of FUN_001c3880
    // (SN@P TCP frame parser) confirms state[0x40] (cursor) is reset to 0
    // every time a message arrives — see claude-0x1007-cursor-pad-bug-2026-05-30.md.
    // Default is now OFF. SNAP_LOBBY_INIT_CURSOR_PAD=1 re-enables for A/B.
    const cursorPad = process.env.SNAP_LOBBY_INIT_CURSOR_PAD === '1' ? Buffer.from([0x00]) : Buffer.alloc(0);
    const payload = Buffer.concat([cursorPad, Buffer.from([0x01, 0x00]), smallField, bigField]);
    conn.log(`[session ${conn.id}]     0x1007 mode=1 snapField-encoded: pad(${cursorPad.length}b)+small(${smallField.length}b)+big(${bigField.length}b) = payload ${payload.length}b (salt=${SALT})`);
    conn.sendPacket(new Packet(null, {
      dir: DIR_SERVER_TELL, cmd: CMD.LOBBY_INIT, p5: p.p5, err: 0, p7: p.p7,
      payload,
    }), `â†’ lobby-init mode=1 cursor-pad=${cursorPad.length} (populates 0x365dcc gate; small=${smallField.length}b big=${bigField.length}b)`);
  },

  // 0x6211 â€” Bio-Serv name LEAVEAGL but PAL reuses in the boot-lobby
  // progression (Codex analysis/tcp10127-cmd6211.md). PAL handler FUN_001c45f0
  // reads one BE u32 from the reply; the value is stored at uRam0036847c but
  // not branched on locally. Codex recommends payload = 0 as the lowest-risk
  // first value. Mirror p5/p7. The post-state transition depends on the major
  // mode at *state (most likely â†’ state+0xd = 0x0e for the "go online" path).
  [CMD.LEAVEAGL]: (conn, p) => {
    conn.log(`[session ${conn.id}]     cmd 0x6211 (PAL, Bio-Serv name LEAVEAGL) p5=0x${p.p5.toString(16)} p7=0x${p.p7.toString(16)}`);
    conn.sendPacket(new Packet(null, {
      dir: DIR_SERVER_TELL, cmd: CMD.LEAVEAGL, p5: p.p5, err: 0, p7: p.p7,
      payload: payloadBE(0),
    }), 'â†’ cmd 0x6211 reply (BE u32 = 0; advances lobby state per *state major mode)');
  },

  // 0x6212 AGLPLAYERCNT â€” aftergame-lobby player count.
  // Per Codex `analysis/tcp10127-cmd6212.md`: EE handler FUN_001c4360 expects
  // a single BE u32 payload (player count) and advances lobby state to 0x10.
  // Mirror p5/p7, err=0. Player count of 1 represents the logged-in user.
  [CMD.AGLPLAYERCNT]: (conn, p) => {
    conn.log(`[session ${conn.id}]     AGLPLAYERCNT (cmd 0x6212) p5=0x${p.p5.toString(16)} p7=0x${p.p7.toString(16)}`);
    conn.sendPacket(new Packet(null, {
      dir: DIR_SERVER_TELL, cmd: CMD.AGLPLAYERCNT, p5: p.p5, err: 0, p7: p.p7,
      payload: payloadBE(1),
    }), 'â†’ AGL player count = 1 (advances lobby state to 0x10)');
  },

  // 0x6213 AGLSTATS â€” aftergame-lobby stats. Per Codex: PAL expects 8 BE u16
  // values. Default to all-zero "no stats" â€” refine once we see what the EE
  // handler does with each slot. Pre-staged to save a round-trip; if the game
  // sends this, we have a reply ready.
  [CMD.AGLSTATS]: (conn, p) => {
    conn.log(`[session ${conn.id}]     AGLSTATS (cmd 0x6213) p5=0x${p.p5.toString(16)} p7=0x${p.p7.toString(16)}`);
    conn.sendPacket(new Packet(null, {
      dir: DIR_SERVER_TELL, cmd: CMD.AGLSTATS, p5: p.p5, err: 0, p7: p.p7,
      payload: payloadBE16(0, 0, 0, 0, 0, 0, 0, 0),
    }), 'â†’ AGL stats = 8x u16 zeros (no-stats placeholder; refine after live test)');
  },

  // 0x6501 LOBBY_HEADER â€” PAL "lobby header" per Ghidra export label.
  // Handler FUN_001c6e80 (Codex analysis/tcp10127-cmd6501.md). Bio-Serv calls
  // it CANCELSLOT but live PAL reaches it during initial lobby population, so
  // the Bio-Serv name doesn't apply semantically.
  // Mode 0x00 = smallest non-error empty/no-entry path (first try).
  // Mode 0x01 + two zero u32s = larger entry-present path (fallback if mode 0
  // advances but ends the lobby too early):
  //   payload: Buffer.from([0x01, 0,0,0,0, 0,0,0,0])  // 9 bytes
  [CMD.LOBBY_HEADER]: (conn, p) => {
    // 2026-05-25 reframe (real-PS2 evidence): mode=0x00 leaves uRam00365e1e=0
    // (total_header_count). Per FUN_001c70b0 decompile in
    // ghidra_exports/ee_lobby_handlers.txt, that counter is ONLY written by
    // 0x6503's parser. Mode=0x00 skips 0x6503, so the counter stays 0; the
    // renderer reaches lobby/server-select with broken pagination ("1/0",
    // "page 88/0", 257 garbage players reading uninitialized memory).
    // Old "mode=1 paging dead end (14% + d901)" verdict was based on PCSX2
    // visuals + a broken 0x6503 handler (raw Latin-1 instead of snapField);
    // both factors invalidated 2026-05-24.
    // Mode=0x01 payload: mode byte + two u32 BE consumed by FUN_001c3b10 calls
    // (stored at uRam00365e04 and uRam00365e00).
    conn.log(`[session ${conn.id}]     LOBBY_HEADER (cmd 0x6501) p5=0x${p.p5.toString(16)} p7=0x${p.p7.toString(16)} payload=${p.payload.length}b`);
    if (!useFullHeaderLobby()) {
      conn.sendPacket(new Packet(null, {
        dir: DIR_SERVER_TELL, cmd: CMD.LOBBY_HEADER, p5: p.p5, err: 0, p7: p.p7,
        payload: Buffer.from([0x00]),
      }), `-> LOBBY_HEADER ${LOBBY_LIST_MODE} mode=0x00 (skip 0x6503 header details)`);
      return;
    }
    conn.sendPacket(new Packet(null, {
      dir: DIR_SERVER_TELL, cmd: CMD.LOBBY_HEADER, p5: p.p5, err: 0, p7: p.p7,
      payload: Buffer.from([0x01, 0,0,0,0, 0,0,0,0]),
    }), 'â†’ LOBBY_HEADER mode=0x01 + two zero u32s (forces game to request 0x6503 for header-count)');
  },

  // 0x6503 LOBBY_HEADER_DETAILS â€” reached after LOBBY_HEADER mode=1.
  // Handler FUN_001c70b0 (ghidra_exports/ee_lobby_handlers.txt line 204+):
  //   u16_be  total_header_count   â† stored at uRam00365e1e; 0 = TERMINAL error, capped at 16
  //   u16_be  batch_start_offset   â† stored at uRam00365e18
  //   u8      batch_count          â† stored at bRam00365e1c
  //   batch_count records, each:
  //     snapField(maxLen=0x3e) via FUN_001c3b90 â†’ stored at +0x365e20 (record name)
  //     snapField(maxLen=0x0f) via FUN_001c3b90 â†’ stored at +0x365e5f (short field)
  //     8 raw bytes via FUN_001c3a60                  â†’ stored at +0x365e6f
  //     snapField(maxLen=0xff) via FUN_001c3b90 â†’ stored at +0x365e77 (long blob)
  // Critical fix 2026-05-25: previous version sent raw Latin-1 where the parser
  // expects snapField encoding â€” would have produced lVar6 < 0 (parser fail)
  // and terminal error. Use snapField helper (same codec as 0x6504).
  [CMD.LOBBY_HEADER_DETAILS]: (conn, p) => {
    conn.log(`[session ${conn.id}]     LOBBY_HEADER_DETAILS (cmd 0x6503) p5=0x${p.p5.toString(16)} p7=0x${p.p7.toString(16)} payload=${p.payload.length}b`);
    enqueueLobbyDiag(conn, 'pre-6503-reply', p);
    // Auto-dump: capture entries 0..3 before AND after the 6503 reply so we can
    // see exactly which entry bytes our reply populates (and identify what stays
    // zero for follow-up RE).
    for (let i = 0; i < 4; i++) dumpLobbyEntry(`PRE-6503 entry ${i}`, i);
    setTimeout(() => {
      for (let i = 0; i < 4; i++) dumpLobbyEntry(`POST-6503 +200ms entry ${i}`, i);
    }, 200);
    const SALT = 0;
    const TOTAL = lobbySlotCount();   // total_header_count: 1..16, 0 = terminal error per decompile
    const BATCH = TOTAL;              // batch_count: send all entries in one batch (uRam00365e18 += BATCH)
    const header = Buffer.alloc(5);
    header.writeUInt16BE(TOTAL, 0);
    header.writeUInt16BE(0, 2);    // batch_start_offset = 0
    header[4] = BATCH;
    // One header record per entry. FUN_001c70b0 writes each at
    // (uRam00365e0c+i)*0x260+0x365e20, so N records populate entries 0..N-1
    // and set uRam00365e1e=N, letting the 0x6502/0x6504 walk visit every entry.
    const records = [];
    for (let i = 0; i < BATCH; i++) {
      records.push(snapField(`PAL Lobby ${i + 1}`,                       0x3e, p.p5, SALT)); // name @+0x365e20
      records.push(snapField(`Outbreak ${i + 1}`,                        0x0f, p.p5, SALT)); // server-select name @+0x365e5f (PROVEN marker test)
      records.push(Buffer.alloc(8, 0x00));                                                   // 8 raw @+0x365e6f
      records.push(snapField('Resident Evil Outbreak File 2 PAL',        0xff, p.p5, SALT)); // blob @+0x365e77
    }
    const payload = Buffer.concat([header, ...records]);
    conn.log(`[session ${conn.id}]     0x6503 snapField-encoded: total=${TOTAL} batch=${BATCH} records=${BATCH} = payload ${payload.length}b (salt=${SALT})`);
    conn.sendPacket(new Packet(null, {
      dir: DIR_SERVER_TELL, cmd: CMD.LOBBY_HEADER_DETAILS, p5: p.p5, err: 0, p7: p.p7,
      payload,
    }), `â†’ LOBBY_HEADER_DETAILS snapField-encoded total=${TOTAL} batch=${BATCH} (sets uRam00365e1e)`);
    enqueueLobbyDiag(conn, 'post-6503-reply+25ms', p, 25);
    enqueueLobbyDiag(conn, 'post-6503-reply+100ms', p, 100);
  },

  // 0x6502 LOBBY_SLOT â€” PAL "lobby slot" per Ghidra export label.
  // Handler FUN_001c7680 (Codex analysis/tcp10127-cmd6502.md).
  // 2026-05-18 (Codex tcp10127-post6510-fast-fin.md): mode=0 caused d901 fast-FIN
  // after the subsequent 0x6510 reply because current_entry+0x365f78 stays zero,
  // sending the state machine to 0x31 (terminal) instead of populating a real
  // slot. Switched to mode=1 + two zero u32s (the entry-present path) so the
  // EE has a non-empty slot to walk into the next state.
  [CMD.LOBBY_SLOT]: (conn, p) => {
    conn.log(`[session ${conn.id}]     LOBBY_SLOT (cmd 0x6502) p5=0x${p.p5.toString(16)} p7=0x${p.p7.toString(16)} payload=${p.payload.length}b`);
    enqueueLobbyDiag(conn, 'pre-6502-reply', p);
    if (useLegacyEmptyLobby()) {
      conn.sendPacket(new Packet(null, {
        dir: DIR_SERVER_TELL, cmd: CMD.LOBBY_SLOT, p5: p.p5, err: 0, p7: p.p7,
        payload: Buffer.from([0x00]),
      }), '-> LOBBY_SLOT legacy-empty mode=0x00 (skip 0x6504 slot details)');
      enqueueLobbyDiag(conn, 'post-6502-legacy-empty+25ms', p, 25);
      return;
    }
    // 2026-05-19 (Codex tcp10127-upstream-state-before-6504.md step 2):
    // Candidate A (u32a=0, u32b=1) tested â€” same 16% / d901 fast-FIN.
    // Trying Candidate B (both u32s = 1) before escalating to step 3
    // (AREACOUNT mode=0x01). first u32 stores into 0x365e08; second into
    // current_entry+0x365f7c.
    conn.sendPacket(new Packet(null, {
      dir: DIR_SERVER_TELL, cmd: CMD.LOBBY_SLOT, p5: p.p5, err: 0, p7: p.p7,
      payload: Buffer.from([0x01, 0,0,0,1, 0,0,0,1]),
    }), 'â†’ LOBBY_SLOT mode=0x01 + u32a=1 u32b=1 (Codex step 2 candidate B)');
    enqueueLobbyDiag(conn, 'post-6502-reply+25ms', p, 25);
  },

  // 0x6504 LOBBY_SLOT_DETAILS â€” PAL slot-detail population. Codex confirmed via
  // analysis/tcp10127-fun-001c3b90-field-codec.md that field_a, field_b, and
  // long_blob are NOT fixed-width; they're variable-length encoded via
  // FUN_001c3b90 with the snapField wire shape: u16_be wire_len+2, u16_be
  // checksum, encoded bytes (XOR with "MINAMIOH" key + salt+p5+i). All other
  // fields (counts + 8 raw bytes + trailing u16/u16/u32) are raw BE.
  //
  // salt = EE TCP SN@P state+0x4c â€” not yet observed live. Codex's instruction
  // is to start with salt=0; sampler watches 0x35ccd0 to discriminate framing
  // (-2) vs checksum (-3) failures:
  //   - 0x35ccd0 stays zero       â†’ framing still wrong
  //   - 0x35ccd0 becomes readable â†’ past the framing gate; salt likely matters
  //   - 0x35ccd0 readable + advance â†’ salt 0 was right
  [CMD.LOBBY_SLOT_DETAILS]: async (conn, p) => {
    conn.log(`[session ${conn.id}]     LOBBY_SLOT_DETAILS (cmd 0x6504) p5=0x${p.p5.toString(16)} p7=0x${p.p7.toString(16)} payload=${p.payload.length}b`);
    enqueueLobbyDiag(conn, 'pre-6504-reply', p);
    // Lobby-entry table dump: capture BEFORE/AFTER cmd 0x6504 reply
    dumpLobbyEntry('PRE-6504 (game asks for slot details, we have not replied yet)');
    setTimeout(() => dumpLobbyEntry('POST-6504 +200ms (after our reply)'), 200);

    const snapTs = Date.now();
    const snapFile = path.join(CMD6504_SNAPSHOT_DIR,
      `cmd6504_session${conn.id}_${snapTs}.log`);
    fs.writeFileSync(snapFile, `=== cmd 0x6504 SESSION ${conn.id} @ ${new Date(snapTs).toISOString()} ===\n`);
    conn.log(`[session ${conn.id}]     cmd6504 snapshot file: ${snapFile}`);
    enqueueCmd6504Snapshot(snapFile, 'PRE-REPLY requested (non-blocking; 0x6504 request received)', snapTs);

    const SALT = 0; // Codex: try 0 first; sample state+0x4c if checksum fails.
    // 2026-06-16: connect host. DEV9 proved the game DNS-resolves this slot name on select
    // ("SLOT0001" → Refused → "server busy"). Use the Pi IP so it resolves/connects directly.
    const fieldA   = snapField(process.env.SNAP_SLOT_HOST || '192.0.2.121',  0x0f, p.p5, SALT);
    const fieldB   = snapField('OPEN',      0x0f, p.p5, SALT);
    const rawBytes = Buffer.alloc(8, 0x00);
    const longBlob = snapField('Test Slot', 0xff, p.p5, SALT);
    const currentPlayersFallback = Math.max(0, Math.min(999, parseInt(process.env.SNAP_LOBBY_SLOT_CURRENT_PLAYERS || '1', 10)));
    const currentPlayers = serverSelectPlayerCountForWire(currentPlayersFallback);
    const maxPlayers = Math.max(1, Math.min(999, parseInt(process.env.SNAP_LOBBY_SLOT_MAX_PLAYERS || '1', 10)));
    const trailing = Buffer.alloc(8);
    trailing.writeUInt16BE(currentPlayers, 0); // field_d; likely current players / occupancy.
    trailing.writeUInt16BE(maxPlayers, 2); // field_e; UI renders this as maximum players.
    trailing.writeUInt32BE(HOST_IP_BE, 4); // field_f — server's LAN IP (auto-detected, override with SERVER_HOST_IP env)

    const header = Buffer.alloc(5);
    header.writeUInt16BE(1, 0); // total_slot_count
    header.writeUInt16BE(0, 2); // batch_start
    header[4] = 0x01;            // batch_count

    const payload = Buffer.concat([header, fieldA, fieldB, rawBytes, longBlob, trailing]);
    conn.log(`[session ${conn.id}]     0x6504 snapField-encoded: total=1 batch=1 fieldA(${fieldA.length}b)+fieldB(${fieldB.length}b)+raw8+blob(${longBlob.length}b)+trail8 = payload ${payload.length}b (salt=${SALT}, currentPlayers=${currentPlayers}, maxPlayers=${maxPlayers})`);

    conn.sendPacket(new Packet(null, {
      dir: DIR_SERVER_TELL, cmd: CMD.LOBBY_SLOT_DETAILS, p5: p.p5, err: 0, p7: p.p7,
      payload,
    }), `â†’ LOBBY_SLOT_DETAILS snapField-encoded (Codex fun_001c3b90 codec, salt=${SALT})`);
    enqueueLobbyDiag(conn, 'post-6504-reply+25ms', p, 25);
    enqueueLobbyDiag(conn, 'post-6504-reply+100ms', p, 100);

    // Post-reply snapshots at staggered intervals:
    //  - +100ms: catch immediate parser side-effects (slot pool, state mutation)
    //  - +500ms: post-FIN state (lobby state / slot map after teardown)
    setTimeout(() => enqueueCmd6504Snapshot(snapFile, 'T+100ms after reply', snapTs), 100);
    setTimeout(() => enqueueCmd6504Snapshot(snapFile, 'T+500ms after reply', snapTs), 500);
    setTimeout(() => enqueueCmd6504Snapshot(snapFile, 'T+1500ms after reply / post-FIN', snapTs), 1500);
  },

  // 0x6510 LOBBY_LIST_CHUNK â€” handler FUN_001c8790. Codex
  // analysis/tcp10127-cmd6510-snapfield-reply.md (2026-05-19) corrected the
  // reply shape: trailing 0x3e field is a snapField, not raw zeros.
  // Reply parser:
  //   u8       reply_count                                     â† must equal uRam00365e1a
  //   u16_be[] status/list, only if reply_count == 0x365e1a    â† reply_count Ã— u16
  //   snapField(..., maxLen=0x3e)                              â† stored at current_entry.name
  //
  // Sampler observed 0x365e1a = LE 1 after the working 0x6504 path (not 8 as
  // the earlier 0x6502 mode=1 spec predicted), so reply_count=1 + one u16=0
  // + snapField("SLOT0001"). Codex picked SLOT0001 because the client just
  // asked for that slot by name.
  [CMD.LOBBY_LIST_CHUNK]: (conn, p) => {
    conn.log(`[session ${conn.id}]     LOBBY_LIST_CHUNK (cmd 0x6510) p5=0x${p.p5.toString(16)} p7=0x${p.p7.toString(16)} payload=${p.payload.length}b`);
    enqueueLobbyDiag(conn, 'pre-6510-reply', p);
    // Lobby-entry table dump: capture BEFORE we send 0x6510 reply, then T+200ms after.
    dumpLobbyEntry('PRE-6510 (game asks for list, we have not replied yet)');
    setTimeout(() => dumpLobbyEntry('POST-6510 +200ms (after our reply)'), 200);
    if (useLegacyEmptyLobby()) {
      const payload = Buffer.concat([
        Buffer.from([0x00]),
        Buffer.alloc(0x3e, 0x00),
      ]);
      conn.sendPacket(new Packet(null, {
        dir: DIR_SERVER_TELL, cmd: CMD.LOBBY_LIST_CHUNK, p5: p.p5, err: 0, p7: p.p7,
        payload,
      }), '-> LOBBY_LIST_CHUNK legacy-empty count=0 + 0x3e zero field');
      enqueueLobbyDiag(conn, 'post-6510-legacy-empty+25ms', p, 25);
      enqueueLobbyDiag(conn, 'post-6510-legacy-empty+75ms', p, 75);
      enqueueLobbyDiag(conn, 'post-6510-legacy-empty+200ms', p, 200);
      return;
    }
    // 2026-05-30 REVERTED: my "fix" (dropping the u16=0) caused D901 on live
    // PS2 test — couldn't even reach server-select. So the u16=0 between
    // count and snapField IS expected by the parser in practice, even though
    // the static decompile of FUN_001c8790 suggests it would be skipped.
    // The discrepancy probably means uRam00365e1a is 1 in the live flow,
    // not 8 — so the parser DOES read 1 u16 (= 0) into slot+0x12c, then
    // reads the snapField. Keeping the original 3-element layout.
    const SALT = 0;
    // 2026-06-14: 0x6510 is a CHUNKED/indexed protocol — a single reply with
    // count=N (the 2026-06-13 fix attempt) D901'd on real PS2. The correct lever
    // for giving server 2 a record is the 0x6503 entry-count walk (SNAP_LOBBY_SLOTS,
    // see lobbySlotCount()), NOT this chunk. So 0x6510 stays at the known-safe
    // count=1 + one snapField, decoupled from SNAP_LOBBY_SLOTS.
    // 2026-07-17 FOUNDATION (SNAP_SERVER_COUNT=1): this u16 lands at slot+0x12c = the DRAWN
    // server-select current-players count (G12-count-displays-RE-2026-07-17; the 0x6504 trail field_d
    // at +0x128 is undrawn). We shipped 0 here -> "0 players". Feed the registry's online count.
    const serverCount = process.env.SNAP_SERVER_COUNT === '1'
      ? Math.max(0, Math.min(999, lobbyState.countOnline()))
      : 0;
    const parts = [
      Buffer.from([0x01]),                       // count = 1 (per-chunk)
      payloadBE16(serverCount),                  // u16 BE -> slot+0x12c (drawn current players)
      snapField(process.env.SNAP_SLOT_HOST || '192.0.2.121', 0x3e, p.p5, SALT),   // connect host (was "SLOT0001" → DNS Refused → busy); Pi IP so it resolves directly
    ];
    const payload = Buffer.concat(parts);
    conn.sendPacket(new Packet(null, {
      dir: DIR_SERVER_TELL, cmd: CMD.LOBBY_LIST_CHUNK, p5: p.p5, err: 0, p7: p.p7,
      payload,
    }), `-> LOBBY_LIST_CHUNK count=1 + (u16=0 + snapField("SLOT0001"), 0x3e, salt=${SALT})`);
    enqueueLobbyDiag(conn, 'post-6510-reply+25ms', p, 25);
    enqueueLobbyDiag(conn, 'post-6510-reply+75ms', p, 75);
    enqueueLobbyDiag(conn, 'post-6510-reply+200ms', p, 200);
  },

  // 0x6104 CHUNK_FETCH_61 — chunk-fetch data reply.
  // 2026-05-28: dispatch table idx 0x30 (dir=02 cmd=0x6104) → FUN_001c6130.
  // Outbound side (FUN_001c6060, dispatcher case 0x2b after our 0x6103
  // manifest) sends:
  //   u32_be key (= our key from 0x6103 manifest)
  //   u32_be offset (current byte offset into entry)
  //   u16_be requested chunk window (0x02d2 default)
  // Reply parser FUN_001c6130 expects:
  //   u32_be returned_key (MUST match 0x365d74[index] = our manifest key)
  //   u32_be returned_offset
  //   u16_be payload_length
  //   snapField(data, max 0x02d2) decoded into chunk buffer + offset
  // Copy destination: 0x35ccc8 + index*0x800 + 0x1000 + offset
  // Completion (after offset+length >= entry total OR offset >= 0x1000):
  //   advance index; if more entries → sub=0x2b; if done & major_mode==3 →
  //   sub=0x31 (D901); else → sub=2 (continue lobby walk).
  [CMD.CHUNK_FETCH_61]: (conn, p) => {
    const req = parseKeyOffsetSize(p.payload, 0x02d2);
    conn.log(`[session ${conn.id}]     CHUNK_FETCH_61 (cmd 0x6104) key=0x${req.key.toString(16)} offset=${req.offset} size=${req.size} p5=0x${p.p5.toString(16)} payload=${p.payload.length}b`);
    if (req.key !== CHUNK_61_KEY) {
      conn.log(`[session ${conn.id}]     ⚠ key mismatch (req=0x${req.key.toString(16)} ≠ ours=0x${CHUNK_61_KEY.toString(16)}); will probably abort EE-side`);
    }
    const { offset, data } = clampChunkSlice(CHUNK_61_RECORD, req.offset, req.size, 0x02d2);
    const header = Buffer.alloc(10);
    header.writeUInt32BE(CHUNK_61_KEY >>> 0, 0);            // returned key
    header.writeUInt32BE(offset >>> 0, 4);                   // returned offset
    header.writeUInt16BE(data.length & 0xffff, 8);           // payload length
    const payload = Buffer.concat([
      header,
      snapField(data, 0x02d2, p.p5, 0),
    ]);
    conn.sendPacket(new Packet(null, {
      dir: DIR_SERVER_TELL, cmd: CMD.CHUNK_FETCH_61, p5: p.p5, err: 0, p7: p.p7,
      payload,
    }), `→ CHUNK_FETCH_61 key=0x${CHUNK_61_KEY.toString(16)} offset=${offset} len=${data.length}/${CHUNK_61_RECORD.length}`);
  },

  // 0x6401 / 0x6402 chunk-list-no-key path (FUN_001c5040 / FUN_001c5260).
  // Reached only from sub=0x15 (after sub=0x14 → 0x6211 reply with major
  // mode 4). We are NEVER in major mode 4 from server side, so these are
  // safety net handlers and won't fire in current traces.
  [CMD.CHUNK_LIST_64]: (conn, p) => {
    conn.log(`[session ${conn.id}]     CHUNK_LIST_64 (cmd 0x6401) p5=0x${p.p5.toString(16)} p7=0x${p.p7.toString(16)} payload=${p.payload.length}b`);
    const payload = Buffer.concat([
      payloadBE16(1),                         // count, max 8
      payloadBE(CHUNK_64_RECORD.length),      // total_len for index 0
    ]);
    conn.sendPacket(new Packet(null, {
      dir: DIR_SERVER_TELL, cmd: CMD.CHUNK_LIST_64, p5: p.p5, err: 0, p7: p.p7,
      payload,
    }), `→ CHUNK_LIST_64 count=1 total_len=${CHUNK_64_RECORD.length}`);
  },

  [CMD.CHUNK_FETCH_64]: (conn, p) => {
    const req = parseIndexOffsetSize(p.payload, 0x02f2);
    conn.log(`[session ${conn.id}]     CHUNK_FETCH_64 (cmd 0x6402) index=${req.index} offset=${req.offset} size=${req.size} p5=0x${p.p5.toString(16)} payload=${p.payload.length}b`);
    const { offset, data } = clampChunkSlice(CHUNK_64_RECORD, req.offset, req.size, 0x02f2);
    const header = Buffer.alloc(6);
    header.writeUInt16BE(req.index & 0xffff, 0);
    header.writeUInt32BE(offset >>> 0, 2);
    const payload = Buffer.concat([
      header,
      snapField(data, 0x02f2, p.p5, 0),
    ]);
    conn.sendPacket(new Packet(null, {
      dir: DIR_SERVER_TELL, cmd: CMD.CHUNK_FETCH_64, p5: p.p5, err: 0, p7: p.p7,
      payload,
    }), `→ CHUNK_FETCH_64 index=${req.index} offset=${offset} len=${data.length}`);
  },

  // 0x6105 STATUS_TABLE_61 — STATUS/MESSAGE TABLE manifest.
  // 2026-05-29: Parsed by FUN_001c63c0 (SLES). Reply shape:
  //   u16_be count (max 8)
  //   per entry: u32_be code, u32_be metadata
  // Side effects: writes 0x00365bb0 (count), 0x00365bb4[i] (code),
  // 0x00365bd4[i] (metadata), 0x00365bf4[i] = 0x35ccb8 + i*0x200 (buf ptr).
  // On count==0 → state+0xd = 0x31 (terminal); on count>0 → state+0xd = 0x41
  // (game emits 0x6320 chunk-fetch).
  //
  // The status table feeds FUN_00626730 event matcher. Press-X gate
  // cRam0086f7e0 is set to 1 ONLY if event byte 0 = 0x27 AND code at body+4
  // matches a code in this table where that code = 0x13. We never send 0x27
  // events, so populating this table is currently optional — but having a
  // valid table also unblocks any path that requires count > 0.
  [CMD.STATUS_TABLE_61]: (conn, p) => {
    conn.log(`[session ${conn.id}]     STATUS_TABLE_61 (cmd 0x6105) p5=0x${p.p5.toString(16)} p7=0x${p.p7.toString(16)} payload=${p.payload.length}b`);
    const entries = STATUS_TABLE_ENTRIES;
    const buf = Buffer.alloc(2 + entries.length * 8);
    buf.writeUInt16BE(entries.length, 0);
    for (let i = 0; i < entries.length; i++) {
      buf.writeUInt32BE(entries[i][0] >>> 0, 2 + i * 8);
      buf.writeUInt32BE(entries[i][1] >>> 0, 6 + i * 8);
    }
    conn.sendPacket(new Packet(null, {
      dir: DIR_SERVER_TELL, cmd: CMD.STATUS_TABLE_61, p5: p.p5, err: 0, p7: p.p7,
      payload: buf,
    }), `→ STATUS_TABLE_61 count=${entries.length} (populates 0x00365bb0/bb4/bd4)`);
  },

  // 0x6320 STATUS_FETCH_63 — STATUS TABLE per-entry chunk fetch.
  // 2026-05-29: dispatch idx 0x41/0x42, parsed by FUN_001c8ae0. Same key+
  // offset+size shape as 0x6104 but writes into the 0x35ccb8 + i*0x200
  // per-entry buffer (0x200 bytes each — much smaller than 0x6104).
  //
  // KNOWN PROTOCOL GAP: the exact parser shape for this hasn't been
  // confirmed via Ghidra yet. Treating it as a chunk-fetch with the same
  // header shape (u32 index/key + u32 offset + u16 size) is the working
  // assumption. May need adjustment after game.bin / FUN_001c8ae0 decompile.
  [CMD.STATUS_FETCH_63]: (conn, p) => {
    const req = parseKeyOffsetSize(p.payload, 0x02d2);
    conn.log(`[session ${conn.id}]     STATUS_FETCH_63 (cmd 0x6320) key=0x${req.key.toString(16)} offset=${req.offset} size=${req.size} p5=0x${p.p5.toString(16)} payload=${p.payload.length}b`);
    const { offset, data } = clampChunkSlice(STATUS_TABLE_CHUNK, req.offset, req.size, 0x02d2);
    const header = Buffer.alloc(10);
    header.writeUInt32BE(req.key >>> 0, 0);
    header.writeUInt32BE(offset >>> 0, 4);
    header.writeUInt16BE(data.length & 0xffff, 8);
    const payload = Buffer.concat([
      header,
      snapField(data, 0x02d2, p.p5, 0),
    ]);
    conn.sendPacket(new Packet(null, {
      dir: DIR_SERVER_TELL, cmd: CMD.STATUS_FETCH_63, p5: p.p5, err: 0, p7: p.p7,
      payload,
    }), `→ STATUS_FETCH_63 key=0x${req.key.toString(16)} offset=${offset} len=${data.length}/${STATUS_TABLE_CHUNK.length}`);
  },

  // ===================================================================
  // BLOCKING/UNRESOLVED PROTOCOL POINTS (revised 2026-05-30)
  // ===================================================================
  // 1. Lobby-entry struct is loaded from DISC (NETBIO00.DAT AFS entries
  //    #0 and #11), NOT from SNAP chunks. The 0x6103 chunks are sprites
  //    for the lobby UI. So our SNAP server CANNOT inject hostname/handle
  //    fields into the press-X struct — those come from the disc-loaded
  //    table at iRam0070d1c0+0x258.
  // 2. Press-X reads uRam0035ba98 (4-byte IP from struct +0x300 via
  //    func_0x001c0690 DNS resolve) and calls func_0x001db7e8(...) with
  //    that IP + port 0xcaf3 (51955). If the on-disc hostname isn't
  //    caught by our DNS catch-all (*.yav4.com / *.dnas.playstation.org /
  //    *.pcsx2), the connect goes to the real, dead, production endpoint.
  // 3. UNI-FI handles DNS UDP 53 (dns_server.js EADDRINUSE). So our
  //    wildcards only apply to hostnames UniFi forwards. Use pktmon to
  //    confirm which hostnames the PS2 actually queries.
  // 4. game.bin in-match protocol (post-press-X) still unmapped.
  // 5. FUN_00626730 event callback (which sets cRam0086f7e0 error flag)
  //    has zero callers in netwk.bin static decompile — likely registered
  //    via SLES callback table; we never emit byte 0x27 events.
  // ===================================================================

  // 0x1004 POST_LOBBY_ACK â€” empty-success ACK sent by the client after the
  // lobby walk completes. Codex analysis/tcp10127-cmd1004.md: EE reply-side
  // stub at 0x001c8e90 is literally `jr ra; li v0, 1` â€” reads no payload,
  // writes no state, always returns success. Just echo p5/p7 with empty body.
  [CMD.POST_LOBBY_ACK]: (conn, p) => {
    conn.log(`[session ${conn.id}]     POST_LOBBY_ACK (cmd 0x1004) p5=0x${p.p5.toString(16)} p7=0x${p.p7.toString(16)} payload=${p.payload.length}b`);
    enqueueLobbyDiag(conn, 'pre-1004-reply', p);
    conn.sendPacket(new Packet(null, {
      dir: DIR_SERVER_TELL, cmd: CMD.POST_LOBBY_ACK, p5: p.p5, err: 0, p7: p.p7,
      payload: Buffer.alloc(0),
    }), 'â†’ POST_LOBBY_ACK empty success (EE handler is jr ra; li v0,1)');
    enqueueLobbyDiag(conn, 'post-1004-reply+50ms', p, 50);
    // Lobby-entry table dump: capture AFTER lobby walk fully completes
    // (this is the moment game would render the server-select screen)
    setTimeout(() => dumpLobbyEntry('POST-1004 +500ms (lobby walk complete, server-select rendered)'), 500);
    setTimeout(() => dumpLobbyEntry('POST-1004 +5000ms (after game settles, before press-X)'), 5000);
    // Mark so socket-close handler re-arms a post-lobby-resume entry for the
    // game's second TCP 10127 connection.
    conn.sentPostLobbyAck = true;

    // Establishment-message experiment (2026-06-10): after the lobby walk the game
    // shows the server-select; selecting a server runs the connect (FUN_00626900)
    // which waits ~10s for event bit 0x10 then 840s. Proactively push a candidate
    // deliverable reliable DATA message to the game's UDP endpoint across that
    // window to try to set bit 0x10. Gated by SNAP_ESTAB_PUSH (default ON); message
    // variant via SNAP_ESTAB_VARIANT. Read bit 0x10 via PINE to evaluate.
    if (process.env.SNAP_ESTAB_PUSH !== '0') {
      const ip = String(conn.socket?.remoteAddress || '').replace(/^::ffff:/, '');
      let gameUdp; try { gameUdp = require('./game_udp_server'); } catch (e) { gameUdp = null; }
      if (gameUdp && gameUdp.proactivePush) {
        for (const delay of [4000, 6000, 8000, 10000, 12000, 14000, 16000]) {
          const t = setTimeout(() => {
            try { const r = gameUdp.proactivePush(ip); conn.log(`[session ${conn.id}] ESTAB-PUSH(+${delay}ms): ${JSON.stringify(r)}`); }
            catch (e) { conn.log(`[session ${conn.id}] ESTAB-PUSH err: ${e.message}`); }
          }, delay);
          t.unref && t.unref();
        }
      }
    }
  },
};

function dispatch(conn, p) {
  const h = HANDLERS[p.cmd];
  if (h) {
    try {
      h(conn, p);
    } catch (e) {
      conn.log(`[session ${conn.id}]     HANDLER ERROR ${CMD_NAME[p.cmd] || p.cmd.toString(16)}: ${e.message}\n${e.stack}`);
    }
  } else {
    conn.log(`[session ${conn.id}]     NO HANDLER for cmd=0x${p.cmd.toString(16)} dir=0x${p.dir.toString(16)}  (${p.toString()})`);
    conn.log(`[session ${conn.id}]     â˜… unhandled â€” add to HANDLERS to advance protocol`);
  }
}

// === Server ==================================================================
let sessionCount = 0;

// session_store auto-purges expired entries via TTL â€” no startup wipe needed.
// Multi-client behavior: multiple pending entries per IP are tracked as a list;
// newest-first wins on SN@P connect.
{
  const { pendingStats } = require('./session_store');
  const stats = pendingStats();
  if (stats.entries > 0) {
    console.log(`SN@P startup: ${stats.entries} pending LBS entries active across ${stats.ips} IP(s) (TTL-managed)`);
  }
}

const server = net.createServer(socket => {
  const id = ++sessionCount;
  const pending = getPendingOnline(socket.remoteAddress);
  const isLobby = !!pending;
  // pending.armedFrom is stable; pending.session.pendingOnlineState is mutated
  // to 'snap-connected' by getPendingOnline so we don't read it for branching.
  const armedFrom = pending?.armedFrom
    || (pending?.sessid?.startsWith('udp9090:') ? 'udp9090-register'
      : pending?.sessid?.startsWith('post-lobby-resume:') ? 'post-lobby-resume'
      : pending ? 'lbs' : null);
  const refreshCount = pending?.refreshCount || 0;
  const reason = pending
    ? (armedFrom === 'udp9090-register'
        ? `armed by UDP 9090 REGISTER for user=${pending.userid} useCount=${pending.useCount}`
        : armedFrom === 'post-lobby-resume'
          ? `armed by post-lobby resume #${refreshCount} for user=${pending.userid} useCount=${pending.useCount}`
          : `armed by POST /mhweb/lbs.jsp for user=${pending.userid} sessid=${pending.sessid} useCount=${pending.useCount}`)
    : 'no pending arming for this IP; using boot auth (independent â€” same path regardless of UDP/HTTP state)';
  const conn = new Connection(socket, id, isLobby, reason);
  conn.armedFrom = armedFrom;
  conn.refreshCount = refreshCount;
  conn.userid = pending?.userid || null;
  conn.handle = pending?.handle || null;
  conn.pendingSessid = pending?.sessid || null;

  conn.log('\n' + '='.repeat(70));
  conn.log(`[session ${id}] OPEN  remote=${socket.remoteAddress}:${socket.remotePort}  t0=${new Date().toISOString()}`);
  conn.log(`[session ${id}] trace log: ${conn.logFile}`);
  conn.log(`[session ${id}] phase: ${isLobby ? 'LOBBY (dispatch)' : 'BOOT AUTH'}  reason=${reason}`);

  // Track timers so they can be cancelled on socket close (avoid leaks/lingering writes)
  conn.timers = [];
  function scheduleSend(delay, packet, label) {
    const t = setTimeout(() => {
      if (!socket.destroyed) conn.sendPacket(packet, label);
    }, delay);
    conn.timers.push(t);
  }

  if (!isLobby) {
    // BOOT AUTH: just the original 3-packet sequence then wait/close
    BOOT_SEQUENCE.forEach((p, i) => scheduleSend(50 + i * 50, p));
    conn.log(`[session ${id}] queued boot packets; listening for IN...`);
  } else {
    // LOBBY: send CONNCHECK challenge proactively. Game's FUN_001c92d0 reads
    // sub_cmd from payload[0] via FUN_001c3a60. Payload-length=0 here is fine
    // because PAL's uninitialized payload buffer reads back as 0 â†’ sub_cmd=0
    // â†’ state 0x23 (no-auth path) â†’ game then queries us with SESSION_VERIFY.
    scheduleSend(5, new Packet(null, {
      dir: DIR_SERVER_CHALL, cmd: CMD.CONNCHECK, p5: 0x01, err: 0, p7: 0,
    }), 'â†’ CONNCHECK challenge (server initiates)');
    conn.log(`[session ${id}] sent CONNCHECK challenge; awaiting game packets in dispatch...`);
  }

  socket.setKeepAlive(true, 1000);

  socket.on('data', chunk => {
    // VERBATIM RAW-IN log fires per-chunk BEFORE any parsing â€” captures
    // non-PAL bytes, partial frames, and any pre-handshake bytes the game
    // sends before the formatted packet log can render anything. 2026-05-18:
    // added for TCP 10127 lobby-phase RE. The formatted log only fires once
    // a full 8-byte header arrives, so sub-frame bytes were previously only
    // visible in the on-close FULL dump.
    conn.log(`[session ${conn.id}] ${conn.dt()}  RAW-IN ${chunk.length}b ${chunk.toString('hex')}`);

    conn.recvBuf = Buffer.concat([conn.recvBuf, chunk]);
    conn.received.push(Buffer.from(chunk));
    conn.totalBytes += chunk.length;

    // Process packets: header is 8 bytes, payload length is BE u16 at bytes 0-1.
    // Wait for the full frame (header + payload) before dispatching.
    while (conn.recvBuf.length >= 8) {
      const payloadLen = conn.recvBuf.readUInt16BE(0);
      const frameLen = 8 + payloadLen;
      if (conn.recvBuf.length < frameLen) break;     // need more bytes

      const raw = conn.recvBuf.slice(0, frameLen);
      conn.recvBuf = conn.recvBuf.slice(frameLen);

      conn.seqIn++;
      const p = new Packet(raw);
      conn.log(`\n[session ${conn.id}] ${conn.dt()}  Î”${String(conn.delta()).padStart(5)}ms  IN  #${conn.seqIn} (${frameLen}b, total=${conn.totalBytes})`);
      conn.log(hex(raw));
      conn.log(`    decode: ${p.toString()}`);
      saveCapture(`session${conn.id}_in_${conn.seqIn}`, raw);

      try {
        dispatch(conn, p);
      } catch (e) {
        // Keep the process alive when a press-X / press-O / unrecognized
        // frame hits an unhandled path. Log the offending bytes so we can
        // RE the frame, but never crash the server.
        conn.log(`[session ${conn.id}] !!! dispatch threw: ${e.stack || e.message}`);
        conn.log(`[session ${conn.id}]     offending frame (${raw.length}b): ${raw.toString('hex')}`);
      }
    }
  });

  socket.on('end', () => {
    conn.log(`\n[session ${conn.id}] ${conn.dt()}  REMOTE FIN â€” total IN bytes: ${conn.totalBytes}`);
    enqueueLobbyDiag(conn, 'remote-fin');
    if (conn.received.length > 0) {
      const full = Buffer.concat(conn.received);
      saveCapture(`session${conn.id}_FULL`, full);
      conn.log(`[session ${conn.id}] full IN dump:\n${hex(full)}`);
    }
  });

  socket.on('close', () => {
    // Cancel any pending timers so they don't write to a dead socket
    if (conn.timers) conn.timers.forEach(clearTimeout);
    conn.timers = [];
    // If this session consumed a pending arming (lobby mode), clear the
    // arming so subsequent TCP 10127 connections from this IP fall back to
    // boot-auth. This lets the user press X to retry â€” game gets the fresh
    // boot-auth handshake instead of being stuck in lobby mode forever.
    // Same principle: each server is independent, no permanent state shifts.
    if (isLobby) {
      const { clearPendingOnline, markPendingPostLobbyResume } = require('./session_store');
      const cleared = clearPendingOnline(socket.remoteAddress, `snap-session-${id}-ended`, conn.pendingSessid);
      // If the lobby walk reached 0x1004 cleanly, re-arm for the game's
      // post-lobby refresh poll. Codex spec (post-lobby-refresh-and-dns-next-step.md):
      // keep re-arm alive for up to 3 follow-up sessions (refresh_count < 3) or
      // until 60s TTL expires, whichever first.
      const REFRESH_CAP = 3;
      if (conn.sentPostLobbyAck && conn.refreshCount < REFRESH_CAP) {
        const userid = conn.userid || 'unknown';
        const handle = conn.handle || userid;
        const nextCount = conn.refreshCount + 1;
        markPendingPostLobbyResume({ ip: socket.remoteAddress, userid, handle, refreshCount: nextCount });
        conn.log(`[session ${conn.id}] re-armed post-lobby-resume #${nextCount}/${REFRESH_CAP} for ${socket.remoteAddress} userid=${userid} (TTL 60s)`);
      } else if (conn.sentPostLobbyAck) {
        conn.log(`[session ${conn.id}] refresh cap reached (${conn.refreshCount}/${REFRESH_CAP}); not re-arming, next connect â†’ boot auth`);
      } else if (cleared) {
        conn.log(`[session ${conn.id}] cleared pending arming for ${socket.remoteAddress}; next TCP 10127 connect â†’ boot auth`);
      }
    }
    enqueueLobbyDiag(conn, 'socket-close');
    conn.log(`[session ${conn.id}] ${conn.dt()}  CLOSED  IN=${conn.seqIn}pkt/${conn.totalBytes}b  OUT=${conn.seqOut}pkt`);
  });

  socket.on('error', e => {
    if (e.code !== 'ECONNRESET') conn.log(`[session ${conn.id}] error: ${e.message}`);
  });
});

// Test-only exports (area-data.test.cjs). No effect on the running server; guarded require.main below
// keeps `require('./snap_server')` from binding the port so the blob can be asserted in isolation.
module.exports = { buildAreaBlob, AREA_BOXES, AREA_MODIFIER_BYTES, AREA_BOX_COUNT, AREA_REC_SIZE, AREA_BLOB_SIZE };

// Bind the listening socket in production — whether launched directly (node server/snap_server.js) OR
// required by start_all.js (require.main is start_all, so a `require.main === module` guard would WRONGLY
// skip the bind and the lobby would never come up). Only a test that needs the pure exports opts out via
// SNAP_TEST_NO_LISTEN=1 (set before requiring this file), which keeps the port unbound so the process exits.
if (!process.env.SNAP_TEST_NO_LISTEN)
server.listen(PORT, '0.0.0.0', () => {
  // 2026-05-29 build marker — change this string when editing to prove a fresh
  // load. If the terminal does NOT print BUILD-2026-05-29-CHUNK_LIST_61 on
  // start, Node is loading a stale snap_server.js from somewhere else.
  console.log(`>>> SN@P BUILD MARKER: 2026-05-30-LOBBY-LIST-CHUNK-REVERTED`);
  console.log(`>>>   0x6510 reply restored to [count=1][u16=0][snapField] — drop-u16 attempt caused D901 in live test`);
  console.log(`>>>   Implication: uRam00365e1a = 1 in live flow (Codex's 2026-05-19 sampler saw 8 in different state)`);
  console.log(`>>>   Press-X still blocked: uRam0035bed8 DNS resolution race (see analysis/claude-press-x-root-cause-2026-05-30.md)`);
  console.log(`>>> Verify CMD_NAME[0x6103] = ${require('util').inspect(CMD_NAME[0x6103])} (expect "CHUNK_LIST_61", NOT "CHECKVERSION")`);
  console.log(`SN@P server listening on port ${PORT}  (Bio-Serv-style dispatcher; ${Object.keys(HANDLERS).length} handlers active)`);
  console.log(`Handlers: ${Object.keys(HANDLERS).map(c => CMD_NAME[c] || c).join(', ')}`);
  console.log(`Lobby list mode: ${LOBBY_LIST_MODE}  (hybrid=real-PS2 empty-lobby path; full-header=0x6503/D901 diagnostic; legacy-empty=14%/d901 diagnostic)`);
  console.log(`Lobby diag: ${LOBBY_DIAG_ENABLED ? 'enabled' : 'disabled'}  (${LOBBY_DIAG_DIR})`);
  console.log(`Lobby-entry auto-dump: ${process.env.SNAP_LOBBY_ENTRY_DUMP === '0' ? 'disabled' : 'ENABLED'}  (PINE-reads 608B @ 0x365E20 [table start] for entries 0..3 at PRE/POST 6503/6504/6510/1004)`);
  console.log(`  → ${LOBBY_ENTRY_DUMP_FILE}`);
  console.log(`Will log every unhandled cmd with "â˜… unhandled" â€” extend HANDLERS to add them.`);
});

server.on('error', e => console.log('Server error:', e.message));
