import assert from 'node:assert/strict';
import test from 'node:test';

import { blowfishEcbDecrypt, createBlowfishKey } from '../src/crypto/blowfish.js';
import { TimingWheel } from '../src/transport/timing-wheel.js';
import { createV1ObservedAreaDirectory } from '../src/udp/area-directory.js';
import { KEEPALIVE_PLAINTEXT_BYTES, LOBBY_OPCODE } from '../src/udp/snap-lobby-codec.js';
import {
  SnapLobbySessions,
  SnapLobbySessionsError,
  latencyTicksFromTlvs,
  watchdogBudgetMsFromLatencyTicks
} from '../src/udp/snap-lobby-sessions.js';

/**
 * The post-selection subsystem end to end, against the archived bytes.
 *
 * Nothing sleeps: the wheel's clock and interval are injected, so "five seconds
 * passed" is a stated fact and the keepalive cadence is testable at all.
 *
 * Archive = `C:\dnas\pi-evidence-archive\extracted\captures\udp9090\`
 * `2026_07_30_14_52_53_udp_192_0_2_248_2000.log` (sanitized), the session that reached a
 * rendered Area Select on real PS2 hardware.
 */

const TOKEN = 0x02f807d0;
const ROUTING_KEY = '192.0.2.248:2000';
/** The rig-proven keepalive key: `deploy/pi-env.d/zzz-op40-keepalive.conf`. */
const KEEPALIVE_KEY = 'SNAP-SWAN';

/** Archive IN #9: the 70-byte op-0x48 NAME query, reliable, sequence 0. */
const ARCHIVE_NAME_QUERY = Buffer.from(
  'f042004802f807d000000000000000000000000a020000004e414d4544313932' +
  '2e302e322e31323130310000004e414d45463139322e302e322e313231313000' +
  '0000ba476611', 'hex');

/**
 * Archive IN #16: TWO op-0x48 queries coalesced into one 136-byte datagram, the
 * first carrying `0x0800`. This exists because the reliable channel's own header
 * says "nothing in the archive shows the client batching application messages at
 * all" - which these bytes contradict. V1 acknowledged the OUTER frame only and
 * the client carried on, so the standing rule holds; the evidence for it is here.
 */
const ARCHIVE_COALESCED_NAME_QUERY = Buffer.from(
  'b842004802f807d000000004000000000000000a020000004e414d4544313932' +
  '2e302e322e31323130310000004e414d45463139322e302e322e313231313000' +
  '0000b042004802f807d0000000000000000000000a020000004e414d45443139' +
  '322e302e322e31323130310000004e414d45463139322e302e322e3132313130' +
  '000000ba476611', 'hex');

