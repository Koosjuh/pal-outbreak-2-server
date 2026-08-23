'use strict';
// Automated coverage for the RF-15 engine-join fixes (Codex #8). Run: node server/join-pipeline.test.cjs
// Asserts: op06 recipient set + order, joiner self-push, idempotent re-join (no dup op0a/count), and
// name resolution via displayName (real handle, no synthetic). State model only (no wire/transport).
const assert = require('assert');
const LS = require('./lobby_state');
const { LobbyState } = LS;
const SLOT = LS.SLOT;
const { createEngine } = require('./lobby_engine');

let pass = 0;
const ok = (c, m) => { assert.ok(c, m); console.log('  ✓ ' + m); pass++; };
const eq = (a, b, m) => { assert.strictEqual(a, b, `${m} (got ${a}, want ${b})`); console.log('  ✓ ' + m); pass++; };

function fresh() {
  const L = new LobbyState(); const E = createEngine(L);
  L.bindEndpoint({ transportKey: 'A:1', userid: '12345', handle: '12345' });
  L.bindEndpoint({ transportKey: 'B:1', userid: 'realguy', handle: 'realguy' });
  const room = L.createRoom('A:1', { name: 'ROOM', maxPlayers: 4 });
  E.goLive('A:1');                       // INCREATE -> GAMESET so join is accepted
  return { L, E, room };
}
const kinds = (plan, E) => plan.map(e => e.kind === E.K.MEMBER_JOIN ? 'op06' : e.kind === E.K.MEMBER_LIST ? 'op0a' : e.kind === E.K.COUNT_0X11 ? 'count' : e.kind === E.K.ROOMLIST_DIRTY ? 'dirty' : e.kind);

// --- A: new join — op06 recipients, order, self-push, names ---
{
  const { L, E, room } = fresh();
  const r = E.joinRoom('B:1', room.handle);
  ok(r.ok && !r.alreadyMember, 'A: join accepted, not already-member');
  const mj = r.plan.filter(e => e.kind === E.K.MEMBER_JOIN);
  eq(mj.length, 3, 'A: 3 op06 deltas (existing<-joiner x1, joiner<-both x2)');
  ok(mj.some(e => e.to.idKey === 'uid:12345' && e.args.name === 'realguy'), 'A: host receives op06 for the joiner (realguy)');
  ok(mj.some(e => e.to.idKey === 'uid:realguy' && e.args.name === '12345'), 'A: joiner receives op06 for the host (12345)');
  ok(mj.some(e => e.to.idKey === 'uid:realguy' && e.args.name === 'realguy'), 'A: joiner receives op06 for ITSELF (self-push)');
  ok(mj.every(e => e.args.name === '12345' || e.args.name === 'realguy'), 'A: all names are REAL handles (no CREATOR/synthetic)');
  // order: all op06 before any op0a; all op0a before count
  const k = kinds(r.plan, E);
  const lastOp06 = k.lastIndexOf('op06'), firstOp0a = k.indexOf('op0a'), firstCount = k.indexOf('count'), lastOp0a = k.lastIndexOf('op0a');
  ok(lastOp06 < firstOp0a, 'A: order — every op06 precedes op0a');
  ok(lastOp0a < firstCount, 'A: order — every op0a precedes count');
}

// --- B: idempotent re-join — NO op06 delta, NO op0a/count re-emit (Codex #5) ---
{
  const { L, E, room } = fresh();
  E.joinRoom('B:1', room.handle);                 // first join
  const r2 = E.joinRoom('B:1', room.handle);      // re-join
  ok(r2.ok && r2.alreadyMember, 'B: re-join ok + already-member');
  eq(r2.plan.length, 0, 'B: re-join emits an EMPTY plan (no op06, no op0a, no count)');
  eq(L.roomPlayerCount(room.handle), 2, 'B: no duplicate member (count stays 2)');
}

// --- C: join is rejected before go-live (reference guard, unchanged) ---
{
  const L = new LobbyState(); const E = createEngine(L);
  L.bindEndpoint({ transportKey: 'A:1', userid: 'H', handle: 'H' });
  L.bindEndpoint({ transportKey: 'B:1', userid: 'J', handle: 'J' });
  const room = L.createRoom('A:1', {});           // INCREATE, no go-live
  const r = E.joinRoom('B:1', room.handle);
  ok(!r.ok && r.reason === 'in-create', 'C: join rejected in-create before go-live (guard intact)');
}

console.log(`\njoin-pipeline: ${pass} assertions passed`);
