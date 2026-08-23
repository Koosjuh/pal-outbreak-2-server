#!/usr/bin/env node
// Dump one full 608-byte lobby-entry record from EE RAM via PINE.
//
// Table base: 0x00365F78  (FUN_001c7cf0 / FUN_001c8790 read it)
// Stride:     0x260       (= 608 bytes per entry)
// Bound:      64 entries  (game iterates up to 64 in the parser)
//
// Per-entry fields we already know are READ by the connect path:
//   entry+0x000 (u16)  parser flag/status
//   entry+0x12c (u16)  written from u16=0 in our 0x6510 reply
//   entry+0x178 (u16)  bound-math input
//   entry+0x300        zeroed during init  (per netwk 0x6151b0 path)
//   entry+0x400 (str)  passed to FUN_001c0690 → stored to *0x35BA98 (dest IP)
//   entry+0x500 (str)  passed to FUN_001c0690 → stored to *0x35BA90 (alt IP)
//
// Usage:
//   node pine_dump_lobby_entry.js                 # entry 0, default label
//   node pine_dump_lobby_entry.js <idx> [label]   # entry N (0..63)
//
// Each call appends to:
//   captures/lobby_entries/lobby_entry_dump.log
// so you can run it at 3 different moments (post-6504, post-6510, pre-press-X)
// and diff them.
'use strict';
const fs = require('fs');
const path = require('path');
const { PineClient } = require('./pine_client');

const TABLE_BASE = 0x00365F78;
const ENTRY_STRIDE = 0x260;
const ENTRY_SIZE = 0x260;

const idx = parseInt(process.argv[2] || '0', 10);
const label = process.argv[3] || `entry${idx}-${new Date().toISOString().replace(/[:.]/g, '_')}`;

const outDir = path.join(__dirname, '..', 'captures', 'lobby_entries');
if (!fs.existsSync(outDir)) fs.mkdirSync(outDir, { recursive: true });
const outFile = path.join(outDir, 'lobby_entry_dump.log');

function hexDump(buf, baseAddr) {
  const lines = [];
  for (let i = 0; i < buf.length; i += 16) {
    const slice = buf.slice(i, i + 16);
    const hex = Array.from(slice).map(b => b.toString(16).padStart(2,'0')).join(' ').padEnd(47);
    const ascii = slice.toString('latin1').replace(/[^\x20-\x7e]/g, '.');
    lines.push(`  0x${(baseAddr + i).toString(16).padStart(8,'0')}  ${hex}  ${ascii}`);
  }
  return lines;
}

(async () => {
  const c = new PineClient({ port: 28011, timeoutMs: 20000 });
  await c.connect();
  console.log('PINE connected');

  const entryAddr = TABLE_BASE + idx * ENTRY_STRIDE;
  console.log(`Reading entry ${idx} at 0x${entryAddr.toString(16)} (${ENTRY_SIZE} bytes)...`);
  const buf = await c.readBytes(entryAddr, ENTRY_SIZE);
  c.close();

  const stamp = new Date().toISOString();
  const lines = [
    '',
    '=========================================================================',
    `LABEL: ${label}`,
    `TIME:  ${stamp}`,
    `ENTRY: ${idx}  ADDR: 0x${entryAddr.toString(16)}  SIZE: ${ENTRY_SIZE} bytes`,
    '=========================================================================',
    ...hexDump(buf, entryAddr),
  ];
  fs.appendFileSync(outFile, lines.join('\n') + '\n');
  console.log(`Wrote ${lines.length} lines to ${outFile}`);
  // Console preview (first 64 + key fields)
  console.log('\n--- preview ---');
  for (const l of hexDump(buf.slice(0, 64), entryAddr)) console.log(l);
  console.log('  ... (skipping middle) ...');
  // Show fields at known interesting offsets
  for (const off of [0x12c, 0x178, 0x300, 0x400, 0x500]) {
    const slice = buf.slice(off, off + 32);
    console.log(`  entry+0x${off.toString(16).padStart(3,'0')}: ${Array.from(slice).map(b => b.toString(16).padStart(2,'0')).join(' ')}`);
    const ascii = slice.toString('latin1').replace(/[^\x20-\x7e]/g, '.');
    console.log(`             ASCII: "${ascii}"`);
  }
})().catch(e => { console.error('FATAL:', e.message); process.exit(1); });
