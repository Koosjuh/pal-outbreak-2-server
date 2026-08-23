'use strict';
// Byte-layout smoke test for the op07 MEMBER-LEAVE builder (SPINE-3 survivor-notify wire vehicle).
// Run: node server/leave-op07-wire.test.cjs
// The op07 body layout is DECOMPILE-KNOWN, RIG-UNCONFIRMED (SPINE-2-3-lobby-leave-RE-2026-07-19 "Still
// capture-gated" #1 / EXP-C5). This test pins the constants we chose against the decompile so a typo in
// opcode/who/offset/endianness is caught locally; the 2-client survivor render is the rig capture.
// dgram is stubbed so requiring the server module does NOT bind UDP 9090.
const assert = require('assert');
const Module = require('module');
const origLoad = Module._load;
Module._load = function (req, ...rest) {
  if (req === 'dgram') {
    return { createSocket: () => ({ on() {}, bind() {}, send() {}, close() {}, address() { return { address: '0.0.0.0', port: 9090 }; }, unref() {} }) };
  }
  // The server's optional PINE diagnostic require uses a path that isn't present in every checkout
  // (tools/pine/pine_client.js vs the ../tools/pine_client require). Stub it — this test only needs
  // the pure wire builders, not the diagnostic client.
  if (typeof req === 'string' && req.endsWith('pine_client')) return { PineClient: class { async connect() {} } };
  return origLoad.call(this, req, ...rest);
};
const srv = require('./game_udp_server');
Module._load = origLoad;

let pass = 0;
const ok = (c, m) => { assert.ok(c, m); console.log('  ✓ ' + m); pass++; };
const eq = (a, b, m) => { assert.strictEqual(a, b, `${m} (got ${a}, want ${b})`); console.log('  ✓ ' + m); pass++; };

// A minimal session stub: addr16 = the 16-byte token the proactive push mirrors, + a tx-seq counter.
function sess() {
  return { addr16: Buffer.from('0011223344556677889900aabbccddee', 'hex'), _txSeq: 0x40, key: 'T:1' };
}

// buildMemberLeaveOp07Packet consumes nextTxSeq(sess) which reads/increments sess.txSeqNext internally;
// we only assert the STRUCTURAL fields (opcode/who/id/trailer/length), not the seq value.
{
  const p = srv.buildMemberLeaveOp07Packet(sess(), 2);
  ok(Buffer.isBuffer(p), 'op07: builder returns a Buffer');
  eq(p.length, 0x24, 'op07: total length 0x24 (0x10 hdr + 0x10 body + 4 trailer)');
  eq(p[0] & 0xf0, 0xa0, 'op07: who nibble 0xA0 (DATA clear -> slot 6 member-LEAVE)');
  eq(p[3], 0x07, 'op07: opcode byte = 0x07 (MEMBER LEAVE)');
  eq(p[2], 0x00, 'op07: sub byte = 0x00');
  const wireLen = ((p[0] & 0x03) << 8) | p[1];
  eq(wireLen, p.length - 4, 'op07: wire length field = total-4 (low 10 bits)');
  eq(p.readUInt32LE(0x10), 2, 'op07: leaver member-id at body+0 (wire 0x10), LE (FUN_005bb670 native read)');
  // session token mirror: addr16[0..12) copied to wire[4..16), then the reliable seq stamps wire[8..12)
  // (same shape as the proven op06 builder). So the token is intact at wire[4..8) and wire[0xc..0x10).
  const tok = sess().addr16;
  ok(p.slice(4, 8).equals(tok.slice(0, 4)), 'op07: session token mirrored at wire[4..8)');
  ok(p.slice(0xc, 0x10).equals(tok.slice(8, 12)), 'op07: session token mirrored at wire[0xc..0x10) (seq occupies 0x08)');
  eq(p.toString('hex', 0x20, 0x24), 'ba476611', 'op07: trailer magic ba476611 at the tail');
}

// Sanity: distinct id round-trips (host-departure carries the host id = playerNo 1).
{
  const p = srv.buildMemberLeaveOp07Packet(sess(), 1);
  eq(p.readUInt32LE(0x10), 1, 'op07: host-leave carries member-id 1 (same op07 vehicle, SPINE-3)');
}

// null-session guard (no addr16 -> nothing to send).
eq(srv.buildMemberLeaveOp07Packet({}, 2), null, 'op07: builder returns null with no session token');

console.log(`\nleave-op07-wire: ${pass} assertions passed`);
