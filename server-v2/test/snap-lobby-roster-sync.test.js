import assert from 'node:assert/strict';
import test from 'node:test';

import { TimingWheel } from '../src/transport/timing-wheel.js';
import { createV1ObservedAreaDirectory } from '../src/udp/area-directory.js';
import {
  AREA_COUNT_TAG_CURRENT,
  AREA_COUNT_TAG_MAXIMUM,
  LOBBY_OPCODE,
  MEMBER_RECORD_BYTES,
  NAMED_CHANNEL_SELECTOR,
  NAMED_CHANNEL_TAG_STAT
} from '../src/udp/snap-lobby-codec.js';
import { SnapLobbySessions } from '../src/udp/snap-lobby-sessions.js';

/**
 * THE ROSTER-SYNC PATH: the three one-shot queries that follow a create accept.
 *
 * The T35 rig run stalled on "Getting information / Please wait for a moment"
 * after a successful create. The cause was not a missing handler for one opcode -
 * the client batches op-0x0a + op-0x09("USER") + op-0x09("MAXI") into ONE datagram
 * and none of the three had an answer. They have no client-side retry and no
 * timeout (`FUN_005fe500` fires them once and parks), so ANY unanswered one is a
 * permanent hang. That is why these are tested together as a path and not one at
 * a time.
 *
 * Two rules here are load-bearing and neither is guessable from the reply shape:
 *  - op-0x0a must be answered DIRECT on opcode 0x0a with `sub = 0`. Through
 *    op-0x28 the selector word shifts every field; with a non-zero sub
 *    `FUN_005c0ae0` returns WITHOUT completing the task.
 *  - op-0x08 must be answered with op-0x28 SELECTOR 8, the only route to reply
 *    slot 0x25.
 */

const TOKEN = 0x02f807d0;
const ROUTING_KEY = '192.0.2.248:2000';

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

/** One datagram carrying several messages, with 0x0800 on the first - as the client sends. */
function batchedDatagram(messages) {
  const parts = messages.map(({ opcode, sequence, sub = 0, payload = Buffer.alloc(0) }, index) => {
    const inner = 0x10 + payload.length;
    const part = Buffer.alloc(inner);
    // 0x0800 = MORE_MESSAGES on the FIRST message only; that is the client's own
    // rule (`FUN_001d6988.c:44`) and what our walk gates on.
    part.writeUInt16BE(0xb000 | (index === 0 ? 0x0800 : 0) | inner, 0);
    part.writeUInt8(sub, 2);
    part.writeUInt8(opcode, 3);
    part.writeUInt32BE(TOKEN, 4);
    part.writeUInt32BE(sequence, 8);
    payload.copy(part, 0x10);
    return part;
  });
  return Buffer.concat([...parts, Buffer.from([0xba, 0x47, 0x66, 0x11])]);
}

