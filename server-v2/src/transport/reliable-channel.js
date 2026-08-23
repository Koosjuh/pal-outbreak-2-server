import {
  FLAG_ACK,
  FLAG_AGGREGATE,
  FLAG_DATA,
  FLAG_MASK,
  FLAG_RELIABLE,
  FLAG_SET,
  HEADER_LENGTH,
  LENGTH_MASK,
  SNAP_TRAILER,
  encodeDatagram,
  encodeTransportAck
} from '../protocol/snap-codec.js';

/**
 * One SN@P transport channel: the reliable send window, the ordered receive
 * stream, and the acknowledgement policy for a SINGLE session.
 *
 * ## Why this file was replaced rather than patched
 *
 * The previous version implemented ordered inbound delivery plus a counter, and
 * nothing else. It had no send-side state at all - `encodeReliable` consumed a
 * sequence and returned a Buffer that was retained nowhere, so nothing could be
 * retransmitted and `highestPeerAcknowledgement` was recorded and never read -
 * its inbound gap buffer was unbounded (20 000 out-of-order segments pinned
 * 17.2 MB and delivered nothing), and it emitted one ACK datagram per segment,
 * which turned one 60-segment datagram into 60 outbound datagrams. It had no
 * importer anywhere in `src/`. What was RIGHT and is kept: one receive base for
 * every reliable opcode, one outbound allocator rather than per-handler
 * counters, and the strict in-order release with cascade.
 *
 * ## The acknowledgement policy, and why it is not "one ACK per segment"
 *
 * The 20-byte ack is `60 10 00 00 | token | 00000000 | ackedSeq | trailer`, and
 * the client frees the acknowledged send block by EXACT id - `FUN_001e1ac8`
 * searches its retransmit queue for that one value, so an ack is not cumulative
 * and one ack can never stand for several messages.
 *
 * Batching acks into one datagram is therefore not merely unhelpful, it does not
 * work: `FUN_001d6988.c:20-23` consumes the `0x4000` ack field of the FIRST
 * message only. Messages two and beyond are copied header-and-all into the
 * delivery queue (`:47-88`) and their `+0x0c` ack field is never read - the loop
 * tests `0x8000` and the sequence and nothing else. Worse, a trailing `0x6010`
 * ack segment carries sequence 0, so it fails the client's unreliable high-water
 * test (`conn+0x10 <= seq`) and is dropped in silence. So N acknowledged
 * sequences genuinely cost N datagrams.
 *
 * What this channel does instead:
 *
 *   BOUND, not batch. It acknowledges the COVERING message's sequence AND each
 *   parsed rider's own id, deduplicated within the datagram - the exact
 *   emission the rig-proven pre-branch build sent, per the standing rig-graded
 *   obligation "ack every reliable inbound" (gap table X1, Observation-rig).
 *   ACCEPTANCE still follows the covering sequence alone (`FUN_001d6988.c:
 *   44-88`: the client gates every reliable sub on `uStack_30`; a riding sub's
 *   own sequence field is unstamped stale memory, T37) - the rider acks change
 *   nothing about delivery. RESTORED 2026-08-08 (nora pre-deploy review, fix
 *   1): a brief revision dropped the rider acks on the claim they "matched
 *   nothing in the client's retransmit queue", but that absence claim is
 *   Inference grade only (`B2-JOIN-FREEZE-EVIDENCE.md` §6 grades the old
 *   per-rider acks "harmless noise - Inference"), while months of rig runs
 *   prove the emission is at least harmless - so the proven bytes ship and
 *   the unproven deviation does not. The fan-out stays bounded: at most one
 *   ack per parsed message, and the walk's parse work is capped by
 *   `maximumMessagesPerDatagram`, which fails closed rather than clamping.
 *
 *   Duplicates are still acknowledged. A duplicate arrives because the peer's
 *   retransmit timer fired; withholding the ack guarantees it fires again, 48
 *   times, and then the peer's transport dies silently. Acking an id the peer
 *   has already freed is a no-op on its side (V1 `game_udp_server.js:1493`).
 *
 * The one remaining reduction available is piggybacking - setting `0x4000` and
 * the ack field on an outbound message that was going out anyway, which is free
 * because every datagram this channel emits carries exactly one message. It is
 * NOT done here: it needs the owner's send scheduling to decide how long an ack
 * may wait, and an ack that waits for a reply that never comes is a peer
 * retransmitting for nothing. (This module IS wired in now - `SnapLobbySession`
 * owns one channel per post-selection session - so the earlier note here that it
 * was not is stale; what is unchanged is that piggybacking is still the caller's
 * decision to make and has not been made.)
 *
 * ## Why the inbound walk is off by default
 *
 * The client's own receive path does walk (`FUN_001d6988.c:44`, gated on the
 * FIRST message carrying `0x0800`, at most `0x38` further messages). The server
 * doing the same to CLIENT datagrams is what corrupted Area Select in V1: the
 * walk stepped `flags & 0x3ff` into an op-0x48 body, which is Blowfish
 * ciphertext, read it as sub-headers, and acked ids like `0xcd0a0000` - freeing
 * the wrong client buffers (V1 `game_udp_server.js:1512-1517`, T9 2026-07-02).
 * The standing obligation from that is "ack all reliable, outer frame id only,
 * never walk coalesced sub-frames" (`analysis/PATH-TO-LOBBY-GAP-TABLE.md` row
 * X1, graded Observation-rig). Bytes past the outer message are counted and
 * reported, never parsed - which is also what the client does when `0x0800` is
 * clear.
 *
 * SUPERSEDED 2026-08-08 by the T35 rig run. The rule above is kept verbatim
 * because its FIRST half is still correct and still enforced - never walk a
 * datagram whose first message leaves `0x0800` clear. What was wrong was the
 * conclusion that "nothing in this protocol" needs walking.
 *
 * The old reasoning generalised from one op-0x48 datagram, where V1 acked the
 * outer frame and the client carried on, to every batch. That does not hold on
 * the create path. After the create accept the client sends THREE queries in one
 * datagram - op-0x0a (20) + op-0x09 (24) + op-0x09 (24) = 68 - and the T35
 * journal logged exactly `20` handled and `BATCH_NOT_WALKED, 48 trailing bytes`.
 * 20 + 48 = 68. All three must be answered or the screen parks on "Getting
 * information" with no client-side timeout and no retry: those queries are
 * one-shot. Answering only the outer message answers one of three and still hangs.
 *
 * So walking is now ON by default, still gated on `0x0800`. That gate is not our
 * invention - it is the client's own rule (`FUN_001d6988.c:44`: walk only when
 * the first message declares `0x0800`, each sub-message's length being its own
 * `flags & 0x3ff`). The V1 corruption came from walking op-0x48 Blowfish bodies
 * whose first message did NOT declare it, which this gate already refuses.
 *
 * Wire proof the client sets the flag (T35 pcap, 22:20:40, 192.0.2.248):
 * `b8 98 00 41 ...` - flags `0xb898`, `0x0800` set, declared length `0x98` = 152,
 * datagram 172, and `172 - 152 - 4` = the 16 trailing bytes the journal reported.
 *
 * `walkBatchedMessages: false` remains available to restore the old behaviour.
 *
 * ## Outbound: one message per datagram, and MORE_MESSAGES never set
 *
 * A wrongly set `0x0800` on a server message makes the client's sub-record loop
 * hit `FUN_001ec1f8` error `0x1772` and ABORT the whole segment un-acked
 * (`analysis/op06-accept-criterion-RE-2026-07-26.txt:135-139`). There is no
 * benefit to weigh against that, so every datagram this channel emits carries
 * exactly one message and `FLAG_AGGREGATE` from a caller is refused.
 *
 * ## Mirror versus stamp
 *
 * Control pushes MIRROR the sequence of the client message they answer and
 * consume no counter (the slot-0x1c op-0x28 push: "seq mirrored, not consumed").
 * Windowed reliable DATA replies STAMP their own from the session counter, which
 * is seeded from the register reply. Getting this backwards desynchronises the
 * counter from the client's `recvBase`; V1 shipped the bug in both directions
 * (`server/game_udp_server.js:826-837` and `:2991-3000`) and the second route
 * surfaces as error 840. They are two methods here precisely so a caller cannot
 * express the confusion, and neither may put two live unacknowledged messages on
 * the same wire sequence - the client would enqueue both, deliver one and leak
 * the twin's buffer.
 *
 * ## Bounds - every one of them fails closed with a named code
 *
 *   `maximumMessagesPerDatagram`  a datagram declaring more is refused WHOLE;
 *                                 nothing from it is delivered or acked, so the
 *                                 ack fan-out has a stated ceiling.
 *   `maximumGapEntries`           a further out-of-order segment is refused and
 *                                 NOT acknowledged, so the peer retransmits it.
 *                                 Nothing already buffered is evicted: it was
 *                                 acknowledged, so dropping it would lose it -
 *                                 the peer will never send it again.
 *   `maximumUnacknowledged`       a send beyond the window throws rather than
 *                                 queueing behind an unbounded backlog.
 *   `gapExpiryMs`                 the ONE place entries are discarded. A hole
 *                                 the peer never filled makes ordered delivery
 *                                 unrecoverable, so this is terminal and loud
 *                                 (`GAP_ABANDONED`), not a silent eviction.
 *
 * ## Timers
 *
 * All from the injected timing wheel, owned by this channel instance, so
 * `close()` cancels the group and `assertOwnerDrained` can prove it. One entry
 * per unacknowledged message plus one gap timer: with the defaults that is 33,
 * inside the wheel's per-owner default of 64.
 *
 * ## Known limit
 *
 * Sequences are compared as plain uint32s, so a stream that wraps past
 * 0xffffffff would order incorrectly. Left explicit rather than fixed: no
 * observed session comes near it (the register reply seeds four-digit values),
 * and a wrapping comparison written without a capture to check it against would
 * be a guess in the one place a guess silently reorders the lobby.
 */

