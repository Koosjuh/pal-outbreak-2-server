import assert from 'node:assert/strict';
import test from 'node:test';

import {
  FLAG_ACK,
  FLAG_AGGREGATE,
  FLAG_DATA,
  FLAG_RELIABLE,
  FLAG_SET,
  encodeSegment,
  SNAP_TRAILER
} from '../src/protocol/snap-codec.js';
import {
  CHANNEL_DEATH,
  ReliableChannel,
  ReliableChannelError
} from '../src/transport/reliable-channel.js';
import { TimingWheel } from '../src/transport/timing-wheel.js';

/**
 * One session's transport: the reliable window, the ordered receive stream and
 * the ack policy.
 *
 * Nothing here sleeps. The timing wheel's clock and interval are injected, so
 * "1.62 s passed" is stated as a fact - which is the only way the 48-retry cap
 * (about 313 s of backoff) is testable at all.
 */

const TOKEN = Buffer.from('028107d0', 'hex');
const OTHER_TOKEN = Buffer.from('deadbeef', 'hex');

function harness({ tickMs = 100, channel: channelOptions = {}, ...wheelOptions } = {}) {
  let nowMs = 1_000;
  let token = null;
  const wheelErrors = [];
  const wheel = new TimingWheel({
    tickMs,
    clock: () => nowMs,
    setInterval: (fn) => { token = { fn, unref() {} }; return token; },
    clearInterval: () => { token = null; },
    onError: (report) => wheelErrors.push(report),
    ...wheelOptions
  });
  wheel.start();

  const sent = [];
  const deaths = [];
  const channel = new ReliableChannel({
    token: TOKEN,
    wheel,
    transmit: (datagram, context) => sent.push({ datagram, ...context }),
    onTransportDead: (report) => deaths.push(report),
    ...channelOptions
  });

  return {
    wheel,
    channel,
    sent,
    deaths,
    wheelErrors,
    nowMs: () => nowMs,
    advanceMs(ms) { nowMs += ms; token?.fn(); },
    advanceTicks(count) { for (let index = 0; index < count; index += 1) this.advanceMs(tickMs); },
    /** Deliver ticks until at least `ms` of injected time has passed. */
    run(ms) { this.advanceTicks(Math.ceil(ms / tickMs)); }
  };
}

function datagramOf(...segments) {
  return Buffer.concat([...segments, SNAP_TRAILER]);
}

function clientMessage({
  sequence, opcode = 0x06, reliable = true, payload = Buffer.alloc(0), token = TOKEN,
  acknowledgement = 0, flags = FLAG_SET | FLAG_DATA
}) {
  return encodeSegment({
    flags: flags | (reliable ? FLAG_RELIABLE : 0),
    opcode,
    token,
    sequence,
    acknowledgement,
    payload
  });
}

const reliableDatagram = (sequence, opcode = 0x06) =>
  datagramOf(clientMessage({ sequence, opcode, payload: Buffer.from([sequence & 0xff]) }));

const unreliableDatagram = (sequence, opcode = 0x41) =>
  datagramOf(clientMessage({ sequence, opcode, reliable: false, payload: Buffer.from([1]) }));

/** The client's own ack shape: 0x6010, no data, acked id at +0x0c. */
const ackDatagram = (acknowledgement) =>
  datagramOf(encodeSegment({
    flags: FLAG_ACK | FLAG_SET, token: TOKEN, sequence: 0, acknowledgement
  }));

function seededChannel(rig, sequence = 100) {
  rig.channel.seedStampedSequence(sequence);
  return rig.channel;
}

/* ---- ordered inbound delivery ----------------------------------------- */

test('reliable messages arriving in order are delivered as they land', () => {
  const rig = harness({ channel: { inboundReceiveBase: 3 } });
  const first = rig.channel.acceptDatagram(reliableDatagram(3, 0x06));
  const second = rig.channel.acceptDatagram(reliableDatagram(4, 0x09));

  assert.deepEqual(first.delivered.map((message) => message.sequence), [3]);
  assert.deepEqual(second.delivered.map((message) => message.opcode), [0x09]);
  assert.equal(rig.channel.receiveBase, 5);
  assert.equal(rig.channel.gapSize, 0);
});

test('a message ahead of the base is buffered and delivered nothing until the hole fills', () => {
  const rig = harness({ channel: { inboundReceiveBase: 3 } });

  const ahead = rig.channel.acceptDatagram(reliableDatagram(5));
  assert.deepEqual(ahead.delivered, [], 'strictly in order: 5 cannot pass 3');
  assert.deepEqual(ahead.bufferedSequences, [5]);
  assert.equal(rig.channel.receiveBase, 3);

  rig.channel.acceptDatagram(reliableDatagram(4));
  assert.deepEqual(rig.channel.gapSequences(), [4, 5]);

  const fill = rig.channel.acceptDatagram(reliableDatagram(3));
  assert.deepEqual(
    fill.delivered.map((message) => message.sequence), [3, 4, 5],
    'the hole releases the whole contiguous run in one cascade'
  );
  assert.equal(rig.channel.receiveBase, 6);
  assert.equal(rig.channel.gapSize, 0);
});

test('a reliable duplicate below the base is dropped but still acknowledged', () => {
  const rig = harness({ channel: { inboundReceiveBase: 3 } });
  rig.channel.acceptDatagram(reliableDatagram(3));

  const duplicate = rig.channel.acceptDatagram(reliableDatagram(3));
  assert.deepEqual(duplicate.delivered, [], 'delivered once, not twice');
  assert.deepEqual(duplicate.duplicates.map((message) => message.sequence), [3]);
  // Withholding this ack is what makes the peer retransmit 48 times and then die
  // in silence, so the duplicate is acked precisely because it is a duplicate.
  assert.equal(duplicate.acknowledgements.length, 1);
  const ack = duplicate.acknowledgements[0];
  assert.equal(ack.readUInt32BE(0x0c), 3);
});

