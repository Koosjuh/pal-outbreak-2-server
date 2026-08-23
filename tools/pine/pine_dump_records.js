#!/usr/bin/env node
// Dump press-X record context for the hostname-format investigation.
'use strict';
const { PineClient } = require('./pine_client');

async function withRetry(label, fn, n = 3) {
  let last;
  for (let i = 0; i < n; i++) {
    try { return await fn(); } catch (e) { last = e; console.log(`  ${label} retry ${i+1}: ${e.message}`); await new Promise(r=>setTimeout(r,250)); }
  }
  throw last;
}

(async () => {
  const c = new PineClient({ port: 28011, timeoutMs: 20000 });
  await c.connect();
  console.log('PINE connected');

  // First: deref the record base ptr to confirm
  const ptr = await withRetry('read32(0x70D1C0)', () => c.read32(0x0070d1c0));
  console.log(`*0x70D1C0 = 0x${ptr.toString(16)} (record base)`);

  const regions = [
    { name: 'record 0 START (+0x000..0x040)',  addr: ptr + 0x000, size: 64 },
    { name: 'record 0 +0x2F0..0x330 (hostname area)', addr: ptr + 0x2f0, size: 64 },
    { name: 'record 0 +0x1300..0x1340 (record tail)', addr: ptr + 0x1300, size: 64 },
    { name: 'record 1 START (= base + 0x1340)', addr: ptr + 0x1340, size: 64 },
    { name: 'record 1 +0x2F0..0x330 (hostname area)', addr: ptr + 0x1340 + 0x2f0, size: 64 },
    { name: 'record 2 +0x2F0..0x330', addr: ptr + 0x2680 + 0x2f0, size: 64 },
  ];

  for (const r of regions) {
    const buf = await withRetry(r.name, () => c.readBytes(r.addr, r.size));
    console.log(`\n== ${r.name} @ 0x${r.addr.toString(16)} ==`);
    dumpHex(r.addr, buf);
    // XOR-decode attempt with MINAMIOH
    const key = Buffer.from('MINAMIOH', 'ascii');
    const xord = Buffer.alloc(buf.length);
    for (let i = 0; i < buf.length; i++) xord[i] = buf[i] ^ key[i & 7];
    console.log('  XOR MINAMIOH (no salt/p5):');
    dumpHex(r.addr, xord, '  ');
  }

  c.close();
})().catch(e => { console.error('FATAL:', e.message); process.exit(1); });

function dumpHex(base, buf, indent = '  ') {
  for (let i = 0; i < buf.length; i += 16) {
    const slice = buf.slice(i, i + 16);
    const hex = Array.from(slice).map(b => b.toString(16).padStart(2,'0')).join(' ');
    const ascii = slice.toString('latin1').replace(/[^\x20-\x7e]/g, '.');
    const addr = (base + i).toString(16).padStart(8, '0');
    console.log(`${indent}${addr}  ${hex.padEnd(48)}  ${ascii}`);
  }
}
