/**
 * Multi-client session store.
 *
 * Design principles (per user request "production server, handle 50 requests at once"):
 *  - Multiple concurrent pending entries per IP â€” keyed by sessid not ip alone.
 *  - In-memory cache, debounced writeback to disk.
 *  - Sliding TTL: every touch extends the pending entry's lifetime.
 *  - No "wipe all on event X" hammer hacks. Stale entries time out naturally.
 *  - getPendingOnline returns the most-recent (LIFO) pending entry for the IP
 *    â€” that matches how the game flow works: HTTP POST /enterareas arms a
 *    pending entry, then SN@P TCP connect happens seconds later from same IP.
 */
'use strict';
const fs = require('fs');
const path = require('path');

const STORE_FILE = path.join(__dirname, 'session_store.json');
const PENDING_TTL_MS = 5 * 60 * 1000;        // 5 min default lifetime
const SLIDING_TTL_MS = 2 * 60 * 1000;        // each touch extends to now+2min
const SESSION_TTL_MS = 60 * 60 * 1000;       // 1 hour for completed sessions
const FLUSH_INTERVAL_MS = 1500;              // debounced disk write

function defaultStore() {
  return {
    sessions: {},          // sessid â†’ session record
    pendingOnlineByIp: {}, // ip â†’ [list of pending entries, newest first]
  };
}

// === In-memory state ========================================================
let store;
let dirty = false;
let flushTimer = null;

function _initFromDisk() {
  try {
    if (!fs.existsSync(STORE_FILE)) { store = defaultStore(); return; }
    const raw = fs.readFileSync(STORE_FILE, 'utf8');
    const parsed = JSON.parse(raw);
    store = {
      sessions: parsed.sessions || {},
      pendingOnlineByIp: _normalizePendingShape(parsed.pendingOnlineByIp || {}),
    };
  } catch {
    store = defaultStore();
  }
  _purgeExpired();
}

// Backward-compat: older store format had pendingOnlineByIp[ip] = single object.
// New format: pendingOnlineByIp[ip] = array of objects.
function _normalizePendingShape(obj) {
  const out = {};
  for (const [ip, val] of Object.entries(obj)) {
    if (Array.isArray(val)) out[ip] = val;
    else if (val && typeof val === 'object') out[ip] = [val];
  }
  return out;
}

function _markDirty() {
  dirty = true;
  if (!flushTimer) {
    flushTimer = setTimeout(_flushNow, FLUSH_INTERVAL_MS);
    flushTimer.unref?.();
  }
}

function _flushNow() {
  flushTimer = null;
  if (!dirty) return;
  try {
    fs.writeFileSync(STORE_FILE, JSON.stringify(store, null, 2));
    dirty = false;
  } catch (e) {
    // disk write failed â€” keep dirty=true so next flush retries
  }
}

function _purgeExpired(now = Date.now()) {
  // Drop expired pending entries
  for (const [ip, list] of Object.entries(store.pendingOnlineByIp)) {
    const kept = list.filter(p => !p.expiresAt || p.expiresAt > now);
    if (kept.length === 0) delete store.pendingOnlineByIp[ip];
    else if (kept.length !== list.length) store.pendingOnlineByIp[ip] = kept;
  }
  // Drop very old sessions (LRU-style)
  for (const [sessid, sess] of Object.entries(store.sessions)) {
    const t = sess.updatedAtMs || (sess.updatedAt ? Date.parse(sess.updatedAt) : 0);
    if (t && now - t > SESSION_TTL_MS) delete store.sessions[sessid];
  }
}

// Background TTL sweep â€” every 30 s. Multi-client safe (no callback contention).
setInterval(() => { _purgeExpired(); _markDirty(); }, 30_000).unref?.();

// === Public API =============================================================

function loadStore() { return store; }
function saveStore(_s) { /* no-op (kept for API compat) */ store = _s || store; _markDirty(); }

