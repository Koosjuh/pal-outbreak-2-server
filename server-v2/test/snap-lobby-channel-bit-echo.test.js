import assert from 'node:assert/strict';
import test from 'node:test';

import { TimingWheel } from '../src/transport/timing-wheel.js';
import { createV1ObservedAreaDirectory } from '../src/udp/area-directory.js';
import { LOBBY_OPCODE } from '../src/udp/snap-lobby-codec.js';
import { SnapLobbySessions } from '../src/udp/snap-lobby-sessions.js';

/**
 * The C3 fix - `SNAP_CHANNEL_BIT_ECHO` (SESSION-LOG-2026-08-24 T1/T2).
 *
 * The in-room Exit press ships ONE datagram: a room-channel op-0x08 "STAT@"
 * (who 0xA818 - RELIABLE|SET|AGGREGATE, DATA clear) with an op-0x07 LEAVE
 * rider (who 0xA010, seq 0, zero body). RS1 frame 5185, byte for byte below.
 * V2 answered both completions with the default 0xB0xx (DATA set) flag word -
 * RS1 frames 5188/5189 - and the client transport-acked them and then parked
 * forever (the 144.8 s watchdog death).
 *
 * The result dispatcher `FUN_001d9f78` case 6 routes the sel-7 completion BY
 * the received DATA bit (DATA set -> conn+0x5D4 = slot 0x23, the LOBBY-leave
 * callback), the AM SNAP client documents the same &0x1000 split
 * (ResultLeaveRoom vs ResultLeaveLobby), and V1 answered op-0x07 with BOTH
 * classes (game_udp_server.js:2065). So a 0xB0xx reply to a 0xA0xx leave fires
 * the wrong completion class. The flag makes sel-7/sel-8 completions echo the
 * request's own DATA bit; every rig-confirmed request on these paths arrives
 * with DATA set, so flag ON changes NOTHING for them - pinned below.
 */

const TOKEN = 0x02f807d0;
const ROUTING_KEY = '192.168.2.248:2000';

/** RS1-20260808-172534.pcap frame 5185, the Exit datagram, byte for byte. */
const C3_EXIT_DATAGRAM = Buffer.from(
  'a818000802f807d0000000aa81000000' + '5354415440000000' + // op-0x08 "STAT@\0\0\0"
  'a010000702f807d00000000094000000' +                      // op-0x07 rider, seq 0
  'ba476611', 'hex');

function reliableDatagram({ opcode, sequence, sub = 0, flags = 0xb000, payload = Buffer.alloc(0) }) {
  const inner = 0x10 + payload.length;
  const datagram = Buffer.alloc(inner + 4);
  datagram.writeUInt16BE(flags | inner, 0);
  datagram.writeUInt8(sub, 2);
  datagram.writeUInt8(opcode, 3);
  datagram.writeUInt32BE(TOKEN, 4);
  datagram.writeUInt32BE(sequence, 8);
  payload.copy(datagram, 0x10);
  Buffer.from([0xba, 0x47, 0x66, 0x11]).copy(datagram, inner);
  return datagram;
}

function harness({ inboundReceiveBase = 0, ...sessionOptions } = {}) {
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
    outboundSequence: 0x98, // the RS1 window: replies land at seq 0x98/0x99
    inboundReceiveBase,
    latencyTicks: 1600,
    transmit: (datagram, context) => sent.push({ datagram, ...context })
  });
  return { table, session, sent };
}

function completionsIn(sent) {
  return sent.filter((entry) =>
    entry.kind === 'reliable' && entry.datagram.readUInt8(3) === LOBBY_OPCODE.COMPLETION);
}

/* ---- flag OFF: the RS1-shipped bytes, pinned ------------------------------ */

test('flag OFF (default): the C3 exit datagram is answered exactly as RS1 shipped it (0xB0xx)', () => {
  // completionSeqEcho ON = the deployed Pi env of RS1 (FULL-RECORD §7), so both
  // replies here pin the shipped wire bytes exactly.
  const rig = harness({ inboundReceiveBase: 0xaa, completionSeqEcho: true });
  rig.session.accept(C3_EXIT_DATAGRAM);

  const [statReply, leaveReply] = completionsIn(rig.sent);
  // RS1 frames 5188/5189, byte for byte - the replies the client acked and
  // then parked on. This pin is the regression identity for the flag OFF.
  assert.deepEqual(statReply.datagram, Buffer.from(
    'b0200028' + '02f807d0' + '00000098' + '00000000' +
    '00000008' + '00000000' + '53544154' + '00000000' + 'ba476611', 'hex'));
  assert.deepEqual(leaveReply.datagram, Buffer.from(
    'b0200028' + '02f807d0' + '00000099' + '00000000' +
    '00000007' + '00000000' + '00000000' + '00000000' + 'ba476611', 'hex'));
});

/* ---- flag ON: room-channel requests get room-channel completions ---------- */

test('flag ON: the sel-7 completion for the C3 exit echoes DATA clear; sel-8 stays default', () => {
  const rig = harness({ inboundReceiveBase: 0xaa, channelBitEcho: true });
  rig.session.accept(C3_EXIT_DATAGRAM);

  const [statReply, leaveReply] = completionsIn(rig.sent);
  // SCOPED TO SEL-7 (nora caveat 1): the sel-8 STAT completion keeps the
  // default 0xB0xx — its dispatch is single-slot and its callback's reading of
  // the channel bit is unread, so it does not move on the first rig run.
  assert.equal(statReply.datagram.readUInt16BE(0), 0xb020,
    'sel-8 stays on the default lobby-context flags (echo scoped to sel-7)');
  assert.equal(statReply.datagram.readUInt32BE(0x10), 8, 'still selector 8');
  assert.equal(leaveReply.datagram.readUInt16BE(0), 0xa018,
    'the LEAVE completion mirrors the rider\'s room channel (DATA clear)');
  assert.equal(leaveReply.datagram.readUInt32BE(0x10), 7, 'still selector 7');
  // Everything below the flag word is unchanged: token, stamped seqs, payloads.
  assert.equal(statReply.datagram.readUInt32BE(4), TOKEN);
  assert.equal(leaveReply.datagram.readUInt32BE(8), 0x99);
});

test('flag ON + completionSeqEcho ON (the Pi env): 0xA020 leave completion with the seq-0 echo', () => {
  const rig = harness({
    inboundReceiveBase: 0xaa, channelBitEcho: true, completionSeqEcho: true
  });
  rig.session.accept(C3_EXIT_DATAGRAM);

  const [, leaveReply] = completionsIn(rig.sent);
  assert.equal(leaveReply.datagram.readUInt16BE(0), 0xa020);
  assert.equal(leaveReply.datagram.readUInt32LE(0x1c), 0,
    'the rider rode sequence 0 and the +0xc echo says so');
});

test('flag ON changes NOTHING for lobby-channel (0xB0xx) requests - byte-identical replies', () => {
  const on = harness({ channelBitEcho: true });
  const off = harness();
  for (const rig of [on, off]) {
    rig.session.accept(reliableDatagram({
      opcode: LOBBY_OPCODE.NAMED_CHANNEL_QUERY, sequence: 0,
      payload: Buffer.from('5354415440000000', 'hex')
    }));
    rig.session.accept(reliableDatagram({ opcode: LOBBY_OPCODE.AREA_LEAVE, sequence: 1 }));
  }
  assert.deepEqual(
    completionsIn(on.sent).map((entry) => entry.datagram),
    completionsIn(off.sent).map((entry) => entry.datagram),
    'every rig-confirmed lobby-channel completion is untouched by the flag');
});
