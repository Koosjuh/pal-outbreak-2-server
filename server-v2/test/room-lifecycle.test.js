import assert from 'node:assert/strict';
import test from 'node:test';

import {
  PROTECTION,
  ROOM_STATUS,
  RoomLifecycleError,
  RoomLifecycleRegistry
} from '../src/state/room-lifecycle.js';

/**
 * The bioserver Slot status machine (Slot.java statuses, PacketHandler
 * transitions), attached to PAL room handles. Contract rows exercised here:
 * - create -> INCREATE (sendCreateSlot line 1196);
 * - create-complete -> GAMESET only from INCREATE, arming the wait timer
 *   (send6504 lines 1330-1333) - "joinable only at the final step";
 * - start/full -> BUSY (broadcastGetReady line 392 / sendJoinGame 1683-1686),
 *   idempotent from BUSY;
 * - recompute on leave (sendCancelSlot 1365-1392): 0 players -> record
 *   released (PAL rooms close when emptied); host remains + non-full ->
 *   GAMESET; host left -> full reset;
 * - password/protection (Slot.setPassword lines 122-125);
 * - wait timer with injectable timing (Slot.setLivetime/getLivetime 187-197).
 */

function refusalCode(fn) {
  try {
    fn();
  } catch (error) {
    assert.ok(error instanceof RoomLifecycleError, `expected a RoomLifecycleError, got ${error}`);
    return error.code;
  }
  return assert.fail('expected a refusal');
}

const HANDLE = 0x2001;

function inCreate() {
  const lifecycle = new RoomLifecycleRegistry();
  lifecycle.beginCreate(HANDLE, { areaNumber: 1 });
  return lifecycle;
}

function gameSet() {
  const lifecycle = inCreate();
  lifecycle.completeCreate(HANDLE, { nowMs: 0 });
  return lifecycle;
}

test('a handle this registry was never told about reads FREE, like an empty slot', () => {
  const lifecycle = new RoomLifecycleRegistry();
  assert.equal(lifecycle.statusOf(HANDLE), ROOM_STATUS.FREE);
  assert.equal(lifecycle.get(HANDLE), null);
});

test('create -> INCREATE, and the room is NOT joinable yet', () => {
  const lifecycle = inCreate();
  assert.equal(lifecycle.statusOf(HANDLE), ROOM_STATUS.INCREATE);
});

test('create-complete -> GAMESET: the create dialogue\'s final step is the joinable flip', () => {
  const lifecycle = inCreate();
  const record = lifecycle.completeCreate(HANDLE, { nowMs: 0 });
  assert.equal(record.status, ROOM_STATUS.GAMESET);
  // send6504 also arms the wait timer with the rule set's wait limit
  // (default value 2 -> ten minutes -> 600 s).
  assert.deepEqual(
    lifecycle.checkWaitTimer(HANDLE, { nowMs: 0 }),
    { remainingSeconds: 600, expired: false }
  );
});

// The transition table: every edge not in the reference refuses.
const BAD_EDGES = [
  ['completeCreate on an unknown handle', (l) => l.completeCreate(0x9999, { nowMs: 0 }),
    () => new RoomLifecycleRegistry(), 'LIFECYCLE_UNKNOWN'],
  ['completeCreate twice (GAMESET is not INCREATE)', (l) => l.completeCreate(HANDLE, { nowMs: 0 }),
    gameSet, 'LIFECYCLE_TRANSITION'],
  ['markBusy from INCREATE', (l) => l.markBusy(HANDLE), inCreate, 'LIFECYCLE_TRANSITION'],
  ['beginCreate twice', (l) => l.beginCreate(HANDLE), inCreate, 'LIFECYCLE_DUPLICATE'],
  ['markBusy on an unknown handle', (l) => l.markBusy(HANDLE),
    () => new RoomLifecycleRegistry(), 'LIFECYCLE_UNKNOWN']
];

for (const [label, act, arrange, code] of BAD_EDGES) {
  test(`refused edge: ${label}`, () => {
    assert.equal(refusalCode(() => act(arrange())), code);
  });
}

test('start/full -> BUSY from GAMESET; BUSY -> BUSY is idempotent', () => {
  const lifecycle = gameSet();
  assert.equal(lifecycle.markBusy(HANDLE).status, ROOM_STATUS.BUSY);
  // broadcastGetReady re-fires on every SLOTTIMER zero read; BUSY absorbs it.
  assert.equal(lifecycle.markBusy(HANDLE).status, ROOM_STATUS.BUSY);
});

test('recompute on leave: zero members releases the record (PAL rooms close when emptied)', () => {
  const lifecycle = gameSet();
  const result = lifecycle.recomputeOnLeave(HANDLE, {
    memberCount: 0, maxPlayers: 4, hostLeft: true
  });
  assert.equal(result, null);
  assert.equal(lifecycle.get(HANDLE), null);
  assert.equal(lifecycle.statusOf(HANDLE), ROOM_STATUS.FREE);
});