export class ReliableChannelError extends Error {
  constructor(code, message) {
    super(message);
    this.name = 'ReliableChannelError';
    this.code = code;
  }
}

function fail(code, message) {
  throw new ReliableChannelError(code, message);
}

/** Named reasons a datagram, or part of one, was not processed. Never thrown at a peer. */
export const CHANNEL_REFUSAL = Object.freeze({
  CLOSED: 'the channel is closed',
  DEAD: 'the channel transport is dead',
  SHORT_DATAGRAM: 'shorter than the 20-byte minimum',
  BAD_TRAILER: 'the SN@P trailer is not ba 47 66',
  BAD_LENGTH: 'the declared message length does not fit the datagram',
  TOKEN_MISMATCH: 'the message carries another session token',
  TOO_MANY_MESSAGES: 'the datagram declares more messages than the per-datagram bound',
  BATCH_MALFORMED: 'a batched sub-message header does not parse',
  BATCH_NOT_WALKED: 'trailing bytes were ignored rather than walked',
  GAP_FULL: 'the out-of-order buffer is full; the segment is refused and left unacknowledged',
  TIMER_CAPACITY: 'the timing wheel refused the gap expiry timer; the segment is not buffered'
});

/** Terminal states. Both are observable on `dead` and reported to `onTransportDead`. */
export const CHANNEL_DEATH = Object.freeze({
  RETRANSMISSION_EXHAUSTED: 'retransmission-exhausted',
  GAP_ABANDONED: 'gap-abandoned'
});

