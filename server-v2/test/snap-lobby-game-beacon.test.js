import assert from 'node:assert/strict';
import test from 'node:test';

import { TimingWheel } from '../src/transport/timing-wheel.js';
import { createV1ObservedAreaDirectory } from '../src/udp/area-directory.js';
import { LOBBY_OPCODE } from '../src/udp/snap-lobby-codec.js';
import { SnapLobbySessions } from '../src/udp/snap-lobby-sessions.js';

/**
 * The in-game beacon - unreliable op-0x0F, wire flags word `0x2012`, body
 * `00 00`, 1 Hz on its own sequence counter.
 *
 * T37 (B1-GAME-START-MODEL.md §1): after the game-module handoff the client
 * sent 115 of these over ~119 s, every one refused as `CHAT_RUNT`, then aborted
 * the scenario into the post-game meeting room. It is not chat - no reliable
 * bit, no DATA flag - and the client's own dispatcher routes this flag shape to
 * slot 0x14, never the chat slots 0x0B/0x0D. `CHAT_RUNT` was a server-side
 * misfile.
 *
 * These tests cover the reroute (always on: the beacon reaches its own handler,
 * never the chat parser) and the flag-gated echo/relay experiment of PORT-PLAN
 * slice 2c(ii), both defaulting OFF.
 */

const TOKEN = 0x02f807d0;

/** T35 22:15:53 chat body: type 2 (lobby), selector 0 (text), `test123`/`abcde`. */
const ARCHIVE_CHAT_BODY = Buffer.from(
  '020007050000' + Buffer.from('test123abcde', 'latin1').toString('hex'), 'hex');

