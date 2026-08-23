#!/usr/bin/env node
// Read all known press-X-related variables in one shot. Helps locate what
// the game actually uses when constructing the register packet.
'use strict';
const { PineClient } = require('./pine_client');

(async () => {
  const c = new PineClient({ port: 28011, timeoutMs: 15000 });
  await c.connect();
  console.log('PINE connected\n');

  const addrs = [
    { name: 'uRam0035ba98 (local bind IP — primary)', addr: 0x0035ba98, size: 8 },
    { name: 'uRam0035ba90 (local IP slot 1)',          addr: 0x0035ba90, size: 8 },
    { name: 'uRam0035ba88 (local IP slot 2)',          addr: 0x0035ba88, size: 8 },
    { name: 'uRam0035bed8 (register-UDP dest)',        addr: 0x0035bed8, size: 8 },
    { name: 'uRam0035bed0 (neighbor)',                 addr: 0x0035bed0, size: 8 },
    { name: 'uRam0035bec8 (mode flag)',                addr: 0x0035bec8, size: 4 },
    { name: 'uRam0035b9e0 (subsystem ID)',             addr: 0x0035b9e0, size: 4 },
    { name: 'uRam0035b9e8 (local port — init 100)',    addr: 0x0035b9e8, size: 4 },
    { name: '0x35bee0 (snap01 hostname buffer)',       addr: 0x0035bee0, size: 48 },
    { name: 'cRam0035ccb3 (conn-target-provisioned)',  addr: 0x0035ccb3, size: 1 },
  ];

  for (const a of addrs) {
    const buf = await c.readBytes(a.addr, a.size);
    const hex = Array.from(buf).map(b => b.toString(16).padStart(2,'0')).join(' ');
    const ascii = buf.toString('latin1').replace(/[^\x20-\x7e]/g, '.');
    console.log(`${a.name}`);
    console.log(`  @ 0x${a.addr.toString(16)}  ${hex.padEnd(24)}  "${ascii}"`);
  }

  c.close();
})().catch(e => { console.error('FATAL:', e.message); process.exit(1); });
