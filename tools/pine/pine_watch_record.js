#!/usr/bin/env node
// Software memory watchpoint: poll record +0x300 (press-X hostname slot) for
// the first N records and log every change with timestamp. Run during boot
// to catch the writer(s).
'use strict';
const fs = require('fs');
const path = require('path');
const { PineClient } = require('./pine_client');

const POLL_INTERVAL_MS = parseInt(process.env.POLL_MS || '50', 10);
const NUM_RECORDS = parseInt(process.env.NUM_RECORDS || '4', 10);
const READ_LEN = 32;             // bytes per region
const OUTFILE = process.argv[2] || `C:\\dnas\\active\\captures\\watch_record_${Date.now()}.jsonl`;

async function withRetry(label, fn, n = 3) {
  for (let i = 0; i < n; i++) {
    try { return await fn(); }
    catch (e) {
      if (i === n - 1) throw e;
      await new Promise(r => setTimeout(r, 200));
    }
  }
}

async function main() {
  const c = new PineClient({ port: 28011, timeoutMs: 15000 });
  await c.connect();
  console.log(`PINE connected; polling every ${POLL_INTERVAL_MS}ms; watching ${NUM_RECORDS} records`);
  console.log(`Log: ${OUTFILE}`);

  const out = fs.createWriteStream(OUTFILE, { flags: 'a' });
  out.write(JSON.stringify({ event: 'start', ts: new Date().toISOString(), pollMs: POLL_INTERVAL_MS, records: NUM_RECORDS }) + '\n');

  let lastBasePtr = null;
  const lastBytes = new Map();       // addr -> hex
  const startMs = Date.now();

  process.on('SIGINT', () => {
    console.log('\nstopping (Ctrl-C)...');
    out.end(() => process.exit(0));
  });

  while (true) {
    const tIso = new Date().toISOString();
    const tMs = Date.now() - startMs;
    let basePtr;
    try { basePtr = await withRetry('basePtr', () => c.read32(0x0070d1c0)); }
    catch (e) {
      console.log(`${tMs}ms basePtr read FAILED: ${e.message}`);
      await new Promise(r => setTimeout(r, POLL_INTERVAL_MS));
      continue;
    }

    if (basePtr !== lastBasePtr) {
      const entry = { event: 'basePtr_change', tMs, tIso, old: lastBasePtr, newVal: basePtr };
      console.log(`+${tMs}ms basePtr ${lastBasePtr === null ? '(initial)' : '0x'+lastBasePtr.toString(16)} → 0x${basePtr.toString(16)}`);
      out.write(JSON.stringify(entry) + '\n');
      lastBasePtr = basePtr;
      // basePtr changed — clear baseline since records are at new addr
      lastBytes.clear();
    }

    if (basePtr < 0x80000 || basePtr >= 0x2000000) {
      await new Promise(r => setTimeout(r, POLL_INTERVAL_MS));
      continue;
    }

    for (let i = 0; i < NUM_RECORDS; i++) {
      const addr = basePtr + i * 0x1340 + 0x300;
      try {
        const buf = await c.readBytes(addr, READ_LEN);
        const hex = buf.toString('hex');
        const prev = lastBytes.get(addr);
        if (prev !== hex) {
          const ascii = buf.toString('latin1').replace(/[^\x20-\x7e]/g, '.');
          const entry = { event: 'change', record: i, addr: '0x'+addr.toString(16), tMs, tIso, hex, ascii, prev: prev || null };
          console.log(`+${tMs}ms rec${i} @ 0x${addr.toString(16)}  ${hex.match(/.{1,32}/g).join(' ')}  "${ascii}"`);
          out.write(JSON.stringify(entry) + '\n');
          lastBytes.set(addr, hex);
        }
      } catch (e) {
        // skip silently — game might be reallocating heap
      }
    }
    await new Promise(r => setTimeout(r, POLL_INTERVAL_MS));
  }
}

main().catch(e => { console.error('FATAL:', e.message); process.exit(1); });
