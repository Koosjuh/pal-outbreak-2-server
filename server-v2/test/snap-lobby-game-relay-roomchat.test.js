import assert from 'node:assert/strict';
import test from 'node:test';

import { TimingWheel } from '../src/transport/timing-wheel.js';
import { createV1ObservedAreaDirectory } from '../src/udp/area-directory.js';
import {
  COMPLETION_SELECTOR,
  LOBBY_OPCODE,
  buildRoomChatSub7Payload
} from '../src/udp/snap-lobby-codec.js';
import { SnapLobbySessions } from '../src/udp/snap-lobby-sessions.js';

/**
 * The two 2026-08-24 relay fixes (ROOMCHAT-SCENARIO-WIRE / GAME-START-WIRE):
 *
 * `SNAP_GAME_RELAY` - reliable game-channel op-0x0F packets fan out
 * byte-identical to the sender's room, excluding the sender: bioserver
 * `GameServerPacketHandler`'s default branch and openSNAP's game-packet rule,
 * caught live as the joiner starving at "Game to begin shortly" while the
 * in-game host pumped 239 frames the server consumed silently.
 *
 * `SNAP_ROOM_CHAT_SUB7` - room chat re-vehicled as op-0x10 sub-7 fragments
 * (`FUN_005bba20` case 7 -> `FUN_005bc1c0` into `0x6fffd1 + slot*0x114`): the
 * in-room surface does not read the op-0x0F scrollback, which is why room chat
 * was delivered and acked all night and never rendered.
 */

const TOKEN_HOST = 0x02f807d0;
const TOKEN_JOINER = 0x02f907d1;

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
  const record = records.find((entry) => entry.name.endsWith(String(boxId).padStart(2, '0')));
  return record.key;
}

function harness({ sessions = {} } = {}) {
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
    keepaliveKey: 'SNAP-SWAN',
    joinLadder: true,
    ...sessions
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

function enter(client, boxId) {
  const key = Buffer.alloc(4);
  key.writeUInt32BE(boxKeyOf(boxId));
  client.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.AREA_ENTER, sequence: client.next(), payload: key, token: client.token
  }));
}

function createRoom(client) {
  const before = client.sent.length;
  client.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CREATE_ROOM, sequence: client.next(), payload: Buffer.alloc(0x2c),
    token: client.token
  }));
  const accept = client.sent.slice(before).find((entry) =>
    entry.datagram.length >= 0x1c && entry.datagram[3] === LOBBY_OPCODE.COMPLETION &&
    entry.datagram.readUInt32BE(0x10) === COMPLETION_SELECTOR.CREATE_ROOM);
  assert.ok(accept, 'the create accept left');
  return accept.datagram.readUInt32BE(0x14);
}

function roomEnterBody(handle, name = '') {
  const payload = Buffer.alloc(0x18);
  payload.writeUInt32LE(handle, 0x00);
  Buffer.from(name, 'latin1').copy(payload, 0x09);
  return payload;
}

function joinRoom(client, handle) {
  client.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.AREA_ENTER, sequence: client.next(),
    payload: roomEnterBody(handle), who: 0xa000, token: client.token
  }));
}

/** A valid op-0x0F chat body: [screenType][selector 0][nameLen][textLen][0 0] name text. */
function chatBody(text, { screenType = 4, name = 'HOST' } = {}) {
  const nameBuffer = Buffer.from(name, 'latin1');
  const textBuffer = Buffer.from(text, 'latin1');
  return Buffer.concat([
    Buffer.from([screenType, 0x00, nameBuffer.length, textBuffer.length, 0x00, 0x00]),
    nameBuffer, textBuffer
  ]);
}

function roomPair(sessions) {
  const rig = harness({ sessions });
  const host = rig.open('192.168.2.248:2000', 'test123', TOKEN_HOST);
  const joiner = rig.open('192.168.2.129:2000', 'real', TOKEN_JOINER);
  enter(host, 1);
  enter(joiner, 1);
  const handle = createRoom(host);
  joinRoom(joiner, handle);
  return { rig, host, joiner, handle };
}