test('a retransmission of a buffered out-of-order message is acked and not buffered twice', () => {
  const rig = harness({ channel: { inboundReceiveBase: 3 } });
  rig.channel.acceptDatagram(reliableDatagram(4));
  const again = rig.channel.acceptDatagram(reliableDatagram(4));

  assert.deepEqual(again.bufferedSequences, []);
  assert.deepEqual(again.duplicates.map((message) => message.sequence), [4]);
  assert.equal(again.acknowledgements.length, 1);
  assert.equal(rig.channel.gapSize, 1);
});

/* ---- unreliable inbound ------------------------------------------------ */

test('an unreliable message at an EQUAL sequence is delivered again, not suppressed', () => {
  const rig = harness();
  const first = rig.channel.acceptDatagram(unreliableDatagram(100));
  const repeat = rig.channel.acceptDatagram(unreliableDatagram(100));

  // `conn+0x10 <= seq` (FUN_001d6988.c:25) - the client redelivers an equal
  // sequence, which is why an outbound unreliable counter must always increment.
  assert.deepEqual(first.delivered.map((message) => message.sequence), [100]);
  assert.deepEqual(repeat.delivered.map((message) => message.sequence), [100]);
  assert.equal(repeat.acknowledgements.length, 0, 'unreliable messages are never acked');
});

test('an unreliable message below the high water is dropped and does not move the reliable base', () => {
  const rig = harness({ channel: { inboundReceiveBase: 9 } });
  rig.channel.acceptDatagram(unreliableDatagram(100));
  const older = rig.channel.acceptDatagram(unreliableDatagram(99));

  assert.deepEqual(older.delivered, []);
  assert.deepEqual(older.duplicates.map((message) => message.sequence), [99]);
  assert.equal(rig.channel.receiveBase, 9);
});

test('a bare transport ack is consumed as an ack and never handed to the application', () => {
  const rig = harness();
  const channel = seededChannel(rig, 40);
  const { sequence } = channel.sendReliable({ opcode: 0x28 });

  const result = channel.acceptDatagram(ackDatagram(sequence));
  assert.deepEqual(result.delivered, [], 'the 20-byte husk is transport-only');
  assert.equal(result.transportOnly.length, 1);
  assert.equal(channel.unacknowledgedCount, 0, 'and it freed the in-flight message');
});

/* ---- the ack policy ---------------------------------------------------- */

test('one inbound datagram produces exactly one ack datagram, of the proven 20-byte shape', () => {
  const rig = harness({ channel: { inboundReceiveBase: 7 } });
  const result = rig.channel.acceptDatagram(reliableDatagram(7, 0x48));

  assert.equal(result.acknowledgements.length, 1);
  const ack = result.acknowledgements[0];
  assert.equal(ack.length, 20);
  assert.equal(ack.readUInt16BE(0), 0x6010, 'CARRIES_ACK|SET|len: not reliable, consumes no sequence');
  assert.deepEqual(ack.subarray(4, 8), TOKEN);
  assert.equal(ack.readUInt32BE(8), 0, 'the ack carries no sequence of its own');
  assert.equal(ack.readUInt32BE(0x0c), 7, 'exact id, because FUN_001e1ac8 matches exactly');
  assert.deepEqual(ack.subarray(16), SNAP_TRAILER);
  assert.deepEqual(
    rig.sent.map((entry) => entry.kind), ['ack'],
    'and it left through transmit, not just the return value'
  );
});

test('a batched datagram cannot amplify acks: 60 segments are refused WHOLE', () => {
  /*
   * The audit case: 60 segments in one datagram used to produce 60 ack datagrams.
   *
   * SUPERSEDED 2026-08-08: this used to assert "1 ack, outer frame only, sub-frames
   * never parsed", because walking was off entirely. Walking is now on (the create
   * path batches three one-shot queries that must all be answered), so the
   * amplification guarantee is enforced by the per-datagram BOUND instead of by
   * refusing to parse - and the bound is strictly stronger here: 60 > 8, so the
   * datagram is refused whole and costs ZERO acks rather than one.
   *
   * The property under test is unchanged and is the one that matters: a peer
   * cannot command a large ack fan-out from a single datagram.
   */
  const segments = [];
  for (let index = 0; index < 60; index += 1) {
    segments.push(clientMessage({
      sequence: 10 + index, flags: FLAG_SET | FLAG_DATA | (index === 0 ? FLAG_AGGREGATE : 0)
    }));
  }
  const rig = harness({ channel: { inboundReceiveBase: 10 } });
  const result = rig.channel.acceptDatagram(datagramOf(...segments));

  assert.equal(result.acknowledgements.length, 0, 'no amplification: the datagram is refused whole');
  assert.deepEqual(result.delivered, [], 'nothing from a refused datagram is delivered');
  assert.deepEqual(
    result.refusals.map((refusal) => refusal.code), ['TOO_MANY_MESSAGES'],
    'the BOUND is what caps the fan-out, and it fails closed rather than clamping'
  );
});

