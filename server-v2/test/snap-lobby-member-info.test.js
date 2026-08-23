import assert from 'node:assert/strict';
import test from 'node:test';

import { TimingWheel } from '../src/transport/timing-wheel.js';
import { createV1ObservedAreaDirectory } from '../src/udp/area-directory.js';
import {
  LOBBY_OPCODE,
  PLAYER_INFO_PAYLOAD_BYTES,
  buildPlayerInfoPayload,
  buildRosterRecordPayload
} from '../src/udp/snap-lobby-codec.js';
import { SnapLobbySessions } from '../src/udp/snap-lobby-sessions.js';

/**
 * THE MEMBER-INFO SUPPLY CHANNEL (RS1-B fix 2, flag SNAP_MEMBER_INFO) - the
 * three emissions V1's July golden set ran and V2 lacked (RS1-B §4):
 *
 *   op-0x0c room query  -> sel-0x0c completion PLUS an op-28 sel-0x0a roster
 *                          record (July pkts 499+500);
 *   op-0x06 join accept -> PLUS an op-0x10 sub-1 player-info push, role 0
 *                          (July pkts 503-505);
 *   ANY game-channel op-0x10 -> answered with the sub-1 push, every time
 *                          (July pkts 547-553; the client re-sends its op-10
 *                          until satisfied - tonight's host retransmit).
 *
 * The RS1 starvations - the joiner's "Getting information", the host's
 * self-close in its own room - sit exactly on this gap.
 */

const TOKEN_A = 0x02f807d0;
const TOKEN_B = 0x02f907d1;

function reliableDatagram({ opcode, sequence, sub = 0, payload = Buffer.alloc(0), who = 0xa000, token = TOKEN_A }) {
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
  let intervalToken = null;
  const wheel = new TimingWheel({
    tickMs: 100,
    clock: () => 1_000,
    setInterval: (fn) => { intervalToken = { fn, unref() {} }; return intervalToken; },
    clearInterval: () => { intervalToken = null; },
    onError: () => {}
  });
  wheel.start();
  const table = new SnapLobbySessions({
    wheel,
    areaDirectory: createV1ObservedAreaDirectory(),
    keepaliveKey: 'SNAP-SWAN',
    memberInfo: true,
    joinLadder: true,
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
    return { session, sent, token, seq: 0, next() { this.seq += 1; return this.seq - 1; } };
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

function repliesIn(sent, opcode) {
  return sent.filter((entry) =>
    (entry.kind === 'reliable' || entry.kind === 'mirrored') &&
    entry.datagram.length > 4 && entry.datagram[3] === opcode);
}

/** A sub-1 player-info frame: op-0x10, DATA clear, 0x304-byte body, sub 1. */
function playerInfoIn(sent) {
  return repliesIn(sent, LOBBY_OPCODE.ROOM_STATE).filter((entry) =>
    entry.datagram.length === 0x10 + PLAYER_INFO_PAYLOAD_BYTES + 4 &&
    entry.datagram[0x18] === 0x01);
}

/* ---- the codec, against the July bytes ----------------------------------- */

test('the sub-1 payload is the July a3-frame body: 0x304 bytes, word0=1, sub 1, role byte', () => {
  const joiner = buildPlayerInfoPayload({ role: 0 });
  assert.equal(joiner.length, 0x304, 'inner length 0x314 = the July a314 frames');
  assert.equal(joiner.readUInt32BE(0), 1, 'header word 1 (wire +0x10)');
  assert.equal(joiner[0x08], 0x01, 'sub-selector 1 (wire +0x18)');
  assert.equal(joiner[0x10], 0, 'role byte 0 = joiner (July pkt 534, wire +0x20)');
  assert.ok(joiner.subarray(0x11).every((byte) => byte === 0), 'blob zeros, as captured');

  const host = buildPlayerInfoPayload({ role: 1 });
  assert.equal(host[0x10], 1, 'role byte 1 = host/creator (July pkt 505)');
});

test('the roster record is the July pkt-500 body: sel 0x0a BE, count LE, id BE, stride LE 0x108', () => {
  const payload = buildRosterRecordPayload({ members: [{ name: 'PLAYER1', memberId: 1 }] });
  assert.equal(payload.length, 0x114, 'inner length 0x124 = the July b124 frame');
  // July pkt 500 body, byte for byte (charstats zeros elided by construction):
  assert.equal(payload.readUInt32BE(0x00), 0x0000000a, 'selector 0x0a BE');
  assert.equal(payload.readUInt32LE(0x08), 1, 'count 1, LITTLE-endian - the proven order');
  assert.deepEqual(payload.subarray(0x0c, 0x13), Buffer.from('PLAYER1', 'latin1'));
  assert.equal(payload.readUInt32BE(0x1c), 1, 'member id BE at entry+0x10');
  assert.equal(payload.readUInt32LE(0x20), 0x108, 'stride 0x108 LE at entry+0x14');
  assert.ok(payload.subarray(0x24).every((byte) => byte === 0), '0xf0 data blob zero');
});

/* ---- op-0x0c: completion + roster record --------------------------------- */

test('an op-0x0c is answered with the sel-0x0c completion PLUS the sel-0x0a roster record', () => {
  const rig = harness();
  const alice = rig.open('192.0.2.248:2000', 'test123', TOKEN_A);
  enter(alice, 3);
  const before = alice.sent.length;

  const [outcome] = alice.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.ROOM_QUERY, sub: 1, sequence: alice.next(),
    payload: Buffer.alloc(240), token: TOKEN_A
  })).handled;
  assert.equal(outcome.answered, true);

  const completions = repliesIn(alice.sent.slice(before), LOBBY_OPCODE.COMPLETION);
  assert.equal(completions.length, 2, 'the completion AND the roster record, July pkts 499+500');
  const [completion, roster] = completions;
  assert.equal(completion.datagram.readUInt32BE(0x10), 0x0c, 'sel-0x0c first');
  assert.equal(completion.datagram[2], 1, 'completion sub echoes the request generation');
  // The record, July shape: who 0xB1 (DATA set, len 0x124), sub 0, sel 0x0a.
  assert.equal(roster.datagram.readUInt16BE(0), 0xb124, 'who|len: the July b124 frame word');
  assert.equal(roster.datagram[2], 0, 'sub 0 on the record - the July wire byte');
  assert.equal(roster.datagram.readUInt32BE(0x10), 0x0a, 'selector 0x0a');
});

