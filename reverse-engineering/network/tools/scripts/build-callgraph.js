'use strict';
// Build the full caller/callee call graph → generated/callgraphs/edges.json + indexes/cross_references.json
// Sources: overlay full-dump CALLERS/CALLEES lines (Ghidra-authoritative) + transport .c body callee refs.
const fs = require('fs');
const path = require('path');
const ROOT = path.resolve(__dirname, '../..');
const REPO = path.resolve(ROOT, '../..');

const edges = new Set();        // "caller->callee"
const add = (from, to) => { if (from && to && from !== to) edges.add(`${from}->${to}`); };

// 1) Overlay: parse the full dump's per-function CALLERS/CALLEES blocks
const dump = fs.readFileSync(path.join(ROOT, 'sources/overlays/overlay-3dat-full-dump.txt'), 'utf8').split(/\r?\n/);
let cur = null;
for (const line of dump) {
  const fm = line.match(/^FUNCTION (FUN_[0-9a-f]+) @/);
  if (fm) { cur = fm[1]; continue; }
  if (!cur) continue;
  const cm = line.match(/^CALLERS \(\d+\):\s*(.*)$/);
  if (cm) for (const m of cm[1].matchAll(/(FUN_[0-9a-f]+|EXT_FUN_[0-9a-f]+)/g)) add(m[1].replace('EXT_', ''), cur);
  const em = line.match(/^CALLEES \(\d+\):\s*(.*)$/);
  if (em) for (const m of em[1].matchAll(/(FUN_[0-9a-f]+|EXT_FUN_[0-9a-f]+)/g)) add(cur, m[1].replace('EXT_', ''));
}

// 2) Transport: callees = FUN_ refs inside each .c body
const tdirs = [path.join(ROOT,'sources/executables/transport-decompile'), path.join(ROOT,'sources/executables/netstack-decompile')];
for (const tdir of tdirs) for (const file of fs.readdirSync(tdir)) {
  const self = file.replace('.c', '');
  const body = fs.readFileSync(path.join(tdir, file), 'utf8');
  for (const m of body.matchAll(/\b(FUN_[0-9a-f]{6,})\b/g)) if (m[1] !== self) add(self, m[1]);
}

// Emit edges + adjacency (callers/callees per node) → cross_references.json
const callees = {}, callers = {};
for (const e of edges) {
  const [a, b] = e.split('->');
  (callees[a] = callees[a] || new Set()).add(b);
  (callers[b] = callers[b] || new Set()).add(a);
}
const nodes = {};
for (const n of new Set([...Object.keys(callees), ...Object.keys(callers)]))
  nodes[n] = { callers: [...(callers[n] || [])].sort(), callees: [...(callees[n] || [])].sort() };

fs.mkdirSync(path.join(ROOT, 'generated/callgraphs'), { recursive: true });
fs.writeFileSync(path.join(ROOT, 'generated/callgraphs/edges.json'), JSON.stringify([...edges].sort(), null, 0));
fs.writeFileSync(path.join(ROOT, 'indexes/cross_references.json'), JSON.stringify(nodes, null, 1));

// Fold callers/callees into functions.json so search --caller/--callee works corpus-wide
const IDX = path.join(ROOT, 'indexes');
const fns = JSON.parse(fs.readFileSync(path.join(IDX, 'functions.json'), 'utf8'));
for (const f of fns) {
  const n = nodes[f.name];
  if (n) { f.callers = n.callers; f.callees = n.callees; }
}
fs.writeFileSync(path.join(IDX, 'functions.json'), JSON.stringify(fns, null, 1));

console.log(`callgraph: ${edges.size} edges, ${Object.keys(nodes).length} nodes`);