function harness({ identity = '12345' } = {}) {
  let nowMs = 1_000;
  let intervalToken = null;
  const wheel = new TimingWheel({
    tickMs: 100,
    clock: () => nowMs,
    setInterval: (fn) => { intervalToken = { fn, unref() {} }; return intervalToken; },
    clearInterval: () => { intervalToken = null; },
    onError: () => {}
  });
  wheel.start();
  const table = new SnapLobbySessions({
    wheel,
    areaDirectory: createV1ObservedAreaDirectory(),
    keepaliveKey: 'SNAP-SWAN'
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
  return { wheel, table, session, sent };
}

function enter(session, boxKey, sequence = 0) {
  const key = Buffer.alloc(4);
  key.writeUInt32BE(boxKey);
  session.accept(reliableDatagram({ opcode: LOBBY_OPCODE.AREA_ENTER, sequence, payload: key }));
}

/** Create a room and return the 4 handle bytes exactly as the client received them. */
function createRoom(session, sequence = 1) {
  const request = Buffer.alloc(0x2c);
  request.writeUInt32BE(4, 0x10);
  request.writeUInt32BE(1, 0x24);
  const [outcome] = session.accept(
    reliableDatagram({ opcode: LOBBY_OPCODE.CREATE_ROOM, sequence, payload: request })
  ).handled;
  const handleBytes = Buffer.alloc(4);
  handleBytes.writeUInt32BE(outcome.handle ?? 1);
  return handleBytes;
}

function repliesOf(sent, opcode) {
  return sent.filter((entry) => entry.datagram.length > 4 && entry.datagram.readUInt8(3) === opcode);
}

/* ---- the batch: the actual milestone ------------------------------------ */

test('all three post-create queries in ONE datagram are answered', () => {
  /*
   * THE REGRESSION, end to end. 20 + 24 + 24 = 68 bytes in one datagram; the T35
   * journal answered the first 20 and reported "48 trailing bytes". Answering one
   * of three still hangs, so this asserts all three replies leave.
   */
  const rig = harness();
  enter(rig.session, 5);
  const handleBytes = createRoom(rig.session);
  const before = rig.sent.length;

  const memberList = handleBytes;
  const userQuery = Buffer.concat([handleBytes, AREA_COUNT_TAG_CURRENT]);
  const maxiQuery = Buffer.concat([handleBytes, AREA_COUNT_TAG_MAXIMUM]);
  const result = rig.session.accept(batchedDatagram([
    { opcode: LOBBY_OPCODE.MEMBER_LIST, sequence: 2, payload: memberList },
    { opcode: LOBBY_OPCODE.AREA_COUNT_QUERY, sequence: 3, payload: userQuery },
    { opcode: LOBBY_OPCODE.AREA_COUNT_QUERY, sequence: 4, payload: maxiQuery }
  ]));

  assert.equal(result.handled.length, 3, 'every message in the batch reached a handler');
  assert.ok(result.handled.every((outcome) => outcome.answered), 'and every one was answered');

  const after = rig.sent.slice(before);
  assert.equal(repliesOf(after, LOBBY_OPCODE.MEMBER_LIST).length, 1, 'one op-0x0a reply');
  assert.equal(repliesOf(after, LOBBY_OPCODE.AREA_COUNT_QUERY).length, 2, 'two op-0x09 replies');
});

/* ---- op-0x0a ------------------------------------------------------------- */

test('op-0x0a is answered DIRECT on opcode 0x0a with sub 0, never through op-0x28', () => {
  const rig = harness();
  enter(rig.session, 5);
  const handleBytes = createRoom(rig.session);
  const before = rig.sent.length;

  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.MEMBER_LIST, sequence: 2, sub: 0, payload: handleBytes
  }));
  const [reply] = repliesOf(rig.sent.slice(before), LOBBY_OPCODE.MEMBER_LIST);
  assert.ok(reply != null, 'the reply rides opcode 0x0a itself');
  /*
   * `sub = 0` is not a default, it is the completion condition. `FUN_001de0c0`
   * returns a literal 0 as the task match key, and `FUN_005c0ae0` returns without
   * completing when 0x2000 is clear and the sub is non-zero - a silent hang.
   */
  assert.equal(reply.datagram.readUInt8(2), 0, 'sub MUST be 0 or the task never completes');
  assert.equal(
    repliesOf(rig.sent.slice(before), LOBBY_OPCODE.COMPLETION).length, 0,
    'no op-0x28: through that route the selector word shifts every field'
  );
});

test('the op-0x0a reply echoes the handle bytes verbatim and carries one record per member', () => {
  const rig = harness();
  enter(rig.session, 5);
  const handleBytes = createRoom(rig.session);
  const before = rig.sent.length;

  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.MEMBER_LIST, sequence: 2, payload: handleBytes
  }));
  const [reply] = repliesOf(rig.sent.slice(before), LOBBY_OPCODE.MEMBER_LIST);
  const body = reply.datagram.subarray(0x10, reply.datagram.length - 4);

  assert.deepEqual(body.subarray(0, 4), handleBytes, 'the handle is echoed, never re-encoded');
  assert.equal(body.readUInt32BE(0x08), 1, 'the host is one member');
  assert.equal(body.length, 0x0c + MEMBER_RECORD_BYTES, 'header + exactly one 0x108 record');
  // The declared blob length IS the stride input: (0xF0 + 0x1B) & ~3 = 0x108.
  // A different value here silently re-strides every following record.
  assert.equal(body.readUInt32BE(0x0c + 0x14), 0xf0, 'the per-record length that yields stride 0x108');
  assert.notEqual(body[0x0c], 0, 'the name is non-empty: an empty name draws a blank row');
});

test('a handle we do not hold is still ANSWERED, with zero records', () => {
  // Silence is worse than an empty answer everywhere on this path: the client has
  // no retry and no timeout, so an unanswered query is a permanent hang.
  const rig = harness();
  enter(rig.session, 5);
  const before = rig.sent.length;
  const bogus = Buffer.from('deadbeef', 'hex');

  const [outcome] = rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.MEMBER_LIST, sequence: 1, payload: bogus
  })).handled;
  assert.equal(outcome.answered, true);
  const [reply] = repliesOf(rig.sent.slice(before), LOBBY_OPCODE.MEMBER_LIST);
  const body = reply.datagram.subarray(0x10, reply.datagram.length - 4);
  assert.deepEqual(body.subarray(0, 4), bogus, 'even the unresolved handle is echoed back');
  assert.equal(body.readUInt32BE(0x08), 0, 'zero records');
});