test('a reliable sub-message rides the covering acceptance; its seq field is dead weight', () => {
  /*
   * SUPERSEDED 2026-08-08 (B2 join freeze): this used to assert the sub-message
   * was classified a DUPLICATE because its sequence field repeated the outer's.
   * The client never reads that field behind a reliable outer
   * (`FUN_001d6988.c:44-88`: every reliable sub is gated on `uStack_30`, the
   * OUTER sequence, and acked once on it), so treating the unstamped field as a
   * real sequence dropped live queries. The sub now rides the outer: delivered
   * with it, never a duplicate of it. Its own id is still acked (the restored
   * pre-branch emission, 2026-08-08 nora fix 1) - here it repeats the outer's,
   * so the dedup collapses both to ONE ack.
   */
  const rig = harness({ channel: { inboundReceiveBase: 4, walkBatchedMessages: true } });
  const result = rig.channel.acceptDatagram(datagramOf(
    clientMessage({ sequence: 4, flags: FLAG_SET | FLAG_DATA | FLAG_AGGREGATE }),
    clientMessage({ sequence: 4 })
  ));

  assert.equal(result.acknowledgements.length, 1, 'covering id == rider id: deduplicated');
  assert.equal(result.acknowledgements[0].readUInt32BE(0x0c), 4);
  assert.deepEqual(result.delivered.map((message) => message.sequence), [4, 4]);
  assert.deepEqual(result.duplicates, [], 'a rider is not a duplicate of its covering message');
});

/* ---- MORE_MESSAGES ----------------------------------------------------- */

test('trailing messages are only walked when the FIRST message sets MORE_MESSAGES', () => {
  const rig = harness({ channel: { inboundReceiveBase: 1, walkBatchedMessages: true } });
  // FUN_001d6988.c:44 gates the walk on the first message's 0x0800; without it
  // the client ignores the rest, so the server does too.
  const undeclared = rig.channel.acceptDatagram(datagramOf(
    clientMessage({ sequence: 1 }),
    clientMessage({ sequence: 2 })
  ));
  assert.deepEqual(undeclared.delivered.map((message) => message.sequence), [1]);
  assert.deepEqual(undeclared.refusals.map((refusal) => refusal.code), ['BATCH_NOT_WALKED']);
  assert.equal(rig.channel.receiveBase, 2);

  const declared = rig.channel.acceptDatagram(datagramOf(
    clientMessage({ sequence: 2, flags: FLAG_SET | FLAG_DATA | FLAG_AGGREGATE }),
    clientMessage({ sequence: 3 })
  ));
  assert.deepEqual(declared.delivered.map((message) => message.sequence), [2, 3]);
  assert.deepEqual(declared.refusals, []);
});

test('every datagram this channel emits carries one message and never sets MORE_MESSAGES', () => {
  const rig = harness();
  const channel = seededChannel(rig, 5);
  channel.sendReliable({ opcode: 0x28, payload: Buffer.alloc(8) });
  channel.sendUnreliable({ opcode: 0x40, payload: Buffer.alloc(4) });
  channel.acceptDatagram(reliableDatagram(0));

  for (const { datagram } of rig.sent) {
    const flagsAndLength = datagram.readUInt16BE(0);
    assert.equal(flagsAndLength & FLAG_AGGREGATE, 0, 'a wrong 0x0800 aborts the segment un-acked');
    assert.equal(
      (flagsAndLength & 0x03ff) + SNAP_TRAILER.length, datagram.length,
      'the declared length reaches exactly the trailer: one message per datagram'
    );
  }
});

test('a caller that asks for MORE_MESSAGES is refused rather than quietly corrected', () => {
  const rig = harness();
  const channel = seededChannel(rig, 5);
  assert.throws(
    () => channel.sendReliable({ opcode: 0x28, flags: FLAG_SET | FLAG_DATA | FLAG_AGGREGATE }),
    (error) => error instanceof ReliableChannelError && error.code === 'AGGREGATE_UNSUPPORTED'
  );
  assert.equal(channel.nextStampedSequence, 5, 'and the refused send burned no sequence');
});

/* ---- the bounds -------------------------------------------------------- */

test('the gap buffer refuses past its bound, keeps what it holds, and withholds that one ack', () => {
  const rig = harness({ channel: { inboundReceiveBase: 0, maximumGapEntries: 3 } });
  for (const sequence of [1, 2, 3]) rig.channel.acceptDatagram(reliableDatagram(sequence));
  assert.deepEqual(rig.channel.gapSequences(), [1, 2, 3]);

  const refused = rig.channel.acceptDatagram(reliableDatagram(4));
  assert.deepEqual(refused.refusals.map((refusal) => refusal.code), ['GAP_FULL']);
  assert.deepEqual(
    refused.acknowledgements, [],
    'unacknowledged on purpose: the peer must retransmit what there is no room to hold'
  );
  assert.deepEqual(rig.channel.gapSequences(), [1, 2, 3], 'nothing already acked was evicted');
});

test('the gap bound is not a ratchet: room freed by the cascade is usable again', () => {
  const rig = harness({ channel: { inboundReceiveBase: 0, maximumGapEntries: 2 } });
  rig.channel.acceptDatagram(reliableDatagram(1));
  rig.channel.acceptDatagram(reliableDatagram(2));
  rig.channel.acceptDatagram(reliableDatagram(0));
  assert.equal(rig.channel.receiveBase, 3);

  const later = rig.channel.acceptDatagram(reliableDatagram(4));
  assert.deepEqual(later.bufferedSequences, [4]);
});

test('an unfilled hole expires into a terminal state instead of pinning memory forever', () => {
  const rig = harness({ channel: { inboundReceiveBase: 0, gapExpiryMs: 5_000 } });
  rig.channel.acceptDatagram(reliableDatagram(1));
  assert.equal(rig.channel.gapSize, 1);

  rig.run(4_900);
  assert.equal(rig.channel.dead, null, 'still waiting for the peer to fill the hole');

  rig.run(200);
  assert.equal(rig.channel.dead.reason, CHANNEL_DEATH.GAP_ABANDONED);
  assert.deepEqual(rig.channel.dead.detail, { receiveBase: 0, buffered: [1] });
  assert.equal(rig.deaths.length, 1, 'loud, not a silent eviction');
  assert.equal(rig.channel.gapSize, 0);
  assert.doesNotThrow(() => rig.wheel.assertOwnerDrained(rig.channel));
});

