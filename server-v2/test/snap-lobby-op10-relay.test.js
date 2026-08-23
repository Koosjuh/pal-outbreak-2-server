import assert from 'node:assert/strict';
import test from 'node:test';

import { TimingWheel } from '../src/transport/timing-wheel.js';
import { createV1ObservedAreaDirectory } from '../src/udp/area-directory.js';
import { LOBBY_OPCODE, decodeRoomEvent } from '../src/udp/snap-lobby-codec.js';
import { SnapLobbySessions } from '../src/udp/snap-lobby-sessions.js';

/**
 * THE op-0x10 ROOM-SCOPED RELAY (PORT-PLAN slice 2a, flag SNAP_OP10_RELAY) -
 * the bioserver dumb-relay principle on the game channel, with chat's proven
 * scope model: the payload fans out VERBATIM to the sender's own room, except
 * the sender.
 *
 * SUPERSEDED (2026-08-08, RS1-B §2/§6): the recipient-addressed version these
 * tests used to pin. Body word1 is the SENDER'S OWN `0x6febe8` handle - July's
 * `02f807d0` and RS1's `00000003` both are - so a relay that resolved it
 * against roster ids excluded the only entity the word could name and
 * delivered to nobody by construction (`relayed: 0`, structural). Matching it
 * against presenceId was additionally a live cross-type collision hazard:
 * RS1's PS2 held presenceId 3 while room handle 3 existed. Nothing in the
 * message body routes anything any more.
 */

const TOKEN_A = 0x02f807d0;
const TOKEN_B = 0x02f907d1;
const TOKEN_C = 0x02fa07d2;

function reliableDatagram({ opcode, sequence, sub = 0, payload = Buffer.alloc(0), who = 0xa000, token }) {
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

function harness({ sessions = {} } = {}) {
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
    op10Relay: true,
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

function enter(client, boxKey) {
  const key = Buffer.alloc(4);
  key.writeUInt32BE(boxKey);
  client.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.AREA_ENTER, sequence: client.next(), payload: key,
    who: 0xb000, token: client.token
  }));
}

/** Put a client into a room directly through the state layer (P2-preserving). */
function intoRoom(rig, client, { host = null, boxId = 5, slot = 1 } = {}) {
  if (host == null) {
    return rig.table.rooms.openFor({
      presence: rig.table.presence, host: client.session.presence, boxId, name: 'ROOM', max: 4
    });
  }
  rig.table.presence.moveTo(client.session.presence, { roomHandle: host.handle, slot });
  return host;
}

/** An op-0x10 body: `[BE32 count][BE32 senderHandle][sub][data]`. */
function burst({ senderHandle, sub = 0x03, data = Buffer.from('feedface', 'hex') }) {
  const payload = Buffer.alloc(4 + 4 + 4 + data.length);
  payload.writeUInt32BE(1, 0);
  payload.writeUInt32BE(senderHandle, 4);
  payload[8] = sub;
  data.copy(payload, 12);
  return payload;
}

function op10In(sent) {
  return sent.filter((entry) =>
    entry.datagram.length > 4 && entry.datagram[3] === LOBBY_OPCODE.ROOM_STATE &&
    entry.kind !== 'ack');
}

/* ---- the RS1 byte-exact replay ------------------------------------------- */

/**
 * RS1 17:39:18.059 UTC, the host's op-0x10 sub-1 datagram body, byte for byte
 * (RS1-B §2): `[BE32 1][BE32 3 = the room handle minted 40 ms earlier - the
 * sender's OWN handle][sub 0x01][zeros]`. The deployed relay resolved the `3`
 * against roster presenceIds/endpoint tokens, matched nobody (its own
 * presenceId was 5), and `relayed: 0`.
 */
const RS1_HOST_OP10_BODY = Buffer.from(
  '00000001' + '00000003' + '01000000' + '00000000' + '00000000', 'hex');

