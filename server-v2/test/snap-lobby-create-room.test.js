import assert from 'node:assert/strict';
import test from 'node:test';

import { TimingWheel } from '../src/transport/timing-wheel.js';
import { createV1ObservedAreaDirectory } from '../src/udp/area-directory.js';
import {
  COMPLETION_SELECTOR,
  LOBBY_OPCODE,
  MEMBER_RECORD_BYTES,
  ROOM_STATE_SUB,
  buildCreateRoomAcceptPayload,
  decodeCreateRoomRequest
} from '../src/udp/snap-lobby-codec.js';
import { ROOM_QUERY_PURPOSE } from '../src/udp/snap-lobby-session.js';
import { SnapLobbySessions } from '../src/udp/snap-lobby-sessions.js';

/**
 * THE CREATE-ROOM WALL, and the back-out wall next to it.
 *
 * The client sends op-0x04 and parks in `FUN_005c3490` step 2 on `0x6CBA7D`,
 * which only an op-0x28 completion routed to slot 0x1f can write; and it sends
 * op-0x07 and parks in `FUN_005c1c80` step 3 on `cRam006cbb6d`, which only the
 * slot-0x23 completion can release. Neither wait has a timeout branch. V2 had no
 * case for either opcode, which is the frozen cursor and the failed back-out.
 *
 * Every byte asserted below is tied to a named client consumer; nothing here is
 * pattern-matched into agreement with the implementation.
 */

const TOKEN = 0x02f807d0;
const ROUTING_KEY = '192.0.2.248:2000';
const KEEPALIVE_KEY = 'SNAP-SWAN';

function reliableDatagram({ opcode, sequence, sub = 0, payload = Buffer.alloc(0) }) {
  const inner = 0x10 + payload.length;
  const datagram = Buffer.alloc(inner + 4);
  datagram.writeUInt16BE(0xb000 | inner, 0);
  datagram.writeUInt8(sub, 2);
  datagram.writeUInt8(opcode, 3);
  datagram.writeUInt32BE(TOKEN, 4);
  datagram.writeUInt32BE(sequence, 8);
  payload.copy(datagram, 0x10);
  Buffer.from([0xba, 0x47, 0x66, 0x11]).copy(datagram, inner);
  return datagram;
}

function harness({ identity = '12345', sessions = {} } = {}) {
  let nowMs = 1_000;
  let intervalToken = null;
  const logs = [];
  const wheel = new TimingWheel({
    tickMs: 100,
    clock: () => nowMs,
    setInterval: (fn) => { intervalToken = { fn, unref() {} }; return intervalToken; },
    clearInterval: () => { intervalToken = null; },
    onError: () => {}
  });
  wheel.start();
  const record = (level) => (message, fields) => logs.push({ level, message, fields });
  const table = new SnapLobbySessions({
    wheel,
    areaDirectory: createV1ObservedAreaDirectory(),
    keepaliveKey: KEEPALIVE_KEY,
    logger: {
      debug: record('debug'), info: record('info'), warn: record('warn'), error: record('error')
    },
    ...sessions
  });
  const sent = [];
  const session = table.open({
    routingKey: ROUTING_KEY,
    loginIdentity: identity,
    endpointToken: TOKEN,
    outboundSequence: 1,
    inboundReceiveBase: 0,
    latencyTicks: 1600,
    transmit: (datagram, context) => sent.push({ datagram, ...context })
  });
  return { wheel, table, session, sent, logs };
}

function enter(session, boxKey, sequence = 0) {
  const key = Buffer.alloc(4);
  key.writeUInt32BE(boxKey);
  session.accept(reliableDatagram({ opcode: LOBBY_OPCODE.AREA_ENTER, sequence, payload: key }));
}

/** The `0x2c` struct `func_0x001dc508` builds, with the fields it can carry. */
function createRequest({ name = '', maximum = 4, password = '', options = 0 } = {}) {
  const payload = Buffer.alloc(0x2c);
  Buffer.from(name, 'latin1').copy(payload, 0x00);
  payload.writeUInt32BE(maximum, 0x10);
  Buffer.from(password, 'latin1').copy(payload, 0x14);
  payload.writeUInt32BE(1, 0x24);
  payload.writeUInt32BE(options, 0x28);
  return payload;
}

/* ---- the accept, byte for byte ----------------------------------------- */

