import assert from 'node:assert/strict';
import test from 'node:test';

import { TimingWheel } from '../src/transport/timing-wheel.js';
import { createV1ObservedAreaDirectory } from '../src/udp/area-directory.js';
import { LOBBY_OPCODE } from '../src/udp/snap-lobby-codec.js';
import { SnapLobbySessions } from '../src/udp/snap-lobby-sessions.js';

/**
 * THE COUNT PUSH (RS1-C C2, flag SNAP_COUNT_PUSH).
 *
 * The lobby-header count is latched from ONE op-0x09 USER answer at entry and
 * the client never re-queries it while it sits in the lobby, so the other
 * player's leave is invisible (the owner's stale "2"). The JP server closes
 * the gap with `broadcastAreaPlayerCnt` on every area enter/exit
 * (PacketHandler.java:661/746/1136); the PAL vehicle is an unsolicited
 * op-0x09 USER reply, byte-shaped exactly like the solicited answer:
 *
 *   - RS1 wire: the entry query is 0xB018 (DATA set) and the rig-rendered
 *     answer is 0xB01C `[BE32 key]['USER'][BE32 count]`;
 *   - `FUN_001dd5f8`/`FUN_001dd840` install the reply cb by SWAPPING it into
 *     the persistent conn+0x548 dispatch table (`FUN_001d4d24`), and
 *     dispatcher `FUN_001d9f78` case 6 invokes the slot on EVERY inbound
 *     op-0x09 without ever clearing it;
 *   - the slot-0x17 handler `FUN_005bf740` does no transaction matching: it
 *     sweeps registry-A for body word0 and commits word2 to the render
 *     struct - so the push re-renders the count on an idle client.
 */

const TOKEN_A = 0x02f807d0;
const TOKEN_B = 0x02f907d1;
const TOKEN_C = 0x02fa07d2;

function reliableDatagram({ opcode, sequence, sub = 0, payload = Buffer.alloc(0), who = 0xb000, token = TOKEN_A }) {
  const inner = 0x10 + payload.length;
  const datagram = Buffer.alloc(inner + 4);
  datagram.writeUInt16BE(who | inner, 0);
  datagram.writeUInt8(sub, 2);
  datagram.writeUInt8(opcode, 3);
  datagram.writeUInt32BE(token, 4);
  datagram.writeUInt32BE(sequence, 8);
  payload.copy(datagram, 0x10);
  Buffer.from([0xba, 0x47, 0x66, 0x11]).copy(datagram, inner);
  return datagram;
}

function harness(sessionOptions = {}) {
  const wheel = new TimingWheel({
    tickMs: 100,
    clock: () => 1_000,
    setInterval: (fn) => ({ fn, unref() {} }),
    clearInterval: () => {},
    onError: () => {}
  });
  wheel.start();
  const table = new SnapLobbySessions({
    wheel,
    areaDirectory: createV1ObservedAreaDirectory(),
    keepaliveKey: 'SNAP-SWAN',
    countPush: true,
    ...sessionOptions
  });
  const open = (routingKey, identity, token) => {
    const sent = [];
    const session = table.open({
      routingKey,
      loginIdentity: identity,
      endpointToken: token,
      outboundSequence: 1,
      inboundReceiveBase: 0,
      latencyTicks: 1600,
      transmit: (datagram, context) => sent.push({ datagram, ...context })
    });
    return { routingKey, session, sent, token, seq: 0, next() { this.seq += 1; return this.seq - 1; } };
  };
  return { table, open };
}

function enter(client, boxKey) {
  const key = Buffer.alloc(4);
  key.writeUInt32BE(boxKey);
  client.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.AREA_ENTER, sequence: client.next(), payload: key,
    who: 0xb000, token: client.token
  }));
}

function leave(client) {
  client.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.AREA_LEAVE, sequence: client.next(),
    who: 0xb000, token: client.token
  }));
}

/** Every op-0x09 frame this session was sent. The push and the answer share the opcode. */
function op09Frames(sent) {
  return sent.filter((entry) =>
    (entry.kind === 'reliable' || entry.kind === 'mirrored') &&
    entry.datagram.length > 4 && entry.datagram[3] === LOBBY_OPCODE.AREA_COUNT_QUERY);
}

