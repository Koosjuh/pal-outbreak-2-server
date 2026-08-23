import assert from 'node:assert/strict';
import test from 'node:test';

import { LobbyRoomRegistry, LobbyRoomsError } from '../src/state/lobby-rooms.js';
import { MAXIMUM_ROOM_LIST_RECORDS, buildRoomListPayload } from '../src/udp/snap-lobby-codec.js';

/**
 * The room model behind op-0x49.
 *
 * It exists because "no rooms" arrived as a `() => []` constructor default that
 * the composed application never overrode, so an empty lobby was
 * indistinguishable from an unwired one. These tests pin the properties that
 * make the emptiness a STATE: it is inspectable, it is per-area, and every bound
 * it enforces is one the op-0x49 codec would otherwise refuse at send time -
 * where a refusal costs the asking client its reply.
 */

function refusalCode(fn) {
  try {
    fn();
  } catch (error) {
    assert.ok(error instanceof LobbyRoomsError, `expected a LobbyRoomsError, got ${error}`);
    return error.code;
  }
  return assert.fail('expected a refusal');
}

test('a new registry holds nothing and says so, rather than answering nothing', () => {
  const rooms = new LobbyRoomRegistry();
  assert.equal(rooms.size, 0);
  assert.deepEqual(rooms.roomsIn(1), []);
});

test('rooms are listed for their own area only', () => {
  const rooms = new LobbyRoomRegistry();
  rooms.open({ handle: 1, boxId: 1, name: 'ONE', max: 4 });
  rooms.open({ handle: 2, boxId: 2, name: 'TWO', max: 4 });
  rooms.open({ handle: 3, boxId: 1, name: 'ONE-AGAIN', max: 4 });
  assert.deepEqual(rooms.roomsIn(1).map((room) => room.handle), [1, 3]);
  assert.deepEqual(rooms.roomsIn(2).map((room) => room.handle), [2]);
  assert.equal(rooms.size, 3);
});

test('a session with no area gets an empty list, never every room on the server', () => {
  const rooms = new LobbyRoomRegistry();
  rooms.open({ handle: 1, boxId: 1, name: 'ONE', max: 4 });
  assert.deepEqual(rooms.roomsIn(null), []);
  assert.deepEqual(rooms.roomsIn(9), []);
});

test('a duplicate handle is refused: the handle is what an ENTER names a room by', () => {
  const rooms = new LobbyRoomRegistry();
  rooms.open({ handle: 7, boxId: 1, name: 'ONE', max: 4 });
  assert.equal(refusalCode(() => rooms.open({ handle: 7, boxId: 2, name: 'TWO', max: 4 })),
    'ROOM_HANDLE');
  assert.equal(refusalCode(() => rooms.open({ handle: 0, boxId: 1, name: 'ZERO', max: 4 })),
    'ROOM_HANDLE');
});

test('a room whose fields the op-0x49 record cannot carry is refused when it is opened', () => {
  const rooms = new LobbyRoomRegistry();
  // 20 bytes: one past the field, and it would overwrite the current-players
  // word the row renders from.
  assert.equal(
    refusalCode(() => rooms.open({ handle: 1, boxId: 1, name: 'X'.repeat(20), max: 4 })),
    'ROOM_NAME'
  );
  assert.equal(refusalCode(() => rooms.open({ handle: 1, boxId: 1, name: '', max: 4 })),
    'ROOM_NAME');
  assert.equal(refusalCode(() => rooms.open({ handle: 1, boxId: 0, name: 'X', max: 4 })),
    'ROOM_AREA');
  assert.equal(refusalCode(() => rooms.open({ handle: 1, boxId: 1, name: 'X', max: 0 })),
    'ROOM_CAPACITY');
  // `current` is no longer a field a caller can set - it is `presence
  // .countInRoom(handle)`. The old assertion here was "current 5 of max 4 is
  // refused", which only ever guarded a number nothing updated. Population is now
  // derived, so an over-full room is not expressible rather than refused.
  assert.equal(rooms.size, 0, 'nothing partial was retained');
});

test('an area cannot hold more rooms than one op-0x49 reply can carry', () => {
  const rooms = new LobbyRoomRegistry();
  for (let index = 0; index < MAXIMUM_ROOM_LIST_RECORDS; index += 1) {
    rooms.open({ handle: index + 1, boxId: 1, name: `R${index}`, max: 4 });
  }
  // The bound is the datagram's, so the list it produces must still encode.
  assert.doesNotThrow(() => buildRoomListPayload({ rooms: rooms.roomsIn(1) }));
  assert.equal(
    refusalCode(() => rooms.open({ handle: 999, boxId: 1, name: 'ONE-TOO-MANY', max: 4 })),
    'ROOM_CAPACITY'
  );
  // Another AREA is unaffected: the bound is per reply, and one reply is one area.
  assert.doesNotThrow(() => rooms.open({ handle: 1000, boxId: 2, name: 'ELSEWHERE', max: 4 }));
});

test('closing a room removes it from its area and is idempotent', () => {
  const rooms = new LobbyRoomRegistry();
  rooms.open({ handle: 5, boxId: 3, name: 'FIVE', max: 4 });
  assert.equal(rooms.close(5), true);
  assert.equal(rooms.close(5), false);
  assert.deepEqual(rooms.roomsIn(3), []);
});