test('the op-0x04 accept payload is BE32 selector 4 then a BE32 handle', () => {
  const payload = buildCreateRoomAcceptPayload({ handle: 0x01020304 });
  assert.equal(payload.length, 8);
  assert.equal(payload.readUInt32BE(0x00), 4, 'selector 4 routes to slot 0x1f');
  /*
   * BIG-endian, and this is the corrected fact. `FUN_001d9f78` case 0x25 calls
   * `FUN_001d7f6c(msg + 0x3c)`, which byteswaps TWO words - `sw v0,0x0(a1)` at
   * 0x1d7fd4 and `sw v0,0x4(a1)` at 0x1d8030, straight-line, then `jr ra`. So
   * both the selector and the handle are BE on the wire.
   *
   * DIRECTIONAL: with the little-endian form V1 shipped, these two assertions
   * both fail - the second reads 0x04030201.
   */
  assert.equal(payload.readUInt32BE(0x04), 0x01020304, 'the handle is BE32, not LE32');
  assert.equal(payload.subarray(4).toString('hex'), '01020304');
});

test('the create accept is one reliable op-0x28 with every field the client reads', () => {
  const rig = harness();
  enter(rig.session, 3);
  const before = rig.sent.length;
  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CREATE_ROOM, sequence: 1, sub: 0x21, payload: createRequest()
  }));
  // [0] is the transport ack the channel sends for the inbound reliable message.
  const [, accept] = rig.sent.slice(before);
  assert.equal(accept.kind, 'reliable', 'stamped from the session counter, never mirrored');
  const wire = accept.datagram;

  assert.equal(wire.readUInt16BE(0x00), 0xb000 | 0x18, 'who 0xB0, inner length 0x18');
  assert.equal(wire[0x02], 0x21, 'the request\'s sub byte, echoed');
  assert.equal(wire[0x03], 0x28, 'wire byte 0x03 = 0x28 IS the accept status');
  assert.equal(wire.readUInt32BE(0x04), TOKEN, 'the session token, mirrored');
  // The server's OWN monotonic reliable sequence, stamped - not the request's,
  // which was 1. The ENTER accept above took sequence 1, so this is 2.
  assert.equal(wire.readUInt32BE(0x08), 2);
  assert.equal(wire.readUInt32BE(0x10), 4, 'selector 4 -> conn+0x5C4 -> slot 0x1f');
  assert.equal(wire.readUInt32BE(0x14), rig.session.createdRoom.handle, 'BE32 minted handle');
  assert.equal(wire.subarray(0x18).toString('hex'), 'ba476611', 'the SN@P trailer');
  assert.equal(wire.length, 0x1c);
});

test('the accept carries a server-minted handle that resolves back to the room', () => {
  const rig = harness();
  enter(rig.session, 5);
  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CREATE_ROOM, sequence: 1, payload: createRequest({ name: 'MINE' })
  }));
  const room = rig.session.createdRoom;
  assert.ok(room != null && room.handle > 0, 'a handle was minted; 0 is the client\'s empty slot');
  // Kept, so a later ENTER carrying this token finds the room it names.
  assert.equal(rig.table.rooms.byHandle(room.handle), room);
  assert.equal(room.boxId, 5, 'the room belongs to the area the creator is in');
  assert.equal(room.name, 'MINE');
});

test('handles are never reused, so a stale token can never resolve to another room', () => {
  const rig = harness();
  enter(rig.session, 5);
  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CREATE_ROOM, sequence: 1, payload: createRequest()
  }));
  const first = rig.session.createdRoom.handle;
  // Back out: the room empties and is closed by the same transition.
  rig.session.accept(reliableDatagram({ opcode: LOBBY_OPCODE.AREA_LEAVE, sequence: 2 }));
  assert.equal(rig.table.rooms.byHandle(first), null, 'the emptied room is gone');
  enter(rig.session, 5, 3);
  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CREATE_ROOM, sequence: 4, payload: createRequest()
  }));
  assert.notEqual(rig.session.createdRoom.handle, first, 'the freed handle was not reissued');
});

/* ---- selector-4 routing -------------------------------------------------- */

test('the completion selector 4 is what routes the reply to slot 0x1f', () => {
  /*
   * `FUN_001d9f78` switches on `*payload - 1`; entry 3 loads `conn + 0x5C4`, and
   * `0x5C4 = 0x548 + 0x1f*4`. The same arithmetic reproduces the two selectors
   * already proven on the rig, so it is corroborated rather than asserted:
   */
  const CALLBACK_TABLE_BASE = 0x548;
  const slotFromOffset = (offset) => (offset - CALLBACK_TABLE_BASE) / 4;
  assert.equal(slotFromOffset(0x5c4), 0x1f, 'selector 4 -> conn+0x5C4 -> slot 0x1f (create)');
  assert.equal(slotFromOffset(0x5cc), 0x21, 'selector 6 -> conn+0x5CC -> slot 0x21 (area enter)');
  assert.equal(slotFromOffset(0x5d4), 0x23, 'selector 7 -> conn+0x5D4 -> slot 0x23 (leave)');
  assert.equal(COMPLETION_SELECTOR.CREATE_ROOM, 4);
  assert.equal(COMPLETION_SELECTOR.AREA_ENTER, 6);
  assert.equal(COMPLETION_SELECTOR.AREA_LEAVE, 7);
});