test('a second ENTER pushes the fresh USER count to the sitting session - the exact solicited-answer bytes', () => {
  const rig = harness();
  const alice = rig.open('192.0.2.129:2000', 'real', TOKEN_A);
  const bob = rig.open('192.0.2.248:2000', 'test123', TOKEN_B);
  enter(alice, 4);
  const beforeAlice = alice.sent.length;
  const beforeBob = bob.sent.length;

  enter(bob, 4);

  const pushes = op09Frames(alice.sent.slice(beforeAlice));
  assert.equal(pushes.length, 1, 'exactly one push per transition, to the sitting session');
  const [push] = pushes;
  // BREAK-THE-FIX ANCHOR: the wire word tonight's rig-rendered answers carried.
  // Inner = 0x10 header + 0x0c body; who 0xB0 = RELIABLE|SET|DATA - DATA set is
  // what routes to slot 0x17, where the entry query's handler is installed.
  assert.equal(push.datagram.readUInt16BE(0), 0xb01c,
    'who|len 0xB01C - byte-identical to the solicited USER answer (RS1 17:33:33.714)');
  assert.equal(push.datagram[2], 0, 'sub 0: nothing routes on it and no request exists to echo');
  const body = push.datagram.subarray(0x10, 0x1c);
  assert.equal(body.readUInt32BE(0), 4, 'word0 = the area +0x20 key the client itself queried with');
  assert.deepEqual(body.subarray(4, 8), Buffer.from('USER', 'latin1'), 'the USER tag');
  assert.equal(body.readUInt32BE(8), 2, 'word2 = the live post-enter count');

  assert.equal(op09Frames(bob.sent.slice(beforeBob)).length, 0,
    'the mover is excluded: its own op-0x09 query volley follows the ENTER and answers fresher');
});

test('an op-0x07 area leave pushes the decremented count to who remains - the stale-"2" fix', () => {
  const rig = harness();
  const alice = rig.open('192.0.2.129:2000', 'real', TOKEN_A);
  const bob = rig.open('192.0.2.248:2000', 'test123', TOKEN_B);
  enter(alice, 4);
  enter(bob, 4);
  const before = alice.sent.length;

  leave(bob);

  const pushes = op09Frames(alice.sent.slice(before));
  assert.equal(pushes.length, 1, 'RS1 17:37:06: the leave that left the owner watching a stale 2');
  const body = pushes[0].datagram.subarray(0x10, 0x1c);
  assert.equal(body.readUInt32BE(0), 4);
  assert.deepEqual(body.subarray(4, 8), Buffer.from('USER', 'latin1'));
  assert.equal(body.readUInt32BE(8), 1, 'the count the server always had - now the client hears it');
});

test('a room-level leave (depth 4 -> 2) pushes NOTHING: the area count did not change', () => {
  const rig = harness({ joinLadder: true, memberInfo: true });
  const host = rig.open('192.0.2.248:2000', 'test123', TOKEN_A);
  const other = rig.open('192.0.2.129:2000', 'real', TOKEN_B);
  enter(host, 3);
  enter(other, 3);
  host.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CREATE_ROOM, sequence: host.next(), payload: Buffer.alloc(0x2c),
    who: 0xb000, token: TOKEN_A
  }));
  const before = other.sent.length;

  // The in-room Exit (RS1-C C3's op-0x07): ascend clears room+slot, keeps the box.
  leave(host);

  assert.equal(op09Frames(other.sent.slice(before)).length, 0,
    'boxId is unchanged by a room ascend; a push here would be noise on the C3-fragile path');
});

test('a teardown (idle/cable-pull reclaim) pushes the vacated box - the RS1 17:50:34 case', () => {
  const rig = harness();
  const alice = rig.open('192.0.2.129:2000', 'real', TOKEN_A);
  const bob = rig.open('192.0.2.248:2000', 'test123', TOKEN_B);
  enter(alice, 4);
  enter(bob, 4);
  const before = alice.sent.length;

  rig.table.close(bob.routingKey, 'idle');

  const pushes = op09Frames(alice.sent.slice(before));
  assert.equal(pushes.length, 1, 'the idle-release detach is a leave nobody sent an op-0x07 for');
  assert.equal(pushes[0].datagram.readUInt32BE(0x18), 1, 'count 1 after the reclaim');
});

test('flag OFF: no unsolicited op-0x09 ever leaves - byte-identical to the RS1 build', () => {
  const rig = harness({ countPush: false });
  const alice = rig.open('192.0.2.129:2000', 'real', TOKEN_A);
  const bob = rig.open('192.0.2.248:2000', 'test123', TOKEN_B);
  enter(alice, 4);
  const before = alice.sent.length;

  enter(bob, 4);
  leave(bob);
  const carol = rig.open('192.0.2.130:2000', 'third', TOKEN_C);
  enter(carol, 4);
  rig.table.close(carol.routingKey, 'idle');

  assert.equal(op09Frames(alice.sent.slice(before)).length, 0,
    'with the flag off every op-0x09 byte on the wire is an answer to a query');
});

test('the push is scoped to the affected box: a neighbour area hears nothing', () => {
  const rig = harness();
  const alice = rig.open('192.0.2.129:2000', 'real', TOKEN_A);
  const bob = rig.open('192.0.2.248:2000', 'test123', TOKEN_B);
  enter(alice, 1);
  const before = alice.sent.length;

  enter(bob, 4);
  leave(bob);

  assert.equal(op09Frames(alice.sent.slice(before)).length, 0,
    'box 1 gained and lost nobody; scope is the presence bucket, never a broadcast to all');
});
