'use strict';
// Emit classification batches for a module: node make-batches.js <module> <batchSize> > batches.json
const fs = require('fs');
const path = require('path');
const ROOT = path.resolve(__dirname, '../..');
const fns = JSON.parse(fs.readFileSync(path.join(ROOT, 'indexes/functions.json'), 'utf8'));
const mod = process.argv[2];           // 'main-ee' | 'overlay-3dat'
const size = Number(process.argv[3] || 50);
const sel = fns.filter(f => f.module === mod && f.raw_path && f.status === 'inventoried')
               .map(f => ({ addr: f.address, name: f.name, raw_path: f.raw_path }));
const batches = [];
for (let i = 0; i < sel.length; i += size) batches.push(sel.slice(i, i + size));
process.stdout.write(JSON.stringify(batches));
process.stderr.write(`${mod}: ${sel.length} fns -> ${batches.length} batches of <=${size}\n`);
