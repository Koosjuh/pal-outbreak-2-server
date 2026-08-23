import assert from 'node:assert/strict';
import test from 'node:test';

import { TimingWheel, TimingWheelError } from '../src/transport/timing-wheel.js';

/**
 * The one timing facility for the SN@P subsystem.
 *
 * Nothing here sleeps or touches the wall clock. The clock and the interval are
 * both injected, so a test states "150 ms passed and one tick was delivered" as
 * a fact rather than waiting for it - which is the only way the late-tick,
 * drift and long-stall properties below can be tested at all, since none of
 * them can be provoked reliably by real time.
 */

function harness({ tickMs = 100, ...options } = {}) {
  let nowMs = 1_000;
  let token = null;
  let unrefCount = 0;
  let clearCount = 0;
  const errors = [];

  const wheel = new TimingWheel({
    tickMs,
    clock: () => nowMs,
    setInterval: (fn, ms) => {
      token = { fn, ms, unref: () => { unrefCount += 1; } };
      return token;
    },
    clearInterval: (cleared) => {
      clearCount += 1;
      if (cleared === token) token = null;
    },
    onError: (report) => errors.push(report),
    ...options
  });

  return {
    wheel,
    errors,
    get token() { return token; },
    get unrefCount() { return unrefCount; },
    get clearCount() { return clearCount; },
    nowMs: () => nowMs,
    /** Time passes AND the interval is delivered. */
    advanceMs(ms) {
      nowMs += ms;
      token?.fn();
    },
    advanceTicks(count) {
      for (let index = 0; index < count; index += 1) this.advanceMs(tickMs);
    },
    /** Time passes with NO tick delivered - a stalled event loop. */
    stallMs(ms) {
      nowMs += ms;
    },
    deliverTick() {
      token?.fn();
    }
  };
}

/** Records firing order by name. */
function recorder() {
  const fired = [];
  return {
    fired,
    on: (name) => () => { fired.push(name); }
  };
}

/* ---- ordering --------------------------------------------------------- */

test('entries due in the same tick fire in the order they were scheduled', () => {
  const rig = harness();
  const log = recorder();
  rig.wheel.start();
  // Identical delay, so all three land in one slot and only insertion order can
  // decide. Scheduled deliberately out of alphabetical order.
  rig.wheel.schedule({ delayMs: 300, callback: log.on('c'), name: 'c' });
  rig.wheel.schedule({ delayMs: 300, callback: log.on('a'), name: 'a' });
  rig.wheel.schedule({ delayMs: 300, callback: log.on('b'), name: 'b' });

  rig.advanceTicks(2);
  assert.deepEqual(log.fired, [], 'nothing is due before its deadline');
  rig.advanceTicks(1);
  assert.deepEqual(log.fired, ['c', 'a', 'b']);
});

test('entries in different slots fire in deadline order, earliest first', () => {
  const rig = harness();
  const log = recorder();
  rig.wheel.start();
  rig.wheel.schedule({ delayMs: 500, callback: log.on('late'), name: 'late' });
  rig.wheel.schedule({ delayMs: 100, callback: log.on('early'), name: 'early' });
  rig.wheel.schedule({ delayMs: 300, callback: log.on('middle'), name: 'middle' });

  rig.advanceTicks(5);
  assert.deepEqual(log.fired, ['early', 'middle', 'late']);
});

test('a delay below one tick fires on the next tick, not in the current one', () => {
  const rig = harness();
  const log = recorder();
  rig.wheel.start();
  rig.wheel.schedule({ delayMs: 0, callback: log.on('zero'), name: 'zero' });
  rig.wheel.schedule({ delayMs: 1, callback: log.on('sub-tick'), name: 'sub-tick' });

  assert.deepEqual(log.fired, [], 'scheduling alone never fires');
  rig.advanceTicks(1);
  assert.deepEqual(log.fired, ['zero', 'sub-tick']);
});

/* ---- cancellation ----------------------------------------------------- */

