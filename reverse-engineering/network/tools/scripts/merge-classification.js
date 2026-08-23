'use strict';
// Merge a workflow classification result ({functions:[...]}) into functions.json + derived indexes.
// Usage: node merge-classification.js <results.json>
const fs = require('fs');
const path = require('path');
const ROOT = path.resolve(__dirname, '../..');
const IDX = path.join(ROOT, 'indexes');
const results = JSON.parse(fs.readFileSync(process.argv[2], 'utf8'));
const items = Array.isArray(results) ? results : (results.functions || []);
const fns = JSON.parse(fs.readFileSync(path.join(IDX, 'functions.json'), 'utf8'));
const byAddr = new Map(fns.map(f => [f.address.toLowerCase(), f]));

let updated = 0, unmatched = 0;
const subMoves = {};
for (const it of items) {
  const f = byAddr.get((it.addr || '').toLowerCase());
  if (!f) { unmatched++; continue; }
  // Never downgrade or overwrite a hand-written deep record (documented/validated) with triage output.
  if (f.status === 'documented' || f.status === 'validated') continue;
  f.resolved_name = it.resolved_name || f.resolved_name;
  f.subsystem = it.subsystem || f.subsystem;
  f.relevance = it.relevance || f.relevance;
  f.confidence = it.confidence || f.confidence;
  f.summary = it.summary || f.summary;
  if (it.callers) f.callers = it.callers;
  if (it.callees) f.callees = it.callees;
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

// Derived: globals + strings indexes (accumulate references)
const gidx = new Map(), sidx = new Map();
for (const f of fns) {
  for (const g of (f.globals || [])) {
    const key = (g.match(/0x[0-9a-fA-F]+/) || [g])[0];
    if (!gidx.has(key)) gidx.set(key, { address: key, tag: g, referenced_by: [] });
    gidx.get(key).referenced_by.push(f.address);
  }
  for (const s of (f.strings || [])) {
    if (!sidx.has(s)) sidx.set(s, { string: s, referenced_by: [] });
    sidx.get(s).referenced_by.push(f.address);
  }
}
fs.writeFileSync(path.join(IDX, 'globals.json'), JSON.stringify([...gidx.values()], null, 1));
fs.writeFileSync(path.join(IDX, 'strings.json'), JSON.stringify([...sidx.values()], null, 1));

console.log(`merged: updated=${updated} unmatched=${unmatched}`);
console.log('subsystems touched:', JSON.stringify(subMoves));
console.log('globals indexed:', gidx.size, '| strings indexed:', sidx.size);
