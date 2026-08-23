/**
 * PAL Outbreak File #2 â€” UDP game server on port 9090.
 *
 * Packet shape (verified from captures/udp9090/*.bin, 154-byte LOGIN):
 *
 *   0x00  30 96 00 2c 02 64 07 d0   header (8 bytes)
 *                  â””â”€â”€ cmd?         â””â”€â”€ source port BE (0x07d0 = 2000)
 *   0x08  00x8                       reserved/zero
 *   0x10  <handle, 16 ASCII>         e.g. "test\0..."
 *   0x20  00x16
 *   0x30  00x8
 *   0x38  <auth_id, 16 ASCII>        e.g. "test@cee-auth\0..."
 *   0x48  00x40                      40 bytes zero
 *   0x76  ca f3                      checksum?
 *   0x78  00x4
 *   0x7c  c0 00 02 64                ?
 *   0x80  00 00 07 d0                source port repeated
 *   0x84  00 00 00 64                ?
 *   0x88  00 02 4c 43                "LC" tag
 *   0x8c  00 00 06 40
 *   0x90  4d 52 00 00                "MR" tag
 *   0x94  00 30 ba 47 66 11          session token + last 2 bytes
 *
 * Best-guess ACK (this is our hypothesis to test):
 *   - byte 0: 0x28 (Bio-Serv GAMESERVER â€” server-side)
 *   - byte 1: 0x02 (Bio-Serv TELL â€” answer to query)
 *   - keep bytes 2-7 (cmd + port)
 *   - mirror the rest
 *
 * If 0x28+0x02 doesn't elicit a follow-up packet from the game, fall back to
 * mirror-plain on the next datagram from the same client.
 *
 * Bio-Serv reference: bioserv2\bioserver\GameServerPacketHandler.java
 * Bio-Serv `who`: 0x18=SERVER, 0x81=CLIENT, 0x28=GAMESERVER, 0x82=GAMECLIENT.
 * Bio-Serv `qsw`: 0x01=QUERY, 0x02=TELL, 0x10=BROADCAST.
 */
'use strict';
const dgram = require('dgram');
const fs = require('fs');
const path = require('path');
const { RUN_ID } = require('./run_id');
const { HOST_IP } = require('./host_ip');
const { Blowfish } = require('./blowfish');
const { PineClient } = require('../tools/pine_client');
const { markPendingOnlineFromRegister } = require('./session_store');
// 2026-07-11 G12: the live area/room/slot registry (shared with snap_server.js; same process).
// Registry hooks below are all gated on SNAP_LOBBY_STATE=1 (default OFF -> golden behavior unchanged;
// pure in-memory bookkeeping, no wire effect). See docs/findings/protocol/G12-room-create-join-RE-2026-07-11.md.
const lobbyState = require('./lobby_state');
const LOBBY_STATE_ON = () => process.env.SNAP_LOBBY_STATE === '1';
// CONSOLIDATION: the transition authority (lobby_engine) + its transport adapter. Gated on
// SNAP_ROOM_ENGINE=1 at each wired transition; OFF = the legacy path (unchanged). The engine mutates
// the SAME lobbyState singleton. Adapter is constructed lazily (after the builders/sendSnapPacket are
// defined) to keep this require order-independent.
const lobbyEngine = require('./lobby_engine');
const { createAdapter } = require('./engine_adapter');
let _engineAdapter = null;
function engineAdapter() {
  if (_engineAdapter) return _engineAdapter;
  _engineAdapter = createAdapter({
    resolveSessions: engineSessionsFor,
    builders: {
      [lobbyEngine.K.MEMBER_LIST]: (sess, a) => {
        const r = lobbyState.rooms.get(a.handle);
        return (r && sess.addr16) ? buildRoomMemberListPacket(sess, r, 0, sess.addr16) : null;
      },
      [lobbyEngine.K.COUNT_0X11]: (sess, a) => sess.addr16 ? buildCount0x11Packet(sess, a.count, sess.addr16) : null,
      // op06 member-JOIN delta: an EXISTING member sees the new joiner (the live-draw vehicle).
      [lobbyEngine.K.MEMBER_JOIN]: (sess, a) => buildMemberJoinOp06Packet(sess, a.id, a.name),
      // op07 member-LEAVE delta: each SURVIVOR removes the leaver (SPINE-3 survivor-notify, slot 6).
      // Host departure = the SAME op07 (K.NV_CANCEL_NOTIFY aliases K.MEMBER_LEAVE) -> one builder.
      [lobbyEngine.K.MEMBER_LEAVE]: (sess, a) => buildMemberLeaveOp07Packet(sess, a.id),
      // ROOMLIST_DIRTY = "re-derive on next pull" marker, no proactive wire push -> null (no-op).
      [lobbyEngine.K.ROOMLIST_DIRTY]: () => null,
    },
    send: (sess, packet) => {
      if (!sess.addr16 || !sess.rinfo) return;
      sendSnapPacket(sess, packet, sess.rinfo, () => {});
      sess.outCount++; sess.totalOut += packet.length;
    },
    log: (line) => console.error(line),
  });
  return _engineAdapter;
}
const ROOM_ENGINE_ON = () => process.env.SNAP_ROOM_ENGINE === '1';

const PORT = 9090;
const ACCOUNTS_PATH = path.join(__dirname, 'accounts.json');

// Body placement on the wire. Codex EE-struct analysis (analysis/snap-packet-struct.md)
// established that FUN_001d9678 decrypts from packet+0x3c, which maps to raw wire
// offset 0x10 (not 0x3c — the older "0x3c" hypothesis confused internal packet-object
// offset with wire offset). 2026-05-17 PINE dump at FUN_001d9678 entry confirmed
// packet+0x3c held zeros while we were writing ciphertext at wire 0x3c — proving
// the EE was reading nothing usable. Default both env vars to the corrected values.
const BODY_OFFSET = parseInt(process.env.SNAP_REGISTER_BODY_OFFSET || '0x10', 16);
const BODY_LEN    = parseInt(process.env.SNAP_REGISTER_BODY_LEN    || '0x80', 16);
if (BODY_LEN % 8 !== 0) throw new Error(`SNAP_REGISTER_BODY_LEN must be multiple of 8 (got 0x${BODY_LEN.toString(16)})`);
const NAMEDSLOT_WORD0 = Math.max(0, Math.min(0xffff, parseInt(process.env.SNAP_NAMEDSLOT_WORD0 || '0xffff', 0)));

// Cache account lookups (small file, but no need to re-read every datagram)
let _accountsCache = null;
let _accountsMtime = 0;
function getPasswordForHandle(handle) {
  try {
    const st = fs.statSync(ACCOUNTS_PATH);
    if (st.mtimeMs !== _accountsMtime) {
      _accountsCache = JSON.parse(fs.readFileSync(ACCOUNTS_PATH, 'utf8'));
      _accountsMtime = st.mtimeMs;
    }
    return _accountsCache?.[handle]?.password || null;
  } catch { return null; }
}

// FUN_001d9678 decrypts REGISTER-OK with key=state+0x484 and
// key_len=strlen(state+0x484). 2026-05-17 PINE dumps showed this buffer is the
// typed password string, e.g. "12345678" or "1234567890", not the request auth
// string. Use the full non-NUL password by default; keep narrower modes only
// for diagnostics.
function blowfishKeyForRegister(decoded) {
  const pw = getPasswordForHandle(decoded?.handle || '');
  const keyMode = process.env.SNAP_REGISTER_KEY || 'password';
  if (keyMode === 'auth') {
    return decoded?.auth ? Buffer.from(decoded.auth, 'latin1') : null;
  }
  if (!pw) return null;
  if (keyMode === 'password8') {
    return Buffer.from(pw.slice(0, 8), 'latin1');
  }
  if (keyMode === 'password40') {
    const key = Buffer.alloc(40);
    Buffer.from(pw.slice(0, 40), 'latin1').copy(key, 0);
    return key;
  }
  return Buffer.from(pw.slice(0, 40), 'latin1');
}

function bswapCipherWords(buf) {
  const out = Buffer.alloc(buf.length);
  for (let i = 0; i < buf.length; i += 4) {
    out[i + 0] = buf[i + 3];
    out[i + 1] = buf[i + 2];
    out[i + 2] = buf[i + 1];
    out[i + 3] = buf[i + 0];
  }
  return out;
}

function encryptEeBlowfishBody(plain, key) {
  const swapMode = process.env.SNAP_REGISTER_SWAP || 'none';
  const cipherMode = process.env.SNAP_REGISTER_CIPHER || 'encrypt';
  const input = (swapMode === 'plain' || swapMode === 'both') ? bswapCipherWords(plain) : plain;
  const bf = new Blowfish(key);
  const ctBE = cipherMode === 'decrypt' ? bf.decryptECB(input) : bf.encryptECB(input);
  const ctLE = (swapMode === 'cipher' || swapMode === 'both') ? bswapCipherWords(ctBE) : ctBE;
  return {
    ctBE,
    ctLE,
  };
}
const ACTIVE_ROOT = path.resolve(__dirname, '..');
const CAPTURES_DIR = path.join(ACTIVE_ROOT, 'captures', 'udp9090');
if (!fs.existsSync(CAPTURES_DIR)) fs.mkdirSync(CAPTURES_DIR, { recursive: true });

// ── Automated PINE snapshots around the slot-19 push ────────────────────────
// Fires at PRE-PUSH, POST-PUSH+50/200/1000ms, and POST-GAME-ACK so we can see
// transient state changes (e.g. slot-0x19 entry appearing/disappearing) without
// the user having to race PCSX2 with manual dumps. Files land in
// .codex/captures/slot19_snapshots/ so Codex can grab them via the junction.
const SLOT19_SNAPSHOT_DIR = path.join(ACTIVE_ROOT, '.codex', 'captures', 'slot19_snapshots');
if (!fs.existsSync(SLOT19_SNAPSHOT_DIR)) fs.mkdirSync(SLOT19_SNAPSHOT_DIR, { recursive: true });
const NAMEDSLOT_DIAG_DIR = path.join(ACTIVE_ROOT, '.codex', 'captures', 'namedslot_diag');
if (!fs.existsSync(NAMEDSLOT_DIAG_DIR)) fs.mkdirSync(NAMEDSLOT_DIAG_DIR, { recursive: true });

const SNAPSHOT_ADDRESSES = [
  ['state base ptr',     0x0025b78c, 0x08],
  ['counter region',     0x007152e0, 0x20],
  ['helper 0x715268',    0x00715268, 0x10],  // 0x0061e910's last return value (signed byte at +0, full word at +0..+3)
  // State object at base = 0x0036d760. Capture full 0x800 to catch parsed
  // opcode 0x48 body wherever FUN_001d8c10 writes it (Codex didn't specify
  // exact offset). Includes +0x80 REGISTER state, +0x88 body-len seed,
  // +0x4f0..+0x51f retry timer, +0x548..+0x647 callback table, +0x60c slot 0x31.
  ['state+0x000..+0x7ff', 0x0036d760, 0x800],
  // Codex udp9090-named-slot-query-op48.md (initial analysis, demoted to "reused
  // globals" after the timed snapshot proved the 0x005bc990 callback path didn't
  // run for our word0=5+5 reply). Capture as-is to keep diff continuity.
  ['0x0087f7f8 reused', 0x0087f7f8, 0x10],
  ['0x0087f800 reused', 0x0087f800, 0x10],
  // Codex 2026-05-19 follow-up: new target after the timed snapshot showed the
  // actual named-slot-query consumer doesn't touch 0x0087f7f8. 0x003797a8..0x3797f8
  // is the data region Codex flagged as the likely real accumulator/session area.
  ['0x003797a8 session region', 0x003797a8, 0x50],  // 80 bytes
  // 2026-05-19: PINE-injected addresses (http_server.js auto-inject) — capture
  // each so Codex can map "which packet should make the game set this itself."
  // PINE injection now disabled; without it the game stalls at some flag check.
  // Snapshot shows which of these are zero (= the game didn't set them, that's
  // where the missing protocol response is).
  ['0x00870870 handle buf', 0x00870870, 0x20],   // userid string slot
  ['0x00701F28 flag pair',  0x00701F28, 0x10],   // includes +0x00 (=0x1A5DF?) and +0x08 (=1?)
  ['0x0029F280 flag',       0x0029F280, 0x04],
  ['0x0035A279 flag',       0x0035A279, 0x04],
];