test('a cancelled entry never fires and is gone from the wheel immediately', () => {
  const rig = harness();
  const log = recorder();
  rig.wheel.start();
  const handle = rig.wheel.schedule({ delayMs: 200, callback: log.on('doomed'), name: 'doomed' });
  rig.wheel.schedule({ delayMs: 200, callback: log.on('kept'), name: 'kept' });

  assert.equal(rig.wheel.size, 2);
  assert.equal(rig.wheel.cancel(handle), true);
  assert.equal(rig.wheel.size, 1, 'cancelling releases the entry at once, not at its deadline');

  rig.advanceTicks(3);
  assert.deepEqual(log.fired, ['kept'], 'and its neighbour is untouched');
});

test('cancelling an unknown or already-fired handle reports false rather than throwing', () => {
  const rig = harness();
  const log = recorder();
  rig.wheel.start();
  const handle = rig.wheel.schedule({ delayMs: 100, callback: log.on('once'), name: 'once' });
  rig.advanceTicks(1);
  assert.deepEqual(log.fired, ['once']);

  // A cancel racing a fire is ordinary - the ack lands as the retransmit runs -
  // so it is a false, not an exception.
  assert.equal(rig.wheel.cancel(handle), false);
  assert.equal(rig.wheel.cancel(999_999), false);
});

test('cancelling one session cancels exactly its own timers and no other session\'s', () => {
  const rig = harness();
  const log = recorder();
  rig.wheel.start();
  const alice = { session: 'alice' };
  const bob = { session: 'bob' };
  rig.wheel.schedule({ delayMs: 100, owner: alice, callback: log.on('alice-keepalive'), name: 'keepalive' });
  rig.wheel.schedule({ delayMs: 200, owner: alice, callback: log.on('alice-watchdog'), name: 'watchdog' });
  rig.wheel.schedule({ delayMs: 100, owner: bob, callback: log.on('bob-keepalive'), name: 'keepalive' });

  assert.equal(rig.wheel.countForOwner(alice), 2);
  assert.equal(rig.wheel.cancelOwner(alice), 2);
  assert.equal(rig.wheel.countForOwner(alice), 0);
  assert.equal(rig.wheel.countForOwner(bob), 1);

  rig.advanceTicks(3);
  assert.deepEqual(log.fired, ['bob-keepalive']);
});

test('a drained owner asserts clean and a leaking one names what it left behind', () => {
  const rig = harness();
  const session = { session: 'alice' };
  rig.wheel.start();
  rig.wheel.schedule({ delayMs: 100, owner: session, callback: () => {}, name: 'keepalive' });
  rig.wheel.schedule({ delayMs: 5_000, owner: session, callback: () => {}, name: 'watchdog' });

  // The leak check is mechanical: teardown can assert it, no reviewer required.
  assert.throws(
    () => rig.wheel.assertOwnerDrained(session),
    (error) => error instanceof TimingWheelError &&
      error.code === 'WHEEL_OWNER_LEAK' &&
      /keepalive/.test(error.message) && /watchdog/.test(error.message)
  );

  rig.wheel.cancelOwner(session);
  assert.doesNotThrow(() => rig.wheel.assertOwnerDrained(session));
});

test('an owner is drained by its entries firing, not only by cancellation', () => {
  const rig = harness();
  const session = { session: 'alice' };
  rig.wheel.start();
  rig.wheel.schedule({ delayMs: 100, owner: session, callback: () => {}, name: 'keepalive' });
  rig.advanceTicks(1);
  assert.equal(rig.wheel.countForOwner(session), 0);
  assert.doesNotThrow(() => rig.wheel.assertOwnerDrained(session));
});

/* ---- re-entrancy ------------------------------------------------------ */

