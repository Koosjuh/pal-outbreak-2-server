#!/usr/bin/env node
// Dump both press-X hostname slots (+0x300 and +0x700) for the first 4 records.
'use strict';
const { PineClient } = require('./pine_client');

(async () => {
  const c = new PineClient({ port: 28011, timeoutMs: 15000 });
  await c.connect();
  console.log('PINE connected');

  const basePtr = await c.read32(0x0070d1c0);
  console.log(`record base = 0x${basePtr.toString(16)}\n`);

  const OFFSETS = [0x000, 0x300, 0x700];   // record start, +0x300, +0x700
  for (let recIdx = 0; recIdx < 4; recIdx++) {
    const recBase = basePtr + recIdx * 0x1340;
    console.log(`=== Record ${recIdx} @ 0x${recBase.toString(16)} ===`);
    for (const off of OFFSETS) {
      const addr = recBase + off;
      const buf = await c.readBytes(addr, 48);
      const hex = Array.from(buf).map(b => b.toString(16).padStart(2,'0')).join(' ');
      const ascii = buf.toString('latin1').replace(/[^\x20-\x7e]/g, '.');
      console.log(`  +0x${off.toString(16).padStart(3,'0')} @ 0x${addr.toString(16)}`);
      console.log(`    hex: ${hex}`);
      console.log(`    asc: ${ascii}`);
    }
  }

  // Also the 20-byte entry list at base+0x258
  console.log(`\n=== 20-byte entry list at base+0x258 (first 4 entries) ===`);
  for (let i = 0; i < 4; i++) {
    const addr = basePtr + 0x258 + i * 20;
    const buf = await c.readBytes(addr, 20);
    const hex = Array.from(buf).map(b => b.toString(16).padStart(2,'0')).join(' ');
    const active_flag = buf.readUInt32LE(0);
    const ptr_field   = buf.readUInt32LE(16);
    console.log(`  entry[${i}] @ 0x${addr.toString(16)}  active=0x${active_flag.toString(16)}  ptr=0x${ptr_field.toString(16)}`);
    console.log(`    ${hex}`);
  }

  c.close();
})().catch(e => { console.error('FATAL:', e.message); process.exit(1); });