/* ---- the reject ---------------------------------------------------------- */

test('a create from outside any area is REFUSED with wire opcode 0x27, not 0x31', () => {
  const rig = harness();
  // No ENTER: the session is at depth server, so there is no area to open into.
  const before = rig.sent.length;
  const result = rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CREATE_ROOM, sequence: 0, sub: 7, payload: createRequest()
  }));
  const [, reject] = rig.sent.slice(before);
  const wire = reject.datagram;

  assert.equal(wire[0x03], 0x27,
    'the reject is an OPCODE change; there is no status field in the payload');
  assert.notEqual(wire[0x03], 0x31,
    'wire 0x31 has its own case body routing to slot 0x1c and never reaches the selector switch');
  assert.equal(wire[0x02], 7, 'the sub byte is still echoed');
  assert.equal(wire.readUInt32BE(0x10), 4, 'the reject uses the IDENTICAL selector dispatch');
  assert.equal(rig.table.rooms.size, 0, 'no room was opened');
  assert.equal(result.handled[0].refused != null, true, 'the refusal is named, never silent');
});

test('a refused create is answered rather than dropped, because the client parks forever', () => {
  const rig = harness();
  const before = rig.sent.length;
  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CREATE_ROOM, sequence: 0, payload: createRequest()
  }));
  const replies = rig.sent.slice(before).filter((entry) => entry.kind === 'reliable');
  assert.equal(replies.length, 1, 'exactly one answer; silence is a permanent freeze');
});

/* ---- the create follow-ups ---------------------------------------------- */

test('the member-JOIN is the FIRST reliable after the accept, on the next sequence', () => {
  const rig = harness({ identity: 'TESTUSR' });
  enter(rig.session, 2);
  const before = rig.sent.length;
  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CREATE_ROOM, sequence: 1, payload: createRequest()
  }));
  const reliable = rig.sent.slice(before).filter((entry) => entry.kind === 'reliable');
  assert.equal(reliable[0].opcode, LOBBY_OPCODE.COMPLETION, 'the accept');
  /*
   * CONTIGUOUS, and that is the point. The client's reorder gate acks an inbound
   * reliable segment only when its sequence is at or above the live expected
   * sequence, BEFORE app dispatch - emitted mid-burst this was dropped un-acked
   * 12 times in 13.
   */
  assert.equal(reliable[1].opcode, LOBBY_OPCODE.MEMBER_JOIN, 'the roster delta comes next');
  assert.equal(reliable[1].sequence, reliable[0].sequence + 1);

  const record = reliable[1].datagram.subarray(0x10, 0x10 + MEMBER_RECORD_BYTES);
  assert.equal(record.length, MEMBER_RECORD_BYTES);
  const name = record.subarray(0, 0x10);
  assert.equal(name.subarray(0, name.indexOf(0)).toString('latin1'), 'TESTUSR',
    'an empty name is the client\'s free-row marker and would draw nothing');
  // who = 0xA0: RELIABLE|SET with DATA CLEAR, which is what routes it to slot 2.
  assert.equal(reliable[1].datagram[0x00] & 0xfc, 0xa0);
});

test('the header push carries max and current as the two bytes the client reads', () => {
  const rig = harness();
  enter(rig.session, 2);
  const before = rig.sent.length;
  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CREATE_ROOM, sequence: 1, payload: createRequest()
  }));
  const [limits] = rig.sent.slice(before)
    .filter((entry) => entry.opcode === LOBBY_OPCODE.ROOM_STATE);
  assert.ok(limits, 'op-0x10 sub-5 is sent; it is the only non-zero writer of 0x6ff2b4');
  assert.equal(limits.datagram[0x18], ROOM_STATE_SUB.ROOM_LIMITS, 'sub 5 at wire +0x18');
  assert.equal(limits.datagram[0x1c], 4, 'max at wire +0x1c');
  assert.equal(limits.datagram[0x1d], 1, 'current at wire +0x1d: the creator is in the room');
});

