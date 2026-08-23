'use strict';
// area-data.test.cjs — asserts the op48 area blob carries the AUTHENTIC File #2 area roster
// (bioserv2/Areas.java:35-44 + RULE-DATA-CATALOG-2026-07-19 §1.1), NOT the old invented labels.
// Data-only check: verifies names/count/status bytes + per-area rule presets, at the exact wire
// offsets the encoder uses (name @rec+0x1c, status @rec+0x14c). Run: node server/area-data.test.cjs
const assert = require('assert');
// snap_server.js top-level require('../tools/pine_client') is currently unresolved on disk (only
// tools/pine/pine_client.js is tracked — the flat tools/pine_client.js was removed by the reverted
// docker-harness commit). That is a PRE-EXISTING breakage unrelated to area data; to unit-test the
// pure area-blob encoder in isolation we stub that one require. No production code is modified.
const Module = require('module');
const _load = Module._load;
Module._load = function (request, parent, isMain) {
  if (request === '../tools/pine_client' || /[\\/]tools[\\/]pine_client$/.test(request)) {
    return { PineClient: class PineClient {} };
  }
  return _load.apply(this, arguments);
};
process.env.SNAP_TEST_NO_LISTEN = '1';   // require the encoder without binding :10127 (else the test hangs)
const S = require('./snap_server');
Module._load = _load;

let pass = 0;
const ok = (c, m) => { assert.ok(c, m); console.log('  ✓ ' + m); pass++; };
const eq = (a, b, m) => { assert.strictEqual(a, b, `${m} (got ${a}, want ${b})`); console.log('  ✓ ' + m); pass++; };

// Read a NUL-terminated latin1 string of at most `len` bytes at `off`.
function readName(buf, off, len) {
  let end = off;
  while (end < off + len && buf[end] !== 0) end++;
  return buf.slice(off, end).toString('latin1');
}

const blob = S.buildAreaBlob();

// --- wire FORMAT is unchanged (constants only asserted, not re-defined) ---
eq(S.AREA_BOX_COUNT, 10, 'File #2 has 10 areas');
eq(S.AREA_REC_SIZE, 0x1e4, 'record size unchanged (0x1e4)');
eq(S.AREA_BLOB_SIZE, 0x1300, 'blob size unchanged (0x1300)');
eq(blob.length, S.AREA_BLOB_SIZE, 'blob length == AREA_BLOB_SIZE');

// --- authentic roster (Areas.java:35-44), name @rec+0x1c, status @rec+0x14c ---
// [name, active?] — area 6 (reserved) and area 10 (SECRET default) are INACTIVE.
const EXPECT = [
  ['Free Area',   true],
  ['Nightmare',   true],
  ['Survival',    true],
  ['Panic',       true],
  ['Infinity',    true],
  ['reserved',    false],
  ['TESTING',     true],
  ['Elimination', true],
  ['Showdown',    true],
  ['SECRET Area', false],
];
EXPECT.forEach(([name, active], i) => {
  const rec = i * S.AREA_REC_SIZE;
  eq(readName(blob, rec + 0x1c, 24), name, `area ${i + 1} name @rec+0x1c == "${name}"`);
  eq(blob[rec + 0x14c], active ? 3 : 0, `area ${i + 1} status @rec+0x14c == ${active ? '3 (ACTIVE)' : '0 (INACTIVE)'}`);
});

// --- the old INVENTED labels must be gone (catalog §1.2 flags them as wrong) ---
const INVENTED = ['Normal', 'Hard', 'Very Hard', '75% Healing', 'Double Damage', 'Infinite Ammo', 'No Healing', 'Infinite'];
const shipped = S.AREA_BOXES.map(b => b.name);
INVENTED.forEach(bad => ok(!shipped.includes(bad), `invented label "${bad}" is NOT shipped`));

// --- per-area rule PRESETS (catalog §1.4/§3, HIGH-confidence flag presets; byte values MED) ---
// Difficulty group entries are [opt,val,en,attr] at index 3+. FF=opt2, NM=opt5, INF=opt6 (val 1=on).
const M = S.AREA_MODIFIER_BYTES;
function hasFlag(bytes, opt) {
  // scan the difficulty-group entries (start at index 3, stride 4) for an [opt,1,...] entry
  for (let i = 3; i + 3 < bytes.length; i += 4) if (bytes[i] === opt && bytes[i + 1] === 1) return true;
  return false;
}
ok(hasFlag(M.nightmare, 0x05), 'area 2 Nightmare preset sets NIGHTMARE (opt5) on');
ok(hasFlag(M.survival, 0x02),  'area 3 Survival preset sets FRIENDLY FIRE (opt2) on');
ok(hasFlag(M.panic, 0x02) && hasFlag(M.panic, 0x05), 'area 4 Panic preset sets FF + NIGHTMARE on');
ok(hasFlag(M.infinity, 0x06), 'area 5 Infinity preset sets INFINITY (opt6) on');
ok(!hasFlag(M.free, 0x02) && !hasFlag(M.free, 0x05) && !hasFlag(M.free, 0x06), 'area 1 Free preset carries no fixed special flags');

console.log(`\narea-data.test.cjs: ${pass} assertions passed`);