test('outside a room the record is V1\'s synthetic PLAYER1; inside, the live roster with join-order ids', () => {
  const rig = harness();
  const alice = rig.open('192.0.2.248:2000', 'test123', TOKEN_A);
  enter(alice, 3);
  const beforeOutside = alice.sent.length;
  alice.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.ROOM_QUERY, sub: 1, sequence: alice.next(),
    payload: Buffer.alloc(240), token: TOKEN_A
  }));
  const [, outsideRecord] = repliesIn(alice.sent.slice(beforeOutside), LOBBY_OPCODE.COMPLETION);
  assert.deepEqual(
    outsideRecord.datagram.subarray(0x1c, 0x23), Buffer.from('PLAYER1', 'latin1'),
    'the record V1 answered every pre-room op-0x0c with, for months of rig runs'
  );

  rig.table.rooms.openFor({
    presence: rig.table.presence, host: alice.session.presence, boxId: 3, name: 'ROOM', max: 4
  });
  const beforeInside = alice.sent.length;
  alice.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.ROOM_QUERY, sub: 2, sequence: alice.next(),
    payload: Buffer.alloc(240), token: TOKEN_A
  }));
  const [, insideRecord] = repliesIn(alice.sent.slice(beforeInside), LOBBY_OPCODE.COMPLETION);
  assert.deepEqual(
    insideRecord.datagram.subarray(0x1c, 0x23), Buffer.from('test123', 'latin1'),
    'in a room the record carries the LIVE roster'
  );
  assert.equal(insideRecord.datagram.readUInt32BE(0x2c), 1,
    'member id = 1-based join order, never presenceId (the RS1 collision hazard)');
});

/* ---- op-0x06 join acceptance: the sub-1 push ----------------------------- */

