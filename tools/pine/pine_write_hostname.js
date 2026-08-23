#!/usr/bin/env node
// One-shot: write hostname string to slot record +0x300 to test the
// press-X-fails-because-hostname-empty hypothesis. Uses write32 for fewer
// roundtrips + retry logic for PINE flakiness.
'use strict';
const { PineClient } = require('./pine_client');

// 2026-05-31: corrected target — press-X reads record_at_*0x70D1C0 + N*0x1340 + 0x300.
// Record 1 hostname slot = 0xAC0000 + 0x1340 + 0x300 = 0xAC1640.
// (Assumes base ptr 0xAC0000 — script auto-derefs to confirm.)
const TARGET_ADDR = 0x00AC1640;
const HOSTNAME = 'snap01.capcom.client.sf.yav4.com';
const MAX_RETRIES = 3;

async function withRetry(label, fn) {
  let lastErr;
  for (let i = 0; i < MAX_RETRIES; i++) {
    try {
      return await fn();
    } catch (e) {
      lastErr = e;
      console.log(`  ${label} attempt ${i+1} failed (${e.message}); retrying...`);
      await new Promise(r => setTimeout(r, 200));
    }
  }
  throw lastErr;
}

(async () => {
  const c = new PineClient({ port: 28011, timeoutMs: 20000 });
  await c.connect();
  console.log('PINE connected');

  // Sanity-check first
  await withRetry('status', async () => {
    const s = await c.status();
    console.log(`PCSX2 status: ${s.name}`);
  });

  // Read existing content - batched
  const before = await withRetry('read-before', () => c.readBytes(TARGET_ADDR, 48));
  console.log(`BEFORE @ 0x${TARGET_ADDR.toString(16)}:`);
  dumpHex(TARGET_ADDR, before);

  // Pad to 4-byte alignment + zero terminator
  const text = HOSTNAME + '\0';
  const padLen = Math.ceil(text.length / 4) * 4 + 4;  // round up + extra zero word
  const buf = Buffer.alloc(padLen);
  Buffer.from(text, 'ascii').copy(buf, 0);

  console.log(`\nWriting ${buf.length} bytes in ${buf.length/4} u32 chunks ...`);
  for (let i = 0; i < buf.length; i += 4) {
    const u32 = buf.readUInt32LE(i);
    await withRetry(`write32@+${i}`, () => c.write32(TARGET_ADDR + i, u32));
  }

  // Verify
  const after = await withRetry('read-after', () => c.readBytes(TARGET_ADDR, 48));
  console.log(`\nAFTER @ 0x${TARGET_ADDR.toString(16)}:`);
  dumpHex(TARGET_ADDR, after);

  c.close();
  console.log('\nDone. Watch wireshark for the next outbound UDP packet (~22s).');
})().catch(e => { console.error('FATAL:', e.message); process.exit(1); });

function dumpHex(base, buf) {
  for (let i = 0; i < buf.length; i += 16) {
    const slice = buf.slice(i, i + 16);
    const hex = Array.from(slice).map(b => b.toString(16).padStart(2,'0')).join(' ');
    const ascii = slice.toString('latin1').replace(/[^\x20-\x7e]/g, '.');
    const addr = (base + i).toString(16).padStart(8, '0');
    console.log(`  ${addr}  ${hex.padEnd(48)}  ${ascii}`);
  }
}