function reliableDatagram({
  opcode, sequence, sub = 0, payload = Buffer.alloc(0), flags = 0xb000
}) {
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

function harness({ tickMs = 100, sessions: sessionOptions = {}, open: openOptions = {} } = {}) {
  let nowMs = 1_000;
  let intervalToken = null;
  const wheelErrors = [];
  const logs = [];
  const wheel = new TimingWheel({
    tickMs,
    clock: () => nowMs,
    setInterval: (fn) => { intervalToken = { fn, unref() {} }; return intervalToken; },
    clearInterval: () => { intervalToken = null; },
    onError: (report) => wheelErrors.push(report)
  });
  wheel.start();

  const record = (level) => (message, fields) => logs.push({ level, message, fields });
  const sent = [];
  const table = new SnapLobbySessions({
    wheel,
    areaDirectory: createV1ObservedAreaDirectory(),
    keepaliveKey: KEEPALIVE_KEY,
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
    // The slot-0x1c push is sent at the constant sequence 0 and takes the
    // client's recvBase to 1, so the stamped stream starts there - exactly the
    // archive's first op-0x48 reply.
    outboundSequence: 1,
    inboundReceiveBase: 0,
    latencyTicks: 1600,
    transmit: (datagram, context) => sent.push({ datagram, ...context }),
    ...openOptions
  });

  return {
    wheel,
    table,
    session,
    sent,
    logs,
    wheelErrors,
    advanceMs(ms) { nowMs += ms; intervalToken?.fn(); },
    run(ms) {
      for (let step = 0; step < Math.ceil(ms / tickMs); step += 1) this.advanceMs(tickMs);
    },
    of(kind, opcode) {
      return sent.filter((entry) =>
        entry.kind === kind && (opcode == null || entry.opcode === opcode));
    }
  };
}

test('the op-0x40 keepalive leaves on the bind and matches V1 byte for byte in its header', () => {
  const rig = harness();
  const [keepalive] = rig.of('unreliable', LOBBY_OPCODE.KEEPALIVE);
  assert.ok(keepalive, 'the keepalive is sent when the session opens, not on the first op-0x0c');
  // 296 bytes; who 0x3124 = SET|DATA with the ten-bit length 0x124, and NO
  // reliable bit; sub 0; opcode 0x40; the token; V1's dedicated counter at 1.
  assert.equal(keepalive.datagram.length, 296);
  assert.deepEqual(
    keepalive.datagram.subarray(0, 16),
    Buffer.from('3124004002f807d00000000100000000', 'hex')
  );
});

test('the keepalive body decrypts to 0x110 zero bytes under the literal SNAP-SWAN key', () => {
  const rig = harness();
  const [keepalive] = rig.of('unreliable', LOBBY_OPCODE.KEEPALIVE);
  const body = keepalive.datagram.subarray(0x10, 0x10 + KEEPALIVE_PLAINTEXT_BYTES);
  // The property that matters is the CLIENT's: FUN_001d9b6c reads four length
  // words out of the decrypted body and memcpys them. Non-zero lengths overrun
  // an unmodified retail console's stack, so this asserts the plaintext, not the
  // ciphertext - which no capture records.
  assert.deepEqual(
    blowfishEcbDecrypt(createBlowfishKey(KEEPALIVE_KEY), body),
    Buffer.alloc(KEEPALIVE_PLAINTEXT_BYTES)
  );
  assert.deepEqual(keepalive.datagram.subarray(0x120, 0x124), Buffer.alloc(4));
});

test('the keepalive repeats on the 5 s cadence with a rising unreliable sequence', () => {
  const rig = harness();
  rig.run(12_000);
  const keepalives = rig.of('unreliable', LOBBY_OPCODE.KEEPALIVE);
  // t=0, t=5s, t=10s.
  assert.equal(keepalives.length, 3);
  assert.deepEqual(keepalives.map((entry) => entry.sequence), [1, 2, 3]);
});

test('a keepalive period the client declared budget cannot absorb is refused, not clamped', () => {
  const rig = harness({
    sessions: { keepalivePeriodMs: 30_000 },
    // LC = 100 -> conn+0x51c = 100*32 + 4000 = 7200 ms.
    open: { latencyTicks: 100 }
  });
  assert.equal(rig.session, null);
  const refused = rig.logs.find((entry) => entry.message === 'udp9090 lobby-session-refused');
  assert.equal(refused.fields.code, 'KEEPALIVE_PERIOD');
});

test('a register with no LC still gets a keepalive, and says loudly that it is unchecked', () => {
  const rig = harness({ open: { latencyTicks: null } });
  assert.ok(rig.session);
  assert.ok(rig.of('unreliable', LOBBY_OPCODE.KEEPALIVE).length > 0);
  const warned = rig.logs.find((entry) =>
    entry.message === 'udp9090 lobby-watchdog-budget-unknown');
  assert.ok(warned, 'an unchecked budget is stated, never silently defaulted');
});

test('the watchdog budget is LC*32+4000, read from the register TLVs', () => {
  assert.equal(watchdogBudgetMsFromLatencyTicks(1600), 55_200);
  assert.equal(latencyTicksFromTlvs([{ tag: 'LC', value: 1600 }, { tag: 'MR', value: 48 }]), 1600);
  assert.equal(latencyTicksFromTlvs([{ tag: 'MR', value: 48 }]), null);
  assert.equal(watchdogBudgetMsFromLatencyTicks(null), null);
});

test('the archived op-0x48 query is acknowledged and answered with the area records', () => {
  const rig = harness();
  const before = rig.sent.length;
  rig.session.accept(ARCHIVE_NAME_QUERY);
  const emitted = rig.sent.slice(before);

  // Archive OUT #8: the ack of sequence 0, byte for byte.
  assert.deepEqual(
    emitted[0].datagram,
    Buffer.from('6010000002f807d00000000000000000ba476611', 'hex')
  );
  // Archive OUT #9: the 392-byte reply at the stamped sequence 1.
  const reply = emitted[1].datagram;
  assert.equal(reply.length, 392);
  assert.deepEqual(
    reply.subarray(0, 16),
    Buffer.from('b184004802f807d00000000100000000', 'hex')
  );
  assert.equal(reply.subarray(0x1c, 0x24).toString('latin1'), 'AREA0001');
});

test('every reliable inbound is acknowledged, including one it cannot answer', () => {
  const rig = harness();
  const before = rig.sent.length;
  // The client's op-0x41 answer to our keepalive: reliable, so it must be acked
  // and nothing else (V1: SNAP_SUPPRESS_UNKNOWN_REPLY).
  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.KEEPALIVE_RESPONSE, sequence: 0, payload: Buffer.alloc(0x88)
  }));
  const emitted = rig.sent.slice(before);
  assert.equal(emitted.length, 1);
  assert.equal(emitted[0].kind, 'ack');
  assert.equal(rig.session.stats().keepaliveResponses, 1);
});

test('the op-0x0c completion copies wire+0x02 verbatim and never assumes zero', () => {
  const rig = harness();
  for (const [index, sub] of [0, 1, 2].entries()) {
    const before = rig.sent.length;
    rig.session.accept(reliableDatagram({
      opcode: LOBBY_OPCODE.ROOM_QUERY, sequence: index, sub, payload: Buffer.alloc(0xf0)
    }));
    const [, completion] = rig.sent.slice(before);
    assert.equal(completion.datagram.readUInt8(2), sub);
    assert.equal(completion.datagram.readUInt8(3), 0x28);
    assert.deepEqual(
      completion.datagram.subarray(0x10, 0x18), Buffer.from('0000000c00000000', 'hex'));
  }
});