let pineConn = null;
async function getPine() {
  if (pineConn) return pineConn;
  const c = new PineClient({ port: 28011, timeoutMs: parseInt(process.env.PINE_TIMEOUT_MS || '250', 0) });
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

async function runSnapshot(sessionFile, label, t0) {
  // DISABLED 2026-05-24 — these snapshots fired 5+ times per UDP event with
  // 50/200/500/1500/5000ms follow-ups, destabilizing PCSX2 (D901 / crashes).
  // Use tools/mem_watcher.js for passive memory diagnostics instead. To
  // re-enable for targeted tests, set env var UDP_SNAPSHOTS=1.
  if (process.env.UDP_SNAPSHOTS !== '1') return;
  const dt = t0 ? `[+${(Date.now() - t0).toString().padStart(5)}ms]` : '[       ]';
  const out = [`\n${dt} ${label}  ${new Date().toISOString()}`];
  let stateBuf = null;
  try {
    const pine = await getPine();
    for (const [name, addr, len] of SNAPSHOT_ADDRESSES) {
      out.push(`[${name}] 0x${addr.toString(16).padStart(8, '0')} (${len}b):`);
      try {
        const buf = await pine.readBytes(addr, len);
        out.push(...snapHexLines(buf, addr));
        if (name.startsWith('state+0x000')) stateBuf = buf;
      } catch (e) {
        out.push(`  read FAIL: ${e.message}`);
      }
    }
    // Dereference state+0x60c (callback slot 0x31 — per Codex's
    // udp9090-named-slot-query-op48.md update, this is the runtime callback
    // registered by FUN_001e094c that decides which record words drive
    // visibility) and dump the code page at that address.
    if (stateBuf && stateBuf.length >= 0x610) {
      const cb = stateBuf.readUInt32LE(0x60c);
      out.push(`\n[slot 0x31 deref] state+0x60c = 0x${cb.toString(16).padStart(8, '0')}`);
      if (cb >= 0x00100000 && cb < 0x02000000) {
        try {
          const codeBuf = await pine.readBytes(cb, 0x200);
          out.push(`[code page @ 0x${cb.toString(16).padStart(8, '0')}] (${codeBuf.length}b):`);
          out.push(...snapHexLines(codeBuf, cb));
        } catch (e) {
          out.push(`  code read FAIL: ${e.message}`);
        }
      } else {
        out.push(`  (pointer out of typical EE code range; skipping deref)`);
      }
    }
  } catch (e) {
    out.push(`  PINE FAIL: ${e.message}`);
    try { pineConn?.close(); } catch {}
    pineConn = null;
  }
  fs.appendFileSync(sessionFile, out.join('\n') + '\n');
}

function jsonHex(buf) {
  return Buffer.isBuffer(buf) ? buf.toString('hex') : null;
}

async function readDiagBytes(pine, addr, len) {
  try {
    return { addr: `0x${addr.toString(16).padStart(8, '0')}`, len, hex: jsonHex(await pine.readBytes(addr, len)) };
  } catch (e) {
    return { addr: `0x${addr.toString(16).padStart(8, '0')}`, len, error: e.message };
  }
}

function saneEePtr(ptr) {
  return Number.isFinite(ptr) && ptr >= 0x00100000 && ptr < 0x02000000;
}

let namedSlotDiagQueue = Promise.resolve();

function recordNamedSlotDiag(s, label, msg = null, reply = null) {
  // 2026-05-31: default OFF — this opens a persistent PineClient that hogs
  // the IPC socket and blocks our diagnostic probes. Set SNAP_NAMEDSLOT_DIAG=1
  // to re-enable for targeted investigation runs.
  if (process.env.SNAP_NAMEDSLOT_DIAG !== '1') return;

  const diagFile = s.namedSlotDiagFile || path.join(NAMEDSLOT_DIAG_DIR, `namedslot_diag_${s.key.replace(/[:.]/g, '_')}_${Date.now()}.jsonl`);
  s.namedSlotDiagFile = diagFile;
  const startedAt = s.namedSlotDiagT0 || Date.now();
  s.namedSlotDiagT0 = startedAt;
  if (!s.namedSlotDiagStarted) {
    s.namedSlotDiagStarted = true;
    fs.appendFileSync(diagFile, JSON.stringify({
      event: 'start',
      iso: new Date().toISOString(),
      key: s.key,
    }) + '\n');
  }

  namedSlotDiagQueue = namedSlotDiagQueue.catch(() => {}).then(async () => {
    const row = {
      event: 'sample',
      label,
      ms: Date.now() - startedAt,
      iso: new Date().toISOString(),
      inboundHex: msg ? msg.toString('hex') : null,
      replyHex: reply ? reply.toString('hex') : null,
      fields: {},
    };
    try {
      const pine = await getPine();
      let statePtr = 0;
      try {
        statePtr = await pine.read32(0x0025b78c);
      } catch (e) {
        throw new Error(`PINE statePtr read failed: ${e.message}`);
      }
      row.statePtr = `0x${statePtr.toString(16).padStart(8, '0')}`;
      row.fields.dat_0025b78c = await readDiagBytes(pine, 0x0025b78c, 0x08);
      row.fields.ntgui_007152e0 = await readDiagBytes(pine, 0x007152e0, 0x20);
      row.fields.reused_0087f7f8 = await readDiagBytes(pine, 0x0087f7f8, 0x10);
      row.fields.reused_0087f800 = await readDiagBytes(pine, 0x0087f800, 0x10);
      row.fields.namedslot_threshold_table_00365e00 = await readDiagBytes(pine, 0x00365e00, 0x80);
      row.fields.session_00374fa0 = await readDiagBytes(pine, 0x00374fa0, 0x80);
      row.fields.session_003797a8 = await readDiagBytes(pine, 0x003797a8, 0x80);
      row.fields.static_state_36d760_cb_table = await readDiagBytes(pine, 0x0036d760 + 0x548, 0x100);
      row.fields.static_state_36d760_cb31_window = await readDiagBytes(pine, 0x0036d760 + 0x5f0, 0x50);
      row.fields.static_state_36d760_full = await readDiagBytes(pine, 0x0036d760, 0x100);

      if (process.env.SNAP_NAMEDSLOT_DEEP === '1') {
        row.fields.namedslot_threshold_table_00365e00_deep = await readDiagBytes(pine, 0x00365e00, 0x800);
        row.fields.static_state_36d760_full_deep = await readDiagBytes(pine, 0x0036d760, 0x800);
      }

      const staticCb31 = row.fields.static_state_36d760_cb31_window.hex
        ? Buffer.from(row.fields.static_state_36d760_cb31_window.hex.slice((0x60c - 0x5f0) * 2, (0x60c - 0x5f0 + 4) * 2), 'hex').readUInt32LE(0)
        : 0;
      row.staticCb31 = `0x${staticCb31.toString(16).padStart(8, '0')}`;
      if (saneEePtr(staticCb31)) {
        const page = staticCb31 & ~0xfff;
        row.fields.static_cb31_page = await readDiagBytes(pine, page, 0x400);
        row.staticCb31Page = `0x${page.toString(16).padStart(8, '0')}`;
      }

      if (saneEePtr(statePtr)) {
        row.fields.ptr_state_cb_table = await readDiagBytes(pine, statePtr + 0x548, 0x100);
        row.fields.ptr_state_cb31_window = await readDiagBytes(pine, statePtr + 0x5f0, 0x50);
        const ptrWinHex = row.fields.ptr_state_cb31_window.hex;
        if (ptrWinHex) {
          const ptrCb31 = Buffer.from(ptrWinHex.slice((0x60c - 0x5f0) * 2, (0x60c - 0x5f0 + 4) * 2), 'hex').readUInt32LE(0);
          row.ptrCb31 = `0x${ptrCb31.toString(16).padStart(8, '0')}`;
          if (saneEePtr(ptrCb31)) {
            const page = ptrCb31 & ~0xfff;
            row.fields.ptr_cb31_page = await readDiagBytes(pine, page, 0x400);
            row.ptrCb31Page = `0x${page.toString(16).padStart(8, '0')}`;
          }
        }
      }
    } catch (e) {
      row.error = e.message;
      try { pineConn?.close(); } catch {}
      pineConn = null;
    } finally {
      fs.appendFileSync(diagFile, JSON.stringify(row) + '\n');
    }
  });
}

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

function readAsciiAt(buf, off, len) {
  const end = Math.min(off + len, buf.length);
  let s = '';
  for (let i = off; i < end; i++) {
    if (buf[i] === 0) break;
    if (buf[i] < 0x20 || buf[i] >= 0x7f) break;
    s += String.fromCharCode(buf[i]);
  }
  return s;
}

function decodePacket(buf) {
  if (buf.length < 0x10) return { kind: 'too-short', len: buf.length };
  return {
    kind: buf.length === 154 ? 'login' : 'unknown',
    len: buf.length,
    who: buf[0],
    qsw: buf[1],
    cmd: buf.readUInt16BE(2),
    srcPort: buf.length >= 8 ? buf.readUInt16BE(6) : null,
    handle: readAsciiAt(buf, 0x10, 16),
    auth: readAsciiAt(buf, 0x38, 16),
  };
}

// Per-session state (keyed by ip:port)
const sessions = new Map();

function getSession(rinfo) {
  const key = `${rinfo.address}:${rinfo.port}`;
  if (!sessions.has(key)) {
    sessions.set(key, {
      key,
      t0: Date.now(),
      lastSeen: Date.now(),
      inCount: 0,
      outCount: 0,
      totalIn: 0,
      totalOut: 0,
      ackStrategy: 'snap-register-reply',  // decompile-verified (EE FUN_001d72a8)
      logFile: path.join(CAPTURES_DIR, `${RUN_ID}_udp_${key.replace(/[:.]/g, '_')}.log`),
    });
    const s = sessions.get(key);
    log(s, `\n${'='.repeat(70)}\n[udp ${key}] NEW SESSION  t0=${new Date().toISOString()}`);
  }
  const s = sessions.get(key);
  s.lastSeen = Date.now();
  return s;
}

// Disconnect lifecycle (engine foundation, RF-1/RF-4/RF-5, 2026-07-18).
// The authoritative model (lobby_state) is only as live as its cleanup. In-room UDP sessions send op41
// every ~5s (RF-4 rig), so a stale in-room session (> SNAP_LIVENESS_TIMEOUT_MS, default 20s) = a real
// disconnect -> remove it from the model NOW (leaveRoom drops membership+count; removeEndpoint clears
// the endpoint). Lobby/menu sessions have NO persistent keepalive (RF-5: silent for minutes at
// server-select) so they must NEVER be fast-reaped — they keep the long 5-min TTL.
// Gated on SNAP_LIVENESS_REAP=1; OFF = the legacy 5-min-TTL-only behavior (unchanged). Rollback-safe.
const LIVENESS_REAP = () => process.env.SNAP_LIVENESS_REAP === '1';
const LIVENESS_TIMEOUT_MS = Math.max(10_000, Number(process.env.SNAP_LIVENESS_TIMEOUT_MS) || 20_000);
setInterval(() => {
  const now = Date.now();
  for (const [k, s] of sessions) {
    const stale = now - s.lastSeen;
    const p = LOBBY_STATE_ON() ? lobbyState.playerByEndpoint(k) : null;
    // Fast in-room liveness disconnect — SAFE only because an in-room client keepalives every ~5s.
    if (LIVENESS_REAP() && p && p.room && stale > LIVENESS_TIMEOUT_MS) {
      log(s, `[udp ${k}] LIVENESS disconnect (in-room ${Math.round(stale / 1000)}s stale > ${LIVENESS_TIMEOUT_MS / 1000}s) -> leaveRoom + removeEndpoint`);
      // 2026-07-19 SPINE-3: a disconnect/timeout is the SAME membership-leave as a graceful op07 — the
      // survivors must be notified identically. Under SNAP_ROOM_ENGINE the ENGINE owns it: onLivenessTimeout
      // -> leaveRoom does the single lobby_state mutation AND returns the op07->op0a->count plan, which
      // engineAdapter executes BEFORE removeEndpoint (so survivors still resolve). Legacy path (engine OFF)
      // keeps the raw lobbyState.leaveRoom with no survivor emit.
      try {
        if (ROOM_ENGINE_ON()) {
          const res = lobbyEngine.onLivenessTimeout(k);
          const sum = engineAdapter().execute(res.plan, 'reap');
          console.error(`[engine] REAP ${k} (timeout) -> plan sent=${sum.sent} ${JSON.stringify(sum.byKind)}`);
        } else {
          lobbyState.leaveRoom(k);
        }
      } catch { /* best-effort */ }
      lobbyState.removeEndpoint(k);
      if (s.kaTimer) clearInterval(s.kaTimer);
      sessions.delete(k);
      continue;
    }
    // Long TTL for lobby/menu sessions and as the universal fallback.
    if (stale > 5 * 60 * 1000) { if (s.kaTimer) clearInterval(s.kaTimer); sessions.delete(k); if (LOBBY_STATE_ON()) lobbyState.removeEndpoint(k); }
  }
}, 5_000).unref();

// 2026-07-06 G11 (server scale): SNAP_LEAN_HOTPATH=1 makes per-message logging a no-op.
// At 100s of connections x ~25/s op48, the synchronous console.log + fs.appendFileSync
// per message (5+/op48) blocks the event loop and fills disk (load-test knee ~10 clients).
// Default OFF = full verbose logs for debugging (1-2 clients); turn ON for load/production.
const LEAN_HOTPATH = process.env.SNAP_LEAN_HOTPATH === '1';
function log(s, line) {
  if (LEAN_HOTPATH) return;
  console.log(line);
  fs.appendFileSync(s.logFile, line + '\n');
}

// 2026-07-02: per-packet file dumps are DEFAULT OFF (SNAP_SAVE_PACKETS=1 to re-enable). They filled
// the Pi SD card twice (ENOSPC -> the "DNAS 50%" false crash) at ~130k files. The harness already
// records a full local pcap and the journal logs every packet's hex, so these files are redundant.
function save(tag, buf) {
  if (process.env.SNAP_SAVE_PACKETS !== '1') return;
  const t = Date.now();
  const base = path.join(CAPTURES_DIR, `${RUN_ID}_udp_${tag}_${t}`);
  fs.writeFileSync(base + '.bin', buf);
  fs.writeFileSync(base + '.txt',
    `Tag : ${tag}\nTime: ${new Date().toISOString()}\nBytes: ${buf.length}\n\n${hex(buf)}\n`);
}

/**
 * Build the ACK we send back to the game.
 *
 * Strategy `snap-register-reply` (default, 2026-05-16) is derived from main EE
 * decompile of FUN_001d72a8 (SN@P recv parser in ghidra_pal_ee). See
 * captures/udp9090_findings.md for full analysis.
 *
 * Key parser checks the response must satisfy:
 *   - first ushort = 0xB096 (kind 0xB000 = REL flag set + ACK piggyback,
 *                            low 10 bits of length 0x096)
 *   - opcode byte at +3  = 0x1c (the slot armed by sender's
 *                                FUN_001d4d24(1, 0x1c, callback))
 *   - server IP echo at certain header offset (preserved by copying request)
 *   - server port echo = bswap16(9090) = 0x8223 (preserved by copying request)
 *   - body length â‰¥ 0x14
 *   - last 4 bytes of body = `ba 47 66 ??` (wire order) â€” the hard-coded
 *     0xba476600 trailer magic the recv parser bitwise-rotates and compares
 *
 * Request bytes 0x96..0x99 are already `ba 47 66 11` (the request's TLV
 * session token tail happens to match the trailer pattern). By mirroring the
 * request and only flipping bytes 0..3 to `B0 96 00 1c`, all echoed fields
 * including the trailer remain valid.
 */
function buildRegisterOkBody(msg, decoded) {
  // Plaintext consumed by FUN_001d9678 after Blowfish-decrypt. body+0x00 must
  // strcmp equal state+0x4ac, which the live PINE dump (2026-05-17) showed
  // contains the typed handle ("12345" for the test account) — NOT zeros as
  // earlier idle probes suggested. So block 0 = handle padded to 8 bytes makes
  // strcmp pass: decrypt yields "12345\0\0\0", strcmp("12345", "12345") == 0.
  const body = Buffer.alloc(BODY_LEN);
  Buffer.from((decoded.handle || '').slice(0, 39), 'latin1').copy(body, 0);
  const host = (process.env.SNAP_REGISTER_HOST || HOST_IP)
    .split('.')
    .map(n => Number.parseInt(n, 10) & 0xff);
  if (host.length === 4) Buffer.from(host).copy(body, 0x28);
  body.writeUInt32BE(0, 0x2c);       // session field stored to state+0x504
  body.writeUInt32BE(PORT, 0x30);    // parsed as port 2000 from bytes 2..3
  body.writeUInt32BE(0, 0x34);       // tail length → memcpy(state+0xac, plain+0x3c, 0) no-op
  body.writeUInt32BE(0, 0x38);       // session field stored to state+0x508
  return body;
}

function buildAck(strategy, msg, decoded = {}, ctx = {}) {
  if (strategy === 'named-slot-query-reply') {
    // Codex udp9090-named-slot-query-op48.md: structured opcode 0x48 response
    // with N 0x24-byte records. FUN_001d81a4 byte-swaps record words 0..4
    // (offsets +0x10..+0x23); first 16 bytes of each record are an untouched
    // ID/string buffer.
    //
    // Inbound packet carries NAME-key entries (4 NAME + 1 flag + 16 value,
    // 21 bytes each, count at offset 0x14, entries start at 0x18). Echo each
    // queried ID back as a record so the game sees the slots it asked about.
    //
    // Wire layout (variable, based on entry count):
    //   [4]   b0 <qsw> 00 48              REL+ACK, qsw = body length (excl. 4-byte header)
    //   [12]  msg[0x04..0x0f]              session mirror
    //   [4]   request_id                   mirrored from inbound 0x10..0x13
    //   [4]   status/reserved              0
    //   [4]   record_count
    //   [N*36] records: 16-byte name + 5×BE u32 (word0..word4)
    //   [4]   ba 47 66 11                  trailer
    const entryCount = msg[0x14] || 0;
    const entries = [];
    for (let i = 0; i < entryCount; i++) {
      const eoff = 0x18 + i * 21;
      if (eoff + 21 > msg.length - 4) break;
      // 0..3 = "NAME", 4 = flag (D=0x44, F=0x46), 5..20 = value buffer
      let valEnd = eoff + 5;
      while (valEnd < eoff + 21 && msg[valEnd] !== 0) valEnd++;
      const value = msg.slice(eoff + 5, valEnd).toString('latin1');
      entries.push({ flag: msg[eoff + 4], value });
    }
    // Fallback if parsing produced nothing — keep zero-count working baseline.
    if (entries.length === 0) entries.push({ flag: 0, value: 'SLOT0001' });

    // AREA-SELECT activation (SNAP_AREA_OP48=1). The area-select op48 "NAME" query
    // reply is consumed by overlay FUN_005c1220: it parses the LAST TWO chars of each
    // record's 16-byte name as a decimal id (1..10 -> box 0..9), then writes the area
    // blob status byte (+0x14c, via FUN_005c2ab0) into the menu display table at
    // 0x6ce5f0+box*0x144 — un-greying that box. Enumerating only one entry leaves the
    // other 9 boxes at the greyed init (0), so emit N records whose names end in
    // "01".."N" to activate all N boxes. Requires the area blob +0x14c to be non-zero
    // (SNAP_AREA_STATUS in snap_server.js) or the copied status stays greyed.
    // Evidence: AREA-LOBBY-FIELD-MAP-EVIDENCE-2026-06-30.md §2d; FUN_005c1220 in
    // analysis/claude-helper-module-full-2026-05-29.txt.
    // NOTE: one frame holds at most 6 records — the wire length is a single byte (qsw=[1]),
    // so body (12+12+N*0x24+4) must stay <=255 => N<=6. Activating all 10 boxes needs a
    // multi-frame delivery (future work); for now enumerate up to 6 to prove the model.
    // T11 EVIDENCE FIX (per-box PINE 2026-07-02): the AREA substitution must cover the WHOLE
    // area-select phase (before area-confirm), not just the 0xF0 connect query. Root cause of the
    // "only Free + No Healing selectable" regression: the game's ongoing op48 poll arrives as 0xB0
    // DURING area-select and was falling to the T6 ECHO path (SNAP_OP48_REPLY_ALL). Its echoed
    // values "...12101"/"...12110" parse (FUN_005c1220) to ids 1 and 10 -> un-grey ONLY box0 (Free)
    // and box9 (No Healing), overwriting the AREA0001-06 six-box result. PINE box statuses:
    // box0=3, box9=3, all others 0 = exactly ids 1 and 10. Fix: substitute AREA for op48 while
    // s.sawAreaConfirm is false (area-select), regardless of kind; only AFTER area-confirm (lobby)
    // do we echo the queried values (the room-list path). ctx.sawAreaConfirm passed by the caller.
    if (process.env.SNAP_AREA_OP48 === '1' && (msg[0] === 0xF0 || ctx.sawAreaConfirm === false)) {
      // T12: activate ALL n boxes (n up to 10). One op48 reply holds <=6 records (wire length is a
      // single byte). FUN_005c1220 un-greys box (id-1) per record and ACCUMULATES across replies
      // without re-greying (proven: 6 boxes stayed stable over 118 polls), so we split >6 boxes
      // across successive polls: frame A = ids 1..6, frame B = ids 7..n. The caller alternates via
      // ctx.areaOp48Frame (per-session counter), so over 2 polls all n boxes activate. n<=6 => single
      // frame (unchanged). SNAP_AREA_OP48_COUNT default 6; set 10 to light all boxes.
      // T13: all n boxes in ONE reply (replies don't accumulate — PINE: alternating frames left
      // 6-9 greyed while 0-5 stayed stable; only one answer takes effect). The 6-record cap was a
      // WRONG-LENGTH artifact: the frame length is the low 10 bits of wire[0..1] (L1 spec §1.1),
      // so >255 body needs the high 2 bits in reply[0] (fixed below), NOT an 8-bit cap.
      const n = Math.max(1, Math.min(10, parseInt(process.env.SNAP_AREA_OP48_COUNT || '6', 10)));
      entries.length = 0;
      for (let i = 1; i <= n; i++) {
        // name MUST end in a 2-digit decimal id; FUN_005c1220 reads name[strlen-2..strlen-1].
        entries.push({ flag: 0, value: `AREA00${String(i).padStart(2, '0')}` });
      }
    }

    const recordCount = entries.length;
    const bodyLen = 12 + 12 + recordCount * 0x24 + 4;  // mirror + meta + records + trailer
    const totalLen = 4 + bodyLen;

    const reply = Buffer.alloc(totalLen);
    // Wire header: wire[0..1] BE u16 = flags(6 bits) | length(low 10 bits) (L1 spec §1.1,
    // decompile-verified). who 0xB0 = flags; length = bodyLen. For bodyLen>255 the high 2 length
    // bits go in reply[0]'s LOW 2 bits (0xB0 has them clear) — NOT reply[2] (opcode high; writing
    // length there corrupts 0x0048->0x0148, the 2026-07-01 regression). reply[2..3]=cmd 0x0048.
    // Verified: 6 recs => body 244 => b0 f4 (unchanged); 10 recs => body 388 => b1 84.
    reply[0] = 0xB0 | ((bodyLen >> 8) & 0x03); reply[1] = bodyLen & 0xff; reply[2] = 0x00; reply[3] = 0x48;
    msg.copy(reply, 4, 4, 16);                  // session mirror (wire 0x04..0x0f)
    msg.copy(reply, 0x10, 0x10, 0x14);          // request_id
    // SEQ FIX (snap-seq-field-spec-2026-06-11.md): wire 0x08 is the reliable
    // server->client sequence. The mirror above copied the inbound (client->server)
    // seq into 0x08 → out-of-window → client ACKs but never DELIVERS. Stamp our
    // next-expected server->client seq instead so FUN_005bc990 actually runs.
    if (typeof ctx.txSeq === 'number') {
      ctx.seqWas = msg.readUInt32BE(0x08);
      reply.writeUInt32BE(ctx.txSeq >>> 0, 0x08);
    }
    reply.writeUInt32BE(0, 0x14);                // status
    reply.writeUInt32BE(recordCount, 0x18);      // record_count

    for (let i = 0; i < recordCount; i++) {
      const roff = 0x1C + i * 0x24;
      Buffer.from(entries[i].value, 'latin1').copy(reply, roff);  // 16-byte name (rest zero-pad)
      // BIN\3.DAT overlay callback at 0x005bc990 reads only lhu(record+0x10)
      // after byte-swap and accumulates it into 0x0087f7f8. It compares the sum
      // against FUN_005c5060(lhu(0x0087f800)), which is a table-derived value.
      // Default high until the diag table read gives us the exact threshold.
      reply.writeUInt32BE(NAMEDSLOT_WORD0, roff + 16);   // word0 aggregate contribution
      reply.writeUInt32BE(0, roff + 20);   // word1 — not read
      reply.writeUInt32BE(0, roff + 24);   // word2 — not read
      reply.writeUInt32BE(0, roff + 28);   // word3 — not read
      reply.writeUInt32BE(0, roff + 32);   // word4 — not read
    }
    const trailerOff = 0x1C + recordCount * 0x24;
    reply[trailerOff] = 0xba; reply[trailerOff+1] = 0x47;
    reply[trailerOff+2] = 0x66; reply[trailerOff+3] = 0x11;

    ctx.parsedDebug = `entries=${recordCount} word0=${NAMEDSLOT_WORD0}: ${entries.map(e => `${String.fromCharCode(e.flag||0x2D)}:${e.value}`).join(', ')}`;
    return reply;
  }
  if (strategy === 'post-register-bind-ack') {
    // 20-byte reliable-transport ACK for post-REGISTER kind-0x31 packets.
    // Shape per Codex's post-register-op01.md analysis: 60 10 00 00 + mirror of
    // inbound bytes 0x04..0x0f + ba 47 66 11 trailer.
    const ack = Buffer.alloc(20);
    ack[0] = 0x60; ack[1] = 0x10; ack[2] = 0x00; ack[3] = 0x00;
    msg.copy(ack, 4, 4, 16);
    // 2026-07-01 SNAP_RELIABLE_ACK: for RELIABLE inbound (msg[0]&0x80, e.g. the 0xF0 op48
    // named-slot-query) the bytes-4..16 mirror puts the game's own cumulative-ack value at
    // +0x0c — which frees NOTHING (FUN_001e1ac8 matches the sender id = inbound wire+0x08).
    // Correct the ack fields so the game's op48 is actually freed from its conn+0x520 pool.
    // Non-reliable kinds (0x31 post-register-bind, 0x32 post-lobby-snap) keep the mirror.
    const bindAckOps = process.env.SNAP_ACK_OPS || (process.env.SNAP_RELIABLE_ACK === '1' ? 'all' : '');
    if ((bindAckOps.trim().toLowerCase() === 'all' || bindAckOps.split(',').some(x => parseInt(x.trim(), 16) === 0x48))
        && (msg[0] & 0x80) && msg.length >= 0x10) {
      ack.writeUInt32BE(0, 0x08);                          // no reverse data
      ack.writeUInt32BE(msg.readUInt32BE(0x08), 0x0c);     // ack the game's send id
    }
    ack[16] = 0xba; ack[17] = 0x47; ack[18] = 0x66; ack[19] = 0x11;
    return ack;
  }
  if (strategy === 'slot1c-status-push') {
    // Per Codex's analysis/slot1c-route-op28.md: live slot 0x1c (state+0x5b8) →
    // 0x00626730 (the NTGUI status callback). Dispatcher case 0x25 (= opcode
    // 0x28 - 3) parses body via FUN_001d7f6c (bswap32 on body[0..1]), then
    // switch(body[0] - 1) → case 0 → call slot 0x1c.
    //
    // Body selector = 1 (wire body[0..3] = 00 00 00 01 LE → bswap → 0x00000001).
    // Callback at 0x00626730 receives metadata byte 0 → normal path →
    // increments 0x007152e1.
    const push = Buffer.alloc(0x1C);      // 28 bytes total: 16 header + 8 body + 4 trailer
    push[0] = 0xB0;                       // flags 0xb000 (REL+ACK)
    push[1] = 0x18;                       // length flag low = body_len(0x08) + 0x10
    push[2] = 0x00;                       // opcode high
    push[3] = 0x28;                       // opcode 0x28 → dispatcher case 0x25 → slot 0x1c (after selector match)
    msg.copy(push, 4, 4, 16);             // mirror session/seq from inbound bytes 0x04..0x0f
    // body bytes 0x10..0x17: selector 1 + zeros
    push[0x10] = 0x00; push[0x11] = 0x00; push[0x12] = 0x00; push[0x13] = 0x01;
    push[0x14] = 0x00; push[0x15] = 0x00; push[0x16] = 0x00; push[0x17] = 0x00;
    push[0x18] = 0xba; push[0x19] = 0x47; push[0x1a] = 0x66; push[0x1b] = 0x11;
    return push;
  }
  if (strategy === 'room-enter-reply-a0' || strategy === 'member-list-reply-a0') {
    // 2026-06-16 ROOM RENDER (subagents room-render-exact-sequence + snap-transport-delivery-contract).
    // Answer the game's reliable op-6 (room-enter) / op-10 (member-list) requests so the post-join
    // render machine runs. THE FIX: wire byte0 must be 0xA0 (flags 0x8000 reliable + 0x2000, DATA bit
    // 0x1000 CLEAR). byte0=0xB0 (every prior attempt) sets DATA → dispatcher FUN_001d9f78 cases 5/9
    // route the reply to dead slots conn+0x5cc/0x5ac; only DATA-clear reaches conn+0x5d0=FUN_005c05c0
    // (arms 0x6ff2b1) / conn+0x5a8=FUN_005c0ae0 (fills member table 0x6cdbe6).
    // Flags|length: BE u16 at wire+0; low 10 bits = (wireLen) = total-4 (trailer excluded); byte0 high
    // 6 bits = flags, low 2 bits = length bits 8-9. Reliable seq at wire+0x08 (BE) MUST = the EE recv
    // base and increment +1 per reliable DATA (ctx.txSeq, monotonic s.txSeqNext).
    const mkHdr = (p, total, opcode) => {
      const wireLen = (total - 4) & 0x3ff;
      p[0] = 0xA0 | ((wireLen >> 8) & 0x03);   // DATA CLEAR; +length hi bits
      p[1] = wireLen & 0xff;
      p[2] = 0x00; p[3] = opcode & 0xff;       // opcode 0x28 (BE u16 = 0x0028, &0x7f = 0x28)
      msg.copy(p, 4, 4, 16);                    // mirror token (+ seq, overwritten below if txSeq set)
      if (ctx && ctx.txSeq !== undefined) p.writeUInt32BE(ctx.txSeq >>> 0, 0x08);
      p[total - 4] = 0xba; p[total - 3] = 0x47; p[total - 2] = 0x66; p[total - 1] = 0x11;
    };
    if (strategy === 'room-enter-reply-a0') {
      // body0=6 (BE) → dispatcher case 5 → FUN_005c05c0(*param_1==0) → 0x6ff2b1=1,0x6ff2b2=1.
      const total = 0x24;                       // 16 hdr + 16 body + 4 trailer
      const p = Buffer.alloc(total);
      mkHdr(p, total, 0x28);
      p.writeUInt32BE(0x00000006, 0x10);        // body[0] = 6
      if (ctx) ctx.parsedDebug = 'room-enter A0 op28 body0=6 (arm 0x6ff2b1)';
      return p;
    }
    // member-list reply: body0=0x0a (BE) → dispatcher case 9 → FUN_005c0ae0 fills 0x6cdbe6.
    // body[8]=entryCount(LE=1); entry@body+0x0c: name[16], ID[4 BE]@+0x10, stride[4]@+0x14=0x108,
    // blob[0xf0]@+0x18. (1 member = the local host/player.)
    const memberId = (ctx && ctx.memberId) || (decoded && decoded.handle) || 'PLAYER1';
    const total = 0x10 + 0x0c + 0x108 + 4;      // hdr + (body0,body1,count) + (entry 0x108) + trailer
    const p = Buffer.alloc(total);
    mkHdr(p, total, 0x28);
    p.writeUInt32BE(0x0000000A, 0x10);          // body[0] = 0x0a
    p.writeUInt32LE(0x00000001, 0x18);          // body[8] = entryCount = 1 (native LE; case 9 no-bswap)
    Buffer.from(String(memberId)).copy(p, 0x1c, 0, 16);          // entry+0x00 name[16]
    p.writeUInt32BE(0x00000001, 0x2c);          // entry+0x10 member ID (BE for FUN_005c50a0); placeholder
    p.writeUInt32LE(0x00000108, 0x30);          // entry+0x14 stride delta = 0x108
    // entry+0x18 .. blob[0xf0] left zero (cosmetic)
    if (ctx) ctx.parsedDebug = `member-list A0 op28 body0=0x0a count=1 id="${memberId}"`;
    return p;
  }
  if (strategy === 'slot1c-status-push-cmd27') {
    // 2026-05-25 (Codex overnight decompile): post-op48 variant. Same slot 0x1c,
    // same selector 1, but command byte 0x27 instead of 0x28. Per Codex's
    // analysis/post-op48-push-candidates-2026-05-25.md:
    //   - FUN_001d9f78 routes cmd=0x27 into the nested selector dispatcher with
    //     callback-header byte cStack_40 = 0x27 (vs 0x28 for the proven push).
    //   - FUN_001d94b0 and FUN_001d9550 reset paths synthesize header byte 0x27
    //     before calling slot 0x1c, so the live slot 0x1c callback at 0x00626730
    //     is wired to expect 0x27 for the "real" inbound, not 0x28.
    //   - The cmd=0x28 push reaches slot 0x1c (transport-ACKed) but likely
    //     takes a different callback branch internally → no phase advance.
    // Status byte is the second u32 body word; env-configurable for probes.
    // Codex suggests trying 0x00 first, then 0x13 and 0x14 as controlled negatives.
    const status = Math.max(0, Math.min(0xff, parseInt(process.env.SNAP_POST_OP48_STATUS || '0x00', 0)));
    const push = Buffer.alloc(0x1C);
    push[0] = 0xB0;
    push[1] = 0x18;
    push[2] = 0x00;
    push[3] = 0x27;                       // cmd=0x27 (per Codex: synthesized header byte for slot 0x1c)
    msg.copy(push, 4, 4, 16);
    push[0x10] = 0x00; push[0x11] = 0x00; push[0x12] = 0x00; push[0x13] = 0x01;  // selector=1 BE
    push[0x14] = 0x00; push[0x15] = 0x00; push[0x16] = 0x00; push[0x17] = status & 0xff;
    push[0x18] = 0xba; push[0x19] = 0x47; push[0x1a] = 0x66; push[0x1b] = 0x11;
    if (ctx) ctx.parsedDebug = `cmd=0x27 selector=1 status=0x${status.toString(16)}`;
    return push;
  }
  if (strategy === 'snap-register-reply' && msg.length >= 0x44) {
    const a = Buffer.from(msg);
    a[0] = 0xB0;                    // kind=0xB000 (REL|ACK) | length top bits
    a[1] = 0x96;                    // length low byte: MUST mirror request (= wire_size - 4 = 0x96 for 154-byte reply).
                                    // 2026-05-17: changing this to (BODY_LEN+0x10)=0x90 made the handler stop running
                                    // entirely (state+0x80 stuck at 1, no error fired). Transport layer validates the
                                    // SN@P length field against the wire envelope. EE still decrypts (0x96-0x10)=0x86
                                    // bytes from packet+0x3c, but Blowfish ECB only processes the 16 full blocks
                                    // (= our BODY_LEN=0x80 of ciphertext); trailing 6 bytes don't affect strcmp.
    a[2] = 0x00;                    // opcode high
    a[3] = 0x2d;                    // opcode 0x2d = REGISTER-OK â†’ FUN_001d9678
                                    // which Blowfish-decrypts from packet+0x3c
                                    // (= wire 0x10) and strcmps against state+0x4ac.

    // Trailer stays at wire 0x96..0x99 from the request mirror (validated by
    // FUN_001d72a8). With BODY_LEN=0x80 ciphertext spans wire 0x10..0x8f,
    // leaving 0x90..0x95 as harmless mirror bytes between body and trailer.
    const key = blowfishKeyForRegister(decoded);
    if (key) {
      const plain = buildRegisterOkBody(msg, decoded);
      const { ctBE, ctLE } = encryptEeBlowfishBody(plain, key);
      ctLE.copy(a, BODY_OFFSET, 0, ctLE.length);
      ctx.cipherDebug = `variant keyMode=${process.env.SNAP_REGISTER_KEY || 'password'} cipher=${process.env.SNAP_REGISTER_CIPHER || 'encrypt'} swap=${process.env.SNAP_REGISTER_SWAP || 'none'} key=${key.toString('hex')} bodyWireOff=0x${BODY_OFFSET.toString(16)} bodyLen=0x${BODY_LEN.toString(16)} plain=${plain.toString('hex')} ctBE=${ctBE.toString('hex')} ctLE=${ctLE.toString('hex')}`;
    } else {
      ctx.cipherDebug = `no auth key for handle "${decoded.handle}" auth="${decoded.auth}" - body not encrypted (strcmp WILL fail)`;
    }
    return a;
  }
  const a = Buffer.from(msg);
  switch (strategy) {
    case 'bioserv-server-tell':
      a[0] = 0x28; a[1] = 0x02;
      return a;
    case 'mirror-set-byte0-18':
      a[0] = 0x18; a[1] = 0x02;
      return a;
    case 'mirror-plain':
      return a;
    case 'header-only-ack':
      return Buffer.from(msg.slice(0, 12));
    default:
      return a;
  }
}
const STRATEGY_ORDER = ['snap-register-reply', 'bioserv-server-tell', 'mirror-plain', 'mirror-set-byte0-18'];

// 2026-06-19 TRANSPORT FIX (snap-session-state-paren-trigger): every reliable-DATA push (0x8000 set)
// must carry a contiguous in-order seq = the EE recv base, +1 per push. register-reply is seq 0
// (= the request's seq) and resets the counter; everything after consumes nextTxSeq contiguously.
function nextTxSeq(s) {
  if (process.env.SNAP_REL_WINDOW === '1') {
    initRelWindow(s);
    const v = (s.relBase + s.relInflight.length + s.relReservations.length) >>> 0;
    s.relReservations.push(v);
    return v;
  }
  if (s.txSeqNext === undefined) s.txSeqNext = (((s.regReplySeq ?? -1) + 1) >>> 0);
  const v = s.txSeqNext >>> 0;
  s.txSeqNext = (s.txSeqNext + 1) >>> 0;
  return v;
}

function relWindowEnabled() {
  return process.env.SNAP_REL_WINDOW === '1';
}

function relWindowLimit() {
  const n = parseInt(process.env.SNAP_REL_WINDOW_SIZE || '32', 10);
  return Number.isFinite(n) && n > 0 ? n : 32;
}

function relRetransmitMs() {
  const n = parseInt(process.env.SNAP_REL_RETX_MS || '300', 10);
  return Number.isFinite(n) && n >= 50 ? n : 300;
}

function initRelWindow(s) {
  if (s.relInflight) return;
  const base = (s.regReplySeq !== undefined)
    ? ((s.regReplySeq + 1) >>> 0)
    : (s.txSeqNext !== undefined ? (s.txSeqNext >>> 0) : 0);
  s.relBase = base;
  s.relInflight = [];
  s.relReservations = [];
}

function resetRelWindow(s) {
  s.relBase = (s.regReplySeq !== undefined) ? ((s.regReplySeq + 1) >>> 0) : 0;
  s.relInflight = [];
  s.relReservations = [];
}

function isReliableDataPacket(buf) {
  return buf && buf.length >= 0x10 && (buf[0] & 0x80) !== 0 && !(buf.length === 20 && buf[0] === 0x60 && buf[3] === 0x00);
}

function relAck(s, ackSeq) {
  if (!relWindowEnabled() || !s.relInflight) return;
  for (const item of s.relInflight) {
    if (item.seq === ackSeq) {
      item.acked = true;
      break;
    }
  }
  let advanced = false;
  while (s.relInflight.length > 0 && s.relInflight[0].acked) {
    s.relBase = (s.relInflight[0].seq + 1) >>> 0;
    s.relInflight.shift();
    advanced = true;
  }
  if (advanced) {
    while (s.relReservations.length > 0 && s.relReservations[0] < s.relBase) s.relReservations.shift();
  }
}

function relRetransmitDue(s, force = false) {
  if (!relWindowEnabled() || !s.relInflight || !s.rinfo) return;
  const now = Date.now();
  const retxMs = relRetransmitMs();
  for (const item of s.relInflight) {
    if (item.acked) continue;
    if (!force && now - item.sentAt < retxMs) continue;
    item.sentAt = now;
    item.retx = (item.retx || 0) + 1;
    server.send(item.buf, item.port, item.address, () => {});
    s.outCount++;
    s.totalOut += item.buf.length;
    log(s, `[udp ${s.key}] OUT #${s.outCount} [rel-window retransmit seq=0x${item.seq.toString(16)} attempt=${item.retx}] (${item.buf.length}b)`);
  }
}

function sendSnapPacket(s, buf, rinfo, cb) {
  if (!relWindowEnabled() || !isReliableDataPacket(buf)) {
    return server.send(buf, rinfo.port, rinfo.address, cb);
  }
  initRelWindow(s);
  const seq = buf.readUInt32BE(0x08) >>> 0;
  // Register/re-register replies are legacy seq 0 control packets. Once the
  // reliable window has been seeded to seq 1, tracking that seq 0 as inflight
  // creates a phantom gap and makes the next real reliable reply skip to seq 2.
  if (seq < s.relBase) {
    return server.send(buf, rinfo.port, rinfo.address, cb);
  }
  const existing = s.relInflight.find(item => item.seq === seq);
  if (existing) {
    existing.buf = Buffer.from(buf);
    existing.sentAt = Date.now();
    existing.port = rinfo.port;
    existing.address = rinfo.address;
    return server.send(buf, rinfo.port, rinfo.address, cb);
  }
  const reservedIdx = s.relReservations.indexOf(seq);
  if (reservedIdx !== -1) s.relReservations.splice(reservedIdx, 1);
  if (s.relInflight.length >= relWindowLimit()) {
    log(s, `[udp ${s.key}] rel-window full (${s.relInflight.length}/${relWindowLimit()}); suppressing new reliable seq=0x${seq.toString(16)} and retransmitting oldest`);
    relRetransmitDue(s, true);
    if (cb) process.nextTick(cb);
    return;
  }
  s.relInflight.push({
    seq,
    buf: Buffer.from(buf),
    sentAt: Date.now(),
    port: rinfo.port,
    address: rinfo.address,
    acked: false,
    retx: 0,
  });
  s.relInflight.sort((a, b) => a.seq - b.seq);
  return server.send(buf, rinfo.port, rinfo.address, cb);
}

// 2026-07-12 G12 ROOM-INFO op10 builder+sender (shared by the PROACTIVE push after enter-accept and the
// client's fallback op10 ping). RE (G12: g12-op10window-test pcap): the room only opens when the server
// sends the op10 sub-1 (FUN_005bba20 case 1 -> 0x6cbc7e=0x10). The client waits ~6s after the enter-accept
// then pings op10 as a FALLBACK; a real host PUSHES the room-info immediately -> instant open. Seq = the
// contiguous reliable counter (nextTxSeq) so it rides the same window as the accept; delivery is in-window
// (measured backlog=0 at this point). Blob zeroed (blank fields until the 0x300 layout is RE'd).
function sendRoomInfoOp10(s, msg, rinfo, dt, label, role) {
  const txSeq = nextTxSeq(s);
  const BLOB = 0x300;
  const total = 0x10 + (4 + BLOB) + 4;             // hdr + [header word + 0x300 blob] + trailer = 0x318
  const wireLen = (total - 4) & 0x3ff;             // 0x314
  const push = Buffer.alloc(total);
  push[0] = 0xA0 | ((wireLen >> 8) & 0x03);        // who 0xA0 (reliable+0x2000, DATA 0x1000/0x400 clear) -> slot 0x13
  push[1] = wireLen & 0xff; push[2] = 0x00; push[3] = 0x10;  // opcode 0x10 (room-manager)
  msg.copy(push, 4, 4, 16);                         // session token + ack mirror
  push.writeUInt32BE(txSeq >>> 0, 0x08);           // in-order reliable seq
  push.writeUInt32BE(1, 0x10);                     // param_2+0 header word = 1 (mirror client's constant)
  push[0x18] = 0x01;                               // param_2+8 = SUB SELECTOR 1 (case 1 -> 0x6cbc7e=0x10)
  // 2026-07-12 G12 CREATE (snap-re G12-populated-room-op10-RE-2026-07-12 §1, [C]): the record copied to the
  // client's 0x6fc2e8 blob starts AFTER the [subsel][pad3] header = wire+0x1c. For record word0==0 (room-param,
  // zeroed here) the room tick FUN_005b5fb0 does 0x6c5539 = blob+4 byte (wire+0x20) — and 0x6c5539 IS the
  // create-screen fork screen+0x9a9: 1 = you are HOST/CREATOR (create SM takes the STAT-0x70 mint path),
  // 0 = JOINER (member-register burst), 2 = error. Our previously zeroed blob told every CREATOR they were a
  // joiner. Rig check: PINE 0x6c5539 == 1 right after this push on a create.
  push[0x20] = (role || 0) & 0xff;
  push[total - 4] = 0xba; push[total - 3] = 0x47; push[total - 2] = 0x66; push[total - 1] = 0x11;
  sendSnapPacket(s, push, rinfo, () => {});
  s.outCount++; s.totalOut += push.length;
  log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [ROOM-INFO op10 ${label} sub=1 role=${(role || 0)} (flip 0x6cbc7e->0x10) seq=0x${txSeq.toString(16)}] (${push.length}b)`);
}

// 2026-07-12 G12-2 MEMBER-JOIN PUSH (SNAP_MEMBER_JOIN_PUSH=1). The roster the player SEES is NOT the op0a
// member-list buffer (0x6cdbe6 — a different list/detail display); it is the per-frame roster table 0x6c7c2c
// drawn by FUN_005fd9e0 (gate: widget[+2]==1 && 0x6c7c2c[row*0x3b0]!=0). That table is filled ONLY by a
// SERVER member-JOIN push: dispatcher routes inbound cmd=0x06 DATA-clear -> callback slot 2 = FUN_005bb4d0
// (install map 0x02->0x550->cmd 0x06; installed with slot 0x13 by FUN_005bc860, so it is ready whenever the
// op10 room push lands). FUN_005bb4d0 (helper:12151): record+0x00 name(16B)->0x6cd682; record+0x10 handle
// (u32)->FUN_005c50a0 encode->0x6cd672 (local id); record+0x18 data(0xf0)->0x6cd696; sets room mode
// 0x6cbc7e=0x10 (this is what satisfies FUN_005fd9e0 widget[+2]==1 — the op0a path never set it, which is why
// slot-6 had 0x6c7c2c bytes but drew 0 rows); fires event 0x1f (FUN_005b5ac0) -> writes the row into 0x6c7c2c;
// increments the room member count *(0x6cfb62+room*0x144) capped at 4. Maps to Bioserver sendCreateSlot ->
// broadcastSlotPlayerStatus (SLOTPLRSTATUS 0x6403): the server PROACTIVELY pushes the creator's own member
// after create. Same mechanism drives the joiner (A sees B): broadcast B's record to A. Framed exactly like the
// working sendRoomInfoOp10 (who=0xA0 DATA-clear, contiguous nextTxSeq so it rides the in-window reliable path).
// Delivery is the one unproven link (second_opinion 2026-07-12: highest risk = outbound seq / window), so this
// is default-OFF and confirmed on the rig by pcap (op06 after the member-list, client acks) + savestate
// (0x6c7c2c[0]!=0, 0x6cbc7e==0x10, count 0x6cfb62+room*0x144 == 1).
function sendMemberJoinOp06(s, msg, rinfo, dt, label, handle, name, attempt = 1) {
  const txSeq = nextTxSeq(s);
  const REC = 0x108;                                 // record: name[16] + handle@0x10 + data[0xf0]@0x18
  const total = 0x10 + REC + 4;                      // hdr + record + trailer = 0x11c
  const wireLen = (total - 4) & 0x3ff;               // 0x118
  const push = Buffer.alloc(total);
  push[0] = 0xA0 | ((wireLen >> 8) & 0x03);          // who 0xA0 (reliable+0x2000, DATA 0x1000 CLEAR) -> outer case 3 -> slot 2
  push[1] = wireLen & 0xff; push[2] = 0x00; push[3] = 0x06;  // opcode 0x06 (member-JOIN into slot 2)
  ((msg && msg.length >= 16) ? msg : s.addr16).copy(push, 4, 4, 16);  // session token + ack mirror (resends use the cached token)
  push.writeUInt32BE(txSeq >>> 0, 0x08);             // in-order reliable seq
  Buffer.from(String(name || 'CREATOR')).copy(push, 0x10, 0, 16);   // record+0x00 name[16] -> 0x6cd682
  push.writeUInt32BE((handle >>> 0) || 1, 0x20);     // record+0x10 handle -> FUN_005c50a0 -> 0x6cd672 (local id)
  // record+0x18 .. +0x107 data blob left zeroed (0xf0 charstats). T27: char-id @ +0xf0 = charstats+0xc8.
  // The creator is member 1 -> char-id 1 (distinct from joiners) so the dedup (FUN_005b5ac0) admits both.
  if (process.env.SNAP_DISTINCT_CHARID === '1') push.writeInt16LE(1, 0xf0);   // creator char-id = 1
  push[total - 4] = 0xba; push[total - 3] = 0x47; push[total - 2] = 0x66; push[total - 1] = 0x11;
  sendSnapPacket(s, push, rinfo, () => {});
  s.outCount++; s.totalOut += push.length;
  log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [MEMBER-JOIN op06 ${label} handle=0x${((handle >>> 0) || 1).toString(16)} name="${name || 'CREATOR'}" (slot2 FUN_005bb4d0 -> roster 0x6c7c2c + count++) seq=0x${txSeq.toString(16)}${attempt > 1 ? ` RETRY n=${attempt}` : ''}] (${push.length}b)`);
  if (process.env.SNAP_MEMBER_JOIN_RETRY === '1') armMemberJoinRetry(s, txSeq, rinfo, dt, label, handle, name, attempt);
}

