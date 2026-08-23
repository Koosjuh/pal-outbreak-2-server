#!/usr/bin/env node
// One-shot dump of the metadata block + state machine vars + list pointers.
// Run when PCSX2 is on the failure screen (840 error or server-select).
'use strict';
const fs = require('fs');
const { PineClient } = require('./pine_client');

async function retry(label, fn, n = 3) {
  for (let i = 0; i < n; i++) {
    try { return await fn(); } catch (e) {
      if (i === n - 1) throw e;
      await new Promise(r => setTimeout(r, 250));
    }
  }
}

function dumpHex(base, buf, indent = '  ') {
  for (let i = 0; i < buf.length; i += 16) {
    const slice = buf.slice(i, i + 16);
    const hex = Array.from(slice).map(b => b.toString(16).padStart(2,'0')).join(' ');
    const ascii = slice.toString('latin1').replace(/[^\x20-\x7e]/g, '.');
    const addr = (base + i).toString(16).padStart(8, '0');
    console.log(`${indent}${addr}  ${hex.padEnd(48)}  ${ascii}`);
  }
}

(async () => {
  const c = new PineClient({ port: 28011, timeoutMs: 20000 });
  await c.connect();
  console.log('PINE connected\n');

  const s = await retry('status', () => c.status());
  console.log(`PCSX2: ${s.name}\n`);

  // === Section A: metadata block + lobby buffer prefix ===
  console.log('=========================================');
  console.log('A. 0x0086F7F0..0x0086F900 (272 bytes)');
  console.log('   covers metadata block + lobby buffer start');
  console.log('=========================================');
  const sectionA = await retry('A', () => c.readBytes(0x0086F7F0, 272));
  dumpHex(0x0086F7F0, sectionA);

  // === Section B: state machine variables ===
  console.log('\n=========================================');
  console.log('B. 0x007152A0..0x00715300 (96 bytes)');
  console.log('   covers 0x7152B0 (scratch), 0x7152E1 (state), 0x7152E4 (substate), 0x7152E8 (cursor)');
  console.log('=========================================');
  const sectionB = await retry('B', () => c.readBytes(0x007152A0, 96));
  dumpHex(0x007152A0, sectionB);

  // === Section C: the list pointers ===
  console.log('\n=========================================');
  console.log('C. List pointers passed to FUN_00634AB0');
  console.log('=========================================');
  const ptrA = await retry('ptrA', () => c.read32(0x003434A8));
  const ptrB = await retry('ptrB', () => c.read32(0x003434A0));
  console.log(`  *0x003434A8 = 0x${ptrA.toString(16).padStart(8,'0')}  (list ptr A — a1 of input poller)`);
  console.log(`  *0x003434A0 = 0x${ptrB.toString(16).padStart(8,'0')}  (list ptr B — a2 of input poller)`);

  // === Section D: deref each list ptr if valid ===
  for (const [label, ptr] of [['*0x003434A8 → A', ptrA], ['*0x003434A0 → B', ptrB]]) {
    if (ptr >= 0x100000 && ptr < 0x2000000) {
      console.log(`\n--- Deref ${label} @ 0x${ptr.toString(16)} (128 bytes) ---`);
      try {
        const buf = await c.readBytes(ptr, 128);
        dumpHex(ptr, buf);
      } catch (e) {
        console.log(`  read failed: ${e.message}`);
      }
    } else {
      console.log(`\n--- Skip ${label}: 0x${ptr.toString(16)} not in EE RAM range ---`);
    }
  }

  // === Section E: the existing render-time vars (renderer's record base, etc) for context ===
  console.log('\n=========================================');
  console.log('E. Renderer pointers + own-handle filter (for context)');
  console.log('=========================================');
  const renderBase = await retry('70d1c0', () => c.read32(0x0070D1C0));
  console.log(`  *0x0070D1C0 = 0x${renderBase.toString(16).padStart(8,'0')}  (renderer record base)`);
  const ownName = await retry('874fc0', () => c.readBytes(0x00874FC0, 16));
  console.log(`  0x00874FC0 (own-handle filter):`);
  dumpHex(0x00874FC0, ownName, '    ');

  c.close();
  console.log('\ndone');
})().catch(e => { console.error('FATAL:', e.message); process.exit(1); });
