/**
 * The single timing facility for the SN@P subsystem.
 *
 * ## Why a wheel and not `setTimeout`
 *
 * Every session needs at least four independent deadlines - a keepalive, a
 * session watchdog, gap-buffer expiry, and one retransmit timer per
 * unacknowledged reliable message. At the target of hundreds to thousands of
 * concurrent players that is 4000+ live `Timeout` objects, each one a heap
 * allocation the libuv timer heap must keep ordered, and each one a distinct
 * wakeup. This is not a refactor of something that exists: an audit of the
 * current tree found roughly one timer per connection (`socket.setTimeout` in
 * the TCP and DNAS services) and NO timers at all in the UDP path, so the
 * subsystem being written has no timing facility to inherit.
 *
 * A hashed timing wheel replaces all of it with ONE interval for the process.
 * Scheduling is O(1), cancelling is O(1), and cost per tick is proportional to
 * the entries actually due rather than to the number of sessions alive.
 *
 * ## This module hardcodes NO protocol durations
 *
 * Every delay is supplied by the caller. That is deliberate. The client's own
 * timeouts are frame-counted, not millisecond-counted - `FUN_005c7d40`
 * (`keepalive_timeout_tick`) counts an idle timer down to a ping and an ack
 * timer down to declaring the link dead, and `FUN_005b68e0` re-arms a shared
 * watchdog with `0xE10` = 3600 frames (~60 s at 60 Hz). Those are the client's
 * numbers, they live in the protocol slice, and burying a copy of them in a
 * generic timing facility is how two sources of truth start disagreeing.
 *
 * The "55.2 s client watchdog" IS grounded, and an earlier note here that said
 * otherwise was wrong. It is not a constant, which is why looking for one found
 * nothing: `conn+0x51c = conn+0x510 * 32 + 4000` ms
 * (`analysis/FOUR-UNKNOWNS-CLOSED.md`), `conn+0x510` is the `LC` TLV the client
 * puts in its own register and bind - an ELF string at `0x259290` - and every
 * client this project has seen on the wire sends `LC = 1600`, which is where
 * 55 200 ms comes from. It is a PER-SESSION value the client declares, so it
 * lives with the sessions that read it (`udp/snap-lobby-sessions.js`,
 * `watchdogBudgetMsFromLatencyTicks`) and still does not belong here.
 *
 * ## Drift and late ticks: catch up, coalesce, never duplicate, never drop
 *
 * A `setInterval` is not delivered on time. GC pauses, a busy event loop, and
 * host suspend all mean the wheel is handed a gap rather than a tick. Three
 * policies were available and the choice matters:
 *
 *   DROP the missed ticks. Rejected outright. A dropped retransmit timer wedges
 *   a session forever and a dropped watchdog leaks it - silently, and only under
 *   load, which is exactly when it is hardest to diagnose.
 *
 *   FIRE PER MISSED TICK. Rejected. It re-fires nothing (an entry lives in one
 *   slot) but it does walk one slot per missed tick, so an hour of host suspend
 *   is 36000 slot walks in one turn of the event loop.
 *
 *   CATCH UP, COALESCED - what this implements. The cursor advances over every
 *   missed tick so that the `rounds` bookkeeping stays exact, all entries that
 *   came due across the whole gap are collected, and each fires EXACTLY ONCE, in
 *   deadline order. The burst is therefore bounded by the number of entries
 *   scheduled, never by the length of the stall: a 30-second stall cannot
 *   produce 300 ticks worth of stampede, only the at-most-N firings that were
 *   already owed. Beyond one full revolution the per-tick walk is replaced by a
 *   single sweep that re-homes surviving entries from their absolute deadlines,
 *   so the cost of a long suspend is one pass over the wheel rather than one
 *   pass per missed tick.
 *
 * Drift is handled separately from lateness. The tick base advances by
 * `elapsedTicks * tickMs` and NOT to "now", so the sub-tick remainder is
 * carried. Snapping the base to now would discard a few milliseconds on every
 * tick, and a keepalive that is late by the interval's jitter on every period
 * accumulates into a missed deadline over a long session. Because the remainder
 * is kept, an entry scheduled 200 ms out fires after 200 ms of real time even if
 * the interval is delivered at 149 ms and 200 ms.
 *
 * A clock that moves BACKWARDS advances nothing. Hence the default clock is
 * `performance.now()`, which is monotonic; `Date.now()` steps backwards on an
 * NTP correction, which under a naive implementation would freeze every timer
 * for the length of the correction and then release them together.
 *
 * ## Bounded, and bounded per owner
 *
 * Two limits, both failing closed with a named code and neither ever evicting a
 * live entry - evicting would silently discard exactly the watchdog or
 * retransmit whose absence is unrecoverable. The global limit protects the
 * process. The per-owner limit is the one that matters for hostile input: a
 * global limit alone lets a single unauthenticated peer consume the whole
 * budget and starve every established session, which is a denial of service on
 * everyone else rather than on the attacker.
 *
 * ## Leak checking is mechanical
 *
 * Entries are indexed by owner, so closing a session cancels its timers as a
 * group in one call, and `assertOwnerDrained` turns "did we clean up?" into an
 * assertion the shutdown path can make rather than something a reviewer has to
 * notice.
 */