function upsertSession(sessid, data) {
  const now = Date.now();
  store.sessions[sessid] = {
    ...(store.sessions[sessid] || {}),
    ...data,
    updatedAt: new Date(now).toISOString(),
    updatedAtMs: now,
  };
  _markDirty();
  return store.sessions[sessid];
}

function getSession(sessid) {
  return store.sessions[sessid] || null;
}

// Same shape as markPendingOnlineFromLbs but armed by a UDP-9090 REGISTER
// completion instead of the HTTP/LBS flow. Used by game_udp_server.js after
// it observes the post-register-bind packet (= REGISTER auth complete on the
// EE side). The TCP 10127 server checks getPendingOnline like usual â€” keeps
// server independence (snap_server.js doesn't know or care which path armed it).
function markPendingOnlineFromRegister({ ip, userid, handle, ttlMs = PENDING_TTL_MS }) {
  const now = Date.now();
  const expiresAt = now + ttlMs;
  const finalHandle = handle || userid;
  const sessid = `udp9090:${userid}:${now}`;

  store.sessions[sessid] = {
    userid,
    handle: finalHandle,
    ip,
    udpRegisterAt: new Date(now).toISOString(),
    pendingOnline: true,
    pendingOnlineState: 'armed-udp9090',
    pendingOnlineUseCount: 0,
    expiresAt,
    updatedAt: new Date(now).toISOString(),
    updatedAtMs: now,
  };

  const pending = {
    sessid,
    userid,
    handle: finalHandle,
    createdAt: now,
    expiresAt,
    useCount: 0,
    lastSeenAt: now,
    armedFrom: 'udp9090-register',
  };

  const list = store.pendingOnlineByIp[ip] || [];
  const filtered = list.filter(p => p.sessid !== sessid);
  filtered.unshift(pending);
  store.pendingOnlineByIp[ip] = filtered;

  _markDirty();
  return pending;
}

// Short-lived re-arm after a successful TCP 10127 lobby walk (0x1004 ACK sent
// + clean FIN). The next TCP 10127 connect from the same IP enters
// SESSION_VERIFY/dispatch phase, not BOOT_AUTH. Per Codex
// analysis/tcp10127-second-connection-session-verify.md. Independence intact:
// per-IP, single-use, short TTL.
function markPendingPostLobbyResume({ ip, userid, handle, ttlMs = 60_000, refreshCount = 1 }) {
  const now = Date.now();
  const expiresAt = now + ttlMs;
  const finalHandle = handle || userid;
  const sessid = `post-lobby-resume:${userid}:${now}`;

  store.sessions[sessid] = {
    userid,
    handle: finalHandle,
    ip,
    postLobbyResumeAt: new Date(now).toISOString(),
    pendingOnline: true,
    pendingOnlineState: 'armed-post-lobby-resume',
    pendingOnlineUseCount: 0,
    refreshCount,
    expiresAt,
    updatedAt: new Date(now).toISOString(),
    updatedAtMs: now,
  };

  const pending = {
    sessid,
    userid,
    handle: finalHandle,
    createdAt: now,
    expiresAt,
    useCount: 0,
    lastSeenAt: now,
    armedFrom: 'post-lobby-resume',
    refreshCount,
  };

  store.pendingOnlineByIp[ip] = [pending];  // replace any prior list â€” single-use
  _markDirty();
  return pending;
}

function markPendingOnlineFromLbs({ ip, sessid, userid, handle, ttlMs = PENDING_TTL_MS }) {
  const now = Date.now();
  const expiresAt = now + ttlMs;
  const finalHandle = handle || store.sessions[sessid]?.handle || userid;

  store.sessions[sessid] = {
    ...(store.sessions[sessid] || {}),
    userid,
    handle: finalHandle,
    ip,
    lbsPostedAt: new Date(now).toISOString(),
    pendingOnline: true,
    pendingOnlineState: 'armed',
    pendingOnlineUseCount: 0,
    expiresAt,
    updatedAt: new Date(now).toISOString(),
    updatedAtMs: now,
  };

  const pending = {
    sessid,
    userid,
    handle: finalHandle,
    createdAt: now,
    expiresAt,
    useCount: 0,
    lastSeenAt: now,
    armedFrom: 'lbs',
  };

  const list = store.pendingOnlineByIp[ip] || [];
  // De-duplicate by sessid â€” if same sessid re-armed, replace existing entry
  const filtered = list.filter(p => p.sessid !== sessid);
  filtered.unshift(pending);  // newest first
  store.pendingOnlineByIp[ip] = filtered;

  _markDirty();
  return pending;
}