test('progress restarts the hole clock rather than killing a busy but healthy stream', () => {
  const rig = harness({ channel: { inboundReceiveBase: 0, gapExpiryMs: 5_000 } });
  rig.channel.acceptDatagram(reliableDatagram(1));
  rig.run(4_000);
  // 0 arrives, 1 is released, and 2 opens a NEW hole - the clock is for the
  // current hole, not for "the buffer has been non-empty for a while".
  rig.channel.acceptDatagram(reliableDatagram(0));
  rig.channel.acceptDatagram(reliableDatagram(3));
  rig.run(4_000);
  assert.equal(rig.channel.dead, null);

  rig.run(1_100);
  assert.equal(rig.channel.dead.reason, CHANNEL_DEATH.GAP_ABANDONED);
});

test('a segment is refused rather than buffered when the wheel will not hold its expiry timer', () => {
  // The buffer and its expiry timer are one resource. If the shared wheel is at
  // its per-owner bound, buffering anyway would pin the entry for the life of
  // the session with nothing able to expire it.
  const rig = harness({ maximumEntriesPerOwner: 1, channel: { inboundReceiveBase: 0 } });
  const channel = seededChannel(rig, 0);
  channel.sendReliable({ opcode: 0x28 });

  const result = channel.acceptDatagram(reliableDatagram(4));
  assert.deepEqual(result.refusals.map((refusal) => refusal.code), ['TIMER_CAPACITY']);
  assert.deepEqual(result.acknowledgements, [], 'unacknowledged, so the peer retransmits it');
  assert.equal(channel.gapSize, 0);
});

test('the per-datagram message bound refuses the datagram WHOLE, delivering nothing', () => {
  const segments = [clientMessage({ sequence: 0, flags: FLAG_SET | FLAG_DATA | FLAG_AGGREGATE })];
  for (let index = 1; index < 4; index += 1) segments.push(clientMessage({ sequence: index }));

  const rig = harness({
    channel: { inboundReceiveBase: 0, walkBatchedMessages: true, maximumMessagesPerDatagram: 3 }
  });
  const result = rig.channel.acceptDatagram(datagramOf(...segments));

  assert.deepEqual(result.refusals.map((refusal) => refusal.code), ['TOO_MANY_MESSAGES']);
  assert.deepEqual(result.delivered, []);
  assert.deepEqual(result.acknowledgements, [], 'the bound is also the ack fan-out ceiling');
  assert.equal(rig.channel.receiveBase, 0, 'atomic: nothing from the datagram moved any state');
});

test('the outbound window refuses a send past its bound instead of growing a backlog', () => {
  const rig = harness({ channel: { maximumUnacknowledged: 2 } });
  const channel = seededChannel(rig, 0);
  channel.sendReliable({ opcode: 0x28 });
  channel.sendReliable({ opcode: 0x28 });

  assert.throws(
    () => channel.sendReliable({ opcode: 0x28 }),
    (error) => error.code === 'WINDOW_FULL'
  );
  assert.equal(channel.unacknowledgedCount, 2);

  channel.acceptDatagram(ackDatagram(0));
  assert.doesNotThrow(() => channel.sendReliable({ opcode: 0x28 }));
});

/* ---- framing ----------------------------------------------------------- */

test('the trailer is validated on its top three bytes only, as the client validates it', () => {
  const rig = harness({ channel: { inboundReceiveBase: 0 } });
  // FUN_001d72a8 byteswaps the trailing u32 and compares to 0xba476600 - the low
  // byte is masked off, so a client datagram differing there must still be taken.
  const datagram = reliableDatagram(0);
  datagram[datagram.length - 1] = 0x99;
  const accepted = rig.channel.acceptDatagram(datagram);
  assert.deepEqual(accepted.delivered.map((message) => message.sequence), [0]);

  datagram[datagram.length - 2] = 0x00;
  const refused = rig.channel.acceptDatagram(datagram);
  assert.deepEqual(refused.refusals.map((refusal) => refusal.code), ['BAD_TRAILER']);
});

test('a datagram carrying another session token is refused whole', () => {
  const rig = harness({ channel: { inboundReceiveBase: 0 } });
  const result = rig.channel.acceptDatagram(
    datagramOf(clientMessage({ sequence: 0, token: OTHER_TOKEN }))
  );
  assert.deepEqual(result.refusals.map((refusal) => refusal.code), ['TOKEN_MISMATCH']);
  assert.deepEqual(result.acknowledgements, []);
  assert.equal(rig.channel.receiveBase, 0);
});

test('short and misdeclared datagrams are refused by name, never thrown at the caller', () => {
  const rig = harness();
  const short = rig.channel.acceptDatagram(Buffer.alloc(12));
  assert.deepEqual(short.refusals.map((refusal) => refusal.code), ['SHORT_DATAGRAM']);

  // A declared length that overruns the trailer: the FUN_001d72a8 length guard.
  const overlong = datagramOf(clientMessage({ sequence: 0 }));
  overlong.writeUInt16BE((overlong.readUInt16BE(0) & 0xfc00) | 0x3ff, 0);
  const result = rig.channel.acceptDatagram(overlong);
  assert.deepEqual(result.refusals.map((refusal) => refusal.code), ['BAD_LENGTH']);
});

/* ---- mirror versus stamp ----------------------------------------------- */

