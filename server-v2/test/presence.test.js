import assert from 'node:assert/strict';
import test from 'node:test';

import { PRESENCE_DEPTH, PresenceError, PresenceRegistry } from '../src/state/presence.js';

/**
 * The presence registry on its own: no protocol, no sockets, no clock.
 *
 * The property under test throughout is I1 - **rebuilding the indices from the
 * presence set yields exactly the current indices**. That is what a set-based
 * index buys over a counter, and it is checkable, which a counter's correctness
 * is not.
 */

function registry(options = {}) {
  return new PresenceRegistry({ ...options });
}

function attach(presence, id, serverEntryId = 'self') {
  return presence.attach({ accountSessionId: id, displayName: id, serverEntryId });
}

function refusalCode(run) {
  try {
    run();
  } catch (error) {
    assert.ok(error instanceof PresenceError, `expected a PresenceError, got ${error}`);
    return error.code;
  }
  return assert.fail('expected a refusal');
}

test('a presence starts at depth SERVER and counts there immediately', () => {
  const presence = registry();
  const one = attach(presence, 'a');
  assert.equal(one.depth, PRESENCE_DEPTH.SERVER);
  assert.equal(presence.countInServer('self'), 1);
  assert.equal(presence.countInArea(3), 0, 'in no area, which is true and not a gap');
  presence.assertConsistent();
});

test('a count for a container is the number of presences AT OR BELOW it', () => {
  const presence = registry();
  const a = attach(presence, 'a');
  const b = attach(presence, 'b');
  const c = attach(presence, 'c');
  presence.moveTo(a, { boxId: 1 });
  presence.moveTo(b, { boxId: 1 });
  presence.moveTo(b, { roomHandle: 0x10, slot: 0 });
  presence.moveTo(c, { boxId: 2 });

  assert.equal(presence.countInServer('self'), 3, 'everyone attached, at any depth');
  assert.equal(presence.countInArea(1), 2, 'b is in a room INSIDE area 1 and still counts there');
  assert.equal(presence.countInArea(2), 1);
  assert.equal(presence.countInRoom(0x10), 1);
  // The capacity invariant is true BY CONSTRUCTION, not by a separate check.
  assert.ok(presence.countInArea(1) + presence.countInArea(2) <= presence.countInServer('self'));
  presence.assertConsistent();
});

test('clearing a level clears everything below it, so a move cannot half-apply', () => {
  const presence = registry();
  const a = attach(presence, 'a');
  presence.moveTo(a, { boxId: 5 });
  presence.moveTo(a, { roomHandle: 0x20, slot: 2 });
  assert.equal(a.depth, PRESENCE_DEPTH.SLOT);

  presence.moveTo(a, { boxId: null });
  assert.deepEqual(
    { boxId: a.boxId, roomHandle: a.roomHandle, slot: a.slot },
    { boxId: null, roomHandle: null, slot: null },
    'leaving the area also left the room inside it'
  );
  assert.equal(presence.countInRoom(0x20), 0);
  presence.assertConsistent();
});

test('a slot without a room is refused, because prefix-closure is not optional', () => {
  const presence = registry();
  const a = attach(presence, 'a');
  assert.equal(refusalCode(() => presence.moveTo(a, { slot: 1 })), 'PRESENCE_PREFIX');
  assert.equal(refusalCode(() => presence.attach({ accountSessionId: 'b' })), 'PRESENCE_DEPTH');
});

test('ascend rises exactly one level, which is what one op-0x07 means', () => {
  const presence = registry();
  const a = attach(presence, 'a');
  presence.moveTo(a, { boxId: 4 });
  presence.moveTo(a, { roomHandle: 0x30, slot: 0 });
  assert.equal(presence.ascend(a), PRESENCE_DEPTH.AREA, 'out of the room, still in the area');
  assert.equal(a.boxId, 4);
  assert.equal(presence.ascend(a), PRESENCE_DEPTH.SERVER, 'out of the area, still attached');
  assert.equal(presence.ascend(a), PRESENCE_DEPTH.SERVER, 'and no further; idempotent at the top');
  presence.assertConsistent();
});

