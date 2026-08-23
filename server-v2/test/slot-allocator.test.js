import assert from 'node:assert/strict';
import test from 'node:test';

import { PresenceRegistry } from '../src/state/presence.js';
import { LobbyRoomRegistry } from '../src/state/lobby-rooms.js';
import { PlayerProfileRegistry } from '../src/state/player-profile.js';
import { ROOM_STATUS, RoomLifecycleRegistry } from '../src/state/room-lifecycle.js';
import {
  JOIN_REFUSAL,
  SlotAllocator,
  SlotAllocatorError
} from '../src/state/slot-allocator.js';

/**
 * The JOINGAME/CANCELSLOT contract rows (BIOSERVER-CONTRACT §6, oracle
 * PacketHandler.sendJoinGame lines 1642-1703 and sendCancelSlot 1356-1396),
 * driven against the REAL presence + room registries so the invariants they
 * enforce (P1 prefix-closure, P2 single home, derived population) are part of
 * the test, not mocked away.
 */

function harness() {
  const presence = new PresenceRegistry({
    onRoomEmptied: (handle) => {
      rooms.close(handle);
      lifecycle.release(handle);
    }
  });
  const rooms = new LobbyRoomRegistry({ countInRoom: (handle) => presence.countInRoom(handle) });
  const lifecycle = new RoomLifecycleRegistry();
  const profiles = new PlayerProfileRegistry();
  const allocator = new SlotAllocator({ presence, profiles, lifecycle });

  let accountSerial = 0;
  const player = (handle) => {
    accountSerial += 1;
    const accountSessionId = `acct-${accountSerial}`;
    const record = presence.attach({ accountSessionId, serverEntryId: 'self', displayName: handle });
    presence.moveTo(record, { boxId: 3 });
    profiles.open({ accountSessionId, handle });
    return record;
  };

  /** The rig-confirmed create path + the engine's status attach. */
  const createRoom = (host, { max = 4, complete = true } = {}) => {
    const room = rooms.openFor({ presence, host, boxId: 3, name: 'ROOM', max });
    lifecycle.beginCreate(room.handle, { areaNumber: 3 });
    allocator.assignHost({ room, hostPresence: host });
    if (complete) lifecycle.completeCreate(room.handle, { nowMs: 0 });
    return room;
  };

  return { presence, rooms, lifecycle, profiles, allocator, player, createRoom };
}

test('host = playernum 1, hostflag 1, presence slot 0 (sendCreateSlot 1194-1195)', () => {
  const h = harness();
  const host = h.player('HOST');
  const room = h.createRoom(host);
  const profile = h.profiles.get(host.accountSessionId);
  assert.equal(profile.playernum, 1);
  assert.equal(profile.hostflag, 1);
  assert.equal(host.roomHandle, room.handle);
  assert.equal(host.slot, 0);
});

test('joiners take the first free of 2, 3, 4 (ClientList.getFreePlayerNum 98-108)', () => {
  const h = harness();
  const room = h.createRoom(h.player('HOST'));
  const j2 = h.player('P2');
  const j3 = h.player('P3');
  const j4 = h.player('P4');
  assert.deepEqual(h.allocator.join({ room, presence: j2 }), { ok: true, playernum: 2 });
  assert.deepEqual(h.allocator.join({ room, presence: j3 }), { ok: true, playernum: 3 });
  assert.deepEqual(h.allocator.join({ room, presence: j4 }), { ok: true, playernum: 4 });
  // Presence slot = playernum - 1, and the room's DERIVED population followed.
  assert.equal(j3.slot, 2);
  assert.equal(room.current, 4);
  h.presence.assertConsistent();
});

test('a freed playernum is reused: 2,3 join, 2 leaves, the next joiner gets 2', () => {
  const h = harness();
  const room = h.createRoom(h.player('HOST'));
  const j2 = h.player('P2');
  const j3 = h.player('P3');
  h.allocator.join({ room, presence: j2 });
  h.allocator.join({ room, presence: j3 });
  h.allocator.leave({ room, presence: j2 });
  assert.equal(h.profiles.get(j2.accountSessionId).playernum, 0);
  assert.equal(j2.roomHandle, null);
  const late = h.player('LATE');
  assert.deepEqual(h.allocator.join({ room, presence: late }), { ok: true, playernum: 2 });
});

test('join-guard ORDER row 1: BUSY wins over everything - a full password room says "full", not "wrong password"', () => {
  const h = harness();
  const room = h.createRoom(h.player('HOST'), { max: 2 });
  h.lifecycle.setPassword(room.handle, Buffer.from('SECRET'));
  h.allocator.join({ room, presence: h.player('P2'), password: Buffer.from('SECRET') });
  // Room is now full -> BUSY (sendJoinGame 1683-1686).
  assert.equal(h.lifecycle.statusOf(room.handle), ROOM_STATUS.BUSY);
  const refusal = h.allocator.join({
    room, presence: h.player('P3'), password: Buffer.from('WRONG')
  });
  assert.deepEqual(refusal, { ok: false, reason: JOIN_REFUSAL.FULL });
});

test('join-guard ORDER row 2: not-GAMESET wins over the password - an INCREATE password room says "not possible"', () => {
  const h = harness();
  const room = h.createRoom(h.player('HOST'), { complete: false });
  h.lifecycle.setPassword(room.handle, Buffer.from('SECRET'));
  const refusal = h.allocator.join({
    room, presence: h.player('P2'), password: Buffer.from('WRONG')
  });
  assert.deepEqual(refusal, { ok: false, reason: JOIN_REFUSAL.NOT_POSSIBLE });
});