test('the first op-0x0c completion is byte-identical to the archived 28-byte reply', () => {
  const rig = harness();
  // Archive: IN #9 (op-0x48, seq 0) then IN #11 (op-0x0c, seq 1), so the
  // completion is the SECOND stamped send and lands at sequence 2.
  rig.session.accept(ARCHIVE_NAME_QUERY);
  const before = rig.sent.length;
  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.ROOM_QUERY, sequence: 1, sub: 0, payload: Buffer.alloc(0xf0)
  }));
  const [, completion] = rig.sent.slice(before);
  assert.deepEqual(
    completion.datagram,
    Buffer.from('b018002802f807d000000002000000000000000c00000000ba476611', 'hex')
  );
});

test('the archived op-0x48 batch still answers its outer message, and walks nothing', () => {
  /*
   * THE CASE THAT FALSIFIED THE SIMPLE RULE, so it is worth stating precisely.
   *
   * Walking was enabled for the create path, where the client batches op-0x0a +
   * op-0x09 + op-0x09 into one datagram and all three must be answered. The
   * proposed safety rule was "walk only when the first message declares 0x0800,
   * which is the client's own rule, and the V1 corruption came from datagrams
   * that did NOT declare it".
   *
   * That last clause is FALSE, and this fixture disproves it: the archived
   * op-0x48 datagram's first word is 0xb842 - 0x0800 IS set - and its second
   * sub-header still does not parse, because an op-0x48 body is Blowfish
   * ciphertext and stepping the declared length into it lands mid-cipher. That
   * is exactly the read that made V1 acknowledge ids like 0xcd0a0000 and free
   * the wrong client buffers (T9 2026-07-02).
   *
   * So the flag alone cannot decide it, and the channel degrades instead: it
   * answers the outer message and declines the part it could not parse.
   * Refusing the whole datagram - the behaviour before the degrade was added -
   * would turn a working op-0x48 into silence.
   */
  const rig = harness();
  const before = rig.sent.length;
  const result = rig.session.accept(ARCHIVE_COALESCED_NAME_QUERY);
  const acks = rig.sent.slice(before).filter((entry) => entry.kind === 'ack');

  assert.equal(acks.length, 1, 'the outer message is still acknowledged, exactly once');
  assert.equal(acks[0].datagram.readUInt32BE(0x0c), 4, 'by the OUTER frame id');
  assert.ok(
    result.refusals.some((refusal) => refusal.code === 'BATCH_WALK_DEGRADED'),
    'the unparseable remainder is reported, never delivered and never acknowledged'
  );
});

/* ---- B2: reliable sub-messages ride the covering acceptance (T37 replays) ---- */

/**
 * T37 frame #2216 (`captures/v2-live/T37-20260808-090328.pcap`, 07:15:27.600,
 * 192.0.2.129, token `028107d0`): the 215-byte aggregate of the B2 join
 * freeze - op-0x41 keepalive-response (seq 0x81, `0x0800` set) with an op-0x49
 * room-list query riding it, stale sequence field `0x76000000`. On the rig this
 * was acked and NEVER answered (no `lobby-room-list` journal event), which
 * stalled `.129`'s reply-driven sweep into the frozen lobby UI
 * (`docs/design/v2-port/B2-JOIN-FREEZE-EVIDENCE.md` §1/§4).
 */
const T37_JOIN_AGGREGATE_129 = Buffer.from(
  'b8980041028107d0000000810000000020a2304dd210388f80b8a8602dadbae5' +
  'cb47aac0c62e703980b8a8602dadbae53e1ca2da24cf2b9280b8a8602dadbae5' +
  'cde5b6497161632c80b8a8602dadbae584a5ce8451bd9c7b80b8a8602dadbae5' +
  '6b12d7ad9bbd78e880b8a8602dadbae55362933e4289f2c939ad5ca5b2d07559' +
  '711d6eec92ffa18380b8a8602dadbae56a3c4b8e13e5bf24b03b0049028107d0' +
  '7600000000000000000000fa0310388f4c4f4944010000000253544154210008' +
  '00000008000053544154210400000004000000ba476611', 'hex');

/**
 * T37 frame #2162 (07:15:22.188, 192.0.2.248, token `02f807d0` - this
 * harness's own token): the post-create batch. op-0x0a member-list (seq 0x49,
 * `0x0800` set) + op-0x09 "USER" + op-0x09 "MAXI", BOTH op-0x09s with sequence
 * field 0 - which per-message acceptance classified below-base `duplicates`,
 * so the T37 journal has no `lobby-area-count` event after either create
 * (B2 doc §3, the same-family defect).
 */
const T37_CREATE_BATCH_248 = Buffer.from(
  'e814000a02f807d0000000490000003900000002a018000902f807d000000000' +
  '0000002d0000000255534552a018010902f807d0000000002700000000000002' +
  '4d415849ba476611', 'hex');

