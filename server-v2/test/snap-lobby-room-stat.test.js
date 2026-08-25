import assert from 'node:assert/strict';
import test from 'node:test';

import { TimingWheel } from '../src/transport/timing-wheel.js';
import { createV1ObservedAreaDirectory } from '../src/udp/area-directory.js';
import { LOBBY_OPCODE } from '../src/udp/snap-lobby-codec.js';
import { SnapLobbySessions } from '../src/udp/snap-lobby-sessions.js';

/**
 * SNAP_ROOM_STAT (analysis/op10-gamechannel-blobs-RE-2026-08-24.md Q4).
 *
 * The host publishes its chosen scenario+rules ONCE, in the op-0x04 CREATE
 * body's optionsWord at +0x28 (BE32) - the room STAT attribute. A joiner reads
 * it from the op-0x49 room record at +0x1c and computes scenario id =
 * (STAT>>1)&0xFF. Tonight's create word 0x020b0a10 -> 8 = the exact ring value
 * host memory held (T13b). Without the STAT the record's +0x1c is 0, so every
 * joiner decodes scenario 0 = Training - the rig symptom.
 */

const TOKEN_HOST = 0x02f807d0;
const TOKEN_JOINER = 0x02f907d1;
const OPTIONS_WORD = 0x020b0a10; // tonight's create word; (>>1)&0xFF == 8

function reliableDatagram({ opcode, sequence, sub = 0, payload = Buffer.alloc(0), who = 0xb000, token = TOKEN_HOST }) {
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

function boxKeyOf(boxId) {
  const { records } = createV1ObservedAreaDirectory().records(() => 0);
  return records.find((entry) => entry.name.endsWith(String(boxId).padStart(2, '0'))).key;
}

function harness(sessions = {}) {
  let nowMs = 1_000;
  let intervalToken = null;
  const wheel = new TimingWheel({
    tickMs: 100, clock: () => nowMs,
    setInterval: (fn) => { intervalToken = { fn, unref() {} }; return intervalToken; },
    clearInterval: () => { intervalToken = null; }, onError: () => {}
  });
  wheel.start();
  const table = new SnapLobbySessions({
    wheel, areaDirectory: createV1ObservedAreaDirectory(),
    keepaliveKey: 'SNAP-SWAN', joinLadder: true, ...sessions
  });
  const open = (routingKey, identity, token) => {
    const sent = [];
    const session = table.open({
      routingKey, loginIdentity: identity, endpointToken: token,
      outboundSequence: 1, inboundReceiveBase: 0, latencyTicks: 1600,
      transmit: (datagram, context) => sent.push({ datagram, ...context })
    });
    return { session, sent, token, seq: 0, next() { this.seq += 1; return this.seq - 1; } };
  };
  return { table, open };
}

function enter(client, boxId) {
  const key = Buffer.alloc(4);
  key.writeUInt32BE(boxKeyOf(boxId));
  client.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.AREA_ENTER, sequence: client.next(), payload: key, token: client.token
  }));
}

/** op-0x04 create with an optionsWord at +0x28. */
function createRoom(client, optionsWord) {
  const body = Buffer.alloc(0x2c);
  if (optionsWord != null) body.writeUInt32BE(optionsWord, 0x28);
  client.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CREATE_ROOM, sequence: client.next(), payload: body, token: client.token
  }));
}

function roomListRecordFlags(client) {
  const before = client.sent.length;
  client.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.ROOM_LIST, sequence: client.next(), token: client.token
  }));
  const reply = client.sent.slice(before).find((entry) =>
    entry.datagram.length > 4 && entry.datagram[3] === LOBBY_OPCODE.ROOM_LIST);
  assert.ok(reply, 'a room-list reply left');
  // header 0x10 wire + 0x0c list header, first record at +0x1c; field +0x1c.
  const recordAt = 0x10 + 0x0c;
  return reply.datagram.readUInt32BE(recordAt + 0x1c);
}

test('roomStat OFF (default): the op-0x49 record +0x1c stays 0 (byte-identical, Training)', () => {
  const rig = harness();
  const host = rig.open('192.168.2.248:2000', 'test123', TOKEN_HOST);
  const joiner = rig.open('192.168.2.129:2000', 'real', TOKEN_JOINER);
  enter(host, 1);
  createRoom(host, OPTIONS_WORD);
  enter(joiner, 1);
  assert.equal(roomListRecordFlags(joiner), 0,
    'without the flag the STAT is discarded - the pre-fix behavior, pinned');
});

test('roomStat ON: +0x1c carries the create optionsWord; joiner decodes scenario 8', () => {
  const rig = harness({ roomStat: true });
  const host = rig.open('192.168.2.248:2000', 'test123', TOKEN_HOST);
  const joiner = rig.open('192.168.2.129:2000', 'real', TOKEN_JOINER);
  enter(host, 1);
  createRoom(host, OPTIONS_WORD);
  enter(joiner, 1);
  const stat = roomListRecordFlags(joiner);
  assert.equal(stat, OPTIONS_WORD, 'the STAT word rode the op-0x49 record verbatim');
  assert.equal((stat >>> 1) & 0xff, 8, 'the client computes scenario id 8, not 0/Training');
});

test('roomStat ON but the client sent no optionsWord: +0x1c is 0 (no invention)', () => {
  const rig = harness({ roomStat: true });
  const host = rig.open('192.168.2.248:2000', 'test123', TOKEN_HOST);
  const joiner = rig.open('192.168.2.129:2000', 'real', TOKEN_JOINER);
  enter(host, 1);
  createRoom(host, null);
  enter(joiner, 1);
  assert.equal(roomListRecordFlags(joiner), 0, 'a create with no word publishes no STAT');
});
