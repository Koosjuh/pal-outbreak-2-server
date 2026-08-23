import assert from 'node:assert/strict';
import test from 'node:test';

import { PlayerProfileRegistry } from '../src/state/player-profile.js';
import { ROOM_STATUS, RoomLifecycleRegistry } from '../src/state/room-lifecycle.js';
import { GameSessionError, GameSessionRegistry } from '../src/state/game-session.js';

/**
 * The broadcastGetReady bookkeeping (PacketHandler.java lines 367-398) minus
 * the GETREADY send - in PAL that is the host's op-0x10 sub-3, not a server
 * push (B1 §3). Contract rows: gamenumber minted ONCE per room; the party
 * carries it; room -> BUSY after the party is set; relay/meeting-room scope =
 * the same-gamenumber set; LEAVEAGL clears it.
 */

const HANDLE = 0x2001;

function harness({ nextGameNumber } = {}) {
  const profiles = new PlayerProfileRegistry();
  const lifecycle = new RoomLifecycleRegistry();
  lifecycle.beginCreate(HANDLE, { areaNumber: 1 });
  lifecycle.completeCreate(HANDLE, { nowMs: 0 });
  const games = new GameSessionRegistry({ nextGameNumber });
  const member = (handle) => profiles.open({ accountSessionId: `acct-${handle}`, handle });
  return { profiles, lifecycle, games, member };
}

test('start mints once, sets the party, and goes BUSY - in the reference order', () => {
  const h = harness();
  const host = h.member('HOST');
  const j2 = h.member('P2');

  // The ordering probe: when markBusy runs, every member must ALREADY carry
  // the gamenumber (broadcastGetReady assigns the party at lines 380-386
  // BEFORE the status write at line 392).
  const seenAtBusy = [];
  const probe = {
    markBusy: (handle) => {
      seenAtBusy.push([host.gamenumber, j2.gamenumber]);
      return h.lifecycle.markBusy(handle);
    }
  };

  const session = h.games.start({ roomHandle: HANDLE, members: [host, j2], lifecycle: probe });
  assert.equal(session.gamenumber, 1);
  assert.deepEqual(session.party, ['acct-HOST', 'acct-P2']);
  assert.equal(host.gamenumber, 1);
  assert.equal(j2.gamenumber, 1);
  assert.equal(h.lifecycle.statusOf(HANDLE), ROOM_STATUS.BUSY);
  assert.deepEqual(seenAtBusy, [[1, 1]], 'BUSY must run AFTER the party carries the gamenumber');
});

test('a second start of the same room REUSES the gamenumber (mint-once, gamenr==0 guard)', () => {
  const h = harness();
  const host = h.member('HOST');
  h.games.start({ roomHandle: HANDLE, members: [host], lifecycle: h.lifecycle });
  const late = h.member('LATE');
  const again = h.games.start({ roomHandle: HANDLE, members: [host, late], lifecycle: h.lifecycle });
  assert.equal(again.gamenumber, 1);
  assert.equal(late.gamenumber, 1);
  assert.equal(h.games.size, 1);
});

test('the counter is injectable and no wall clock is involved', () => {
  const minted = [];
  const h = harness({
    nextGameNumber: () => {
      const value = 7000 + minted.length;
      minted.push(value);
      return value;
    }
  });
  const session = h.games.start({
    roomHandle: HANDLE, members: [h.member('HOST')], lifecycle: h.lifecycle
  });
  assert.equal(session.gamenumber, 7000);
  assert.deepEqual(minted, [7000]);
});

test('distinct rooms get distinct gamenumbers; a duplicate mint is refused', () => {
  const h = harness();
  h.lifecycle.beginCreate(HANDLE + 1, { areaNumber: 1 });
  h.lifecycle.completeCreate(HANDLE + 1, { nowMs: 0 });
  const a = h.games.start({ roomHandle: HANDLE, members: [h.member('A')], lifecycle: h.lifecycle });
  const b = h.games.start({
    roomHandle: HANDLE + 1, members: [h.member('B')], lifecycle: h.lifecycle
  });
  assert.notEqual(a.gamenumber, b.gamenumber);

  const stuck = new GameSessionRegistry({ nextGameNumber: () => 42 });
  const lifecycle2 = new RoomLifecycleRegistry();
  for (const handle of [1, 2]) {
    lifecycle2.beginCreate(handle, { areaNumber: 1 });
    lifecycle2.completeCreate(handle, { nowMs: 0 });
  }
  const profiles = new PlayerProfileRegistry();
  const m = profiles.open({ accountSessionId: 'acct-m', handle: 'M' });
  stuck.start({ roomHandle: 1, members: [m], lifecycle: lifecycle2 });
  assert.throws(
    () => stuck.start({ roomHandle: 2, members: [m], lifecycle: lifecycle2 }),
    GameSessionError
  );
});

test('relay scope = same gamenumber minus the sender (the dumb-relay audience)', () => {
  const h = harness();
  const host = h.member('HOST');
  const j2 = h.member('P2');
  const bystander = h.member('OUTSIDE');
  h.games.start({ roomHandle: HANDLE, members: [host, j2], lifecycle: h.lifecycle });
  const scope = h.games.relayScope({ gamenumber: 1, profiles: h.profiles, except: host });
  assert.deepEqual(scope.map((profile) => profile.handle), ['P2']);
  assert.ok(!scope.includes(bystander));
});

test('meeting-room membership IS the gamenumber set; LEAVEAGL clears a member out of it', () => {
  const h = harness();
  const host = h.member('HOST');
  const j2 = h.member('P2');
  h.games.start({ roomHandle: HANDLE, members: [host, j2], lifecycle: h.lifecycle });
  // The lobby-side room dissolves while the party plays (contract §7.4 step
  // 5); the meeting room still finds the party by gamenumber.
  h.games.clearRoom(HANDLE);
  assert.deepEqual(
    h.games.meetingRoomMembers({ gamenumber: 1, profiles: h.profiles })
      .map((profile) => profile.handle),
    ['HOST', 'P2']
  );
  h.games.leaveMeetingRoom(j2);
  assert.equal(j2.gamenumber, 0);
  assert.deepEqual(
    h.games.meetingRoomMembers({ gamenumber: 1, profiles: h.profiles })
      .map((profile) => profile.handle),
    ['HOST']
  );
});

test('start refuses an empty party, a bad handle, and a missing lifecycle', () => {
  const h = harness();
  assert.throws(
    () => h.games.start({ roomHandle: HANDLE, members: [], lifecycle: h.lifecycle }),
    GameSessionError
  );
  assert.throws(
    () => h.games.start({ roomHandle: 0, members: [h.member('A')], lifecycle: h.lifecycle }),
    GameSessionError
  );
  assert.throws(
    () => h.games.start({ roomHandle: HANDLE, members: [h.member('B')] }),
    GameSessionError
  );
});