test('T37 join freeze replay: the coalesced op-0x49 is dispatched and ANSWERED', () => {
  const rig = harness({
    open: { endpointToken: 0x028107d0, inboundReceiveBase: 0x81 }
  });
  const before = rig.sent.length;
  const result = rig.session.accept(T37_JOIN_AGGREGATE_129);
  const emitted = rig.sent.slice(before);

  assert.equal(result.handled.length, 2, 'the keepalive-response AND the room-list query');
  assert.equal(rig.session.stats().keepaliveResponses, 1);

  // The pre-branch ack emission (nora pre-deploy fix 1): the covering sequence
  // AND the parsed rider's own id - the exact acks months of rig runs sent.
  const acks = emitted.filter((entry) => entry.kind === 'ack');
  assert.deepEqual(
    acks.map((entry) => entry.datagram.readUInt32BE(0x0c)), [0x81, 0x76000000],
    'the OUTER sequence gates the stream; the rider id is acked as rig-proven noise'
  );

  // THE CURE: on the rig this exact datagram produced an ack and nothing else.
  const replies = emitted.filter((entry) => entry.kind === 'reliable' && entry.opcode === 0x49);
  assert.equal(replies.length, 1, 'the room-list query is answered, not swallowed');
  assert.ok(
    rig.logs.some((entry) => entry.message === 'udp9090 lobby-room-list'),
    'the journal event T37 was missing for every coalesced query'
  );
});

test('T37 create batch replay: the op-0x09 USER/MAXI riders with seq field 0 are answered', () => {
  const rig = harness({ open: { inboundReceiveBase: 0x49 } });
  const before = rig.sent.length;
  const result = rig.session.accept(T37_CREATE_BATCH_248);
  const emitted = rig.sent.slice(before);

  assert.equal(result.handled.length, 3, 'op-0x0a + op-0x09 USER + op-0x09 MAXI all dispatch');
  const acks = emitted.filter((entry) => entry.kind === 'ack');
  assert.deepEqual(
    acks.map((entry) => entry.datagram.readUInt32BE(0x0c)), [0x49, 0x00],
    'covering sequence + the riders\' shared stale id 0, deduplicated (nora fix 1)'
  );

  const memberList = emitted.filter((entry) => entry.kind === 'reliable' && entry.opcode === 0x0a);
  const counts = emitted.filter((entry) => entry.kind === 'reliable' && entry.opcode === 0x09);
  assert.equal(memberList.length, 1, 'the outer member-list query is answered as before');
  assert.equal(counts.length, 2, 'BOTH count queries are answered; T37 answered neither');
  assert.equal(
    rig.logs.filter((entry) => entry.message === 'udp9090 lobby-area-count').length, 2,
    'the lobby-area-count events missing from the T37 journal after both creates'
  );
});

test('the ENTER accept answers selector 6 and resolves the key back to its box', () => {
  const rig = harness();
  const key = Buffer.alloc(4);
  key.writeUInt32BE(7);
  const before = rig.sent.length;
  const [outcome] = rig.session.accept(
    reliableDatagram({ opcode: LOBBY_OPCODE.AREA_ENTER, sequence: 0, sub: 3, payload: key })
  ).handled;
  const [, accept] = rig.sent.slice(before);
  assert.equal(outcome.boxId, 7);
  assert.equal(accept.datagram.readUInt8(2), 3, 'wire+0x02 echoes the send generation');
  assert.deepEqual(accept.datagram.subarray(0x10, 0x18), Buffer.from('0000000600000000', 'hex'));
});

/* ---- M-2: op-0x48 counts and op-0x49 rooms come from live state ---------- */

/** The `+0x10` player count of one box's record in an op-0x48 reply datagram. */
function publishedCount(datagram, boxId) {
  const record = 0x10 + 12 + (boxId - 1) * 0x24;
  return datagram.readUInt32BE(record + 0x10);
}

function enter(session, boxKey) {
  const key = Buffer.alloc(4);
  key.writeUInt32BE(boxKey);
  session.accept(reliableDatagram({ opcode: LOBBY_OPCODE.AREA_ENTER, sequence: 0, payload: key }));
}

test('op-0x48 publishes the sessions actually in each area, never zeros', () => {
  /*
   * The seam this pins was `playerCountFor = () => 0`, which the composed
   * application never overrode: every area reported 0 players on the rig. That
   * makes the distinct `+0x20` keys pointless - nothing per-box is ever
   * distinguishable - and it makes the "Server full" gate untestable, because
   * `FUN_005bc990` sums exactly these words.
   */
  const rig = harness();
  const second = rig.table.open({
    routingKey: '192.0.2.249:2000',
    loginIdentity: '54321',
    endpointToken: TOKEN,
    outboundSequence: 1,
    inboundReceiveBase: 0,
    latencyTicks: 1600,
    transmit: () => {}
  });
  // The V1-observed directory publishes key == box id, so key 7 is box 7.
  enter(rig.session, 7);
  enter(second, 7);

  const before = rig.sent.length;
  rig.session.accept(reliableDatagram({ opcode: LOBBY_OPCODE.NAME_QUERY, sequence: 1,
    payload: ARCHIVE_NAME_QUERY.subarray(0x10, ARCHIVE_NAME_QUERY.length - 4) }));
  const [, reply] = rig.sent.slice(before);
  assert.equal(publishedCount(reply.datagram, 7), 2, 'both sessions entered box 7');
  assert.equal(publishedCount(reply.datagram, 1), 0, 'and nobody is in box 1');
  // The sum is the gate's left operand, so the log has to carry the same number.
  const logged = rig.logs.filter((entry) => entry.message === 'udp9090 lobby-name-query').at(-1);
  assert.equal(logged.fields.population, 2);
});