/**
 * The client's own numbers for ITS reliable sends: RTO about 1.62 s rising about
 * 200 ms per retry, cap `conn+0x518` = 48, after which `conn+0x50c = 300` and
 * every later send is refused with `DAT_0025b790 = 0x66` - the transport is dead
 * and says nothing (`analysis/PATH-TO-LOBBY-GAP-TABLE.md` §2). Reusing them for
 * the server's own sends is a CHOICE, not an observation: no capture shows what
 * the original server used. Note that 48 retries spans about 313 s, far beyond
 * the client's 55.2 s register watchdog and its 3600-frame app watchdog, so in
 * practice a session dies of those first and `RETRANSMISSION_EXHAUSTED` is a
 * diagnostic of last resort rather than the primary failure detector.
 */
const DEFAULT_RETRANSMISSION_TIMEOUT_MS = 1_620;
const DEFAULT_RETRANSMISSION_BACKOFF_STEP_MS = 200;
const DEFAULT_MAXIMUM_RETRANSMISSIONS = 48;

/**
 * Server-side choices, not protocol constants.
 *
 * The gap expiry sits below the client's app watchdog (0xe10 frames, about 60 s
 * NTSC / 72 s PAL) so that the server names the cause before the client's error
 * screen makes it look like something else.
 *
 * The per-datagram bound is 8 where the client's structural ceiling is 1 + 0x38
 * = 57 (`FUN_001d6988.c:47`). The client DOES batch: archive IN #16 is a
 * 136-byte datagram carrying two op-0x48 queries with `0x0800` set on the first
 * (the fixture is `ARCHIVE_COALESCED_NAME_QUERY` in
 * `test/snap-lobby-session.test.js`). No archived batch exceeds two, and this
 * bound is also the ack amplification factor an unauthenticated peer can
 * command, so it is set to headroom rather than to the ceiling. Raise it, with
 * evidence, if a capture shows a larger one.
 */
const DEFAULT_GAP_EXPIRY_MS = 30_000;
const DEFAULT_MAXIMUM_GAP_ENTRIES = 32;
const DEFAULT_MAXIMUM_UNACKNOWLEDGED = 32;
const DEFAULT_MAXIMUM_MESSAGES_PER_DATAGRAM = 8;

/** The client masks the low byte off before comparing: `byteswap(u32) == 0xba476600`. */
const TRAILER_CHECKED_BYTES = 3;

function uint32(value, field) {
  if (!Number.isInteger(value) || value < 0 || value > 0xffffffff) {
    fail('INVALID_U32', `${field} must be a uint32, not ${value}`);
  }
  return value >>> 0;
}

function positiveInteger(value, field) {
  if (!Number.isSafeInteger(value) || value < 1) {
    fail('INVALID_BOUND', `${field} must be a positive whole number, not ${value}`);
  }
  return value;
}

function tokenBytes(token) {
  if (Buffer.isBuffer(token)) {
    if (token.length !== 4) fail('INVALID_TOKEN', 'a token buffer must contain exactly four bytes');
    return Buffer.from(token);
  }
  const encoded = Buffer.alloc(4);
  encoded.writeUInt32BE(uint32(token ?? 0, 'token'));
  return encoded;
}

export class ReliableChannel {
  #token;
  #wheel;
  #transmit;
  #onTransportDead;

  #receiveBase;
  #outboundSequence;
  #unreliableSequence;
  #unreliableHighWater = null;
  #highestPeerAcknowledgement = null;

  // sequence -> { sequence, datagram, retransmissions, handle, mirrored }
  #unacknowledged = new Map();
  // sequence -> message, held only while it is ahead of the receive base
  #gap = new Map();
  #gapTimerHandle = null;

  #dead = null;
  #closed = false;

  #retransmissionTimeoutMs;
  #retransmissionBackoffStepMs;
  #maximumRetransmissions;
  #gapExpiryMs;
  #maximumGapEntries;
  #maximumUnacknowledged;
  #maximumMessagesPerDatagram;
  #walkBatchedMessages;

  constructor({
    token = 0,
    wheel,
    transmit,
    onTransportDead = null,
    inboundReceiveBase = 0,
    outboundSequence = null,
    unreliableSequence = 0,
    retransmissionTimeoutMs = DEFAULT_RETRANSMISSION_TIMEOUT_MS,
    retransmissionBackoffStepMs = DEFAULT_RETRANSMISSION_BACKOFF_STEP_MS,
    maximumRetransmissions = DEFAULT_MAXIMUM_RETRANSMISSIONS,
    gapExpiryMs = DEFAULT_GAP_EXPIRY_MS,
    maximumGapEntries = DEFAULT_MAXIMUM_GAP_ENTRIES,
    maximumUnacknowledged = DEFAULT_MAXIMUM_UNACKNOWLEDGED,
    maximumMessagesPerDatagram = DEFAULT_MAXIMUM_MESSAGES_PER_DATAGRAM,
    /*
     * ON by default since T35: the create path batches three one-shot queries
     * into one datagram and all three must be answered. Still gated on the
     * client-declared `0x0800`; see the doctrine note at the top of this file.
     */
    walkBatchedMessages = true
  } = {}) {
    if (wheel == null || typeof wheel.schedule !== 'function' || typeof wheel.cancelOwner !== 'function') {
      // Injected, never constructed here: one wheel serves the whole subsystem,
      // and a channel that made its own would reintroduce a timer per session.
      fail('WHEEL_REQUIRED', 'a timing wheel with schedule/cancelOwner is required');
    }
    if (typeof transmit !== 'function') {
      fail('TRANSMIT_REQUIRED', 'transmit(datagram, context) is required: retransmission has no other outlet');
    }
    if (onTransportDead !== null && typeof onTransportDead !== 'function') {
      fail('DEAD_HANDLER', 'onTransportDead must be a function when supplied');
    }

    this.#token = tokenBytes(token);
    this.#wheel = wheel;
    this.#transmit = transmit;
    this.#onTransportDead = onTransportDead;
    this.#receiveBase = uint32(inboundReceiveBase, 'inboundReceiveBase');
    this.#outboundSequence =
      outboundSequence === null ? null : uint32(outboundSequence, 'outboundSequence');
    this.#unreliableSequence = uint32(unreliableSequence, 'unreliableSequence');
    this.#retransmissionTimeoutMs = positiveInteger(retransmissionTimeoutMs, 'retransmissionTimeoutMs');
    if (!Number.isSafeInteger(retransmissionBackoffStepMs) || retransmissionBackoffStepMs < 0) {
      fail('INVALID_BOUND', 'retransmissionBackoffStepMs must be a whole number of milliseconds');
    }
    this.#retransmissionBackoffStepMs = retransmissionBackoffStepMs;
    this.#maximumRetransmissions = positiveInteger(maximumRetransmissions, 'maximumRetransmissions');
    this.#gapExpiryMs = positiveInteger(gapExpiryMs, 'gapExpiryMs');
    this.#maximumGapEntries = positiveInteger(maximumGapEntries, 'maximumGapEntries');
    this.#maximumUnacknowledged = positiveInteger(maximumUnacknowledged, 'maximumUnacknowledged');
    this.#maximumMessagesPerDatagram =
      positiveInteger(maximumMessagesPerDatagram, 'maximumMessagesPerDatagram');
    this.#walkBatchedMessages = walkBatchedMessages === true;
  }