test('deleting a presence makes every view instantly correct, with no counter to update', () => {
  const presence = registry();
  const a = attach(presence, 'a');
  const b = attach(presence, 'b');
  presence.moveTo(a, { boxId: 7 });
  presence.moveTo(b, { boxId: 7 });
  presence.moveTo(a, { roomHandle: 0x40, slot: 0 });
  presence.detach(a, 'test');
  assert.equal(presence.countInArea(7), 1);
  assert.equal(presence.countInRoom(0x40), 0);
  assert.equal(presence.countInServer('self'), 1);
  presence.assertConsistent();
});

test('a room that loses its last member reports it once, and only when it is empty', () => {
  const emptied = [];
  const presence = registry({ onRoomEmptied: (handle) => emptied.push(handle) });
  const a = attach(presence, 'a');
  const b = attach(presence, 'b');
  presence.moveTo(a, { boxId: 1, roomHandle: 0x50, slot: 0 });
  presence.moveTo(b, { boxId: 1, roomHandle: 0x50, slot: 1 });
  presence.ascend(a);
  assert.deepEqual(emptied, [], 'b is still in it');
  presence.detach(b, 'test');
  assert.deepEqual(emptied, [0x50], 'reported exactly once, by the transition that emptied it');
  presence.assertConsistent();
});

test('the roster is join order, which is what the client\'s four-slot table wants', () => {
  const presence = registry();
  const first = attach(presence, 'first');
  const second = attach(presence, 'second');
  presence.moveTo(first, { boxId: 1, roomHandle: 0x60, slot: 0 });
  presence.moveTo(second, { boxId: 1, roomHandle: 0x60, slot: 1 });
  assert.deepEqual(
    presence.rosterOf(0x60).map((entry) => entry.displayName), ['first', 'second']
  );
});

test('the same account attaching twice is refused; displacement must detach first', () => {
  const presence = registry();
  attach(presence, 'a');
  // Attach-first would momentarily double-count, and a path that then removes
  // "the presence for this account" can remove the NEW one - the shape of a
  // demonstrated authorisation defect elsewhere in this codebase.
  assert.equal(refusalCode(() => attach(presence, 'a')), 'PRESENCE_DUPLICATE');
  presence.detach(presence.get('a'), 'displaced');
  assert.doesNotThrow(() => attach(presence, 'a'));
  assert.equal(presence.countInServer('self'), 1, 'never two');
});

test('a full registry refuses a new presence rather than evicting a live one', () => {
  const presence = registry({ maximumPresences: 1 });
  attach(presence, 'a');
  assert.equal(refusalCode(() => attach(presence, 'b')), 'PRESENCE_CAPACITY');
  assert.equal(presence.get('a')?.accountSessionId, 'a', 'the live player is still in');
});

test('the area population version moves on area transitions and nowhere else', () => {
  const presence = registry();
  const a = attach(presence, 'a');
  const atAttach = presence.areaPopulationVersion;
  presence.moveTo(a, { boxId: 2 });
  const afterEnter = presence.areaPopulationVersion;
  assert.notEqual(afterEnter, atAttach, 'entering an area changes the op-0x48 payload');
  presence.moveTo(a, { roomHandle: 0x70, slot: 0 });
  assert.equal(presence.areaPopulationVersion, afterEnter,
    'joining a room inside the same area does not change any area count');
  presence.detach(a, 'test');
  assert.notEqual(presence.areaPopulationVersion, afterEnter);
});

test('a randomised sequence of transitions never breaks the rebuild-and-compare invariant', () => {
  // Deterministic: a fixed LCG, so a failure is reproducible rather than a flake.
  let seed = 0x2b7e1516;
  const next = (bound) => {
    seed = (seed * 1103515245 + 12345) & 0x7fffffff;
    return seed % bound;
  };
  const presence = registry({ maximumPresences: 32 });
  const live = [];
  for (let step = 0; step < 2000; step += 1) {
    const choice = next(5);
    if (choice === 0 && live.length < 32) {
      const id = `p${step}`;
      live.push(presence.attach({ accountSessionId: id, displayName: id, serverEntryId: 'self' }));
    } else if (live.length > 0) {
      const index = next(live.length);
      const target = live[index];
      if (choice === 1) presence.moveTo(target, { boxId: 1 + next(10) });
      else if (choice === 2 && target.boxId != null) {
        presence.moveTo(target, { roomHandle: 1 + next(6), slot: next(4) });
      } else if (choice === 3) presence.ascend(target);
      else {
        presence.detach(target, 'random');
        live.splice(index, 1);
      }
    }
    presence.assertConsistent();
  }
  assert.ok(presence.totalAttached() <= 32);
});
