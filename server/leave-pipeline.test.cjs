'use strict';
// Automated coverage for the engine-owned LEAVE / survivor-notify (op07) pipeline (SPINE-3).
// Run: node server/leave-pipeline.test.cjs
// Evidence: docs/findings/protocol/SPINE-2-3-lobby-leave-RE-2026-07-19.md — the survivor-notify vehicle
// is op07 (MEMBER LEAVE, slot 6 FUN_005bb670): the leaver's 32-bit member-id at body+0; each survivor
// fires event 0x20 REMOVE + decrements the in-room count; host departure = the SAME op07 (no distinct
// dissolve op). This test asserts the ENGINE half (transition -> ordered emission plan). State model
// only (no wire/transport); the op07 body byte layout + 2-client render are the rig capture (EXP-C5).
const assert = require('assert');
const LS = require('./lobby_state');
const { LobbyState } = LS;
const SLOT = LS.SLOT;
const { createEngine } = require('./lobby_engine');

let pass = 0;
const ok = (c, m) => { assert.ok(c, m); console.log('  ✓ ' + m); pass++; };
const eq = (a, b, m) => { assert.strictEqual(a, b, `${m} (got ${a}, want ${b})`); console.log('  ✓ ' + m); pass++; };

// A host (A) + N joiners, all go-live so joins are accepted. Returns the room + engine + state.
function room2() {
  const L = new LobbyState(); const E = createEngine(L);
  L.bindEndpoint({ transportKey: 'A:1', userid: 'hostguy', handle: 'hostguy' }); L.enterArea('A:1', 1);
  L.bindEndpoint({ transportKey: 'B:1', userid: 'joinerB', handle: 'joinerB' }); L.enterArea('B:1', 1);
  const room = L.createRoom('A:1', { name: 'ROOM', maxPlayers: 4 });
  E.goLive('A:1');
  E.joinRoom('B:1', room.handle);
  return { L, E, room };
}
// Map an emission kind to a short tag for order assertions.
const tag = (E, k) => k === E.K.MEMBER_LEAVE ? 'op07' : k === E.K.MEMBER_LIST ? 'op0a'
  : k === E.K.COUNT_0X11 ? 'count' : k === E.K.ROOMLIST_DIRTY ? 'dirty' : k;
const kinds = (plan, E) => plan.map(e => tag(E, e.kind));
const count = (plan, kind) => plan.filter(e => e.kind === kind).length;

// --- A: member leave — survivors get op07 with the LEAVER id, ordered op07 -> op0a -> count ---
{
  const { L, E, room } = room2();
  const bId = L.playerByEndpoint('B:1').playerNo;   // the id survivors matched at join (op06 record+0x10)
  eq(bId, 2, 'A: joiner B has playerNo 2 (the member-id op07 must carry)');
  const r = E.leaveRoom('B:1');
  const op07 = r.plan.filter(e => e.kind === E.K.MEMBER_LEAVE);
  eq(op07.length, 1, 'A: exactly one op07 survivor-notify (to the host A)');
  ok(op07[0].to.idKey === 'uid:hostguy', 'A: op07 recipient is the SURVIVING host (A), not the leaver');
  eq(op07[0].args.id, bId, 'A: op07 body carries the LEAVER member-id (playerNo 2, FUN_005bb670 @body+0)');
  ok(op07.every(e => e.to.idKey !== 'uid:joinerB'), 'A: the leaver B receives NO op07');
  // order: every op07 precedes every op0a; every op0a precedes count
  const k = kinds(r.plan, E);
  const lastOp07 = k.lastIndexOf('op07'), firstOp0a = k.indexOf('op0a'), lastOp0a = k.lastIndexOf('op0a'), firstCount = k.indexOf('count');
  ok(lastOp07 < firstOp0a, 'A: order — every op07 precedes op0a (live REMOVE before durable roster)');
  ok(lastOp0a < firstCount, 'A: order — every op0a precedes count');
  eq(L.roomPlayerCount(room.handle), 1, 'A: room count decremented to 1 after the leave');
}

