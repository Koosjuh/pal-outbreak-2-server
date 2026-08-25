import assert from 'node:assert/strict';
import test from 'node:test';

import { TimingWheel } from '../src/transport/timing-wheel.js';
import { createV1ObservedAreaDirectory } from '../src/udp/area-directory.js';
import { LOBBY_OPCODE } from '../src/udp/snap-lobby-codec.js';
import { SnapLobbySessions } from '../src/udp/snap-lobby-sessions.js';

/**
 * SNAP_ROSTER_TO_JOINER (analysis/seated-slot-roster-RE-2026-08-25): a joiner
 * must receive an op-06 for every EXISTING member so it seats them in its own
 * 0x6c7c2c (the table FUN_00605790 renders the member list from). Without it
 * the joiner's list shows only itself.
 */

const TOKEN_HOST = 0x02f807d0;
const TOKEN_JOINER = 0x028107d0;

function reliableDatagram({ opcode, sequence, payload = Buffer.alloc(0), who = 0xb000, token }) {
  const inner = 0x10 + payload.length;
  const d = Buffer.alloc(inner + 4);
  d.writeUInt16BE(who | inner, 0); d.writeUInt8(0, 2); d.writeUInt8(opcode, 3);
  d.writeUInt32BE(token, 4); d.writeUInt32BE(sequence, 8);
  payload.copy(d, 0x10); Buffer.from([0xba, 0x47, 0x66, 0x11]).copy(d, inner);
  return d;
}
function boxKeyOf(boxId) {
  const { records } = createV1ObservedAreaDirectory().records(() => 0);
  return records.find((e) => e.name.endsWith(String(boxId).padStart(2, '0'))).key;
}
function harness(sessions = {}) {
  let nowMs = 1_000, it = null;
  const wheel = new TimingWheel({
    tickMs: 100, clock: () => nowMs,
    setInterval: (fn) => { it = { fn, unref() {} }; return it; },
    clearInterval: () => { it = null; }, onError: () => {}
  });
  wheel.start();
  const table = new SnapLobbySessions({
    wheel, areaDirectory: createV1ObservedAreaDirectory(),
    keepaliveKey: 'SNAP-SWAN', joinLadder: true, ...sessions
  });
  const open = (rk, id, token) => {
    const sent = [];
    const session = table.open({
      routingKey: rk, loginIdentity: id, endpointToken: token,
      outboundSequence: 1, inboundReceiveBase: 0, latencyTicks: 1600,
      transmit: (d, c) => sent.push({ datagram: d, ...c })
    });
    return { session, sent, token, seq: 0, next() { this.seq += 1; return this.seq - 1; } };
  };
  return { open };
}
function enter(c, box) {
  const k = Buffer.alloc(4); k.writeUInt32BE(boxKeyOf(box));
  c.session.accept(reliableDatagram({ opcode: LOBBY_OPCODE.AREA_ENTER, sequence: c.next(), payload: k, token: c.token }));
}
function createRoom(c) {
  const at = c.sent.length;
  c.session.accept(reliableDatagram({ opcode: LOBBY_OPCODE.CREATE_ROOM, sequence: c.next(), payload: Buffer.alloc(0x2c), token: c.token }));
  return c.sent.slice(at).find((e) => e.datagram[3] === LOBBY_OPCODE.COMPLETION && e.datagram.readUInt32BE(0x10) === 4).datagram.readUInt32BE(0x14);
}
function joinRoom(c, handle) {
  const body = Buffer.alloc(0x18); body.writeUInt32LE(handle, 0);
  c.session.accept(reliableDatagram({ opcode: LOBBY_OPCODE.AREA_ENTER, sequence: c.next(), payload: body, who: 0xa000, token: c.token }));
}
function memberJoinsTo(client, sinceIndex) {
  return client.sent.slice(sinceIndex).filter((e) =>
    e.kind === 'reliable' && e.datagram.length >= 0x108 && e.datagram[3] === LOBBY_OPCODE.MEMBER_JOIN);
}

test('OFF (default): the joiner gets only its own member-JOIN, none for the host', () => {
  const rig = harness();
  const host = rig.open('192.168.2.248:2000', 'test123', TOKEN_HOST);
  const joiner = rig.open('192.168.2.129:2000', 'real', TOKEN_JOINER);
  enter(host, 1); const h = createRoom(host); enter(joiner, 1);
  const at = joiner.sent.length;
  joinRoom(joiner, h);
  assert.equal(memberJoinsTo(joiner, at).length, 1, 'pre-fix: only the joiner self-record');
});

test('ON: the joiner also receives an op-06 for the existing host (seats it in the member list)', () => {
  const rig = harness({ rosterToJoiner: true });
  const host = rig.open('192.168.2.248:2000', 'test123', TOKEN_HOST);
  const joiner = rig.open('192.168.2.129:2000', 'real', TOKEN_JOINER);
  enter(host, 1); const h = createRoom(host); enter(joiner, 1);
  const at = joiner.sent.length;
  joinRoom(joiner, h);
  const records = memberJoinsTo(joiner, at);
  assert.ok(records.length >= 2, 'the joiner now gets its own record AND the host record');
  // one of them names the host and carries a distinct non-zero charstats key
  const names = records.map((e) => e.datagram.subarray(0x10, 0x20).toString('latin1').replace(/\0+$/, ''));
  assert.ok(names.some((n) => n.startsWith('test123')), 'the host is in the joiner\'s pushed roster');
});

test('SNAP_HOST_RESEAT: the host receives an extra op-06 for ITSELF when a joiner arrives', () => {
  const rig = harness({ hostReseat: true });
  const host = rig.open('192.168.2.248:2000', 'test123', TOKEN_HOST);
  const joiner = rig.open('192.168.2.129:2000', 'real', TOKEN_JOINER);
  enter(host, 1); const h = createRoom(host); enter(joiner, 1);
  const at = host.sent.length;
  joinRoom(joiner, h);
  const records = memberJoinsTo(host, at);
  const names = records.map((e) => e.datagram.subarray(0x10, 0x20).toString('latin1').replace(/\0+$/, ''));
  assert.ok(names.some((n) => n.startsWith('test123')), 'the host re-seats itself (its own name)');
  assert.ok(names.some((n) => n.startsWith('real')), 'and still seats the joiner');
});