/* ---- presence ------------------------------------------------------------ */

test('a presence exists at BIND-ACCEPT, before any ENTER, and is counted on the server', () => {
  const rig = harness();
  /*
   * THE ORDERING FIX. Under the old model - location recorded only when an ENTER
   * resolved - this count was structurally zero, and the `0x6510` "current
   * players" field could only ever be a config constant. It is asked on the
   * TCP-10127 ladder, before the player has selected anything at all.
   */
  assert.equal(rig.table.presence.totalAttached(), 1);
  assert.equal(rig.table.playersOnServer(), 1, 'counted at depth server, with no area');
  assert.equal(rig.table.playersIn(3), 0, 'and in no area, which is also true');
  assert.equal(rig.session.presence.depth, 1);
});

test('counts are correct at every depth as one session descends and comes back up', () => {
  const rig = harness();
  const presence = rig.table.presence;
  const at = () => ({
    server: rig.table.playersOnServer(),
    area: rig.table.playersIn(6),
    depth: rig.session.presence.depth
  });

  assert.deepEqual(at(), { server: 1, area: 0, depth: 1 });
  enter(rig.session, 6);
  assert.deepEqual(at(), { server: 1, area: 1, depth: 2 });

  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CREATE_ROOM, sequence: 1, payload: createRequest()
  }));
  const handle = rig.session.createdRoom.handle;
  assert.deepEqual(at(), { server: 1, area: 1, depth: 4 }, 'a room member is still an area member');
  assert.equal(presence.countInRoom(handle), 1);
  assert.deepEqual(presence.rosterOf(handle).map((entry) => entry.displayName), ['12345']);

  // op-0x07 rises ONE level: out of the room, still in the area.
  rig.session.accept(reliableDatagram({ opcode: LOBBY_OPCODE.AREA_LEAVE, sequence: 2 }));
  assert.deepEqual(at(), { server: 1, area: 1, depth: 2 });
  assert.equal(presence.countInRoom(handle), 0);

  // And again: out of the area, still attached.
  rig.session.accept(reliableDatagram({ opcode: LOBBY_OPCODE.AREA_LEAVE, sequence: 3 }));
  assert.deepEqual(at(), { server: 1, area: 0, depth: 1 });

  rig.table.close(ROUTING_KEY, 'test');
  assert.equal(rig.table.playersOnServer(), 0, 'detached, and every count follows');
  presence.assertConsistent();
});

test('the indices are exactly what rebuilding them from the presence set would give', () => {
  const rig = harness();
  const presence = rig.table.presence;
  enter(rig.session, 4);
  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CREATE_ROOM, sequence: 1, payload: createRequest()
  }));
  // I1, the invariant that keeps a set-based index honest. A counter could drift
  // here and nothing in the data would say so.
  presence.assertConsistent();
  rig.session.accept(reliableDatagram({ opcode: LOBBY_OPCODE.AREA_LEAVE, sequence: 2 }));
  presence.assertConsistent();
});

/* ---- the leave ----------------------------------------------------------- */

test('op-0x07 is answered with selector 7, which is the slot the client installed', () => {
  const rig = harness();
  enter(rig.session, 8);
  const before = rig.sent.length;
  rig.session.accept(reliableDatagram({ opcode: LOBBY_OPCODE.AREA_LEAVE, sequence: 1, sub: 9 }));
  const [, accept] = rig.sent.slice(before);
  const wire = accept.datagram;
  assert.equal(wire[0x03], 0x28, 'accept');
  assert.equal(wire[0x02], 9, 'the sub byte is echoed; FUN_005bfe90 latches it into 0x6cbc80');
  assert.equal(wire.readUInt32BE(0x10), 7,
    'selector 7 -> conn+0x5D4 -> slot 0x23, the slot snap_send_leave installs');
  // The DATA flag must be set: case 6 sends a DATA-clear message to slot 0x24
  // instead, which is a different callback entirely.
  assert.equal((wire.readUInt16BE(0) & 0x1000) !== 0, true, 'DATA set selects conn+0x5D4');
  assert.equal(wire.length, 0x1c);
});

test('a leave from a room the session created closes the room it emptied', () => {
  const rig = harness();
  enter(rig.session, 8);
  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CREATE_ROOM, sequence: 1, payload: createRequest()
  }));
  assert.equal(rig.table.rooms.size, 1);
  rig.session.accept(reliableDatagram({ opcode: LOBBY_OPCODE.AREA_LEAVE, sequence: 2 }));
  // Closed by the transition that removed the last member, not by a sweeper.
  assert.equal(rig.table.rooms.size, 0);
  assert.equal(rig.session.createdRoom, null);
});

