#!/usr/bin/env node
// Read *0x25B78C (SN@P state struct ptr) — if NULL, FUN_001DBA68 returns error 100.
'use strict';
const { PineClient } = require('./pine_client');

(async () => {
  const c = new PineClient({ port: 28011, timeoutMs: 15000 });
  await c.connect();
  console.log('PINE connected');

  const subsysId = await c.read32(0x35B9E0);
  console.log(`uRam0035b9e0 (subsystem ID) = 0x${subsysId.toString(16).padStart(8,'0')}  (1 = valid, -1 = uninitialized)`);

  const tbl = await c.readBytes(0x25B788, 16);
  console.log(`\nSubsystem ptr table @ 0x25B788 (16 bytes):`);
  console.log(`  hex: ${Array.from(tbl).map(b=>b.toString(16).padStart(2,'0')).join(' ')}`);
  const slot0 = tbl.readUInt32LE(0);
  const slot1 = tbl.readUInt32LE(4);
  const slot2 = tbl.readUInt32LE(8);
  const slot3 = tbl.readUInt32LE(12);
  console.log(`  *0x25B788 (slot 0) = 0x${slot0.toString(16).padStart(8,'0')}`);
  console.log(`  *0x25B78C (slot 1) = 0x${slot1.toString(16).padStart(8,'0')}  ★ (the subsystem ptr FUN_001DBA68 checks)`);
  console.log(`  *0x25B790 (slot 2) = 0x${slot2.toString(16).padStart(8,'0')}`);
  console.log(`  *0x25B794 (slot 3) = 0x${slot3.toString(16).padStart(8,'0')}`);

  if (slot1 >= 0x100000 && slot1 < 0x2000000) {
    console.log(`\n★ slot1 is a valid pointer! Dumping first 128 bytes:`);
    const buf = await c.readBytes(slot1, 128);
    for (let i = 0; i < buf.length; i += 16) {
      const slice = buf.slice(i, i + 16);
      const hex = Array.from(slice).map(b => b.toString(16).padStart(2,'0')).join(' ');
      const ascii = slice.toString('latin1').replace(/[^\x20-\x7e]/g, '.');
      const addr = (slot1 + i).toString(16).padStart(8, '0');
      console.log(`  ${addr}  ${hex}  ${ascii}`);
    }
  } else {
    console.log(`\n★ slot1 is NOT a valid EE pointer — FUN_001DBA68 would return error 100 here`);
  }

  c.close();
})().catch(e => { console.error('FATAL:', e.message); process.exit(1); });