test('recompute on leave: host remains + non-full -> GAMESET (a full BUSY room reopens)', () => {
  const lifecycle = gameSet();
  lifecycle.markBusy(HANDLE);   // room filled
  const record = lifecycle.recomputeOnLeave(HANDLE, {
    memberCount: 3, maxPlayers: 4, hostLeft: false
  });
  assert.equal(record.status, ROOM_STATUS.GAMESET);
});

test('recompute on leave: the host leaving resets the slot outright (sendCancelSlot 1365-1372)', () => {
  const lifecycle = gameSet();
  lifecycle.setPassword(HANDLE, Buffer.from('SECRET'));
  lifecycle.setScene(HANDLE, { slotType: 0x12, scenario: 2 });
  lifecycle.get(HANDLE).rules.setRuleValue(0, 0);
  const record = lifecycle.recomputeOnLeave(HANDLE, {
    memberCount: 2, maxPlayers: 4, hostLeft: true
  });
  // Slot.reset(): FREE, protection off, scenario/slotType cleared, rules reset.
  assert.equal(record.status, ROOM_STATUS.FREE);
  assert.equal(record.protection, PROTECTION.OFF);
  assert.equal(record.scenario, 0);
  assert.equal(record.slotType, 0);
  assert.equal(record.rules.ruleValue(0), 2);
  // NOT GAMESET: members remained but the leaver WAS the host (the ishost==0
  // condition on the reopen, sendCancelSlot line 1387).
  assert.notEqual(record.status, ROOM_STATUS.GAMESET);
});

test('password: non-empty flips protection ON; the check is match-or-unprotected', () => {
  const lifecycle = gameSet();
  // Unprotected room accepts anything, including the empty password.
  assert.equal(lifecycle.passwordAccepts(HANDLE, Buffer.alloc(0)), true);
  assert.equal(lifecycle.passwordAccepts(HANDLE, Buffer.from('X')), true);
  lifecycle.setPassword(HANDLE, Buffer.from('SECRET'));
  assert.equal(lifecycle.get(HANDLE).protection, PROTECTION.ON);
  assert.equal(lifecycle.passwordAccepts(HANDLE, Buffer.from('SECRET')), true);
  assert.equal(lifecycle.passwordAccepts(HANDLE, Buffer.from('WRONG')), false);
  assert.equal(lifecycle.passwordAccepts(HANDLE, Buffer.alloc(0)), false);
  // An empty password does NOT flip protection (Slot.setPassword's guard).
  const other = gameSet();
  other.setPassword(HANDLE, Buffer.alloc(0));
  assert.equal(other.get(HANDLE).protection, PROTECTION.OFF);
});

test('the wait timer is injectable time, clamps at zero, and expiry is the auto-start signal', () => {
  const lifecycle = inCreate();
  // Never armed: no remaining, never expired.
  assert.deepEqual(
    lifecycle.checkWaitTimer(HANDLE, { nowMs: 0 }),
    { remainingSeconds: null, expired: false }
  );
  lifecycle.completeCreate(HANDLE, { nowMs: 1_000_000 });
  assert.deepEqual(
    lifecycle.checkWaitTimer(HANDLE, { nowMs: 1_000_000 + 599_000 }),
    { remainingSeconds: 1, expired: false }
  );
  // Past the limit: clamped to 0, expired while GAMESET (auto-start fires).
  assert.deepEqual(
    lifecycle.checkWaitTimer(HANDLE, { nowMs: 1_000_000 + 600_000 }),
    { remainingSeconds: 0, expired: true }
  );
  // Re-arm moves the deadline (SCENESELECT re-arms too).
  lifecycle.armWaitTimer(HANDLE, { nowMs: 2_000_000 });
  assert.equal(
    lifecycle.checkWaitTimer(HANDLE, { nowMs: 2_000_000 }).remainingSeconds, 600
  );
  // Once BUSY, an expired timer is no longer a start signal.
  lifecycle.markBusy(HANDLE);
  assert.deepEqual(
    lifecycle.checkWaitTimer(HANDLE, { nowMs: 9_000_000 }),
    { remainingSeconds: 0, expired: false }
  );
});

test('the registry is bounded and fail-closed', () => {
  const lifecycle = new RoomLifecycleRegistry({ maximumRooms: 1 });
  lifecycle.beginCreate(1);
  assert.equal(refusalCode(() => lifecycle.beginCreate(2)), 'LIFECYCLE_CAPACITY');
  assert.equal(lifecycle.release(1), true);
  assert.equal(lifecycle.release(1), false);
  lifecycle.beginCreate(2);
  assert.equal(refusalCode(() => lifecycle.beginCreate(0)), 'LIFECYCLE_HANDLE');
});