test('a callback that reschedules itself keeps firing on its own period', () => {
  const rig = harness();
  const fired = [];
  const session = { session: 'alice' };
  rig.wheel.start();
  const keepalive = () => {
    fired.push(rig.nowMs());
    rig.wheel.schedule({ delayMs: 500, owner: session, callback: keepalive, name: 'keepalive' });
  };
  rig.wheel.schedule({ delayMs: 500, owner: session, callback: keepalive, name: 'keepalive' });

  rig.advanceTicks(15);
  assert.deepEqual(fired, [1_500, 2_000, 2_500], 'every 500 ms, with no drift and no doubling');
  assert.equal(rig.wheel.countForOwner(session), 1, 'exactly one keepalive is armed at a time');
});

test('scheduling from inside a callback does not skip or re-fire the entries beside it', () => {
  const rig = harness();
  const log = recorder();
  rig.wheel.start();
  // All three are due in the same tick; the first one schedules into the very
  // slot the wheel is standing on.
  rig.wheel.schedule({
    delayMs: 100,
    name: 'first',
    callback: () => {
      log.fired.push('first');
      rig.wheel.schedule({ delayMs: 100, callback: log.on('added-by-first'), name: 'added' });
    }
  });
  rig.wheel.schedule({ delayMs: 100, callback: log.on('second'), name: 'second' });
  rig.wheel.schedule({ delayMs: 100, callback: log.on('third'), name: 'third' });

  rig.advanceTicks(1);
  assert.deepEqual(
    log.fired, ['first', 'second', 'third'],
    'the new entry does not gatecrash the batch it was created in'
  );
  rig.advanceTicks(1);
  assert.deepEqual(log.fired, ['first', 'second', 'third', 'added-by-first']);
});

test('a callback can cancel a sibling that is due in the same batch and it will not fire', () => {
  const rig = harness();
  const log = recorder();
  rig.wheel.start();
  let siblingHandle = null;
  rig.wheel.schedule({
    delayMs: 100,
    name: 'canceller',
    callback: () => {
      log.fired.push('canceller');
      // The sibling has already been collected as due. Honouring the cancel is
      // the whole point: an ack handler must be able to kill the retransmit.
      assert.equal(rig.wheel.cancel(siblingHandle), true);
    }
  });
  siblingHandle = rig.wheel.schedule({ delayMs: 100, callback: log.on('sibling'), name: 'sibling' });
  rig.wheel.schedule({ delayMs: 100, callback: log.on('bystander'), name: 'bystander' });

  rig.advanceTicks(2);
  assert.deepEqual(log.fired, ['canceller', 'bystander']);
});

test('a callback that cancels its own owner group leaves the wheel consistent', () => {
  const rig = harness();
  const log = recorder();
  const session = { session: 'alice' };
  rig.wheel.start();
  rig.wheel.schedule({
    delayMs: 100,
    owner: session,
    name: 'watchdog',
    callback: () => {
      log.fired.push('watchdog');
      // Session teardown from inside a timer: the real shutdown path.
      rig.wheel.cancelOwner(session);
    }
  });
  rig.wheel.schedule({ delayMs: 100, owner: session, callback: log.on('keepalive'), name: 'keepalive' });
  rig.wheel.schedule({ delayMs: 300, owner: session, callback: log.on('gap-expiry'), name: 'gap' });

  rig.advanceTicks(5);
  assert.deepEqual(log.fired, ['watchdog'], 'the whole group went with it');
  assert.equal(rig.wheel.size, 0);
  assert.doesNotThrow(() => rig.wheel.assertOwnerDrained(session));
});

/* ---- a throwing callback ---------------------------------------------- */

test('a callback that throws is reported and the rest of its slot still fires', () => {
  const rig = harness();
  const log = recorder();
  rig.wheel.start();
  const session = { session: 'alice' };
  const boom = new Error('handler exploded');
  rig.wheel.schedule({ delayMs: 100, callback: log.on('before'), name: 'before' });
  rig.wheel.schedule({
    delayMs: 100, owner: session, name: 'thrower', callback: () => { throw boom; }
  });
  rig.wheel.schedule({ delayMs: 100, callback: log.on('after'), name: 'after' });

  rig.advanceTicks(1);
  assert.deepEqual(log.fired, ['before', 'after'], 'one bad session does not silence the others');
  assert.equal(rig.errors.length, 1);
  assert.equal(rig.errors[0].error, boom);
  assert.equal(rig.errors[0].owner, session, 'the report says whose timer it was');
  assert.equal(rig.errors[0].name, 'thrower');
});