test('a stamped reliable reply consumes the session counter and a mirrored push does not', () => {
  const rig = harness();
  const channel = seededChannel(rig, 200);

  const stamped = channel.sendReliable({ opcode: 0x28, payload: Buffer.alloc(4) });
  const mirrored = channel.sendMirrored({ opcode: 0x28, subSelector: 1, sequence: 0x0e0c });
  const next = channel.sendReliable({ opcode: 0x10 });

  assert.equal(stamped.sequence, 200);
  assert.equal(mirrored.sequence, 0x0e0c, 'the push echoes the message it answers');
  assert.equal(next.sequence, 201, 'the mirror did not advance the counter');
  assert.equal(channel.nextStampedSequence, 202);
  assert.deepEqual(
    rig.sent.map((entry) => entry.kind), ['reliable', 'mirrored', 'reliable'],
    'and the two are distinguishable to whatever logs them'
  );
});

test('two live reliable messages may never share a sequence', () => {
  const rig = harness();
  const channel = seededChannel(rig, 300);
  channel.sendReliable({ opcode: 0x28 });

  // The client would enqueue both, deliver one, and leak the twin's pool buffer.
  assert.throws(
    () => channel.sendMirrored({ opcode: 0x28, sequence: 300 }),
    (error) => error.code === 'SEQUENCE_IN_FLIGHT'
  );
  channel.acceptDatagram(ackDatagram(300));
  assert.doesNotThrow(() => channel.sendMirrored({ opcode: 0x28, sequence: 300 }));
});

test('an unseeded stamped counter refuses to send rather than starting at zero', () => {
  const rig = harness();
  // Zero would sit below the client's recvBase, where FUN_001d6988 frees the
  // reply un-acked and the application simply never sees it.
  assert.throws(
    () => rig.channel.sendReliable({ opcode: 0x28 }),
    (error) => error.code === 'SEQUENCE_UNSEEDED'
  );
  assert.doesNotThrow(() => rig.channel.sendMirrored({ opcode: 0x28, sequence: 12 }));
});

test('the unreliable counter always increments, including across a repeat of the same body', () => {
  const rig = harness({ channel: { unreliableSequence: 7 } });
  const first = rig.channel.sendUnreliable({ opcode: 0x40 });
  const second = rig.channel.sendUnreliable({ opcode: 0x40 });

  assert.deepEqual([first.sequence, second.sequence], [7, 8]);
  assert.equal(
    rig.sent[0].datagram.readUInt16BE(0) & FLAG_RELIABLE, 0,
    'unreliable: it consumes no reliable sequence and is never retransmitted'
  );
  assert.equal(rig.channel.unacknowledgedCount, 0);
});

/* ---- retransmission ---------------------------------------------------- */

test('an unacknowledged reliable message is retransmitted byte-identically after the RTO', () => {
  const rig = harness();
  const channel = seededChannel(rig, 50);
  const { datagram } = channel.sendReliable({ opcode: 0x28, payload: Buffer.from('body') });
  assert.equal(rig.sent.length, 1);

  rig.run(1_600);
  assert.equal(rig.sent.length, 1, 'not yet: the RTO is 1.62 s');

  rig.run(100);
  assert.equal(rig.sent.length, 2);
  assert.deepEqual(rig.sent[1].datagram, datagram, 'the same bytes, same sequence');
  assert.equal(rig.sent[1].retransmission, 1);
  assert.equal(channel.retransmissionsFor(50), 1);
});

test('the retransmission timeout rises by the backoff step on each retry', () => {
  const rig = harness();
  const channel = seededChannel(rig, 60);
  channel.sendReliable({ opcode: 0x28 });

  const firedAt = [];
  for (let retry = 0; retry < 3; retry += 1) {
    const before = rig.sent.length;
    while (rig.sent.length === before) rig.advanceTicks(1);
    firedAt.push(rig.nowMs());
  }
  const gaps = [firedAt[0] - 1_000, firedAt[1] - firedAt[0], firedAt[2] - firedAt[1]];
  // 1620, 1820 and 2020 ms, each rounded UP to the wheel's 100 ms resolution -
  // the wheel never fires early, so a deadline lands on the tick at or after it.
  assert.deepEqual(gaps, [1_700, 1_900, 2_100]);
  assert.equal(channel.retransmissionsFor(60), 3);
});

test('an exact-id ack stops that message being retransmitted and frees nothing else', () => {
  const rig = harness();
  const channel = seededChannel(rig, 70);
  channel.sendReliable({ opcode: 0x28 });
  channel.sendReliable({ opcode: 0x10 });
  assert.deepEqual(channel.unacknowledgedSequences(), [70, 71]);

  // FUN_001e1ac8 matches ONE id: acking 71 says nothing about 70.
  channel.acceptDatagram(ackDatagram(71));
  assert.deepEqual(channel.unacknowledgedSequences(), [70]);
  assert.equal(channel.highestPeerAcknowledgement, 71);

  const before = rig.sent.length;
  rig.run(2_000);
  const retransmitted = rig.sent.slice(before).map((entry) => entry.sequence);
  assert.deepEqual(retransmitted, [70], 'only the still-unacknowledged one goes again');
});

test('an ack for an unknown id is recorded and changes nothing else', () => {
  const rig = harness();
  const channel = seededChannel(rig, 80);
  channel.sendReliable({ opcode: 0x28 });
  channel.acceptDatagram(ackDatagram(9_999));

  assert.deepEqual(channel.unacknowledgedSequences(), [80]);
  assert.equal(channel.highestPeerAcknowledgement, 9_999);
});

test('exhausting the 48-retry cap leaves the channel observably dead, not silently stuck', () => {
  const rig = harness();
  const channel = seededChannel(rig, 90);
  channel.sendReliable({ opcode: 0x28 });

  // 48 retransmissions at 1.62 s + 200 ms each is about 313 s of injected time.
  let guard = 0;
  while (channel.dead === null && guard < 10_000) { rig.advanceTicks(1); guard += 1; }

  assert.equal(channel.dead.reason, CHANNEL_DEATH.RETRANSMISSION_EXHAUSTED);
  assert.deepEqual(channel.dead.detail, { sequence: 90, retransmissions: 48 });
  assert.equal(
    rig.sent.length, 49,
    'the original plus 48 retries - the client sets conn+0x50c = 300 at the same count'
  );
  assert.equal(rig.deaths.length, 1);
  assert.doesNotThrow(() => rig.wheel.assertOwnerDrained(channel), 'a dead channel holds no timers');
});

