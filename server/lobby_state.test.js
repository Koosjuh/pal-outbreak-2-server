'use strict';
// Local unit test for lobby_state.js — run: node server/lobby_state.test.js
const { LobbyState, AREA_SELECT } = require('./lobby_state');
let pass = 0, fail = 0;
function eq(actual, expected, msg) {
  if (actual === expected) { pass++; }
  else { fail++; console.error(`  FAIL: ${msg}  (got ${JSON.stringify(actual)}, want ${JSON.stringify(expected)})`); }
}

// 1. Two DIFFERENT clients enter the same area -> count == 2 (the G12 step-3 proof, in-memory)
{
  const L = new LobbyState();
  L.bindEndpoint({ transportKey: '10.0.0.1:2000', userid: '111', handle: 'ALICE' });
  L.bindEndpoint({ transportKey: '10.0.0.2:2000', userid: '222', handle: 'BOB' });
  L.enterArea('10.0.0.1:2000', 3);
  L.enterArea('10.0.0.2:2000', 3);
  eq(L.areaPlayerCount(3), 2, 'two clients in area 3 -> count 2');
  eq(L.areaPlayerCount(5), 0, 'empty area 5 -> count 0');
  // one leaves
  L.exitArea('10.0.0.2:2000');
  eq(L.areaPlayerCount(3), 1, 'after one exits -> count 1');
  // the one who left is back in Area Select
  eq(L.playerByEndpoint('10.0.0.2:2000').area, AREA_SELECT, 'exited player back in Area Select');
}

// 2. Same client cycles areas -> moves membership, never double-counts
{
  const L = new LobbyState();
  L.enterArea('10.0.0.1:2000', 1);
  L.enterArea('10.0.0.1:2000', 2); // switched areas without explicit exit
  eq(L.areaPlayerCount(1), 0, 'left area 1');
  eq(L.areaPlayerCount(2), 1, 'now in area 2');
}

// 3. Re-register: same userid from a NEW endpoint REPLACES (no phantom double-count)
{
  const L = new LobbyState();
  L.bindEndpoint({ transportKey: '10.0.0.1:2000', userid: '111', handle: 'ALICE' });
  L.enterArea('10.0.0.1:2000', 4);
  eq(L.areaPlayerCount(4), 1, 'alice in area 4');
  // alice reconnects from a new UDP port, same userid
  L.bindEndpoint({ transportKey: '10.0.0.1:2050', userid: '111', handle: 'ALICE' });
  eq(L.players.size, 1, 're-register keeps ONE player for the same userid');
  eq(L.areaPlayerCount(4), 1, 're-register does not double-count area membership');
}

// 4. Two clients behind ONE IP (emulator + PS2), different ports -> do NOT collide
{
  const L = new LobbyState();
  L.bindEndpoint({ transportKey: '192.0.2.5:2000', userid: 'A', handle: 'A' });
  L.bindEndpoint({ transportKey: '192.0.2.5:2001', userid: 'B', handle: 'B' });
  L.enterArea('192.0.2.5:2000', 7);
  L.enterArea('192.0.2.5:2001', 7);
  eq(L.areaPlayerCount(7), 2, 'two identities behind one IP -> count 2');
}

// 5. Disconnect/timeout clears membership + reclaims the player
{
  const L = new LobbyState();
  L.bindEndpoint({ transportKey: '10.0.0.9:2000', userid: 'Z', handle: 'Z' });
  L.enterArea('10.0.0.9:2000', 2);
  eq(L.areaPlayerCount(2), 1, 'Z in area 2');
  L.removeEndpoint('10.0.0.9:2000');
  eq(L.areaPlayerCount(2), 0, 'after disconnect -> area empty');
  eq(L.players.size, 0, 'player reclaimed (no endpoints left)');
  eq(L.playerByEndpoint('10.0.0.9:2000'), null, 'endpoint index cleared');
}

// 6. Transient (pre-bind) endpoint can still enter an area; later bind carries membership
{
  const L = new LobbyState();
  L.enterArea('10.0.0.3:2000', 6);           // no identity yet -> transient player
  eq(L.areaPlayerCount(6), 1, 'transient endpoint counted');
  L.bindEndpoint({ transportKey: '10.0.0.3:2000', userid: '333', handle: 'CARL' });
  eq(L.players.size, 1, 'bind reuses/migrates the transient player (no phantom)');
  eq(L.areaPlayerCount(6), 1, 'area membership carried across bind');
}