test('RS1 replay: the host sub-1 burst reaches the room peer VERBATIM, whatever word1 says', () => {
  const rig = harness();
  const host = rig.open('192.0.2.248:2000', 'test123', TOKEN_A);
  const joiner = rig.open('192.0.2.129:2000', 'real', TOKEN_B);
  enter(host, 5);
  enter(joiner, 5);
  const room = intoRoom(rig, host);
  intoRoom(rig, joiner, { host: room });
  assert.notEqual(joiner.session.presence.presenceId, 3,
    'precondition: word1 (3) names NO presence in this rig - as on the RS1 wire');
  const before = joiner.sent.length;

  // Wire flags 0xe0: RELIABLE | ACK | SET, exactly the captured frame word
  // (`e0 24 00 10`); the ack half carries the client's live cumulative ack.
  const [outcome] = host.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.ROOM_STATE, sequence: host.next(),
    payload: RS1_HOST_OP10_BODY, token: TOKEN_A, who: 0xe000
  })).handled;

  assert.equal(outcome.relayed, 1,
    'the RS1 wire produced relayed:0 from this exact body; room scope delivers it');
  const [forwarded] = op10In(joiner.sent.slice(before));
  assert.ok(forwarded, 'the room member received it on op-0x10');
  assert.deepEqual(
    forwarded.datagram.subarray(0x10, forwarded.datagram.length - 4),
    RS1_HOST_OP10_BODY,
    'forwarded VERBATIM - count word, sender handle, sub and data untouched'
  );
  assert.equal(forwarded.datagram[0] & 0x10, 0, 'DATA clear: the slot-0x13 routing');
});

test('word1 is decoded as the sender handle, and decode is structural only', () => {
  const decoded = decodeRoomEvent(RS1_HOST_OP10_BODY);
  assert.equal(decoded.senderHandle, 3, 'the room handle minted 40 ms earlier - the sender itself');
  assert.equal(decoded.sub, 0x01);
});

/* ---- the scope model ------------------------------------------------------ */

test('room scope: every room member gets it; a same-area outsider gets NOTHING', () => {
  const rig = harness();
  const host = rig.open('192.0.2.248:2000', 'hostA', TOKEN_A);
  const joiner = rig.open('192.0.2.129:2000', 'joinerB', TOKEN_B);
  const outsider = rig.open('192.0.2.130:2000', 'outsiderC', TOKEN_C);
  enter(host, 5);
  enter(joiner, 5);
  enter(outsider, 5); // same AREA, never in the room
  const room = intoRoom(rig, host);
  intoRoom(rig, joiner, { host: room });
  const joinerBefore = joiner.sent.length;
  const outsiderBefore = outsider.sent.length;

  const body = burst({ senderHandle: room.handle });
  const [outcome] = host.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.ROOM_STATE, sequence: host.next(), payload: body, token: TOKEN_A
  })).handled;

  assert.equal(outcome.relayed, 1, 'the one room peer');
  const [forwarded] = op10In(joiner.sent.slice(joinerBefore));
  assert.deepEqual(
    forwarded.datagram.subarray(0x10, forwarded.datagram.length - 4), body,
    'forwarded VERBATIM (relay, never interpret)'
  );
  assert.equal(op10In(outsider.sent.slice(outsiderBefore)).length, 0,
    'area presence is not room presence');
});

test('the presenceId collision hazard is dead: word1 naming an OUTSIDER delivers only in-room', () => {
  /*
   * The RS1 hazard note (§6.3): a small-integer handle word can equal an
   * unrelated presenceId. Under the superseded matcher that produced a false
   * TARGET; under room scope the word routes nothing at all.
   */
  const rig = harness();
  const host = rig.open('192.0.2.248:2000', 'hostA', TOKEN_A);
  const joiner = rig.open('192.0.2.129:2000', 'joinerB', TOKEN_B);
  const outsider = rig.open('192.0.2.130:2000', 'outsiderC', TOKEN_C);
  enter(host, 5);
  enter(joiner, 5);
  enter(outsider, 5);
  const room = intoRoom(rig, host);
  intoRoom(rig, joiner, { host: room });
  const outsiderBefore = outsider.sent.length;
  const joinerBefore = joiner.sent.length;

  const [outcome] = host.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.ROOM_STATE, sequence: host.next(),
    payload: burst({ senderHandle: outsider.session.presence.presenceId }), token: TOKEN_A
  })).handled;

  assert.equal(outcome.relayed, 1, 'the room member, and only the room member');
  assert.equal(op10In(outsider.sent.slice(outsiderBefore)).length, 0,
    'a body word can never address a player outside the sender\'s room');
  assert.equal(op10In(joiner.sent.slice(joinerBefore)).length, 1);
});