test('a dead channel refuses to send and refuses inbound datagrams by name', () => {
  const rig = harness({ channel: { maximumRetransmissions: 1 } });
  const channel = seededChannel(rig, 0);
  channel.sendReliable({ opcode: 0x28 });
  rig.run(10_000);
  assert.equal(channel.dead.reason, CHANNEL_DEATH.RETRANSMISSION_EXHAUSTED);

  assert.throws(() => channel.sendReliable({ opcode: 0x28 }), (error) => error.code === 'CHANNEL_DEAD');
  const result = channel.acceptDatagram(reliableDatagram(0));
  assert.deepEqual(result.refusals.map((refusal) => refusal.code), ['DEAD']);
});

/* ---- lifecycle --------------------------------------------------------- */

test('closing a session cancels every timer it owns and the wheel proves it', () => {
  const rig = harness({ channel: { inboundReceiveBase: 0 } });
  const channel = seededChannel(rig, 10);
  channel.sendReliable({ opcode: 0x28 });
  channel.sendReliable({ opcode: 0x10 });
  channel.acceptDatagram(reliableDatagram(5));
  assert.equal(rig.wheel.countForOwner(channel), 3, 'two retransmits and the gap timer');

  assert.equal(channel.close(), 3);
  assert.doesNotThrow(() => rig.wheel.assertOwnerDrained(channel));
  assert.equal(rig.wheel.size, 0, 'and nothing of this session is left in the wheel at all');

  const before = rig.sent.length;
  rig.run(60_000);
  assert.equal(rig.sent.length, before, 'no timer fires after the close');
  assert.equal(channel.close(), 0, 'idempotent');
});

test('two channels on one wheel are independent, and closing one leaves the other running', () => {
  const rig = harness();
  const alice = seededChannel(rig, 10);
  const bob = new ReliableChannel({
    token: OTHER_TOKEN,
    wheel: rig.wheel,
    transmit: (datagram, context) => rig.sent.push({ datagram, owner: 'bob', ...context }),
    outboundSequence: 500
  });
  alice.sendReliable({ opcode: 0x28 });
  bob.sendReliable({ opcode: 0x28 });

  alice.close();
  assert.doesNotThrow(() => rig.wheel.assertOwnerDrained(alice));
  assert.equal(rig.wheel.countForOwner(bob), 1);

  rig.run(2_000);
  assert.deepEqual(
    rig.sent.filter((entry) => entry.retransmission === 1).map((entry) => entry.owner), ['bob']
  );
  bob.close();
});

test('a closed channel refuses to send and refuses inbound datagrams by name', () => {
  const rig = harness();
  const channel = seededChannel(rig, 10);
  channel.close();

  assert.throws(() => channel.sendReliable({ opcode: 0x28 }), (error) => error.code === 'CHANNEL_CLOSED');
  assert.throws(() => channel.sendUnreliable({ opcode: 0x40 }), (error) => error.code === 'CHANNEL_CLOSED');
  assert.deepEqual(
    channel.acceptDatagram(reliableDatagram(0)).refusals.map((refusal) => refusal.code), ['CLOSED']
  );
});

/* ---- construction ------------------------------------------------------ */

test('a channel without a wheel or without a transmit sink is refused at construction', () => {
  assert.throws(
    () => new ReliableChannel({ token: TOKEN, transmit: () => {} }),
    (error) => error instanceof ReliableChannelError && error.code === 'WHEEL_REQUIRED'
  );
  const wheel = new TimingWheel({ onError: () => {} });
  assert.throws(
    () => new ReliableChannel({ token: TOKEN, wheel }),
    (error) => error.code === 'TRANSMIT_REQUIRED'
  );
});

test('a nonsensical bound or token is refused at construction, never clamped', () => {
  const base = { token: TOKEN, wheel: new TimingWheel({ onError: () => {} }), transmit: () => {} };
  for (const [option, value] of [
    ['maximumGapEntries', 0], ['maximumUnacknowledged', 0], ['maximumMessagesPerDatagram', 0],
    ['maximumRetransmissions', 0], ['gapExpiryMs', 0], ['retransmissionTimeoutMs', 0]
  ]) {
    assert.throws(
      () => new ReliableChannel({ ...base, [option]: value }),
      (error) => error.code === 'INVALID_BOUND',
      `expected ${option}=${value} to be refused`
    );
  }
  assert.throws(
    () => new ReliableChannel({ ...base, token: Buffer.alloc(3) }),
    (error) => error.code === 'INVALID_TOKEN'
  );
  assert.throws(
    () => new ReliableChannel({ ...base, inboundReceiveBase: -1 }),
    (error) => error.code === 'INVALID_U32'
  );
});

/*
 * Byte-exact T37 replay fixtures (`captures/v2-live/T37-20260808-090328.pcap`,
 * both consoles, token `028107d0` = 192.0.2.129 - the same token this
 * harness's channel is built with). Extracted with a scratch pcap parser and
 * verified against `docs/design/v2-port/B2-JOIN-FREEZE-EVIDENCE.md` §1/§3.
 */

/**
 * T37 frame #345, 07:06:18.851, `.129`: the 68-byte create batch (+ trailer).
 * op-0x0a (seq 0x25, `0x0800` set) + op-0x09 "USER" + op-0x09 "MAXI" - and BOTH
 * op-0x09 sub-messages carry sequence field 0, which per-message acceptance
 * classified `duplicates` (0 < receiveBase) and silently dropped: the T37
 * journal has NO `lobby-area-count` event after either create.
 */
