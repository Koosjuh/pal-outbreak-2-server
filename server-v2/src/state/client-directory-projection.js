import { decodeSnapField } from '../protocol/snap-field-codec.js';
import { DIRECTORY_LIMITS, DirectoryState } from './directory-state.js';

/**
 * One connection's view of the authoritative directory.
 *
 * Everything that changes as a client walks its initialization sequence lives
 * here and nowhere else: the field codec word, the traversal position, which
 * records the client currently holds, and the correlation data that lets a
 * `0x6510` request be answered by key. Closing a connection discards exactly
 * this object; the `DirectoryState` it read is untouched.
 *
 * Two connections therefore hold independent projections, may sit at different
 * entries, and may have different records resident at the same moment.
 *
 * ## This is a PREDICTION of state the server cannot see
 *
 * The client's slot table, per-entry counts and cursors live in its own memory.
 * The server never observes them; it reconstructs them from what it sent. That
 * makes any divergence between this model and the real client show up as a
 * `0x6510` request that does not match the window this projection expects, which
 * is failed closed. When that happens the cause may be a misbehaving client OR
 * this model being wrong, and the diagnostics say so rather than blaming the
 * client. Only a real-client capture can settle which.
 *
 * ## The residency budget is the client's, not the server's
 *
 * `FUN_001c7a70` assigns record slots from ONE 64-entry ownership table at
 * `0x3619d0` shared by every entry (`0x001c7b58 addiu a0,a0,6608`; capacity
 * checks at `0x001c7c08`, `0x001c7cfc`, `0x001c8370`; `li v1,64` at
 * `0x001c7f6c`). That bounds what one CLIENT holds resident. It is not a limit
 * on authoritative state, and eviction here never deletes anything from
 * `DirectoryState`.
 *
 * Allocation, proved in the record loop: the slot index is `poolCursor + i`, and
 * an inner loop advances `poolCursor` while that slot is neither free (`0xffff`)
 * nor already owned by the current entry. The cursor resets to zero for each new
 * entry (`uRam00365e12 = 0` in the parser tail).
 *
 * Eviction, proved at `0x001c7d18 daddiu a0,zero,0x3f` with
 * `0x001c7e1c addiu a0,a0,-1` and `0x001c7e28 bgez a2,0x1c7d2c`: when the other
 * entries' totals plus this entry's declared total exceed `0x40`, the client
 * scans the slot table DOWNWARD from slot 63, skipping free slots and slots the
 * current entry owns, and frees each victim owner's whole entry - its slots, its
 * `+0x158` count and its `+0x15c` value - until enough room exists. Because
 * slots are handed out forward from a cursor that resets per entry, the highest
 * occupied slot belongs to the most recently seated entry, so the newest
 * neighbour is evicted first, not the oldest.
 *
 * ## The field codec word is connection state
 *
 * `FUN_001c3b90` (decode) and `FUN_001c3f40` (encode) both pass
 * `*(u16 *)(connection + 0x4c)` to the field transform, together with header
 * byte 5 of the frame being parsed or built. Within the transport corpus the
 * only writer of that connection field is `FUN_001c4100`, which reads a BE16 out
 * of a received payload; the ELF tables bind it to command `0x1002` DIRECTION
 * `0x01`. The captured server sent `0x1002` with direction `0x02`, which the
 * tables map to a handler-less entry, so that handler never ran in any captured
 * session and `+0x4c` kept its initial value.
 *
 * The captures then settle that value empirically: all four captured `0x1007`
 * identity fields decode and checksum with codec byte `0`, and `1`, `2`, `0x7f`
 * and `0xff` all fail (`test/connection-identity.test.js`). Because the client
 * verifies the SERVER's fields with the same word, encoding with any other value
 * would make `FUN_001c3b90` return -3 and drop the connection.
 *
 * A decode that verifies is evidence about the plaintext, not proof that the
 * codec state was chosen correctly - so this class never searches codec values.
 * It uses the one word the connection is known to hold and fails closed when a
 * field will not decode under it.
 */

export const PROJECTION_PHASE = Object.freeze({
  RECORD_DELIVERY: 'record-delivery',
  KEY_EXCHANGE: 'key-exchange',
  COMPLETE: 'complete'
});

