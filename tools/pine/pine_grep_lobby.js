#!/usr/bin/env node
// One-shot: read the lobby data buffer (0x0087f864, 0x1000 bytes) and the
// renderer records (0x00694700, 50*56=2800 bytes). Grep for "LOBBY".
'use strict';
const { PineClient } = require('./pine_client');

(async () => {
  const c = new PineClient({ port: 28011, timeoutMs: 15000 });
  await c.connect();
  console.log('connected to PINE');

  // CORRECTED 2026-05-30: lobby data buffer is at 0x0086f864 NOT 0x87F864.
  // Disasm of state-2 handler memcpy at vaddr 0x00627010:
  //   lui a0, 0x87 ; addiu a0, a0, -1948 ; a0 = 0x86F864.
  const lobbyBuf = await c.readBytes(0x0086f864, 0x300);
  console.log('\n== 0x0086f864 (lobby data buffer, 0x300 bytes) ==');
  dumpHex(0x0086f864, lobbyBuf);
  grep('LOBBY', lobbyBuf, 0x0086f864);

  // 0x694700: renderer records (50 slots × 56 bytes = 2800 bytes)
  const recBuf = await c.readBytes(0x00694700, 2800);
  console.log('\n== 0x00694700 (renderer records, 50×56b) ==');
  // Show first 8 records (8*56 = 448 bytes)
  dumpHex(0x00694700, recBuf.slice(0, 448));
  grep('LOBBY', recBuf, 0x00694700);

  // 0x35ccc8: scratch buffer pointer used by FUN_001c9030
  const scratchPtr = await c.read32(0x0035ccc8);
  console.log('\n== iRam0035ccc8 (scratch buf ptr) ==');
  console.log(`  0x${scratchPtr.toString(16)}`);
  if (scratchPtr > 0x80000 && scratchPtr < 0x2000000) {
    const scratchBuf = await c.readBytes(scratchPtr, 0x100);
    console.log(`\n== scratch buf @ 0x${scratchPtr.toString(16)} (first 256b) ==`);
    dumpHex(scratchPtr, scratchBuf);
    grep('LOBBY', scratchBuf, scratchPtr);
    // also +0x14 — that's where the big snapField lands
    const bigOff = scratchPtr + 0x14;
    const bigBuf = await c.readBytes(bigOff, 0x300);
    console.log(`\n== scratch buf+0x14 @ 0x${bigOff.toString(16)} (big snapField dest, 0x300b) ==`);
    dumpHex(bigOff, bigBuf);
    grep('LOBBY', bigBuf, bigOff);
  }

  // 0x874fc0 — own-name filter buffer
  const ownNameBuf = await c.readBytes(0x00874fc0, 32);
  console.log('\n== 0x00874fc0 (own-name filter) ==');
  dumpHex(0x00874fc0, ownNameBuf);

  c.close();
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
function grep(needle, buf, base) {
  const target = Buffer.from(needle, 'ascii');
  let count = 0;
  for (let i = 0; i <= buf.length - target.length; i++) {
    if (buf.slice(i, i + target.length).equals(target)) {
      const addr = (base + i).toString(16);
      const ctx = buf.slice(Math.max(0, i-4), Math.min(buf.length, i+16)).toString('latin1').replace(/[^\x20-\x7e]/g, '.');
      console.log(`  ★ "${needle}" found at 0x${addr} (ctx: ${ctx})`);
      count++;
    }
  }
  if (count === 0) console.log(`  (no "${needle}" matches)`);
}
