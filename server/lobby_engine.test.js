'use strict';
// Unit tests for lobby_engine.js (FOUNDATION step 1) — run: node server/lobby_engine.test.js
// Each block asserts a REFERENCE behavior (Bioserver PacketHandler/ClientList/Slot, file:line in
// the engine's comments) against the port. Pure state + emission plans; no wire.
const { LobbyState, AREA_SELECT, SLOT } = require('./lobby_state');
const { createEngine } = require('./lobby_engine');

let pass = 0, fail = 0;
function eq(actual, expected, msg) {
  if (actual === expected) { pass++; }
  else { fail++; console.error(`  FAIL: ${msg}  (got ${JSON.stringify(actual)}, want ${JSON.stringify(expected)})`); }
}
function kinds(plan) { return plan.map(e => e.kind); }
function count(plan, kind) { return plan.filter(e => e.kind === kind).length; }

function fresh() {
  const L = new LobbyState();
  L.SLOT = SLOT;
  const E = createEngine(L);
  return { L, E };
}

// 1. INCREATE rejects joiners (PacketHandler.java:1660); GAMESET admits; BUSY rejects.
{
  const { L, E } = fresh();
  L.bindEndpoint({ transportKey: 'h:1', userid: 'H', handle: 'HOST' });
  L.enterArea('h:1', 1);
  const { room } = E.createRoom('h:1', { name: 'R', maxPlayers: 2 });
  eq(room.status, SLOT.INCREATE, 'created room is INCREATE');
  L.bindEndpoint({ transportKey: 'j:1', userid: 'J', handle: 'JOIN' });
  L.enterArea('j:1', 1);
  const r1 = E.joinRoom('j:1', room.handle);
  eq(r1.ok, false, 'INCREATE rejects the joiner');
  eq(r1.reason, 'in-create', 'reject reason in-create');
  E.goLive('h:1');
  eq(room.status, SLOT.GAMESET, 'go-live -> GAMESET');
  const r2 = E.joinRoom('j:1', room.handle);
  eq(r2.ok, true, 'GAMESET admits the joiner');
  eq(room.status, SLOT.BUSY, 'full (2/2) -> BUSY');
  L.bindEndpoint({ transportKey: 'x:1', userid: 'X', handle: 'XX' });
  L.enterArea('x:1', 1);
  eq(E.joinRoom('x:1', room.handle).reason, 'full', 'BUSY rejects with full');
}

// 2. playerNo: host=1; joiners get lowest free of 2..max (ClientList.java:98-108).
{
  const { L, E } = fresh();
  for (const [k, h] of [['a:1', 'A'], ['b:1', 'B'], ['c:1', 'C']]) {
    L.bindEndpoint({ transportKey: k, userid: h, handle: h });
    L.enterArea(k, 1);
  }
  const { room } = E.createRoom('a:1', { maxPlayers: 4 });
  E.goLive('a:1');
  E.joinRoom('b:1', room.handle);
  E.joinRoom('c:1', room.handle);
  eq(L.playerByEndpoint('a:1').playerNo, 1, 'host playerNo 1');
  eq(L.playerByEndpoint('b:1').playerNo, 2, 'first joiner playerNo 2');
  eq(L.playerByEndpoint('c:1').playerNo, 3, 'second joiner playerNo 3');
  // b leaves; a new joiner takes the freed 2 (lowest free)
  E.leaveRoom('b:1');
  L.bindEndpoint({ transportKey: 'd:1', userid: 'D', handle: 'D' });
  L.enterArea('d:1', 1);
  E.joinRoom('d:1', room.handle);
  eq(L.playerByEndpoint('d:1').playerNo, 2, 'freed playerNo 2 reassigned lowest-free');
}