function getPendingOnline(ip) {
  const now = Date.now();
  const list = store.pendingOnlineByIp[ip] || [];

  // Find the newest non-expired entry
  const fresh = list.filter(p => !p.expiresAt || p.expiresAt > now);
  if (fresh.length === 0) {
    if (list.length > 0) delete store.pendingOnlineByIp[ip];  // all expired
    return null;
  }
  store.pendingOnlineByIp[ip] = fresh;

  const pending = fresh[0];  // newest
  pending.useCount = (pending.useCount || 0) + 1;
  pending.lastSeenAt = now;
  pending.expiresAt = Math.max(pending.expiresAt || 0, now + SLIDING_TTL_MS); // slide

  if (store.sessions[pending.sessid]) {
    store.sessions[pending.sessid].snapConnectedAt = new Date(now).toISOString();
    store.sessions[pending.sessid].pendingOnlineState = 'snap-connected';
    store.sessions[pending.sessid].pendingOnlineUseCount = pending.useCount;
    store.sessions[pending.sessid].updatedAt = new Date(now).toISOString();
    store.sessions[pending.sessid].updatedAtMs = now;
  }

  _markDirty();

  return {
    sessid: pending.sessid,
    userid: pending.userid,
    handle: pending.handle,
    session: store.sessions[pending.sessid] || null,
    useCount: pending.useCount,
    armedFrom: pending.armedFrom || null,   // stable; pending.session.pendingOnlineState gets mutated to 'snap-connected' above
    refreshCount: pending.refreshCount || 0,
  };
}

function clearPendingOnline(ip, reason = 'cleared', sessid = null) {
  const list = store.pendingOnlineByIp[ip];
  if (!list || list.length === 0) return false;

  const now = Date.now();
  const shouldClear = p => !sessid || p.sessid === sessid;
  let cleared = false;
  const kept = [];

  for (const p of list) {
    if (!shouldClear(p)) {
      kept.push(p);
      continue;
    }
    cleared = true;
    if (store.sessions[p.sessid]) {
      store.sessions[p.sessid].pendingOnline = false;
      store.sessions[p.sessid].pendingClearedReason = reason;
      store.sessions[p.sessid].updatedAt = new Date(now).toISOString();
      store.sessions[p.sessid].updatedAtMs = now;
    }
  }

  if (!cleared) return false;
  if (kept.length > 0) store.pendingOnlineByIp[ip] = kept;
  else delete store.pendingOnlineByIp[ip];
  _markDirty();
  return true;
}

/**
 * Diagnostic helper: snapshot count for logging.
 */
function pendingStats() {
  let totalEntries = 0;
  for (const list of Object.values(store.pendingOnlineByIp)) totalEntries += list.length;
  return {
    ips: Object.keys(store.pendingOnlineByIp).length,
    entries: totalEntries,
    sessions: Object.keys(store.sessions).length,
  };
}

// Backwards-compat shim for old call sites
function purgeExpired(_s, now) { _purgeExpired(now); _markDirty(); return true; }

// Initialize on module load
_initFromDisk();

// Graceful flush on exit
process.on('beforeExit', _flushNow);
process.on('SIGINT', () => { _flushNow(); process.exit(0); });

module.exports = {
  STORE_FILE,
  loadStore,
  saveStore,
  purgeExpired,
  upsertSession,
  getSession,
  markPendingOnlineFromLbs,
  markPendingOnlineFromRegister,
  markPendingPostLobbyResume,
  getPendingOnline,
  clearPendingOnline,
  pendingStats,
};

