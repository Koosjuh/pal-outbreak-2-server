import assert from 'node:assert/strict';
import test from 'node:test';

import { TimingWheel } from '../src/transport/timing-wheel.js';
import { createV1ObservedAreaDirectory } from '../src/udp/area-directory.js';
import {
  CHAT_TEXT_MAXIMUM,
  LOBBY_OPCODE,
  decodeChatMessage
} from '../src/udp/snap-lobby-codec.js';
import { SnapLobbySessions } from '../src/udp/snap-lobby-sessions.js';

/**
 * LOBBY CHAT - op-0x0F, which the client has been sending since the first lobby
 * run and which the server logged as an unhandled opcode and dropped.
 *
 * The owner reported chat as "only local". That is exactly what an unrelayed
 * op-0x0F looks like: `FUN_005C4AF0` writes the line into the sender's own display
 * block BEFORE transmitting, so the sender always sees it and nobody else ever
 * does. The local half was never broken, which is why it read as a half-working
 * feature rather than a missing one.
 *
 * The fixture below is the real thing, from the T35 capture at 22:15:53 -
 * `192.0.2.248 -> 192.0.2.121:9090`, user `test123` typing `abcde`.
 */

const TOKEN = 0x02f807d0;

/** T35 22:15:53, body verbatim: type 2 (lobby), selector 0 (text), 7-byte name, 5-byte text. */
const ARCHIVE_CHAT_BODY = Buffer.from('020007050000' + Buffer.from('test123abcde', 'latin1').toString('hex'), 'hex');
/** The OTHER captured op-0x0F: selector 1, no name, and our own area-table version as "text". */
const ARCHIVE_PROBE_BODY = Buffer.from('000100090000' + Buffer.from('OBAREA-V2', 'latin1').toString('hex'), 'hex');

/**
 * `who` default 0xb400 is the CLIENT'S OWN chat flag shape: RELIABLE | SET |
 * DATA | 0x0400 (T35 `0xb422`, RS1 `0xb421`). The 0x0400 bit is the
 * dispatcher's chat/game discriminator - a chat body sent without it routes to
 * the game-channel path, exactly as on a real console (RS1-A §6.2).
 */
function reliableDatagram({ opcode, sequence, sub = 0, payload = Buffer.alloc(0), who = 0xb400 }) {
  const inner = 0x10 + payload.length;
  const datagram = Buffer.alloc(inner + 4);
  datagram.writeUInt16BE(who | inner, 0);
  datagram.writeUInt8(sub, 2);
  datagram.writeUInt8(opcode, 3);
  datagram.writeUInt32BE(TOKEN, 4);
  datagram.writeUInt32BE(sequence, 8);
  payload.copy(datagram, 0x10);
  Buffer.from([0xba, 0x47, 0x66, 0x11]).copy(datagram, inner);
  return datagram;
}

function harness() {
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
    wheel, areaDirectory: createV1ObservedAreaDirectory(), keepaliveKey: 'SNAP-SWAN'
  });
  const open = (routingKey, identity) => {
    const sent = [];
    const session = table.open({
      routingKey,
      loginIdentity: identity,
      endpointToken: TOKEN,
      outboundSequence: 1,
      inboundReceiveBase: 0,
      latencyTicks: 1600,
      transmit: (datagram, context) => sent.push({ datagram, ...context })
    });
    return { session, sent };
  };
  return { table, open };
}

function enter(session, boxKey, sequence = 0) {
  const key = Buffer.alloc(4);
  key.writeUInt32BE(boxKey);
  session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.AREA_ENTER, sequence, payload: key, who: 0xb000
  }));
}

function chatRelaysIn(sent) {
  return sent.filter((entry) =>
    entry.datagram.length > 4 && entry.datagram.readUInt8(3) === LOBBY_OPCODE.CHAT);
}

/* ---- the capability ------------------------------------------------------ */

test('a chat line reaches the OTHER player in the same area', () => {
  const rig = harness();
  const alice = rig.open('192.0.2.248:2000', 'alice');
  const bob = rig.open('192.0.2.129:2000', 'bob');
  enter(alice.session, 5);
  enter(bob.session, 5);
  const before = bob.sent.length;

  const [outcome] = alice.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CHAT, sequence: 1, payload: ARCHIVE_CHAT_BODY
  })).handled;

  assert.equal(outcome.relayed, 1, 'exactly one peer received it');
  const [relay] = chatRelaysIn(bob.sent.slice(before));
  assert.ok(relay != null, 'and it arrived on op-0x0F');

  const body = relay.datagram.subarray(0x10, relay.datagram.length - 4);
  const decoded = decodeChatMessage(body);
  assert.equal(decoded.name.toString('latin1'), 'test123');
  assert.equal(decoded.text.toString('latin1'), 'abcde');
  assert.equal(decoded.isChatText, true);
});