test('a callback that throws does not stop the tick itself', () => {
  const rig = harness();
  const log = recorder();
  rig.wheel.start();
  rig.wheel.schedule({ delayMs: 100, name: 'thrower', callback: () => { throw new Error('boom'); } });
  rig.wheel.schedule({ delayMs: 300, callback: log.on('later'), name: 'later' });

  rig.advanceTicks(3);
  assert.deepEqual(log.fired, ['later'], 'the wheel is still ticking after the throw');
  assert.equal(rig.errors.length, 1);
});

test('an error handler that itself throws is counted, not allowed to stop the batch', () => {
  const log = recorder();
  const rig = harness({ onError: () => { throw new Error('the handler is broken too'); } });
  rig.wheel.start();
  rig.wheel.schedule({ delayMs: 100, name: 'thrower', callback: () => { throw new Error('boom'); } });
  rig.wheel.schedule({ delayMs: 100, callback: log.on('bystander'), name: 'bystander' });

  rig.advanceTicks(1);
  assert.deepEqual(log.fired, ['bystander']);
  assert.equal(rig.wheel.errorHandlerFailures, 1, 'and it is visible rather than silent');
});

/* ---- the bound -------------------------------------------------------- */

test('the wheel refuses to grow past its global bound instead of evicting a live timer', () => {
  const rig = harness({ maximumEntries: 3 });
  rig.wheel.start();
  for (let index = 0; index < 3; index += 1) {
    rig.wheel.schedule({ delayMs: 1_000, callback: () => {}, name: `entry-${index}` });
  }
  assert.throws(
    () => rig.wheel.schedule({ delayMs: 1_000, callback: () => {}, name: 'one-too-many' }),
    (error) => error instanceof TimingWheelError && error.code === 'WHEEL_CAPACITY'
  );
  assert.equal(rig.wheel.size, 3, 'nothing already armed was sacrificed to make room');
});

test('one owner cannot consume the whole budget and starve every other session', () => {
  const rig = harness({ maximumEntries: 100, maximumEntriesPerOwner: 2 });
  rig.wheel.start();
  const hostile = { session: 'hostile' };
  const innocent = { session: 'innocent' };
  rig.wheel.schedule({ delayMs: 1_000, owner: hostile, callback: () => {}, name: 'a' });
  rig.wheel.schedule({ delayMs: 1_000, owner: hostile, callback: () => {}, name: 'b' });

  assert.throws(
    () => rig.wheel.schedule({ delayMs: 1_000, owner: hostile, callback: () => {}, name: 'c' }),
    (error) => error.code === 'WHEEL_OWNER_CAPACITY'
  );
  // The point of the per-owner bound: the well-behaved session is unaffected.
  assert.doesNotThrow(
    () => rig.wheel.schedule({ delayMs: 1_000, owner: innocent, callback: () => {}, name: 'a' })
  );
});

test('an owner that fires or cancels its entries can schedule again, so the bound is not a ratchet', () => {
  const rig = harness({ maximumEntriesPerOwner: 1 });
  const session = { session: 'alice' };
  rig.wheel.start();
  rig.wheel.schedule({ delayMs: 100, owner: session, callback: () => {}, name: 'keepalive' });
  assert.throws(
    () => rig.wheel.schedule({ delayMs: 100, owner: session, callback: () => {}, name: 'second' }),
    (error) => error.code === 'WHEEL_OWNER_CAPACITY'
  );
  rig.advanceTicks(1);
  assert.doesNotThrow(
    () => rig.wheel.schedule({ delayMs: 100, owner: session, callback: () => {}, name: 'rearmed' })
  );
});

/* ---- wraparound ------------------------------------------------------- */