  get token() {
    return Buffer.from(this.#token);
  }

  /** The next reliable sequence the peer must deliver before anything behind it moves. */
  get receiveBase() {
    return this.#receiveBase;
  }

  /** The sequence the next STAMPED reliable send will carry, or null while unseeded. */
  get nextStampedSequence() {
    return this.#outboundSequence;
  }

  get unacknowledgedCount() {
    return this.#unacknowledged.size;
  }

  get gapSize() {
    return this.#gap.size;
  }

  /** The highest ack the peer has ever sent. Diagnostics: matching is by exact id. */
  get highestPeerAcknowledgement() {
    return this.#highestPeerAcknowledgement;
  }

  /** `{ reason, detail }` once terminal, else null. Terminal is permanent. */
  get dead() {
    return this.#dead === null ? null : { ...this.#dead };
  }

  get closed() {
    return this.#closed;
  }

  /** Live unacknowledged sequences, oldest first. Diagnostics and tests only. */
  unacknowledgedSequences() {
    return [...this.#unacknowledged.keys()];
  }

  /** Buffered out-of-order sequences, ascending. Diagnostics and tests only. */
  gapSequences() {
    return [...this.#gap.keys()].sort((left, right) => left - right);
  }

  /** How many times a message has been retransmitted, or null if it is not in flight. */
  retransmissionsFor(sequence) {
    return this.#unacknowledged.get(uint32(sequence, 'sequence'))?.retransmissions ?? null;
  }

  /**
   * Seed the stamped counter from the proven handshake.
   *
   * Unseeded is deliberately an error rather than zero: the counter continues the
   * register reply's sequence, and starting at zero puts every reply below the
   * client's `recvBase`, where `FUN_001d6988` frees it un-acked and the app
   * simply never sees it.
   */
  seedStampedSequence(sequence) {
    this.#outboundSequence = uint32(sequence, 'sequence');
    return this.#outboundSequence;
  }

  /**
   * Send a windowed reliable DATA message, stamping the session counter.
   *
   * Returns `{ sequence, datagram }`; the datagram has already left through
   * `transmit`, and is retained for retransmission until the peer acknowledges
   * that exact sequence.
   */
  sendReliable({
    opcode = 0, subSelector = 0, payload = Buffer.alloc(0), flags = FLAG_SET | FLAG_DATA
  } = {}) {
    this.#requireLive('sendReliable');
    if (this.#outboundSequence === null) {
      fail(
        'SEQUENCE_UNSEEDED',
        'the stamped reliable sequence is unseeded; seed it from the proven handshake'
      );
    }
    const sequence = this.#outboundSequence;
    const datagram = this.#emitReliable({ opcode, subSelector, payload, flags, sequence, mirrored: false });
    // Advanced only after the send is accepted, so a refused send does not burn a
    // sequence and leave a permanent hole in the client's ordered stream.
    this.#outboundSequence = (sequence + 1) >>> 0;
    return { sequence, datagram };
  }

  /**
   * Send a control push that MIRRORS the sequence of the client message it
   * answers, consuming no counter.
   *
   * The caller passes the sequence to mirror because only the caller knows which
   * request this answers; inferring it here from "the last inbound sequence"
   * would silently answer the wrong message when two requests are in flight.
   */
  sendMirrored({
    opcode = 0, subSelector = 0, payload = Buffer.alloc(0), flags = FLAG_SET | FLAG_DATA, sequence
  } = {}) {
    this.#requireLive('sendMirrored');
    const mirrored = uint32(sequence, 'sequence');
    const datagram =
      this.#emitReliable({ opcode, subSelector, payload, flags, sequence: mirrored, mirrored: true });
    return { sequence: mirrored, datagram };
  }

  /**
   * Send an unreliable message - the op-0x40 keepalive shape, and anything else
   * the client takes on its high-water channel.
   *
   * The counter ALWAYS advances, including across losses. The client's test is
   * `conn+0x10 <= seq` (`FUN_001d6988.c:25`), so a repeated value is delivered
   * to the application a second time rather than suppressed.
   */
  sendUnreliable({
    opcode = 0, subSelector = 0, payload = Buffer.alloc(0), flags = FLAG_SET | FLAG_DATA
  } = {}) {
    this.#requireLive('sendUnreliable');
    this.#requireSendableFlags(flags, false);
    const sequence = this.#unreliableSequence;
    this.#unreliableSequence = (sequence + 1) >>> 0;
    const datagram = encodeDatagram([
      { flags, subSelector, opcode, token: this.#token, sequence, payload }
    ]);
    this.#transmit(datagram, { kind: 'unreliable', sequence, opcode });
    return { sequence, datagram };
  }

  /**
   * Accept one datagram from the peer.
   *
   * Never throws on peer input: everything refused comes back in `refusals` with
   * a named code, and a refusal at datagram scope is atomic - no delivery, no
   * acknowledgement, no state moved.
   *
   * Returns `{ delivered, acknowledgements, duplicates, transportOnly,
   * bufferedSequences, refusals, receiveBase }`. `acknowledgements` are the ack
   * datagrams ALREADY sent through `transmit`; they are returned so a caller can
   * log or assert them, not so it can send them.
   */
  acceptDatagram(datagram) {
    const result = {
      delivered: [],
      acknowledgements: [],
      duplicates: [],
      transportOnly: [],
      bufferedSequences: [],
      refusals: [],
      receiveBase: this.#receiveBase
    };
    if (this.#closed) return this.#refuse(result, 'CLOSED');
    if (this.#dead !== null) return this.#refuse(result, 'DEAD', this.#dead.reason);
    if (!Buffer.isBuffer(datagram)) {
      fail('INVALID_DATAGRAM', 'a datagram must be a Buffer');
    }

    // ---- validate the whole datagram before touching any state ----
    if (datagram.length < HEADER_LENGTH + SNAP_TRAILER.length) {
      return this.#refuse(result, 'SHORT_DATAGRAM', `${datagram.length} bytes`);
    }
    const trailerOffset = datagram.length - SNAP_TRAILER.length;
    if (!datagram
      .subarray(trailerOffset, trailerOffset + TRAILER_CHECKED_BYTES)
      .equals(SNAP_TRAILER.subarray(0, TRAILER_CHECKED_BYTES))) {
      return this.#refuse(result, 'BAD_TRAILER', datagram.subarray(trailerOffset).toString('hex'));
    }

    const outer = this.#decodeMessageAt(datagram, 0, trailerOffset);
    if (outer.refusal != null) return this.#refuse(result, outer.refusal, outer.detail);

    const messages = [outer.message];
    const trailing = trailerOffset - outer.message.innerLength;
    if (trailing > 0) {
      if (!this.#walkBatchedMessages || !outer.message.moreMessages) {
        /*
         * Reported, never parsed. `FUN_001d6988.c:44` only walks when the first
         * message declares 0x0800, and V1 proved that walking a client datagram
         * reads Blowfish ciphertext as sub-headers (T9 2026-07-02).
         */
        result.refusals.push({ code: 'BATCH_NOT_WALKED', detail: `${trailing} trailing bytes` });
      } else {
        const walked = this.#walk(datagram, outer.message.innerLength, trailerOffset);
        /*
         * The BOUND still fails closed, and only the bound. `TOO_MANY_MESSAGES`
         * is a security control, not a parse ambiguity: it caps the ack fan-out
         * an unauthenticated peer can command from one datagram, so degrading it
         * to "answer the outer message" would hand back the amplification the
         * bound exists to deny. A malformed sub-header is a different thing - it
         * says we cannot read the rest, not that the peer is asking for too much.
         */
        if (walked.refusal === 'TOO_MANY_MESSAGES') {
          return this.#refuse(result, walked.refusal, walked.detail);
        }
        if (walked.refusal != null) {
          /*
           * DEGRADE to the outer message; do NOT refuse the datagram.
           *
           * This is the case that falsified the simple rule. Both of these
           * declare `0x0800`:
           *
           *   - the create batch (op-0x0a + op-0x09 + op-0x09), whose sub-headers
           *     parse cleanly and which MUST be walked or the client parks
           *     forever on "Getting information";
           *   - the archived op-0x48 name query, whose second sub-header does NOT
           *     parse, because an op-0x48 body is Blowfish ciphertext and stepping
           *     `flags & 0x3ff` into it lands mid-cipher. That is precisely the
           *     read that made V1 acknowledge ids like `0xcd0a0000` and free the
           *     wrong client buffers (T9 2026-07-02).
           *
           * So `0x0800` alone does not decide it, and the earlier claim that the
           * V1 corruption came only from UNFLAGGED datagrams is wrong - verified
           * here: the archived datagram's first word is `0xb842`, `0x0800` set.
           *
           * Refusing the whole datagram would answer neither, turning a working
           * op-0x48 into silence. Degrading answers the outer message exactly as
           * before and simply declines the part we could not parse - which is the
           * old behaviour for that datagram, reached by evidence rather than by
           * blanket policy. Nothing malformed is ever delivered or acknowledged,
           * so the wrong-id ack that caused the corruption remains impossible.
           */
          result.refusals.push({
            code: 'BATCH_WALK_DEGRADED',
            detail: `${walked.refusal} at ${walked.detail}; answered the outer message only`
          });
        } else {
          messages.push(...walked.messages);
        }
      }
    }
    for (const message of messages) {
      if (!message.token.equals(this.#token)) {
        return this.#refuse(result, 'TOKEN_MISMATCH', message.token.toString('hex'));
      }
    }

    // ---- process ----
    /*
     * Reliable sub-messages RIDE the covering reliable message.
     *
     * The client's own acceptor (`FUN_001d6988.c:44-88`) gates every reliable
     * sub-message of a walked batch on the sequence of the FIRST reliable
     * message in the datagram - the outer message or, when the outer is
     * unreliable, the first reliable sub (`uStack_30`) - and acks that ONE
     * value once. A riding sub-message's own sequence field is dead weight the
     * client leaves unstamped: T37 carried stale buffer content there
     * (`0x76000000`, `0x7A000000`, `0x08000000`), and running those through
     * per-message acceptance gap-buffered live op-0x49 queries forever - the
     * B2 join freeze - and killed a session outright when the 30 s gap expiry
     * fired (`gap-abandoned buffered:[134217728 = 0x08000000]`, T37 journal
     * 07:10:39). So a riding sub-message is delivered iff its covering message
     * is delivered, is never gap-buffered on its own sequence field, and never
     * counts toward `gap-abandoned`
     * (`docs/design/v2-port/B2-JOIN-FREEZE-EVIDENCE.md` §3, Conclusion grade).
     * Its id IS still acknowledged alongside the covering sequence - the
     * pre-branch, rig-proven ack emission (see `#acceptReliable` and the ack
     * doctrine at the top of this file; restored 2026-08-08, nora fix 1).
     *
     * Unreliable sub-messages keep their own high-water test: the one case the
     * client reads a sub's own sequence field (`FUN_001d6988.c:55`).
     */
    const acknowledgeSequences = [];
    const accepted = [];
    let covering = null;
    for (const message of messages) {
      if (message.acknowledges) this.#acknowledge(message.acknowledgement);
      if (!message.reliable) {
        accepted.push(message);
      } else if (covering === null) {
        covering = message;
        accepted.push(message);
      } else {
        (covering.riders ??= []).push(message);
      }
    }
    for (const message of accepted) {
      if (message.reliable) {
        this.#acceptReliable(message, result, acknowledgeSequences);
      } else {
        this.#acceptUnreliable(message, result);
      }
    }
    for (const sequence of acknowledgeSequences) {
      const ack = encodeTransportAck({ token: this.#token, acknowledgedSequence: sequence });
      this.#transmit(ack, { kind: 'ack', sequence });
      result.acknowledgements.push(ack);
    }
    result.receiveBase = this.#receiveBase;
    return result;
  }

  /**
   * Close the channel: cancel every timer it owns and drop its buffers.
   *
   * Returns how many timing entries were cancelled. After this the wheel's
   * `assertOwnerDrained(channel)` passes, which is how a session teardown proves
   * it leaked nothing instead of a reviewer having to notice.
   */
  close() {
    if (this.#closed) return 0;
    this.#closed = true;
    const cancelled = this.#wheel.cancelOwner(this);
    this.#unacknowledged.clear();
    this.#gap.clear();
    this.#gapTimerHandle = null;
    return cancelled;
  }

  /* ---- inbound ---------------------------------------------------------- */

  #acceptReliable(message, result, acknowledgeSequences) {
    /*
     * Acked whatever happens next - including a duplicate below the base. The
     * peer only retransmits because its ack never arrived, and its retry budget
     * is finite (48, then its transport dies in silence). Note the asymmetry:
     * the CLIENT frees a below-base segment un-acked (`FUN_001d6988.c:34`); the
     * server does not copy that, because the standing rig-graded obligation is
     * to ack every reliable inbound (gap table X1).
     */
    if (!acknowledgeSequences.includes(message.sequence)) {
      acknowledgeSequences.push(message.sequence);
    }
    /*
     * Each parsed rider's own id is acked too, deduplicated - the pre-branch
     * build's emission, RESTORED 2026-08-08 (nora pre-deploy review, fix 1).
     * Riders ride the covering ACCEPTANCE (their stale sequence field decides
     * nothing about delivery), but the rig-graded obligation is "ack every
     * reliable inbound" (gap table X1) and the claim that the rider acks match
     * nothing client-side is Inference grade only (B2-JOIN-FREEZE-EVIDENCE.md
     * §6: "graded harmless noise - Inference"); months of rig runs prove them
     * at least harmless, so the proven emission wins over the unproven saving.
     */
    if (message.riders != null) {
      for (const rider of message.riders) {
        if (!acknowledgeSequences.includes(rider.sequence)) {
          acknowledgeSequences.push(rider.sequence);
        }
      }
    }

    if (message.sequence < this.#receiveBase || this.#gap.has(message.sequence)) {
      // A duplicate covering message was already delivered once, riders and
      // all - re-delivering the riders would double-dispatch their queries.
      result.duplicates.push(message);
      if (message.riders != null) result.duplicates.push(...message.riders);
      return;
    }

    if (message.sequence !== this.#receiveBase) {
      // The buffer and its expiry timer are ONE resource: an entry the wheel has
      // no room to expire would be pinned for the life of the session, which is
      // the unbounded growth this rewrite exists to remove.
      const hasRoom = this.#gap.size < this.#maximumGapEntries;
      if (!hasRoom || !this.#armGapTimer()) {
        /*
         * Refused AND unacknowledged - the one place an ack is withheld on
         * purpose, because accepting it would mean promising to deliver a
         * message there is no room to hold. The peer retransmits it, which is
         * exactly the backpressure wanted. Nothing already buffered is evicted:
         * those were acknowledged, so the peer will never send them again.
         */
        // The riders' acks are withheld WITH the covering message's: nothing
        // from a refused datagram is promised, and the peer retransmits it whole.
        const withheld = [
          message.sequence, ...(message.riders ?? []).map((rider) => rider.sequence)
        ];
        for (const sequence of withheld) {
          const index = acknowledgeSequences.indexOf(sequence);
          if (index >= 0) acknowledgeSequences.splice(index, 1);
        }
        result.refusals.push({
          code: hasRoom ? 'TIMER_CAPACITY' : 'GAP_FULL',
          detail: `sequence ${message.sequence}`
        });
        return;
      }
      this.#gap.set(message.sequence, message);
      result.bufferedSequences.push(message.sequence);
      return;
    }

    // In order: release this one and everything the gap now makes contiguous.
    this.#release(message, result);
    this.#receiveBase = (this.#receiveBase + 1) >>> 0;
    while (this.#gap.has(this.#receiveBase)) {
      this.#release(this.#gap.get(this.#receiveBase), result);
      this.#gap.delete(this.#receiveBase);
      this.#receiveBase = (this.#receiveBase + 1) >>> 0;
    }
    // The timer measures how long the CURRENT hole has gone unfilled, so progress
    // restarts it and an empty buffer disarms it.
    if (this.#gap.size === 0) this.#disarmGapTimer();
    else this.#armGapTimer({ rearm: true });
  }

  /**
   * Deliver one covering message and, in datagram order, the reliable
   * sub-messages riding it. Riders were accepted under the covering sequence -
   * a gap-buffered covering message keeps them attached and releases them here
   * when the cascade reaches it, so a rider can never outlive or predate its
   * covering message in the delivered stream.
   */
  #release(message, result) {
    result.delivered.push(message);
    if (message.riders != null) result.delivered.push(...message.riders);
  }

  #acceptUnreliable(message, result) {
    if (this.#unreliableHighWater !== null && message.sequence < this.#unreliableHighWater) {
      result.duplicates.push(message);
      return;
    }
    // `conn+0x10 <= seq` (`FUN_001d6988.c:25`): an EQUAL sequence is delivered
    // again. Mirrored here so the server and the client agree on what a repeat of
    // an unreliable message means.
    this.#unreliableHighWater = message.sequence;
    if (message.data || message.payload.length > 0) {
      result.delivered.push(message);
      return;
    }
    // A bare 0x6010 ack carries no opcode and no body. Its ack field was consumed
    // above; handing the husk to the application would be noise.
    result.transportOnly.push(message);
  }

  #acknowledge(sequence) {
    if (this.#highestPeerAcknowledgement === null || sequence > this.#highestPeerAcknowledgement) {
      this.#highestPeerAcknowledgement = sequence;
    }
    // Exact id, never cumulative: `FUN_001e1ac8` frees the one matching block and
    // no-ops on anything else, so a higher ack says nothing about a lower one.
    const entry = this.#unacknowledged.get(sequence);
    if (entry == null) return false;
    this.#unacknowledged.delete(sequence);
    this.#wheel.cancel(entry.handle);
    return true;
  }

  /* ---- outbound --------------------------------------------------------- */

  #emitReliable({ opcode, subSelector, payload, flags, sequence, mirrored }) {
    this.#requireSendableFlags(flags, true);
    if (this.#unacknowledged.has(sequence)) {
      // Two live reliable messages on one sequence: the client enqueues both,
      // delivers one, and leaks the twin's buffer out of the conn+0x520 pool.
      fail(
        'SEQUENCE_IN_FLIGHT',
        `reliable sequence ${sequence} is already unacknowledged; a twin would leak the client's buffer`
      );
    }
    if (this.#unacknowledged.size >= this.#maximumUnacknowledged) {
      fail(
        'WINDOW_FULL',
        `refusing to send: ${this.#unacknowledged.size} messages are already unacknowledged`
      );
    }

    const datagram = encodeDatagram([
      { flags: flags | FLAG_RELIABLE, subSelector, opcode, token: this.#token, sequence, payload }
    ]);
    const entry = { sequence, datagram, retransmissions: 0, handle: null, mirrored, opcode };
    // Armed BEFORE it is recorded: the wheel is bounded and may refuse, and an
    // entry in the window with no timer would never be retransmitted and never
    // reach the retry cap - it would just sit there, which is the silence this
    // whole module exists to remove. The wheel cannot fire before this returns.
    entry.handle = this.#armRetransmit(entry);
    this.#unacknowledged.set(sequence, entry);
    this.#transmit(datagram, {
      kind: mirrored ? 'mirrored' : 'reliable', sequence, opcode, retransmission: 0
    });
    return datagram;
  }

  #requireSendableFlags(flags, reliable) {
    if (!Number.isInteger(flags) || flags < 0 || flags > 0xffff || (flags & LENGTH_MASK) !== 0) {
      fail('INVALID_FLAGS', 'flags must be a uint16 with the low ten length bits clear');
    }
    if ((flags & FLAG_AGGREGATE) !== 0) {
      // A wrongly set 0x0800 aborts the whole segment un-acked in the client
      // (`op06-accept-criterion-RE-2026-07-26.txt:135-139`). Refused, not cleared:
      // a caller that asked for batching must learn it cannot have it.
      fail('AGGREGATE_UNSUPPORTED', 'this channel emits one message per datagram; MORE_MESSAGES is refused');
    }
    if (!reliable && (flags & FLAG_RELIABLE) !== 0) {
      fail('FLAG_CONTRADICTS_SEND', 'sendUnreliable was given the RELIABLE flag; use sendReliable');
    }
  }

  #armRetransmit(entry) {
    const delayMs =
      this.#retransmissionTimeoutMs + entry.retransmissions * this.#retransmissionBackoffStepMs;
    return this.#wheel.schedule({
      delayMs,
      owner: this,
      name: `retransmit:${entry.sequence}`,
      callback: () => this.#onRetransmit(entry)
    });
  }

  #onRetransmit(entry) {
    if (this.#closed || this.#dead !== null) return;
    if (this.#unacknowledged.get(entry.sequence) !== entry) return;
    if (entry.retransmissions >= this.#maximumRetransmissions) {
      this.#die(CHANNEL_DEATH.RETRANSMISSION_EXHAUSTED, {
        sequence: entry.sequence,
        retransmissions: entry.retransmissions
      });
      return;
    }
    entry.retransmissions += 1;
    // Re-armed BEFORE the send, so a transmit that throws leaves a channel that
    // still has a timer rather than one message stuck forever with none.
    entry.handle = this.#armRetransmit(entry);
    this.#transmit(entry.datagram, {
      kind: entry.mirrored ? 'mirrored' : 'reliable',
      sequence: entry.sequence,
      opcode: entry.opcode,
      retransmission: entry.retransmissions
    });
  }

  /* ---- the gap timer ---------------------------------------------------- */

  /** Returns whether a live expiry timer covers the gap buffer afterwards. */
  #armGapTimer({ rearm = false } = {}) {
    if (this.#gapTimerHandle !== null) {
      if (!rearm) return true;
      this.#wheel.cancel(this.#gapTimerHandle);
      this.#gapTimerHandle = null;
    }
    try {
      this.#gapTimerHandle = this.#wheel.schedule({
        delayMs: this.#gapExpiryMs,
        owner: this,
        name: 'gap-expiry',
        callback: () => this.#onGapExpiry()
      });
    } catch (error) {
      // The wheel is shared and bounded, and it refuses rather than evicting. A
      // refusal is reported to the caller as a refused segment; anything that is
      // NOT the wheel saying "full" is a defect and must not be swallowed.
      if (typeof error?.code !== 'string' || !error.code.startsWith('WHEEL_')) throw error;
      this.#gapTimerHandle = null;
      return false;
    }
    return true;
  }

  #disarmGapTimer() {
    if (this.#gapTimerHandle === null) return;
    this.#wheel.cancel(this.#gapTimerHandle);
    this.#gapTimerHandle = null;
  }

  #onGapExpiry() {
    this.#gapTimerHandle = null;
    if (this.#closed || this.#dead !== null || this.#gap.size === 0) return;
    /*
     * The hole was never filled. Every buffered segment behind it was already
     * acknowledged, so the peer will not send them again and ordered delivery can
     * never resume - which makes this terminal rather than an eviction that
     * quietly continues with a stream that has a permanent hole in it.
     */
    this.#die(CHANNEL_DEATH.GAP_ABANDONED, {
      receiveBase: this.#receiveBase,
      buffered: this.gapSequences()
    });
  }

  /* ---- terminal state --------------------------------------------------- */

  #die(reason, detail) {
    if (this.#dead !== null) return;
    this.#dead = { reason, detail };
    this.#wheel.cancelOwner(this);
    this.#unacknowledged.clear();
    this.#gap.clear();
    this.#gapTimerHandle = null;
    this.#onTransportDead?.({ channel: this, reason, detail });
  }

  #requireLive(operation) {
    if (this.#closed) fail('CHANNEL_CLOSED', `${operation} on a closed channel`);
    if (this.#dead !== null) {
      fail('CHANNEL_DEAD', `${operation} on a dead channel (${this.#dead.reason})`);
    }
  }

  #refuse(result, code, detail = null) {
    result.refusals.push({ code, detail });
    return result;
  }

  /* ---- framing ---------------------------------------------------------- */

  /**
   * Decode ONE message header.
   *
   * Deliberately not `decodeDatagram`: that walks the whole datagram, and
   * walking a client datagram is what corrupted Area Select in V1. The layout
   * constants still come from the codec, so there is one source of truth for the
   * bit positions; only the field offsets are restated (`FUN_001e180c`).
   */
  #decodeMessageAt(datagram, offset, limit) {
    if (limit - offset < HEADER_LENGTH) {
      return { refusal: 'BAD_LENGTH', detail: `${limit - offset} bytes left for a 16-byte header` };
    }
    const flagsAndLength = datagram.readUInt16BE(offset);
    const innerLength = flagsAndLength & LENGTH_MASK;
    if (innerLength < HEADER_LENGTH || offset + innerLength > limit) {
      return { refusal: 'BAD_LENGTH', detail: `declared ${innerLength} at offset ${offset}` };
    }
    const raw = datagram.subarray(offset, offset + innerLength);
    return {
      message: {
        offset,
        innerLength,
        flags: flagsAndLength & FLAG_MASK,
        reliable: (flagsAndLength & FLAG_RELIABLE) !== 0,
        acknowledges: (flagsAndLength & FLAG_ACK) !== 0,
        set: (flagsAndLength & FLAG_SET) !== 0,
        data: (flagsAndLength & FLAG_DATA) !== 0,
        // snap-codec calls this bit `aggregate`; it means "another message follows".
        moreMessages: (flagsAndLength & FLAG_AGGREGATE) !== 0,
        subSelector: raw[2],
        opcode: raw[3],
        opcodeWord: raw.readUInt16BE(2),
        token: Buffer.from(raw.subarray(4, 8)),
        sequence: raw.readUInt32BE(8),
        acknowledgement: raw.readUInt32BE(12),
        // Copied, not a view: a buffered gap entry that kept a subarray would pin
        // the whole receive buffer, which is how 20 000 gap entries held 17.2 MB.
        payload: Buffer.from(raw.subarray(HEADER_LENGTH))
      }
    };
  }

  #walk(datagram, startOffset, trailerOffset) {
    const messages = [];
    let offset = startOffset;
    while (offset < trailerOffset) {
      if (messages.length + 1 >= this.#maximumMessagesPerDatagram) {
        // Stop at the bound and let the caller refuse the datagram whole, rather
        // than parsing an unbounded number of headers to find out how many there
        // were.
        return { refusal: 'TOO_MANY_MESSAGES', detail: `more than ${this.#maximumMessagesPerDatagram}` };
      }
      const decoded = this.#decodeMessageAt(datagram, offset, trailerOffset);
      if (decoded.refusal != null) {
        return { refusal: 'BATCH_MALFORMED', detail: decoded.detail };
      }
      messages.push(decoded.message);
      offset += decoded.message.innerLength;
    }
    return { messages };
  }
}

export function createReliableChannel(options) {
  return new ReliableChannel(options);
}
