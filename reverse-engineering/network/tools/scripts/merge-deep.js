'use strict';
// Merge deep-reconstruction results from a workflow journal: set status=reconstructed for written records.
// Usage: node merge-deep.js <journal.jsonl>
const fs = require('fs');
const path = require('path');
const IDX = path.resolve(__dirname, '../../indexes');
const fns = JSON.parse(fs.readFileSync(path.join(IDX, 'functions.json'), 'utf8'));
const byAddr = new Map(fns.map(f => [f.address.toLowerCase(), f]));
let items = [];
for (const line of fs.readFileSync(process.argv[2], 'utf8').split(/\r?\n/)) {
  if (!line.trim()) continue;
  let o; try { o = JSON.parse(line); } catch { continue; }
  if (o.type !== 'result') continue;
  const r = o.result || o.value; const arr = r && r.functions ? r.functions : [];
  items = items.concat(arr);
}
let recon = 0, unmatched = 0;
for (const it of items) {
  const f = byAddr.get((it.addr || '').toLowerCase());
  if (!f) { unmatched++; continue; }
  if (it.resolved_name) f.resolved_name = it.resolved_name;
  if (it.confidence) f.confidence = it.confidence;
  if (it.notes) f.notes = it.notes;
  // Terminal states: 'reconstructed' (corrected pseudocode) or 'documented' (opaque/halt_baddata — body
  // undecodable from the decompiler; record preserves low-level facts + flags the need for raw disasm).
  if (it.status === 'reconstructed' && !['reconstructed', 'validated'].includes(f.status)) { f.status = 'reconstructed'; recon++; }
  else if (it.status === 'documented' && f.status === 'classified') { f.status = 'documented'; f.undecodable = true; recon++; }
}
fs.writeFileSync(path.join(IDX, 'functions.json'), JSON.stringify(fns, null, 1));
console.log(`deep-merge: reconstructed=${recon} unmatched=${unmatched} of ${items.length}`);