test('an entry scheduled more than one full revolution out waits the extra revolutions', () => {
  // Eight slots at 100 ms: one revolution is 800 ms, so 1500 ms is a revolution
  // plus seven ticks and lands in a slot the cursor passes twice.
  const rig = harness({ tickMs: 100, slotCount: 8 });
  const log = recorder();
  rig.wheel.start();
  rig.wheel.schedule({ delayMs: 1_500, callback: log.on('watchdog'), name: 'watchdog' });

  rig.advanceTicks(7);
  assert.deepEqual(log.fired, [], 'not fired when the cursor first crosses its slot');
  rig.advanceTicks(7);
  assert.deepEqual(log.fired, [], 'still armed at 1400 ms');
  rig.advanceTicks(1);
  assert.deepEqual(log.fired, ['watchdog'], 'fires at 1500 ms exactly, not a revolution early');
});

test('an entry at exactly one revolution fires on that revolution, not immediately', () => {
  const rig = harness({ tickMs: 100, slotCount: 8 });
  const log = recorder();
  rig.wheel.start();
  // 800 ms hashes to the slot the cursor is standing on - the off-by-one that
  // makes a naive wheel fire it on the very next tick.
  rig.wheel.schedule({ delayMs: 800, callback: log.on('exact'), name: 'exact' });

  rig.advanceTicks(7);
  assert.deepEqual(log.fired, []);
  rig.advanceTicks(1);
  assert.deepEqual(log.fired, ['exact']);
});

test('entries a revolution apart still fire in deadline order', () => {
  const rig = harness({ tickMs: 100, slotCount: 8 });
  const log = recorder();
  rig.wheel.start();
  rig.wheel.schedule({ delayMs: 1_700, callback: log.on('third'), name: 'third' });
  rig.wheel.schedule({ delayMs: 100, callback: log.on('first'), name: 'first' });
  rig.wheel.schedule({ delayMs: 900, callback: log.on('second'), name: 'second' });

  rig.advanceTicks(20);
  assert.deepEqual(log.fired, ['first', 'second', 'third']);
});

/* ---- late ticks, coalescing and drift --------------------------------- */

test('a stalled event loop fires each overdue entry exactly once, in deadline order', () => {
  const rig = harness({ tickMs: 100, slotCount: 32 });
  const log = recorder();
  rig.wheel.start();
  rig.wheel.schedule({ delayMs: 100, callback: log.on('a'), name: 'a' });
  rig.wheel.schedule({ delayMs: 200, callback: log.on('b'), name: 'b' });
  rig.wheel.schedule({ delayMs: 300, callback: log.on('c'), name: 'c' });

  // 500 ms of time passes and exactly ONE tick is delivered - the GC-pause case.
  rig.stallMs(500);
  rig.deliverTick();
  assert.deepEqual(log.fired, ['a', 'b', 'c'], 'each owed firing happens once - no stampede of repeats');

  rig.advanceTicks(10);
  assert.deepEqual(log.fired, ['a', 'b', 'c'], 'and the catch-up did not re-arm anything');
  assert.equal(rig.wheel.size, 0);
});

test('a stall longer than one revolution fires what is overdue and re-homes what is not', () => {
  // Eight slots at 100 ms: a 1000 ms stall exceeds the 800 ms revolution and
  // takes the sweep path rather than the per-tick walk.
  const rig = harness({ tickMs: 100, slotCount: 8 });
  const log = recorder();
  rig.wheel.start();
  rig.wheel.schedule({ delayMs: 300, callback: log.on('overdue'), name: 'overdue' });
  rig.wheel.schedule({ delayMs: 5_000, callback: log.on('watchdog'), name: 'watchdog' });

  rig.stallMs(1_000);
  rig.deliverTick();
  assert.deepEqual(log.fired, ['overdue'], 'the long watchdog was not dragged forward with it');
  assert.equal(rig.wheel.size, 1);

  // Re-homed from its ABSOLUTE deadline, so it still fires at 5000 ms.
  rig.advanceTicks(39);
  assert.equal(rig.nowMs(), 5_900);
  assert.deepEqual(log.fired, ['overdue'], 'still armed at 4900 ms of its own timeline');
  rig.advanceTicks(1);
  assert.deepEqual(log.fired, ['overdue', 'watchdog']);
});