// --- B: durable op0a drops the leaver so a survivor's next poll does NOT re-add them ---
{
  const { L, E, room } = room2();
  E.leaveRoom('B:1');
  // The durable whole-list pull (op0a) after the leave enumerates only the survivor(s).
  const pull = E.onMemberListPull('A:1');
  eq(count(pull.plan, E.K.MEMBER_LIST), 1, 'B: host A still gets its op0a whole-list on the next poll');
  const members = L.membersOf(room.handle).map(m => m.idKey);
  ok(!members.includes('uid:joinerB'), 'B: the leaver is dropped from the durable roster (no re-add on poll)');
  eq(members.length, 1, 'B: only the host remains in the durable member list');
}

// --- C: host leave = the SAME op07 (host id) and DISSOLVES the room (SD-5, no migration) ---
{
  const { L, E, room } = room2();
  const aId = L.playerByEndpoint('A:1').playerNo;
  const r = E.leaveRoom('A:1');
  const op07 = r.plan.filter(e => e.kind === E.K.MEMBER_LEAVE);
  eq(op07.length, 1, 'C: host leave -> one op07 survivor-notify (to B), the SAME vehicle as member-leave');
  eq(op07[0].args.id, aId, 'C: op07 carries the HOST member-id (playerNo 1) — host departure = same op07');
  ok(op07[0].to.idKey === 'uid:joinerB', 'C: the surviving member B receives the op07');
  ok(op07[0].args.wasHost === true, 'C: the plan flags wasHost (dissolve) for the frontend');
  eq(L.rooms.has(room.handle), false, 'C: host leave dissolves the room (no migration)');
  eq(L.playerByEndpoint('B:1').room, 0, 'C: the survivor is evicted from the dissolved room');
  // dissolved -> no op0a/count (room gone); room-list viewers just re-derive (dirty).
  eq(count(r.plan, E.K.MEMBER_LIST), 0, 'C: no op0a after dissolve (room is gone)');
}

// --- D: disconnect/timeout produces the SAME plan as a graceful leave (single ownership) ---
{
  const a = room2();
  const graceful = a.E.leaveRoom('B:1');
  const b = room2();
  const timeout = b.E.onLivenessTimeout('B:1');
  const gk = kinds(graceful.plan, a.E).join(',');
  const tk = kinds(timeout.plan, b.E).join(',');
  eq(tk, gk, 'D: timeout leave emits the identical ordered plan as the graceful leave');
  eq(count(timeout.plan, b.E.K.MEMBER_LEAVE), 1, 'D: timeout still produces the op07 survivor-notify');
  eq(b.L.roomPlayerCount(b.room.handle), 1, 'D: timeout removed the member from the room');
}

// --- E: idempotency — leaving a room you are not in emits an EMPTY plan ---
{
  const { L, E } = room2();
  // B leaves once (now out of the room)...
  E.leaveRoom('B:1');
  // ...leaving again is a no-op.
  const again = E.leaveRoom('B:1');
  eq(again.plan.length, 0, 'E: re-leaving (not a member) emits an EMPTY plan');
  // a player who was never in any room:
  L.bindEndpoint({ transportKey: 'Z:1', userid: 'ghost', handle: 'ghost' });
  const never = E.leaveRoom('Z:1');
  eq(never.plan.length, 0, 'E: leaving with no room emits an EMPTY plan');
}

// --- F: 3-member room — a middle member leaves; BOTH survivors get op07 (fan-out) ---
{
  const L = new LobbyState(); const E = createEngine(L);
  for (const [k, h] of [['A:1', 'hostA'], ['B:1', 'memB'], ['C:1', 'memC']]) {
    L.bindEndpoint({ transportKey: k, userid: h, handle: h }); L.enterArea(k, 1);
  }
  const room = L.createRoom('A:1', { maxPlayers: 4 }); E.goLive('A:1');
  E.joinRoom('B:1', room.handle); E.joinRoom('C:1', room.handle);
  const bId = L.playerByEndpoint('B:1').playerNo;
  const r = E.leaveRoom('B:1');
  const op07 = r.plan.filter(e => e.kind === E.K.MEMBER_LEAVE);
  eq(op07.length, 2, 'F: both surviving members (A and C) get an op07');
  ok(op07.every(e => e.args.id === bId), 'F: every op07 carries the leaver B member-id');
  const recips = new Set(op07.map(e => e.to.idKey));
  ok(recips.has('uid:hostA') && recips.has('uid:memC'), 'F: op07 fans out to A and C (not to the leaver B)');
  eq(L.roomPlayerCount(room.handle), 2, 'F: room count decremented to 2');
}

console.log(`\nleave-pipeline: ${pass} assertions passed`);
