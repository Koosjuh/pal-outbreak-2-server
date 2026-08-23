#!/usr/bin/env node
// Robust PINE dump — sequential, per-call timing, retry, smaller chunks.
'use strict';
const { PineClient } = require('./pine_client');

const t0 = Date.now();
const t = () => `+${(Date.now() - t0).toString().padStart(5)}ms`;
const log = m => console.log(`${t()} ${m}`);

async function withRetry(label, fn, n = 3) {
  for (let i = 0; i < n; i++) {
    try { return await fn(); }
    catch (e) {
      log(`  ${label} attempt ${i+1} FAILED: ${e.message}`);
      if (i === n-1) throw e;
      await new Promise(r => setTimeout(r, 500));
    }
  }
}

// Read N bytes in 4-byte chunks. Each chunk is ONE PINE call.
async function readChunked(c, addr, total, label) {
  const out = Buffer.alloc(total);
  for (let off = 0; off < total; off += 4) {
    const v = await withRetry(`${label}+0x${off.toString(16)}`,
      () => c.read32(addr + off));
    out.writeUInt32LE(v >>> 0, off);
    // tiny pause to let PCSX2 catch breath
    await new Promise(r => setImmediate(r));
  }
  return out;
}

(async () => {
  log('connecting...');
  const c = new PineClient({ port: 28011, timeoutMs: 30000 });
  await c.connect();
  log('connected');

  log('status check...');
  const s = await withRetry('status', () => c.status());
  log(`status = ${s.name}`);

  log('reading record base ptr...');
  const ptr = await withRetry('read32(0x70D1C0)', () => c.read32(0x0070d1c0));
  log(`*0x70D1C0 = 0x${ptr.toString(16)}`);

  if (ptr < 0x80000 || ptr > 0x2000000) {
    log(`base ptr out of range; aborting`);
    c.close();
    return;
  }

  const regions = [
    { name: 'rec0_start',        addr: ptr,                size: 32 },
    { name: 'rec0_hostname',     addr: ptr + 0x300,        size: 32 },
    { name: 'rec0_tail',         addr: ptr + 0x1320,       size: 16 },
    { name: 'rec1_start',        addr: ptr + 0x1340,       size: 32 },
    { name: 'rec1_hostname',     addr: ptr + 0x1340+0x300, size: 32 },
  ];

  for (const r of regions) {
    log(`reading ${r.name} @ 0x${r.addr.toString(16)} (${r.size}b)...`);
    const buf = await readChunked(c, r.addr, r.size, r.name);
    console.log(`\n== ${r.name} @ 0x${r.addr.toString(16)} ==`);
    dumpHex(r.addr, buf);
    // raw XOR with MINAMIOH
    const key = Buffer.from('MINAMIOH', 'ascii');
    const xd = Buffer.alloc(buf.length);
    for (let i = 0; i < buf.length; i++) xd[i] = buf[i] ^ key[i & 7];
    console.log('  XOR(MINAMIOH):');
    dumpHex(r.addr, xd, '    ');
  }

  c.close();
  log('done');
})().catch(e => { log(`FATAL: ${e.message}`); process.exit(1); });

function dumpHex(base, buf, indent = '  ') {
  for (let i = 0; i < buf.length; i += 16) {
    const slice = buf.slice(i, i + 16);
    const hex = Array.from(slice).map(b => b.toString(16).padStart(2,'0')).join(' ');
    const ascii = slice.toString('latin1').replace(/[^\x20-\x7e]/g, '.');
    const addr = (base + i).toString(16).padStart(8, '0');
    console.log(`${indent}${addr}  ${hex.padEnd(48)}  ${ascii}`);
  }
}