function reliableDatagram({ opcode, sequence, sub = 0, payload = Buffer.alloc(0), who = 0xb000 }) {
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

/**
 * The T37 beacon shape, byte for byte: flags word `0x2012` (SET only, length
 * 0x12), sub 0, op 0x0F, the token, the beacon's own sequence, body `00 00`.
 */
function beaconDatagram({ sequence, body = Buffer.from([0x00, 0x00]) }) {
  const inner = 0x10 + body.length;
  const datagram = Buffer.alloc(inner + 4);
  datagram.writeUInt16BE(0x2000 | inner, 0);
  datagram.writeUInt8(0, 2);
  datagram.writeUInt8(LOBBY_OPCODE.CHAT, 3);
  datagram.writeUInt32BE(TOKEN, 4);
  datagram.writeUInt32BE(sequence, 8);
  body.copy(datagram, 0x10);
  Buffer.from([0xba, 0x47, 0x66, 0x11]).copy(datagram, inner);
  return datagram;
}

function harness(sessionOptions = {}) {
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
    keepaliveKey: 'SNAP-SWAN',
    logger: {
      debug: record('debug'), info: record('info'),
      warn: record('warn'), error: record('error')
    },
    ...sessionOptions
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
  return { table, open, logs };
}

function enter(session, boxKey, sequence = 0) {
  const key = Buffer.alloc(4);
  key.writeUInt32BE(boxKey);
  session.accept(reliableDatagram({ opcode: LOBBY_OPCODE.AREA_ENTER, sequence, payload: key }));
}

/** Every op-0x0F the given transmit log carries, of any kind. */
function opcode0fIn(sent) {
  return sent.filter((entry) =>
    entry.datagram.length > 4 && entry.datagram.readUInt8(3) === LOBBY_OPCODE.CHAT);
}

/* ---- the reroute (always on) --------------------------------------------- */

test('the flags-0x2012 beacon routes to its own handler, not the chat path', () => {
  const rig = harness();
  const alice = rig.open('192.0.2.248:2000', 'alice');
  const { handled } = alice.session.accept(beaconDatagram({ sequence: 1 }));

  assert.equal(handled.length, 1);
  assert.equal(handled[0].gameBeacon, true, 'consumed by the beacon handler');
  assert.equal(handled[0].opcode, LOBBY_OPCODE.CHAT);
  // Never the chat parser's outcomes: neither a refusal nor the short-variant.
  assert.equal(handled[0].refusal, undefined);
  assert.equal(handled[0].shortVariant, undefined);
});

test('the beacon is consumed at debug and never warns', () => {
  const rig = harness();
  const alice = rig.open('192.0.2.248:2000', 'alice');
  for (let sequence = 1; sequence <= 3; sequence += 1) {
    alice.session.accept(beaconDatagram({ sequence }));
  }
  const beaconLogs = rig.logs.filter((entry) => entry.message === 'udp9090 lobby-game-beacon');
  assert.equal(beaconLogs.length, 3);
  assert.ok(beaconLogs.every((entry) => entry.level === 'debug'));
  assert.equal(
    rig.logs.filter((entry) => entry.level === 'warn' &&
      entry.message.includes('chat')).length,
    0,
    'no CHAT_RUNT-style warning: the T37 misfile is gone'
  );
});

test('a real reliable chat line still takes the chat path after the reroute', () => {
  const rig = harness();
  const alice = rig.open('192.0.2.248:2000', 'alice');
  const bob = rig.open('192.0.2.129:2000', 'bob');
  enter(alice.session, 5);
  enter(bob.session, 5);
  const before = bob.sent.length;

  const [outcome] = alice.session.accept(reliableDatagram({
    // 0xb400: the client's own chat flag shape - 0x0400 is the discriminator.
    opcode: LOBBY_OPCODE.CHAT, sequence: 1, payload: ARCHIVE_CHAT_BODY, who: 0xb400
  })).handled;

  assert.equal(outcome.gameBeacon, undefined, 'not treated as a beacon');
  assert.equal(outcome.relayed, 1, 'relayed to the one peer in the area');
  assert.equal(opcode0fIn(bob.sent.slice(before)).length, 1);
});

/* ---- the RELIABLE game-channel species (RS1-A §2, the 15:02:47 frame) ----- */

/**
 * The reaction frame of 2026-08-08 15:02:47.430 UTC, byte for byte from the T37
 * pcap: RELIABLE op-0x0F, flags `0xa03a` (RELIABLE | SET; DATA clear, 0x0400
 * clear), 42-byte structured body of `06 00`-length blocks. The deployed build
 * misfiled it as chat (`lobby-chat` screenType 40, relayed 0) because the old
 * routing tested `!reliable && !data` instead of the client's own 0x0400
 * discriminator - and the body was only recoverable from the pcap.
 */
const RS1A_RELIABLE_0F_BODY = Buffer.from(
  '28000600041402000000060001000108000000000000' +
  '06000414220000000600010001080000000000' + '00', 'hex');

test('RS1-A replay: the reliable 0x0400-clear op-0x0F is game-channel, never chat', () => {
  const rig = harness();
  const alice = rig.open('192.0.2.248:2000', 'alice');
  const before = alice.sent.length;

  assert.equal(RS1A_RELIABLE_0F_BODY.length, 42, 'the captured body is 42 bytes');
  const [outcome] = alice.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CHAT, sequence: 0, payload: RS1A_RELIABLE_0F_BODY, who: 0xa000
  })).handled;

  assert.equal(outcome.gameChannel, true, 'consumed by the game-channel path');
  assert.equal(outcome.answered, false, 'nothing is invented in reply');
  assert.equal(outcome.relayed, undefined, 'the chat relay never saw it');
  assert.equal(outcome.refusal, undefined);
  assert.equal(opcode0fIn(alice.sent.slice(before)).length, 0, 'no op-0x0F left the server');

  // The raw body hex is journalled at debug - the evidence RS1-A §6.3 demands.
  const log = rig.logs.find((entry) => entry.message === 'udp9090 lobby-game-channel-0f');
  assert.ok(log != null, 'the game-channel journal line exists');
  assert.equal(log.level, 'debug');
  assert.equal(log.fields.body, RS1A_RELIABLE_0F_BODY.toString('hex'));
  assert.equal(
    rig.logs.filter((entry) => entry.message === 'udp9090 lobby-chat').length, 0,
    'the RS1-A misfile is gone: no lobby-chat event for game-module traffic'
  );
  assert.equal(alice.session.stats().gameChannelFrames, 1);
});

test('a 0x0400-clear DATA-set op-0x0F also routes to the game channel, not the chat parser', () => {
  // The client's table tests ONLY 0x0400; DATA merely picks slot 0x0B vs 0x0D
  // WITHIN chat. A DATA-set frame without 0x0400 has no chat branch at all.
  const rig = harness();
  const alice = rig.open('192.0.2.248:2000', 'alice');
  const [outcome] = alice.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CHAT, sequence: 0, payload: ARCHIVE_CHAT_BODY, who: 0xb000
  })).handled;
  assert.equal(outcome.gameChannel, true,
    'a chat-shaped body without 0x0400 is game-module traffic, exactly as the client routes it');
  assert.equal(outcome.relayed, undefined);
});