// 2026-07-26 G12 (SNAP_MEMBER_JOIN_RETRY=1). The create-self op06 is dropped un-acked by the client
// NONDETERMINISTICALLY (SESSION-LOG-2026-07-25 T10: the only-unacked seq in 2 of 3 rig runs, even 66ms+
// separated from other traffic — not a flush race). A reliable push must retransmit until the client's
// selective transport-ack (wire+0x0c == our seq) confirms it — the client does the same toward us.
// Each resend uses a FRESH txSeq (the reliable stream is in-order; never reuse a seq). Cleared by the
// matching ack (transport-ack site), a room change, attempt cap 4, or session reset.
function armMemberJoinRetry(s, seq, rinfo, dt, label, handle, name, attempt) {
  if (s.pendingMemberJoin?.timer) clearTimeout(s.pendingMemberJoin.timer);
  const entry = { seq: seq >>> 0, attempt, label, handle, name, room: s.roomHandle, timer: null };
  entry.timer = setTimeout(() => {
    if (s.pendingMemberJoin !== entry) return;       // acked/superseded meanwhile
    s.pendingMemberJoin = null;
    if (entry.attempt >= 4 || s.roomHandle !== entry.room || !s.addr16) {
      log(s, `[udp ${s.key}] --  [MEMBER-JOIN op06 GIVE-UP after n=${entry.attempt} (seq=0x${entry.seq.toString(16)} unacked)]`);
      return;
    }
    sendMemberJoinOp06(s, null, rinfo, dt, entry.label, entry.handle, entry.name, entry.attempt + 1);
  }, 250);
  s.pendingMemberJoin = entry;
}

// 2026-07-13 G12-5 JOINER BROADCAST (SNAP_JOINER_BROADCAST=1). When B joins a room A is in, push B's member
// record to A's session so A appends B as a second roster row. Distinct from sendMemberJoinOp06 (the self-push):
// this is PROACTIVE to a DIFFERENT session (target=A) — it uses the TARGET's cached addr16 token (like the op40
// keepalive) and the target's own nextTxSeq, so it rides A's reliable window, not the joiner's. snap-re
// (G12-joiner-broadcast-RE-2026-07-13): FUN_005b5ac0 draws the row from the member-JOIN record ALONE (memcpy
// 0x114 from 0x6cd672) — NAME must be non-empty (empty NAME = free-row marker), id is read native LE (so write
// LE, not the self-push's BE), row2 lands at 0x6c7c2c+0x3b0. Durability (follow-up): B must also appear in A's
// future op0a replies or the whole-list render wipes the append. Self-push (golden candidate) left untouched.
// 2026-07-17 FOUNDATION (SNAP_REAL_NAMES=1): PAL renders the 16-byte name field @rec+0x00 of the
// member record we send — verbatim (G12-identity-vehicle-RE-2026-07-17). We already capture the login
// handle at register (game_udp_server.js:376) / bind (:2420) and store it as p.handle. So real names
// need NO new client vehicle: resolve the member's handle from lobby_state, fall back to the synthetic
// name when off/unknown. idKey OR transportKey accepted.
function realMemberName(idOrTransportKey, fallback) {
  if (process.env.SNAP_REAL_NAMES !== '1') return fallback;
  let p = lobbyState.players.get(idOrTransportKey) || lobbyState.playerByEndpoint(idOrTransportKey);
  const nm = p && lobbyState.displayName(p, null);
  return (nm && String(nm).trim()) ? String(nm) : fallback;
}

// ---- CONSOLIDATION C1: PURE builders (session -> packet) for the engine adapter ------------------
// These return a wire packet WITHOUT sending, so the engine's emission plans can drive them through
// engine_adapter (which owns the reliable-window send). The legacy inline handlers below are being
// migrated to call these so there is ONE builder per vehicle (no divergent copies). tokenSrc = a
// 16-byte buffer whose [4..16) is the session token to mirror (the inbound msg on a reply, or s.addr16
// on a proactive push). Names resolve through realMemberName (SNAP_REAL_NAMES).

// op0a member-list (op28 sel-0x0a -> slot 0x18 FUN_005c0ae0 fill). The DURABLE roster: enumerates ALL
// room members so the client's whole-list redraw (and the sub-1 rebuild) draw from a complete buffer.
function buildRoomMemberListPacket(s, room, subByte, tokenSrc) {
  if (!room || room.members.size === 0) return null;
  const members = [...room.members].slice(0, 4);       // idKeys, join order (dest 0x6cdbe6 = 4x0x118)
  const n = members.length;
  const REC = 0x108;                                   // name 0x10 + id 4 + len 4 + data 0xf0
  const total = 0x10 + (0xc + n * REC) + 4;
  const wireLen = (total - 4) & 0x3ff;
  const ml = Buffer.alloc(total);
  ml[0] = 0xA0 | ((wireLen >> 8) & 0x03);              // DATA-CLEAR -> case 9 -> slot 0x18 (fill+count)
  ml[1] = wireLen & 0xff; ml[2] = subByte & 0xff; ml[3] = 0x28;
  (tokenSrc || s.addr16).copy(ml, 4, 4, 16);           // session token mirror
  ml.writeUInt32BE(nextTxSeq(s) >>> 0, 0x08);
  ml.writeUInt32BE(0x0000000A, 0x10);                  // body+0 = selector 0x0a
  ml.writeUInt32LE(n >>> 0, 0x18);                     // body+8 = entryCount (LE, proven)
  members.forEach((idKey, i) => {
    const off = 0x1c + i * REC;
    // RF-15 naming fix, GATED behind SNAP_ROOM_ENGINE (Codex #6 rollback-safety): the ENGINE path resolves
    // the name via the authoritative lobby_state handle (displayName -> real login handle); the LEGACY path
    // (engine off) keeps realMemberName(idKey) exactly as before -> engine-off output is byte-identical,
    // fully reversible.
    const nm = (process.env.SNAP_ROOM_ENGINE === '1')
      ? lobbyState.displayName(lobbyState.players.get(idKey), (room.hostId && idKey === room.hostId) ? 'HOST' : 'PLAYER' + (i + 1))
      : realMemberName(idKey, (room.hostId && idKey === room.hostId) ? 'CREATOR' : 'PLAYER' + (i + 1));
    Buffer.from(nm).copy(ml, off, 0, 16);   // +0x00 name[16]
    ml.writeUInt32BE((i + 1) >>> 0, off + 0x10);       // +0x10 member id (BE, proven)
    ml.writeUInt32LE(0x000000f0, off + 0x14);          // +0x14 data length -> nextRec = rec+0xf0+0x18
    // T27 distinct char-id: charstats+0xc8 = rec+0x18+0xc8 = off+0xe0. Same per-member value as the
    // op06 push so the redraw (buffer->visible) stays consistent with the deduped live rows.
    if (process.env.SNAP_DISTINCT_CHARID === '1') ml.writeInt16LE(((i + 1) % 8) & 0xffff, off + 0xe0);
  });                                                  // +0x18 data[0xf0] zeroed
  ml[total - 4] = 0xba; ml[total - 3] = 0x47; ml[total - 2] = 0x66; ml[total - 1] = 0x11;
  return ml;
}

// op10 sub-0x11 count update (FUN_005bbea0 -> writes 0x6cfb70[room], no BUILD event) — the registry-
// derived count push (Bioserver SLOTPLRSTATUS analog). Replaces the client-accumulated 0x6cfb62 drift.
function buildCount0x11Packet(s, count, tokenSrc) {
  const total = 0x24;                                  // 16 hdr + 16 body + 4 trailer
  const push = Buffer.alloc(total);
  push[0] = 0xA0; push[1] = 0x20; push[2] = 0x00; push[3] = 0x10;   // who 0xA0 -> slot 0x13
  (tokenSrc || s.addr16).copy(push, 4, 4, 16);
  push.writeUInt32BE(nextTxSeq(s) >>> 0, 0x08);
  push.writeUInt32BE(1, 0x10);                         // header word = 1 (mirror the proven sub pushes)
  push[0x18] = 0x11;                                   // SUB 0x11 = member-count update
  push.writeUInt32LE((count >>> 0) & 0xff, 0x1c);      // payload+4 = count (FUN_005bbea0 reads *(byte))
  push[0x20] = 0xba; push[0x21] = 0x47; push[0x22] = 0x66; push[0x23] = 0x11;
  return push;
}

// 2026-07-26 G12 creator count/max display (SNAP_ROOM_LIMITS_OP10SUB5=1). The host engine zeroes
// 0x6ff2b4 on each screen rebuild; op10 sub-5 is the sole non-zero writer (max @sub+4, current @sub+5).
// Frame exactly like the proven sub-0x11 count push and re-assert after create plus every room-info ping.
function sendRoomLimitsOp10Sub5(s, tokenSrc, rinfo, dt) {
  const room = (s.roomHandle != null) ? lobbyState.rooms.get(s.roomHandle) : null;
  const maxPlayers = room ? room.maxPlayers : 4;
  const current = room ? room.members.size : 1;
  const push = buildCount0x11Packet(s, 0, tokenSrc);
  push[0x18] = 0x05;
  push[0x1c] = maxPlayers & 0xff;
  push[0x1d] = current & 0xff;
  sendSnapPacket(s, push, rinfo, () => {});
  s.outCount++; s.totalOut += push.length;
  log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [ROOM-LIMITS op10 sub=5 max=${maxPlayers} cur=${current}] (${push.length}b)`);
}

// op06 member-JOIN delta (BUILD-only, for the engine adapter). Mirrors sendMemberJoinBroadcast but RETURNS
// the buffer (the adapter's send transmits it) so the reliable seq is allocated once, on the emission path.
function buildMemberJoinOp06Packet(sess, id, name) {
  if (!sess || !sess.addr16) return null;
  const REC = 0x108;
  const total = 0x10 + REC + 4;                        // hdr + record + trailer = 0x11c
  const wireLen = (total - 4) & 0x3ff;                 // 0x118
  const push = Buffer.alloc(total);
  push[0] = 0xA0 | ((wireLen >> 8) & 0x03);            // who 0xA0 (DATA clear) -> slot 2 (member-JOIN)
  push[1] = wireLen & 0xff; push[2] = 0x00; push[3] = 0x06;
  sess.addr16.copy(push, 4, 0, 12);                    // TARGET session token
  push.writeUInt32BE(nextTxSeq(sess) >>> 0, 0x08);     // reliable seq on the TARGET window (one owner)
  Buffer.from(String(name || 'PLAYER')).copy(push, 0x10, 0, 16);   // record+0x00 NAME
  push.writeUInt32LE((id >>> 0) || 2, 0x20);           // record+0x10 id (LE)
  if (process.env.SNAP_DISTINCT_CHARID === '1') push.writeInt16LE((((id >>> 0) || 1) % 8) & 0xffff, 0xf0); // char-id (dedup)
  push[total - 4] = 0xba; push[total - 3] = 0x47; push[total - 2] = 0x66; push[total - 1] = 0x11;
  return push;
}

// op07 member-LEAVE delta (BUILD-only, for the engine adapter) — the SPINE-3 survivor-notify vehicle.
// snap-re SPINE-2-3-lobby-leave-RE-2026-07-19: op07 (normal, no 0x1000 DATA flag) -> dispatcher slot 6
// -> FUN_005bb670 MEMBER LEAVE. It reads the leaver's 32-bit member-id at body+0 (param_2[0], same
// id-encoding as the op06 join it mirrors), fires event 0x20 REMOVE-render and decrements the in-room
// count 0x6cfb62; a HOST recipient also compacts 0x7006d4 and re-pushes op10 sub-0x11. Modeled on
// buildMemberJoinOp06Packet: who=0xA0 (DATA clear -> slot 6, the op07 sibling of op06's slot 2),
// opcode 0x07, reliable seq on the TARGET (survivor) window, id written LE (FUN_005bb670 reads native
// LE, same as op06's FUN_005bb4d0). WIRE-FORMAT [decompile-known, rig-unconfirmed]: the exact leave
// body bytes + the 2-client survivor render are the EXP-C5 capture-check (SPINE-3 "Still capture-gated").
function buildMemberLeaveOp07Packet(sess, id) {
  if (!sess || !sess.addr16) return null;
  const total = 0x10 + 0x10 + 4;                      // hdr + body(16, id @+0) + trailer = 0x24
  const wireLen = (total - 4) & 0x3ff;                // 0x20
  const push = Buffer.alloc(total);
  push[0] = 0xA0 | ((wireLen >> 8) & 0x03);           // who 0xA0 (DATA clear) -> slot 6 (member-LEAVE)
  push[1] = wireLen & 0xff; push[2] = 0x00; push[3] = 0x07;   // opcode 0x07 (MEMBER LEAVE)
  sess.addr16.copy(push, 4, 0, 12);                   // TARGET session token (proactive push, no live msg)
  push.writeUInt32BE(nextTxSeq(sess) >>> 0, 0x08);    // reliable seq on the TARGET (survivor) window
  push.writeUInt32LE((id >>> 0) || 0, 0x10);          // body+0 = leaver 32-bit member-id (LE, FUN_005bb670)
  push[total - 4] = 0xba; push[total - 3] = 0x47; push[total - 2] = 0x66; push[total - 1] = 0x11;
  return push;
}

// Resolve an engine recipient (lobby_state player) to its live UDP session object(s).
function engineSessionsFor(player) {
  if (!player || !player.udpKeys) return [];
  const out = [];
  for (const k of player.udpKeys) { const sess = sessions.get(k); if (sess) out.push(sess); }
  return out;
}

function sendMemberJoinBroadcast(s, id, name) {
  if (!s || !s.addr16 || !s.rinfo) return false;
  const txSeq = nextTxSeq(s);
  const REC = 0x108;
  const total = 0x10 + REC + 4;                      // hdr + record + trailer = 0x11c
  const wireLen = (total - 4) & 0x3ff;               // 0x118
  const push = Buffer.alloc(total);
  push[0] = 0xA0 | ((wireLen >> 8) & 0x03);          // who 0xA0 (reliable, DATA clear) -> outer case 3 -> slot 2
  push[1] = wireLen & 0xff; push[2] = 0x00; push[3] = 0x06;  // opcode 0x06 (member-JOIN)
  s.addr16.copy(push, 4, 0, 12);                     // TARGET session token + ack mirror (proactive, no live msg)
  push.writeUInt32BE(txSeq >>> 0, 0x08);             // in-order reliable seq on the TARGET's window
  Buffer.from(String(name || 'PLAYER')).copy(push, 0x10, 0, 16);   // record+0x00 NAME (non-empty -> not a free row)
  push.writeUInt32LE((id >>> 0) || 2, 0x20);         // record+0x10 id (LE — FUN_005bb4d0 reads native LE)
  // record+0x18..+0x107 data blob zeroed (the 0xf0 charstats)
  // 2026-07-18 ROOT CAUSE (T27): the roster insert FUN_005b5ac0 DEDUPS by char-id (0x6c7d18 =
  // charstats+0xc8 = wire+0xf0). All members default to char-id 0 -> the 2nd member is deduped away
  // and never drawn. Write a DISTINCT synthetic char-id per member (join-order id, kept in 1..7 valid
  // range) so the dedup passes and every member draws. Real characters come with the charstats capture.
  if (process.env.SNAP_DISTINCT_CHARID === '1') {
    push.writeInt16LE((((id >>> 0) || 1) % 8) & 0xffff, 0xf0);   // charstats+0xc8 = char-id
  }
  push[total - 4] = 0xba; push[total - 3] = 0x47; push[total - 2] = 0x66; push[total - 1] = 0x11;
  sendSnapPacket(s, push, s.rinfo, () => {});
  s.outCount++; s.totalOut += push.length;
  log(s, `[udp ${s.key}] OUT #${s.outCount} [MEMBER-JOIN-BROADCAST op06 -> ${s.key} name="${name}" id=0x${((id >>> 0) || 2).toString(16)} (slot2 append row) seq=0x${txSeq.toString(16)}] (${push.length}b)`);
  return true;
}

function extractReentryInnerOp48(msg) {
  if (msg.length < 0x14 + 0x18) return null;
  const outerFlags = msg.readUInt16BE(0);
  if ((outerFlags & 0x0800) === 0) return null;
  const innerOff = 0x14;
  if (msg[innerOff] !== 0xB0 || msg[innerOff + 2] !== 0x00 || msg[innerOff + 3] !== 0x48) return null;

  const innerBodyLen = msg.readUInt16BE(innerOff) & 0x03ff;
  const innerTotal = 4 + innerBodyLen + 4;
  if (innerTotal >= 0x18 && innerOff + innerTotal <= msg.length) {
    return msg.subarray(innerOff, innerOff + innerTotal);
  }
  return msg.subarray(innerOff);
}

// 2026-07-05 G10 (SNAP_RESET_SESSION_ON_REGISTER=1) — reset the per-CONNECT-EPOCH state on a
// re-register so a client that backs out and re-selects a server starts a clean SN@P epoch.
// ROOT CAUSE (Codex diagnosis + snap-recvbase-delivery-contract-RE-2026-06-28): reliable DATA uses
// ONE recvBase that MUST reset per session-open/register; but the "seed txSeqNext ONCE, never rewind"
// line (~1615, the PS2 first-render fix) keeps the PRIOR epoch's txSeqNext across a re-register. The
// client re-registers with a fresh recvBase, so the connect-phase op48 named-slot-query-reply is
// stamped OUT-OF-EPOCH -> the client never receives it -> it sits at "connecting" looping op41 (its
// pong to our op40 keepalive; op41 is a symptom, not a request needing a reply). Clearing txSeqNext
// here lets the register-reply re-seed it from the NEW regReplySeq (1614-1615) = a clean epoch, while
// the "don't rewind WITHIN an epoch" rule is preserved (no re-seed mid-epoch). Gated: default OFF =
// golden behavior unchanged. Returns the prior txSeqNext for the confirming log.
function resetUdpSessionForRegister(s) {
  const prevTx = s.txSeqNext;
  if (s.kaTimer) { clearInterval(s.kaTimer); s.kaTimer = null; }
  if (s.pendingMemberJoin?.timer) { clearTimeout(s.pendingMemberJoin.timer); }
  s.pendingMemberJoin = null;
  s.txSeqNext = undefined;      // re-seeded from the fresh regReplySeq at ~1615
  s.regReplySeq = undefined;
  resetRelWindow(s);
  s.gameAck = undefined;
  s.sawAreaConfirm = false;     // possible 2nd gate (Hypothesis)
  s.estabOnBindDone = false;    // possible 2nd gate (Hypothesis)
  s.areaOp48Frame = 0;
  s.roomRenderDone = false;
  s.namedSlotReplyAt = null;
  s.pushedAt = null;
  s.kaSeq = 0;
  return prevTx;
}

const server = dgram.createSocket({ type: 'udp4', reuseAddr: true });
let pktCounter = 0;

// 2026-06-21 (T20): per-client register counter. Login = 1st register (must NOT be disturbed so the
// login->TCP-lobby->server-select-grid renders); select = 2nd+ register. estab-on-bind fires only on
// the 2nd+ so it targets the SELECT connect, not login. Reset by SNAP_REG_COUNT_RESET unused.
const regCountByIp = new Map();

/**
 * Classify the incoming SN@P/UDP packet by its `kind` byte (byte 0).
 *
 * Verified from captures + decompile (FUN_001d72a8 + FUN_001db7e8):
 *   0x30  â€” DATA request (REGISTER, etc). Reply with snap-register-reply.
 *   0x60  â€” Transport-layer ACK. Do NOT reply (reliable transport â€” game
 *           sends this after accepting our reply, and replying back would be
 *           interpreted as new data which it isn't).
 *   other â€” Unknown; fall through to strategy rotation for diagnostics.
 */
function classifyIncoming(msg) {
  if (msg.length < 4) return 'too-short';
  const kindByte = msg[0];
  if (kindByte === 0x30 && msg.length === 154) return 'register-request';
  if (kindByte === 0x60 && msg.length === 20)  return 'transport-ack';
  // 2026-05-17 (Codex analysis post-register-op01.md): kind=0x31, opcode=0x0001
  // is the post-REGISTER session-bind packet from FUN_001d6ee0. The sender does
  // NOT arm a FUN_001d4d24 callback, so the game expects only a reliable-transport
  // ACK, not an encrypted application reply.
  if (kindByte === 0x31 && msg.length >= 0x14 && msg[2] === 0x00 && msg[3] === 0x01) {
    return 'post-register-bind';
  }
  if (kindByte === 0x31) return 'post-register-other';  // kind 0x31 with different opcode — handler unknown
  // 2026-05-18: after the slot-0x1c push lands, the game sends a REL+ACK
  // (kind 0xb0) with opcode 0x02 and no body — application-level "I got it"
  // ACK. Don't reply to it; the game is just confirming receipt before
  // tearing down the SN@P UDP state and moving to the TCP 10127 lobby phase.
  if (kindByte === 0xB0 && msg.length === 20 && msg[3] === 0x02) return 'app-ack-op02';
  // 2026-05-19 (Codex analysis tcp10127-field-a-and-post-lobby-dns.md):
  // After the full lobby walk completes, the game's compile-time default
  // host 0x35bee0 = "snap01.capcom.client.sf.yav4.com" + port 0x2382 path
  // sends a fresh UDP 9090 packet with kindByte 0x32. Empirical shape:
  // 570 bytes, qsw 0x36, opcode 0x0001, body NOT blowfish-encrypted (decode
  // shows handle=""). Classify so we don't fall through to snap-register-reply.
  if (kindByte === 0x32) return 'post-lobby-snap';
  // 2026-05-19: AFTER the slot1c push following the 570B ACK, the game starts
  // sending 70-byte UDP packets every 2-4 seconds carrying SLOT IDs at offsets
  // 0x18 + 0x2e (16-byte fixed-width strings like "NAMEDSLOT000101",
  // "NAMEFSLOT000110"). kind=0xf0, opcode=0x0048. This is the first packet
  // class the game emits after our state-advance experiment — likely a
  // friends-list / named-slot query. Awaiting Codex mapping.
  if (kindByte === 0xF0 && msg.length === 70 && msg[3] === 0x48) return 'named-slot-query';
  // 2026-07-02 T6 (SNAP_OP48_REPLY_ALL=1): the LOBBY op48 NAME queries arrive as kind 0xB0/0xB8
  // (reliable, opcode 0x0048, entries "NAME"+flag+value "192.0.2.121xx") and in golden fell to
  // the catch-all register-reply (out-of-window => never app-delivered => the query NEVER
  // completes; consumer FUN_005c1220 sets ready_6ce5be, a shared lobby gate). Classify them as
  // named-slot-query so they get the structured echo-record reply (proven shape). Non-0xF0
  // frames skip the bind-ack + snapshot machinery (see strategy selection). Default OFF.
  if (process.env.SNAP_OP48_REPLY_ALL === '1' && (kindByte & 0x80) && kindByte !== 0xF0
      && msg[2] === 0x00 && msg[3] === 0x48 && msg.length >= 0x20) {
    return 'named-slot-query';
  }
  // 2026-06-12: AFTER the overlay JOIN commits (seq fix + cap=4 + capfix), the game
  // emits a previously-unreachable 268-byte query: kind=0xa1, qsw=0x00, cmd=0x0c,
  // body = token + wire-seq + zeros. This is the post-join ROOM/MEMBER query. The
  // game backoff-retries it ~60s and times out to Error:840 if unanswered correctly.
  // See docs/findings/protocol/join-commits-new-wall-cmd0x0c-room-query-2026-06-12.md
  // 2026-06-12 PHASE 1 result: the subcmd-2 push ADVANCES the poll who-byte (0xa1 → 0xe1, field+0x0c
  // goes 0→2). Both are the room poll at successive phases — keep pushing on both to drive the sequence.
  if ((kindByte === 0xA1 || kindByte === 0xE1) && msg.length >= 0x40 && msg[3] === 0x0c) return 'room-query-cmd0c';

  // 2026-06-21: after the op-0x31 establish-push, the game opens the bidirectional reliable
  // channel: f0/op2 = DATA(0xb0)|ACK(0x40), 20 bytes, op 0x02, carrying its reverse-channel
  // data seq at +0x08 and a cumulative ack at +0x0c. Must be ACK'd (was falling to 'unknown'
  // echo, which over-acked a non-existent seq -> instant 820). See op31-establishes-wall memory.
  if (kindByte === 0xF0 && msg.length === 20 && msg[3] === 0x02) return 'transport-data-f0op2';
  // 2026-06-16 ROOM RENDER (room-render-exact-sequence-2026-06-16): the game's reliable op-6
  // (room-enter) and op-10 (member-list) REQUESTS, emitted by overlay room-flow SMs (FUN_005fada0
  // state 2 / FUN_005fa190 state 3) after the join commits. We answer with byte0=0xA0 (DATA clear)
  // so dispatcher cases 5/9 reach the render callbacks. Gated by SNAP_ROOM_RENDER_A0 so it is inert
  // unless explicitly enabled (Phase B). Reliable bit (0x80) set + opcode-high 0 + opcode low 6/0x0a.
  if (process.env.SNAP_ROOM_RENDER_A0 === '1' && (kindByte & 0x80) && msg[2] === 0x00) {
    if (msg[3] === 0x06) return 'room-enter-request';
    if (msg[3] === 0x0a) return 'member-list-request';
  }
  return 'unknown';
}

// 2026-06-30 DECOUPLED op-0x40 keepalive (gated SNAP_OP40_TIMER). Render = phase-3 survival
// (RENDER-FINGERPRINT-2026-06-30): the connecting->lobby gate 0x6c4b90 reaches 6 ONLY while
// conn+0x7c keeps being refreshed, and ONLY an inbound op0x40 refreshes it (FUN_001d9b6c, 1st
// instr *(conn+0x7c)=*(conn+0x4fc)). Sent NON-RELIABLE (byte0=0x30, own monotonic s.kaSeq) so it
// bypasses the reliable recvBase reorder gate (FUN_001d6988) and dispatches every time. Body =
// zero plaintext encrypted with conn+0x4d4 key (SNAP-SWAN, PINE-confirmed) so the handler's
// memcpy copies 0 bytes (no stack overflow). Reuses the already-cached s.addr16 header so no live
// msg is needed. Per-session ~5s interval (decoupled from the cmd0c poll) per SYNTHESIS-2026-06-29.
function sendOp40Keepalive(s) {
  if (!s || !s.addr16 || !s.rinfo) return;
  let op40key = null;
  if (process.env.SNAP_OP40_KEY) op40key = Buffer.from(process.env.SNAP_OP40_KEY, 'latin1');
  else { const pw = getPasswordForHandle(s.handle || ''); if (pw) op40key = Buffer.from(pw.slice(0, 40), 'latin1'); }
  if (!op40key) { log(s, `[udp ${s.key}] op40-timer SKIP — no key`); return; }
  const plain = Buffer.alloc(0x110);                       // 34 Blowfish blocks, all zero
  const { ctLE } = encryptEeBlowfishBody(plain, op40key);
  const kaSeq = (s.kaSeq = ((s.kaSeq || 0) + 1)) >>> 0;    // dedicated monotonic non-reliable seq
  const total = 0x10 + 0x114 + 4;
  const ka = Buffer.alloc(total);
  const wireLen = (total - 4) & 0x3ff;
  ka[0] = 0x30 | ((wireLen >> 8) & 0x03);                  // 0x30 = DATA(0x1000)+0x2000, NO reliable(0x8000)
  ka[1] = wireLen & 0xff; ka[2] = 0x00; ka[3] = 0x40;      // opcode 0x40
  s.addr16.copy(ka, 4, 0, 12);                             // session token + cum-ack mirror (msg[4..16])
  ka.writeUInt32BE(kaSeq >>> 0, 0x08);                     // wire seq (overwrites mirror[8..12])
  ctLE.copy(ka, 0x10, 0, 0x110);                           // encrypted zero body
  ka[total - 4] = 0xba; ka[total - 3] = 0x47; ka[total - 2] = 0x66; ka[total - 1] = 0x11;
  server.send(ka, s.rinfo.port, s.rinfo.address, () => {});
  s.outCount++; s.totalOut += ka.length;
  log(s, `[udp ${s.key}] OUT #${s.outCount} [op40-timer NONREL seq=0x${kaSeq.toString(16)}] (${ka.length}b)`);
}

