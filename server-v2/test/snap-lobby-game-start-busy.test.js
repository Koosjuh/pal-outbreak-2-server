import assert from 'node:assert/strict';
import test from 'node:test';

import { ROOM_STATUS } from '../src/state/room-lifecycle.js';
import { TimingWheel } from '../src/transport/timing-wheel.js';
import { createV1ObservedAreaDirectory } from '../src/udp/area-directory.js';
import { COMPLETION_SELECTOR, LOBBY_OPCODE } from '../src/udp/snap-lobby-codec.js';
import { SnapLobbySessions } from '../src/udp/snap-lobby-sessions.js';

/**
 * ROOM -> BUSY ON START (PORT-PLAN slice 2b) - bioserver broadcastGetReady
 * steps 1-2 wired to the earliest server-visible start signal.
 *
 * The signal is the op-0x0D BODY-1 barrier: `FUN_005c4760` state 4 sends
 * `[BE32 1]` as each member enters the game, and T37 shows it answered and
 * consumed (B1-GAME-START-MODEL.md S1 B-ii). The body value is the
 * discriminator - `f7e00001` is the post-game re-open on the SAME opcode.
 * THE REPLY DOES NOT CHANGE: both callbacks read only the status byte, and the
 * op-0x28 sel-0x0D answer is a rig-consumed path. What body 1 adds is ENGINE
 * state only: gamenumber mint-once, party snapshot, room -> BUSY.
 *
 * The wire half - op-0x49 record flags +0x1c carrying the status - is
 * EVIDENCE-GATED behind SNAP_ROOMFLAGS_PUBLISH (default OFF): no console has
 * ever been shown non-zero flags, and B2's H-B even suspects zeros gate the
 * join UI.
 */

const TOKEN = 0x02f807d0;

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
    ...sessions
  });
  const sent = [];
  const session = table.open({
    routingKey: '192.0.2.248:2000',
    loginIdentity: 'host',
    endpointToken: TOKEN,
    outboundSequence: 1,
    inboundReceiveBase: 0,
    latencyTicks: 1600,
    transmit: (datagram, context) => sent.push({ datagram, ...context })
  });
  let seq = 0;
  const next = () => { seq += 1; return seq - 1; };
  return { table, session, sent, next };
}

function enter(rig, boxKey) {
  const key = Buffer.alloc(4);
  key.writeUInt32BE(boxKey);
  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.AREA_ENTER, sequence: rig.next(), payload: key
  }));
}

function createRoom(rig) {
  const before = rig.sent.length;
  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CREATE_ROOM, sequence: rig.next(), payload: Buffer.alloc(0x2c)
  }));
  const accept = rig.sent.slice(before).find((entry) =>
    entry.datagram.length >= 0x1c && entry.datagram[3] === LOBBY_OPCODE.COMPLETION &&
    entry.datagram.readUInt32BE(0x10) === COMPLETION_SELECTOR.CREATE_ROOM);
  assert.ok(accept, 'the create accept left');
  return accept.datagram.readUInt32BE(0x14);
}

function sendBarrier(rig, bodyWord) {
  const body = Buffer.alloc(4);
  body.writeUInt32BE(bodyWord, 0);
  const before = rig.sent.length;
  const [outcome] = rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.REENTRY_QUERY, sequence: rig.next(), payload: body, who: 0xa000
  })).handled;
  return { outcome, sent: rig.sent.slice(before) };
}

/* ---- the barrier ---------------------------------------------------------- */

test('op-0x0D body 1 marks the room BUSY, mints the game session - and the reply is untouched', () => {
  const rig = harness();
  enter(rig, 5);
  const handle = createRoom(rig);
  assert.equal(rig.table.roomLifecycle.statusOf(handle), ROOM_STATUS.GAMESET);

  const { outcome, sent } = sendBarrier(rig, 1);

  // THE REPLY FIRST, because it is the protected path: op-0x28 selector 0x0D,
  // status 0, the exact 8-byte body every previous build sent (T37-consumed).
  const reply = sent.find((entry) =>
    entry.datagram.length > 4 && entry.datagram[3] === LOBBY_OPCODE.COMPLETION &&
    entry.kind !== 'ack');
  assert.ok(reply, 'the sel-0x0D completion left');
  assert.equal(reply.datagram.length, 0x10 + 8 + 4, 'the 8-byte body, unchanged');
  assert.equal(reply.datagram.readUInt32BE(0x10), COMPLETION_SELECTOR.REENTRY);
  assert.equal(reply.datagram.readUInt32BE(0x14), 0, 'status 0');

  // Then the engine consequence (broadcastGetReady steps 1-2).
  assert.equal(outcome.barrier, true);
  assert.equal(outcome.gamenumber, 1, 'the first minted gamenumber');
  assert.equal(rig.table.roomLifecycle.statusOf(handle), ROOM_STATUS.BUSY,
    'the room is BUSY: nobody else joins a started game');
  const game = rig.table.gameSessions.forRoom(handle);
  assert.ok(game != null);
  assert.deepEqual([...game.party], ['host'], 'the party snapshot at start');
  assert.equal(rig.table.profiles.get('host').gamenumber, 1,
    'every member profile carries the gamenumber');
});