function framesOf(sent, opcode) {
  return sent.filter((entry) =>
    entry.kind === 'reliable' && entry.datagram.length > 4 && entry.datagram[3] === opcode);
}

/* ---- SNAP_GAME_RELAY ------------------------------------------------------ */

const GAME_PACKET = Buffer.from(
  '280006001400020004140200041422000600140004000200041402000414220006001400', 'hex');

test('gameRelay OFF (default): the reliable game packet is consumed, nothing relayed', () => {
  const { host, joiner } = roomPair();
  const before = joiner.sent.length;
  host.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CHAT, sequence: host.next(), payload: GAME_PACKET,
    who: 0xa000, token: host.token
  }));
  assert.equal(framesOf(joiner.sent.slice(before), LOBBY_OPCODE.CHAT).length, 0,
    'the pre-fix behavior is pinned: consumed at debug, no relay');
});

test('gameRelay ON: byte-identical fan-out to the room, excluding the sender', () => {
  const { host, joiner } = roomPair({ gameRelay: true });
  const beforeJoiner = joiner.sent.length;
  const beforeHost = host.sent.length;
  host.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CHAT, sequence: host.next(), payload: GAME_PACKET,
    who: 0xa000, token: host.token
  }));
  const relayed = framesOf(joiner.sent.slice(beforeJoiner), LOBBY_OPCODE.CHAT);
  assert.equal(relayed.length, 1, 'exactly one relayed frame reached the joiner');
  const frame = relayed[0].datagram;
  // who 0xA0xx: reliable + room channel, the class the sender transmitted and
  // the in-game slot-0x12 GamePacketRUDP callback receives.
  assert.equal(frame[0] & 0xf0, 0xa0, 'room-channel reliable class');
  assert.deepEqual(frame.subarray(0x10, frame.length - 4), GAME_PACKET,
    'the payload is byte-identical - the bioserver dumb-relay contract');
  // The sender got no copy of its own packet (both references forbid it).
  assert.equal(framesOf(host.sent.slice(beforeHost), LOBBY_OPCODE.CHAT).length, 0,
    'never relayed back to the sender - the RS1-A echo failure, not repeated');
});

test('gameRelay ON: a retransmitted packet relays exactly once (window dedup)', () => {
  const { host, joiner } = roomPair({ gameRelay: true });
  const before = joiner.sent.length;
  const sequence = host.next();
  const datagram = reliableDatagram({
    opcode: LOBBY_OPCODE.CHAT, sequence, payload: GAME_PACKET, who: 0xa000, token: host.token
  });
  host.session.accept(datagram);
  host.session.accept(datagram); // the client's 200ms retransmit
  assert.equal(framesOf(joiner.sent.slice(before), LOBBY_OPCODE.CHAT).length, 1,
    'the duplicate was acked, not re-relayed');
});

test('gameRelay ON: a sender in no room relays to nobody', () => {
  const rig = harness({ sessions: { gameRelay: true } });
  const solo = rig.open('192.168.2.248:2000', 'test123', TOKEN_HOST);
  const bystander = rig.open('192.168.2.129:2000', 'real', TOKEN_JOINER);
  enter(solo, 1);
  enter(bystander, 1);
  const before = bystander.sent.length;
  solo.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CHAT, sequence: solo.next(), payload: GAME_PACKET,
    who: 0xa000, token: solo.token
  }));
  assert.equal(framesOf(bystander.sent.slice(before), LOBBY_OPCODE.CHAT).length, 0,
    'game packets are room-scoped; the area is never the audience');
});

/* ---- SNAP_ROOM_CHAT_SUB7 -------------------------------------------------- */

