#!/usr/bin/env node
// Path A: PINE-poke uRam0035bed8 with our LAN IP bytes (c0 a8 02 c4) to test
// the DNS-race theory. If next outbound UDP register from PCSX2 goes to
// 192.0.2.196 instead of 192.0.2.100, theory is confirmed.
//
// Writes byte-by-byte so the in-memory layout matches what the game produces
// when DNS resolution succeeds (it does u8 writes, not a u32 store).
'use strict';
const { PineClient } = require('./pine_client');

const BED8 = 0x0035BED8;
const HOSTNAME_BUF = 0x0035BEE0;
const IP_BYTES = [0xc0, 0xa8, 0x02, 0xc4];        // 192.0.2.196 — bytes in NETWORK order
const IP_BYTES_REVERSED = [0xc4, 0x02, 0xa8, 0xc0]; // same value, opposite byte order
const MONITOR_MS = parseInt(process.env.MONITOR_MS || '60000', 10);
const REPOKE_INTERVAL_MS = parseInt(process.env.REPOKE_MS || '500', 10);

async function withRetry(label, fn, n = 3) {
  for (let i = 0; i < n; i++) {
    try { return await fn(); }
    catch (e) {
      if (i === n-1) throw e;
      await new Promise(r => setTimeout(r, 250));
    }
  }
}

(async () => {
  const c = new PineClient({ port: 28011, timeoutMs: 15000 });
  await c.connect();
  console.log('PINE connected');

  const s = await withRetry('status', () => c.status());
  console.log(`PCSX2 status: ${s.name}`);

  console.log(`\n== BEFORE ==`);
  const before = await withRetry('read-before', () => c.readBytes(BED8, 32));
  dump(BED8, before);
  const hostBuf = await withRetry('read-hostname', () => c.readBytes(HOSTNAME_BUF, 64));
  console.log(`hostname buffer @ 0x${HOSTNAME_BUF.toString(16)}:`);
  dump(HOSTNAME_BUF, hostBuf);

  // Byte order experiment: write BOTH possibilities to consecutive addresses
  // so we can see which order ends up in the wire packet.
  console.log(`\nWriting bytes [${IP_BYTES.map(b=>b.toString(16)).join(' ')}] to 0x${BED8.toString(16)}+0..3 (network order)`);
  for (let i = 0; i < 4; i++) {
    await withRetry(`write8@${i}`, () => c.write8(BED8 + i, IP_BYTES[i]));
  }

  console.log(`\n== AFTER initial write ==`);
  const after = await withRetry('read-after', () => c.readBytes(BED8, 32));
  dump(BED8, after);

  // MONITOR + RE-POKE: game might clear bed8 between attempts. Re-write
  // periodically so the next auto-connect retry sees our value.
  console.log(`\nMonitoring + re-poking every ${REPOKE_INTERVAL_MS}ms for ${MONITOR_MS}ms. Watch wireshark.`);
  const t0 = Date.now();
  let lastVal = null;
  while (Date.now() - t0 < MONITOR_MS) {
    try {
      const buf = await c.readBytes(BED8, 4);
      const hex = buf.toString('hex');
      if (hex !== lastVal) {
        console.log(`+${(Date.now()-t0).toString().padStart(5)}ms bed8 = ${hex}`);
        lastVal = hex;
      }
      // Re-write if it's been zeroed
      if (buf[0] === 0 && buf[1] === 0 && buf[2] === 0 && buf[3] === 0) {
        for (let i = 0; i < 4; i++) await c.write8(BED8 + i, IP_BYTES[i]);
        console.log(`+${(Date.now()-t0).toString().padStart(5)}ms RE-POKED bed8`);
      }
    } catch (e) {
      console.log(`+${(Date.now()-t0).toString().padStart(5)}ms read failed: ${e.message}`);
    }
    await new Promise(r => setTimeout(r, REPOKE_INTERVAL_MS));
  }

  c.close();
  console.log('done');
})().catch(e => { console.error('FATAL:', e.message); process.exit(1); });

function dump(base, buf) {
  for (let i = 0; i < buf.length; i += 16) {
    const slice = buf.slice(i, i + 16);
    const hex = Array.from(slice).map(b => b.toString(16).padStart(2,'0')).join(' ');
    const ascii = slice.toString('latin1').replace(/[^\x20-\x7e]/g, '.');
    const addr = (base + i).toString(16).padStart(8, '0');
    console.log(`  ${addr}  ${hex}  ${ascii}`);
  }
}
