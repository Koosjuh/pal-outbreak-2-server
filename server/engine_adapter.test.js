'use strict';
// Unit tests for engine_adapter.js (CONSOLIDATION C0) — run: node server/engine_adapter.test.js
// Pure, injectable — no UDP socket. Asserts the adapter resolves recipients, rides the builders,
// logs needs-vehicle, and never throws into the caller.
const { createAdapter } = require('./engine_adapter');

let pass = 0, fail = 0;
function eq(a, b, msg) { if (a === b) pass++; else { fail++; console.error(`  FAIL: ${msg} (got ${JSON.stringify(a)}, want ${JSON.stringify(b)})`); } }

// A player fixture with N sessions.
function player(idKey, nSessions = 1) {
  return { idKey, _sessions: Array.from({ length: nSessions }, (_, i) => ({ key: `${idKey}#${i}`, sent: [] })) };
}

function harness(builders) {
  const logs = [];
  const sends = [];
  const adapter = createAdapter({
    resolveSessions: (p) => p._sessions || [],
    builders,
    send: (session, packet) => { session.sent.push(packet); sends.push({ session: session.key, packet }); },
    log: (l) => logs.push(l),
  });
  return { adapter, logs, sends };
}

// 1. A mapped kind builds + sends to each of the recipient's sessions.
{
  const B = { MEMBER_JOIN: (s, a) => Buffer.from(`join:${a.name}`) };
  const { adapter, sends } = harness(B);
  const A = player('uid:A', 2);   // two endpoints
  const s = adapter.execute([{ to: A, kind: 'MEMBER_JOIN', args: { name: 'KOOS' } }], 't1');
  eq(s.sent, 2, 'sent to both of A\'s sessions');
  eq(sends[0].packet.toString(), 'join:KOOS', 'builder output delivered');
  eq(sends[1].session, 'uid:A#1', 'second endpoint reached');
}

// 2. needs-vehicle / unmapped kind is logged and dropped, never sent.
{
  const { adapter, logs, sends } = harness({});
  const A = player('uid:A');
  const s = adapter.execute([{ to: A, kind: 'needs-vehicle:chat-out', args: {} }], 't2');
  eq(s.sent, 0, 'nothing sent for needs-vehicle');
  eq(s.needsVehicle, 1, 'needs-vehicle counted');
  eq(sends.length, 0, 'no send call');
  eq(logs.some(l => l.includes('NEEDS-VEHICLE') && l.includes('chat-out')), true, 'needs-vehicle logged');
}

// 3. Recipient with no live session is skipped gracefully (counted, logged, not sent).
{
  const B = { COUNT: () => Buffer.from('c') };
  const { adapter, sends } = harness(B);
  const ghost = { idKey: 'uid:GONE', _sessions: [] };
  const s = adapter.execute([{ to: ghost, kind: 'COUNT', args: {} }], 't3');
  eq(s.sent, 0, 'no send to a sessionless player');
  eq(s.skippedNoSession, 1, 'no-session counted');
  eq(sends.length, 0, 'nothing delivered');
}

// 4. A builder returning null sends nothing (empty-room case), no crash.
{
  const B = { LIST: () => null };
  const { adapter, sends } = harness(B);
  const A = player('uid:A');
  const s = adapter.execute([{ to: A, kind: 'LIST', args: {} }], 't4');
  eq(s.sent, 0, 'null builder -> nothing sent');
  eq(sends.length, 0, 'no delivery');
}

// 5. A throwing builder is contained — logged, other emissions still run.
{
  const B = { BAD: () => { throw new Error('boom'); }, GOOD: () => Buffer.from('g') };
  const { adapter, logs, sends } = harness(B);
  const A = player('uid:A');
  const s = adapter.execute([
    { to: A, kind: 'BAD', args: {} },
    { to: A, kind: 'GOOD', args: {} },
  ], 't5');
  eq(s.sent, 1, 'the good emission still sent after the bad one threw');
  eq(sends[0].packet.toString(), 'g', 'good packet delivered');
  eq(logs.some(l => l.includes('builder threw') && l.includes('boom')), true, 'builder throw logged');
}

// 6. A send that throws is contained (transport hiccup) — counted as not sent, no propagation.
{
  const B = { X: () => Buffer.from('x') };
  const logs = [];
  const adapter = createAdapter({
    resolveSessions: (p) => p._sessions,
    builders: B,
    send: () => { throw new Error('socket'); },
    log: (l) => logs.push(l),
  });
  const A = player('uid:A');
  let threw = false;
  let s;
  try { s = adapter.execute([{ to: A, kind: 'X', args: {} }], 't6'); } catch { threw = true; }
  eq(threw, false, 'execute did not throw when send failed');
  eq(s.sent, 0, 'failed send not counted as sent');
  eq(logs.some(l => l.includes('send failed')), true, 'send failure logged');
}

// 7. Empty / malformed plans are no-ops.
{
  const { adapter } = harness({ K: () => Buffer.from('k') });
  eq(adapter.execute([], 't7').sent, 0, 'empty plan -> 0 sent');
  eq(adapter.execute(null, 't7b').sent, 0, 'null plan -> 0 sent');
  eq(adapter.execute([{ to: null, kind: 'K' }, { kind: 'K' }, { to: {} }], 't7c').sent, 0, 'malformed emissions skipped');
}

// 8. Multi-recipient broadcast: one plan, several players, mixed kinds.
{
  const B = { JOIN: (s, a) => Buffer.from(`j:${a.id}`), COUNT: () => Buffer.from('n') };
  const { adapter, sends } = harness(B);
  const A = player('uid:A'), C = player('uid:C');
  const s = adapter.execute([
    { to: A, kind: 'JOIN', args: { id: 2 } },
    { to: C, kind: 'JOIN', args: { id: 2 } },
    { to: A, kind: 'COUNT', args: {} },
    { to: C, kind: 'COUNT', args: {} },
  ], 't8');
  eq(s.sent, 4, 'all four emissions delivered');
  eq(sends.filter(x => x.session === 'uid:A#0').length, 2, 'A got join+count');
  eq(sends.filter(x => x.session === 'uid:C#0').length, 2, 'C got join+count');
}

console.log(`\nengine_adapter tests: ${pass} pass, ${fail} fail`);
process.exit(fail ? 1 : 0);