// 3. Join emissions: joiner record to EVERY member incl. self; existing members' records to joiner;
//    counts to room+list viewers (PLAYERSTATBC + SLOTPLRSTATUS order).
{
  const { L, E } = fresh();
  L.bindEndpoint({ transportKey: 'a:1', userid: 'A', handle: 'A' }); L.enterArea('a:1', 1);
  L.bindEndpoint({ transportKey: 'b:1', userid: 'B', handle: 'B' }); L.enterArea('b:1', 1);
  L.bindEndpoint({ transportKey: 'v:1', userid: 'V', handle: 'V' }); L.enterArea('v:1', 1); // list viewer
  const { room } = E.createRoom('a:1', {});
  E.goLive('a:1');
  const res = E.joinRoom('b:1', room.handle);
  eq(res.ok, true, 'join ok');
  // Authoritative full-state: MEMBER_LIST to EVERY member (A and B), not deltas.
  eq(count(res.plan, E.K.MEMBER_LIST), 2, 'member-LIST to both members (A and B)');
  const aGotList = res.plan.some(e => e.kind === E.K.MEMBER_LIST && e.to.idKey === 'uid:A');
  const bGotList = res.plan.some(e => e.kind === E.K.MEMBER_LIST && e.to.idKey === 'uid:B');
  eq(aGotList && bGotList, true, 'both the existing member (A) and the joiner (B) get the full roster');
  eq(count(res.plan, E.K.COUNT_0X11) >= 3, true, 'count update to members + list viewer');
  const viewerGotCount = res.plan.some(e => e.kind === E.K.COUNT_0X11 && e.to.idKey === 'uid:V');
  eq(viewerGotCount, true, 'room-list viewer gets the count too (broadcastInSlotNRoom)');
}

// 4. Host leave dissolves (no migration) with cancel-notify; member leave notifies + recomputes.
{
  const { L, E } = fresh();
  L.bindEndpoint({ transportKey: 'a:1', userid: 'A', handle: 'A' }); L.enterArea('a:1', 1);
  L.bindEndpoint({ transportKey: 'b:1', userid: 'B', handle: 'B' }); L.enterArea('b:1', 1);
  const { room } = E.createRoom('a:1', {});
  E.goLive('a:1');
  E.joinRoom('b:1', room.handle);
  // member leave first
  const r1 = E.leaveRoom('b:1');
  eq(count(r1.plan, E.K.MEMBER_LEAVE), 1, 'member leave -> op07 member-leave to the survivor');
  eq(L.rooms.has(room.handle), true, 'room persists after member leave');
  eq(room.status, SLOT.GAMESET, 'member leave -> back to GAMESET');
  // host leave dissolves — same op07 vehicle (SPINE-3: no distinct host-cancel op)
  E.joinRoom('b:1', room.handle);
  const r2 = E.leaveRoom('a:1');
  eq(count(r2.plan, E.K.MEMBER_LEAVE), 1, 'host leave -> same op07 member-leave to the survivor');
  eq(L.rooms.has(room.handle), false, 'host leave dissolves the room (no migration)');
  eq(L.playerByEndpoint('b:1').room, 0, 'survivor evicted from the dissolved room');
}

// 5. Area transitions emit count updates to area viewers + area-select viewers.
{
  const { L, E } = fresh();
  L.bindEndpoint({ transportKey: 's:1', userid: 'S', handle: 'S' });   // sits in Area Select
  L.bindEndpoint({ transportKey: 'a:1', userid: 'A', handle: 'A' });
  const res = E.enterArea('a:1', 2);
  eq(count(res.plan, E.K.AREA_COUNT) >= 2, true, 'enterArea -> counts to entrant + area-select viewer');
  const toSelect = res.plan.some(e => e.kind === E.K.AREA_COUNT && e.to.idKey === 'uid:S');
  eq(toSelect, true, 'area-select viewer receives the count update');
  eq(res.plan[0].args.counts.inLobby, 1, 'count triple inLobby=1');
}