test('a session that has not entered an area counts towards no area', () => {
  const rig = harness();
  rig.session.accept(ARCHIVE_NAME_QUERY);
  const [, reply] = rig.sent.slice(-2);
  for (let boxId = 1; boxId <= 10; boxId += 1) {
    assert.equal(publishedCount(reply.datagram, boxId), 0);
  }
  assert.equal(rig.table.playersIn(7), 0);
});

test('a closed session leaves the area population it was counted in', () => {
  const rig = harness();
  enter(rig.session, 4);
  assert.equal(rig.table.playersIn(4), 1);
  rig.table.close(ROUTING_KEY, 'test');
  assert.equal(rig.table.playersIn(4), 0);
});

test('op-0x49 lists the rooms held for THIS session\'s area and no other', () => {
  const rig = harness();
  rig.table.rooms.open({ handle: 0x11, boxId: 7, name: 'SEVEN', max: 4 });
  rig.table.rooms.open({ handle: 0x22, boxId: 3, name: 'THREE', max: 4 });
  enter(rig.session, 7);

  const before = rig.sent.length;
  rig.session.accept(reliableDatagram({ opcode: LOBBY_OPCODE.ROOM_LIST, sequence: 1 }));
  const [, reply] = rig.sent.slice(before);
  // `[BE32 0][BE32 0][BE32 count]` then 0x28-byte records; the payload starts at
  // datagram +0x10.
  assert.equal(reply.datagram.readUInt32BE(0x18), 1, 'only box 7\'s room');
  assert.equal(reply.datagram.subarray(0x1c, 0x21).toString('latin1'), 'SEVEN');
  assert.equal(reply.datagram.readUInt32BE(0x1c + 0x20), 4, 'max players, big-endian');
});

test('with no rooms open the op-0x49 reply reports none, which is a real lobby state', () => {
  const rig = harness();
  enter(rig.session, 7);
  const before = rig.sent.length;
  rig.session.accept(reliableDatagram({ opcode: LOBBY_OPCODE.ROOM_LIST, sequence: 1 }));
  const [, reply] = rig.sent.slice(before);
  assert.equal(rig.table.rooms.size, 0);
  assert.equal(reply.datagram.readUInt32BE(0x18), 0);
  const logged = rig.logs.find((entry) => entry.message === 'udp9090 lobby-room-list');
  assert.equal(logged.fields.boxId, 7);
});

test('a session table refuses to construct without a room model or a count seam', () => {
  // Both used to default to a lambda that reported nothing, and the defaults are
  // what production ran on. A missing seam must now be loud.
  assert.throws(
    () => new SnapLobbySessions({
      wheel: new TimingWheel({ onError: () => {} }),
      areaDirectory: createV1ObservedAreaDirectory(),
      keepaliveKey: KEEPALIVE_KEY,
      rooms: {}
    }),
    (error) => error instanceof SnapLobbySessionsError && error.code === 'ROOMS_REQUIRED'
  );
});

test('an ENTER whose key matches nothing is still accepted, and says so', () => {
  const rig = harness();
  const key = Buffer.alloc(4);
  key.writeUInt32BE(0xdeadbeef);
  rig.session.accept(
    reliableDatagram({ opcode: LOBBY_OPCODE.AREA_ENTER, sequence: 0, payload: key })
  );
  const logged = rig.logs.find((entry) => entry.message === 'udp9090 lobby-area-enter');
  assert.equal(logged.fields.resolvedBox, null);
  assert.match(logged.fields.note, /matches no published area/);
});

/* ---- M-3: a full send window must not flood, and must not hide an ENTER --- */

/**
 * Fill the reliable send window so every later send is refused.
 *
 * The client never acknowledges here, so the 32-message window fills after 32
 * answered queries and everything past that is a `WINDOW_FULL` refusal - which
 * is the state the 2026-08-06 rig run was in when it produced 223 warn lines in
 * 12 seconds.
 */
function fillSendWindow(rig) {
  for (let sequence = 0; sequence < 64; sequence += 1) {
    rig.session.accept(reliableDatagram({
      opcode: LOBBY_OPCODE.NAME_QUERY, sequence,
      payload: ARCHIVE_NAME_QUERY.subarray(0x10, ARCHIVE_NAME_QUERY.length - 4)
    }));
  }
  assert.ok(rig.session.stats().sendRefusals > 0, 'the window is full and sends are refused');
}

