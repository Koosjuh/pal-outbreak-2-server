import assert from 'node:assert/strict';
import test from 'node:test';

import { TimingWheel } from '../src/transport/timing-wheel.js';
import { createV1ObservedAreaDirectory } from '../src/udp/area-directory.js';
import { LOBBY_OPCODE } from '../src/udp/snap-lobby-codec.js';
import { SnapLobbySessions } from '../src/udp/snap-lobby-sessions.js';

/**
 * SNAP_OP10_DROP_SELF (analysis/solo-start-refuse-RE-2026-08-26.md, wire-confirmed).
 *
 * On a 2-player start the host's roster SM (FUN_005c6500) loops EVERY seated slot
 * INCLUDING its own seat0 and emits one op-0x10 sub-3 per seat, bundled in one
 * 0x0800-multi datagram. Live wire (attempt 3): the host (PS2, token 0x028107d0)
 * sent TWO sub-3 - word0=0x028107d0 (its OWN token = self) and word0=0x02 (the
 * joiner's seat id). The op10Relay fanned BOTH to the joiner; the joiner ACCEPTed
 * the first (screen 4/0xe), that advanced its screen, and the SECOND sub-3 fell to
 * the REFUSE branch -> accept count never held at 2 -> solo start.
 *
 * The fix drops the self-targeted frame (word0 == the sender's own endpointToken)
 * from the peer fan-out, so the joiner receives exactly one sub-3.
 */

const TOKEN_HOST = 0x028107d0;   // PS2 = the host in the wire-confirmed attempt 3
const TOKEN_JOINER = 0x02f807d0; // PC = the joiner
const JOINER_SEAT_ID = 0x02;     // word0 the host aims at the joiner's seat (wire)

function reliableDatagram({ opcode, sequence, payload = Buffer.alloc(0), who = 0xa000, token }) {
  const inner = 0x10 + payload.length;
  const datagram = Buffer.alloc(inner + 4);
  datagram.writeUInt16BE(who | inner, 0);
  datagram.writeUInt8(opcode, 3);
  datagram.writeUInt32BE(token, 4);
  datagram.writeUInt32BE(sequence, 8);
  payload.copy(datagram, 0x10);
  Buffer.from([0xba, 0x47, 0x66, 0x11]).copy(datagram, inner);
  return datagram;
}

/** op-0x10 room-event body: [BE32 count=1][BE32 word0][u8 sub @ +0x08]. */
function roomEventBody(word0, sub) {
  const b = Buffer.alloc(12);
  b.writeUInt32BE(1, 0);
  b.writeUInt32BE(word0 >>> 0, 4);
  b[8] = sub;
  return b;
}

function boxKeyOf(boxId) {
  const { records } = createV1ObservedAreaDirectory().records(() => 0);
  return records.find((entry) => entry.name.endsWith(String(boxId).padStart(2, '0'))).key;
}

function harness(extra = {}) {
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
    keepaliveKey: 'SNAP-SWAN', joinLadder: true, op10Relay: true, memberInfo: true,
    memberIdToken: true, hostReseat: true, rosterToJoiner: true, ...extra
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
  const key = Buffer.alloc(4); key.writeUInt32BE(boxKeyOf(boxId));
  client.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.AREA_ENTER, sequence: client.next(), payload: key, token: client.token
  }));
}
function createRoom(client) {
  client.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CREATE_ROOM, sequence: client.next(), payload: Buffer.alloc(0x2c), token: client.token
  }));
}
function joinRoom(client, handle = 1) {
  const body = Buffer.alloc(0x18); body.writeUInt32LE(handle, 0x00);
  client.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.AREA_ENTER, sequence: client.next(), payload: body, who: 0xa000, token: client.token
  }));
}
function setup(extra) {
  const rig = harness(extra);
  const host = rig.open('192.168.2.129:2000', 'real', TOKEN_HOST);
  const joiner = rig.open('192.168.2.248:2000', 'test123', TOKEN_JOINER);
  enter(host, 1); createRoom(host); enter(joiner, 1); joinRoom(joiner, 1);
  return { rig, host, joiner };
}
/** Count op-0x10 sub-3 ROOM_STATE frames the joiner received as room-event relays. */
function joinerRelayedSub3(joiner, since) {
  return joiner.sent.slice(since).filter((e) =>
    e.datagram[3] === LOBBY_OPCODE.ROOM_STATE &&
    e.datagram.length >= 0x1c &&
    e.datagram.readUInt32BE(0x10) === 1 &&       // count word
    e.datagram[0x18] === 3);                      // sub byte
}