test('the sender does NOT get its own line back', () => {
  /*
   * `FUN_005C4AF0` already wrote the line into the sender's display block before
   * transmitting. Echoing would show every player their own messages twice - and
   * it is why the symptom read as "only local" rather than "chat missing".
   */
  const rig = harness();
  const alice = rig.open('192.0.2.248:2000', 'alice');
  const bob = rig.open('192.0.2.129:2000', 'bob');
  enter(alice.session, 5);
  enter(bob.session, 5);
  const before = alice.sent.length;

  alice.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CHAT, sequence: 1, payload: ARCHIVE_CHAT_BODY
  }));
  assert.equal(chatRelaysIn(alice.sent.slice(before)).length, 0);
});

test('chat does not leak into another area', () => {
  // Scope is the SENDER'S OWN location, read from presence - never from anything
  // in the message, so a client cannot address a place it is not in.
  const rig = harness();
  const alice = rig.open('192.0.2.248:2000', 'alice');
  const bob = rig.open('192.0.2.129:2000', 'bob');
  enter(alice.session, 5);
  enter(bob.session, 3);
  const before = bob.sent.length;

  const [outcome] = alice.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CHAT, sequence: 1, payload: ARCHIVE_CHAT_BODY
  })).handled;

  assert.equal(outcome.relayed, 0);
  assert.equal(chatRelaysIn(bob.sent.slice(before)).length, 0);
});

test('area chat still reaches a peer who is INSIDE a room in that area', () => {
  /*
   * Pins the exact pre-extraction semantics of `#relayChat` across the
   * `broadcast(scope, deliver)` refactor: only the SENDER's depth picks the
   * scope. A sender at area depth addresses the whole area, including peers
   * who have descended into rooms there - the old `sameArea` test read only
   * `peer.boxId`, never `peer.roomHandle`.
   */
  const rig = harness();
  const alice = rig.open('192.0.2.248:2000', 'alice');
  const bob = rig.open('192.0.2.129:2000', 'bob');
  enter(alice.session, 5);
  enter(bob.session, 5);
  rig.table.rooms.openFor({
    presence: rig.table.presence, host: bob.session.presence, boxId: 5, name: 'ROOM', max: 4
  });
  assert.notEqual(bob.session.presence.roomHandle, null, 'bob is in a room');
  const before = bob.sent.length;

  const [outcome] = alice.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CHAT, sequence: 1, payload: ARCHIVE_CHAT_BODY
  })).handled;

  assert.equal(outcome.relayed, 1, 'the room does not hide bob from area chat');
  assert.equal(chatRelaysIn(bob.sent.slice(before)).length, 1);
});

test('a player in no area at all hears nothing and sends to nobody', () => {
  const rig = harness();
  const alice = rig.open('192.0.2.248:2000', 'alice');
  const bob = rig.open('192.0.2.129:2000', 'bob');
  enter(alice.session, 5);
  // bob never entered an area: he is at server depth.
  const before = bob.sent.length;

  const [outcome] = alice.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CHAT, sequence: 1, payload: ARCHIVE_CHAT_BODY
  })).handled;
  assert.equal(outcome.relayed, 0);
  assert.equal(chatRelaysIn(bob.sent.slice(before)).length, 0);
});

/* ---- the relayed frame's flags (RS1-C §C1, byte-exact) ------------------- */

/**
 * RS1 17:34:09.618 UTC, `192.0.2.248 -> server`, verbatim: user `test123`
 * typing `1234` on the lobby screen. Inbound flags word `0xB421`. The deployed
 * relay re-emitted the body byte-perfectly but with flags `0xB021` - the
 * `0x0400` bit missing - and the PS2 transport-acked it at +23 ms and never
 * rendered it: the client dispatcher has NO branch for `0x1000`-set/
 * `0x0400`-clear, so the datagram dies after the ack (RS1-C §C1, Conclusion).
 */
const RS1_CHAT_BODY = Buffer.from(
  '020007040000' + Buffer.from('test1231234', 'latin1').toString('hex'), 'hex');