test('a full send window logs the first refusal and then a bounded rollup', () => {
  const rig = harness();
  fillSendWindow(rig);
  const refused = rig.logs.filter((entry) =>
    entry.message === 'udp9090 lobby-name-query-reply-refused');
  // 32 refusals from the 64 queries: one line, not 32.
  assert.equal(rig.session.stats().sendRefusals, 32);
  assert.equal(refused.length, 1, 'the first refusal, then silence until the rollup');
  assert.equal(refused[0].fields.refusals, 1);
  assert.equal(refused[0].fields.code, 'WINDOW_FULL');
});

test('the rollup line carries the running count so nothing is lost to suppression', () => {
  const rig = harness();
  // 132 queries: 32 answered, then 100 refused - which is exactly one rollup.
  for (let sequence = 0; sequence < 132; sequence += 1) {
    rig.session.accept(reliableDatagram({
      opcode: LOBBY_OPCODE.NAME_QUERY, sequence,
      payload: ARCHIVE_NAME_QUERY.subarray(0x10, ARCHIVE_NAME_QUERY.length - 4)
    }));
  }
  const refused = rig.logs.filter((entry) =>
    entry.message === 'udp9090 lobby-name-query-reply-refused');
  assert.equal(rig.session.stats().sendRefusals, 100);
  assert.deepEqual(refused.map((entry) => entry.fields.refusals), [1, 100]);
  assert.equal(refused[1].fields.suppressed, 99);
});

test('an ENTER refused by a full window is loud, and distinguishable from a poll refusal', () => {
  const rig = harness();
  fillSendWindow(rig);
  const before = rig.logs.length;
  const key = Buffer.alloc(4);
  key.writeUInt32BE(7);
  const [outcome] = rig.session.accept(
    reliableDatagram({ opcode: LOBBY_OPCODE.AREA_ENTER, sequence: 64, payload: key })
  ).handled;
  assert.equal(outcome.answered, false);
  const after = rig.logs.slice(before);
  // Its own event name, so it can never be read as one more op-0x48 refusal...
  const refusal = after.find((entry) =>
    entry.message === 'udp9090 lobby-area-enter-accept-refused');
  assert.ok(refusal, 'the ENTER refusal has its own journal line');
  assert.equal(refusal.level, 'warn');
  // ...and the ENTER's own line says what it cost, at warn rather than info.
  const entered = after.find((entry) => entry.message === 'udp9090 lobby-area-enter');
  assert.equal(entered.level, 'warn');
  assert.equal(entered.fields.answered, false);
  assert.match(entered.fields.note, /lobby will not appear/);
});

test('every ENTER refusal is logged, because the client only ever asks once', () => {
  const rig = harness();
  fillSendWindow(rig);
  const key = Buffer.alloc(4);
  key.writeUInt32BE(7);
  for (let sequence = 64; sequence < 67; sequence += 1) {
    rig.session.accept(reliableDatagram({
      opcode: LOBBY_OPCODE.AREA_ENTER, sequence, payload: key
    }));
  }
  const refused = rig.logs.filter((entry) =>
    entry.message === 'udp9090 lobby-area-enter-accept-refused');
  assert.deepEqual(refused.map((entry) => entry.fields.refusals), [1, 2, 3]);
});

test('a runt op-0x48 cannot throw out of the datagram handler', () => {
  /*
   * B-1 from the 2026-08-06 review, and it was the one defect that would have
   * taken the whole server down.
   *
   * A 16-byte datagram whose op-0x48 payload is shorter than the 8-byte header
   * threw NAME_QUERY_TOO_SHORT out of `accept`, out of the UDP 'message'
   * listener, and into `bin/pal-server-v2.js`, which stops every listener and
   * exits 1. With `Restart=always` in the unit file that is a
   * drop-every-player restart loop, from one datagram, from an unauthenticated
   * source. The class comment claimed "never throws on peer input"; it did.
   *
   * The parser is still strict - a runt query IS malformed and refusing it is
   * right. What changed is that the refusal stays inside the session.
   */
  for (const payload of [
    Buffer.alloc(0),
    Buffer.alloc(1),
    Buffer.alloc(7)            // one byte short of the header
  ]) {
    const rig = harness();
    let result;
    assert.doesNotThrow(() => {
      result = rig.session.accept(reliableDatagram({
        opcode: LOBBY_OPCODE.NAME_QUERY, sequence: 0, payload
      }));
    }, `a ${payload.length}-byte NAME query must not throw`);
    assert.ok(
      result.refusals.some((refusal) => refusal.code === 'HANDLER_THREW'),
      'and it is reported as a refusal rather than swallowed'
    );
    assert.equal(rig.session.closed, false, 'the session survives it');
  }
});

test('a handler that throws still leaves the session able to serve the next message', () => {
  // The guard must not wedge the stream: a refused message is dropped, and the
  // NEXT well-formed one is answered normally.
  const rig = harness();
  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.NAME_QUERY, sequence: 0, payload: Buffer.alloc(3)
  }));
  const before = rig.sent.length;
  // The NEXT sequence, so the ordered stream is not the thing under test - a
  // well-formed query with an empty entry list.
  const result = rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.NAME_QUERY, sequence: 1, payload: Buffer.alloc(8)
  }));
  assert.equal(result.handled.length, 1, 'the next query is delivered, not wedged behind the runt');
  assert.ok(rig.sent.length > before, 'and answered');
});