test('a join acceptance is followed by the sub-1 player-info push, role 0', () => {
  const rig = harness();
  const host = rig.open('192.0.2.248:2000', 'hostA', TOKEN_A);
  const joiner = rig.open('192.0.2.129:2000', 'joinerB', TOKEN_B);
  enter(host, 5);
  enter(joiner, 5);
  // Through the CREATE handler, so the engine records exist and the join guards pass.
  host.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CREATE_ROOM, sequence: host.next(), payload: Buffer.alloc(0x2c),
    who: 0xb000, token: TOKEN_A
  }));
  const room = host.session.createdRoom;
  const before = joiner.sent.length;

  // The room-ENTER join form: inner 0x28, LE handle at body +0x00.
  const enterBody = Buffer.alloc(0x18);
  enterBody.writeUInt32LE(room.handle, 0);
  const [outcome] = joiner.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.AREA_ENTER, sequence: joiner.next(), payload: enterBody,
    who: 0xa000, token: TOKEN_B
  })).handled;
  assert.equal(outcome.joined, true);

  const pushes = playerInfoIn(joiner.sent.slice(before));
  assert.equal(pushes.length, 1, 'exactly one sub-1 push rides the acceptance (July pkt 505)');
  const [push] = pushes;
  assert.equal(push.datagram.readUInt16BE(0), 0xa314,
    'who 0xA0 | inner 0x314: DATA and 0x0400 clear - the slot-0x13 routing, the July a314 word');
  assert.equal(push.datagram[0x20], 0, 'role byte 0: this session is a JOINER');
});

/* ---- every inbound game-channel op-0x10 is answered ---------------------- */

/** RS1 17:39:18.059: the host's sub-1 body, byte for byte (word1 = its own handle 3). */
const RS1_HOST_OP10_BODY = Buffer.from(
  '00000001' + '00000003' + '01000000' + '00000000' + '00000000', 'hex');

test('RS1 replay: the host\'s unanswered op-0x10 now gets the sub-1 answer, role 1', () => {
  const rig = harness();
  const host = rig.open('192.0.2.248:2000', 'test123', TOKEN_A);
  enter(host, 5);
  host.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CREATE_ROOM, sequence: host.next(), payload: Buffer.alloc(0x2c),
    who: 0xb000, token: TOKEN_A
  }));
  const before = host.sent.length;

  const [outcome] = host.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.ROOM_STATE, sequence: host.next(), payload: RS1_HOST_OP10_BODY,
    who: 0xe000, token: TOKEN_A
  })).handled;

  assert.equal(outcome.answered, true,
    'tonight this exact frame got a transport ack and NO application answer; the client ' +
    're-sent it 40 ms later (RS1-B §2) - V1 answered every one');
  const pushes = playerInfoIn(host.sent.slice(before));
  assert.equal(pushes.length, 1);
  assert.equal(pushes[0].datagram[0x20], 1, 'role 1: the sender created the room it is in');
});

test('the join-request sub-2 keeps its rig-proven sub-0x0C confirm, not the sub-1 answer', () => {
  const rig = harness();
  const host = rig.open('192.0.2.248:2000', 'hostA', TOKEN_A);
  enter(host, 5);
  rig.table.rooms.openFor({
    presence: rig.table.presence, host: host.session.presence, boxId: 5, name: 'ROOM', max: 4
  });
  const before = host.sent.length;

  const joinRequest = Buffer.from('00000001' + '02f807d0' + '02000000', 'hex');
  const [outcome] = host.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.ROOM_STATE, sequence: host.next(), payload: joinRequest,
    who: 0xe000, token: TOKEN_A
  })).handled;

  assert.equal(outcome.joinConfirm, true, 'SNAP_JOIN_LADDER owns sub-2');
  assert.equal(playerInfoIn(host.sent.slice(before)).length, 0,
    'no competing sub-1 answer on the sub-2 exchange (the deployed V1 fix answered 0x0C alone)');
});

test('flag OFF: no roster record, no sub-1 pushes - byte-identical to the RS1 build', () => {
  const rig = harness({ memberInfo: false, joinLadder: false, op10Relay: false });
  const alice = rig.open('192.0.2.248:2000', 'test123', TOKEN_A);
  enter(alice, 3);
  const before = alice.sent.length;

  alice.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.ROOM_QUERY, sub: 1, sequence: alice.next(),
    payload: Buffer.alloc(240), token: TOKEN_A
  }));
  const completions = repliesIn(alice.sent.slice(before), LOBBY_OPCODE.COMPLETION);
  assert.equal(completions.length, 1, 'the completion alone - the previous build');

  const beforeOp10 = alice.sent.length;
  const [outcome] = alice.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.ROOM_STATE, sequence: alice.next(), payload: RS1_HOST_OP10_BODY,
    who: 0xe000, token: TOKEN_A
  })).handled;
  assert.equal(outcome.answered, false, 'unhandled, as before');
  assert.equal(playerInfoIn(alice.sent.slice(beforeOp10)).length, 0);
});