test('RS1 replay: the AREA relay carries 0xB4xx - the exact inbound flag shape', () => {
  const rig = harness();
  const alice = rig.open('192.0.2.248:2000', 'alice');
  const bob = rig.open('192.0.2.129:2000', 'bob');
  enter(alice.session, 4);
  enter(bob.session, 4);
  const before = bob.sent.length;

  const [outcome] = alice.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CHAT, sequence: 1, payload: RS1_CHAT_BODY, who: 0xb400
  })).handled;

  assert.equal(outcome.relayed, 1);
  const [relay] = chatRelaysIn(bob.sent.slice(before));
  assert.equal(relay.datagram.readUInt16BE(0), 0xb421,
    'RELIABLE | SET | DATA | 0x0400 | len 0x21 - byte-identical to the inbound flags word; ' +
    'the deployed 0xB021 is the one-bit defect RS1-C proved fatal');
  assert.deepEqual(
    relay.datagram.subarray(0x10, relay.datagram.length - 4), RS1_CHAT_BODY,
    'body verbatim, as it always was - the flags were the only diff'
  );
});

test('ROOM chat relays as 0xA4xx: 0x0400 set, DATA clear - the room-scope shape', () => {
  const rig = harness();
  const alice = rig.open('192.0.2.248:2000', 'alice');
  const bob = rig.open('192.0.2.129:2000', 'bob');
  enter(alice.session, 4);
  enter(bob.session, 4);
  const room = rig.table.rooms.openFor({
    presence: rig.table.presence, host: alice.session.presence, boxId: 4, name: 'ROOM', max: 4
  });
  rig.table.presence.moveTo(bob.session.presence, { roomHandle: room.handle, slot: 1 });
  const before = bob.sent.length;

  const [outcome] = alice.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CHAT, sequence: 1, payload: RS1_CHAT_BODY, who: 0xa400
  })).handled;

  assert.equal(outcome.relayed, 1, 'room scope: only the room member');
  const [relay] = chatRelaysIn(bob.sent.slice(before));
  assert.equal(relay.datagram.readUInt16BE(0), 0xa421,
    'RELIABLE | SET | 0x0400 with DATA CLEAR: the corpus room-chat shape (0xA400|len)');
});

/* ---- the probe that shares the opcode ------------------------------------ */

test('the area-name probe is NOT relayed, even though it rides op-0x0F', () => {
  /*
   * Selector 1 is the probe, and the captured one carries our own area-table
   * version string. Relaying blind would broadcast "OBAREA-V2" to the room as
   * though a player had typed it.
   */
  const rig = harness();
  const alice = rig.open('192.0.2.248:2000', 'alice');
  const bob = rig.open('192.0.2.129:2000', 'bob');
  enter(alice.session, 5);
  enter(bob.session, 5);
  const before = bob.sent.length;

  const [outcome] = alice.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CHAT, sequence: 1, payload: ARCHIVE_PROBE_BODY
  })).handled;

  assert.equal(outcome.probe, true);
  assert.equal(outcome.answered, true, 'consumed and acknowledged, not refused');
  assert.equal(chatRelaysIn(bob.sent.slice(before)).length, 0, 'and never forwarded');
});

/* ---- the bound that protects everyone else ------------------------------- */

test('an over-long line is refused rather than relayed into a peer memcpy', () => {
  /*
   * The receiver `FUN_005BC590` memcpys name and text into fixed globals with NO
   * length check. This is the one place on this path where refusing is right:
   * elsewhere silence hangs the sender, but here forwarding a bad line corrupts
   * memory on every OTHER console in the room.
   */
  const rig = harness();
  const alice = rig.open('192.0.2.248:2000', 'alice');
  const bob = rig.open('192.0.2.129:2000', 'bob');
  enter(alice.session, 5);
  enter(bob.session, 5);
  const before = bob.sent.length;

  const oversized = Buffer.concat([
    Buffer.from([2, 0, 4, CHAT_TEXT_MAXIMUM + 1, 0, 0]),
    Buffer.from('name', 'latin1'),
    Buffer.alloc(CHAT_TEXT_MAXIMUM + 1, 0x41)
  ]);
  const [outcome] = alice.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CHAT, sequence: 1, payload: oversized
  })).handled;

  assert.equal(outcome.answered, false);
  assert.equal(outcome.refusal, 'CHAT_TEXT_LENGTH');
  assert.equal(chatRelaysIn(bob.sent.slice(before)).length, 0, 'nothing reached the peer');
});

test('a truncated body cannot read past the end of the datagram', () => {
  const rig = harness();
  const alice = rig.open('192.0.2.248:2000', 'alice');
  enter(alice.session, 5);
  const [outcome] = alice.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CHAT,
    sequence: 1,
    // Declares a 7-byte name and 5-byte text, then carries none of it.
    payload: Buffer.from([2, 0, 7, 5, 0, 0])
  })).handled;
  assert.equal(outcome.answered, false);
  assert.equal(outcome.refusal, 'CHAT_TRUNCATED');
});