const T37_CREATE_BATCH = Buffer.from(
  'e814000a028107d0000000250000002000000001a0180009028107d000000000' +
  '0b0000000000000155534552a0180109028107d0000000000000000b00000001' +
  '4d415849ba476611', 'hex');

/**
 * T37 frame #2216, 07:15:27.600, `.129`: the 215-byte aggregate that FROZE the
 * join. op-0x41 keepalive-response (seq 0x81, `0x0800` set) + op-0x49 room-list
 * query riding it with the stale sequence field `0x76000000` - which
 * per-message acceptance gap-buffered forever: acked, never answered, no
 * journal event (B2 doc §1).
 */
const T37_JOIN_AGGREGATE = Buffer.from(
  'b8980041028107d0000000810000000020a2304dd210388f80b8a8602dadbae5' +
  'cb47aac0c62e703980b8a8602dadbae53e1ca2da24cf2b9280b8a8602dadbae5' +
  'cde5b6497161632c80b8a8602dadbae584a5ce8451bd9c7b80b8a8602dadbae5' +
  '6b12d7ad9bbd78e880b8a8602dadbae55362933e4289f2c939ad5ca5b2d07559' +
  '711d6eec92ffa18380b8a8602dadbae56a3c4b8e13e5bf24b03b0049028107d0' +
  '7600000000000000000000fa0310388f4c4f4944010000000253544154210008' +
  '00000008000053544154210400000004000000ba476611', 'hex');

/**
 * T37 frame #666, 07:07:37.729, `.248` (token `02f807d0`): the aggregate that
 * KILLED the first session. op-0x41 (seq 0x11) + op-0x48 name query riding it
 * with stale sequence field `0x08000000`; gap-buffered, and when the client
 * wedged the 30 s expiry fired `gap-abandoned buffered:[134217728]` (journal
 * 07:10:39.086; 134217728 == 0x08000000). Frame #1536 (07:14:19, a separate
 * session) carries the identical stale value and outer seq - it is
 * deterministic stale memory, not a sequence.
 */
const T37_KILL_AGGREGATE = Buffer.from(
  'b898004102f807d0000000110000000020a2304dd210388f80b8a8602dadbae5' +
  'cb47aac0c62e703980b8a8602dadbae53e1ca2da24cf2b9280b8a8602dadbae5' +
  'cde5b6497161632c80b8a8602dadbae5335757d0a0d4cc4a80b8a8602dadbae5' +
  '6b12d7ad9bbd78e880b8a8602dadbae55362933e4289f2c9e22a85b03bfcc47e' +
  '711d6eec92ffa18380b8a8602dadbae59263b0102eec349ab042004802f807d0' +
  '08000000000000000000000a020000004e414d454445305230303100000000' +
  '0000000000004e414d454645305230313000000000000000000000ba476611', 'hex');

test('the create batch is walked: all three queries are delivered, not just the first', () => {
  /*
   * THE REGRESSION THIS EXISTS FOR, in the owner's words: "exiting a room does
   * not work ... I have to wait until the timer runs out."
   *
   * After the create accept the client sends THREE one-shot queries in ONE
   * datagram - op-0x0a (20) + op-0x09 (24) + op-0x09 (24) = 68. The T35 rig
   * journal logged 20 bytes handled and "BATCH_NOT_WALKED, 48 trailing bytes";
   * 20 + 48 = 68 exactly. Those queries have no client-side retry and no
   * timeout, so answering only the outer message answers one of three and the
   * screen parks on "Getting information" forever.
   *
   * Delivering all three is therefore the prerequisite for the whole in-room
   * layer, and it is asserted here at the transport seam rather than through a
   * handler, so it cannot silently regress if a handler changes.
   *
   * SUPERSEDED IN PART 2026-08-08: this test used to build the batch with
   * guessed sequential sub-sequences (21, 22) and to assert one ack PER
   * sub-message. The real bytes (T37 frame #345) carry sequence field 0 on both
   * op-0x09s; replayed byte-exact now.
   *
   * SUPERSEDED AGAIN 2026-08-08 (nora pre-deploy review, fix 1): the slice-1a
   * commit ALSO dropped the per-rider acks, on the claim they "matched nothing
   * in the client's retransmit queue". That absence claim is Inference grade
   * only (B2-JOIN-FREEZE-EVIDENCE.md §6: the old per-rider acks are "graded
   * harmless noise - Inference"), while months of rig runs prove the emission
   * at least harmless. The rig-graded obligation stands: ack every reliable
   * inbound (gap table X1). So the pre-branch emission is restored - covering
   * sequence AND each rider's own id, deduplicated - and only the delivery fix
   * (riders ride the covering acceptance) is kept from slice 1a.
   */
  const rig = harness({ channel: { inboundReceiveBase: 0x25 } });
  const result = rig.channel.acceptDatagram(T37_CREATE_BATCH);

  assert.deepEqual(
    result.delivered.map((message) => message.opcode), [0x0a, 0x09, 0x09],
    'every batched query is delivered; one of three is a permanent client hang'
  );
  assert.deepEqual(
    result.delivered.slice(1).map((message) => message.payload.subarray(4).toString('latin1')),
    ['USER', 'MAXI'],
    'the riders are the real op-0x09 count queries, byte for byte'
  );
  assert.deepEqual(
    result.duplicates, [],
    'sequence field 0 on a rider is NOT "below the base": the field is unstamped stale memory'
  );
  assert.deepEqual(result.refusals, [], 'a well-formed declared batch is not a fault');
  /*
   * Each sub-message is acknowledged in its own right, alongside the covering
   * sequence (the obligation the slice-1a commit deleted, restored by nora
   * pre-deploy fix 1): the rig-graded rule is "ack every reliable inbound"
   * (gap table X1), the client's handling of an id it never sent is a no-op at
   * worst, and months of rig runs shipped exactly these acks. Both riders
   * carry the same stale id 0, so the dedup emits it once - covering 0x25
   * first, then 0. This is the bounded fan-out the per-datagram limit exists
   * to cap, not an amplification.
   */
  assert.deepEqual(
    result.acknowledgements.map((ack) => ack.readUInt32BE(0x0c)), [0x25, 0x00],
    'the covering sequence, then each parsed rider id, deduplicated'
  );
  assert.equal(rig.channel.receiveBase, 0x26, 'the covering message alone advances the base');
});