// 2026-07-12 G12 CREATE (SNAP_MULTIPLEX_WALK=1): split a coalesced SN@P frame into standalone
// datagrams (each slice + the ba476611 trailer re-appended). A frame = concatenated messages, each
// ((b0&3)<<8|b1) bytes (16B hdr + body), then ONE 4B trailer. Evidence: trackA pkt 384 = outer op0a
// (20B) + op09 'USER' (24B) + op10 roster (28B) + op09 'MAXI' (24B) + trailer = 100B
// (G12-create-accept-wireformat-RE-2026-07-12.md). Conservative: returns null (no split) unless
// EVERY slice parses cleanly and the walk lands exactly on the trailer.
const SNAP_TRAILER = Buffer.from([0xba, 0x47, 0x66, 0x11]);
function splitMultiplexFrame(msg) {
  if (msg.length < 24 || !msg.subarray(msg.length - 4).equals(SNAP_TRAILER)) return null;
  const end = msg.length - 4;
  const parts = [];
  let off = 0;
  while (off < end) {
    if (end - off < 16) return null;                       // dangling bytes that can't be a header
    const len = ((msg[off] & 0x03) << 8) | msg[off + 1];   // hdr+body length (low 10 bits of wire[0..1])
    if (len < 16 || off + len > end || (msg[off] & 0x80) === 0) return null;
    parts.push(Buffer.concat([msg.subarray(off, off + len), SNAP_TRAILER]));
    off += len;
  }
  return parts;
}