// 6. Liveness + join-request + member-list transitions emit the proven vehicles.
{
  const { L, E } = fresh();
  L.bindEndpoint({ transportKey: 'a:1', userid: 'A', handle: 'A' }); L.enterArea('a:1', 1);
  L.bindEndpoint({ transportKey: 'b:1', userid: 'B', handle: 'B' }); L.enterArea('b:1', 1);
  const { room } = E.createRoom('a:1', {}); E.goLive('a:1'); E.joinRoom('b:1', room.handle);
  eq(kinds(E.onRoomLiveness('b:1').plan)[0], E.K.LIVENESS_0F, 'sub-0x0e -> sub-0x0f');
  eq(L.playerByEndpoint('b:1').lastRoomLivenessAt > 0, true, 'liveness timestamp touched');
  eq(kinds(E.onJoinRequest('b:1').plan)[0], E.K.JOIN_ACCEPT_0C, 'sub-0x02 -> sub-0x0C');
  eq(E.onJoinRequest('b:1').plan[0].args.count, 2, 'sub-0x0C carries the real count');
  eq(kinds(E.onMemberListPull('b:1').plan)[0], E.K.MEMBER_LIST, 'op0a pull -> member list');
  const pub = E.onHostPublish('a:1');
  eq(count(pub.plan, E.K.MEMBER_LIST), 2, 'host publish -> authoritative list refresh to both members');
  eq(E.onHostPublish('b:1').plan.length, 0, 'non-host publish ignored');
}

// 7. Identity: displayName prefers hnpair; memberRecord carries it; synthetic fallback otherwise.
{
  const { L, E } = fresh();
  L.bindEndpoint({ transportKey: 'a:1', userid: 'A', handle: 'loginA' }); L.enterArea('a:1', 1);
  const { room } = E.createRoom('a:1', {});
  const p = L.playerByEndpoint('a:1');
  eq(E.memberRecord(room, p).name, 'loginA', 'login handle used before hnpair (seeded identity)');
  L.setIdentity('a:1', { handle: 'KOOS', nickname: 'Koos' });
  eq(E.memberRecord(room, p).name, 'Koos', 'hnpair nickname wins once HNSELECT lands');
  eq(E.memberRecord(room, p).isHost, true, 'host flag in the record');
}

// 8. Ghost sweep: GAMESET+empty -> FREE (seeded rooms exempt).
{
  const { L, E } = fresh();
  L.bindEndpoint({ transportKey: 'a:1', userid: 'A', handle: 'A' }); L.enterArea('a:1', 1);
  const seeded = L.seedRoom({ name: 'PAL LOBBY' });
  const { room } = E.createRoom('a:1', {});
  E.goLive('a:1');
  // empty the created room without dissolving (simulate the ghost condition)
  room.members.clear(); room.hostId = 'gone';
  const res = E.ghostSweep();
  eq(room.status, SLOT.FREE, 'ghost GAMESET room swept to FREE');
  eq(seeded.status, SLOT.GAMESET, 'seeded room untouched by the sweep');
  eq(res.plan.every(e => e.kind === E.K.ROOMLIST_DIRTY), true, 'sweep emits roomlist refreshes only');
}

// 9. Timeout = the same cleanup as leave (removeClient port).
{
  const { L, E } = fresh();
  L.bindEndpoint({ transportKey: 'a:1', userid: 'A', handle: 'A' }); L.enterArea('a:1', 1);
  L.bindEndpoint({ transportKey: 'b:1', userid: 'B', handle: 'B' }); L.enterArea('b:1', 1);
  const { room } = E.createRoom('a:1', {}); E.goLive('a:1'); E.joinRoom('b:1', room.handle);
  const res = E.onLivenessTimeout('b:1');
  eq(count(res.plan, E.K.MEMBER_LEAVE), 1, 'timeout -> op07 member-leave to survivors');
  eq(room.members.size, 1, 'timed-out member removed from the room');
}

console.log(`\nlobby_engine tests: ${pass} pass, ${fail} fail`);
process.exit(fail ? 1 : 0);