test('a stall of many revolutions does not multiply the work or the firings', () => {
  const rig = harness({ tickMs: 100, slotCount: 8 });
  let fireCount = 0;
  rig.wheel.start();
  for (let index = 0; index < 20; index += 1) {
    rig.wheel.schedule({ delayMs: 100 * (index + 1), callback: () => { fireCount += 1; }, name: `e${index}` });
  }
  // An hour of host suspend: the burst must be bounded by the entries owed, not
  // by the length of the stall.
  rig.stallMs(3_600_000);
  rig.deliverTick();
  assert.equal(fireCount, 20);
  assert.equal(rig.wheel.size, 0);
});

test('jittery tick delivery does not drift an entry past its deadline', () => {
  const rig = harness({ tickMs: 100 });
  const log = recorder();
  rig.wheel.start();
  rig.wheel.schedule({ delayMs: 200, callback: log.on('keepalive'), name: 'keepalive' });

  // The interval is late by 49 ms, then early relative to that lateness. Snapping
  // the tick base to "now" would swallow the remainder and push the 200 ms
  // deadline into the next tick; carrying it means real time decides.
  rig.advanceMs(149);
  assert.deepEqual(log.fired, [], 'one tick has elapsed, not two');
  rig.advanceMs(51);
  assert.equal(rig.nowMs(), 1_200);
  assert.deepEqual(log.fired, ['keepalive'], 'fires at 200 ms of real time despite the jitter');
});

test('drift does not accumulate over many jittery ticks', () => {
  const rig = harness({ tickMs: 100 });
  const log = recorder();
  rig.wheel.start();
  rig.wheel.schedule({ delayMs: 1_000, callback: log.on('watchdog'), name: 'watchdog' });

  // Ten deliveries at 99 ms - always just short of a tick - then the real
  // elapsed time reaches 1000 ms and the entry is due, regardless of how the
  // deliveries were spaced.
  for (let index = 0; index < 10; index += 1) rig.advanceMs(99);
  assert.equal(rig.nowMs(), 1_990);
  assert.deepEqual(log.fired, [], 'only 990 ms of real time has passed');
  rig.advanceMs(10);
  assert.deepEqual(log.fired, ['watchdog'], 'due at 1000 ms of real time, not 1000 deliveries');
});

test('a clock that steps backwards neither fires anything nor loses the tick base', () => {
  let nowMs = 10_000;
  let tick = null;
  const log = recorder();
  const wheel = new TimingWheel({
    tickMs: 100,
    clock: () => nowMs,
    setInterval: (fn) => { tick = fn; return { fn, unref() {} }; },
    clearInterval: () => {},
    onError: () => {}
  });
  wheel.start();
  wheel.schedule({ delayMs: 200, callback: log.on('keepalive'), name: 'keepalive' });

  // An NTP correction of a full second. Nothing may fire, and nothing may be
  // stampeded when time moves forward again.
  nowMs -= 1_000;
  tick();
  assert.deepEqual(log.fired, []);

  nowMs += 1_200;
  tick();
  assert.deepEqual(log.fired, ['keepalive'], 'exactly one firing once real time caught up');
  assert.equal(wheel.size, 0);
});

/* ---- lifecycle -------------------------------------------------------- */

test('the interval is unrefd so a finished server can still exit', () => {
  const rig = harness();
  rig.wheel.start();
  assert.equal(rig.unrefCount, 1);
  assert.equal(rig.token.ms, 100, 'one interval for the process, at the tick period');
});

