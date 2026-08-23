'use strict';
// Merge classification results directly from workflow journal.jsonl files into functions.json + indexes.
// Usage: node merge-journals.js <journal1.jsonl> [journal2.jsonl ...]
const fs = require('fs');
const path = require('path');
const ROOT = path.resolve(__dirname, '../..');
const IDX = path.join(ROOT, 'indexes');
const fns = JSON.parse(fs.readFileSync(path.join(IDX, 'functions.json'), 'utf8'));
const byAddr = new Map(fns.map(f => [f.address.toLowerCase(), f]));

let items = [];
for (const jf of process.argv.slice(2)) {
  for (const line of fs.readFileSync(jf, 'utf8').split(/\r?\n/)) {
    if (!line.trim()) continue;
    let o; try { o = JSON.parse(line); } catch { continue; }
    if (o.type !== 'result') continue;
    const r = o.result || o.value || o.output;
    const arr = r && r.functions ? r.functions : (Array.isArray(r) ? r : []);
    items = items.concat(arr);
  }
}

let updated = 0, unmatched = 0, skipped = 0;
const subMoves = {};
for (const it of items) {
  const f = byAddr.get((it.addr || '').toLowerCase());
  if (!f) { unmatched++; continue; }
  if (f.status === 'documented' || f.status === 'validated') { skipped++; continue; }
  if (it.resolved_name) f.resolved_name = it.resolved_name;
  if (it.subsystem) f.subsystem = it.subsystem;
  if (it.relevance) f.relevance = it.relevance;
  if (it.confidence) f.confidence = it.confidence;
  if (it.summary) f.summary = it.summary;
  if (it.callers && it.callers.length) f.callers = it.callers;
  if (it.callees && it.callees.length) f.callees = it.callees;
  if (it.globals) f.globals = it.globals;
  if (it.strings) f.strings = it.strings;
  if (it.opcodes && it.opcodes.length) f.opcodes = it.opcodes;
  if (it.state_vars) f.state_vars = it.state_vars;
  if (it.notes) f.notes = it.notes;
  if (f.status === 'inventoried') f.status = 'classified';
  subMoves[f.subsystem] = (subMoves[f.subsystem] || 0) + 1;
  updated++;
}
fs.writeFileSync(path.join(IDX, 'functions.json'), JSON.stringify(fns, null, 1));

// Rebuild globals + strings indexes from all classified functions
const gidx = new Map(), sidx = new Map(), opidx = new Map();
for (const f of fns) {
  for (const g of (f.globals || [])) {
    const key = (g.match(/0x[0-9a-fA-F]+/) || [g])[0];
    if (!gidx.has(key)) gidx.set(key, { address: key, tags: new Set(), referenced_by: [] });
    gidx.get(key).tags.add(g); gidx.get(key).referenced_by.push(f.address);
  }
  for (const s of (f.strings || [])) {
    if (!sidx.has(s)) sidx.set(s, { string: s, referenced_by: [] });
    sidx.get(s).referenced_by.push(f.address);
  }
  for (const op of (f.opcodes || [])) {
    if (!opidx.has(op)) opidx.set(op, { opcode: op, functions: [] });
    opidx.get(op).functions.push({ addr: f.address, name: f.resolved_name || f.name, subsystem: f.subsystem });
  }
}
const gArr = [...gidx.values()].map(g => ({ address: g.address, tags: [...g.tags], referenced_by: g.referenced_by }));
fs.writeFileSync(path.join(IDX, 'globals.json'), JSON.stringify(gArr, null, 1));
fs.writeFileSync(path.join(IDX, 'strings.json'), JSON.stringify([...sidx.values()], null, 1));
fs.writeFileSync(path.join(IDX, 'opcodes_seen.json'), JSON.stringify([...opidx.values()], null, 1));

console.log(`merged: updated=${updated} skipped(doc)=${skipped} unmatched=${unmatched} of ${items.length} items`);
console.log(`globals=${gidx.size} strings=${sidx.size} opcodes=${opidx.size}`);
console.log('subsystems:', JSON.stringify(subMoves));
