import assert from 'node:assert/strict';
import test from 'node:test';

import { TimingWheel } from '../src/transport/timing-wheel.js';
import { createV1ObservedAreaDirectory } from '../src/udp/area-directory.js';
import { LOBBY_OPCODE } from '../src/udp/snap-lobby-codec.js';
import { SnapLobbySessions } from '../src/udp/snap-lobby-sessions.js';

/**
 * B3 fix 1 - the op-0x02 close mirror behind `SNAP_EXIT_CLOSE_MIRROR`.
 *
 * T37 (B3-LEAVE-TWICE-EVIDENCE.md §1): on the second exit the client's exit
 * path degrades to the screen-6 teardown and sends a reliable ZERO-body
 * op-0x02 (`FUN_001dbd0c`, `who = 0xb000` "type 2"). V2 acked it at the
 * transport and answered nothing; the client parked ~7 s, gave up and
 * re-registered - sometimes wedging the console permanently.
 *
 * The exit-contract RE (G12-exit-contract-RE-2026-07-17.md, xchain:29337)
 * records the 0xb000 close as a BIDIRECTIONAL handshake the dispatcher
 * mirrors. Flag on: mirror a zero-body op-0x02 (wire flags word `0xb010`,
 * stamped seq) and release the server-side session so the client's follow-up
 * register starts a clean epoch. Flag off (the default): exactly the previous
 * behaviour - transport ack only, session stays.
 */

const TOKEN = 0x02f807d0;
const ROUTING_KEY = '192.0.2.248:2000';

/** The T37 close, byte-shaped: reliable, zero body, sub 0, `who = 0xb010`. */
function closeDatagram({ sequence }) {
  const datagram = Buffer.alloc(0x10 + 4);
  datagram.writeUInt16BE(0xb010, 0);
  datagram.writeUInt8(0, 2);
  datagram.writeUInt8(LOBBY_OPCODE.SESSION_CLOSE, 3);
  datagram.writeUInt32BE(TOKEN, 4);
  datagram.writeUInt32BE(sequence, 8);
  Buffer.from([0xba, 0x47, 0x66, 0x11]).copy(datagram, 0x10);
  return datagram;
}

function harness(sessionOptions = {}) {
  let nowMs = 1_000;
  let intervalToken = null;
  const logs = [];
  const sent = [];
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
  const session = table.open({
    routingKey: ROUTING_KEY,
    loginIdentity: '12345',
    endpointToken: TOKEN,
    outboundSequence: 1,
    inboundReceiveBase: 0,
    latencyTicks: 1600,
    transmit: (datagram, context) => sent.push({ datagram, ...context })
  });
  return { table, session, sent, logs };
}

function op02RepliesIn(sent) {
  return sent.filter((entry) =>
    (entry.kind === 'reliable' || entry.kind === 'mirrored') &&
    entry.datagram.readUInt8(3) === LOBBY_OPCODE.SESSION_CLOSE);
}

/* ---- flag OFF: the previous behaviour, untouched -------------------------- */

test('with the flag OFF (the default) the close is acked, unanswered, and the session stays', () => {
  const rig = harness();
  const before = rig.sent.length;

  const { handled, acknowledgements } = rig.session.accept(closeDatagram({ sequence: 0 }));

  assert.equal(acknowledgements.length, 1, 'the transport ack is kept');
  assert.equal(handled.length, 1);
  assert.equal(handled[0].answered, false);
  assert.equal(handled[0].released, undefined, 'nothing releases the session');
  assert.equal(op02RepliesIn(rig.sent.slice(before)).length, 0, 'no op-0x02 goes back');
  assert.equal(rig.table.get(ROUTING_KEY), rig.session, 'the session is still held');
  assert.ok(
    rig.logs.some((entry) => entry.message === 'udp9090 lobby-observed-message' &&
      entry.fields.opcode === '0x2'),
    'logged exactly as the unhandled opcode it used to be'
  );
});

/* ---- flag ON: mirror + release -------------------------------------------- */

test('with SNAP_EXIT_CLOSE_MIRROR the close is mirrored: zero body, flags 0xb010, stamped seq', () => {
  const rig = harness({ exitCloseMirror: true });
  const before = rig.sent.length;
  const expectedStamp = rig.session.channel.nextStampedSequence;

  const { handled, acknowledgements } = rig.session.accept(closeDatagram({ sequence: 0 }));

  assert.equal(acknowledgements.length, 1, 'the transport ack is still sent first');
  assert.equal(handled[0].answered, true);
  assert.equal(handled[0].released, true);

  const [mirror] = op02RepliesIn(rig.sent.slice(before));
  assert.ok(mirror != null, 'a server->client op-0x02 left');
  // The whole message: who 0xb010 (RELIABLE|SET|DATA, len 16 = zero body),
  // sub 0, opcode 0x02, the token, the STAMPED sequence, then only the trailer.
  assert.equal(mirror.datagram.length, 0x14);
  assert.equal(mirror.datagram.readUInt16BE(0), 0xb010);
  assert.equal(mirror.datagram.readUInt8(2), 0);
  assert.equal(mirror.datagram.readUInt32BE(4), TOKEN);
  assert.equal(mirror.datagram.readUInt32BE(8), expectedStamp,
    'stamped from the session counter, not mirrored from the request');
  assert.deepEqual(mirror.datagram.subarray(0x10), Buffer.from([0xba, 0x47, 0x66, 0x11]));
});

test('the mirrored close RELEASES the session: table slot freed, presence detached', () => {
  const rig = harness({ exitCloseMirror: true });
  assert.equal(rig.table.playersOnServer(), 1);

  rig.session.accept(closeDatagram({ sequence: 0 }));

  assert.equal(rig.table.get(ROUTING_KEY), null, 'the routing slot is free for the re-register');
  assert.equal(rig.table.playersOnServer(), 0, 'no count still sees the departed player');
  assert.equal(rig.session.closed, true);
  // The teardown proves it left no timers behind - same bar as every close path.
  rig.session.assertDrained();
});

test('after the release the same routing key re-opens cleanly (the fresh epoch)', () => {
  const rig = harness({ exitCloseMirror: true });
  rig.session.accept(closeDatagram({ sequence: 0 }));

  const reopened = rig.table.open({
    routingKey: ROUTING_KEY,
    loginIdentity: '12345',
    endpointToken: TOKEN,
    outboundSequence: 1,
    inboundReceiveBase: 0,
    latencyTicks: 1600,
    transmit: () => {}
  });
  assert.ok(reopened != null, 'the re-register epoch is clean');
  assert.equal(rig.table.get(ROUTING_KEY), reopened);
  assert.equal(rig.table.playersOnServer(), 1);
});