server.on('message', async (msg, rinfo) => {
  const s = getSession(rinfo);
  s.inCount++;
  s.rxTick = (s.rxTick || 0) + 1;        // 2026-07-11: per-inbound-frame tick; nextTxSeq re-anchors the
                                         // reliable burst to recvBase once per frame under SNAP_REL_WINDOW.
  s.rinfo = rinfo;                       // 2026-06-30: cache for the decoupled op40 timer
  // Cache the session-address bytes (4..15) so a proactive post-lobby push can
  // reuse them without an inbound packet to mirror. (Establishment-message experiment.)
  if (msg.length >= 16) s.addr16 = Buffer.from(msg.subarray(4, 16));
  s.totalIn += msg.length;
  pktCounter++;
  const dt = `+${String(Date.now() - s.t0).padStart(5)}ms`;

  const decoded = decodePacket(msg);
  if (decoded && decoded.handle) s.handle = decoded.handle;   // 2026-06-30: op40 key fallback source
  const klass = classifyIncoming(msg);
  if (klass === 'register-request') {
    regCountByIp.set(rinfo.address, (regCountByIp.get(rinfo.address) || 0) + 1);
    // 2026-07-05 G10: reset the per-epoch UDP state on a re-register (SNAP_RESET_SESSION_ON_REGISTER=1).
    if (process.env.SNAP_RESET_SESSION_ON_REGISTER === '1') {
      const prevTx = resetUdpSessionForRegister(s);
      log(s, `    [G10] resetUdpSessionForRegister regN=${regCountByIp.get(rinfo.address)} cleared txSeqNext=0x${(prevTx >>> 0).toString(16)} -> fresh epoch`);
    }
  }
  log(s, `\n[udp ${s.key}] ${dt}  IN  #${s.inCount} (${msg.length}b) class=${klass} regN=${regCountByIp.get(rinfo.address) || 0}`);
  log(s, hex(msg, 160));
  log(s, `    decode: kind=${decoded.kind} who=0x${(decoded.who||0).toString(16)} qsw=0x${(decoded.qsw||0).toString(16)} cmd=0x${(decoded.cmd||0).toString(16)} srcPort=${decoded.srcPort} handle="${decoded.handle}" auth="${decoded.auth}"`);

  save(`p${pktCounter}_${rinfo.address.replace(/\./g, '_')}_${rinfo.port}_IN`, msg);

  if (msg.length < 8) return;

  // 2026-07-12 G12 CREATE (SNAP_MULTIPLEX_WALK=1): the in-room mode-4 member-register burst arrives
  // as ONE type-14 multiplex frame (outer op0a + embedded op09 'USER' + op10 + op09 'MAXI', trackA
  // pkt 384). We answered only the OUTER op0a -> the embedded op09 session-opens never completed ->
  // STAT (op08) never fired = the create stall; the un-acked embedded reliable ids also leak the
  // client's conn+0x520 send pool (the deep-stall pool-err=0x65). Split and re-dispatch each message
  // as its own datagram: each then gets its transport ACK + app reply from the normal handlers.
  // Gated to OUTER op0a frames only — op0106/op48-piggyback frames keep their dedicated path
  // (op48 bodies are encrypted; the G2-validated flows stay byte-identical). Re-entry safe: a split
  // part is a single message, so splitMultiplexFrame yields 1 part and falls through.
  if (process.env.SNAP_MULTIPLEX_WALK === '1' && msg[3] === 0x0a && (msg[0] & 0x80)) {
    const parts = splitMultiplexFrame(msg);
    if (parts && parts.length > 1) {
      log(s, `[udp ${s.key}] ${dt}  [multiplex-walk] ${msg.length}b frame -> ${parts.map(p => `op${p[3].toString(16).padStart(2, '0')}/sub${p[2]}`).join(' + ')}`);
      for (const part of parts) server.emit('message', part, rinfo);
      return;
    }
  }

  // Don't reply to transport-layer ACKs â€” they're reliability-layer artifacts.
  // Game sent 0x60-kind ACK after accepting our REGISTER reply; replying to
  // it as if it were data made the game drop the session in our previous test.
  if (klass === 'transport-ack') {
    // 2026-07-12: wire+0x0c is an exact/selective ACK of one server->client reliable seq.
    // It is not a safe cumulative recvBase export; SNAP_REL_WINDOW advances relBase only
    // across the contiguous acked prefix.
    if (msg.length >= 0x10) {
      s.gameAck = msg.readUInt32BE(0x0c) >>> 0;
      relAck(s, s.gameAck);
      relRetransmitDue(s);
      if (s.pendingMemberJoin && (s.gameAck >>> 0) === s.pendingMemberJoin.seq) {
        clearTimeout(s.pendingMemberJoin.timer);
        log(s, `[udp ${s.key}] ${dt}  [MEMBER-JOIN op06 ACKED seq=0x${s.pendingMemberJoin.seq.toString(16)} n=${s.pendingMemberJoin.attempt}]`);
        s.pendingMemberJoin = null;
      }
    }
    log(s, `[udp ${s.key}] ${dt}  (suppressed â€” transport-layer ACK, ackSeq=0x${(s.gameAck>>>0).toString(16)})`);

    if (s.namedSlotReplyAt && (Date.now() - s.namedSlotReplyAt) < 5000) {
      recordNamedSlotDiag(s, 'post-game-ack-after-namedslot-reply', msg, null);
      s.namedSlotReplyAt = null;
      setTimeout(() => recordNamedSlotDiag(s, 'T+2s settled after namedslot ack', null, null), 2000);
    }

    // Automated snapshot: if this is the transport-ACK that closely follows
    // our slot-19 push, capture state to detect transient slot registrations.
    if (s.snapFile && s.pushedAt && (Date.now() - s.pushedAt) < 5000) {
      await runSnapshot(s.snapFile, 'POST-GAME-ACK (transport ACK received)', s.snapT0);
      s.pushedAt = null;
      setTimeout(() => runSnapshot(s.snapFile, 'T+2s settled', s.snapT0), 2000);
    }
    return;
  }

  // 2026-07-01 SNAP_RELIABLE_ACK=1 — per-message transport ACK for the game's reliable sends.
  // RE (SESSION-LOG-2026-07-01-reliable-ack.md T1, Ghidra main ELF): every reliable client message
  // (wire u16 BE flags bit 0x8000, i.e. msg[0]&0x80) is held in the game's conn+0x58 retransmit
  // queue, allocated from the shared conn+0x520 pool, and freed ONLY by an inbound frame with
  // flags bit 0x4000 whose wire+0x0c == the message's send id (= its wire+0x08; FUN_001d6468
  // stamps both from one counter; FUN_001e1ac8 frees on exact match, no-op if unknown). We never
  // sent these acks, so op48/op41/op2d/op06/cmd0c pile up until the pool can't fit op49's ~0x2bc
  // alloc (FUN_001e0ed8 -> DAT_0025b790=0x65) — the lobby room-list send-failure. Ack shape = the
  // proven f0op2 ack: 60 10 00 00 | token(+0x04 echo) | +0x08=0 | +0x0c=inbound id | ba 47 66 11.
  // Coalesced frames (outer flags bit 0x800): each 0x10-byte sub-header carries its own reliable
  // id at sub+0x08 — ack each one. Skips f0op2 (own correct handler) and named-slot-query (its
  // bind-ack is corrected under this flag in buildAck). Double-acking a freed id is a client
  // no-op, so retransmit races are safe. Default OFF; rollback = unset env.
  // 2026-07-02 T5 refinement (SESSION-LOG T3/T4): indiscriminate acking regressed (op48-NAMED
  // driver fast-retries when acked without a valid app reply) and suppression alone didn't stop
  // the 0x65 pool fail — the game's own unACKed send backlog dominates. SNAP_ACK_OPS selects
  // WHICH reliable client opcodes get acked: "all", or csv hex list e.g. "0f,41,2d" (op0f =
  // fire-and-forget presence ping, no driver waits on it — pure pool relief, app-invisible).
  // (SNAP_RELIABLE_ACK=1 is a legacy alias for "all"; superseded by SNAP_ACK_OPS.)
  // 2026-07-02 T8 CORRECTION (LOBBY-STATE-MACHINE-RE + T7 pool read): op49's 0x65 is NOT pool
  // exhaustion — PINE showed sub-pool free counts 110/15/3 with SNAP_ACK_OPS=all. The real cause is
  // a WATERMARK LATCH on sub-pool 2 (FUN_001ebed0: 10 blocks of 0x3ac, low-watermark 3 @ pool+0x74):
  // op48 AND op49 both reserve 0x2a8 (=sub2 940B block); the lobby op48 poll keeps ~7 sub2 blocks
  // in flight, dips free to <=2, and FUN_001ec1f8 LATCHES sub2 disabled (bit0 of subpool+0xe via
  // FUN_001eb33c) — cleared only when a FREE lifts free back to >=4. op49's later alloc is refused
  // while latched (free stuck at 3). LEVER: ACK the game's op48 sends so their sub2 buffers free
  // promptly (FUN_001e1ac8 matches our ack +0x0c == the game's send id) -> sub2 stays >=4, latch
  // clears, op49 allocs + transmits. Earlier code EXCLUDED klass 'named-slot-query' so op48 (the
  // dominant sub2 consumer) was NEVER acked — the bug. Now ack lobby op48 (0xB0/0xB8) too; the
  // connect-phase 0xF0 op48 keeps its bind-ack-only path (already acks correctly). Acking op48 is
  // safe now that it gets a VALID structured reply (T6, ready_6ce5be=10) so no T3 re-arm flood.
  // 2026-07-02 T9 REGRESSION FIX: T8 (ack op48) locked the AREA-SELECT cursor. Journal diagnosis:
  // the coalesced sub-frame walk produced GARBAGE ack ids (0xcd0a0000, 0x83050000, ...) — it walked
  // off = flags&0x3ff INTO the op48 body, which is BLOWFISH-ENCRYPTED, so it read ciphertext as fake
  // sub-frame headers and acked bogus ids -> FUN_001e1ac8 freed WRONG buffers -> area-select
  // corruption. TWO fixes: (1) REMOVE the coalesced walk entirely (can't parse encrypted bodies;
  // ack only the plaintext OUTER frame id at wire+0x08). (2) Never ack the AREA-SELECT op48 — only
  // the LOBBY op48. Distinguisher: s.sawAreaConfirm (set on op06 area-confirm) => we're past
  // area-select. So op48 (0x48) is acked ONLY after op06; area-select op48 is left alone (= the
  // proven-good path). Other opcodes still ack by outer id per SNAP_ACK_OPS.
  const ackOpsEnv = process.env.SNAP_ACK_OPS || (process.env.SNAP_RELIABLE_ACK === '1' ? 'all' : '');
  const reentryConfirmAck = process.env.SNAP_REENTRY_CONFIRM_REPLY === '1';
  if ((ackOpsEnv || reentryConfirmAck) && (msg[0] & 0x80) && msg.length >= 0x10
      && klass !== 'transport-data-f0op2'
      && !(klass === 'named-slot-query' && msg[0] === 0xF0)) {
    const ackAll = ackOpsEnv.trim().toLowerCase() === 'all';
    const ackSet = ackAll ? null : new Set(ackOpsEnv.split(',').map(x => parseInt(x.trim(), 16)));
    // 2026-07-02 L1-v0 VALIDATION (spec §5.1/§7.2): op49's send is one-shot at the area-select->
    // lobby transition, so sub2 must already be above its watermark THEN — which requires acking
    // op48 THROUGH area-select, not only after op06. The op06-gate (T9) protected area-select while
    // we distrusted op48-acking, but the real T8 culprit was garbage ids from the coalesced walk
    // (now removed). SNAP_ACK_OP48_ALWAYS=1 lifts the gate to test the clean hypothesis: correct
    // per-id op48 acks are safe during area-select AND keep sub2 healthy so op49's one-shot lands.
    // Single variable vs T9 (which already acked everything except op48-pre-op06 with area-select OK).
    const gateOp48 = process.env.SNAP_ACK_OP48_ALWAYS !== '1';
    // 2026-07-11 G12 (snap-re G12-reliable-pool-RE): the transport ACK (60 10 .. id) frees the client's
    // reliable send block (conn+0x520 pool) by its wire+0x08 id AND fires its completion cb. That id is
    // GENERATION-INDEPENDENT, so gating acks on hi(msg[2])===0 was the bug: it left every gen>=1 reliable
    // send un-acked. First op07/op08 (leave), then op09 (transition) leaked send-pool blocks each cycle
    // until the pool exhausted (DAT_0025b790=0x65) and the next op06 enter couldn't allocate -> stuck at
    // ~8 cycles. Fix: ACK ALL reliable ops for ANY generation (subject to SNAP_ACK_OPS), keeping ONLY the
    // area-select op48 gate (sawAreaConfirm) — acking area-select op48 is the one case that corrupts.
    const wantsAck = (hi, lo) =>
      (ackAll || (ackSet && ackSet.has(lo)) || (reentryConfirmAck && lo >= 0x06 && lo <= 0x09))
      && !(lo === 0x48 && gateOp48 && !s.sawAreaConfirm);
    const outerFlags = msg.readUInt16BE(0);
    const ids = [];
    // ONLY the outer frame's plaintext id. (No coalesced walk — op48 bodies are encrypted.)
    if ((outerFlags & 0x8000) && wantsAck(msg[2], msg[3])) ids.push(msg.readUInt32BE(0x08));
    for (const id of ids) {
      const rack = Buffer.alloc(20);
      rack[0] = 0x60; rack[1] = 0x10; rack[2] = 0x00; rack[3] = 0x00;
      msg.copy(rack, 0x04, 0x04, 0x08);                    // session token echo
      rack.writeUInt32BE(0, 0x08);                         // no reverse data (f0op2-proven)
      rack.writeUInt32BE(id >>> 0, 0x0c);                  // free the game's message <id>
      rack[0x10] = 0xba; rack[0x11] = 0x47; rack[0x12] = 0x66; rack[0x13] = 0x11;
      sendSnapPacket(s, rack, rinfo, perr => {
        if (perr) { log(s, `  reliable-ack err: ${perr.message}`); return; }
        s.outCount++; s.totalOut += rack.length;
        log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [reliable-ack id=0x${(id >>> 0).toString(16)}] (20b)`);
      });
    }
    // fall through — the application-level handlers below still run.
  }

  // 2026-06-21: f0/op2 = the game's reverse-channel reliable DATA after the op-0x31 establish.
  // Reply with a 0x60 transport ACK whose seqB (+0x0c) = the game's seqA (+0x08) — acknowledging
  // the data it sent. Echoing the frame (old 'unknown' path) over-acked a seq the game never sent
  // and triggered an immediate 820 teardown. SNAP_F0_ACK=0 disables for regression isolation.
  if (klass === 'transport-data-f0op2') {
    if (process.env.SNAP_F0_ACK !== '0') {
      const seqA = msg.readUInt32BE(0x08);
      const ack = Buffer.alloc(20);
      ack[0] = 0x60; ack[1] = 0x10; ack[2] = 0x00; ack[3] = 0x00;
      msg.copy(ack, 0x04, 0x04, 0x08);            // echo token
      ack.writeUInt32BE(0, 0x08);                 // our seqA (no reverse data)
      ack.writeUInt32BE(seqA >>> 0, 0x0c);        // ACK the game's data seq
      msg.copy(ack, 0x10, 0x10, 0x14);            // echo trailer
      sendSnapPacket(s, ack, rinfo, perr => {
        if (perr) { log(s, `  f0-ack err: ${perr.message}`); return; }
        s.outCount++; s.totalOut += ack.length;
        log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [f0op2-transport-ack seqB=0x${seqA.toString(16)}] (20b) ${ack.toString('hex')}`);
      });
    } else {
      log(s, `[udp ${s.key}] ${dt}  (f0/op2 ack disabled SNAP_F0_ACK=0)`);
    }
    return;
  }

  // Suppress reply for kind-0x31 packets with opcodes we don't yet handle.
  // Sending a blind snap-register-reply with no encrypted body is worse than
  // silence â€” the game decrypts garbage and times out anyway, but with extra
  // confusion in the EE state.
  if (klass === 'post-register-other') {
    log(s, `[udp ${s.key}] ${dt}  (suppressed â€” kind-0x31 with unknown opcode 0x${msg[2].toString(16).padStart(2,'0')}${msg[3].toString(16).padStart(2,'0')}; captured for analysis)`);
    return;
  }

  // Suppress reply for the post-slot1c-push application ACK (kind 0xb0, opcode 0x02).
  // Game tears down the SN@P UDP state right after this and moves to TCP 10127.
  if (klass === 'app-ack-op02') {
    log(s, `[udp ${s.key}] ${dt}  (suppressed â€” application ACK opcode 0x02 after slot-1c push; game proceeding to TCP 10127 lobby phase)`);
    if (s.namedSlotDiagFile) {
      recordNamedSlotDiag(s, 'delayed-app-ack-op02-after-namedslot', msg, null);
    }
    return;
  }

  // 2026-06-12: post-join ROOM query (kind=0xa1 cmd=0x0c). The default catch-all
  // (snap-register-reply) answers it with cmd=0x2d which the game REJECTS (keeps
  // retrying → 840). Default: SUPPRESS (silence beats a wrong opcode). Experiment:
  // SNAP_ROOM_QUERY_REPLY=1 sends an echo-cmd (b0..00 0c) reply with the seq fix.
  // Reply seq = regReplySeq + SNAP_ROOM_SEQ_OFFSET (default 2: client accepted
  // register@N and op48@N+1, so the room data should be the next-expected N+2).
  // 2026-07-01 AREA-CONFIRM reply (SNAP_AREA_CONFIRM_REPLY=1). RE: HANDOFF-2026-07-01-room-create-host-path.
  // On select-accept the game sends op06 (area handle) via FUN_001dc9fc and registers the reply at
  // SLOT 0x21 (conn+0x5cc, cb FUN_005bfb40); it then WAITS (FUN_005ad030 case 7) and never advances to
  // the room-list stage (area_id 0x86f840 stays 0, room table empty). Slot 0x21 is reached ONLY via
  // dispatcher FUN_001d9f78 op28 selector 6 (body[0]=6) with the 0x1000 flag (who byte 0xB0 supplies
  // it) + metadata=DATA (op28). FUN_005bfb40 on metadata==0 -> FUN_005c4dc0/FUN_005bdfe0 ADVANCE
  // (u16@body+0xc non-gating). So reply op28/selector-6 to advance area-confirm -> room-list stage.
  // Mirrors the proven SNAP_CMD0C_SELECTOR12 push (selector 12 -> slot 0x26). Falls through so the
  // existing room-enter-reply-a0 still fires. Default OFF; rollback = unset env.
  // Detect op06 DIRECTLY (reliable bit + cmd 0x0006), independent of SNAP_ROOM_RENDER_A0 classification
  // (which is off, so op06 arrives as klass 'unknown'). Confirmed on real PS2: who=0xb0 qsw=0x14 cmd=0x6.
  // 2026-07-02 T9: mark that this session has passed area-select (op06 = area-confirm), INDEPENDENT
  // of the reply flag. Gates the op48 reliable-ack so we only ack the LOBBY op48, never area-select.
  // 2026-07-07 G2 correction: re-entry op0106 is NOT area-confirm. The fresh rig evidence shows it is
  // a coalesced outer reliable frame wrapping an inner op48 NAME/named-slot query at +0x14. The outer
  // op0106 is transport-ACKed above; the app reply must be built from the inner op48 with the existing
  // named-slot-query-reply builder, not from the outer op0106 seq and not as op28 selector 6.
  // 2026-07-10 G12 STEP-0 (v4): re-entry op06 has msg[2] = re-entry GENERATION (0=first, 1=second,
  // 2=third...). Detect ANY reliable op06 with a non-zero generation (v1..v3 only matched msg[2]==1
  // and would miss 3rd+ entries). See docs/findings/protocol/G12-STEP0-WIRE-MATRIX-2026-07-10.md.
  // 2026-07-11 G12: any reliable op06 = an area ENTER -> mark the player present in a lobby. The client
  // never reports WHICH area (dual-capture proven), and rooms are effectively a single global list, so we
  // use area=1 as an "in a lobby" presence marker (enterArea is idempotent). Enables room-cleanup on exit.
  // 2026-07-11 G12: the room-ENTER op06 carries a NON-ZERO room handle at wire+0x10; the area-enter op06 has
  // a ZERO handle there. THE HANDLE is the distinguisher — NOT byte0's 0x40 bit (that is the 0x4000
  // ack-piggyback flag, which varies per packet: the ENTER was 0xe0 in one run, 0xa0 in another; requiring
  // 0x40 made us miss the 0xa0 ENTER and reply area-confirm -> 0x6ff2b1 stayed 0). Require only the reliable
  // bit (0x80) + a non-zero handle. Area-enter (handle=0) is excluded, so no area-entry regression.
  // 2026-07-12 CORRECTION (Ghidra helper:16099 FUN_005c04f0 + second_opinion): the ENTER sender has NO
  // nonzero-handle gate — a create on a Vacant slot transmits op06 with handle=0 (0x6fee68[idx] unwritten)
  // and the typed title at +0x19. Requiring a non-zero handle made us classify it as an area-confirm and
  // answer slot 0x21 instead of the ENTER slot 0x22 -> 0x6ff2b1 stayed 0 -> fields locked, Finish stuck
  // (rig 2026-07-12 10:13). The standalone room-ENTER form is declared len 0x28 (44B; FUN_001dcdfc body is
  // a fixed 0x18); area-enter op06s declare 0x14. So: room-ENTER = len 0x28 AND (handle != 0 OR name at
  // +0x19 non-empty). The zero-handle+name case is a Vacant-slot create.
  const decl06 = ((msg[0] & 0x03) << 8) | msg[1];
  const isRoomEnter06 = msg[3] === 0x06 && (msg[0] & 0x80) && msg.length >= 44 && decl06 === 0x28
    && (msg.readUInt32BE(0x10) !== 0 || msg[0x19] !== 0);
  if (LOBBY_STATE_ON() && msg[3] === 0x06 && (msg[0] & 0x80) && !isRoomEnter06) lobbyState.enterArea(s.key, 1);
  const reentry0106 = process.env.SNAP_REENTRY_CONFIRM_REPLY === '1'
      && msg[2] >= 0x01 && msg[3] === 0x06 && (msg[0] & 0x80) && !isRoomEnter06;
  if (reentry0106) {
    // 2026-07-10 G12 STEP-0 ROOT CAUSE (PINE + Ghidra FUN_001d9f78 + FUN_005bfb40, all ground-truth):
    // the op06-completion matcher FUN_005be120 -> FUN_005ad9f0 -> FUN_005f74d0 (screen 0x6c4b90 1->2,
    // objF 0x6c4b9f 5->0) fires ONLY if the op28 reply's MATCH KEY == the op06 send-seq stored at
    // conn+0x618. Ghidra dispatch FUN_001d9f78 case 0x25/sel6 hands the slot-0x21 handler a match key
    // uStack_34 = (*(ushort*)(param_2+0x2e) >> 8) = the reply frame's SUB byte (wire+0x02). FUN_005bfb40
    // then does uRam006cbc80 = (short)*(param_1+0xc) = that sub byte. So the reply's sub byte MUST equal
    // the op06 send-seq. PINE at a live re-entry stall: armed async slot 0 key16 = 0x0001 = send-seq,
    // while first-entry's was 0x0000. First-entry "works" only by luck (send-seq 0 == our hardcoded
    // sub 0); on re-entry send-seq=1 but we still sent sub=0 -> mismatch -> objF frozen at 5.
    // The client stamps its send-seq into the op06 request's sub byte (msg[2]), so echo msg[2] as the
    // reply sub. Body/selector/seq/ack are NOT the match key (the handler ignores the body). NO GUESS.
    const push = Buffer.alloc(0x1C);
    push[0] = 0xB0; push[1] = 0x18; push[2] = msg[2]; push[3] = 0x28;  // op28 -> slot 0x21; sub = send-seq (MATCH KEY)
    msg.copy(push, 4, 4, 16);                         // session + op06 seq(+0x08) + ack(+0x0c) mirror
    push.writeUInt32BE(6, 0x10);                     // body[0] = selector 6 (routing -> slot 0x21)
    push.writeUInt32BE(0, 0x14);                      // body[1] = 0 (not the match key; ignored by handler)
    push[0x18] = 0xba; push[0x19] = 0x47; push[0x1a] = 0x66; push[0x1b] = 0x11;
    sendSnapPacket(s, push, rinfo, () => {});
    s.outCount++; s.totalOut += push.length;
    log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [reentry op06 op28 sel=6 sub=0x${msg[2].toString(16)} (=send-seq match key)] (${push.length}b) ${push.toString('hex')}`);
    return;
  }

  // 2026-07-12 G12 CREATE-SLOT ACCEPT (SNAP_CREATE_SLOT_ACCEPT=1). ROOT CAUSE of the create hang, proven
  // from a POST-FINISH savestate (slot 4) + decompile: the ACTUAL create SM is FUN_005f99c0 (NOT the
  // op06-ENTER path FUN_005fada0 the earlier work targeted). It sends the room-register as **op04** via
  // func_0x001dc508 (opcode 4, cb FUN_005c3a40 installed at slot 0x1f), then parks in FUN_005c3490 state
  // 0x6cba78==2 waiting for 0x6cba7d==1. FUN_005c3a40 sets 0x6cba7d=1 (+ 0x6ff2b0=1, writes the handle to
  // 0x6fee8c) ONLY on an op28/selector-4/status-0 reply -> dispatcher FUN_001d9f78 case 0x25 inner-case-3
  // -> conn+0x5c4 = slot 0x1f. Then FUN_005c3490 sets uRam006ff2b1=1 = the SINGLE gate that unlocks
  // title/password/scenario. Frozen proof: 0x6cba7d=0, op pending, 0x6ff2b1=0. Our server NEVER answered
  // op04 (pcap create_run frame 295: op04 "PAL ..." followed only by op41 inputs) -> create hung, 20+ times.
  // The unlock needs ONLY status 0 (auto for a plain op28); the handle at body+1 (wire+0x14) is a bonus for
  // the 0x6fee8c registry, so this is not sensitive to the send-seq/handle byte-order that broke prior tries.
  // Default OFF (golden-safe). Verify by PINE: 0x6cba7d 0->1, then 0x6ff2b1 0->1 (fields unlock).
  if (msg[3] === 0x04 && (msg[0] & 0x80) && process.env.SNAP_CREATE_SLOT_ACCEPT === '1') {
    let handle = 0;
    if (process.env.SNAP_LOBBY_STATE === '1') {
      const room = lobbyState.createRoom(s.key, { name: 'ROOM', maxPlayers: 4 });
      handle = room.handle >>> 0; s.roomHandle = handle;
      // ===== TEST SCAFFOLD (SNAP_TEST_FORCE_GOLIVE, default OFF) — TEMPORARY synthetic stand-in for the
      // UN-CAPTURED PAL 0x6504 host go-live (RF-14). Fires the reference-faithful lobby_engine.goLive
      // (INCREATE->GAMESET; no direct status write, no timer, explicit+deterministic once-on-create) so the
      // engine-owned JOIN pipeline can be validated. Validates ONLY post-go-live membership, NOT create/
      // config/go-live. REMOVE before create-to-gameplay is considered implemented. Normal path = INCREATE.
      if (process.env.SNAP_TEST_FORCE_GOLIVE === '1') {
        const prevStatus = room.status;
        lobbyEngine.goLive(s.key);
        console.error(`[TEST-SCAFFOLD] SYNTHETIC GO-LIVE room=0x${room.handle.toString(16)} status ${prevStatus}->${room.status} (INCREATE->GAMESET) -- TEMPORARY synthetic replacement for the uncaptured PAL 0x6504 go-live; validates post-go-live membership ONLY, not create/config/go-live protocol`);
      }
    }
    // 2026-07-12 G12-2: the op04 accept enters the new-game-lobby, after which the CLIENT pulls a member/config
    // burst (op0a member-list + op09 USER/MAXI + ...). Mark the create context so the op0a answer becomes a
    // real member-list (creator = member 1) instead of the count=0 modifier-panel reply. RE:
    // G12-populated-room-after-create-RE-2026-07-12. Cleared on area exit (op07/op08).
    s.inCreate = true;
    const txSeq = nextTxSeq(s);
    const push = Buffer.alloc(0x1C);                 // 16 hdr + 8 body + 4 trailer
    push[0] = 0xB0; push[1] = 0x18; push[2] = 0x00; push[3] = 0x28;  // op28 who=0xB0 -> case 0x25
    msg.copy(push, 4, 4, 16);                         // session token + ack mirror
    push.writeUInt32BE(txSeq >>> 0, 0x08);           // in-order server->client seq
    push.writeUInt32BE(4, 0x10);                     // body[0] = selector 4 (BE) -> inner case 3 -> slot 0x1f
    push.writeUInt32LE(handle, 0x14);                // body[1] = minted handle -> FUN_005c3a40 -> 0x6fee8c
    push[0x18] = 0xba; push[0x19] = 0x47; push[0x1a] = 0x66; push[0x1b] = 0x11;
    sendSnapPacket(s, push, rinfo, () => {});
    s.outCount++; s.totalOut += push.length;
    log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [CREATE-SLOT accept op04->op28 sel=4 handle=0x${handle.toString(16)} seq=0x${txSeq.toString(16)}] (${push.length}b) ${push.toString('hex')}`);
    // 2026-07-26 G12 (SNAP_MEMBER_JOIN_AT_ACCEPT=1). The create-self op06 was dropped un-acked 12/13 times
    // when emitted MID-BURST inside the later op0a cascade. Transport RE (analysis/op06-accept-criterion-
    // RE-2026-07-26.txt): the client acks an inbound reliable seg only if msgSeq >= its live expected-seq
    // (reorder gate **(conn+0x5c), FUN_001d6988), BEFORE app dispatch. Emitting op06 HERE — the first,
    // lowest-seq reliable immediately after the op04-accept — gives it the contiguous next seq so it lands
    // in-window and is acked. s.memberJoinPushed guards the later op0a-context copies from double-firing.
    if (process.env.SNAP_MEMBER_JOIN_AT_ACCEPT === '1' && process.env.SNAP_MEMBER_JOIN_PUSH === '1') {
      s.memberJoinPushed = true;
      sendMemberJoinOp06(s, msg, rinfo, dt, 'create-self-at-accept', handle || 1, realMemberName(s.key, 'CREATOR'));
      // 2026-07-26 G12 (SNAP_MEMBER_JOIN_SETTLE=1). The at-accept op06 populates roster row0 in memory
      // (rig-verified) but the client does NOT repaint: op06 fires event 0x1f (roster ADD) THEN event 0x19
      // (the generic "roster changed, refresh UI" notify — analysis/roster-row-draw-RE-2026-07-26 ADDENDUM 3,
      // helper:12180; op07-leave fires it too, helper:12250). The self-op06's 0x19 fires while the room node
      // is still BUILDING, so it no-ops; the 07-16 joiner's identical 0x19 repainted because the node was
      // parked/settled. Re-emit the SAME op06 ~500ms later (node settled) to re-fire 0x19 with the panel up.
      // Dedup-safe: FUN_005b5ac0 returns early for an already-present member (helper:8713-8724) — no double
      // row / no count inflation. Fresh in-window seq allocated inside sendMemberJoinOp06.
      if (process.env.SNAP_MEMBER_JOIN_SETTLE === '1') {
        const settleHandle = s.roomHandle, settleName = realMemberName(s.key, 'CREATOR');
        setTimeout(() => {
          if (s.roomHandle === settleHandle && s.addr16) {
            sendMemberJoinOp06(s, null, rinfo, dt, 'create-self-settle', (settleHandle >>> 0) || 1, settleName);
          }
        }, 500);
      }
    }
    if (process.env.SNAP_ROOM_LIMITS_OP10SUB5 === '1') {
      sendRoomLimitsOp10Sub5(s, msg, rinfo, dt);
    }
    return;
  }

  // 2026-07-11 G12 ROOM-ENTER accept (SNAP_ROOM_ENTER_ACCEPT=1). snap-re dump-proven
  // (G12-enter-accept-reply-RE-2026-07-11): the "Enter Room" ENTER is a SN@P type-14 session-open op06
  // (msg[0]=0xe0 -> bit 0x40 SET; area-enter op06 = 0x80/0xb0, 0x40 CLEAR) carrying the room handle at
  // wire+0x10. FUN_005c04f0@helper:16099 installs cb FUN_005c05c0 at slot 0x22. Dispatcher FUN_001d9f78
  // selector-6 case routes by the DATA (0x1000) flag: who 0xB0 (DATA SET) -> area slot 0x21; who 0xA0
  // (DATA CLEAR) -> room-enter slot 0x22 -> FUN_005c05c0 accept branch sets uRam006ff2b1=1/6ff2b2=1
  // (unlocks the room). So the ONLY diff from area-confirm is who=0xA0. reply[0]=0 is the dispatcher
  // status byte (auto-0 for a plain cmd 0x28). FUN_005c05c0 ignores the SUB byte, but echo msg[2] for
  // cross-gen parity (harmless). op0f "OBAREA-V1" only needs the transport ACK (multigen-ack handles it).
  if (isRoomEnter06 && process.env.SNAP_ROOM_ENTER_ACCEPT === '1') {
    const txSeq = nextTxSeq(s);
    const push = Buffer.alloc(0x1C);                 // 16 hdr + 8 body + 4 trailer
    push[0] = 0xA0; push[1] = 0x18; push[2] = msg[2]; push[3] = 0x28;  // who 0xA0 (DATA clear) -> slot 0x22 = FUN_005c05c0
    msg.copy(push, 4, 4, 16);                         // session token + ack mirror
    push.writeUInt32BE(txSeq >>> 0, 0x08);           // in-order server->client seq (transport delivery)
    push.writeUInt32BE(6, 0x10);                     // body[0] = selector 6 (BE) -> dispatcher case 5
    push.writeUInt32BE(0, 0x14);
    push[0x18] = 0xba; push[0x19] = 0x47; push[0x1a] = 0x66; push[0x1b] = 0x11;
    sendSnapPacket(s, push, rinfo, () => {});
    s.outCount++; s.totalOut += push.length;
    log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [ROOM-ENTER accept op28 sel=6 who=0xA0 sub=0x${msg[2].toString(16)} handle=0x${msg.readUInt32BE(0x10).toString(16)} seq=0x${txSeq.toString(16)}] (${push.length}b) ${push.toString('hex')}`);
    // 2026-07-12 G12 Track A + CREATE: register this endpoint in lobby_state BEFORE the op10 push so the
    // pushed room-info can describe the right room. CREATE-vs-JOIN discriminant [L, needs-rig] (both 44B,
    // same builder FUN_001dcdfc — G12-create-accept-wireformat-RE-2026-07-12.md M2): the name field at
    // wire+0x19 was the PLAYER-TYPED title on the one captured create ("REA-V1") and EMPTY on the one
    // captured join; wire+0x10 is unreliable for create (it read the existing registry handle 1). On create: lobbyState.createRoom
    // MINTS the real handle (client gets it in the op09 USER/MAXI replies -> 0x6fee68 registry) and the
    // creator becomes host. On join: register membership so the op49 count is real (2/4 both clients in).
    // The op49 wrote the handle at rec+0x24 with writeUInt32LE; the client ENTERs it back in the same LE
    // bytes, so msg.readUInt32LE(0x10) = the registry handle directly (no byteswap).
    if (process.env.SNAP_LOBBY_STATE === '1') {
      const nameEnd = msg.indexOf(0, 0x19);
      const roomName = msg.toString('latin1', 0x19, nameEnd > 0x19 ? Math.min(nameEnd, msg.length - 4) : 0x19);
      if (roomName.length > 0 && process.env.SNAP_CREATE_FLOW === '1') {
        // Bind the room to the vacant-slot handle the client ENTERed (wire+0x10, LE — same bytes we
        // advertised at rec+0x24); lobby_state falls back to minting fresh if it isn't a free vacant handle.
        const room = lobbyState.createRoom(s.key, { name: roomName, maxPlayers: 4, handle: msg.readUInt32LE(0x10) >>> 0 });
        s.roomHandle = room.handle;
        s.pendingCreateStat = true;    // arm the op08 'STAT' mint-accept (cleared there / on exit)
        console.error(`[lobby_state] CREATE ${s.key} minted handle=0x${room.handle.toString(16)} "${room.name}" host | registry: ${JSON.stringify(lobbyState.stats())} rooms=${lobbyState.roomList().map(r => r.name + ':' + r.current + '/' + r.max).join(',')}`);
        // ===== TEST SCAFFOLD (SNAP_TEST_FORCE_GOLIVE, default OFF) — REMOVE before create-to-gameplay is done.
        // TEMPORARY, SYNTHETIC stand-in for the UN-CAPTURED PAL 0x6504 host go-live (RF-14): it fires the
        // reference-faithful lobby_engine.goLive transition (INCREATE->GAMESET) so the engine-owned JOIN
        // pipeline can be validated on hardware. It does NOT implement create/config/go-live and validates
        // ONLY the post-go-live membership lifecycle. Explicit + deterministic (once, on create); NO timer,
        // NO implicit mutation, NO direct room.status write (goLive owns the transition). Normal behavior
        // stays INCREATE. The real PAL go-live capture (U7) remains a separate critical-path blocker.
        if (process.env.SNAP_TEST_FORCE_GOLIVE === '1') {
          const prevStatus = room.status;
          lobbyEngine.goLive(s.key);
          console.error(`[TEST-SCAFFOLD] SYNTHETIC GO-LIVE room=0x${room.handle.toString(16)} status ${prevStatus}->${room.status} (INCREATE->GAMESET) -- TEMPORARY synthetic replacement for the uncaptured PAL 0x6504 go-live; validates post-go-live membership ONLY, not create/config/go-live protocol`);
        }
      } else {
        const regH = msg.readUInt32LE(0x10) >>> 0;
        // SINGLE mutation path: when the engine owns the join it mutates lobby_state itself (below), so here
        // we only LOOK UP the room (no legacy mutation). Legacy path (engine OFF) mutates here as before.
        const room = ROOM_ENGINE_ON() ? lobbyState.rooms.get(regH) : lobbyState.joinRoom(s.key, regH);
        s.roomHandle = room ? room.handle : null;
        // console.error -> journal-visible even under SNAP_LEAN_HOTPATH (the join is the Track-A proof point).
        console.error(`[lobby_state] JOIN ${s.key} handle=0x${regH.toString(16)} -> ${room ? room.members.size + '/' + room.maxPlayers + ' "' + room.name + '"' : 'NOT FOUND'}  | registry: ${JSON.stringify(lobbyState.stats())} rooms=${lobbyState.roomList().map(r => r.name + ':' + r.current + '/' + r.max).join(',')}`);
        // 2026-07-13 G12-5 JOINER BROADCAST (SNAP_JOINER_BROADCAST=1): B just joined room `room`. Push B's
        // member record to each EXISTING member's session (A sees B), and push each existing member to B
        // (B sees A) — symmetric, so both draw without depending on the op0a whole-list path. Synthetic
        // per-member id/name (join order) until real identity (IDHNPAIRS/HNSELECT) lands. snap-re: member-JOIN
        // alone draws the row (FUN_005b5ac0 <- record). Durability (op0a must also carry B) is the follow-up.
        // CONSOLIDATION C1 (SNAP_ROOM_ENGINE=1): the AUTHORITATIVE path. lobbyState.joinRoom already
        // mutated the registry above; ask the engine to re-push the full room state to EVERY member.
        // The full member-list push fills each member's whole-list buffer (0x6cdbe6) with ALL members,
        // so the client's redraw (and the sub-1 rebuild) draw a COMPLETE roster -> the creator no
        // longer loses the joiner (the 2026-07-17 wipe). Replaces the ad-hoc delta broadcasts below.
        if (ROOM_ENGINE_ON()) {
          // ENGINE owns the join: lobbyEngine.joinRoom does the SINGLE lobby_state mutation AND returns one
          // ordered plan (op06 delta to existing -> op0a durable to all -> count). The legacy lobbyState.
          // joinRoom above is skipped under the flag, and the legacy inline broadcasts below are the else.
          const res = lobbyEngine.joinRoom(s.key, regH);
          s.roomHandle = res.room ? res.room.handle : null;
          if (res.ok) { const sum = engineAdapter().execute(res.plan, 'join'); console.error(`[engine] JOIN ${s.key} h=0x${regH.toString(16)} already=${res.alreadyMember || false} ${res.room.members.size}/${res.room.maxPlayers} sent=${sum.sent} ${JSON.stringify(sum.byKind)}`); }
          else console.error(`[engine] JOIN ${s.key} h=0x${regH.toString(16)} REJECT ${res.reason}`);
        } else if (room && process.env.SNAP_JOINER_BROADCAST === '1') {
          const members = [...room.members];                 // idKeys, join order; B is the newest
          const bId = members.length;                        // B's 1-based synthetic id
          const bName = realMemberName(s.key, 'PLAYER' + bId);   // B's login handle (SNAP_REAL_NAMES)
          for (const epKey of lobbyState.roomMemberEndpoints(room.handle, s.key)) {
            const other = sessions.get(epKey);
            if (other) sendMemberJoinBroadcast(other, bId, bName);   // A sees B
          }
          members.forEach((m, i) => {
            const p = lobbyState.players.get(m);
            if (!p || p.udpKeys.has(s.key)) return;          // B's own record is pushed below
            sendMemberJoinBroadcast(s, i + 1, realMemberName(m, 'PLAYER' + (i + 1)));   // B sees A
          });
          // 2026-07-17 G12: B sees B — the joiner-SELF push. Slot-10 savestate + journal (roster test
          // 08:08): the displayed "N play" is the push-driven count 0x6cfb62 (creator: self+broadcast=2
          // matched its display; joiner: broadcast-only=1 matched its "1"). Each client needs one push
          // per member INCLUDING itself — same as the create-self push the creator gets (T17), and
          // Bioserver's SLOTPLRSTATUS broadcast includes the joiner. Fires once per join event.
          sendMemberJoinBroadcast(s, bId, bName);                             // B sees B
        }
      }
    }
    // 2026-07-12 G12 PROACTIVE ROOM-INFO: push the op10 sub-1 IMMEDIATELY after the accept so the room opens
    // instantly. RE (g12-op10window-test): the client waits ~6s after the accept before pinging op10 itself
    // (a fallback); a real host pushes the room-info now. delivery in-window here (measured backlog=0).
    if (process.env.SNAP_ROOM_INFO_OP10 === '1' && process.env.SNAP_ROOM_INFO_PROACTIVE !== '0') {
      // role byte: 1 = creator/host (drives the STAT mint path via 0x6c5539), 0 = joiner.
      sendRoomInfoOp10(s, msg, rinfo, dt, 'PROACTIVE-after-accept', s.pendingCreateStat ? 1 : 0);
    }
    return;
  }

  // 2026-07-11 G12 ROOM-INFO op10 (SNAP_ROOM_INFO_OP10=1) — OPENS the room. snap-re dump-proven
  // (G12-inroom-handshake-RE-2026-07-11): after the enter-accept sets 0x6ff2b1=1, the screen id
  // 0x6cbc7e is still 2 (transitional) — the room only RENDERS when 0x6cbc7e flips to 0x10, and the ONLY
  // code that does that is the op10 room-manager sub-1 handler FUN_005bbb90 (slot 0x13 FUN_005bba20 case 1),
  // which also fires UI event 0xc = BUILD ROOM. The client sends op10 (roster ping) which we only 60-ACK'd
  // -> screen stuck at 2 -> hang. FIX = reply with a REAL op10 (opcode 0x10, who=0xA0 so 0x1000/0x400 clear
  // -> dispatcher case 0xd -> slot 0x13) carrying sub-command 1 + a 0x300 room-descriptor blob. Layout
  // mirrors the client's own sub-1 builder FUN_005c4d20 (helper:19078): app_body[0]=sub, [1..3]=pad,
  // [4..0x304)=blob; SN@P body offset 0x10 -> sub@wire+0x10, blob@wire+0x14. The screen FLIP is
  // unconditional in case 1 (proved); the blob CONTENTS (room name/host/rules layout) are needs-rig.
  if (msg[3] === 0x10 && (msg[0] & 0x80) && process.env.SNAP_ROOM_INFO_OP10 === '1') {
    // 2026-07-16 G12-5 JOINER RENDER (SNAP_JOIN_OP10_SUBC=1). T21 trace + snap-re G12-joiner-tag17-RE:
    // the op10 app payload starts at wire+0x18 and byte[0] there is a SUB-SELECTOR dispatched by slot 0x13
    // FUN_005bba20. A JOINER (host 0x6ff2b0==0) parks its screen-4 SM at major 0x6c4b9f==5 (FUN_005fed70
    // advances only on step 0x6c4ba0==1) and sends op10 sub-0x02 (join-request), storing continuation
    // FUN_00601300 in uRam006fec00 under pending tag 0x6c4fbb=0x17. A real host answers sub-0x02 with
    // sub-0x0C (FUN_005bbc20 -> FUN_005c6050); FUN_005bbe00 (the 0x0C case, helper:12526-12541) fires the
    // continuation, which on blob status 0 does step++ -> 1 -> major 5->6 -> the room RENDERS (savestate
    // slot-1 disassembly of 0x601300 confirms: tag-0x17 guard, clear tag, status==0 -> step+=1; else
    // major=7 error). Our sub-1 push does NOT fire it = the joiner "moving background" stall. Reply body:
    // +0x10 header word 1 (BE, mirror), +0x14 echo the request's token word, +0x18 sub 0x0C,
    // +0x1c member count LE (FUN_005bbe00 reads payload+4 as the displayed count; real registry count).
    if (process.env.SNAP_JOIN_OP10_SUBC === '1' && msg.length >= 0x1c && msg[0x18] === 0x02) {
      const txSeq = nextTxSeq(s);
      const push = Buffer.alloc(0x24);                 // 16 hdr + 16 body + 4 trailer
      push[0] = 0xA0; push[1] = 0x20; push[2] = 0x00; push[3] = 0x10;  // who 0xA0 DATA-clear -> slot 0x13
      msg.copy(push, 4, 4, 16);                        // session token + ack mirror
      push.writeUInt32BE(txSeq >>> 0, 0x08);           // in-order reliable seq
      push.writeUInt32BE(1, 0x10);                     // header word = 1 (mirror the proven sub-1 push)
      msg.copy(push, 0x14, 0x14, 0x18);                // echo the request's token word (02f807d0)
      push[0x18] = 0x0c;                               // SUB 0x0C = join-accept -> FUN_005bbe00 fires the continuation
      let count = 1;
      if (process.env.SNAP_LOBBY_STATE === '1' && s.roomHandle != null) {
        const r = lobbyState.roomList().find(x => x.handle === s.roomHandle);
        if (r && r.current > 0) count = r.current;
      }
      push.writeUInt32LE(count >>> 0, 0x1c);           // payload+4 = displayed member count
      push[0x20] = 0xba; push[0x21] = 0x47; push[0x22] = 0x66; push[0x23] = 0x11;
      sendSnapPacket(s, push, rinfo, () => {});
      s.outCount++; s.totalOut += push.length;
      log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [JOIN-ACCEPT op10 sub=0x0c count=${count} (fires 0x601300: step->1, major 5->6, RENDER) seq=0x${txSeq.toString(16)}] (${push.length}b) ${push.toString('hex')}`);
      return;
    }
    // 2026-07-19 STABLE-MEMBERSHIP slice 1 (SNAP_LIVENESS_REPLY=1): the client's in-room liveness poll is
    // op10 sub-0x0e (FUN_005c6150, non-host ~30s countdown). The correct PEER reply is op10 sub-0x0f, whose
    // client handler FUN_005bc350 sets the alive-flag 0x6ff2b2=3 and resets the self-eject countdown
    // (SPINE-2-3 op10 sub table lines 135-136). RF-8 (2-device): the current fallback answers with sub=1
    // (ROOM-INFO ping-response) — the WRONG reply — so the joiner self-ejects ~80s. Codex readiness review:
    // decompile-proven. Framed like the proven JOIN-ACCEPT (who=0xA0 DATA-clear -> slot 0x13; contiguous
    // reliable seq). Rig-validate: the joiner stays in-room past 80s. Default OFF = legacy behavior.
    if (process.env.SNAP_LIVENESS_REPLY === '1' && msg.length >= 0x1c && msg[0x18] === 0x0e) {
      const txSeq = nextTxSeq(s);
      const push = Buffer.alloc(0x24);                  // 16 hdr + 16 body + 4 trailer (mirror JOIN-ACCEPT)
      push[0] = 0xA0; push[1] = 0x20; push[2] = 0x00; push[3] = 0x10;  // who 0xA0 DATA-clear -> slot 0x13, op10
      msg.copy(push, 4, 4, 16);                         // session token + ack mirror
      push.writeUInt32BE(txSeq >>> 0, 0x08);            // in-order reliable seq
      push.writeUInt32BE(1, 0x10);                      // header word mirror
      msg.copy(push, 0x14, 0x14, 0x18);                 // echo the request's token word
      push[0x18] = 0x0f;                                // SUB 0x0f = liveness reply -> FUN_005bc350: 0x6ff2b2=3
      push[0x20] = 0xba; push[0x21] = 0x47; push[0x22] = 0x66; push[0x23] = 0x11;
      sendSnapPacket(s, push, rinfo, () => {});
      s.outCount++; s.totalOut += push.length;
      log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [LIVENESS-REPLY op10 sub=0x0f (FUN_005bc350 -> 0x6ff2b2=3) seq=0x${txSeq.toString(16)}] (${push.length}b) ${push.toString('hex')}`);
      return;
    }
    // The client's op10 roster ping (a ~6s fallback if the host never pushed room-info). We normally push
    // proactively right after the enter-accept (above), so this is a backstop / re-render. Same op10 sub-1,
    // same role as the proactive push (re-assert host role if a create is pending — also covers the
    // "0x6c5539 overwritten by a client-local sub-1" confounder flagged in the populated-room doc).
    sendRoomInfoOp10(s, msg, rinfo, dt, 'ping-response', s.pendingCreateStat ? 1 : 0);
    if (process.env.SNAP_ROOM_LIMITS_OP10SUB5 === '1' && s.roomHandle != null) {
      sendRoomLimitsOp10Sub5(s, msg, rinfo, dt);
    }
    return;
  }

  // 2026-07-12 G12 CREATE REGISTERS (SNAP_CREATE_FLOW=1): the in-room mode-4 burst's op09 'USER'(sub0)
  // / 'MAXI'(sub1) session-opens — builders FUN_005bffa0/FUN_005c02b0 via main-ELF FUN_001dd5f8 (body
  // [u32][tag], wire opcode 9, send-seq conn+0x61d = the SUB byte, cb slot 0x16). Consumer FUN_005c0060
  // (helper:15878/15893). These were NEVER answered -> the mode-4 poller never reached phase 8 -> STAT
  // never fired = THE create stall (trackA pkt 384; G12-create-accept-wireformat-RE-2026-07-12.md M4/M6).
  // Reply = op28 who=0xA0 (DATA clear), selector 9 -> slot 0x16, SUB byte echoed (match key), status
  // auto-0; body: word1 = the ROOM HANDLE (-> the client's 0x6fee68 registry — where the server DELIVERS
  // the minted handle), word2 = tag echo (raw ASCII; dispatcher byteswap makes it the 0x55534552/
  // 0x4d415849 constant FUN_005c0060 compares), word3 = value (USER: member count; MAXI: max players).
  // Word byte order BE, mirroring the proven sel-6/sel-12 pushes (dispatcher byteswaps body words).
  // Rig check [L]: PINE 0x6fee8c == handle after USER; 0x6cfb6c == 1 after MAXI; then op08 'STAT' appears.
  if (msg[3] === 0x09 && (msg[0] & 0x80) && msg.length >= 0x1c
      && process.env.SNAP_CREATE_FLOW === '1') {
    const tag = msg.toString('latin1', 0x14, 0x18);
    if (tag === 'USER' || tag === 'MAXI') {
      const room = (s.roomHandle != null) ? lobbyState.rooms.get(s.roomHandle) : null;
      const handle = room ? room.handle : (s.roomHandle >>> 0 || 0);
      const value = tag === 'USER' ? (room ? room.members.size : 1) : (room ? room.maxPlayers : 4);
      const txSeq = nextTxSeq(s);
      const total = 0x24;                              // 16 hdr + 0x10 body + 4 trailer
      const push = Buffer.alloc(total);
      push[0] = 0xA0; push[1] = (total - 4) & 0xff; push[2] = msg[2]; push[3] = 0x28;  // sub = send-seq echo
      msg.copy(push, 4, 4, 16);                        // session token + seq/ack mirror
      push.writeUInt32BE(txSeq >>> 0, 0x08);           // in-order server->client seq
      push.writeUInt32BE(9, 0x10);                     // body word0 = selector 9 -> slot 0x16
      push.writeUInt32BE(handle >>> 0, 0x14);          // word1 = room handle -> 0x6fee68 registry
      msg.copy(push, 0x18, 0x14, 0x18);                // word2 = tag echo (raw request bytes)
      push.writeUInt32BE(value >>> 0, 0x1c);           // word3 = USER count / MAXI max-players
      push[0x20] = 0xba; push[0x21] = 0x47; push[0x22] = 0x66; push[0x23] = 0x11;
      sendSnapPacket(s, push, rinfo, () => {});
      s.outCount++; s.totalOut += push.length;
      log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [create-register op09 ${tag} sel=9 sub=0x${msg[2].toString(16)} handle=0x${handle.toString(16)} value=${value} seq=0x${txSeq.toString(16)}] (${push.length}b) ${push.toString('hex')}`);
      console.error(`[lobby_state] REGISTER ${tag} ${s.key} handle=0x${handle.toString(16)} value=${value}${room ? ` "${room.name}"` : ' (NO ROOM — handle fallback)'}`);
      return;
    }
    log(s, `[udp ${s.key}] ${dt}  [op09 unknown tag "${tag}" — not answered, needs RE]`);
  }

  const areaConfirm06 = msg[3] === 0x06 && (msg[0] & 0x80) && !isRoomEnter06 && msg[2] === 0x00;
  if (areaConfirm06) s.sawAreaConfirm = true;
  if (areaConfirm06 && process.env.SNAP_AREA_CONFIRM_REPLY === '1') {
    const txSeq = nextTxSeq(s);
    const push = Buffer.alloc(0x1C);                 // 16 hdr + 8 body + 4 trailer
    push[0] = 0xB0; push[1] = 0x18; push[2] = 0x00; push[3] = 0x28;  // op28, who 0xB0 (0x1000 flag) -> case 0x25
    msg.copy(push, 4, 4, 16);                         // session mirror + cumulative-ack field
    push.writeUInt32BE(txSeq >>> 0, 0x08);           // in-order server->client seq
    push.writeUInt32BE(6, 0x10);                     // body[0] = selector 6 (BE) -> sub-case 5 -> slot 0x21
    push.writeUInt32BE(0, 0x14);                      // body[1] = 0 (u16 @body+0xc is non-gating)
    push[0x18] = 0xba; push[0x19] = 0x47; push[0x1a] = 0x66; push[0x1b] = 0x11;
    sendSnapPacket(s, push, rinfo, () => {});
    s.outCount++; s.totalOut += push.length;
    log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [area-confirm op28 sel=6 seq=0x${txSeq.toString(16)}] (${push.length}b) ${push.toString('hex')}`);
  }
  // 2026-07-03 LOBBY LEAVE reply (SNAP_LOBBY_LEAVE_REPLY=1) — completes the Triangle-back exit
  // (lobby -> Area Select). RE (lobby-back-exitarea-RE-2026-07-03.md, subagent): back arms a leave
  // driver (FUN_005c1c80) that sends op07 x2 (senders FUN_001dd07c flags 0xb000 -> reply slot 0x23;
  // FUN_001dd1dc flags 0xa000 -> slot 0x24) + op08 (FUN_001dd33c -> slot 0x25) and WAITS on
  // cRam006cbb6d; only when it flips does phase 4 write 0x6c4b90 = 1 (back to Area Select). Answer
  // op28/selector-7 (who 0xB0 = DATA-set -> slot 0x23; who 0xA0 = DATA-clear -> slot 0x24) +
  // selector-8 (who 0xA0 -> slot 0x25), status 0 -> FUN_005bfe90->FUN_005bdfe0->FUN_005be120->cb
  // 0x5c1c30 sets cRam006cbb6d -> leave completes. Same op28/selector family as area-confirm (sel6).
  // CAVEAT: op07/op08 share the conn+0x520 send pool; if they don't transmit (0x25b790=0x65) the
  // reply can't help. Detect op07/op08 DIRECTLY (arrive as klass 'unknown'). Default OFF.
  // 2026-07-03 RE-ENTRY FIX: back-nav (op07/op08) returns to Area Select, so RESET s.sawAreaConfirm
  // (set on op06) — otherwise the re-entry area op48 stays on the lobby ECHO path instead of the
  // AREA0001-nn substitution, the area handles are wrong, and the next area-confirm can't advance
  // (screen stuck at 1). Independent of the reply flag so the gate always resets on back-nav.
  // 2026-07-10 G12 STEP-0: the leave (op07/op08) completion uses the SAME match mechanism as op06
  // (reply SUB byte == the request's send-seq/generation; Ghidra FUN_001d9f78 uStack_34). The 2nd
  // back-nav (lobby re-entered -> back) has generation 1, so gating on msg[2]===0x00 dropped it AND
  // hardcoding push[2]=0x00 mismatched its send-seq -> stuck. Mirror the op06 fix: fire for any
  // generation and echo push[2]=msg[2]. (op07-sub==send-seq is inferred by analogy to op06; the
  // re-drive capture confirms.) See docs/findings/protocol/G12-STEP0-WIRE-MATRIX-2026-07-10.md.
  // 2026-07-12 G12 CREATE STAT (SNAP_CREATE_FLOW=1): the create/mint finalize — op08 via the tagged
  // sender FUN_001dd33c, body word0 = 'STAT' ASCII at wire+0x10 (bswap('STAT') stored LE = natural
  // order on the wire), send-seq conn+0x61c, cb slot 0x25. Fires from the mode-4 poller phase 8 ONLY
  // after USER/MAXI/op0a complete (G12-create-accept-wireformat-RE-2026-07-12.md M7). Reply = op28
  // who=0xA0 selector 8 -> slot 0x25, SUB echo, status 0; body word1 = the minted handle — [R] the
  // 0x6ca97c owned-slot consumer 0x5c06b0 is outside the dumps (reply offset UNCONFIRMED, mirrored from
  // the op09 form); rig check = PINE 0x6ca97c == handle.
  // MUST precede the op07/08 leave lines below: a create-STAT hitting exitArea would DISSOLVE the
  // room it just minted. Discriminant = 'STAT' tag + a pending create on this session. The leave
  // op08's tag is unconfirmed (no op08 in any capture yet) — the log below collects that evidence.
  if (msg[3] === 0x08 && (msg[0] & 0x80) && msg.length >= 0x14 && process.env.SNAP_CREATE_FLOW === '1') {
    const tag08 = msg.toString('latin1', 0x10, 0x14);
    log(s, `[udp ${s.key}] ${dt}  [op08 tag "${tag08}" pendingCreateStat=${!!s.pendingCreateStat}]`);
    if (tag08 === 'STAT' && s.pendingCreateStat) {
      const handle = (s.roomHandle >>> 0) || 0;
      const txSeq = nextTxSeq(s);
      const push = Buffer.alloc(0x20);                 // 16 hdr + 0xc body + 4 trailer
      push[0] = 0xA0; push[1] = 0x1c; push[2] = msg[2]; push[3] = 0x28;  // sub = send-seq echo
      msg.copy(push, 4, 4, 16);                        // session token mirror
      push.writeUInt32BE(txSeq >>> 0, 0x08);
      push.writeUInt32BE(8, 0x10);                     // body word0 = selector 8 -> slot 0x25
      push.writeUInt32BE(handle, 0x14);                // word1 = minted owned handle -> 0x6ca97c [L]
      push.writeUInt32BE(0, 0x18);                     // word2 = 0
      push[0x1c] = 0xba; push[0x1d] = 0x47; push[0x1e] = 0x66; push[0x1f] = 0x11;
      sendSnapPacket(s, push, rinfo, () => {});
      s.outCount++; s.totalOut += push.length;
      s.pendingCreateStat = false;
      log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [create-STAT accept op28 sel=8 sub=0x${msg[2].toString(16)} handle=0x${handle.toString(16)} seq=0x${txSeq.toString(16)}] (${push.length}b) ${push.toString('hex')}`);
      console.error(`[lobby_state] STAT-MINT ${s.key} handle=0x${handle.toString(16)} — create finalized`);
      return;                                          // do NOT fall to the leave path (exitArea would dissolve)
    }
  }
  if ((msg[3] === 0x07 || msg[3] === 0x08) && (msg[0] & 0x80)) s.sawAreaConfirm = false;
  // 2026-07-11 G12: op07/op08 (any generation) = area EXIT -> clear presence + leave any room (dissolve if host).
  // 2026-07-19 SPINE-3: this is the GRACEFUL room-leave (the leaver back-navs to Area Select). Under
  // SNAP_ROOM_ENGINE the ENGINE owns the transition: lobbyEngine.exitArea does the SINGLE lobby_state
  // mutation (L.exitArea -> L.leaveRoom) AND returns one ordered plan (op07 survivor-notify -> op0a
  // durable -> count, then area counts). engineAdapter executes it so surviving members SEE the leave
  // (RF-9/RF-10 gap). Legacy path (engine OFF) keeps the raw lobbyState.exitArea with NO survivor emit.
  if (LOBBY_STATE_ON() && (msg[3] === 0x07 || msg[3] === 0x08) && (msg[0] & 0x80)) {
    if (ROOM_ENGINE_ON()) {
      const res = lobbyEngine.exitArea(s.key);
      const sum = engineAdapter().execute(res.plan, 'leave');
      console.error(`[engine] LEAVE ${s.key} op0${msg[3]} -> plan sent=${sum.sent} ${JSON.stringify(sum.byKind)}`);
    } else {
      lobbyState.exitArea(s.key);
    }
    s.roomHandle = null; s.pendingCreateStat = false; s.inCreate = false; s.memberJoinPushed = false;   // 2026-07-12: clear the create-session state too
  }
  if ((msg[3] === 0x07 || msg[3] === 0x08) && (msg[0] & 0x80)
      && process.env.SNAP_LOBBY_LEAVE_REPLY === '1') {
    const replies = msg[3] === 0x07 ? [[0xB0, 7], [0xA0, 7]] : [[0xA0, 8]];  // op07 -> slots 0x23/0x24; op08 -> 0x25
    for (const [who, sel] of replies) {
      const txSeq = nextTxSeq(s);
      const push = Buffer.alloc(0x1C);                 // 16 hdr + 8 body + 4 trailer
      push[0] = who; push[1] = 0x18; push[2] = msg[2]; push[3] = 0x28;  // op28; sub = send-seq (MATCH KEY)
      msg.copy(push, 4, 4, 16);                         // session mirror
      push.writeUInt32BE(txSeq >>> 0, 0x08);           // in-order seq
      push.writeUInt32BE(sel, 0x10);                   // body[0] = selector (BE) -> slot
      push.writeUInt32BE(0, 0x14);                     // status 0 (success)
      push[0x18] = 0xba; push[0x19] = 0x47; push[0x1a] = 0x66; push[0x1b] = 0x11;
      sendSnapPacket(s, push, rinfo, () => {});
      s.outCount++; s.totalOut += push.length;
      log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [lobby-leave op28 sel=${sel} who=0x${who.toString(16)} seq=0x${txSeq.toString(16)}] (${push.length}b) ${push.toString('hex')}`);
    }
  }
  // 2026-07-02 MODIFIER-PANEL reply (SNAP_MODIFIER_REPLY=1) — unfreezes the area rule/option panel.
  // RE (op0c-modifier-reply-RE-2026-07-02.md, subagent): the panel query is SN@P **cmd 0x0a** (NOT
  // 0x0c), sent by FUN_005c3190 via func_0x001de0c0 (reply slot 0x18 = FUN_005c3370). Dispatcher
  // FUN_001d9f78 routes cmd 0x0a -> case 7 -> conn+0x5a8 (slot 0x18) ONLY when the DATA bit 0x1000
  // is CLEAR -> reply who MUST be 0xA0 (0x8000|0x2000; who=0xB0 sets DATA and hits a dead slot).
  // The 0x2000 flag makes reply[1]=0 so FUN_005c3370 sets gate uRam006cba55=1 (count=0 = no records,
  // gate only); FUN_005c3190 then advances (cRam006cba50 1->2) and FUN_005c2f40(1) draws the panel
  // from the LOCAL blob +0x16c. Unclassified today (falls to 'unknown', no reply) => cursor freezes.
  // NOTE: slot 0x18 is shared with the post-join member-list query (same cmd 0x0a); safe now because
  // room-join isn't built (all cmd-0x0a = the area/lobby modifier query). Phase-gate when join lands.
  // 2026-07-17 G12 ROOM MEMBER-LIST, REGISTRY-BACKED (SNAP_ROOM_MEMBERLIST_ALL=1) — the DURABLE roster.
  // This is the "phase-gate when join lands" the note above called for: when the session is IN A ROOM
  // (s.roomHandle set by createRoom/joinRoom), its op0a is the member-list query, NOT the modifier panel.
  // G12-inroom-RE-2026-07-17 Gap 1 (slot-3 savestate): the roster render is wiped every op0a poll by the
  // whole-list redraw (FUN_00600de0 memset 0x6c79ac + refill from 0x6cdbe6, helper:51918), and our reply
  // only ever carried the querier -> members never see each other. Fix: enumerate ALL room members from
  // lobby_state. Reply shape mirrors the RIG-PROVEN create member-list below (op28 who=0xA0 -> case 9 ->
  // slot 0x18 FUN_005c0ae0, sub echoes msg[2], selector 0x0a, count LE @body+8, entries @body+0xc).
  // Record walk (FUN_005c0ae0, helper:16391-16400): name[16]@+0, id u32@+0x10 (FUN_005c50a0-encoded),
  // DATA-LENGTH @+0x14 (client computes nextRec = rec + len + 0x18 -> 0xf0 packs records at 0x108; the
  // old branch's 0x108 was only ever run at count=1 where the field is unread), data[0xf0]@+0x18.
  // Count capped at 4: the client dest 0x6cdbe6 is 4 slots x 0x118. Member ids = 1-based join order
  // (same synthetic ids the member-JOIN broadcast draws and the slot-3 peer table held) [Inference,
  // needs-rig]; host row named CREATOR (matches what the rig drew), others PLAYERn — real identity
  // (IDHNPAIRS) is a later gap.
  if (msg[3] === 0x0a && (msg[0] & 0x80) && process.env.SNAP_ROOM_MEMBERLIST_ALL === '1'
      && process.env.SNAP_LOBBY_STATE === '1' && s.roomHandle != null) {
    const room = lobbyState.rooms.get(s.roomHandle);
    if (room && room.members.size > 0) {
      const ml = buildRoomMemberListPacket(s, room, msg[2], msg);   // pure builder (C1) — sub = poll seq
      const n = Math.min(room.members.size, 4);
      sendSnapPacket(s, ml, rinfo, () => {});
      s.outCount++; s.totalOut += ml.length;
      log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [ROOM member-list op28 sel=0x0a count=${n} room=0x${(s.roomHandle >>> 0).toString(16)} "${room.name}" sub=0x${msg[2].toString(16)}] (${ml.length}b)`);
      console.error(`[lobby_state] MEMBERLIST-ALL ${s.key} room=0x${(s.roomHandle >>> 0).toString(16)} count=${n} -> [${[...room.members].slice(0, 4).map((k, i) => realMemberName(k, (room.hostId && k === room.hostId) ? 'CREATOR' : 'PLAYER' + (i + 1))).join(',')}]`);
      // Preserve the T17-confirmed create-self member-JOIN push (draw-enable 0x6cbc7e=0x10 + fingerprints)
      // that the old CREATE_MEMBERLIST branch fired — but ONCE, not per poll: the per-poll re-fire was the
      // T19 count-inflation bug (each push += 0x6cfb62 via FUN_005bb4d0 helper:12173).
      if (s.inCreate && process.env.SNAP_MEMBER_JOIN_PUSH === '1' && !s.memberJoinPushed) {
        s.memberJoinPushed = true;
        if (process.env.SNAP_MEMBER_JOIN_DEFER === '1') {
          const scheduledRoomHandle = s.roomHandle;
          setTimeout(() => {
            if (s.roomHandle === scheduledRoomHandle) {
              sendMemberJoinOp06(s, msg, rinfo, dt, 'create-self-once', (scheduledRoomHandle >>> 0) || 1, realMemberName(s.key, 'CREATOR'));
            }
          }, 120);
        } else {
          sendMemberJoinOp06(s, msg, rinfo, dt, 'create-self-once', (s.roomHandle >>> 0) || 1, realMemberName(s.key, 'CREATOR'));
        }
      }
      return;
    }
    // in-room but the room is gone/empty: fall through (modifier panel keeps the old behavior)
  }
  // 2026-07-12 G12-2 CREATE MEMBER-LIST (SNAP_CREATE_MEMBERLIST=1): after the op04 accept the client PULLs a
  // member-list via op0a (RE G12-populated-room-after-create-RE-2026-07-12: population is pull, not push).
  // In the create context (s.inCreate) that op0a must return the CREATOR as member 1 (not the count=0 modifier
  // panel), so the new-game-lobby shows "players: 1". Reply = op28 who=0xB0 selector-0x0a (dispatcher case 9,
  // DATA-set -> 0x5c2460 the count-setter, slot 0x18) + entryCount 1 + creator record -> fills the display
  // buffer 0x6cdbe6 + count 0x6ca890=1 (via FUN_005c0ae0/FUN_005c50a0). SUB byte echoes the op0a send-seq
  // (msg[2], the T9 completion key). Verify PINE 0x6ca890 -> 1. Default OFF. Needs SNAP_MULTIPLEX_WALK so the
  // op0a (outer of the create burst frame) is split out to reach here.
  if (msg[3] === 0x0a && (msg[0] & 0x80) && s.inCreate && process.env.SNAP_CREATE_MEMBERLIST === '1') {
    const handle = (s.roomHandle >>> 0) || 1;
    const mlSeq = nextTxSeq(s);
    const total = 0x10 + 0x114 + 4;                  // 16 hdr + body + 4 trailer (matches the proven member-list)
    const ml = Buffer.alloc(total);
    const wireLen = (total - 4) & 0x3ff;
    // 2026-07-12 G12-2 CORRECTION (snap-re G12-peer-table-population-RE): who=0xA0 (DATA bit 0x1000 CLEAR)
    // -> dispatcher case 9 -> slot 0x18 = FUN_005c0ae0, which FILLS 0x6cdbe6 AND increments the count
    // 0x6ca890 (helper:16404). who=0xB0 (DATA set) routes to slot 0x19 (0x5ac) which the create context never
    // installed -> the T11 failure (0x6ca890 stayed 0). Fill happens BEFORE the key check, so a right-routed
    // reply sets 0x6ca890 even if the send-seq key is off (diagnostic).
    ml[0] = 0xA0 | ((wireLen >> 8) & 0x03);           // DATA-CLEAR -> case 9 -> slot 0x18 = FUN_005c0ae0 (fill+count)
    ml[1] = wireLen & 0xff; ml[2] = msg[2]; ml[3] = 0x28;  // sub = op0a send-seq (completion key)
    msg.copy(ml, 4, 4, 16);
    ml.writeUInt32BE(mlSeq >>> 0, 0x08);
    ml.writeUInt32BE(0x0000000A, 0x10);               // body0 = selector 0x0a
    ml.writeUInt32LE(0x00000001, 0x18);               // body+8 = entryCount = 1 (the creator)
    Buffer.from('CREATOR').copy(ml, 0x1c, 0, 16);      // entry name[16]
    ml.writeUInt32BE(handle, 0x2c);                   // entry+0x10 = member handle (BE) -> 0x6cdbe6
    ml.writeUInt32LE(0x00000108, 0x30);               // entry+0x14 = stride delta
    ml[total - 4] = 0xba; ml[total - 3] = 0x47; ml[total - 2] = 0x66; ml[total - 1] = 0x11;
    sendSnapPacket(s, ml, rinfo, () => {});
    s.outCount++; s.totalOut += ml.length;
    log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [CREATE member-list op28 sel=0x0a count=1 handle=0x${handle.toString(16)} sub=0x${msg[2].toString(16)} seq=0x${mlSeq.toString(16)}] (${ml.length}b)`);
    // 2026-07-12 G12-2: the op0a reply above fills 0x6cdbe6 (list buffer) but NOT the DRAWN roster 0x6c7c2c.
    // The visible "1 player" row comes from the SERVER member-JOIN push (op06 -> slot 2 -> FUN_005bb4d0), sent
    // here where the room callbacks are installed and delivery is in-window. Separate flag (golden-safe):
    // SNAP_MEMBER_JOIN_PUSH=1 (see sendMemberJoinOp06). Bioserver parity: broadcastSlotPlayerStatus after create.
    // SNAP_MEMBER_JOIN_AT_ACCEPT already sent the op06 as the first reliable after op04-accept (in-window);
    // skip the mid-burst copy here to avoid a duplicate row + count inflation.
    if (process.env.SNAP_MEMBER_JOIN_PUSH === '1' && process.env.SNAP_MEMBER_JOIN_AT_ACCEPT !== '1') {
      if (process.env.SNAP_MEMBER_JOIN_DEFER === '1') {
        const scheduledRoomHandle = s.roomHandle;
        setTimeout(() => {
          if (s.roomHandle === scheduledRoomHandle) {
            sendMemberJoinOp06(s, msg, rinfo, dt, 'create-self', handle, 'CREATOR');
          }
        }, 120);
      } else {
        sendMemberJoinOp06(s, msg, rinfo, dt, 'create-self', handle, 'CREATOR');
      }
    }
    return;
  }
  if (msg[3] === 0x0a && (msg[0] & 0x80) && process.env.SNAP_MODIFIER_REPLY === '1') {
    const txSeq = nextTxSeq(s);
    const total = 0x20;                              // 16 hdr + 0xc body + 4 trailer
    const wireLen = (total - 4) & 0x3ff;             // 0x1c
    const push = Buffer.alloc(total);
    push[0] = 0xA0 | ((wireLen >> 8) & 0x03);        // who 0xA0 (0x2000 flag, DATA 0x1000 CLEAR -> slot 0x18)
    push[1] = wireLen & 0xff; push[2] = 0x00; push[3] = 0x0a;  // cmd 0x0a
    msg.copy(push, 4, 4, 16);                         // session token mirror
    push.writeUInt32BE(txSeq >>> 0, 0x08);           // in-order server->client seq
    push.writeUInt32BE(0, 0x10);                      // body word0
    push.writeUInt32BE(0, 0x14);                      // body word1
    push.writeUInt32BE(0, 0x18);                      // body+8 = record count = 0 (gate only)
    push[0x1c] = 0xba; push[0x1d] = 0x47; push[0x1e] = 0x66; push[0x1f] = 0x11;
    sendSnapPacket(s, push, rinfo, () => {});
    s.outCount++; s.totalOut += push.length;
    log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [modifier-panel cmd0a who=A0 seq=0x${txSeq.toString(16)}] (${push.length}b) ${push.toString('hex')}`);
  }
  // 2026-07-01 ROOM-LIST reply (SNAP_ROOMLIST_REPLY=1) — unlocks the lobby cursor. RE (HANDOFF):
  // the lobby SM (FUN_005f78c0->FUN_005c14a0) sends room-list queries via op49 (FUN_001e0ed8, reply
  // slot 0x32) and WAITS on cRam006cba05; the cursor is armed only after the SM advances. Reply op49
  // DATA: dispatcher FUN_001d9f78 outer case 0x46 (opcode 0x49) -> conn+0x610=slot 0x32 -> FUN_005c3da0
  // (matches query id 0 == reply subid msg[2]=0) -> FUN_005c13e0. who=0xB0 sets the 0x2000 flag so
  // param_1[1]=0 -> FUN_005c13e0 sets cRam006cba05=1 (empty-list advance). Body = 3 header words +
  // count@+8=0 (FUN_001d8cc0 iterates records only if count>0; FUN_001d8710 byteswaps body+0/4/8).
  // Empty list unlocks the cursor; showing rooms needs param_1[1]=1 + records (next step). Default OFF.
  // 2026-07-11 G12 (snap-re G12-lobby-wedge-RE-2026-07-11.md §8): op49 FAIL-FAST. The lobby wedge
  // after multiple cycles = the client ctx3 latch cRam006cba04 (armed on op49-request, cleared ONLY
  // at op49's terminal state) is never reset on EXITAREA; backing out while op49 is still in flight
  // (its 4 LOID/STAT sub-queries) leaves it latched and every later entry wedges. The original
  // SN@P/Bioserver server never wedged with the same client because it completed the room-list every
  // cycle. LEVER: terminate op49 in ONE round-trip instead of 4 by driving the op49 completion
  // FUN_005c13e0 down its status-0x27 branch -> cRam006cba05=2 -> ctx3 state 2->4 terminal. Routing
  // (dispatcher FUN_001d9f78, mirrors the proven SNAP_CMD0C_SELECTOR12 selector push): opcode 0x27
  // (outer case 0x24 sets the status local cStack_40=0x27, falls into case 0x25's selector switch) +
  // selector 0x49 (byteswapped -1 = 0x48 -> inner case 0x48 -> conn+0x610 = slot 0x32 = FUN_005c3da0
  // -> FUN_005c13e0). sub=0 matches op49's hard-coded id 0. Op49 id never climbs (sender FUN_001e0ed8
  // passes send-seq 0), so no generation echo. Any-generation detect. Reliable+in-order (like
  // cmd0c-selector12); if intra-session txSeq drift drops it, switch push[0] to 0x30 (non-reliable,
  // snap-re §8.3). Mutually exclusive with the empty SNAP_ROOMLIST_REPLY below.
  if (msg[3] === 0x49 && (msg[0] & 0x80) && process.env.SNAP_ROOMLIST_FAILFAST === '1') {
    const txSeq = nextTxSeq(s);
    const push = Buffer.alloc(0x1C);                 // 16 hdr + 8 body + 4 trailer
    push[0] = 0xB0; push[1] = 0x18; push[2] = 0x00; push[3] = 0x27;  // opcode 0x27 -> case 0x24 (cStack_40=0x27)
    msg.copy(push, 4, 4, 16);                         // session token + ack mirror from the op49 query
    push.writeUInt32BE(txSeq >>> 0, 0x08);           // in-order server->client seq
    push.writeUInt32BE(0x49, 0x10);                  // selector 0x49 (BE) -> inner case 0x48 -> slot 0x32
    push.writeUInt32BE(0, 0x14);                      // payload word1 (unused on the fail-fast path)
    push[0x18] = 0xba; push[0x19] = 0x47; push[0x1a] = 0x66; push[0x1b] = 0x11;
    sendSnapPacket(s, push, rinfo, () => {});
    s.outCount++; s.totalOut += push.length;
    log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [roomlist FAILFAST op27 sel=0x49 seq=0x${txSeq.toString(16)} (cba05=2 terminal)] (${push.length}b) ${push.toString('hex')}`);
  }
  // 2026-07-11 G12 (snap-re G12-op49-roomlist-RE-2026-07-11.md): render ONE real room by answering op49
  // with a count=1 room-list body + one 0x28 record. The record decodes via the DETAIL completion
  // FUN_005c19d0 into the room-row buffer 0x6cfb60. Record layout (stride 0x28): name @+0x00 (20B),
  // current players @+0x14, flags @+0x1c (bit16=locked), max @+0x20. count @body+8 (byteswapped by
  // FUN_001d8710, so write BE). EXPERIMENT: only renders if the DETAIL op49 context is pending (both
  // op49 queries are opcode 0x49). If cursor unlocks but no row shows, we hit the SUMMARY context.
  // Default OFF; mutually exclusive with the empty SNAP_ROOMLIST_REPLY / SNAP_ROOMLIST_FAILFAST.
  // 2026-07-11 G12: op49 room list rendered from the REAL registry (lobby_state.roomList()). Each room ->
  // one 0x28 record (name@+0x00 20B, current@+0x14, flags@+0x1c, max@+0x20; validated by SNAP_ROOMLIST_ONE).
  // count @body+8 (byteswapped -> write BE). Effectively a single global list (client never scopes by area).
  // Behind SNAP_ROOMLIST_REGISTRY (default OFF); mutually exclusive with the static/empty/fail-fast paths.
  if (msg[2] === 0x00 && msg[3] === 0x49 && (msg[0] & 0x80) && process.env.SNAP_ROOMLIST_REGISTRY === '1'
      && process.env.SNAP_ROOMLIST_FAILFAST !== '1') {
    const txSeq = nextTxSeq(s);
    // 2026-07-12 G12 "real rooms via JOIN" (Track A): while create-your-own-room is still walled, SEED one
    // server-owned persistent room so 2 clients can JOIN the SAME real registry room (co-location). op49
    // renders it from lobbyState.roomList() with rec+0x24 = its real handle; joinRoom (on the enter-accept)
    // makes the member count real. SNAP_SEED_ROOM (default the name below) can override / '0' disables.
    if (process.env.SNAP_SEED_ROOM !== '0' && lobbyState.roomList().length === 0) {
      lobbyState.seedRoom({ name: process.env.SNAP_SEED_ROOM || 'PAL LOBBY', maxPlayers: 4 });
    }
    const rooms = lobbyState.roomList();
    // 2026-07-12 G12 CREATE (rig-proven wall): create-on-a-Vacant-slot never transmits its ENTER because
    // the client's handle table 0x6fee68[idx] is 0 for unadvertised slots (journal: op09 USER arrived with
    // NO preceding op06; parking doc §"Open dependency"). Bioserver model: slots EXIST server-side and
    // "Vacant" is a status — so advertise pre-minted VACANT slot records (empty name, 0/4 players) whose
    // rec+0x24 handle gives the create-ENTER a target; createRoom then binds the room to that handle.
    // SNAP_ROOMLIST_VACANT sets how many (default 0 = OFF: second_opinion 2026-07-12 ranked empty-name
    // record rendering as an unproven risk, and the handle-0+name ENTER detection covers the create case
    // without it; enable for the slot-pool experiment once the row rendering is rig-checked).
    const vacantN = parseInt(process.env.SNAP_ROOMLIST_VACANT || '0', 10);
    const vacant = (process.env.SNAP_CREATE_FLOW === '1' && vacantN > 0)
      ? lobbyState.vacantHandles(vacantN).filter(h => !lobbyState.rooms.has(h)) : [];
    const nRec = rooms.length + vacant.length;
    const total = 0x1c + nRec * 0x28 + 4;           // 0x10 hdr + (word0,word1,count)=0xc + N*0x28 recs + 4 trailer (matches ONE)
    const wireLen = (total - 4) & 0x3ff;
    const push = Buffer.alloc(total);
    push[0] = 0xB0 | ((wireLen >> 8) & 0x03);
    push[1] = wireLen & 0xff; push[2] = 0x00; push[3] = 0x49;
    msg.copy(push, 4, 4, 16);
    push.writeUInt32BE(txSeq >>> 0, 0x08);
    push.writeUInt32BE(0, 0x10); push.writeUInt32BE(0, 0x14);
    push.writeUInt32BE(nRec, 0x18);                  // record count (byteswapped -> N)
    // 2026-07-17 FOUNDATION (SNAP_OP49_BE=1): the op49 record numerics @ +0x14/+0x1c/+0x20 are
    // BYTESWAPPED by the transport (FUN_001d7d20) before the client reads them, so our LE writes
    // rendered as 0 -> the room list always showed "0/0" (G12-op49-fields-RE-2026-07-17; the count
    // @body+8 is already BE and works, corroborating). Flip the DISPLAY fields to BE. The handle
    // @+0x24 is DELIBERATELY left LE: it round-trips (client ENTERs it back, we read readUInt32LE) and
    // join is rig-proven working today; flipping it risks the proven ENTER target resolution, so it
    // gets its own rig check before any change. No status byte in op49: INCREATE/GAMESET map to
    // full(current==max)/locked(flags bit16)/open — the registry's r.current/r.max already express it.
    const w32 = (buf, val, at) => (process.env.SNAP_OP49_BE === '1'
      ? buf.writeUInt32BE(val >>> 0, at) : buf.writeUInt32LE(val >>> 0, at));
    let off = 0x1c;
    for (const r of rooms) {
      Buffer.from(String(r.name)).copy(push, off, 0, Math.min(20, r.name.length));
      w32(push, r.current >>> 0, off + 0x14);        // current players (display)
      w32(push, r.flags >>> 0,   off + 0x1c);        // flags (bit16=locked)
      w32(push, r.max >>> 0,     off + 0x20);        // max players (display)
      // rec +0x24 = server-minted ROOM HANDLE -> client's 0x6fee68 handle table -> ENTER target.
      // Kept LE (see note): the ENTER round-trip is proven with LE; don't perturb it here.
      push.writeUInt32LE((r.handle >>> 0) || 0x00010001, off + 0x24);
      off += 0x28;
    }
    for (const h of vacant) {                        // vacant slot: empty name, 0 players, real handle
      w32(push, 0, off + 0x14);                      // current = 0
      w32(push, 0, off + 0x1c);                      // flags = 0 (unlocked)
      w32(push, 4, off + 0x20);                      // max = 4
      push.writeUInt32LE(h >>> 0, off + 0x24);       // pre-minted vacant handle (LE, ENTER target)
      off += 0x28;
    }
    push[total - 4] = 0xba; push[total - 3] = 0x47; push[total - 2] = 0x66; push[total - 1] = 0x11;
    sendSnapPacket(s, push, rinfo, () => {});
    s.outCount++; s.totalOut += push.length;
    log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [roomlist REGISTRY n=${nRec} (rooms=${rooms.length} vacant=${vacant.length}) seq=0x${txSeq.toString(16)}] (${push.length}b)`);
  }
  if (msg[2] === 0x00 && msg[3] === 0x49 && (msg[0] & 0x80) && process.env.SNAP_ROOMLIST_ONE === '1'
      && process.env.SNAP_ROOMLIST_FAILFAST !== '1' && process.env.SNAP_ROOMLIST_REGISTRY !== '1') {
    const txSeq = nextTxSeq(s);
    const rec = Buffer.alloc(0x28);
    Buffer.from('TESTROOM').copy(rec, 0);            // name @ +0x00 (20 bytes, zero-padded)
    rec.writeUInt32LE(1, 0x14);                       // current players = 1
    rec.writeUInt32LE(0, 0x1c);                       // flags = 0 (open, not locked)
    rec.writeUInt32LE(4, 0x20);                       // max players = 4
    // 2026-07-11 G12: rec +0x24 = ROOM HANDLE. op49 consumer FUN_005c19d0 stores rec+0x24 into the
    // handle table 0x6fee68 (1-based room number -> handle[roomNo]); create/join ENTER (FUN_005c04f0)
    // reads *(u32*)(idx*0x24+0x6fee68) as the session-open target. Was 0 -> ENTER never fired (create
    // froze at the registry gap; G12-create-wall-is-registry-gap-2026-07-11). Non-zero handle unblocks it.
    if (process.env.SNAP_ROOM_HANDLE !== '0') rec.writeUInt32LE(0x00010001, 0x24); // TESTROOM handle
    const total = 0x1c + 0x28 + 4;                    // 16 hdr + (word0,word1,count) + 0x28 rec + 4 trailer = 0x48
    const wireLen = (total - 4) & 0x3ff;
    const push = Buffer.alloc(total);
    push[0] = 0xB0 | ((wireLen >> 8) & 0x03);
    push[1] = wireLen & 0xff; push[2] = 0x00; push[3] = 0x49;
    msg.copy(push, 4, 4, 16);                         // session mirror
    push.writeUInt32BE(txSeq >>> 0, 0x08);           // in-order seq
    push.writeUInt32BE(0, 0x10);                      // body word0
    push.writeUInt32BE(0, 0x14);                      // body word1
    push.writeUInt32BE(1, 0x18);                      // body+8 = record count = 1 (byteswapped -> 1)
    rec.copy(push, 0x1c);                             // record[0] @ body+0xc
    push[total - 4] = 0xba; push[total - 3] = 0x47; push[total - 2] = 0x66; push[total - 1] = 0x11;
    sendSnapPacket(s, push, rinfo, () => {});
    s.outCount++; s.totalOut += push.length;
    log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [roomlist ONE 'TESTROOM' 1/4 seq=0x${txSeq.toString(16)}] (${push.length}b) ${push.toString('hex')}`);
  }
  if (msg[2] === 0x00 && msg[3] === 0x49 && (msg[0] & 0x80) && process.env.SNAP_ROOMLIST_REPLY === '1'
      && process.env.SNAP_ROOMLIST_FAILFAST !== '1' && process.env.SNAP_ROOMLIST_ONE !== '1'
      && process.env.SNAP_ROOMLIST_REGISTRY !== '1') {
    const txSeq = nextTxSeq(s);
    const total = 0x20;                              // 16 hdr + 0xc body + 4 trailer
    const wireLen = (total - 4) & 0x3ff;             // 0x1c
    const push = Buffer.alloc(total);
    push[0] = 0xB0 | ((wireLen >> 8) & 0x03);        // who 0xB0 (0x2000 flag -> param_1[1]=0 empty)
    push[1] = wireLen & 0xff; push[2] = 0x00; push[3] = 0x49;  // subid 0 (== query id 0) + opcode 0x49
    msg.copy(push, 4, 4, 16);                         // session mirror
    push.writeUInt32BE(txSeq >>> 0, 0x08);           // in-order seq
    push.writeUInt32BE(0, 0x10);                      // body word0 (byteswapped, unused)
    push.writeUInt32BE(0, 0x14);                      // body word1
    push.writeUInt32BE(0, 0x18);                      // body+8 = record count = 0 (empty list)
    push[0x1c] = 0xba; push[0x1d] = 0x47; push[0x1e] = 0x66; push[0x1f] = 0x11;
    sendSnapPacket(s, push, rinfo, () => {});
    s.outCount++; s.totalOut += push.length;
    log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [roomlist op49 empty seq=0x${txSeq.toString(16)}] (${push.length}b) ${push.toString('hex')}`);
  }
  if (klass === 'room-query-cmd0c') {
    // 2026-06-30: start the decoupled op40 keepalive on the FIRST cmd0c poll = the select/
    // connecting screen (excludes the login conn, avoiding the prior two-IP churn). Fire one now,
    // then every ~5s, so conn+0x7c keeps refreshing and the gate can advance 1->6 (render).
    if ((process.env.SNAP_OP40_TIMER === '1' || process.env.SNAP_OP40_KEEPALIVE === '1') && !s.kaTimer) {
      sendOp40Keepalive(s);
      s.kaTimer = setInterval(() => sendOp40Keepalive(s), 5000);
      log(s, `[udp ${s.key}] ${dt}  op40-timer STARTED (5s cadence) on first cmd0c poll`);
    }
    // 2026-06-27 (cmd0c-real-consumer-is-slot26-via-op28-sel12): the cmd=0x0c poll's OWN reply
    // callback is registered at SLOT 0x26 by its sender FUN_001de470 — VERIFIED in Ghidra:
    // FUN_001de470 builds the poll via FUN_001e180c(...,0xc,...) AND calls FUN_001d4d24(1,0x26,cb).
    // A direct cmd-0x0c reply routes to slot 0xa (overlay 0x5bc430, a DIFFERENT screen) and is futile
    // (this is the 06-12 "poll registers no slot" note — slot 0xa was never armed). Slot 0x26 is
    // reachable ONLY via opcode 0x28 + selector 12: dispatcher FUN_001d9f78 case 0x25 reads
    // selector=body[0] (BE, bswapped by FUN_001d7f6c), switch(selector-1); case 0xb -> param1+0x5e0
    // = slot 0x26. opcode-0x28 entry leaves the event byte = DATA. So PUSH op28/selector-12 on the
    // poll to drive the poll's own registered consumer. See
    // docs/findings/protocol/cmd0c-roomlist-wire-RE-2026-06-27.md. Default OFF; rollback = unset env.
    if (process.env.SNAP_CMD0C_SELECTOR12 === '1') {
      const selector = Math.max(1, Math.min(0x7f, parseInt(process.env.SNAP_CMD0C_SELECTOR || '0x0c', 0)));
      // Reliable DATA push must DELIVER in-order: seq = game's recvBase+1 (captured from transport-acks).
      const txSeq = nextTxSeq(s);   // UNIFY (PS2 collision fix): one monotonic reliable counter, not gameAck+1
      const push = Buffer.alloc(0x1C);                 // 16 hdr + 8 body + 4 trailer
      // 2026-07-11 G12 (snap-re): the slot-0x26 completion (op0c PREPARE consumer, FUN_005bd8c0) matches
      // on the reply SUB byte == the op0c send-seq (conn+0x61f) — SAME mechanism as op06/slot-0x21. The
      // client stamps the send-seq in the op0c query's sub byte (msg[2]), so ECHO it (was hardcoded 0x00,
      // which is why sel12 "targeted the right slot but never fired the one-shot"). This should fire the
      // RULE-screen PREPARE completion (0x6ca97e -> 0) and un-park FUN_005fada0 case 1.
      // 2026-07-12 G12 PREPARE correction: FUN_001de470 stores conn+0x61f in the op0c SUB byte and returns
      // that same byte into 0x6ca97e. FUN_005bd8c0 copies the inbound reply SUB byte into 0x6cbc80 before
      // FUN_005be120 matches it against 0x6ca97e. Do not echo wire+0x08 here; that is the transport seq.
      const subEcho = msg[2];
      push[0] = 0xB0; push[1] = 0x18; push[2] = subEcho; push[3] = 0x28;  // op 0x28 -> case 0x25; selector 12 -> slot 0x26
      msg.copy(push, 4, 4, 16);                         // mirror session token + cumulative-ack field
      push.writeUInt32BE(txSeq >>> 0, 0x08);           // override with in-order server->client seq
      push.writeUInt32BE(selector >>> 0, 0x10);        // body[0] = selector (BE) -> case 0xb -> slot 0x26
      push.writeUInt32BE(0, 0x14);                      // body[1] = 0
      push[0x18] = 0xba; push[0x19] = 0x47; push[0x1a] = 0x66; push[0x1b] = 0x11;
      sendSnapPacket(s, push, rinfo, () => {});
      s.outCount++; s.totalOut += push.length;
      log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [cmd0c-selector12 op28 sel=${selector} sub=0x${subEcho.toString(16)} seq=0x${txSeq.toString(16)}] (${push.length}b) ${push.toString('hex')}`);

      // 2026-06-27 STEP B — runtime-PROVEN step A (above) advances 0x6cbc7e->2 and the
      // sel-8 gate 0x6c4b90->6 (lobby screen renders) but count 0x70047c stays 0 and the
      // room table 0x6cdbe6 stays empty, so the list is empty -> 840. The count+table are
      // filled by 0x5c2460 = op28 selector 0x0a with the DATA bit SET (byte0=0xB0 ->
      // dispatcher FUN_001d9f78 case 9 with sStack_3a==0x1000 -> conn+0x5ac=0x5c2460, the
      // count-setting twin of 0x5c0ae0). RENDER2 used 0xA0 (DATA-clear->0x5c0ae0, no count)
      // which is why it never set count. Push one room record so 0x70047c!=0 + 0x6cdbe6 fills.
      // Gated by SNAP_CMD0C_MEMBERLIST (default ON once selector12 is on).
      if (process.env.SNAP_CMD0C_MEMBERLIST !== '0') {
        const V = (parseInt(process.env.SNAP_CMD0C_ROOM_ID || '1', 0)) >>> 0;
        const mlSeq = nextTxSeq(s);   // UNIFY (PS2 collision fix): contiguous after selector-12, not gameAck+2
        const total = 0x10 + 0x114 + 4;            // 16 hdr + body + 4 trailer
        const ml = Buffer.alloc(total);
        const wireLen = (total - 4) & 0x3ff;
        ml[0] = 0xB0 | ((wireLen >> 8) & 0x03);    // DATA bit SET (0x1000) -> case 9 -> 0x5c2460 (count-setter)
        ml[1] = wireLen & 0xff; ml[2] = 0x00; ml[3] = 0x28;
        msg.copy(ml, 4, 4, 16);
        ml.writeUInt32BE(mlSeq >>> 0, 0x08);       // in-order seq = recvBase+2 (after selector-12 at +1)
        ml.writeUInt32BE(0x0000000A, 0x10);        // body0 = 0x0a -> selector 0x0a (case 9)
        ml.writeUInt32LE(0x00000001, 0x18);        // body+8 = entryCount = 1
        Buffer.from(String(process.env.SNAP_CMD0C_ROOM_NAME || 'PLAYER1')).copy(ml, 0x1c, 0, 16); // entry name[16]
        ml.writeUInt32BE(V, 0x2c);                 // entry+0x10 = room/member id (BE) -> 0x6cdbe6 via 0x5c50a0
        ml.writeUInt32LE(0x00000108, 0x30);        // entry+0x14 = stride delta
        ml[total - 4] = 0xba; ml[total - 3] = 0x47; ml[total - 2] = 0x66; ml[total - 1] = 0x11;
        sendSnapPacket(s, ml, rinfo, () => {});
        s.outCount++; s.totalOut += ml.length;
        log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [cmd0c-memberlist op28 sel=0x0a DATA-SET id=${V} seq=0x${mlSeq.toString(16)}] (${ml.length}b)`);
      }
      return;
    }
    // 2026-06-26 RENDER2 (SESSION-LOG R-COUNT-SETTER). Decisive test of the in-area room-list wall:
    //   - cmd0c consumer 0x5bc430 advances render iff: count 0x70047c!=0 AND parse(id@0x6cdbe6, 8 ascii
    //     digits) == bswap(reply word0) AND reply body+0xe5==1. (witness: 0x6cd672 memcpy / 0x6cbc7e adv)
    //   - count 0x70047c=1 is set ONLY by FUN_005c2460, the DATA-SET twin of member-list FUN_005c0ae0.
    //   Hypothesis: a member-list reply with byte0=0xB0 (DATA bit 0x1000 SET) op28 body0=0x0a reaches
    //   conn+0x5ac=0x5c2460 → sets count + fills 0x6cdbe6 (from entry+0x10 binary id via 0x5c50a0) +
    //   advances. Then a cmd0c reply word0=id + body+0xe5=1 makes 0x5bc430 match.
    if (process.env.SNAP_RENDER2 === '1' && !s.render2Done) {
      s.render2Done = true;
      const token   = Buffer.from(msg.subarray(4, 8));
      const trailer = Buffer.from([0xba, 0x47, 0x66, 0x11]);
      const V = (parseInt(process.env.SNAP_R2_ID || '1', 0)) >>> 0;   // member id value (→ "00000001")
      // R-RENDER2-1: recvBase-aligned seq (game next-expected = recvBase+1). gameAck = last cumulative ack.
      let r2seq = (((s.gameAck >>> 0) || 0) + 1) >>> 0;
      const mk = (byte0, opcode, bodyLen, fill) => {
        const total = 0x10 + bodyLen + 4;
        const p = Buffer.alloc(total);
        const wireLen = (total - 4) & 0x3ff;
        p[0] = byte0 | ((wireLen >> 8) & 0x03);
        p[1] = wireLen & 0xff; p[2] = 0x00; p[3] = opcode & 0xff;
        token.copy(p, 4);
        p.writeUInt32BE(r2seq >>> 0, 0x08); r2seq = (r2seq + 1) >>> 0;
        fill(p);
        trailer.copy(p, total - 4);
        return p;
      };
      // [1] member-list DATA-CLEAR (byte0=0xA0) → conn+0x5a8 = 0x5c0ae0 (fills id 0x6cdbe6 + advances)
      const ml = mk(0xA0, 0x28, 0x114, (p) => {
        p.writeUInt32BE(0x0000000A, 0x10);            // body0 = 0x0a (sub-case 9)
        p.writeUInt32LE(0x00000001, 0x18);            // body+8 = entryCount = 1
        Buffer.from('PLAYER1').copy(p, 0x1c, 0, 16);  // entry+0x00 name[16]
        p.writeUInt32BE(V, 0x2c);                     // entry+0x10 = member ID (BE) → 0x6cdbe6 ascii
        p.writeUInt32LE(0x00000108, 0x30);            // entry+0x14 stride
      });
      // [2] cmd0c reply: word0 = V (BE → dispatcher bswap → V = parse(0x6cdbe6)); body+0xe5 = 1
      const c0 = mk(0xB0, 0x0c, 0xe6, (p) => {
        p.writeUInt32BE(V, 0x10);                     // body word0 = V
        p.writeUInt32BE(1, 0x18);                     // body+8 = count field (cosmetic)
        p[0x10 + 0xe5] = 1;                           // body+0xe5 = 1 (state-0x24 advance flag)
      });
      for (const [lbl, pkt] of [['ml-A0(0x5c0ae0)', ml], ['cmd0c-match', c0]]) {
        sendSnapPacket(s, pkt, rinfo, () => {});
        s.outCount++; s.totalOut += pkt.length;
        log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [render2 ${lbl}] (${pkt.length}b) ${pkt.toString('hex')}`);
      }
      log(s, `[udp ${s.key}] ${dt}  RENDER2 pushed (V=0x${V.toString(16)}) — watch count 0x70047c / 0x6cdbe6 / 0x6cd672 / 0x6cbc7e`);
      return;
    }
    if (process.env.SNAP_RENDER2 === '1') return; // already pushed; let the game digest
    // 2026-06-16 ROOM RENDER push (room-render-exact-sequence + byte0=0xA0 confirmation). The game
    // commits the join and POLLS cmd=0x0c (it does NOT emit op-6/op-10 as requests on the wire), so
    // we PUSH the render sequence in response to the poll, ONCE per session, on consecutive seqs:
    //   [1] op-6 room-enter reply  (byte0=0xA0, op 0x28, body0=6)  → arms gate 0x6ff2b1
    //   [2] op-10 member-list reply (byte0=0xA0, op 0x28, body0=0x0a, 1 member) → fills 0x6cdbe6
    //   [3..5] opcode-0x10 (byte0=0x80, op 0x10) subcmd 2 (join) → 5 (count=1) → 4 (arm slot)
    // Seq base = SNAP_ROOM_PUSH_SEQ (default 2; op48 used 1). Override w/ SNAP_ROOM_ABS_SEQ.
    if (process.env.SNAP_ROOM_RENDER === '1' && !s.roomRenderDone) {
      s.roomRenderDone = true;
      const absSeq = process.env.SNAP_ROOM_ABS_SEQ;
      if (absSeq !== undefined && absSeq !== '') s.txSeqNext = parseInt(absSeq, 0) >>> 0;
      const seqBase = s.txSeqNext ?? 0;
      const token   = Buffer.from(msg.subarray(4, 8));
      const trailer = Buffer.from([0xba, 0x47, 0x66, 0x11]);
      const memberId = (decoded && decoded.handle) || '12345';
      const seq = () => nextTxSeq(s);   // contiguous with slot1c/op48 (unified reliable seq)
      const pkts = [];
      pkts.push(['room-enter A0', buildAck('room-enter-reply-a0', msg, decoded, { txSeq: seq() })]);
      pkts.push(['member-list A0', buildAck('member-list-reply-a0', msg, decoded, { txSeq: seq(), memberId })]);
      for (const [sub, isCount] of [[0x02, false], [0x05, true], [0x04, false]]) {
        const payload = Buffer.alloc(9);
        payload[8] = sub;
        if (isCount) payload[5] = 0x01;               // count=1 for subcmd 5 → 0x6ff2b3
        const push = Buffer.concat([Buffer.alloc(0x10), payload, trailer]);
        push[0] = 0x80; push[1] = (push.length - 4) & 0xff; push[2] = 0x00; push[3] = 0x10;
        token.copy(push, 4); push.writeUInt32BE(seq(), 0x08);
        pkts.push([`op10 sub=0x${sub.toString(16)}`, push]);
      }
      let n = 0;
      for (const [label, pkt] of pkts) {
        sendSnapPacket(s, pkt, rinfo, () => {});
        s.outCount++; s.totalOut += pkt.length;
        log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [room-render ${n}/${label} seq=0x${(seqBase + n) >>> 0}] (${pkt.length}b) ${pkt.toString('hex')}`);
        n++;
      }
      log(s, `[udp ${s.key}] ${dt}  ROOM-RENDER sequence pushed (${pkts.length} pkts, seq base 0x${(seqBase >>> 0).toString(16)}) — watch for screen to leave black`);
      return;
    }
    if (process.env.SNAP_ROOM_RENDER === '1') return; // already pushed; let the game digest
    // 2026-06-12 (snap-re findings, docs/findings/protocol/cmd0x0c-reply-spec-RE-2026-06-12.md):
    // Experiment 1 (zero-mirror echo) was IGNORED. The reply must be built like the WORKING op48
    // reply: proper 16-byte header + STRUCTURED app payload (category + count + records), and the
    // qsw byte = (payload_len - 4) [Confirmed: register 154→0x96, session 28→0x18, op48 104→0x64].
    // Reply A = empty room list (count=0). Tunables via env for fast iteration without redeploy.
    // 2026-06-12 PHASE 1: the cmd=0x0c poll registers no slot (futile to answer). The in-area
    // lobby is driven by a server PUSH of outer opcode 0x10 → slot-0x13 room manager (0x5bba20),
    // which sub-dispatches on payload[8]. Framing (FUN_001e180c + slot1c-push): byte3=opcode,
    // wire+0x10=payload, qsw=len-4, seq in-order, trailer ba476611. We fire one push per poll with
    // an auto-incrementing in-order seq so a single joined session can sweep subcmds.
    //   SNAP_ROOM_PUSH=1          enable
    //   SNAP_ROOM_PUSH_SUBCMD=cycle | 0xN   (cycle sweeps 1..0x11 across polls)
    //   SNAP_ROOM_PUSH_B0=0xb0    byte0 (flag/kind variant; try 0xb0/0x30/0xf0/0xb8)
    //   SNAP_ROOM_PUSH_OP=0x10    outer opcode (byte3)
    //   SNAP_ROOM_PUSH_SEQ=2      starting reliable seq (op48 used 1 → room starts at 2)
    //   SNAP_ROOM_PUSH_DATA=<hex> extra payload bytes after subcmd (payload+9)
    if (process.env.SNAP_ROOM_PUSH === '1') {
      if (s.roomPushSeq === undefined) s.roomPushSeq = parseInt(process.env.SNAP_ROOM_PUSH_SEQ || '2', 0) >>> 0;
      const b0  = parseInt(process.env.SNAP_ROOM_PUSH_B0 || '0xb0', 0) & 0xff;
      // outer-opcode: phase-aware + cyclable. SNAP_ROOM_PUSH_OP_E1=cycle sweeps the 15 registered
      // handler opcodes on the e1-phase to find what advances it past e1. (slot 0x13 = opcode 0x10.)
      const OPSET = [0x04,0x05,0x06,0x07,0x08,0x0c,0x0e,0x0f,0x10,0x28,0x48];
      const whoB = msg[0];
      let opEnv;
      if (whoB === 0xE1) opEnv = process.env.SNAP_ROOM_PUSH_OP_E1 || process.env.SNAP_ROOM_PUSH_OP || '0x10';
      else opEnv = process.env.SNAP_ROOM_PUSH_OP || '0x10';
      let op;
      if (opEnv === 'cycle') { op = OPSET[(s.roomOpN || 0) % OPSET.length]; s.roomOpN = (s.roomOpN || 0) + 1; }
      else op = parseInt(opEnv, 0) & 0xff;
      // PHASE-AWARE: the poll who-byte advances per phase (0xa1 → 0xe1 after subcmd 2). Each phase
      // needs its own subcmd. Pick by who: SNAP_ROOM_PUSH_SUBCMD_A1 (default 2) for the a1-poll,
      // SNAP_ROOM_PUSH_SUBCMD_E1 (default cycle) for the e1-poll. Falls back to SNAP_ROOM_PUSH_SUBCMD.
      const who = msg[0];
      let subEnv;
      if (who === 0xA1) subEnv = process.env.SNAP_ROOM_PUSH_SUBCMD_A1 || process.env.SNAP_ROOM_PUSH_SUBCMD || '0x02';
      else if (who === 0xE1) subEnv = process.env.SNAP_ROOM_PUSH_SUBCMD_E1 || 'cycle';
      else subEnv = process.env.SNAP_ROOM_PUSH_SUBCMD || 'cycle';
      let subcmd;
      if (subEnv === 'cycle') { subcmd = 1 + ((s.roomPushN || 0) % 0x11); s.roomPushN = (s.roomPushN || 0) + 1; }
      else subcmd = parseInt(subEnv, 0) & 0xff;
      const extra = process.env.SNAP_ROOM_PUSH_DATA ? Buffer.from(process.env.SNAP_ROOM_PUSH_DATA, 'hex') : Buffer.alloc(0);
      const token   = msg.subarray(4, 8);
      const trailer = msg.subarray(msg.length - 4);
      // payload: 8 header bytes + subcmd byte (payload[8]) + extra. slot 0x13 reads payload[8].
      const payload = Buffer.concat([Buffer.alloc(9), extra]);
      payload[8] = subcmd;
      const push = Buffer.concat([Buffer.alloc(0x10), payload, trailer]);
      push[0] = b0; push[1] = (push.length - 4) & 0xff; push[2] = 0x00; push[3] = op;
      token.copy(push, 0x04);
      const seq = s.roomPushSeq++;
      push.writeUInt32BE(seq >>> 0, 0x08);
      sendSnapPacket(s, push, rinfo, perr => {
        if (perr) { log(s, `  room-push err: ${perr.message}`); return; }
        s.outCount++; s.totalOut += push.length;
        log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [room-push op=0x${op.toString(16)} sub=0x${subcmd.toString(16)} b0=0x${b0.toString(16)} seq=0x${seq.toString(16)}] (${push.length}b) ${push.toString('hex')}`);
        save(`p${pktCounter}_${rinfo.address.replace(/\./g,'_')}_${rinfo.port}_OUT_room_push`, push);
      });
      return;
    }
    if (process.env.SNAP_CMD0C_TEST === '1') {
      // DIAGNOSTIC (2026-06-23, T-CMD0C-ADVANCE): test whether cmd0c consumer 0x5bc430 advances the SM.
      // 0x5bc430 advances iff count 0x70047c!=0 (poked) AND local 0x6cdbe6 id (poked "0000000"→0) ==
      // reply word0 (=body+0 = category = 0 here) AND reply byte at body+0xe5 (=s1+8+0xdd, wire 0xf5) ==1.
      // Reply = 0x10 hdr + 0xe6 body + 4 trailer = 250B (qsw=0xf6 fits one byte). In-order seq (critical).
      // SEQ FIX: nextTxSeq over-counts (gaps) → seq ahead of recvBase → buffered → 0x5bc430 never runs.
      // Seq-align to the game's recvBase (captured from transport-acks). SNAP_CMD0C_SEQ: ack1|ack|next.
      const seqMode = process.env.SNAP_CMD0C_SEQ || 'ack1';
      let txSeq;
      if (seqMode === 'next' || s.gameAck === undefined) txSeq = nextTxSeq(s);
      else if (seqMode === 'ack') txSeq = s.gameAck >>> 0;
      else txSeq = (s.gameAck + 1) >>> 0;   // ack1 (next-expected after last received)
      const token   = msg.subarray(4, 8);
      const trailer = msg.subarray(msg.length - 4);
      const payload = Buffer.alloc(0xe6);
      payload.writeUInt32BE(0x12345678, 0x00);   // word0 = 0x12345678 non-zero (matches poked local id "12345678" parsed by 0x5c5120; tests if word0==0 was a skip-sentinel)
      payload.writeUInt32BE(1, 0x08);   // count
      payload[0xe5] = 1;                // body+0xe5 = s1+8+0xdd = the advance flag (==1)
      const reply = Buffer.concat([Buffer.alloc(0x10), payload, trailer]);
      reply[0] = 0xB0; reply[1] = (reply.length - 4) & 0xff; reply[2] = 0x00; reply[3] = 0x0c;
      token.copy(reply, 0x04);
      reply.writeUInt32BE(txSeq >>> 0, 0x08);
      sendSnapPacket(s, reply, rinfo, () => {});
      s.outCount++; s.totalOut += reply.length;
      log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [cmd0c-TEST len=${reply.length} word0=0 byte0xf5=1 seq=0x${txSeq.toString(16)}] ${reply.toString('hex')}`);
      return;
    }
    if (process.env.SNAP_ROOM_QUERY_REPLY === '1') {
      const off      = parseInt(process.env.SNAP_ROOM_SEQ_OFFSET   || '2',   10);
      const category = parseInt(process.env.SNAP_ROOM_CATEGORY     || '0x0a', 0) >>> 0;
      const count    = parseInt(process.env.SNAP_ROOM_COUNT        || '0',    10);
      const recName  = process.env.SNAP_ROOM_REC_NAME || 'SLOT000101'; // used when count>=1
      // seq-robust: prefer env absolute seq (survives mid-session server restart for hot-iteration),
      // else regReplySeq+off. Register is always seq 0 / op48 seq 1, so room reply seq = 2.
      const absSeq   = process.env.SNAP_ROOM_ABS_SEQ;
      // 2026-06-21 (run_20260621_131326): the game sends the room-query-cmd0c ~30x;
      // a FIXED seq (regReplySeq+off=2) means only the FIRST reply is delivered — every
      // repeat is seq<recvBase => dropped as dup => recvBase stalls at 4 => the SN@P
      // channel never reaches '(' => 840. SNAP_ROOM_SEQ_ADVANCE=1 makes each cmd0c reply
      // consume the shared in-order counter (2,4,5,6...) so every delivery advances
      // recvBase (the transport-delivery-contract condition for channel-establish).
      const txSeq    = (absSeq !== undefined && absSeq !== '')
                       ? (parseInt(absSeq, 0) >>> 0)
                       : (process.env.SNAP_ROOM_SEQ_ADVANCE === '1'
                          ? nextTxSeq(s)
                          : (((s.regReplySeq ?? 0) + off) >>> 0));
      const token    = msg.subarray(4, 8);                 // echo query token (02e707d0)
      const trailer  = msg.subarray(msg.length - 4);       // echo connection trailer (ba476611)
      // app payload: category(4) + reserved(4) + count(4) + count*record(0x24)
      const recStride = 0x24;
      const payload = Buffer.alloc(0xc + count * recStride);
      payload.writeUInt32BE(category, 0x00);               // app+0  = category
      payload.writeUInt32BE(0,        0x04);               // app+4  = reserved
      payload.writeUInt32BE(count,    0x08);               // app+8  = COUNT
      for (let i = 0; i < count; i++) {
        const ro = 0xc + i * recStride;
        const nm = Buffer.from(recName, 'latin1');
        nm.copy(payload, ro, 0, Math.min(nm.length, 0x10));// record+0x00 = name (<=0x10)
        // record+0x10 = the halfword op48 summed for the cap gate; keep 0 (empty)
      }
      const reply = Buffer.concat([Buffer.alloc(0x10), payload, trailer]);
      reply[0] = 0xB0;                                     // who = server REL|ACK
      reply[1] = (reply.length - 4) & 0xff;                // qsw = payload_len - 4 (Confirmed)
      reply[2] = 0x00; reply[3] = 0x0c;                    // cmd = echo 0x0c
      token.copy(reply, 0x04);                             // wire+0x04 = token
      reply.writeUInt32BE(txSeq, 0x08);                    // wire+0x08 = reliable seq (= regReplySeq+2)
      // wire+0x0c reserved already 0
      sendSnapPacket(s, reply, rinfo, perr => {
        if (perr) { log(s, `  room-query-reply err: ${perr.message}`); return; }
        s.outCount++; s.totalOut += reply.length;
        log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [room-query-cmd0c-reply] (${reply.length}b) b0/qsw=0x${reply[1].toString(16)}/00/0c cat=0x${category.toString(16)} count=${count} seq=0x${txSeq.toString(16)}  ${reply.toString('hex')}`);
        save(`p${pktCounter}_${rinfo.address.replace(/\./g,'_')}_${rinfo.port}_OUT_room_query_cmd0c_reply`, reply);
      });
      // 2026-06-20 (snap-channel-establish-FSM): the channel flips to '(' only when a
      // server-INITIATED reliable room-enter DATA is delivered IN-ORDER. The cmd0c reply
      // (seq=txSeq) is a keepalive; recvBase (read from the game's transport-ACKs) reaches
      // txSeq then stalls because we push nothing after. Send ONE room-enter DATA at the
      // next contiguous seq (txSeq+1). One-shot per session (later polls would dup-drop it).
      if (process.env.SNAP_ROOM_ENTER_PUSH === '1' && !s.roomEnterPushed) {
        s.roomEnterPushed = true;
        // snap-channel-establish-FSM-ROOMENTER-APPENDIX: the channel char '(' is driven by the
        // transport session-control opcode 0x27 (FUN_001d507c), server->INITIATED (the game sends
        // no 0x27 inbound). byte0=0xe0 (control class, like the game's own e0/0x10 frames), token
        // echoed (only one token on the wire), seq contiguous. body0 = window/seq-init param.
        // Defaults set to frame (A). All tunable for the constrained value sweep (seq/body0/b0).
        const reB0    = parseInt(process.env.SNAP_ROOM_ENTER_B0    || '0xe0', 0) & 0xff;
        const reOp    = parseInt(process.env.SNAP_ROOM_ENTER_OP    || '0x27', 0) & 0xff;
        const reBody0 = parseInt(process.env.SNAP_ROOM_ENTER_BODY0 || '0',    0) >>> 0;
        // seq: 'next' = contiguous in-order (txSeq+1); or absolute via SNAP_ROOM_ENTER_SEQ (e.g. 0
        // if the room is a fresh channel whose recvBase starts at 0).
        const seqEnv  = process.env.SNAP_ROOM_ENTER_SEQ;
        const reSeq   = (seqEnv !== undefined && seqEnv !== '') ? (parseInt(seqEnv,0)>>>0)
                        : (process.env.SNAP_ROOM_SEQ_ADVANCE === '1' ? nextTxSeq(s) : ((txSeq + 1) >>> 0));
        const rePayload = Buffer.alloc(0xc);
        rePayload.writeUInt32BE(reBody0, 0x00);
        // 2026-06-21 (connect-sm-error-is-f4-plus-820): for op 0x31 the dispatcher FUN_001d9f78
        // calls the connect-SM callback FUN_00626730 with event = payload+0x40, and it reads
        // event.f4 = byteswap(payload[2]) = THIS dword. FUN_00626730 then computes the on-screen
        // error as f4 + 820, and f4 == 0x13 (19) = SUCCESS (cs_result=1, session established).
        // Our old all-zero payload => f4=0 => 820. Set payload[2] = 0x13 so the game sees the
        // connection as established. SNAP_ROOM_ENTER_F4 tunes it (e.g. 0x11 = partial).
        const reF4 = parseInt(process.env.SNAP_ROOM_ENTER_F4 || '0x13', 0) >>> 0;
        rePayload.writeUInt32BE(reF4, 0x08);   // payload[2] -> connect-SM event.f4
        const rePush = Buffer.concat([Buffer.alloc(0x10), rePayload, trailer]);
        rePush[0] = reB0; rePush[1] = (rePush.length - 4) & 0xff; rePush[2] = 0x00; rePush[3] = reOp;
        token.copy(rePush, 0x04);
        rePush.writeUInt32BE(reSeq, 0x08);
        sendSnapPacket(s, rePush, rinfo, perr => {
          if (perr) { log(s, `  establish-push err: ${perr.message}`); return; }
          s.outCount++; s.totalOut += rePush.length;
          log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [establish-push b0=0x${reB0.toString(16)} op=0x${reOp.toString(16)} body0=0x${reBody0.toString(16)} seq=0x${reSeq.toString(16)}] (${rePush.length}b) ${rePush.toString('hex')}`);
          save(`p${pktCounter}_${rinfo.address.replace(/\./g,'_')}_${rinfo.port}_OUT_establish_push`, rePush);
        });
      }
    } else {
      log(s, `[udp ${s.key}] ${dt}  (suppressed — room-query cmd=0x0c; set SNAP_ROOM_QUERY_REPLY=1)`);
    }
    return;
  }

  // (kind-0x32 post-lobby-snap now handled below via post-register-bind-ack
  //  strategy per Codex analysis/udp9090-post-lobby-snap-op01.md: same
  //  reliable-transport ACK shape as 0x31 post-register-bind, just different
  //  inbound kind/opcode. Body is 0xf0+0x128 zero-padded, not menu data.)

  // (kind=0xf0 op=0x48 'named-slot-query' now handled below: transport ACK
  //  via post-register-bind-ack strategy, then structured opcode-0x48 reply
  //  via named-slot-query-reply strategy. Per Codex udp9090-named-slot-query-op48.md)

  // 2026-07-02 SNAP_SUPPRESS_UNKNOWN_REPLY=1 — single-variable A/B (SESSION-LOG T4): stop the
  // catch-all snap-register-reply for RELIABLE unknown frames (op48-NAMED/op41/op2d floods).
  // Those replies mirror the inbound seq at wire+0x08 => always out-of-window => the game
  // acks-but-never-delivers them and BUFFERS each one in its conn+0x520 pool (FUN_001d6988
  // reliable branch queues seq>=recvBase, frees nothing) — a major pool consumer suspected of
  // causing the op49 alloc fail (0x25b790=0x65). Out-of-window frames never reach the app
  // layer, so suppression is transport-only and cannot change app behavior. Direct-detect
  // handlers above (op06 area-confirm, op49 roomlist) already fired for their opcodes.
  // Non-reliable unknowns keep the catch-all (conservative). Default OFF; rollback = unset env.
  if (process.env.SNAP_SUPPRESS_UNKNOWN_REPLY === '1' && klass === 'unknown' && (msg[0] & 0x80)) {
    log(s, `[udp ${s.key}] ${dt}  (suppressed — reliable unknown cmd=0x${msg[2].toString(16)}${msg[3].toString(16).padStart(2,'0')} seq=0x${msg.length >= 0xc ? msg.readUInt32BE(8).toString(16) : '?'}; SNAP_SUPPRESS_UNKNOWN_REPLY)`);
    return;
  }

  // Always reply with the same strategy keyed to the packet class. Rotation
  // would break the AVE-TCP reliability layer â€” retransmits expect the same
  // (deterministic) reply, not a different shape each time.
  const strategy = (klass === 'register-request')    ? 'snap-register-reply'
                 : (klass === 'post-register-bind')  ? 'post-register-bind-ack'
                 : (klass === 'post-lobby-snap')     ? 'post-register-bind-ack'  // same ACK shape per Codex udp9090-post-lobby-snap-op01.md
                 : (klass === 'named-slot-query')    ? (msg[0] === 0xF0 ? 'post-register-bind-ack'      // connect-phase: transport ACK first, then structured reply below
                                                                        : 'named-slot-query-reply')     // T6 lobby op48 (0xB0/0xB8): structured echo reply ONLY (no bind-ack — its mirrored +0x0c would free a wrong id; acking op48 is deliberately excluded per T5b guardian review)
                 : (klass === 'room-enter-request')  ? 'room-enter-reply-a0'      // ROOM RENDER step 1 (arm 0x6ff2b1)
                 : (klass === 'member-list-request') ? 'member-list-reply-a0'     // ROOM RENDER step 2 (fill 0x6cdbe6)
                 : s.ackStrategy;

  // Automated PRE-PUSH snapshot when we receive the post-register-bind packet,
  // just BEFORE we send the ACK and slot-19 push. Captures the "before"
  // baseline so Codex can diff against the post-push snapshots.
  // Codex udp9090-post-lobby-after-ack.md (2026-05-19): same PRE-PUSH +
  // post-ACK slot1c-push experiment is the next discriminator for the 570B
  // post-lobby-snap packet — slot 0x1c likely still points at 0x00626730,
  // and re-firing the opcode-0x28 push may advance the post-lobby state machine.
  // T6: PINE snapshots/diag only for the connect-phase 0xF0 op48 — running them on every lobby
  // op48 would hammer PINE and break the timing-critical render (observer effect).
  if (klass === 'post-register-bind' || klass === 'post-lobby-snap'
      || (klass === 'named-slot-query' && msg[0] === 0xF0)) {
    // 2026-07-06 G11: this snapshot file is only ever filled by runSnapshot (gated on
    // UDP_SNAPSHOTS=1). When snapshots are off, the writeFileSync just created an empty
    // header file per 0xF0 op48 (unconditional disk hit under the Area Select flood).
    // Gate the whole diagnostic setup on the same flag so the hot path is I/O-free.
    if (process.env.UDP_SNAPSHOTS === '1') {
      const ts = Date.now();
      const filePrefix = klass === 'post-lobby-snap' ? 'postlobby'
                       : klass === 'named-slot-query' ? 'namedslotq'
                       : 'slot19';
      s.snapFile = path.join(SLOT19_SNAPSHOT_DIR, `${filePrefix}_${s.key.replace(/[:.]/g, '_')}_${ts}.log`);
      s.snapT0 = ts;
      fs.writeFileSync(s.snapFile, `=== SESSION ${s.key} (${klass}) @ ${new Date(ts).toISOString()} ===\n`);
      log(s, `[udp ${s.key}] ${dt}  snapshot file: ${s.snapFile}`);
      await runSnapshot(s.snapFile, `PRE-PUSH (${klass} received)`, s.snapT0);
      if (klass === 'named-slot-query') {
        s.namedSlotDiagFile = path.join(NAMEDSLOT_DIAG_DIR, `namedslot_diag_${s.key.replace(/[:.]/g, '_')}_${ts}.jsonl`);
        s.namedSlotDiagT0 = ts;
        recordNamedSlotDiag(s, 'pre-named-slot-reply', msg, null);
        log(s, `[udp ${s.key}] ${dt}  namedslot diag: ${s.namedSlotDiagFile}`);
      }
    }

    // Arm TCP 10127 only from the original post-register bind. Post-lobby
    // opcode 0x01 and opcode 0x48 reuse this same block for snapshots, but
    // they are already downstream of the TCP lobby walk. Arming from them
    // leaves stale pending entries that make the next TCP connect run the
    // wrong state machine.
    if (klass === 'post-register-bind') {
      // Handle from the post-bind body (offset 0x20, dash-suffixed e.g. "12345-").
      let handle = '';
      if (msg.length > 0x20) {
        const handleEnd = msg.indexOf(0, 0x20);
        const stopAt = handleEnd > 0 && handleEnd < 0x40 ? handleEnd : 0x40;
        for (let i = 0x20; i < stopAt; i++) {
          const b = msg[i];
          if (b < 0x20 || b >= 0x7f) break;
          handle += String.fromCharCode(b);
        }
        // Strip trailing dash so the userid matches accounts.json
        if (handle.endsWith('-')) handle = handle.slice(0, -1);
      }
      if (handle) {
        markPendingOnlineFromRegister({ ip: rinfo.address, userid: handle, handle });
        if (LOBBY_STATE_ON()) lobbyState.bindEndpoint({ transportKey: s.key, userid: handle, handle });
        log(s, `[udp ${s.key}] ${dt}  armed snap_server lobby mode for ${rinfo.address} handle="${handle}"`);
      } else {
        log(s, `[udp ${s.key}] ${dt}  could not extract handle from ${klass}; snap_server will use boot-auth`);
      }
    } else if (klass === 'post-lobby-snap' || klass === 'named-slot-query') {
      log(s, `[udp ${s.key}] ${dt}  not arming snap_server from ${klass}; packet belongs to post-lobby UDP phase`);
    }
  }
  const ctx = {};
  // T6: the direct lobby op48 reply needs its in-order server->client seq stamped (same
  // mechanism as the connect-phase reply, which gets it in the send-callback below).
  if (strategy === 'named-slot-query-reply') {
    const absEnv = process.env.SNAP_TXSEQ_ABS;
    ctx.txSeq = (absEnv !== undefined && absEnv !== '') ? (parseInt(absEnv, 0) >>> 0) : nextTxSeq(s);
  }
  // ROOM RENDER outbound seq (subagent snap-transport-delivery-contract-2026-06-16): reliable DATA
  // must use a SINGLE monotonic outbound seq = the EE recv base, +1 per reliable packet (gaps buffer
  // & never deliver; repeats drop as dup). Seed from regReplySeq+1 (or SNAP_TXSEQ_ABS for PINE calib,
  // or the request's own wire-0x08 seq as a fallback). Used only for the op-6/op-10 A0 replies.
  if (strategy === 'room-enter-reply-a0' || strategy === 'member-list-reply-a0') {
    const absEnv = process.env.SNAP_TXSEQ_ABS;
    if (s.txSeqNext === undefined) {
      s.txSeqNext = (absEnv !== undefined && absEnv !== '') ? (parseInt(absEnv, 0) >>> 0)
                  : (s.regReplySeq !== undefined) ? ((s.regReplySeq + 1) >>> 0)
                  : (msg.length >= 0x0c ? (msg.readUInt32BE(0x08) >>> 0) : 0);
    }
    ctx.txSeq = s.txSeqNext >>> 0;
    s.txSeqNext = (s.txSeqNext + 1) >>> 0;
    ctx.memberId = (decoded && decoded.handle) || undefined;
  }
  ctx.sawAreaConfirm = !!s.sawAreaConfirm;   // T11: gate op48 AREA-substitution (area-select) vs echo (lobby)
  // T12: alternate the AREA op48 record frame per op48 poll so >6 boxes activate across 2 frames.
  if (klass === 'named-slot-query') s.areaOp48Frame = (s.areaOp48Frame || 0) + 1;
  ctx.areaOp48Frame = s.areaOp48Frame || 0;
  const ack = buildAck(strategy, msg, decoded, ctx);
  // Cache the proven-deliverable b096 register-reply for the establishment-message experiment.
  if (strategy === 'snap-register-reply') {
    s.lastReplyB096 = Buffer.from(ack);
    // SEQ FIX: register-reply is the one server->client packet that DOES deliver,
    // so its wire-0x08 seq is the in-window base. Seed our outbound counter from it.
    if (ack.length >= 0x0c) {
      s.regReplySeq = ack.readUInt32BE(0x08);
      if (s.txSeqNext === undefined) s.txSeqNext = (s.regReplySeq + 1) >>> 0;   // UNIFY: seed ONCE; do NOT rewind on re-register (PS2 seq-collision fix)
      if (relWindowEnabled()) resetRelWindow(s);
      s.roomRenderDone = false;                  // allow a fresh room-render push on re-join
    }
  }

  sendSnapPacket(s, ack, rinfo, err => {
    if (err) { log(s, `  send err: ${err.message}`); return; }
    s.outCount++;
    s.totalOut += ack.length;
    log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [${strategy}] (${ack.length}b)  ${ack.slice(0,16).toString('hex')}...`);
    if (ctx.cipherDebug) log(s, `    blowfish: ${ctx.cipherDebug}`);
    save(`p${pktCounter}_${rinfo.address.replace(/\./g, '_')}_${rinfo.port}_OUT_${strategy}`, ack);

    // For named-slot-query: send the structured opcode-0x48 reply right after
    // the transport ACK (per Codex udp9090-named-slot-query-op48.md). This is
    // distinct from the slot1c push below — different opcode, different shape.
    // T6: only for the connect-phase 0xF0 flow (bind-ack strategy); the lobby op48
    // path sends the structured reply AS its strategy, so this would double-send.
    if (klass === 'named-slot-query' && strategy === 'post-register-bind-ack') {
      // SEQ FIX: stamp the next-expected server->client seq into the op48 reply.
      // Gated by SNAP_TXSEQ_FIX=1. Default target = register-reply seq + offset
      // (SNAP_TXSEQ_OFFSET, default 1, since intermediate replies are out-of-window
      // and don't advance the client window). SNAP_TXSEQ_ABS overrides absolutely
      // (set it to a PINE-read conn+4+1 for exact calibration).
      const absEnv = process.env.SNAP_TXSEQ_ABS;
      const txSeq = (absEnv !== undefined && absEnv !== '') ? (parseInt(absEnv, 0) >>> 0) : nextTxSeq(s);
      const replyCtx = { txSeq, sawAreaConfirm: !!s.sawAreaConfirm, areaOp48Frame: s.areaOp48Frame || 0 };  // T11/T12
      const structuredReply = buildAck('named-slot-query-reply', msg, decoded, replyCtx);
      sendSnapPacket(s, structuredReply, rinfo, perr => {
        if (perr) { log(s, `  named-slot-query-reply err: ${perr.message}`); return; }
        s.outCount++;
        s.totalOut += structuredReply.length;
        log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [named-slot-query-reply] (${structuredReply.length}b)  ${structuredReply.toString('hex')}`);
        if (replyCtx.parsedDebug) log(s, `    parsed: ${replyCtx.parsedDebug}`);
        if (replyCtx.txSeq !== undefined) log(s, `    SEQ FIX: wire0x08 0x${(replyCtx.seqWas>>>0).toString(16)} -> 0x${(replyCtx.txSeq>>>0).toString(16)} (regReplySeq=0x${(s.regReplySeq>>>0).toString(16)})`);
        save(`p${pktCounter}_${rinfo.address.replace(/\./g, '_')}_${rinfo.port}_OUT_named_slot_query_reply`, structuredReply);
        s.namedSlotReplyAt = Date.now();
        recordNamedSlotDiag(s, 'post-named-slot-reply-sent', msg, structuredReply);

        // 2026-05-25: post-op48 server push experiment.
        // Per analysis/udp9090-post-lobby-after-ack.md, after game ACKs the
        // op48 reply, state+0x80 == 3 and the game waits for a server-initiated
        // application push to advance further. With no push, state+0x51c timer
        // (~4-5s) fires FUN_001d94b0 -> REGISTER cycle restart (D901 / 840).
        // Codex's "lowest-risk experiment": repeat slot-0x1c opcode 0x28
        // selector-1 push, which already works to advance into the TCP lobby
        // phase. Push happens 50ms after the op48 reply to let the game's
        // transport ACK arrive first. Disable with SNAP_POST_OP48_PUSH=0.
        // 2026-05-25 (PM): cmd=0x27 push falsified by live PINE watcher. Watcher
        // showed NTGUI state byte (0x007152e1) went from 0x02 → 0x00 immediately
        // after the push, NOT to 0x05 as Codex's FUN_00626730 decompile predicted.
        // Likely the state-5 handler at 0x00626bdc instantly transitions to 0
        // (terminal/reset). Game UI shows immediate D901 instead of slower timeout.
        // Push DEFAULT OFF now. Set SNAP_POST_OP48_PUSH=1 to re-enable for further
        // probes (e.g., trying different status bytes or alternate cmds 0x3d).
        if (process.env.SNAP_POST_OP48_PUSH === '1') {
          setTimeout(() => {
            const post48PushCtx = {};
            const post48Push = buildAck('slot1c-status-push-cmd27', msg, decoded, post48PushCtx);
            sendSnapPacket(s, post48Push, rinfo, p2err => {
              if (p2err) { log(s, `  post-op48 slot1c push err: ${p2err.message}`); return; }
              s.outCount++;
              s.totalOut += post48Push.length;
              log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [post-op48 slot1c-status-push-cmd27] (${post48Push.length}b)  ${post48Push.toString('hex')}`);
              if (post48PushCtx.parsedDebug) log(s, `    parsed: ${post48PushCtx.parsedDebug}`);
              save(`p${pktCounter}_${rinfo.address.replace(/\./g, '_')}_${rinfo.port}_OUT_post_op48_slot1c_push_cmd27`, post48Push);
            });
          }, 50);
        }

        // 2026-06-03: AUTO PINE-WRITE counter-gate state to TRIGGER the natural
        // ntgui/recv-parser path that sets state+0x80=3.
        // RE found (ntgui FUN_007d70cc, the lobby state machine):
        //   case state+0x80 == 2:  // current state — "in lobby waiting"
        //     if (state+0x7c + 500 < state+0x4fc) {
        //       jal FUN_001d6ee0(state)         ← network function w/ SIDE EFFECTS
        //       state+0x7c = state+0x4fc        ← reset counter
        //       state+0x80 = 3                  ← advance phase
        //     }
        //   case state+0x80 == 3: ... (different path)
        // Writing state+0x80=3 directly takes us to case 3 which doesn't run
        // FUN_001d6ee0. We need case 2 with the counter gate satisfied.
        // Set SNAP_PINE_AUTO_ADVANCE=0 to disable.
        // 2026-06-03 (rev 3): Conditional PINE auto-advance.
        // Live test showed:
        //   - At T+100ms state+0x80 was ALREADY 3 (natural code path worked)
        //   - state+0x7c/0x4fc are TIMESTAMPS (~2.2B values), not counters
        //   - Our blanket writes broke game state → eventual D901/reset
        // Only fire if game is actually stuck (state+0x80 == 2, the wait state)
        // AND keep counter values in their natural range (just narrow the gate).
        if (process.env.SNAP_PINE_AUTO_ADVANCE !== '0') {
          const STATE_BASE = 0x0036D760;
          const writeAdvance = async (label) => {
            try {
              const pine = await getPine();
              const cur80  = await pine.read32(STATE_BASE + 0x80);
              if (cur80 !== 2) {
                log(s, `[udp ${s.key}] ${dt}  PINE auto-advance ${label}: SKIP — state+0x80=0x${cur80.toString(16)} (only fires if =2)`);
                return;
              }
              const cur7c  = await pine.read32(STATE_BASE + 0x7c);
              const cur4fc = await pine.read32(STATE_BASE + 0x4fc);
              // Already gated? (state+0x7c + 500 < state+0x4fc → game's next tick fires it)
              const diff = (cur4fc - cur7c) >>> 0;
              if (diff > 500 && diff < 0x80000000) {
                log(s, `[udp ${s.key}] ${dt}  PINE auto-advance ${label}: SKIP — gate already satisfied (4fc-7c=${diff})`);
                return;
              }
              // Narrow the gate by lowering 7c just enough. Keep value near the
              // natural range so game's tick math stays consistent.
              const new7c = (cur4fc - 1000) >>> 0;
              await pine.write32(STATE_BASE + 0x7c, new7c);
              log(s, `[udp ${s.key}] ${dt}  PINE auto-advance ${label}: state+0x80=2, 7c=${cur7c} 4fc=${cur4fc} → wrote 7c=${new7c} (diff now ~1000)`);
            } catch (e) {
              log(s, `[udp ${s.key}] ${dt}  PINE auto-advance FAIL (${label}): ${e.message}`);
              try { pineConn?.close(); } catch {}
              pineConn = null;
            }
          };
          // Fire later, less often. Give the game time to do natural progression.
          setTimeout(() => writeAdvance('T+2000ms'), 2000);
          setTimeout(() => writeAdvance('T+10000ms'), 10000);
          setTimeout(() => writeAdvance('T+30000ms'), 30000);
        }

        setTimeout(() => recordNamedSlotDiag(s, 'T+25ms after namedslot reply', null, structuredReply), 25);
        setTimeout(() => recordNamedSlotDiag(s, 'T+50ms after namedslot reply', null, structuredReply), 50);
        setTimeout(() => recordNamedSlotDiag(s, 'T+200ms after namedslot reply', null, structuredReply), 200);
        setTimeout(() => recordNamedSlotDiag(s, 'T+1000ms after namedslot reply', null, structuredReply), 1000);

        // Per Codex's "dump 0x0087f7f8, 0x0087f800, and state+0x60c around
        // callback execution" — capture state at multiple offsets AFTER the
        // game's callback at 0x005bc990 processes our records.
        if (s.snapFile) {
          runSnapshot(s.snapFile, 'POST-REPLY (named-slot-query-reply sent)', s.snapT0);
          setTimeout(() => runSnapshot(s.snapFile, 'T+50ms after reply', s.snapT0), 50);
          setTimeout(() => runSnapshot(s.snapFile, 'T+200ms after reply', s.snapT0), 200);
          setTimeout(() => runSnapshot(s.snapFile, 'T+500ms after reply', s.snapT0), 500);
          setTimeout(() => runSnapshot(s.snapFile, 'T+1500ms after reply', s.snapT0), 1500);
          setTimeout(() => runSnapshot(s.snapFile, 'T+5000ms after reply', s.snapT0), 5000);
        }
      });
    }

    // State-3 server push targeting the live slot 0x1c (callback 0x00626730).
    // The initial post-register push is proven: it moves the game into TCP
    // 10127 lobby population. Now that TCP reaches 0x1004 cleanly, ACK-only
    // post-lobby UDP stalls at black screen, so repeat the push by default.
    // Set SNAP_POST_LOBBY_PUSH=0 to disable for regression tests.
    const shouldPushSlot1c =
      klass === 'post-register-bind' ||
      (klass === 'post-lobby-snap' && process.env.SNAP_POST_LOBBY_PUSH !== '0');
    if (shouldPushSlot1c) {
      const pushCtx = {};
      const push = buildAck('slot1c-status-push', msg, decoded, pushCtx);
      // 2026-06-20: the slot1c push is a 0xb0 control push processed out-of-band,
      // NOT a windowed reliable DATA. Consuming nextTxSeq here (the 06-19 "unified
      // seq" fix) desynced the counter from the game's recvBase: register-reply
      // delivered → recvBase=1, but the push took seq=1, so the following
      // named-slot/cmd0c reply landed at seq=2 > recvBase=1 → buffered → 840.
      // Default: mirror (do NOT consume the counter) so op48/cmd0c/render stay
      // contiguous from seq=1 (== recvBase). SNAP_SLOT1C_INORDER=1 = old behavior.
      if (process.env.SNAP_SLOT1C_INORDER === '1') {
        push.writeUInt32BE(nextTxSeq(s), 0x08);
      }   // else: mirrored seq from buildAck stands (no counter consumption)
      sendSnapPacket(s, push, rinfo, perr => {
        if (perr) { log(s, `  push err: ${perr.message}`); return; }
        s.outCount++;
        s.totalOut += push.length;
        log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [slot1c-status-push] (${push.length}b)  ${push.toString('hex')}`);
        save(`p${pktCounter}_${rinfo.address.replace(/\./g, '_')}_${rinfo.port}_OUT_slot1c_push`, push);

        // Mark push send time so the next transport-ACK triggers POST-GAME-ACK
        // snapshot. Also kick off delayed snapshots to catch any transient state
        // between the EE receiving our push and the game sending its ACK.
        if (s.snapFile) {
          s.pushedAt = Date.now();
          runSnapshot(s.snapFile, 'POST-PUSH (push sent)', s.snapT0);
          setTimeout(() => runSnapshot(s.snapFile, 'T+50ms after push', s.snapT0), 50);
          setTimeout(() => runSnapshot(s.snapFile, 'T+200ms after push', s.snapT0), 200);
          setTimeout(() => runSnapshot(s.snapFile, 'T+1000ms after push', s.snapT0), 1000);
        }
      });
    }

    // 2026-06-21 (T19): RE-TIMED establish-push. PINE proved slot-0x1c callback (conn+0x5b8) is
    // FUN_00626730 (connect-SM result handler) ONLY during the early connect window (~+0..1.1s),
    // and is re-registered to 0x5bca90 by cmd0c time (~+24s) — so the old post-cmd0c push hit the
    // WRONG callback. The post-register-bind is at ~+616ms = inside the 0x626730 window. Fire op-0x31
    // with f4=0x13 HERE so FUN_00626730 sees a0==0x27/f4==0x13 → cs_result=1. Gated SNAP_ESTAB_ON_BIND=1.
    const regN = regCountByIp.get(rinfo.address) || 0;
    const estabMinReg = parseInt(process.env.SNAP_ESTAB_MIN_REG || '2', 10);  // 2 = select bind, not login
    if (klass === 'post-register-bind' && process.env.SNAP_ESTAB_ON_BIND === '1'
        && regN >= estabMinReg && !s.estabOnBindDone) {
      s.estabOnBindDone = true;
      const reOp    = parseInt(process.env.SNAP_ROOM_ENTER_OP || '0x31', 0) & 0xff;
      const reF4    = parseInt(process.env.SNAP_ROOM_ENTER_F4 || '0x13', 0) >>> 0;
      const reSeq   = nextTxSeq(s);                 // in-order: register-reply=0 → this=1 (==recvBase)
      const token   = msg.subarray(4, 8);
      const trailer = msg.subarray(msg.length - 4);
      const rePayload = Buffer.alloc(0xc);
      rePayload.writeUInt32BE(reF4, 0x08);          // payload[2] → connect-SM event.f4 (param_2+0x44)
      const rePush = Buffer.concat([Buffer.alloc(0x10), rePayload, trailer]);
      rePush[0] = 0xe0; rePush[1] = (rePush.length - 4) & 0xff; rePush[2] = 0x00; rePush[3] = reOp;
      token.copy(rePush, 0x04);
      rePush.writeUInt32BE(reSeq, 0x08);
      sendSnapPacket(s, rePush, rinfo, perr => {
        if (perr) { log(s, `  estab-on-bind err: ${perr.message}`); return; }
        s.outCount++; s.totalOut += rePush.length;
        log(s, `[udp ${s.key}] ${dt}  OUT #${s.outCount} [estab-on-bind op=0x${reOp.toString(16)} f4=0x${reF4.toString(16)} seq=0x${reSeq.toString(16)}] (${rePush.length}b) ${rePush.toString('hex')}`);
      });
    }
  });
});

