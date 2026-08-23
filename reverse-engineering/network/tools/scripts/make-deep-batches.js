'use strict';
// Emit deep-reconstruction batches (net-related, not yet reconstructed), priority-ordered by subsystem.
// node make-deep-batches.js <batchSize> <subsystem[,subsystem...]|core|all> > batches.json
const fs = require('fs');
const path = require('path');
const ROOT = path.resolve(__dirname, '../..');
const fns = JSON.parse(fs.readFileSync(path.join(ROOT, 'indexes/functions.json'), 'utf8'));
const size = Number(process.argv[2] || 18);
const which = process.argv[3] || 'core';
const CORE = ['transport', 'packets', 'session', 'rooms', 'roster', 'lobby', 'chat'];
const set = which === 'all' ? null : (which === 'core' ? CORE : which.split(','));

const done = (f) => ['reconstructed','validated','documented'].includes(f.status);
const sel = fns.filter(f =>
  f.raw_path && f.subsystem !== 'unrelated' && !done(f) &&
  (!set || set.includes(f.subsystem))
).sort((a, b) => {
  // core relevance first, then by subsystem priority, then address
  if ((a.relevance === 'core') !== (b.relevance === 'core')) return a.relevance === 'core' ? -1 : 1;
  const pa = CORE.indexOf(a.subsystem), pb = CORE.indexOf(b.subsystem);
  if (pa !== pb) return (pa < 0 ? 99 : pa) - (pb < 0 ? 99 : pb);
  return a.address.localeCompare(b.address);
}).map(f => ({ addr: f.address, name: f.name, raw_path: f.raw_path, doc_path: f.doc_path, subsystem: f.subsystem }));

const batches = [];
for (let i = 0; i < sel.length; i += size) batches.push(sel.slice(i, i + size));
process.stdout.write(JSON.stringify(batches));
process.stderr.write(`${which}: ${sel.length} fns -> ${batches.length} batches of <=${size}\n`);
