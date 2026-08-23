import assert from 'node:assert/strict';
import test from 'node:test';

import { TimingWheel } from '../src/transport/timing-wheel.js';
import { createV1ObservedAreaDirectory } from '../src/udp/area-directory.js';
import {
  COMPLETION_SELECTOR,
  LOBBY_OPCODE,
  buildCompletionPayload
} from '../src/udp/snap-lobby-codec.js';
import { SnapLobbySessions } from '../src/udp/snap-lobby-sessions.js';

/**
 * B3 fix 2 - the `+0xc` send-seq echo behind `SNAP_COMPLETION_SEQ_ECHO`.
 *
 * The sel-6/sel-7 reply handlers latch `0x6cbc80 = (u16)*(u32*)(param+0xc)` and
 * the pool sweep `FUN_005be120` fires the stored continuation only when that
 * value matches the request's send-seq (`G12-exit-contract-RE-2026-07-17.md:84`,
 * B3-LEAVE-TWICE-EVIDENCE.md §3). Our 8-byte completion puts that read PAST the
 * datagram - the only observed deviation from the RE'd reply contract in the
 * whole first-leave exchange, and the root-cause candidate for "leave twice"
 * under mechanism M1.
 *
 * The touched builder also serves the RIG-CONFIRMED sel-6 ENTER accept, so the
 * off-path tests here pin the payload and the whole reply datagram against
 * HARDCODED pre-change bytes: the flag off must be byte-identical, not merely
 * equivalent.
 */

const TOKEN = 0x02f807d0;
const ROUTING_KEY = '192.0.2.248:2000';

/** Box 5's published `+0x20` key in the V1-observed directory. */
function boxKeyOf(boxId) {
  const { records } = createV1ObservedAreaDirectory().records(() => 0);
  const record = records.find((entry) => entry.name.endsWith(String(boxId).padStart(2, '0')));
  return record.key;
}

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

function harness(sessionOptions = {}) {
  let nowMs = 1_000;
  let intervalToken = null;
  const sent = [];
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
  return { table, session, sent };
}

function completionsIn(sent) {
  return sent.filter((entry) =>
    entry.kind === 'reliable' && entry.datagram.readUInt8(3) === LOBBY_OPCODE.COMPLETION);
}

function enterKey(boxId) {
  const key = Buffer.alloc(4);
  key.writeUInt32BE(boxKeyOf(boxId));
  return key;
}

/* ---- the codec: OFF is byte-identical, ON is the documented layout -------- */

test('without sendSeqEcho the builder emits the exact pre-change 8 bytes', () => {
  // Hardcoded, not computed: this is the payload of the rig-confirmed sel-6
  // ENTER accept (B3 doc §3 shows the sel-7 twin on the wire byte for byte).
  assert.deepEqual(
    buildCompletionPayload({ selector: COMPLETION_SELECTOR.AREA_ENTER, status: 0 }),
    Buffer.from('0000000600000000', 'hex')
  );
  assert.deepEqual(
    buildCompletionPayload({ selector: COMPLETION_SELECTOR.AREA_LEAVE, status: 0 }),
    Buffer.from('0000000700000000', 'hex')
  );
});

test('with sendSeqEcho the payload grows to 0x10 with the send-seq LE at +0xc', () => {
  const payload = buildCompletionPayload({
    selector: COMPLETION_SELECTOR.AREA_LEAVE, status: 0, sendSeqEcho: 0x16
  });
  // +0x00/+0x04 BE as before (the dispatcher's FUN_001d7f6c swaps exactly those
  // two); +0x08 zero; +0xc LITTLE-endian so the client's raw *(u32*) read
  // truncates to the pool slot's native u16 send-seq.
  assert.deepEqual(payload, Buffer.from('00000007' + '00000000' + '00000000' + '16000000', 'hex'));
});

/* ---- the session: flag OFF leaves the rig-confirmed replies untouched ----- */

test('flag OFF (the default): the ENTER and LEAVE reply datagrams are byte-identical to before', () => {
  const rig = harness();
  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.AREA_ENTER, sequence: 0, payload: enterKey(5)
  }));
  rig.session.accept(reliableDatagram({ opcode: LOBBY_OPCODE.AREA_LEAVE, sequence: 1 }));

  const [enterReply, leaveReply] = completionsIn(rig.sent);
  // The WHOLE datagrams, hardcoded: who 0xb018 (len 0x18 = 8-byte payload),
  // sub 0, op 0x28, token, stamped seqs 1 and 2, ack word 0, selector/status,
  // trailer. This is the shape B3 doc §3 shows a real console consuming.
  assert.deepEqual(enterReply.datagram, Buffer.from(
    'b0180028' + '02f807d0' + '00000001' + '00000000' + '0000000600000000' + 'ba476611', 'hex'));
  assert.deepEqual(leaveReply.datagram, Buffer.from(
    'b0180028' + '02f807d0' + '00000002' + '00000000' + '0000000700000000' + 'ba476611', 'hex'));
});

/* ---- the session: flag ON echoes each request's own send-seq -------------- */

test('flag ON: sel-6 and sel-7 completions carry each REQUEST\'S send-seq at +0xc', () => {
  const rig = harness({ completionSeqEcho: true });
  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.AREA_ENTER, sequence: 0, payload: enterKey(5)
  }));
  rig.session.accept(reliableDatagram({ opcode: LOBBY_OPCODE.AREA_LEAVE, sequence: 1 }));

  const [enterReply, leaveReply] = completionsIn(rig.sent);
  // len 0x20 now (0x10 payload); the +0xc word is the inbound sequence, LE.
  assert.equal(enterReply.datagram.readUInt16BE(0), 0xb020);
  assert.equal(enterReply.datagram.readUInt32BE(0x10), COMPLETION_SELECTOR.AREA_ENTER);
  assert.equal(enterReply.datagram.readUInt32LE(0x1c), 0, 'the ENTER rode sequence 0');
  assert.equal(leaveReply.datagram.readUInt16BE(0), 0xb020);
  assert.equal(leaveReply.datagram.readUInt32BE(0x10), COMPLETION_SELECTOR.AREA_LEAVE);
  assert.equal(leaveReply.datagram.readUInt32LE(0x1c), 1, 'the LEAVE rode sequence 1');
});

test('flag ON does NOT touch the other completion selectors (0x0c, 0x0d, create)', () => {
  const rig = harness({ completionSeqEcho: true });
  // The connect-screen op-0x0c (260 bytes) and the op-0x0d re-entry query.
  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.ROOM_QUERY, sequence: 0, payload: Buffer.alloc(260 - 16)
  }));
  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.REENTRY_QUERY, sequence: 1, payload: Buffer.alloc(8)
  }));

  for (const reply of completionsIn(rig.sent)) {
    assert.equal(reply.datagram.readUInt16BE(0), 0xb018,
      'still the 8-byte completion: the echo is scoped to sel-6/sel-7 alone');
  }
});