test('T37 join freeze: the coalesced op-0x49 rides the op-0x41 and is never gap-buffered', () => {
  /*
   * THE B2 JOIN FREEZE, byte for byte. `.129`'s room-list sweep coalesced its
   * op-0x49 poll behind the due keepalive-response; the rider's stale sequence
   * field `0x76000000` was treated as a far-future hole, so the query was
   * acked, gap-buffered forever, and never dispatched - every second poll
   * unanswered degraded the ~100 ms sweep to 10 s stalls and the lobby UI
   * froze (B2 doc §1/§4, Conclusion).
   */
  const rig = harness({ channel: { inboundReceiveBase: 0x81 } });
  const result = rig.channel.acceptDatagram(T37_JOIN_AGGREGATE);

  assert.deepEqual(
    result.delivered.map((message) => message.opcode), [0x41, 0x49],
    'the room-list query reaches dispatch in the same acceptance as its carrier'
  );
  assert.equal(result.delivered[1].sequence, 0x76000000, 'the stale field travels, unread');
  assert.deepEqual(result.bufferedSequences, [], 'no gap-buffering of a riding sub-message');
  assert.equal(rig.channel.gapSize, 0);
  assert.deepEqual(result.refusals, []);
  // The pre-branch ack emission (nora fix 1): the OUTER sequence gates and
  // advances the stream; the rider's stale id is acked as rig-proven noise.
  assert.deepEqual(
    result.acknowledgements.map((ack) => ack.readUInt32BE(0x0c)), [0x81, 0x76000000],
    'covering sequence first, then the parsed rider id'
  );
  assert.equal(rig.channel.receiveBase, 0x82);
});

test('T37 session kill: a stale rider sequence can no longer expire into gap-abandoned', () => {
  /*
   * The defect did not only freeze a screen - it killed `.248`'s first session:
   * the op-0x48 rider's stale `0x08000000` armed the 30 s gap expiry, and when
   * the client wedged, `GAP_ABANDONED buffered:[0x08000000]` closed the session
   * (journal 07:10:39.086). With the rider delivered under the outer's
   * acceptance there is no phantom hole, no timer, and no death.
   */
  const rig = harness({ channel: { token: Buffer.from('02f807d0', 'hex'), inboundReceiveBase: 0x11 } });
  const result = rig.channel.acceptDatagram(T37_KILL_AGGREGATE);

  assert.deepEqual(result.delivered.map((message) => message.opcode), [0x41, 0x48]);
  assert.equal(rig.channel.gapSize, 0, 'nothing buffered, so nothing can be abandoned');
  rig.run(31_000);
  assert.equal(rig.channel.dead, null, 'the session survives a quiet spell');
  assert.deepEqual(rig.deaths, []);
});

test('a gap-buffered covering message keeps its riders and releases them in the cascade', () => {
  /*
   * A REAL out-of-order outer (its own stamped sequence, ahead of the base)
   * must still buffer - that part of ordered delivery is untouched. Its riders
   * travel with it: never in the gap buffer on their own, delivered exactly
   * when the covering message is.
   */
  const rig = harness({ channel: { inboundReceiveBase: 3 } });
  const ahead = rig.channel.acceptDatagram(datagramOf(
    clientMessage({ sequence: 5, opcode: 0x41, flags: FLAG_SET | FLAG_DATA | FLAG_AGGREGATE }),
    clientMessage({ sequence: 0x76000000, opcode: 0x49 })
  ));
  assert.deepEqual(ahead.delivered, [], 'strictly in order: 5 cannot pass 3');
  assert.deepEqual(ahead.bufferedSequences, [5], 'the covering sequence, not the rider field');
  assert.deepEqual(rig.channel.gapSequences(), [5], 'the rider is not a gap entry');

  rig.channel.acceptDatagram(reliableDatagram(4));
  const fill = rig.channel.acceptDatagram(reliableDatagram(3));
  assert.deepEqual(
    fill.delivered.map((message) => [message.sequence, message.opcode]),
    [[3, 0x06], [4, 0x06], [5, 0x41], [0x76000000, 0x49]],
    'the cascade releases the covering message with its rider immediately after it'
  );
  assert.equal(rig.channel.gapSize, 0);
});

test('a retransmitted aggregate is a duplicate WITH its riders: nothing dispatches twice', () => {
  const rig = harness({ channel: { inboundReceiveBase: 0x25 } });
  const first = rig.channel.acceptDatagram(T37_CREATE_BATCH);
  assert.equal(first.delivered.length, 3);

  const again = rig.channel.acceptDatagram(T37_CREATE_BATCH);
  assert.deepEqual(again.delivered, [], 'the peer retransmit changes nothing');
  assert.deepEqual(
    again.duplicates.map((message) => message.opcode), [0x0a, 0x09, 0x09],
    'the riders are duplicates of their covering message, not free-standing messages'
  );
  assert.deepEqual(
    again.acknowledgements.map((ack) => ack.readUInt32BE(0x0c)), [0x25, 0x00],
    'still acked - covering and rider ids alike - so the retransmission stops'
  );
});