server.on('listening', () => {
  const a = server.address();
  console.log(`UDP game server listening on ${a.address}:${a.port}`);
  console.log(`Captures: ${CAPTURES_DIR}`);
  console.log(`Default ACK strategy: snap-register-reply (bytes0-3 = B0 96 00 2d, body at wire 0x${BODY_OFFSET.toString(16)}, body len 0x${BODY_LEN.toString(16)}; declared body_len 0x86 mirrors request for transport-layer match)`);
  console.log(`State-3 push test: SNAP_STATE3_PUSH_TEST=${process.env.SNAP_STATE3_PUSH_TEST || 'unset'}  (set to '1' to enable opcode-0x0f experiment after post-register-bind ACK)`);
  console.log(`Post-lobby slot1c push: ${process.env.SNAP_POST_LOBBY_PUSH === '0' ? 'disabled' : 'enabled'}  (set SNAP_POST_LOBBY_PUSH=0 to disable)`);
  console.log(`PINE auto-advance state+0x80=3: ${process.env.SNAP_PINE_AUTO_ADVANCE === '0' ? 'disabled' : 'ENABLED'} (set SNAP_PINE_AUTO_ADVANCE=0 to disable; needs PCSX2 PINE port 28011)`);
  console.log(`On retry from same client, rotates to bioserv-server-tell â†’ mirror-plain â†’ mirror-set-byte0-18`);
});

