#!/usr/bin/env node
// Test A: simulate "user pressed X on SLOT0001" by setting up the state the
// confirm path leaves behind, so the press-X handler enters its next state.
//
// What we KNOW from the RE:
//   - State-11 confirm copies 0x7152B0 -> 0x86F810 (slot name)
//   - State byte at 0x7152E1 advances 11 -> 1 -> 2 -> ... after confirm
//   - rt_state_machine_626900 at 0x626900 eventually fires func_0x001d46ec
//   - The downstream call uses *0x35BA98 (IP string) and *0x35B9E8 (port)
//
// We pre-populate the state and slot buffers, then advance the state byte so
// the dispatcher proceeds without needing the (unrenderable on PCSX2) UI.
//
// Usage: node pine_simulate_pressx.js [slot_name] [new_state]
//   slot_name  default "SLOT0001" — written to both 0x7152B0 and 0x86F810
//   new_state  default 1 — state byte to set (post-confirm initial)

'use strict';
const { PineClient } = require('./pine_client');

const slotName  = process.argv[2] || 'SLOT0001';
const newState  = parseInt(process.argv[3] || '1', 10);

(async () => {
  const c = new PineClient({ port: 28011, timeoutMs: 15000 });
  await c.connect();
  console.log('PINE connected\n');

  // === A. Read BEFORE state ===
  const before = {
    state:   await c.read8(0x007152E1),
    subsys:  await c.read32(0x0035B9E0),
    p25b78c: await c.read32(0x0025B78C),
    ip0:     await c.read32(0x0035BA98),
    port:    await c.read32(0x0035B9E8),
    f810_b0: await c.readBytes(0x0086F810, 16),
    sc7152b0: await c.readBytes(0x007152B0, 16),
  };
  console.log('BEFORE:');
  console.log(`  state byte 0x7152E1      = 0x${before.state.toString(16).padStart(2,'0')}`);
  console.log(`  *0x25B78C (subsys ptr)   = 0x${before.p25b78c.toString(16).padStart(8,'0')}`);
  console.log(`  *0x35B9E0 (subsys ID)    = 0x${before.subsys.toString(16).padStart(8,'0')}`);
  console.log(`  *0x35BA98 (IP first u32) = 0x${before.ip0.toString(16).padStart(8,'0')}`);
  console.log(`  *0x35B9E8 (port u16)     = ${before.port & 0xffff}`);
  console.log(`  0x86F810 (slot copy)     = "${before.f810_b0.toString('latin1').replace(/\0.*/,'')}"`);
  console.log(`  0x7152B0 (input scratch) = "${before.sc7152b0.toString('latin1').replace(/\0.*/,'')}"`);

  // === B. Simulate the confirm path's strcpy result ===
  console.log(`\nWriting:`);
  const slotBuf = Buffer.alloc(16, 0);
  slotBuf.write(slotName, 0, 'ascii');
  await c.writeBytes(0x007152B0, slotBuf);
  await c.writeBytes(0x0086F810, slotBuf);
  console.log(`  0x7152B0  <- "${slotName}\\0..."`);
  console.log(`  0x86F810  <- "${slotName}\\0..."`);

  // === C. Advance the state byte ===
  await c.write8(0x007152E1, newState & 0xff);
  console.log(`  0x7152E1  <- 0x${newState.toString(16)}`);

  // === D. Verify ===
  const after = {
    state:    await c.read8(0x007152E1),
    f810_b0:  await c.readBytes(0x0086F810, 16),
    sc7152b0: await c.readBytes(0x007152B0, 16),
  };
  console.log(`\nAFTER:`);
  console.log(`  state byte 0x7152E1      = 0x${after.state.toString(16).padStart(2,'0')}`);
  console.log(`  0x86F810                 = "${after.f810_b0.toString('latin1').replace(/\0.*/,'')}"`);
  console.log(`  0x7152B0                 = "${after.sc7152b0.toString('latin1').replace(/\0.*/,'')}"`);

  console.log(`\nNow watch PCSX2. Wait ~10s, then re-run pine_check_25b78c.js to see if`);
  console.log(`*0x25B78C got allocated (state machine fired the allocator naturally).`);

  c.close();
})().catch(e => { console.error('FATAL:', e.message); process.exit(1); });