function hostSendsBothSub3(host) {
  // self-targeted (word0 == host token) then joiner-targeted (word0 == 0x02)
  host.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.ROOM_STATE, sequence: host.next(),
    payload: roomEventBody(TOKEN_HOST, 3), who: 0xa000, token: host.token
  }));
  host.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.ROOM_STATE, sequence: host.next(),
    payload: roomEventBody(JOINER_SEAT_ID, 3), who: 0xa000, token: host.token
  }));
}

test('OFF (default): the joiner receives BOTH sub-3 (the accept-then-refuse cause)', () => {
  const { host, joiner } = setup({ op10DropSelf: false });
  const at = joiner.sent.length;
  hostSendsBothSub3(host);
  assert.equal(joinerRelayedSub3(joiner, at).length, 2,
    'pre-fix: both the self-targeted and joiner-targeted sub-3 are fanned to the joiner');
});

test('ON: the self-targeted sub-3 (word0 == host token) is dropped; joiner gets exactly one', () => {
  const { host, joiner } = setup({ op10DropSelf: true });
  const at = joiner.sent.length;
  hostSendsBothSub3(host);
  const got = joinerRelayedSub3(joiner, at);
  assert.equal(got.length, 1, 'the joiner receives exactly one sub-3 -> it ACCEPTs and never refuses');
  assert.equal(got[0].datagram.readUInt32BE(0x14), JOINER_SEAT_ID,
    'the surviving frame is the joiner-targeted one (word0 == 0x02), not the host self-frame');
});

test('ON: a self-targeted NON-start sub (sub-1 member-info) is NOT dropped (nora gap 1)', () => {
  const { host, joiner } = setup({ op10DropSelf: true });
  const at = joiner.sent.length;
  // A host op-0x10 sub-1 whose word0 also == the host token: only the START
  // sub-family (3/5/6/7/9) loops seats, so this must still relay to the joiner.
  host.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.ROOM_STATE, sequence: host.next(),
    payload: roomEventBody(TOKEN_HOST, 1), who: 0xa000, token: host.token
  }));
  const relayedSub1 = joiner.sent.slice(at).filter((e) =>
    e.datagram[3] === LOBBY_OPCODE.ROOM_STATE &&
    e.datagram.length >= 0x1c &&
    e.datagram.readUInt32BE(0x10) === 1 &&
    e.datagram[0x18] === 1);
  assert.equal(relayedSub1.length, 1,
    'a non-start op-0x10 (sub-1) is scoped out of the drop and relays unchanged even when ' +
    'word0 == the sender token');
});

test('ON: the sub-5/6/7 HANDOFF (word0 == host token) is NOT dropped - RIG rig3 regression', () => {
  // The host sends its own idx/peer-info/charstats TO the joiner; these carry
  // word0 == the host token (host = subject) but the joiner NEEDS them. Dropping
  // sub-7 starved the joiner of charstats -> wrong characters + network error.
  const { host, joiner } = setup({ op10DropSelf: true });
  const at = joiner.sent.length;
  for (const sub of [0x05, 0x06, 0x07]) {
    host.session.accept(reliableDatagram({
      opcode: LOBBY_OPCODE.ROOM_STATE, sequence: host.next(),
      payload: roomEventBody(TOKEN_HOST, sub), who: 0xa000, token: host.token
    }));
  }
  const relayed = joiner.sent.slice(at).filter((e) =>
    e.datagram[3] === LOBBY_OPCODE.ROOM_STATE &&
    e.datagram.length >= 0x1c &&
    e.datagram.readUInt32BE(0x10) === 1 &&
    [0x05, 0x06, 0x07].includes(e.datagram[0x18]));
  assert.equal(relayed.length, 3,
    'all three handoff subs reach the joiner even though word0 == the host token');
});