test('the handle resolves in EITHER byte order, because the round trip is opaque', () => {
  /*
   * The client stores the four bytes we put at op-0x28 sel-4 body +0x04 and sends
   * them straight back, so the server must not re-encode. The one captured sample
   * reads the reverse of what we mint, from a console that had not created a room
   * in that window - attribution is Inference. Accepting both removes an
   * endianness bet from the critical path.
   */
  const rig = harness();
  enter(rig.session, 5);
  const handleBytes = createRoom(rig.session);
  const reversed = Buffer.from(handleBytes).reverse();
  const before = rig.sent.length;

  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.MEMBER_LIST, sequence: 2, payload: reversed
  }));
  const [reply] = repliesOf(rig.sent.slice(before), LOBBY_OPCODE.MEMBER_LIST);
  const body = reply.datagram.subarray(0x10, reply.datagram.length - 4);
  assert.equal(body.readUInt32BE(0x08), 1, 'the room resolved from the reversed bytes');
  assert.deepEqual(body.subarray(0, 4), reversed, 'and the reply echoes what was SENT, not what we hold');
});

/* ---- op-0x09 ------------------------------------------------------------- */

test('USER is the live member count and MAXI is the room capacity, both derived', () => {
  const rig = harness();
  enter(rig.session, 5);
  const handleBytes = createRoom(rig.session);

  // enter used 0 and create used 1, so the next in-order sequence is 2.
  let sequence = 1;
  const ask = (tag) => {
    const before = rig.sent.length;
    rig.session.accept(reliableDatagram({
      opcode: LOBBY_OPCODE.AREA_COUNT_QUERY,
      // Distinct per call: a repeated sequence is a DUPLICATE and is not re-delivered.
      sequence: sequence += 1,
      payload: Buffer.concat([handleBytes, tag])
    }));
    const [reply] = repliesOf(rig.sent.slice(before), LOBBY_OPCODE.AREA_COUNT_QUERY);
    const body = reply.datagram.subarray(0x10, reply.datagram.length - 4);
    assert.deepEqual(body.subarray(0, 4), handleBytes, 'handle echoed, or the value is discarded');
    assert.deepEqual(body.subarray(4, 8), tag, 'tag echoed');
    return body.readUInt32BE(0x08);
  };

  assert.equal(ask(AREA_COUNT_TAG_CURRENT), 1, 'the host is present, so USER is 1 - never 0');
  assert.equal(ask(AREA_COUNT_TAG_MAXIMUM), 4, 'MAXI is the room capacity');
});

test('an unrecognised op-0x09 tag is still answered, because refusing would hang the screen', () => {
  // FUN_005c0060 stores nothing for an unknown tag but STILL completes the task,
  // so a wrong tag is a wrong number; no reply at all is a permanent stall.
  const rig = harness();
  enter(rig.session, 5);
  const handleBytes = createRoom(rig.session);
  const before = rig.sent.length;

  const [outcome] = rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.AREA_COUNT_QUERY,
    sequence: 2,
    payload: Buffer.concat([handleBytes, Buffer.from('ZZZZ', 'latin1')])
  })).handled;
  assert.equal(outcome.answered, true);
  assert.equal(repliesOf(rig.sent.slice(before), LOBBY_OPCODE.AREA_COUNT_QUERY).length, 1);
});

/* ---- op-0x08 ------------------------------------------------------------- */

test('op-0x08 STAT is answered with op-0x28 selector 8 - the only route to slot 0x25', () => {
  /*
   * NOT the exit button; that is op-0x07 and is handled elsewhere. This one is
   * answered because its reply is the ONLY exit from the roster SM's single
   * unbounded wait, so silence here is a permanent hang rather than a slow path.
   */
  const rig = harness();
  enter(rig.session, 5);
  const before = rig.sent.length;

  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.NAMED_CHANNEL_QUERY,
    sequence: 1,
    sub: 7,
    payload: Buffer.concat([NAMED_CHANNEL_TAG_STAT, Buffer.alloc(4)])
  }));
  const [reply] = repliesOf(rig.sent.slice(before), LOBBY_OPCODE.COMPLETION);
  assert.ok(reply != null, 'answered on op-0x28, not on 0x08');
  assert.equal(reply.datagram.readUInt8(2), 7, 'the sub byte is echoed: it is the task match key');

  const body = reply.datagram.subarray(0x10, reply.datagram.length - 4);
  assert.equal(body.readUInt32BE(0x00), NAMED_CHANNEL_SELECTOR, 'selector 8 reaches conn+0x5DC');
  assert.deepEqual(body.subarray(0x08, 0x0c), NAMED_CHANNEL_TAG_STAT, 'the tag is echoed at +0x08');
});

test('op-0x08 is answered even for a tag we do not recognise', () => {
  const rig = harness();
  enter(rig.session, 5);
  const before = rig.sent.length;
  const [outcome] = rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.NAMED_CHANNEL_QUERY,
    sequence: 1,
    payload: Buffer.concat([Buffer.from('WXYZ', 'latin1'), Buffer.alloc(4)])
  })).handled;
  assert.equal(outcome.answered, true);
  assert.equal(repliesOf(rig.sent.slice(before), LOBBY_OPCODE.COMPLETION).length, 1);
});