export class TimingWheelError extends Error {
  constructor(code, message) {
    super(message);
    this.name = 'TimingWheelError';
    this.code = code;
  }
}

function fail(code, message) {
  throw new TimingWheelError(code, message);
}

/**
 * 100 ms resolution, 512 slots: a 51.2 s revolution and ten process wakeups a
 * second regardless of session count. A delay longer than one revolution is an
 * ordinary case rather than an exotic one - any session watchdog on the order of
 * a minute exceeds it - so the `rounds` path is load-bearing and is tested
 * directly.
 */
const DEFAULT_TICK_MS = 100;
const DEFAULT_SLOT_COUNT = 512;

/** Headroom over 4000 sessions x 4 deadlines, with room for retransmit bursts. */
const DEFAULT_MAXIMUM_ENTRIES = 65_536;

/**
 * Per owner: a keepalive, a watchdog, gap expiry, and one retransmit per
 * unacknowledged reliable message. The reliable window bounds the last of those,
 * so this is generous rather than tight. It is not a protocol constant.
 */
const DEFAULT_MAXIMUM_ENTRIES_PER_OWNER = 64;

const ENTRY_SCHEDULED = 'scheduled';
const ENTRY_DUE = 'due';
const ENTRY_CANCELLED = 'cancelled';
const ENTRY_FIRED = 'fired';

export class TimingWheel {
  #tickMs;
  #slotCount;
  #maximumEntries;
  #maximumEntriesPerOwner;
  #clock;
  #setInterval;
  #clearInterval;
  #onError;

  #slots;
  #cursor = 0;
  // handle -> entry, for O(1) cancel. Holds entries that are scheduled AND
  // entries collected as due but not yet fired, so that a callback can still
  // cancel a sibling that is about to fire in the same batch.
  #entries = new Map();
  // owner -> Set<handle>. An owner may be any value, so this is a Map, not an
  // object: session identity is the caller's to choose.
  #owners = new Map();
  #nextHandle = 1;
  #interval = null;
  #lastTickMs = 0;
  #errorHandlerFailures = 0;

  constructor({
    tickMs = DEFAULT_TICK_MS,
    slotCount = DEFAULT_SLOT_COUNT,
    maximumEntries = DEFAULT_MAXIMUM_ENTRIES,
    maximumEntriesPerOwner = DEFAULT_MAXIMUM_ENTRIES_PER_OWNER,
    clock = () => performance.now(),
    setInterval: injectedSetInterval = setInterval,
    clearInterval: injectedClearInterval = clearInterval,
    onError = null
  } = {}) {
    if (!Number.isSafeInteger(tickMs) || tickMs < 1) {
      fail('WHEEL_TICK_MS', 'tickMs must be a positive whole number of milliseconds');
    }
    if (!Number.isSafeInteger(slotCount) || slotCount < 2) {
      fail('WHEEL_SLOT_COUNT', 'slotCount must be a whole number of at least 2');
    }
    if (!Number.isSafeInteger(maximumEntries) || maximumEntries < 1) {
      fail('WHEEL_MAXIMUM_ENTRIES', 'maximumEntries must be a positive whole number');
    }
    if (!Number.isSafeInteger(maximumEntriesPerOwner) || maximumEntriesPerOwner < 1) {
      fail('WHEEL_MAXIMUM_PER_OWNER', 'maximumEntriesPerOwner must be a positive whole number');
    }
    for (const [name, value] of [
      ['clock', clock], ['setInterval', injectedSetInterval], ['clearInterval', injectedClearInterval]
    ]) {
      if (typeof value !== 'function') fail('WHEEL_DEPENDENCY', `${name} must be a function`);
    }
    /*
     * The error handler is REQUIRED. A default would have to either swallow a
     * callback's exception - the failure mode where a session stops being
     * serviced and nothing anywhere says why - or rethrow it into the interval
     * and take every other session's timers down with it. Neither is a sane
     * default, so the caller states what happens.
     */
    if (typeof onError !== 'function') {
      fail('WHEEL_ERROR_HANDLER', 'onError is required: a timing wheel must never swallow a callback error');
    }

    this.#tickMs = tickMs;
    this.#slotCount = slotCount;
    this.#maximumEntries = maximumEntries;
    this.#maximumEntriesPerOwner = maximumEntriesPerOwner;
    this.#clock = clock;
    this.#setInterval = injectedSetInterval;
    this.#clearInterval = injectedClearInterval;
    this.#onError = onError;
    this.#slots = Array.from({ length: slotCount }, () => new Map());
    this.#lastTickMs = this.#clock();
  }