test('join-guard row 3: wrong password refused, right password joins, unprotected ignores it', () => {
  const h = harness();
  const room = h.createRoom(h.player('HOST'));
  h.lifecycle.setPassword(room.handle, Buffer.from('SECRET'));
  assert.deepEqual(
    h.allocator.join({ room, presence: h.player('P2'), password: Buffer.from('WRONG') }),
    { ok: false, reason: JOIN_REFUSAL.WRONG_PASSWORD }
  );
  assert.equal(
    h.allocator.join({ room, presence: h.player('P3'), password: Buffer.from('SECRET') }).ok,
    true
  );
  const open = h.createRoom(h.player('HOST2'));
  assert.equal(h.allocator.join({ room: open, presence: h.player('P4') }).ok, true);
});

test('create-dialogue: the room is joinable ONLY at the final step (send6504)', () => {
  const h = harness();
  const room = h.createRoom(h.player('HOST'), { complete: false });
  const joiner = h.player('EARLY');
  // Mid-dialogue: INCREATE -> "not possible".
  assert.deepEqual(
    h.allocator.join({ room, presence: joiner }),
    { ok: false, reason: JOIN_REFUSAL.NOT_POSSIBLE }
  );
  // The final step flips it.
  h.lifecycle.completeCreate(room.handle, { nowMs: 0 });
  assert.deepEqual(h.allocator.join({ room, presence: joiner }), { ok: true, playernum: 2 });
});

test('a rejected joiner is NOT moved: presence stays in the area (mutate only on accept)', () => {
  const h = harness();
  const room = h.createRoom(h.player('HOST'), { complete: false });
  const joiner = h.player('P2');
  h.allocator.join({ room, presence: joiner });
  assert.equal(joiner.roomHandle, null);
  assert.equal(joiner.boxId, 3);
  assert.equal(room.current, 1);
});

test('leave recompute: a BUSY-because-full room reopens to GAMESET when a joiner leaves', () => {
  const h = harness();
  const room = h.createRoom(h.player('HOST'), { max: 2 });
  const j2 = h.player('P2');
  h.allocator.join({ room, presence: j2 });
  assert.equal(h.lifecycle.statusOf(room.handle), ROOM_STATUS.BUSY);
  h.allocator.leave({ room, presence: j2 });
  assert.equal(h.lifecycle.statusOf(room.handle), ROOM_STATUS.GAMESET);
});

test('leave recompute: the LAST member leaving closes room, lifecycle record and status', () => {
  const h = harness();
  const host = h.player('HOST');
  const room = h.createRoom(host);
  h.allocator.leave({ room, presence: host });
  // onRoomEmptied closed the room and released the lifecycle record.
  assert.equal(h.rooms.byHandle(room.handle), null);
  assert.equal(h.lifecycle.get(room.handle), null);
  assert.equal(h.profiles.get(host.accountSessionId).hostflag, 0);
  assert.equal(host.roomHandle, null);
  h.presence.assertConsistent();
});

test('leave recompute: the HOST leaving with members remaining resets, does NOT reopen', () => {
  const h = harness();
  const host = h.player('HOST');
  const room = h.createRoom(host);
  h.allocator.join({ room, presence: h.player('P2') });
  h.allocator.leave({ room, presence: host });
  // sendCancelSlot: host path resets the slot; the ishost==0 condition keeps
  // the reopen-to-GAMESET from firing, so the room reads FREE.
  assert.equal(h.lifecycle.statusOf(room.handle), ROOM_STATUS.FREE);
  assert.equal(h.profiles.get(host.accountSessionId).hostflag, 0);
});

test('the allocator refuses to construct unwired, and a profile-less JOIN is a refusal result', () => {
  const h = harness();
  assert.throws(() => new SlotAllocator({}), SlotAllocatorError);
  const ghost = h.presence.attach({ accountSessionId: 'no-profile', serverEntryId: 'self' });
  h.presence.moveTo(ghost, { boxId: 3 });
  const room = h.createRoom(h.player('HOST'));
  /*
   * SUPERSEDED 2026-08-08 (nora pre-deploy fix 3): this used to assert the
   * join THREW SlotAllocatorError. A profile-less session is peer-reachable
   * (the bind's profile open is logged-and-tolerated), so the join path
   * returns a structured refusal that the session journals as a join refusal
   * instead of a generic handler-threw. The server-initiated transitions keep
   * the throw - a missing profile there is a genuine defect.
   */
  assert.deepEqual(
    h.allocator.join({ room, presence: ghost }),
    { ok: false, reason: JOIN_REFUSAL.NO_PROFILE },
    'peer-reachable state is a result, never a throw through the dispatch guard'
  );
  assert.equal(ghost.roomHandle, null, 'and nothing moved');
  assert.throws(
    () => h.allocator.leave({ room, presence: ghost }),
    (error) => error instanceof SlotAllocatorError && error.code === 'ALLOCATOR_PROFILE',
    'leave keeps the programmer-error throw'
  );
  assert.throws(() => h.allocator.join({ room, presence: null }), SlotAllocatorError,
    'a join without a live presence is still a defect, not a refusal');
});
