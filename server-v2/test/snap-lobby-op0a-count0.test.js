import assert from 'node:assert/strict';
import test from 'node:test';

import { TimingWheel } from '../src/transport/timing-wheel.js';
import { createV1ObservedAreaDirectory } from '../src/udp/area-directory.js';
import { LOBBY_OPCODE, buildMemberListCount0Payload } from '../src/udp/snap-lobby-codec.js';
import { SnapLobbySessions } from '../src/udp/snap-lobby-sessions.js';

/**
 * RS1-B fix 1 (flag SNAP_OP0A_COUNT0): the op-0x0a member-list reply.
 *
 * The reply CONTENT is the H-B discriminator (RS1-B §5): July V1 answered
 * `count 0` - twelve zero bytes, who 0xA0 - and its joiner proceeded straight
 * down the ladder. V2's count-1 reply with a zeroed 0xF0 charstats blob
 * starved BOTH consoles that ever received it: transport-acked, then "Getting
 * information" for ~142 s, then a client op-0x02 close (T37 emulator
 * 07:07:47 -> 07:10:09; RS1 PS2 17:37:59 -> 17:40:22). The codec's old
 * "answering this is what releases 'Getting information'" annotation is
 * SUPERSEDED by that wire.
 */

const TOKEN = 0x028107d0;

function reliableDatagram({ opcode, sequence, sub = 0, payload = Buffer.alloc(0), who = 0xa000 }) {
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

function harness(sessionOptions = {}) {
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
    ...sessionOptions
  });
  const sent = [];
  const session = table.open({
    routingKey: '192.0.2.129:2000',
    loginIdentity: 'real',
    endpointToken: TOKEN,
    outboundSequence: 1,
    inboundReceiveBase: 0,
    latencyTicks: 1600,
    transmit: (datagram, context) => sent.push({ datagram, ...context })
  });
  return { table, session, sent };
}

/**
 * RS1 17:37:59.560 UTC, the PS2's selection query, byte for byte:
 * `a0 14 00 0a | 028107d0 | 00000123 | 00000000 | 02000000 | ba476611` -
 * the 4-byte body is the LE room handle 2. (Sequence re-based to 0 for the
 * fresh test channel; every other byte is the capture's.)
 */
const RS1_OP0A_BODY = Buffer.from('02000000', 'hex');

function memberListRepliesIn(sent) {
  return sent.filter((entry) =>
    entry.kind === 'reliable' && entry.datagram.length > 4 &&
    entry.datagram[3] === LOBBY_OPCODE.MEMBER_LIST);
}

test('flag ON: the RS1 query is answered with July V1\'s exact count-0 shape', () => {
  const rig = harness({ op0aCount0: true });
  const [outcome] = rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.MEMBER_LIST, sequence: 0, payload: RS1_OP0A_BODY, who: 0xa000
  })).handled;

  assert.equal(outcome.answered, true);
  assert.equal(outcome.members, 0);
  const [reply] = memberListRepliesIn(rig.sent);
  assert.ok(reply != null, 'an op-0x0a reply left');

  // July pkt 516, byte for byte past the session-specific words:
  // `a0 1c 00 0a | token | seq | ack | 000000000000000000000000`.
  assert.equal(reply.datagram.readUInt16BE(0), 0xa01c,
    'who 0xA0 (DATA CLEAR - the routing case 7 accepts) | inner length 0x1c');
  assert.equal(reply.datagram[2], 0, 'sub 0: a non-zero sub is a silent permanent hang');
  assert.equal(reply.datagram[3], LOBBY_OPCODE.MEMBER_LIST);
  assert.deepEqual(
    reply.datagram.subarray(0x10, reply.datagram.length - 4),
    Buffer.alloc(12),
    'TWELVE ZERO BYTES: no handle echo, count 0, no records - the shape whose joiner proceeded'
  );
  assert.deepEqual(buildMemberListCount0Payload(), Buffer.alloc(12));
});

test('break-the-fix: flag OFF restores the count-1 starvation shape byte-identically', () => {
  /*
   * The rollback arm, and the proof the flag discriminates: OFF, the reply is
   * the previous build's - DATA set (0xB0xx), the handle echoed at +0x00.
   * With a member in the queried room it would also declare count 1 with the
   * zeroed 0xF0 blob - the exact bytes RS1-B §1 shows starving the PS2.
   */
  const rig = harness({ op0aCount0: false });
  const [outcome] = rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.MEMBER_LIST, sequence: 0, payload: RS1_OP0A_BODY, who: 0xa000
  })).handled;

  assert.equal(outcome.answered, true);
  const [reply] = memberListRepliesIn(rig.sent);
  assert.equal(reply.datagram.readUInt16BE(0) & 0xfc00, 0xb000, 'the old who: DATA set');
  assert.deepEqual(reply.datagram.subarray(0x10, 0x14), RS1_OP0A_BODY,
    'the old body: handle echoed verbatim, not zeros');
});

test('flag ON: a resolved room with a live member still answers count 0, not count 1', () => {
  // H-B says declaring a member without backing data is the one fatal state;
  // until the member-info channel backs it, the count-0 shape must win even
  // when the registry COULD enumerate someone.
  const rig = harness({ op0aCount0: true });
  const key = Buffer.alloc(4);
  key.writeUInt32BE(5);
  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.AREA_ENTER, sequence: 0, payload: key, who: 0xb000
  }));
  const room = rig.table.rooms.openFor({
    presence: rig.table.presence, host: rig.session.presence, boxId: 5, name: 'ROOM', max: 4
  });
  const handleBytes = Buffer.alloc(4);
  handleBytes.writeUInt32LE(room.handle);
  const before = rig.sent.length;

  const [outcome] = rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.MEMBER_LIST, sequence: 1, payload: handleBytes, who: 0xa000
  })).handled;

  assert.equal(outcome.members, 0);
  const [reply] = memberListRepliesIn(rig.sent.slice(before));
  assert.deepEqual(reply.datagram.subarray(0x10, reply.datagram.length - 4), Buffer.alloc(12));
});