export class ProjectionError extends Error {
  constructor(code, message) {
    super(message);
    this.name = 'ProjectionError';
    this.code = code;
  }
}

function fail(code, message) {
  throw new ProjectionError(code, message);
}

/**
 * `FUN_001c85c0` caps its request batch with `li v0,12` at `0x001c85cc` and only
 * lowers it toward the remaining record count, so a client never asks for more
 * than twelve keys at once.
 */
const MAXIMUM_KEY_BATCH = 0x0c;

/** `0x6504` serializes its batch count in one byte. */
const MAXIMUM_RECORD_BATCH = 0xff;

const FREE_SLOT = null;

export class ClientDirectoryProjection {
  #directory;
  #codecByte;
  #recordBatchSize;
  #phase = PROJECTION_PHASE.RECORD_DELIVERY;
  #entryIndex = 0;
  // How many entries 0x6503 has delivered. Mirrors the client's own 0x365e18
  // during the entry-list phase, and is the only thing a 0x6503 offset is
  // checked against. It is separate from #entryIndex, which tracks the RECORD
  // walk that follows.
  #entryCursor = 0;
  #deliveredCount = 0;
  #keyCursor = 0;
  // The client's shared slot table: slot index -> owning entry index, or null.
  #slotOwner = new Array(DIRECTORY_LIMITS.clientResidencyBudget).fill(FREE_SLOT);
  #poolCursor = 0;
  /*
   * Per entry index: `{ declaredTotal, records: [{ entryIndex, recordId, key,
   * slot, sequence }] }`.
   *
   * A REFERENCE - entry index plus record id - never the answer. It used to hold
   * `word: record.unknownWord6510`, a VALUE copied at `0x6504`-delivery time and
   * replayed several round trips later when `0x6510` asked. That is the same
   * ordering defect as recording presence only at the deepest level: the number
   * on the wire described a moment that had already passed. It was latent only
   * because the value was a literal 0 in the shipped directory; it becomes a real
   * wrong answer the instant that count goes live.
   */
  #resident = new Map();
  #resolveRecordWord;

  constructor({ directory, codecByte, recordBatchSize = null, resolveRecordWord = null }) {
    if (!(directory instanceof DirectoryState)) {
      fail('PROJECTION_DIRECTORY', 'a projection requires a DirectoryState');
    }
    if (!Number.isSafeInteger(codecByte) || codecByte < 0 || codecByte > 0xff) {
      fail('PROJECTION_CODEC_STATE', "codecByte must be the connection's unsigned byte");
    }
    if (recordBatchSize !== null &&
        (!Number.isSafeInteger(recordBatchSize) ||
         recordBatchSize < 1 || recordBatchSize > MAXIMUM_RECORD_BATCH)) {
      fail(
        'PROJECTION_BATCH_SIZE',
        `recordBatchSize must be null or 1..${MAXIMUM_RECORD_BATCH}`
      );
    }
    if (resolveRecordWord !== null && typeof resolveRecordWord !== 'function') {
      fail('PROJECTION_WORD_RESOLVER', 'resolveRecordWord must be a function when supplied');
    }
    this.#directory = directory;
    this.#codecByte = codecByte;
    this.#recordBatchSize = recordBatchSize ?? MAXIMUM_RECORD_BATCH;
    /*
     * The seam through which a LIVE count reaches `0x6510`. The default reads the
     * authored directory, which is what shipped and is a constant; supplying a
     * resolver is what makes the "current players" field describe the population
     * at the moment the client asks. Either way it is evaluated AT ANSWER TIME.
     */
    this.#resolveRecordWord = resolveRecordWord ??
      (({ record }) => record.unknownWord6510);
  }

  get phase() {
    return this.#phase;
  }

  get entryIndex() {
    return this.#entryIndex;
  }

  get codecByte() {
    return this.#codecByte;
  }