/* ---- the echo experiment (SNAP_GAME_BEACON_ECHO, default OFF) ------------- */

test('with the echo flag OFF (the default) the beacon is not answered at all', () => {
  const rig = harness();
  const alice = rig.open('192.0.2.248:2000', 'alice');
  const before = alice.sent.length;
  alice.session.accept(beaconDatagram({ sequence: 1 }));
  assert.equal(opcode0fIn(alice.sent.slice(before)).length, 0,
    'nothing on op-0x0F left the server - identical to every previous build');
});

test('with SNAP_GAME_BEACON_ECHO the beacon comes back verbatim to the sender', () => {
  const rig = harness({ gameBeaconEcho: true });
  const alice = rig.open('192.0.2.248:2000', 'alice');
  const before = alice.sent.length;

  const { handled } = alice.session.accept(beaconDatagram({ sequence: 7 }));
  assert.equal(handled[0].echoed, true);

  const [echo] = opcode0fIn(alice.sent.slice(before));
  assert.ok(echo != null, 'an op-0x0F went back to the sender');
  // Verbatim shape: unreliable, flags word 0x2012 (SET | length 0x12), sub 0,
  // and the exact 2-byte body. The sequence is stamped from the server's own
  // unreliable counter - the channel owns that stream.
  assert.equal(echo.kind, 'unreliable');
  assert.equal(echo.datagram.readUInt16BE(0), 0x2012);
  assert.equal(echo.datagram.readUInt8(2), 0);
  assert.deepEqual(echo.datagram.subarray(0x10, 0x12), Buffer.from([0x00, 0x00]));
});

/* ---- the relay experiment (SNAP_GAME_BEACON_RELAY, default OFF) ----------- */

/** Alice creates a room in box 5 and bob is moved into it. Returns both ends. */
function roomPair(rig) {
  const alice = rig.open('192.0.2.248:2000', 'alice');
  const bob = rig.open('192.0.2.129:2000', 'bob');
  enter(alice.session, 5, 0);
  alice.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CREATE_ROOM, sequence: 1, payload: Buffer.alloc(0x2c)
  }));
  const handle = alice.session.createdRoom.handle;
  enter(bob.session, 5, 0);
  rig.table.presence.moveTo(bob.session.presence, { roomHandle: handle });
  return { alice, bob };
}

test('with the relay flag OFF (the default) nothing reaches the room peer', () => {
  const rig = harness();
  const { alice, bob } = roomPair(rig);
  const before = bob.sent.length;
  const { handled } = alice.session.accept(beaconDatagram({ sequence: 1 }));
  assert.equal(handled[0].relayed, 0);
  assert.equal(opcode0fIn(bob.sent.slice(before)).length, 0);
});

test('with SNAP_GAME_BEACON_RELAY the beacon reaches room members, never the sender', () => {
  const rig = harness({ gameBeaconRelay: true });
  const { alice, bob } = roomPair(rig);
  const beforeBob = bob.sent.length;
  const beforeAlice = alice.sent.length;

  const { handled } = alice.session.accept(beaconDatagram({ sequence: 1 }));
  assert.equal(handled[0].relayed, 1, 'exactly the one room peer');

  const [relayed] = opcode0fIn(bob.sent.slice(beforeBob));
  assert.ok(relayed != null);
  assert.equal(relayed.kind, 'unreliable');
  assert.equal(relayed.datagram.readUInt16BE(0), 0x2012);
  assert.deepEqual(relayed.datagram.subarray(0x10, 0x12), Buffer.from([0x00, 0x00]));

  assert.equal(opcode0fIn(alice.sent.slice(beforeAlice)).length, 0,
    'the sender does not get its own beacon back through the RELAY flag');
});

test('the relay is room-scoped: a player merely in the same AREA hears nothing', () => {
  const rig = harness({ gameBeaconRelay: true });
  const alice = rig.open('192.0.2.248:2000', 'alice');
  const bob = rig.open('192.0.2.129:2000', 'bob');
  enter(alice.session, 5, 0);
  alice.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CREATE_ROOM, sequence: 1, payload: Buffer.alloc(0x2c)
  }));
  enter(bob.session, 5, 0); // same box, NOT in the room
  const before = bob.sent.length;

  const { handled } = alice.session.accept(beaconDatagram({ sequence: 1 }));
  assert.equal(handled[0].relayed, 0);
  assert.equal(opcode0fIn(bob.sent.slice(before)).length, 0);
});
