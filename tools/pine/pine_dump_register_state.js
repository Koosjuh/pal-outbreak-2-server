#!/usr/bin/env node
// Comprehensive register-state dump for RE.
// Reads the EE state struct at 0x0036D760 + key offsets that REGISTER-OK
// (FUN_001d98f8) reads/writes.
'use strict';
const { PineClient } = require('./pine_client');

const STATE_BASE = 0x0036D760;

const ranges = [
  // password / key buffer (state+0x484 → blowfish key for REGISTER decrypt)
  { name: 'password key (state+0x484)',       addr: STATE_BASE + 0x484, len: 0x40 },
  // handle buffer (state+0x4ac → strcmp target for REGISTER-OK validation)
  { name: 'handle buffer (state+0x4ac)',      addr: STATE_BASE + 0x4ac, len: 0x40 },
  // post-decrypt destinations
  { name: 'register fields (state+0x500-538)', addr: STATE_BASE + 0x500, len: 0x40 },
  // register state byte
  { name: 'register state (state+0x80)',       addr: STATE_BASE + 0x80,  len: 0x10 },
  // press-X destination IP, port, subsystem ID (separate global vars)
  { name: 'press-X dest IP (0x35BA98)',         addr: 0x0035BA98,         len: 0x10 },
  { name: 'press-X subsystem (0x35B9E0)',       addr: 0x0035B9E0,         len: 0x10 },
  { name: 'press-X port etc (0x35B9E8)',        addr: 0x0035B9E8,         len: 0x10 },
  // subsystem callback table
  { name: 'callback table (0x25B788)',          addr: 0x0025B788,         len: 0x10 },
  // NTGUI state byte
  { name: 'NTGUI state (0x7152E0)',             addr: 0x007152E0,         len: 0x10 },
];

function hex(buf, base) {
  for (let i = 0; i < buf.length; i += 16) {
    const slice = buf.slice(i, i + 16);
    const h = Array.from(slice).map(b => b.toString(16).padStart(2,'0')).join(' ').padEnd(47);
    const a = slice.toString('latin1').replace(/[^\x20-\x7e]/g, '.');
    console.log(`  0x${(base + i).toString(16).padStart(8,'0')}  ${h}  ${a}`);
  }
}

(async () => {
  const c = new PineClient({ port: 28011, timeoutMs: 15000 });
  await c.connect();
  console.log('PINE connected\n');

  for (const r of ranges) {
    try {
      const buf = await c.readBytes(r.addr, r.len);
      console.log(`=== ${r.name} (${r.len} bytes) ===`);
      hex(buf, r.addr);
      console.log('');
    } catch (e) {
      console.log(`=== ${r.name} — READ FAILED: ${e.message} ===\n`);
    }
  }

  c.close();
})().catch(e => { console.error('FATAL:', e.message); process.exit(1); });