// 7. ROOMS — the 2-client "A creates -> B sees -> B joins" loop (the G12 multiplayer core, in-memory)
{
  const L = new LobbyState();
  L.bindEndpoint({ transportKey: 'a:1', userid: 'A', handle: 'A' }); L.enterArea('a:1', 3);
  L.bindEndpoint({ transportKey: 'b:1', userid: 'B', handle: 'B' }); L.enterArea('b:1', 3);
  const room = L.createRoom('a:1', { name: 'TESTROOM', maxPlayers: 4 });
  eq(L.roomList().length, 1, 'A created a room -> 1 room in the list');
  eq(room.members.size, 1, 'new room has the host (1 player)');
  eq(L.playerByEndpoint('a:1').host, true, 'A is host');
  // B (in the same effectively-global list) sees it and joins
  eq(L.roomList()[0].name, 'TESTROOM', 'B sees TESTROOM in the room list');
  L.joinRoom('b:1', room.handle);
  eq(L.roomPlayerCount(room.handle), 2, 'B joined -> room has 2 players');
  eq(L.playerByEndpoint('b:1').room, room.handle, 'B is in the room');
  eq(L.roomList()[0].current, 2, 'op49 record shows 2/4');
}

// 8. Room lifecycle: full rejects; non-host leave decrements; host leave dissolves
{
  const L = new LobbyState();
  const r = L.createRoom('h:1', { name: 'R', maxPlayers: 2 });
  L.joinRoom('g:1', r.handle);
  eq(L.joinRoom('x:1', r.handle), null, 'join a full room -> rejected');
  L.leaveRoom('g:1');
  eq(L.roomPlayerCount(r.handle), 1, 'non-host left -> 1 player');
  L.leaveRoom('h:1');                                  // host leaves
  eq(L.rooms.size, 0, 'host left -> room dissolved');
}

// 11. Switching rooms leaves the old one — no leaked occupancy (nora-flagged guard)
{
  const L = new LobbyState();
  const r1 = L.createRoom('a:1', { name: 'R1', maxPlayers: 4 });
  const r2 = L.createRoom('b:1', { name: 'R2', maxPlayers: 4 });
  L.joinRoom('a:1', r2.handle);                        // A (host of r1) switches to r2
  eq(L.rooms.has(r1.handle), false, 'A switching rooms dissolved its old host room r1');
  eq(L.roomPlayerCount(r2.handle), 2, 'r2 now has both A and B');
  eq(L.playerByEndpoint('a:1').room, r2.handle, 'A is in r2, not double-counted in r1');
}

// 9. Disconnect leaves the room (and dissolves if host)
{
  const L = new LobbyState();
  const r = L.createRoom('h:1', { name: 'R', maxPlayers: 4 });
  L.joinRoom('g:1', r.handle);
  L.removeEndpoint('g:1');                             // guest disconnects
  eq(L.roomPlayerCount(r.handle), 1, 'guest disconnect -> room down to 1');
  L.removeEndpoint('h:1');                             // host disconnects
  eq(L.rooms.size, 0, 'host disconnect -> room dissolved');
}

// 10. Exiting the area leaves the room
{
  const L = new LobbyState();
  L.enterArea('a:1', 2);
  const r = L.createRoom('a:1', { name: 'R' });
  eq(L.rooms.size, 1, 'room created');
  L.exitArea('a:1');
  eq(L.rooms.size, 0, 'exiting area dissolved the host room');
  eq(L.playerByEndpoint('a:1').room, 0, 'player no longer in a room');
}

// 12. SEEDED server room — 2 clients JOIN the same real room (Track A: real 2-client via join) + persists empty
{
  const L = new LobbyState();
  const r = L.seedRoom({ name: 'PAL LOBBY', maxPlayers: 4 });
  eq(L.roomList().length, 1, 'seeded room shows in op49 list');
  eq(L.roomList()[0].current, 0, 'seeded room starts at 0 members');
  L.joinRoom('a:1', r.handle); L.joinRoom('b:1', r.handle);
  eq(L.roomPlayerCount(r.handle), 2, 'two clients JOIN the seeded room -> 2 members (co-located)');
  eq(L.roomList()[0].current, 2, 'op49 shows real 2/4 count');
  L.leaveRoom('a:1'); L.leaveRoom('b:1');
  eq(L.rooms.size, 1, 'seeded room PERSISTS when empty (server-owned, not dissolved)');
  eq(L.roomList()[0].current, 0, 'back to 0/4, still advertised');
}

console.log(`\nlobby_state.test: ${pass} passed, ${fail} failed`);
process.exit(fail ? 1 : 0);