test('a sender in NO room relays to nobody, whatever word1 carries', () => {
  const rig = harness();
  const sender = rig.open('192.0.2.248:2000', 'senderA', TOKEN_A);
  const bystander = rig.open('192.0.2.129:2000', 'bystanderB', TOKEN_B);
  enter(sender, 5);
  enter(bystander, 5);
  intoRoom(rig, bystander); // the BYSTANDER is in a room; the SENDER is not
  const before = bystander.sent.length;

  const [outcome] = sender.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.ROOM_STATE, sequence: sender.next(),
    payload: burst({ senderHandle: bystander.session.presence.presenceId }), token: TOKEN_A
  })).handled;

  assert.equal(outcome.relayed, 0, 'scope comes from the SENDER\'s presence, never the message');
  assert.equal(op10In(bystander.sent.slice(before)).length, 0);
});

test('a solo host relays to nobody - the sender is always excluded', () => {
  const rig = harness();
  const host = rig.open('192.0.2.248:2000', 'hostA', TOKEN_A);
  enter(host, 5);
  const room = intoRoom(rig, host);
  const before = host.sent.length;

  const [outcome] = host.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.ROOM_STATE, sequence: host.next(),
    payload: burst({ senderHandle: room.handle }), token: TOKEN_A
  })).handled;

  assert.equal(outcome.relayed, 0, 'relay means "to the others"; tonight\'s roster held nobody else');
  assert.equal(op10In(host.sent.slice(before)).length, 0);
});

/* ---- structural bounds ---------------------------------------------------- */

test('a lying word count cannot read past the body, and an absurd one is refused', () => {
  const rig = harness();
  const host = rig.open('192.0.2.248:2000', 'hostA', TOKEN_A);
  enter(host, 5);
  intoRoom(rig, host);

  const truncated = Buffer.alloc(8);
  truncated.writeUInt32BE(3, 0); // declares 3 handle words, carries none of them
  const [first] = host.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.ROOM_STATE, sequence: host.next(), payload: truncated, token: TOKEN_A
  })).handled;
  assert.equal(first.refusal, 'ROOM_EVENT_RUNT');

  const absurd = Buffer.alloc(0x40);
  absurd.writeUInt32BE(0xffff, 0);
  const [second] = host.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.ROOM_STATE, sequence: host.next(), payload: absurd, token: TOKEN_A
  })).handled;
  assert.equal(second.refusal, 'ROOM_EVENT_RECIPIENTS');
});

test('flag OFF: the burst stays an unhandled opcode and nothing is forwarded', () => {
  const rig = harness({ sessions: { op10Relay: false } });
  const host = rig.open('192.0.2.248:2000', 'hostA', TOKEN_A);
  const joiner = rig.open('192.0.2.129:2000', 'joinerB', TOKEN_B);
  enter(host, 5);
  enter(joiner, 5);
  const room = intoRoom(rig, host);
  intoRoom(rig, joiner, { host: room });
  const before = joiner.sent.length;

  const [outcome] = host.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.ROOM_STATE, sequence: host.next(),
    payload: burst({ senderHandle: room.handle }), token: TOKEN_A
  })).handled;

  assert.equal(outcome.answered, false);
  assert.equal(outcome.relayed, undefined, 'the unhandled default answered, not the relay');
  assert.equal(op10In(joiner.sent.slice(before)).length, 0);
});
