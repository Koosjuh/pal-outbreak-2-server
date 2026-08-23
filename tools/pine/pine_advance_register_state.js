#!/usr/bin/env node
// PINE-advance state+0x80 (register state byte) to 3.
//
// Why: register-OK handler FUN_001d98f8 checks `if (state+0x80 != 3) state+0x80 = 2`.
// Value 3 = "phase complete, advance lobby". Only writers in code:
//   - SLES 0x1d7490 (SN@P recv parser) — needs counter gate state+0x7c+500 < state+0x4fc
//   - ntgui 0x7d71d8 / 0x7d9ac8 (overlay X-press handler) — needs user input
//
// On PCSX2 black-lobby, X-press handler in ntgui doesn't fire (no input). The
// SN@P parser gate also doesn't trigger (counters don't satisfy). So state+0x80
// stays at 2 → game waits 56s → times out → error 840.
//
// This tool PINE-writes state+0x80 = 3 directly, simulating completed X-press.
// If correct, game proceeds past the 56s wait without timing out.
//
// Usage: node pine_advance_register_state.js [new_state]
//        default new_state = 3
'use strict';
const { PineClient } = require('./pine_client');

const STATE_BASE = 0x0036D760;
const newVal = parseInt(process.argv[2] || '3', 10);

(async () => {
  const c = new PineClient({ port: 28011, timeoutMs: 15000 });
  await c.connect();
  console.log('PINE connected\n');

  const beforeStateByte = await c.read32(STATE_BASE + 0x80);
  const before7c = await c.read32(STATE_BASE + 0x7c);
  const before4fc = await c.read32(STATE_BASE + 0x4fc);
  const beforeNtgui = await c.read8(0x007152E1);

  console.log('BEFORE:');
  console.log(`  state+0x80 (register state)  = 0x${beforeStateByte.toString(16)} (${beforeStateByte})`);
  console.log(`  state+0x7c (counter)         = ${before7c}`);
  console.log(`  state+0x4fc (counter target) = ${before4fc}`);
  console.log(`  delta (4fc - 7c - 500)       = ${before4fc - before7c - 500}  (must be > 0 for SN@P path)`);
  console.log(`  NTGUI state 0x7152E1         = 0x${beforeNtgui.toString(16)}`);

  console.log(`\nWriting state+0x80 = ${newVal}`);
  await c.write32(STATE_BASE + 0x80, newVal);

  const afterStateByte = await c.read32(STATE_BASE + 0x80);
  console.log(`\nAFTER:`);
  console.log(`  state+0x80 = 0x${afterStateByte.toString(16)}`);

  console.log(`\nWatch PCSX2 for ~10s. If game advances past Connecting,`);
  console.log(`state+0x80 = 3 was the missing gate.`);

  c.close();
})().catch(e => { console.error('FATAL:', e.message); process.exit(1); });