/* ---- the op-0x0c collision ----------------------------------------------- */

test('both op-0x0c questions are recognised, each for its own stated reason', () => {
  /*
   * TWO different client requests carry opcode 0x0c and BOTH install at slot
   * 0x26: the connect-screen query (`FUN_005b52e0`, the only exit from connect
   * sub-state 7 step 0) and the create PREPARE (`func_0x001de470` from
   * `FUN_005c3490` step 0, callback `FUN_005c39e0`). V2 answered "any op-0x0c"
   * and satisfied the PREPARE BY ACCIDENT.
   *
   * These two tests fail if either is answered only because the other's handler
   * happened to match: each asserts the purpose the server recorded, which is
   * what proves the recognition is deliberate.
   */
  const rig = harness();
  const connectQuery = rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.ROOM_QUERY, sequence: 0, payload: Buffer.alloc(244)
  }));
  assert.equal(connectQuery.handled[0].purpose, ROOM_QUERY_PURPOSE.CONNECT_SCREEN);
  assert.equal(connectQuery.handled[0].answered, true);

  enter(rig.session, 1, 1);
  const prepare = rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.ROOM_QUERY, sequence: 2, payload: Buffer.alloc(0x40)
  }));
  assert.equal(prepare.handled[0].purpose, ROOM_QUERY_PURPOSE.CREATE_PREPARE);
  assert.equal(prepare.handled[0].answered, true);

  // Both are journalled with the client function each one unblocks, so a rig log
  // says WHICH question was answered rather than "an op-0x0c was".
  const notes = rig.logs
    .filter((entry) => entry.message === 'udp9090 lobby-room-query')
    .map((entry) => entry.fields.note);
  assert.equal(notes.length, 2);
  assert.match(notes[0], /FUN_005b52e0/);
  assert.match(notes[1], /FUN_005c39e0/);
});

test('both op-0x0c answers carry selector 0x0c, because the wire cannot tell them apart', () => {
  /*
   * Stated rather than pretended: NO wire field has been established that
   * separates the two, and both install at the same slot, so the ANSWER is
   * identical and a misclassification costs a log line. Asserting the bytes for
   * both explicitly is the honest form of that.
   */
  const rig = harness();
  const shapes = [
    { payload: Buffer.alloc(244), boxId: null },
    { payload: Buffer.alloc(0x40), boxId: 1 }
  ];
  for (const [index, shape] of shapes.entries()) {
    const fresh = harness();
    if (shape.boxId != null) enter(fresh.session, shape.boxId);
    const before = fresh.sent.length;
    fresh.session.accept(reliableDatagram({
      opcode: LOBBY_OPCODE.ROOM_QUERY, sequence: shape.boxId == null ? 0 : 1, payload: shape.payload
    }));
    const [, reply] = fresh.sent.slice(before);
    assert.equal(reply.datagram[0x03], 0x28, `shape ${index}: an op-0x28 completion`);
    assert.equal(reply.datagram.readUInt32BE(0x10), COMPLETION_SELECTOR.ROOM_QUERY);
    assert.equal(reply.datagram.readUInt32BE(0x14), 0, 'status 0');
  }
  assert.ok(rig.session);
});

/* ---- the request decoder ------------------------------------------------- */

test('the create request is decoded at the offsets func_0x001dc508 builds', () => {
  const decoded = decodeCreateRoomRequest(
    createRequest({ name: 'HALL', maximum: 4, password: 'pw', options: 0x1ffff })
  );
  assert.equal(decoded.name, 'HALL', 'name[16] at +0x00');
  assert.equal(decoded.maximumPlayers, 4, 'BE32 at +0x10 - a ceiling only Likely, not Confirmed');
  assert.equal(decoded.password, 'pw', 'password[16] at +0x14, NOT at +0x12');
  assert.equal(decoded.unknownWord24, 1, '+0x24 is the literal 1 the pump passes; role unknown');
  assert.equal(decoded.optionsWord, 0x1ffff, '+0x28 is a packed options word, not a scenario id');
  assert.equal(decoded.complete, true);
});

test('a truncated create request is decoded to nulls rather than throwing at a peer', () => {
  const decoded = decodeCreateRoomRequest(Buffer.alloc(4));
  assert.equal(decoded.complete, false);
  assert.equal(decoded.maximumPlayers, null);
  assert.equal(decoded.optionsWord, null);
});
