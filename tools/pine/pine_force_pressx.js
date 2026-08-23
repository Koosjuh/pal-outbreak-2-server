#!/usr/bin/env node
// Force the press-X TCP path on PCSX2 by:
//   (1) Overwriting the press-X destination IP at 0x35BA98
//       (it's currently 192.0.2.100 — TEST-NET-1, RFC 5737 reserved, NOT routable)
//   (2) Marking the subsystem ID at 0x35B9E0 as "allocated" (1 instead of -1)
//   (3) Pre-populating slot-name buffers (0x86F810, 0x7152B0)
//   (4) Setting NTGUI state byte to enter the dispatcher
//
// What we learned via RE 2026-06-01:
//   - rt_state_machine_626900 (netwk 0x626900) is the press-X press-handler.
//   - At state-machine "SEND" branch (netwk 0x626b30..b80):
//       a0 = *(0x35B9E0)         ← reads subsystem ID. -1 = "uninitialized"
//       state byte = 4            ← sets local state
//       jal FUN_001dbe60          ← builds outbound SN@P packet
//       jal FUN_001d4de0          ← writes ptr to *0x25B78C (slot 1 callback)
//       jal FUN_001ca780          ← sends the packet
//   - FUN_001dbe60 builds the IP target from *(0x35BA98).
//   - With *0x35BA98 = 192.0.2.100, all press-X TCP attempts hit reserved IP.
//
// After this poke, the state-machine SEND branch should fire to OUR server.

'use strict';
const { PineClient } = require('./pine_client');

const ourIp = process.argv[2] || '192.0.2.196';
const slotName = process.argv[3] || 'SLOT0001';
const newState = parseInt(process.argv[4] || '1', 10);

// Pack IP as LE u32. EE stores IP as bytes 0x35BA98..0x35BA9B in network order
// (BE), so LE u32 has bytes reversed.
const octets = ourIp.split('.').map(n => parseInt(n, 10) & 0xff);
const ipLE = (octets[3] << 24) | (octets[2] << 16) | (octets[1] << 8) | octets[0];

(async () => {
  const c = new PineClient({ port: 28011, timeoutMs: 15000 });
  await c.connect();
  console.log('PINE connected\n');

  const before = {
    ip:    await c.read32(0x0035BA98),
    sub:   await c.read32(0x0035B9E0),
    port:  await c.read16(0x0035B9E8),
    state: await c.read8(0x007152E1),
    f810:  await c.readBytes(0x0086F810, 16),
  };
  const ipBytes = [
    (before.ip      ) & 0xff,
    (before.ip >>  8) & 0xff,
    (before.ip >> 16) & 0xff,
    (before.ip >> 24) & 0xff,
  ].join('.');
  console.log('BEFORE:');
  console.log(`  *0x35BA98 (press-X dest IP LE)   = 0x${before.ip.toString(16).padStart(8,'0')}  (= ${ipBytes})`);
  console.log(`  *0x35B9E0 (subsystem ID)         = 0x${before.sub.toString(16).padStart(8,'0')}  (-1=uninitialized)`);
  console.log(`  *0x35B9E8 (press-X port)         = ${before.port}`);
  console.log(`  state byte 0x7152E1              = 0x${before.state.toString(16)}`);
  console.log(`  0x86F810 (slot copy)             = "${before.f810.toString('latin1').replace(/\0.*/,'')}"`);

  console.log(`\nWriting:`);
  // 1. Fix press-X destination IP
  await c.write32(0x0035BA98, ipLE >>> 0);
  console.log(`  *0x35BA98  <- 0x${(ipLE >>> 0).toString(16).padStart(8,'0')}  (= ${ourIp})`);

  // 2. Mark subsystem as allocated
  await c.write32(0x0035B9E0, 1);
  console.log(`  *0x35B9E0  <- 1                              (subsystem ID = allocated)`);

  // 3. Slot name buffers
  const slotBuf = Buffer.alloc(16, 0);
  slotBuf.write(slotName, 0, 'ascii');
  await c.writeBytes(0x007152B0, slotBuf);
  await c.writeBytes(0x0086F810, slotBuf);
  console.log(`  0x7152B0   <- "${slotName}"`);
  console.log(`  0x86F810   <- "${slotName}"`);

  // 4. State byte
  await c.write8(0x007152E1, newState & 0xff);
  console.log(`  0x7152E1   <- 0x${newState.toString(16)}                          (NTGUI state)`);

  console.log(`\nAFTER:`);
  const after = {
    ip:    await c.read32(0x0035BA98),
    sub:   await c.read32(0x0035B9E0),
    state: await c.read8(0x007152E1),
  };
  const ipBytesAfter = [
    (after.ip      ) & 0xff,
    (after.ip >>  8) & 0xff,
    (after.ip >> 16) & 0xff,
    (after.ip >> 24) & 0xff,
  ].join('.');
  console.log(`  *0x35BA98 = 0x${after.ip.toString(16).padStart(8,'0')}  (= ${ipBytesAfter})`);
  console.log(`  *0x35B9E0 = 0x${after.sub.toString(16).padStart(8,'0')}`);
  console.log(`  0x7152E1  = 0x${after.state.toString(16)}`);

  console.log(`\nNow watch PCSX2 + DEV9 log + server console for ~30s.`);
  console.log(`Expect: TCP/UDP attempts to ${ourIp} (not 192.0.2.100 anymore).`);

  c.close();
})().catch(e => { console.error('FATAL:', e.message); process.exit(1); });
