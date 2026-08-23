#!/usr/bin/env node
// Force the NTGUI state byte (0x7152E1) to a new value to bypass stuck animations.
// Usage: node pine_poke_state.js <new_state> [iters]
//   <new_state>  — value 0-255 to write
//   [iters]      — optional, default 1. Number of repeats with 200ms delay
'use strict';
const { PineClient } = require('./pine_client');

const newState = parseInt(process.argv[2] || '3', 0);
const iters    = parseInt(process.argv[3] || '1', 10);

(async () => {
  const c = new PineClient({ port: 28011, timeoutMs: 15000 });
  await c.connect();
  console.log(`PINE connected. Will write state = 0x${newState.toString(16)} (${newState}) ${iters}x`);

  const before = await c.read32(0x007152E0);
  console.log(`BEFORE 0x7152E0..E3 = 0x${before.toString(16).padStart(8,'0')}  (state byte = 0x${(before >>> 8 & 0xff).toString(16)})`);

  for (let i = 0; i < iters; i++) {
    await c.write8(0x007152E1, newState & 0xff);
    if (iters > 1) {
      const cur = await c.read32(0x007152E0);
      console.log(`  iter ${i+1}: state = 0x${(cur >>> 8 & 0xff).toString(16)}`);
      await new Promise(r => setTimeout(r, 200));
    }
  }

  const after = await c.read32(0x007152E0);
  console.log(`AFTER  0x7152E0..E3 = 0x${after.toString(16).padStart(8,'0')}  (state byte = 0x${(after >>> 8 & 0xff).toString(16)})`);
  c.close();
})().catch(e => { console.error('FATAL:', e.message); process.exit(1); });