test('the cmd-0x14 RTT probe is absorbed without an error or a warning', () => {
  const rig = harness();
  const before = rig.sent.length;
  // Non-reliable, 68 bytes, 0x55 filler - FUN_005bcc30's bandwidth probe.
  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.RTT_PROBE, sequence: 0, flags: 0x3000, payload: Buffer.alloc(0x30, 0x55)
  }));
  assert.equal(rig.sent.slice(before).length, 0, 'non-reliable: nothing to acknowledge');
  assert.equal(rig.logs.filter((entry) => entry.level === 'warn').length, 0);
  assert.ok(rig.logs.some((entry) => entry.message === 'udp9090 lobby-rtt-probe'));
});

test('the re-entry op-0x0d is answered with selector 0x0d and nothing else', () => {
  const rig = harness();
  const before = rig.sent.length;
  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.REENTRY_QUERY, sequence: 0, sub: 5, payload: Buffer.from('f7e00001', 'hex')
  }));
  const [, completion] = rig.sent.slice(before);
  assert.deepEqual(
    completion.datagram.subarray(0x10, 0x18), Buffer.from('0000000d00000000', 'hex'));
});

test('the op-0x29 success transition is off by default and refuses to be sent', () => {
  // It has NEVER been captured - it is reconstructed from the disassembly at
  // 1daf7c-1db01c alone - and the keepalive defers 840 indefinitely without it.
  const rig = harness();
  rig.session.accept(ARCHIVE_NAME_QUERY);
  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.ROOM_QUERY, sequence: 1, payload: Buffer.alloc(0xf0)
  }));
  assert.equal(rig.of('reliable', LOBBY_OPCODE.SUCCESS_TRANSITION).length, 0);
  assert.equal(rig.session.stats().successTransitionSent, false);
  assert.throws(
    () => rig.session.sendSuccessTransition(),
    (error) => error.code === 'SUCCESS_TRANSITION_DISABLED'
  );
});

test('enabled, the op-0x29 carries the token reversed and clears the DATA bit', () => {
  const rig = harness({ sessions: { successTransition: true } });
  rig.session.sendSuccessTransition();
  const [transition] = rig.of('reliable', LOBBY_OPCODE.SUCCESS_TRANSITION);
  // who 0xa01c: RELIABLE | SET with the DATA bit clear, and 28 bytes of message.
  assert.equal(transition.datagram.readUInt16BE(0), 0xa01c);
  // body +0x00 = 0 so FUN_001d507c skips the port write; +0x08 = the token in
  // reverse, which the client compares against its own byte-reversed copy.
  assert.equal(transition.datagram.readUInt32BE(0x10), 0);
  assert.deepEqual(transition.datagram.subarray(0x18, 0x1c), Buffer.from('d007f802', 'hex'));
  assert.equal(rig.session.stats().successTransitionSent, true);
});

test('the outbound stamped sequence is monotonic across every answered request', () => {
  const rig = harness();
  rig.session.accept(ARCHIVE_NAME_QUERY);
  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.ROOM_QUERY, sequence: 1, payload: Buffer.alloc(0xf0)
  }));
  rig.session.accept(reliableDatagram({ opcode: LOBBY_OPCODE.ROOM_LIST, sequence: 2 }));
  assert.deepEqual(
    rig.sent.filter((entry) => entry.kind === 'reliable').map((entry) => entry.sequence),
    [1, 2, 3]
  );
});

test('closing a session cancels every timer it and its channel own', () => {
  const rig = harness();
  rig.session.accept(ARCHIVE_NAME_QUERY);
  assert.ok(rig.wheel.size > 0);
  assert.equal(rig.table.close(ROUTING_KEY), true);
  // assertOwnerDrained is called inside close() and throws on a leak, so
  // reaching here IS the assertion; this states it for a reader.
  assert.equal(rig.wheel.countForOwner(rig.session), 0);
  assert.equal(rig.wheel.countForOwner(rig.session.channel), 0);
  assert.equal(rig.table.size, 0);
});

test('a closed session stops sending keepalives', () => {
  const rig = harness();
  rig.table.close(ROUTING_KEY);
  const before = rig.of('unreliable', LOBBY_OPCODE.KEEPALIVE).length;
  rig.run(30_000);
  assert.equal(rig.of('unreliable', LOBBY_OPCODE.KEEPALIVE).length, before);
  assert.deepEqual(rig.wheelErrors, []);
});

test('re-opening the same routing key replaces the epoch and leaks nothing', () => {
  const rig = harness();
  const first = rig.session;
  rig.session.accept(ARCHIVE_NAME_QUERY);
  const second = rig.table.open({
    routingKey: ROUTING_KEY,
    loginIdentity: '12345',
    endpointToken: TOKEN,
    outboundSequence: 1,
    latencyTicks: 1600,
    transmit: () => {}
  });
  assert.notEqual(second, first);
  assert.equal(rig.table.size, 1);
  assert.equal(rig.wheel.countForOwner(first), 0);
  assert.equal(rig.wheel.countForOwner(first.channel), 0);
});