server.on('error', err => {
  console.log(`UDP server error: ${err.message}`);
  server.close();
});

server.bind(PORT, '0.0.0.0');

// ── Establishment-message experiment (2026-06-10) ────────────────────────────
// The post-lobby connect (FUN_00626900) waits for event bit 0x10, set only by an
// inbound reliable DATA message that reassembles to attrs 0x1000+0x200. The server
// normally sends nothing post-lobby. proactivePush() sends a candidate deliverable
// message to the game's UDP :port using the cached session address. snap_server
// calls this after the lobby walk (POST_LOBBY_ACK). Variants via SNAP_ESTAB_VARIANT:
//   b096-fresh (default) = re-send the proven-deliverable register-reply framing,
//                          one body byte varied so it is NOT a byte-identical dup.
//   b018-fresh           = fresh slot1c-style control push (varied) — control type.
let _estabCounter = 0;
function proactivePush(ip) {
  let s = null;
  for (const v of sessions.values()) {
    if (v.key.startsWith(ip + ':')) { if (!s || v.lastSeen > s.lastSeen) s = v; }
  }
  if (!s) return { ok: false, reason: 'no UDP session for ' + ip };
  const port = parseInt(s.key.split(':')[1], 10);
  const variant = process.env.SNAP_ESTAB_VARIANT || 'b096-fresh';
  const n = (++_estabCounter) & 0xff;
  let push;
  if (variant === 'b096-fresh' && s.lastReplyB096) {
    push = Buffer.from(s.lastReplyB096);
    push[0x10] = (push[0x10] + n) & 0xff;          // vary first body byte (not a byte-identical dup)
  } else if (s.addr16) {
    push = Buffer.alloc(0x1C);
    push[0] = 0xB0; push[1] = 0x18; push[2] = 0x00; push[3] = 0x28;
    s.addr16.copy(push, 4, 0, 12);
    push[0x13] = 0x01; push[0x17] = n;             // selector 1, varied status
    push[0x18] = 0xba; push[0x19] = 0x47; push[0x1a] = 0x66; push[0x1b] = 0x11;
  } else {
    return { ok: false, reason: 'no template/addr for ' + ip };
  }
  try { sendSnapPacket(s, push, { port, address: ip }, () => {}); } catch (e) { return { ok: false, reason: e.message }; }
  log(s, `[udp ${s.key}]  ESTAB-PUSH #${n} variant=${variant} (${push.length}b) ${push.slice(0, 8).toString('hex')}`);
  return { ok: true, key: s.key, variant, n };
}
// Test surface (additive): the pure engine-adapter builders, exported so their wire byte-layout can be
// unit-asserted without a live socket. No runtime behavior change (production uses them via engineAdapter).
module.exports = { proactivePush, buildMemberLeaveOp07Packet, buildMemberJoinOp06Packet };