test('stop clears the interval, leaves nothing scheduled, and is idempotent', () => {
  const rig = harness();
  const log = recorder();
  rig.wheel.start();
  rig.wheel.schedule({ delayMs: 100, callback: log.on('a'), name: 'a' });
  rig.wheel.schedule({ delayMs: 5_000, callback: log.on('b'), name: 'b' });

  assert.equal(rig.wheel.stop(), 2, 'shutdown is told what was still armed rather than losing it silently');
  assert.equal(rig.wheel.size, 0);
  assert.equal(rig.token, null, 'the interval is cleared, so the process is not held open');
  assert.equal(rig.wheel.running, false);

  // Idempotent: a second stop clears nothing and reports nothing outstanding.
  assert.equal(rig.wheel.stop(), 0);
  assert.equal(rig.clearCount, 1, 'and it does not clear a stale token');
  assert.deepEqual(log.fired, []);
});

test('a stopped wheel holds no owner state, so every session asserts drained', () => {
  const rig = harness();
  const session = { session: 'alice' };
  rig.wheel.start();
  rig.wheel.schedule({ delayMs: 100, owner: session, callback: () => {}, name: 'keepalive' });
  rig.wheel.stop();
  assert.equal(rig.wheel.countForOwner(session), 0);
  assert.doesNotThrow(() => rig.wheel.assertOwnerDrained(session));
});

test('a wheel can be restarted after a stop and times from the restart', () => {
  const rig = harness();
  const log = recorder();
  rig.wheel.start();
  rig.wheel.stop();
  rig.wheel.start();
  rig.wheel.schedule({ delayMs: 200, callback: log.on('a'), name: 'a' });
  rig.advanceTicks(2);
  assert.deepEqual(log.fired, ['a']);
});

test('starting twice is refused rather than silently double-ticking', () => {
  const rig = harness();
  rig.wheel.start();
  assert.throws(
    () => rig.wheel.start(),
    (error) => error instanceof TimingWheelError && error.code === 'WHEEL_ALREADY_RUNNING'
  );
});

test('entries scheduled before start are timed from the start, not from construction', () => {
  const rig = harness();
  const log = recorder();
  // Wiring a subsystem up takes real time; that time must not be charged to a
  // timer that has not begun.
  rig.wheel.schedule({ delayMs: 200, callback: log.on('a'), name: 'a' });
  rig.stallMs(60_000);
  rig.wheel.start();

  rig.advanceTicks(1);
  assert.deepEqual(log.fired, [], 'not treated as an hour overdue');
  rig.advanceTicks(1);
  assert.deepEqual(log.fired, ['a']);
});

test('a wheel that was never started fires nothing', () => {
  const rig = harness();
  const log = recorder();
  rig.wheel.schedule({ delayMs: 100, callback: log.on('a'), name: 'a' });
  rig.stallMs(10_000);
  assert.equal(rig.token, null, 'no interval exists to deliver');
  assert.deepEqual(log.fired, []);
  assert.equal(rig.wheel.size, 1, 'the entry is armed, waiting for time to start flowing');
});

/* ---- fail closed on caller mistakes ----------------------------------- */

test('a wheel without an error handler is refused at construction', () => {
  // The alternative defaults are swallowing a callback error or killing the
  // interval; the caller has to say which.
  assert.throws(
    () => new TimingWheel({}),
    (error) => error instanceof TimingWheelError && error.code === 'WHEEL_ERROR_HANDLER'
  );
});

test('an invalid delay is refused, never clamped into a different deadline', () => {
  const rig = harness();
  rig.wheel.start();
  for (const delayMs of [-1, -0.5, NaN, Infinity, '100', null, undefined]) {
    assert.throws(
      () => rig.wheel.schedule({ delayMs, callback: () => {} }),
      (error) => error.code === 'WHEEL_DELAY',
      `expected ${String(delayMs)} to be refused`
    );
  }
});

test('a missing callback is refused at schedule time, not discovered at fire time', () => {
  const rig = harness();
  rig.wheel.start();
  for (const callback of [undefined, null, 'fire', 42]) {
    assert.throws(
      () => rig.wheel.schedule({ delayMs: 100, callback }),
      (error) => error.code === 'WHEEL_CALLBACK'
    );
  }
});