test('roomChatSub7 OFF (default): room chat still relays as op-0x0F 0xA4xx (pinned)', () => {
  const { host, joiner } = roomPair();
  const before = joiner.sent.length;
  host.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CHAT, sequence: host.next(), payload: chatBody('hello'),
    who: 0xa400, token: host.token
  }));
  const relayed = framesOf(joiner.sent.slice(before), LOBBY_OPCODE.CHAT);
  assert.equal(relayed.length, 1);
  assert.equal(relayed[0].datagram[0] & 0xf4, 0xa4, 'the pre-fix 0xA4xx room relay, pinned');
});

test('roomChatSub7 ON: room chat re-vehicles as an op-0x10 sub-7 fragment, byte-exact', () => {
  const { host, joiner } = roomPair({ roomChatSub7: true });
  const before = joiner.sent.length;
  host.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CHAT, sequence: host.next(), payload: chatBody('hello'),
    who: 0xa400, token: host.token
  }));
  assert.equal(framesOf(joiner.sent.slice(before), LOBBY_OPCODE.CHAT).length, 0,
    'no op-0x0F copy - the in-room surface does not read the scrollback');
  const pushes = framesOf(joiner.sent.slice(before), LOBBY_OPCODE.ROOM_STATE);
  assert.equal(pushes.length, 1, 'one op-0x10 push reached the joiner');
  const payload = pushes[0].datagram.subarray(0x10, pushes[0].datagram.length - 4);
  // The whole payload, byte for byte: header word 1, sub 7, slot 0 (host =
  // playernum 1), length, offset 0, then the text at app+8.
  assert.deepEqual(payload, buildRoomChatSub7Payload({
    slot: 0, text: Buffer.from('hello', 'latin1')
  }));
  assert.equal(payload[0x08], 0x07, 'sub-event 7 -> FUN_005bc1c0');
  assert.equal(payload[0x0c], 0, 'host slot = playernum 1 - 1');
  assert.equal(payload[0x0d], 5, 'fragment length');
  assert.equal(payload.subarray(0x10).toString('latin1'), 'hello');
});

test('roomChatSub7 ON: the joiner\'s line arrives at the host with slot 1', () => {
  const { host, joiner } = roomPair({ roomChatSub7: true });
  const before = host.sent.length;
  joiner.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CHAT, sequence: joiner.next(), payload: chatBody('yo', { name: 'REAL' }),
    who: 0xa400, token: joiner.token
  }));
  const pushes = framesOf(host.sent.slice(before), LOBBY_OPCODE.ROOM_STATE);
  assert.equal(pushes.length, 1);
  const payload = pushes[0].datagram.subarray(0x10, pushes[0].datagram.length - 4);
  assert.equal(payload[0x0c], 1, 'joiner slot = playernum 2 - 1');
  assert.equal(payload.subarray(0x10).toString('latin1'), 'yo');
});

test('roomChatSub7 ON: AREA chat is untouched - byte-identical op-0x0F 0xB4xx', () => {
  const on = harness({ sessions: { roomChatSub7: true } });
  const off = harness();
  for (const rig of [on, off]) {
    const talker = rig.open('192.168.2.248:2000', 'test123', TOKEN_HOST);
    const listener = rig.open('192.168.2.129:2000', 'real', TOKEN_JOINER);
    enter(talker, 1);
    enter(listener, 1);
    rig.talker = talker; rig.listener = listener;
    talker.session.accept(reliableDatagram({
      opcode: LOBBY_OPCODE.CHAT, sequence: talker.next(), payload: chatBody('lobby line'),
      who: 0xb400, token: talker.token
    }));
  }
  assert.deepEqual(
    framesOf(on.listener.sent, LOBBY_OPCODE.CHAT).map((entry) => entry.datagram),
    framesOf(off.listener.sent, LOBBY_OPCODE.CHAT).map((entry) => entry.datagram),
    'the working lobby-chat surface is byte-identical under the flag');
});
