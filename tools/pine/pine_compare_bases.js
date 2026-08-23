#!/usr/bin/env node
// Compare the two base pointers (read base vs write base) and dump active flags.
'use strict';
const { PineClient } = require('./pine_client');

(async () => {
  const c = new PineClient({ port: 28011, timeoutMs: 15000 });
  await c.connect();
  console.log('PINE connected\n');

  const readBase  = await c.read32(0x0070d1c0);
  const writeBase = await c.read32(0x00715da8);
  console.log(`READ  base (*0x70d1c0) = 0x${readBase.toString(16)}`);
  console.log(`WRITE base (*0x715da8) = 0x${writeBase.toString(16)}`);
  console.log(`Same pointer? ${readBase === writeBase ? 'YES' : 'NO'}\n`);

  for (const [label, base] of [['READ', readBase], ['WRITE', writeBase]]) {
    if (base < 0x80000 || base >= 0x2000000) {
      console.log(`${label} base 0x${base.toString(16)} out of EE range - skipping\n`);
      continue;
    }
    console.log(`=== ${label} base 0x${base.toString(16)} — first 8 entries (20b each) at +0x258 ===`);
    for (let i = 0; i < 8; i++) {
      const addr = base + 0x258 + i * 20;
      const buf = await c.readBytes(addr, 20);
      const active = buf.readUInt32LE(0);
      const ptr    = buf.readUInt32LE(16);
      const hex    = Array.from(buf).map(b => b.toString(16).padStart(2,'0')).join(' ');
      const mark   = active === 1 ? ' ★ACTIVE' : '';
      console.log(`  entry[${i}] @ 0x${addr.toString(16)}  active=0x${active.toString(16).padStart(8,'0')} ptr=0x${ptr.toString(16).padStart(8,'0')}${mark}`);
      console.log(`    ${hex}`);
    }
    console.log();
  }

  c.close();
})().catch(e => { console.error('FATAL:', e.message); process.exit(1); });
