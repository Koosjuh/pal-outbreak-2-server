#!/usr/bin/env node
// Test A: fake the SN@P subsystem allocation by writing a non-null pointer to
// *0x25B78C and a valid subsystem ID to uRam0035b9e0. Goal: bypass the NULL
// check in FUN_001DBA68 to see what code runs next.
'use strict';
const { PineClient } = require('./pine_client');

// Use 0x86F864 (the lobby data buffer) as the fake struct ptr.
// It has LOBBY01..16 bytes, well-aligned, in valid EE RAM.
const FAKE_STRUCT_PTR = 0x0086F864;

(async () => {
  const c = new PineClient({ port: 28011, timeoutMs: 15000 });
  await c.connect();
  console.log('PINE connected\n');

  // Read BEFORE
  const before_b78c = await c.read32(0x0025B78C);
  const before_b9e0 = await c.read32(0x0035B9E0);
  console.log(`BEFORE:`);
  console.log(`  *0x25B78C = 0x${before_b78c.toString(16).padStart(8,'0')}`);
  console.log(`  *0x35B9E0 (subsysID) = 0x${before_b9e0.toString(16).padStart(8,'0')}`);

  // Write the fake pointer and the subsystem ID
  console.log(`\nWriting:`);
  console.log(`  *0x25B78C = 0x${FAKE_STRUCT_PTR.toString(16)}  (fake struct ptr = lobby buffer)`);
  console.log(`  *0x35B9E0 = 1                                  (subsystem ID)`);
  await c.write32(0x0025B78C, FAKE_STRUCT_PTR);
  await c.write32(0x0035B9E0, 1);

  // Read AFTER (verify)
  const after_b78c = await c.read32(0x0025B78C);
  const after_b9e0 = await c.read32(0x0035B9E0);
  console.log(`\nAFTER:`);
  console.log(`  *0x25B78C = 0x${after_b78c.toString(16).padStart(8,'0')}`);
  console.log(`  *0x35B9E0 (subsysID) = 0x${after_b9e0.toString(16).padStart(8,'0')}`);

  console.log(`\nNow trigger a new connect cycle. Try:`);
  console.log(`  node tools\\pine_poke_state.js 0`);
  console.log(`  ... wait ~60s and observe PCSX2 + DEV9 log`);
  c.close();
})().catch(e => { console.error('FATAL:', e.message); process.exit(1); });