  /** Records the client currently holds across all entries. Never above 64. */
  get residentRecordCount() {
    return this.#slotOwner.reduce(
      (total, owner) => (owner === FREE_SLOT ? total : total + 1), 0
    );
  }

  residentEntryIndexes() {
    return [...this.#resident.keys()]
      .filter((entryIndex) => this.#resident.get(entryIndex).records.length > 0)
      .sort((left, right) => left - right);
  }

  residentRecordCountForEntry(entryIndex) {
    const entry = this.#resident.get(entryIndex);
    return entry == null ? 0 : entry.records.length;
  }

  /**
   * Resolve one resident record's `0x6510` word, NOW.
   *
   * The client writes this straight to record `+0x12c` with no comparison found,
   * so a value that differs between two ladder runs is Hypothesis-safe but has
   * never been tested with a changing number. What is settled is that answering
   * from a copy taken at `0x6504` time is wrong whatever the source.
   */
  #resolveWordFor(resident) {
    const entry = this.#directory.entryAt(resident.entryIndex);
    const record = entry?.records.find((candidate) => candidate.recordId === resident.recordId);
    if (record == null) {
      // The directory was replaced under a live projection. Fail closed and named
      // rather than answer 0, which the client would render as an empty server.
      fail(
        'PROJECTION_RECORD_GONE',
        `record ${resident.recordId} of entry ${resident.entryIndex} is no longer in the ` +
        'directory; this connection is projecting a directory that has been replaced'
      );
    }
    const word = this.#resolveRecordWord({
      entryIndex: resident.entryIndex,
      recordId: resident.recordId,
      entry,
      record
    });
    if (!Number.isSafeInteger(word) || word < 0 || word > 0xffff) {
      fail(
        'PROJECTION_WORD_RANGE',
        `the 0x6510 word for record ${resident.recordId} is ${word}; the field is a BE16`
      );
    }
    return word;
  }

  #currentEntry() {
    const entry = this.#directory.entryAt(this.#entryIndex);
    if (entry == null) {
      fail(
        'PROJECTION_ENTRY_RANGE',
        `no entry at index ${this.#entryIndex}; the directory holds ${this.#directory.entryCount}`
      );
    }
    return entry;
  }

  /**
   * Advance past the entry just finished.
   *
   * Both proven paths do this: `FUN_001c7680` on a mode-0 `0x6502` reply, and
   * `FUN_001c7a70` once a batch completes an entry. Both also reset the pool
   * cursor. When the last entry is done the client restarts at entry 0 for the
   * `0x6510` phase (`uRam00365e0c = 0`, substate `0x0c`).
   */
  #finishEntry() {
    this.#entryIndex += 1;
    this.#deliveredCount = 0;
    this.#poolCursor = 0;
    if (this.#entryIndex >= this.#directory.entryCount) {
      this.#entryIndex = 0;
      this.#keyCursor = 0;
      this.#phase = PROJECTION_PHASE.KEY_EXCHANGE;
    }
  }

  /**
   * Return to the state a fresh projection starts in.
   *
   * Everything here is client state this projection predicts, and the client
   * rebuilds all of it on a mode-1 re-walk: the entry table from `0x6503`, the
   * per-entry record lists and slot ownership from `0x6504`, and the key cursor
   * from `0x6510`. Nothing authoritative is touched - `DirectoryState` is not
   * reachable from here.
   */
  #rewindForFreshWalk() {
    this.#phase = PROJECTION_PHASE.RECORD_DELIVERY;
    this.#entryIndex = 0;
    this.#entryCursor = 0;
    this.#deliveredCount = 0;
    this.#keyCursor = 0;
    this.#poolCursor = 0;
    this.#slotOwner.fill(FREE_SLOT);
    this.#resident.clear();
  }

  #evictEntry(entryIndex) {
    for (let slot = 0; slot < this.#slotOwner.length; slot += 1) {
      if (this.#slotOwner[slot] === entryIndex) {
        this.#slotOwner[slot] = FREE_SLOT;
      }
    }
    this.#resident.delete(entryIndex);
  }

  /**
   * Seat `declaredTotal` records for an entry, evicting exactly as the client
   * does. Only this projection changes: every evicted record stays in
   * `DirectoryState` and stays visible to every other connection.
   */
  #seat(entryIndex, declaredTotal) {
    let othersTotal = 0;
    for (const [index, entry] of this.#resident) {
      if (index !== entryIndex) othersTotal += entry.records.length;
    }
    if (othersTotal + declaredTotal <= DIRECTORY_LIMITS.clientResidencyBudget) return;

    let needed = othersTotal + declaredTotal - DIRECTORY_LIMITS.clientResidencyBudget;
    for (let slot = this.#slotOwner.length - 1; slot >= 0 && needed > 0; slot -= 1) {
      const owner = this.#slotOwner[slot];
      if (owner === FREE_SLOT || owner === entryIndex) continue;
      const victim = this.#resident.get(owner);
      const victimCount = victim == null ? 0 : victim.records.length;
      this.#evictEntry(owner);
      // The client stops as soon as one victim covers what is still needed.
      if (victimCount >= needed) return;
      needed -= victimCount;
    }
    if (needed > 0) {
      fail(
        'PROJECTION_RESIDENCY',
        `cannot seat ${declaredTotal} records for entry ${entryIndex} within the client's ` +
        `${DIRECTORY_LIMITS.clientResidencyBudget}-record budget`
      );
    }
  }

  /**
   * Take `count` slots the way the record loop does: the slot for record `i` is
   * `poolCursor + i`, and the cursor advances past any slot that is neither free
   * nor already this entry's.
   */
  #allocate(entryIndex, count) {
    const slots = [];
    for (let index = 0; index < count; index += 1) {
      while (
        this.#poolCursor + index < this.#slotOwner.length &&
        this.#slotOwner[this.#poolCursor + index] !== FREE_SLOT &&
        this.#slotOwner[this.#poolCursor + index] !== entryIndex
      ) {
        this.#poolCursor += 1;
      }
      const slot = this.#poolCursor + index;
      if (slot >= this.#slotOwner.length) {
        fail(
          'PROJECTION_RESIDENCY',
          `entry ${entryIndex} ran past the client's ${DIRECTORY_LIMITS.clientResidencyBudget}-slot ` +
          'record pool'
        );
      }
      this.#slotOwner[slot] = entryIndex;
      slots.push(slot);
    }
    this.#poolCursor += count;
    return slots;
  }

  /**
   * `0x6503`: the server-entry list, which is the ONLY command that writes the
   * client's entry table.
   *
   * `FUN_001c70b0` is its sole writer: it sets the entry total at `0x365e1e` and
   * streams `0x260`-byte entries into `0x365e20` as
   * host(<=0x3e) / name(<=0x0f) / 8 raw / description(<=0xff), clamping the list
   * to 16. Until it runs, the total stays 0, so Server Select renders "1/0" with
   * an empty row - the fill loop is `for i < count` and never executes.
   *
   * ## The batch is the CLIENT's window, not ours
   *
   * `FUN_001c7000` sends `[BE16 0x365e18][BE16 0x365e1a]` - the offset it has
   * already received and the count it wants, which the mode-1 `0x6501` reply set
   * to 8. Honouring both is what the parser expects: it writes entry `i` at
   * cursor `0x365e0c + i`, and only advances that cursor by the batch count it
   * was actually sent, re-requesting from the new offset while
   * `0x365e18 < 0x365e1e`. Serving more than was asked for would work by
   * accident on a short list and put ~5.6 KB in one frame on a full one, against
   * a client receive buffer whose size is Unknown.
   *
   * The offset is validated rather than clamped: an offset that is not the one
   * this projection expects means the client's cursor and ours have diverged,
   * and guessing past that would corrupt the entry table it seats.
   */
  takeCommand6503Batch({ start, count } = {}) {
    /*
     * THE RE-WALK, and ONLY from a completed one.
     *
     * `FUN_001c7000` sends the client's own `0x365e18`, and the only thing that
     * zeroes it is a mode-1 `0x6501` reply (`FUN_001c6e80`), which also zeroes
     * `0x365e0c` and sets the batch size to 8. So a `0x6503` at offset 0 on a
     * COMPLETE projection is a client that finished a ladder, reset its
     * transport, reconnected and was answered mode 1 again - which is exactly
     * what `0x6501` now does on a resumed connection (gap-table C-1, V1
     * session 6). Before this, that connection's very next `0x6503` raised
     * `PROJECTION_PHASE` and dropped the player with "could not connect to lobby
     * server"; it is the reset T32 flagged as the cost of the correction.
     *
     * Deliberately NOT triggered mid-walk. A projection still in
     * `record-delivery` has a client whose cursor has moved, so an offset of 0
     * there is a divergence and stays failed closed below.
     *
     * Rewinding to the initial state - rather than patching the phase - is what
     * the client does: it re-walks every entry with `0x6502`/`0x6504` and
     * re-seats each one's records at pool cursor 0, overwriting rather than
     * accumulating. A model that kept the old residency would then expect twice
     * the records at `0x6510`.
     */
    if (start === 0 && this.#phase === PROJECTION_PHASE.COMPLETE) {
      this.#rewindForFreshWalk();
    }
    /*
     * 0x6503 precedes record delivery on the MODE-1 route and does not exist on
     * the mode-0 route, so it is not its own phase: it is allowed only before
     * any record has been delivered. A projection that has already delivered
     * records is mid-walk and a 0x6503 there would contradict the entry table
     * the client has already seated.
     */
    if (this.#phase !== PROJECTION_PHASE.RECORD_DELIVERY ||
        this.#entryIndex !== 0 || this.#deliveredCount !== 0) {
      fail(
        'PROJECTION_PHASE',
        `0x6503 is only expected at the start of a walk, not during ${this.#phase} ` +
        `at entry ${this.#entryIndex} after ${this.#deliveredCount} delivered records`
      );
    }
    const total = this.#directory.entryCount;
    if (total === 0) {
      // The client treats a zero total as terminal, so refusing here is strictly
      // better than putting a 0 on the wire.
      fail('PROJECTION_NO_ENTRIES', '0x6503 cannot declare zero entries; the client treats it as fatal');
    }
    if (!Number.isSafeInteger(start) || start < 0 || start > 0xffff ||
        !Number.isSafeInteger(count) || count < 0 || count > 0xffff) {
      fail('PROJECTION_ENTRY_BATCH', '0x6503 start and count must be unsigned 16-bit integers');
    }
    if (start !== this.#entryCursor) {
      fail(
        'PROJECTION_ENTRY_BATCH',
        `0x6503 asked for entries from ${start} but this connection has delivered ` +
        `${this.#entryCursor} of ${total}; either the client diverged or this projection is wrong`
      );
    }
    if (count === 0) {
      fail('PROJECTION_ENTRY_BATCH', '0x6503 asked for zero entries; there is no empty batch to send');
    }
    const batchCount = Math.min(count, total - start);
    if (batchCount === 0) {
      fail(
        'PROJECTION_ENTRY_BATCH',
        `0x6503 asked for entries from ${start} but the directory holds only ${total}`
      );
    }
    const entries = [];
    for (let index = start; index < start + batchCount; index += 1) {
      const entry = this.#directory.entryAt(index);
      entries.push({
        host: Buffer.from(entry.host),
        name: Buffer.from(entry.name),
        raw8: Buffer.from(entry.raw8),
        description: Buffer.from(entry.description)
      });
    }
    this.#entryCursor = start + batchCount;
    // The phase is unchanged: 0x6502 follows and record delivery proceeds
    // exactly as it does on the mode-0 route.
    return { total, batchStart: start, unknownCodecByte: this.#codecByte, entries };
  }

  /**
   * `0x6502`: does the current entry still owe the client records?
   *
   * Mode 1 sends the client to `0x6504` for this entry; mode 0 advances it. Both
   * routes are proven by `FUN_001c7680`; which one to take is a server decision
   * over that proven routing, and the two mode-1 BE32 values are opaque values
   * the operator configured on the entry.
   */
  selectCommand6502Response() {
    if (this.#phase !== PROJECTION_PHASE.RECORD_DELIVERY) {
      fail('PROJECTION_PHASE', `0x6502 is not expected during ${this.#phase}`);
    }
    const entry = this.#currentEntry();
    if (this.#deliveredCount >= entry.records.length) {
      this.#finishEntry();
      return { mode: 0 };
    }
    return {
      mode: 1,
      unknown0: entry.command6502Unknown0,
      unknown1: entry.command6502Unknown1
    };
  }

  /**
   * `0x6504`: the next batch of the current entry's records.
   *
   * `unknownStart` is not decorative. `FUN_001c7a70` loads it straight into the
   * client's own progress counter `uRam00365e18` and then adds the batch count,
   * so the server's start value is what decides whether the client asks for
   * another batch or moves on.
   */
  takeCommand6504Batch({ sequence }) {
    if (this.#phase !== PROJECTION_PHASE.RECORD_DELIVERY) {
      fail('PROJECTION_PHASE', `0x6504 is not expected during ${this.#phase}`);
    }
    const entry = this.#currentEntry();
    const total = entry.records.length;
    if (total === 0) {
      fail(
        'PROJECTION_EMPTY_ENTRY',
        `entry ${this.#entryIndex} has no records; it should have been skipped with 0x6502 mode 0`
      );
    }
    const start = this.#deliveredCount;
    const batch = entry.records.slice(start, start + this.#recordBatchSize);
    if (batch.length === 0) {
      fail('PROJECTION_BATCH_EXHAUSTED', `entry ${this.#entryIndex} has no records left to send`);
    }

    // The client seats the whole declared total when it parses the first batch.
    if (start === 0) this.#seat(this.#entryIndex, total);
    const slots = this.#allocate(this.#entryIndex, batch.length);
    let resident = this.#resident.get(this.#entryIndex);
    if (resident == null) {
      resident = { declaredTotal: total, records: [] };
      this.#resident.set(this.#entryIndex, resident);
    }
    resident.declaredTotal = total;
    batch.forEach((record, index) => {
      resident.records.push({
        // A reference, resolved when 0x6510 asks. NOT the word.
        entryIndex: this.#entryIndex,
        recordId: record.recordId,
        key: record.unknownField0.toString('latin1'),
        slot: slots[index],
        sequence
      });
    });

    this.#deliveredCount = start + batch.length;
    if (this.#deliveredCount >= total) {
      this.#finishEntry();
    }

    return {
      unknownTotal: total,
      unknownStart: start,
      unknownCodecByte: this.#codecByte,
      // Copied out: the provider hands these to the encoder, and authoritative
      // state must not be reachable through a response object.
      records: batch.map((record) => ({
        unknownField0: Buffer.from(record.unknownField0),
        unknownField1: Buffer.from(record.unknownField1),
        unknownRaw8: Buffer.from(record.unknownRaw8),
        unknownField2: Buffer.from(record.unknownField2),
        unknownWord0: record.unknownWord0,
        unknownWord1: record.unknownWord1,
        unknownDword: record.unknownDword
      }))
    };
  }

  /**
   * `0x6510`: answer one BE16 per requested key, in request order.
   *
   * The client identifies records BY KEY on the way out - `FUN_001c85c0` sends
   * each resident record's `unknownField0`, the string the server itself supplied
   * in `0x6504` - and consumes the answer BY POSITION, storing reply word `i`
   * into the record at cursor `uRam00365e10 + i` (`0x001c8900 sh v0,300(v1)`).
   * Both halves are honoured: keys are matched, and the words come back in the
   * order the keys arrived.
   *
   * Every failure here is closed. An undecodable key, an unknown or stale key, a
   * duplicate, a key belonging to another entry, or a count that does not match
   * the window the client should be asking for all raise rather than guess.
   */
  resolveCommand6510Response({ sequence, encodedRecordFields }) {
    // A RESUMED connection re-enters the key exchange over records the client
    // still holds. After a completed ladder this projection sits at COMPLETE
    // with entryIndex 0 and keyCursor 0, and the client - which kept its own
    // directory state across the transport reset - restarts the SAME positional
    // window at cursor 0.
    //
    // Grounded twice over, and this was the gate on the whole slice:
    //
    //   Runtime (T28, 2026-08-05, two-record directory): the resumed 0x6510
    //   carried count=2 with keys "E0R0" AND "E0R1" - both resident records, in
    //   order - not one targeted key. With one record it had carried one key,
    //   which is why the single-record fixture could not tell the two models
    //   apart and why the fixture, not the code, was the thing to change.
    //
    //   Corpus (FUN_001c8790, the client's own 0x6510 receiver): the client
    //   keeps cursor `uRam00365e10` and batch count `uRam00365e1a`, gates on
    //   `replyCount == uRam00365e1a`, then advances the cursor and clamps the
    //   next batch to the records remaining. The positional window is the
    //   CLIENT's model, proven statically and independently of the capture.
    //
    // So re-entry restores exactly what the existing window computation already
    // expects; nothing about the count, the ordering or the codec changes.
    // Only a session-owned projection can do this - a connection-owned one is
    // empty here, which is what produced COMMAND_6510_RESPONSE_PROVIDER and the
    // player-visible "could not connect to lobby server".
    if (this.#phase === PROJECTION_PHASE.COMPLETE) {
      /*
       * The question is whether this projection holds ANY records, not whether
       * entry 0 does.
       *
       * It asked about entry 0 until 2026-08-06, and that was wrong for an
       * ordinary directory: an entry with no records is skipped by `0x6502`
       * mode 0 and seats nothing, so a first entry with no rooms made every
       * resume fail with the very error this branch exists to prevent - the
       * player-visible "could not connect to lobby server". It was unreachable
       * only because the client could not walk past entry 0 until `0x6503`
       * shipped, which is exactly the kind of latent defect T32 makes live.
       *
       * COMPLETE with nothing resident anywhere IS still unreachable - a
       * projection only reaches COMPLETE by walking records - so it stays failed
       * closed rather than re-entering an exchange with nothing to answer from.
       */
      if (this.residentRecordCount === 0) {
        fail(
          'PROJECTION_RESUME_EMPTY',
          'a resumed 0x6510 arrived on a completed projection that holds no records; ' +
          'the retained state is gone rather than merely finished'
        );
      }
      this.#phase = PROJECTION_PHASE.KEY_EXCHANGE;
      this.#entryIndex = 0;
      this.#keyCursor = 0;
    }
    if (this.#phase !== PROJECTION_PHASE.KEY_EXCHANGE) {
      fail('PROJECTION_PHASE', `0x6510 is not expected during ${this.#phase}`);
    }
    const entry = this.#currentEntry();
    const resident = this.#resident.get(this.#entryIndex);
    const residentRecords = resident == null ? [] : resident.records;

    const remaining = residentRecords.length - this.#keyCursor;
    const expectedCount = Math.max(0, Math.min(MAXIMUM_KEY_BATCH, remaining));
    if (encodedRecordFields.length !== expectedCount) {
      fail(
        'PROJECTION_KEY_BATCH',
        `entry ${this.#entryIndex} expected ${expectedCount} keys at cursor ${this.#keyCursor} ` +
        `but the request carried ${encodedRecordFields.length}; either the client diverged or ` +
        'this projection of its resident records is wrong'
      );
    }

    const window = residentRecords.slice(this.#keyCursor, this.#keyCursor + expectedCount);
    const available = new Map(window.map((record) => [record.key, record]));
    const seen = new Set();
    const recordWords = [];
    for (let index = 0; index < encodedRecordFields.length; index += 1) {
      const decoded = decodeSnapField({
        field: encodedRecordFields[index],
        maximumDecodedLength: DIRECTORY_LIMITS.maximumField0Length,
        sequence,
        unknownCodecByte: this.#codecByte
      });
      if (decoded == null) {
        fail(
          'PROJECTION_KEY_DECODE',
          `0x6510 key ${index} does not decode under this connection's codec state`
        );
      }
      const key = decoded.toString('latin1');
      if (seen.has(key)) {
        fail('PROJECTION_KEY_DUPLICATE', `0x6510 repeats key ${JSON.stringify(key)}`);
      }
      seen.add(key);
      const match = available.get(key);
      if (match == null) {
        fail(
          'PROJECTION_KEY_UNKNOWN',
          `0x6510 key ${index} ${JSON.stringify(key)} is not a record this connection currently ` +
          `holds in entry ${this.#entryIndex} at cursor ${this.#keyCursor}`
        );
      }
      recordWords.push(this.#resolveWordFor(match));
    }

    this.#keyCursor += expectedCount;
    if (this.#keyCursor >= residentRecords.length) {
      this.#keyCursor = 0;
      this.#entryIndex += 1;
      if (this.#entryIndex >= this.#directory.entryCount) {
        this.#entryIndex = 0;
        this.#phase = PROJECTION_PHASE.COMPLETE;
      }
    }

    return {
      unknownCodecByte: this.#codecByte,
      recordWords,
      /*
       * THE ENTRY HOST, not pageField. T30 (2026-08-05) proved the client takes
       * this trailing field, stores it at entry +0x00 (FUN_001c8790), and on
       * selection RESOLVES IT AS A CONNECT TARGET - our pageField "PAL-V2-0"
       * produced an NXDOMAIN and the client's "server too busy" fallback with no
       * socket ever opened. It is a connect target, not a label.
       */
      unknownTrailingField: Buffer.from(entry.host)
    };
  }
}

export function createClientDirectoryProjection(options) {
  return new ClientDirectoryProjection(options);
}