  /** Entries currently scheduled or awaiting their turn in the firing batch. */
  get size() {
    return this.#entries.size;
  }

  get tickMs() {
    return this.#tickMs;
  }

  get running() {
    return this.#interval !== null;
  }

  /** How many times the injected error handler itself threw. Diagnostics only. */
  get errorHandlerFailures() {
    return this.#errorHandlerFailures;
  }

  /**
   * Start the one interval.
   *
   * Time only flows while the wheel runs. Wiring a subsystem up takes real
   * milliseconds, so anything scheduled before this point is re-based by the
   * elapsed amount: its slot was chosen relative to the cursor, and leaving its
   * absolute deadline on the older base would make the two catch-up paths
   * disagree about whether it is overdue.
   */
  start() {
    if (this.#interval !== null) {
      fail('WHEEL_ALREADY_RUNNING', 'the wheel is already running; a second interval would double every tick');
    }
    const startedAtMs = this.#clock();
    const rebaseMs = startedAtMs - this.#lastTickMs;
    if (Number.isFinite(rebaseMs) && rebaseMs !== 0) {
      for (const entry of this.#entries.values()) entry.deadlineMs += rebaseMs;
    }
    this.#lastTickMs = startedAtMs;
    const token = this.#setInterval(() => this.#onTick(), this.#tickMs);
    if (token == null) {
      fail('WHEEL_SCHEDULER', 'the injected setInterval returned no token; the wheel could not prove it is running');
    }
    /*
     * Optional-called twice over: an injected scheduler may return a plain
     * token. An interval that keeps the process alive would make a server that
     * has finished serving refuse to exit.
     */
    token.unref?.();
    this.#interval = token;
    return this;
  }

  /**
   * Clear the interval and discard every entry. Idempotent; returns how many
   * entries were still scheduled.
   *
   * Keeping entries across a stop would leave timers that can never fire, which
   * is a leak that looks like working code. Discarding them and REPORTING the
   * count lets shutdown assert it was clean instead of hoping.
   */
  stop() {
    if (this.#interval !== null) {
      this.#clearInterval(this.#interval);
      this.#interval = null;
    }
    const discarded = this.#entries.size;
    for (const slot of this.#slots) slot.clear();
    this.#entries.clear();
    this.#owners.clear();
    return discarded;
  }

  /**
   * Schedule `callback` to run once, at least `delayMs` from now.
   *
   * `owner` groups the entry for cancellation and for the per-owner bound; pass
   * the session it belongs to. A null owner is for process-lifetime timers only
   * - it cannot be group-cancelled, and it still counts against the global
   * bound. Returns an opaque handle, never reused.
   *
   * A `delayMs` below one tick fires on the NEXT tick. That is the wheel's
   * stated resolution rather than a clamp of a caller mistake; `tickMs` is
   * public so a caller can see it. A negative or non-finite delay IS a mistake
   * and is refused.
   */
  schedule({ delayMs, callback, owner = null, name = 'unnamed' } = {}) {
    if (typeof callback !== 'function') {
      fail('WHEEL_CALLBACK', 'schedule requires a callback function');
    }
    if (typeof delayMs !== 'number' || !Number.isFinite(delayMs) || delayMs < 0) {
      fail('WHEEL_DELAY', `delayMs must be a finite non-negative number of milliseconds, not ${delayMs}`);
    }
    if (this.#entries.size >= this.#maximumEntries) {
      // Fail closed. Evicting to make room would drop a watchdog or a retransmit
      // that nothing else will ever re-arm.
      fail(
        'WHEEL_CAPACITY',
        `refusing to schedule ${name}: the wheel already holds ${this.#entries.size} entries`
      );
    }
    let ownerHandles = null;
    if (owner !== null) {
      ownerHandles = this.#owners.get(owner);
      if (ownerHandles != null && ownerHandles.size >= this.#maximumEntriesPerOwner) {
        // Per owner, so that one peer exhausts only its own budget.
        fail(
          'WHEEL_OWNER_CAPACITY',
          `refusing to schedule ${name}: this owner already holds ${ownerHandles.size} entries`
        );
      }
    }

    const handle = this.#nextHandle;
    this.#nextHandle += 1;
    const ticksOut = Math.max(1, Math.ceil(delayMs / this.#tickMs));
    const entry = {
      handle,
      name,
      owner,
      callback,
      // Absolute, so the long-stall sweep can re-home from the deadline the
      // caller actually asked for rather than from wheel bookkeeping.
      deadlineMs: this.#lastTickMs + ticksOut * this.#tickMs,
      state: ENTRY_SCHEDULED,
      rounds: 0,
      slotIndex: 0
    };
    this.#entries.set(handle, entry);
    if (owner !== null) {
      if (ownerHandles == null) {
        ownerHandles = new Set();
        this.#owners.set(owner, ownerHandles);
      }
      ownerHandles.add(handle);
    }
    this.#place(entry, ticksOut);
    return handle;
  }

  /**
   * Cancel one entry. Returns whether it was still live.
   *
   * An unknown or already-fired handle returns false rather than throwing: a
   * cancel racing a fire is normal (the ack arrives as the retransmit runs), not
   * a caller error.
   */
  cancel(handle) {
    const entry = this.#entries.get(handle);
    if (entry == null) return false;
    if (entry.state === ENTRY_SCHEDULED) {
      this.#slots[entry.slotIndex].delete(handle);
    }
    // An entry already collected as due is left for the firing loop to skip, so
    // cancelling from inside a callback stops a sibling that has not run yet.
    entry.state = ENTRY_CANCELLED;
    this.#forget(entry);
    return true;
  }

  /** Cancel every entry belonging to `owner`. Returns how many were cancelled. */
  cancelOwner(owner) {
    if (owner === null) return 0;
    const ownerHandles = this.#owners.get(owner);
    if (ownerHandles == null) return 0;
    let cancelled = 0;
    // Snapshot: cancel() mutates this set.
    for (const handle of [...ownerHandles]) {
      if (this.cancel(handle)) cancelled += 1;
    }
    this.#owners.delete(owner);
    return cancelled;
  }

  countForOwner(owner) {
    const ownerHandles = this.#owners.get(owner);
    return ownerHandles == null ? 0 : ownerHandles.size;
  }

  /** The names of an owner's live entries, for diagnostics and leak reports. */
  scheduledNamesForOwner(owner) {
    const ownerHandles = this.#owners.get(owner);
    if (ownerHandles == null) return [];
    return [...ownerHandles].map((handle) => this.#entries.get(handle)?.name ?? 'unknown');
  }

  /**
   * Throw unless `owner` holds nothing. The point is that a session teardown can
   * PROVE it left nothing behind, in the shutdown path, instead of a reviewer
   * having to spot a missing cancel.
   */
  assertOwnerDrained(owner) {
    const remaining = this.countForOwner(owner);
    if (remaining === 0) return;
    fail(
      'WHEEL_OWNER_LEAK',
      `owner still holds ${remaining} timing entries after teardown: ` +
      `${this.scheduledNamesForOwner(owner).join(', ')}`
    );
  }

  #place(entry, ticksOut) {
    const index = (this.#cursor + ticksOut) % this.#slotCount;
    // Ticks until this slot comes round again, so a delay longer than one
    // revolution waits out whole revolutions in place instead of firing early.
    entry.rounds = Math.floor((ticksOut - 1) / this.#slotCount);
    entry.slotIndex = index;
    entry.state = ENTRY_SCHEDULED;
    this.#slots[index].set(entry.handle, entry);
  }

  #forget(entry) {
    this.#entries.delete(entry.handle);
    const ownerHandles = entry.owner === null ? null : this.#owners.get(entry.owner);
    if (ownerHandles != null) {
      ownerHandles.delete(entry.handle);
      if (ownerHandles.size === 0) this.#owners.delete(entry.owner);
    }
  }

  #onTick() {
    try {
      this.#advance();
    } catch (error) {
      // A defect in the wheel itself must not tear down the interval and with it
      // every session's timers.
      this.#report(error, null);
    }
  }

  #advance() {
    const now = this.#clock();
    const elapsedMs = now - this.#lastTickMs;
    // Sub-tick, or a clock that moved backwards: advance nothing and keep the
    // base, so neither case can drift or stampede.
    if (!Number.isFinite(elapsedMs) || elapsedMs < this.#tickMs) return;
    const elapsedTicks = Math.floor(elapsedMs / this.#tickMs);
    // The remainder is deliberately kept. See the drift note in the header.
    this.#lastTickMs += elapsedTicks * this.#tickMs;

    const due = elapsedTicks >= this.#slotCount
      ? this.#sweep(elapsedTicks, now)
      : this.#walk(elapsedTicks);
    this.#fire(due);
  }

  /**
   * Ordinary path: step the cursor over each elapsed tick, collecting whatever
   * came due. Entries are collected across the whole catch-up and fired
   * afterwards, so slot order gives deadline order and a callback that schedules
   * during the burst lands relative to the final cursor rather than a
   * half-advanced one.
   */
  #walk(elapsedTicks) {
    const due = [];
    for (let step = 0; step < elapsedTicks; step += 1) {
      this.#cursor = (this.#cursor + 1) % this.#slotCount;
      const slot = this.#slots[this.#cursor];
      if (slot.size === 0) continue;
      // Deleting during Map iteration is defined; nothing is inserted here
      // because no callback runs until #fire.
      for (const entry of slot.values()) {
        if (entry.rounds > 0) {
          entry.rounds -= 1;
          continue;
        }
        slot.delete(entry.handle);
        entry.state = ENTRY_DUE;
        due.push(entry);
      }
    }
    return due;
  }

  /**
   * Long-stall path, taken once the gap exceeds a full revolution - host
   * suspend, or a debugger. Walking tick by tick would be correct but would cost
   * one slot walk per missed tick for a gap that is by definition long, so the
   * wheel is instead re-homed once from absolute deadlines. Same outcome: every
   * overdue entry fires exactly once, in deadline order, and nothing is dropped.
   */
  #sweep(elapsedTicks, now) {
    this.#cursor = (this.#cursor + elapsedTicks) % this.#slotCount;
    const due = [];
    const survivors = [];
    for (const slot of this.#slots) {
      for (const entry of slot.values()) {
        if (entry.deadlineMs <= now) {
          entry.state = ENTRY_DUE;
          due.push(entry);
        } else {
          survivors.push(entry);
        }
      }
      slot.clear();
    }
    for (const entry of survivors) {
      this.#place(entry, Math.max(1, Math.ceil((entry.deadlineMs - now) / this.#tickMs)));
    }
    // Handle order is schedule order, so it breaks deadline ties exactly as the
    // per-slot insertion order does on the ordinary path.
    due.sort((left, right) => left.deadlineMs - right.deadlineMs || left.handle - right.handle);
    return due;
  }

  #fire(due) {
    for (const entry of due) {
      // Cancelled by an earlier callback in this same batch.
      if (entry.state !== ENTRY_DUE) continue;
      entry.state = ENTRY_FIRED;
      // Forgotten BEFORE the callback runs, so a callback may reschedule under
      // the same owner without tripping the per-owner bound on its own entry,
      // and so cancelling its own handle is a no-op rather than a surprise.
      this.#forget(entry);
      try {
        entry.callback();
      } catch (error) {
        this.#report(error, entry);
      }
    }
  }

  #report(error, entry) {
    try {
      this.#onError({
        error,
        handle: entry?.handle ?? null,
        owner: entry?.owner ?? null,
        name: entry?.name ?? null
      });
    } catch {
      /*
       * The handler threw. Counted and swallowed: a broken error handler must
       * not stop the remaining callbacks in this batch, which belong to other
       * sessions that did nothing wrong. The count is exposed so a test or a rig
       * log can see it happened.
       */
      this.#errorHandlerFailures += 1;
    }
  }
}

export function createTimingWheel(options) {
  return new TimingWheel(options);
}