test('a session that hears nothing for the idle timeout is released with its timers', () => {
  const rig = harness({ sessions: { idleTimeoutMs: 60_000 } });
  rig.run(50_000);
  assert.equal(rig.table.size, 1, 'still inside the timeout');
  rig.run(80_000);
  assert.equal(rig.table.size, 0);
  assert.equal(rig.wheel.countForOwner(rig.session), 0);
  assert.equal(rig.wheel.countForOwner(rig.session.channel), 0);
  assert.ok(rig.logs.some((entry) => entry.message === 'udp9090 lobby-session-idle'));
});

test('traffic inside the window re-arms the idle release instead of ending the session', () => {
  const rig = harness({ sessions: { idleTimeoutMs: 60_000 } });
  for (let step = 0; step < 5; step += 1) {
    rig.run(40_000);
    // The client's ~25/s Area-Select poll, thinned to one datagram per window.
    rig.session.accept(
      reliableDatagram({ opcode: LOBBY_OPCODE.KEEPALIVE_RESPONSE, sequence: step }));
  }
  assert.equal(rig.table.size, 1);
  assert.ok(rig.of('unreliable', LOBBY_OPCODE.KEEPALIVE).length > 30);
});

test('an idle timeout at or below the keepalive period is refused', () => {
  const rig = harness({ sessions: { keepalivePeriodMs: 5_000, idleTimeoutMs: 5_000 } });
  assert.equal(rig.session, null);
  const refused = rig.logs.find((entry) => entry.message === 'udp9090 lobby-session-refused');
  assert.equal(refused.fields.code, 'IDLE_TIMEOUT');
});

test('the keepalive key has no default: omitting it is refused at construction', () => {
  assert.throws(
    () => new SnapLobbySessions({
      wheel: new TimingWheel({ onError: () => {} }),
      areaDirectory: createV1ObservedAreaDirectory()
    }),
    (error) => error instanceof SnapLobbySessionsError && error.code === 'KEEPALIVE_KEY_REQUIRED'
  );
});

test('the session table refuses a new session at capacity rather than evicting one', () => {
  const rig = harness({ sessions: { maximumSessions: 1 } });
  const second = rig.table.open({
    routingKey: '10.0.0.9:2000',
    loginIdentity: 'other',
    endpointToken: 0x0a000009,
    outboundSequence: 1,
    latencyTicks: 1600,
    transmit: () => {}
  });
  assert.equal(second, null);
  assert.equal(rig.table.get(ROUTING_KEY), rig.session);
});

test('identity comes from the registration, never from the source address', () => {
  const rig = harness({ open: { loginIdentity: 'proven-by-the-nonce' } });
  assert.equal(rig.session.loginIdentity, 'proven-by-the-nonce');
  assert.throws(
    () => rig.table.open({
      routingKey: '10.0.0.9:2000',
      endpointToken: 1,
      outboundSequence: 1,
      transmit: () => {}
    }) ?? (() => { throw new Error('unreachable'); })(),
    /a lobby session carries the identity its registration proved|unreachable/
  );
});

test('the SAME account binding from a second address closes the first session', () => {
  /*
   * The defect this pins was silent and untestable from the outside: the
   * identity->routing-key map was DECLARED and READ, but never written. Every
   * lookup returned undefined, so displacement closed nothing and the branch
   * that closes the orphan was dead code that still read as implemented.
   *
   * Nothing else in the suite could catch it. `close(routingKey)` only reaches a
   * session at the same address and port, and a second console arrives on a
   * different one - so the orphan simply stayed live and every existing test
   * still passed. Hence a test that asserts the OLD session is gone, not merely
   * that the new one exists.
   *
   * The behaviour is also the stated rule: one account on two devices
   * disconnects the first, as every game does.
   */
  const rig = harness();
  const first = rig.session;
  assert.equal(rig.table.get(ROUTING_KEY) != null, true, 'the first session is live');

  const second = rig.table.open({
    routingKey: '192.0.2.249:2000',
    loginIdentity: '12345',
    endpointToken: TOKEN,
    outboundSequence: 1,
    inboundReceiveBase: 0,
    latencyTicks: 1600,
    transmit: () => {}
  });

  assert.notEqual(second, first, 'a distinct session was opened for the second address');
  assert.equal(rig.table.get(ROUTING_KEY), null,
    'the displaced session must be CLOSED, not merely have its presence detached: an orphan ' +
    'still routes datagrams, and every op-0x06/op-0x07 on it throws PRESENCE_DETACHED before ' +
    'it can reply, so that console stalls with no completion');
  assert.equal(rig.table.get('192.0.2.249:2000'), second, 'the survivor is the new session');

  // Exactly one presence for the identity, at the new session - never two, and
  // never zero because detach ran after the close.
  assert.equal(rig.table.presence.get('12345'), second.presence);
});
