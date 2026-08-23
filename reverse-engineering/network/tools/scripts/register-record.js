'use strict';
// Register a hand-written function record in functions.json.
// Usage: node register-record.js <addr> <subsystem> <status> <confidence> <resolved_name> <doc_path>
const fs = require('fs');
const path = require('path');
const IDX = path.resolve(__dirname, '../../indexes');
const [addr, subsystem, status, confidence, resolved, doc] = process.argv.slice(2);
const fns = JSON.parse(fs.readFileSync(path.join(IDX, 'functions.json'), 'utf8'));
const f = fns.find(x => x.address.toLowerCase() === addr.toLowerCase());
if (!f) { console.error('not found:', addr); process.exit(1); }
Object.assign(f, { subsystem, status, confidence, resolved_name: resolved, doc_path: doc });
fs.writeFileSync(path.join(IDX, 'functions.json'), JSON.stringify(fns, null, 1));
console.log(`registered ${addr} -> ${subsystem}/${status}/${confidence} ${resolved}`);