test('a second barrier from the same room reuses the gamenumber (mint once)', () => {
  const rig = harness();
  enter(rig, 5);
  const handle = createRoom(rig);
  sendBarrier(rig, 1);
  const { outcome } = sendBarrier(rig, 1);
  assert.equal(outcome.gamenumber, 1, 'minted once; BUSY -> BUSY is the idempotent edge');
  assert.equal(rig.table.roomLifecycle.statusOf(handle), ROOM_STATUS.BUSY);
});

test('op-0x0D body 0xf7e00001 (post-game re-open) is answered and starts NOTHING', () => {
  const rig = harness();
  enter(rig, 5);
  const handle = createRoom(rig);

  const { outcome, sent } = sendBarrier(rig, 0xf7e00001);

  assert.equal(outcome.answered, true, 'the re-open is answered exactly as before');
  assert.equal(outcome.barrier, false, 'the body value is the discriminator');
  assert.equal(outcome.gamenumber, null);
  assert.equal(rig.table.roomLifecycle.statusOf(handle), ROOM_STATUS.GAMESET,
    'the room stays joinable');
  assert.equal(rig.table.gameSessions.forRoom(handle), null);
  assert.ok(sent.some((entry) =>
    entry.datagram.length > 4 && entry.datagram[3] === LOBBY_OPCODE.COMPLETION));
});

test('a barrier from a session in no room is answered and refused quietly', () => {
  const rig = harness();
  enter(rig, 5);
  const { outcome } = sendBarrier(rig, 1);
  assert.equal(outcome.answered, true);
  assert.equal(outcome.barrier, true);
  assert.equal(outcome.gamenumber, null, 'no room, no game session, no throw');
});

/* ---- the wire half, flag-gated ------------------------------------------- */

function roomListRecords(rig) {
  const before = rig.sent.length;
  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.ROOM_LIST, sequence: rig.next()
  }));
  const reply = rig.sent.slice(before).find((entry) =>
    entry.datagram.length > 4 && entry.datagram[3] === LOBBY_OPCODE.ROOM_LIST &&
    entry.kind !== 'ack');
  assert.ok(reply, 'the op-0x49 reply left');
  // payload at +0x10; header 12 bytes; then 0x28-byte records.
  return reply.datagram.subarray(0x10 + 12, reply.datagram.length - 4);
}

test('SNAP_ROOMFLAGS_PUBLISH OFF (default): record flags +0x18/+0x1c stay zero', () => {
  const rig = harness();
  enter(rig, 5);
  const handle = createRoom(rig);
  sendBarrier(rig, 1); // the room IS BUSY in the engine...
  assert.equal(rig.table.roomLifecycle.statusOf(handle), ROOM_STATUS.BUSY);

  const record = roomListRecords(rig);
  assert.equal(record.readUInt32BE(0x18), 0, '+0x18 zero - byte-identical to every build');
  assert.equal(record.readUInt32BE(0x1c), 0, '+0x1c zero - ...but the wire never learns it');
});

test('SNAP_ROOMFLAGS_PUBLISH ON: +0x1c carries the authored status, BE like its siblings', () => {
  const rig = harness({ sessions: { roomFlagsPublish: true } });
  enter(rig, 5);
  const handle = createRoom(rig);

  let record = roomListRecords(rig);
  assert.equal(record.readUInt32BE(0x1c), ROOM_STATUS.GAMESET, 'joinable publishes GAMESET (3)');

  sendBarrier(rig, 1);
  assert.equal(rig.table.roomLifecycle.statusOf(handle), ROOM_STATUS.BUSY);
  record = roomListRecords(rig);
  assert.equal(record.readUInt32BE(0x1c), ROOM_STATUS.BUSY, 'started publishes BUSY (4)');
  assert.equal(record.readUInt32BE(0x18), 0, '+0x18 stays zero; only +0x1c is the flags word');
});