test('a nonsensical wheel geometry is refused at construction', () => {
  const onError = () => {};
  assert.throws(() => new TimingWheel({ tickMs: 0, onError }), (error) => error.code === 'WHEEL_TICK_MS');
  assert.throws(() => new TimingWheel({ tickMs: 1.5, onError }), (error) => error.code === 'WHEEL_TICK_MS');
  assert.throws(() => new TimingWheel({ slotCount: 1, onError }), (error) => error.code === 'WHEEL_SLOT_COUNT');
  assert.throws(
    () => new TimingWheel({ maximumEntries: 0, onError }), (error) => error.code === 'WHEEL_MAXIMUM_ENTRIES'
  );
  assert.throws(
    () => new TimingWheel({ maximumEntriesPerOwner: 0, onError }),
    (error) => error.code === 'WHEEL_MAXIMUM_PER_OWNER'
  );
  assert.throws(
    () => new TimingWheel({ clock: 'now', onError }), (error) => error.code === 'WHEEL_DEPENDENCY'
  );
});

test('a scheduler that returns no token is refused rather than leaving a dead wheel', () => {
  const wheel = new TimingWheel({ setInterval: () => null, clearInterval: () => {}, onError: () => {} });
  assert.throws(
    () => wheel.start(),
    (error) => error instanceof TimingWheelError && error.code === 'WHEEL_SCHEDULER'
  );
  assert.equal(wheel.running, false);
});

/* ---- the shape the subsystem will actually use ------------------------ */

test('a session\'s four deadlines coexist and teardown provably leaves nothing behind', () => {
  const rig = harness({ tickMs: 100, slotCount: 512 });
  const log = recorder();
  const session = { session: 'alice' };
  rig.wheel.start();

  // The four deadlines named in the design, with caller-supplied durations - the
  // wheel holds no protocol constants of its own.
  rig.wheel.schedule({ delayMs: 5_000, owner: session, callback: log.on('keepalive'), name: 'keepalive' });
  rig.wheel.schedule({ delayMs: 55_200, owner: session, callback: log.on('watchdog'), name: 'watchdog' });
  rig.wheel.schedule({ delayMs: 1_000, owner: session, callback: log.on('retransmit'), name: 'retransmit' });
  rig.wheel.schedule({ delayMs: 2_000, owner: session, callback: log.on('gap-expiry'), name: 'gap-expiry' });
  assert.equal(rig.wheel.countForOwner(session), 4);

  // The watchdog is 552 ticks out - beyond the 512-slot revolution - so the
  // wraparound path is on the ordinary production route, not an edge case.
  rig.advanceTicks(60);
  assert.deepEqual(log.fired, ['retransmit', 'gap-expiry', 'keepalive']);

  rig.wheel.cancelOwner(session);
  assert.doesNotThrow(() => rig.wheel.assertOwnerDrained(session));
  assert.equal(rig.wheel.size, 0, 'closing the session left nothing in the wheel');
});

test('thousands of sessions cost one interval, and each session cleans up independently', () => {
  const rig = harness();
  const fired = new Set();
  rig.wheel.start();
  const sessions = Array.from({ length: 1_000 }, (unused, index) => `session-${index}`);
  for (const session of sessions) {
    rig.wheel.schedule({
      delayMs: 5_000, owner: session, name: 'keepalive', callback: () => { fired.add(session); }
    });
    rig.wheel.schedule({ delayMs: 55_200, owner: session, callback: () => {}, name: 'watchdog' });
  }
  assert.equal(rig.wheel.size, 2_000);
  assert.equal(rig.unrefCount, 1, 'still exactly one process timer for 2000 deadlines');

  rig.advanceTicks(50);
  assert.equal(fired.size, 1_000, 'every keepalive fired once');

  for (const session of sessions) rig.wheel.cancelOwner(session);
  assert.equal(rig.wheel.size, 0);
});
