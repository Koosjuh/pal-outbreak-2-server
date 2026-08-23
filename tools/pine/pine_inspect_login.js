'use strict';
/**
 * PINE state-struct inspector.
 *
 * Goal: find the per-connection state struct used by the PAL SN@P LOGIN handler
 * (FUN_001c5a20 in EE @ 0x1c5a20) and dump the critical fields — most importantly
 * state[0x28] (expected hash buffer ptr) and state[0x29] (hash length) which
 * determine the LOGIN seed payload shape we need to send.
 *
 * How it works:
 *   1. Search EE RAM (0x00100000..0x02000000) for the 8-byte signature of our
 *      LOGIN seed packet header: `00 09 02 61 01 00 00 00`. This is what the
 *      game's packet reader writes to state[0x30]->buffer when it receives our
 *      LOGIN seed.
 *   2. For each signature match (header buffer candidate H):
 *      - Scan EE RAM in 4-byte-aligned strides for a u32 = H.
 *      - That u32's address is a candidate state[0x30] (struct offset 0x30 holds
 *        the header buffer pointer). So state-struct base = ptr_addr - 0x30.
 *   3. For each candidate state struct, dump:
 *        offset 0x0d   state[0xd]       — state-advance byte
 *        offset 0x34   state[0xd]       — also-read-as state[0xd] in some funcs
 *        offset 0xa0   state[0x28]      — expected hash buffer ptr
 *        offset 0xa4   state[0x29]      — hash length
 *        offset 0xd0   state[0x34]      — payload buffer ptr
 *        offset 0xdc   state[0x37]      — error code
 *        offset 0xec   state[0x3b]      — pcap/aux
 *        full 0x100 bytes for offline analysis.
 *
 * Usage:
 *   1. Boot the game, do the in-game login, click "Go Online".
 *   2. Once the auto-PINE injector message appears in the server log AND you've
 *      clicked through to the lobby, run this tool:
 *
 *        node tools/pine_inspect_login.js
 *
 *   3. It will print all candidate state structs. If state[0x29] is non-zero on
 *      ALL candidates, that's our answer — the LOGIN payload needs that many
 *      hash bytes (and we'd need to dig out the hash from state[0x28]).
 *
 * Limitation: the EE state struct may be freed when the SN@P TCP connection
 * closes. Speed matters. Run this WHILE the lobby session is active, not after.
 */

const { PineClient } = require('./pine_client');

const SCAN_START = 0x00100000;
const SCAN_END   = 0x02000000;   // 32 MB EE RAM
const BATCH_BYTES = 4096;        // bytes per PINE batch
const LOGIN_SEED_HEADER = Buffer.from([0x00, 0x09, 0x02, 0x61, 0x01, 0x00, 0x00, 0x00]);

function hex(buf) {
  const rows = [];
  for (let i = 0; i < buf.length; i += 16) {
    const chunk = buf.slice(i, i + 16);
    const hp = [...chunk].map(b => b.toString(16).padStart(2, '0')).join(' ').padEnd(47);
    const ap = [...chunk].map(b => (b >= 0x20 && b < 0x7f) ? String.fromCharCode(b) : '.').join('');
    rows.push(`  ${i.toString(16).padStart(4, '0')}  ${hp}  ${ap}`);
  }
  return rows.join('\n');
}

/**
 * Read a contiguous range from EE RAM via PINE, in BATCH_BYTES chunks of read64.
 * Uses pine_client's send([...]) batching for speed.
 */
async function readRange(client, start, end) {
  const OP_READ64 = 0x03;
  const total = end - start;
  const out = Buffer.alloc(total);
  let off = 0;
  const step = BATCH_BYTES / 8; // u64s per batch
  while (off < total) {
    const remainingU64 = Math.ceil((total - off) / 8);
    const thisBatch = Math.min(step, remainingU64);
    const cmds = [];
    for (let i = 0; i < thisBatch; i++) {
      const addr = start + off + i * 8;
      const payload = Buffer.alloc(4); payload.writeUInt32LE(addr >>> 0, 0);
      cmds.push({ opcode: OP_READ64, body: Buffer.concat([Buffer.from([OP_READ64]), payload]) });
    }
    const replies = await client.send(cmds);
    for (let i = 0; i < replies.length; i++) {
      if (!replies[i].ok) continue;
      const bytes = replies[i].payload;
      const dst = off + i * 8;
      const writeLen = Math.min(8, total - dst);
      bytes.copy(out, dst, 0, writeLen);
    }
    off += thisBatch * 8;
  }
  return out;
}

function findSignature(buf, sig, baseAddr) {
  const hits = [];
  for (let i = 0; i <= buf.length - sig.length; i++) {
    let ok = true;
    for (let j = 0; j < sig.length; j++) {
      if (buf[i + j] !== sig[j]) { ok = false; break; }
    }
    if (ok) hits.push(baseAddr + i);
  }
  return hits;
}

function findU32(buf, target, baseAddr) {
  const hits = [];
  for (let i = 0; i + 4 <= buf.length; i += 4) {
    if (buf.readUInt32LE(i) === target) hits.push(baseAddr + i);
  }
  return hits;
}

async function main() {
  const port = Number(process.argv[2] || 28011);
  const client = new PineClient({ port, timeoutMs: 5000 });

  console.log(`Connecting to PINE on port ${port}...`);
  await client.connect();
  const status = await client.status();
  console.log(`PINE OK — status: ${status.name}`);

  console.log(`Scanning EE RAM 0x${SCAN_START.toString(16)}..0x${SCAN_END.toString(16)} for LOGIN seed header signature...`);
  console.log(`  signature: ${LOGIN_SEED_HEADER.toString('hex')}`);
  const t0 = Date.now();
  const ram = await readRange(client, SCAN_START, SCAN_END);
  console.log(`  read ${ram.length} bytes in ${Date.now() - t0}ms`);

  const sigHits = findSignature(ram, LOGIN_SEED_HEADER, SCAN_START);
  console.log(`\nFound ${sigHits.length} signature hit(s):`);
  for (const addr of sigHits) console.log(`  0x${addr.toString(16).padStart(8, '0')}`);

  if (sigHits.length === 0) {
    console.log(`\nNo hits. Possible reasons:`);
    console.log(`  - The LOBBY SN@P session has not yet sent the LOGIN seed.`);
    console.log(`  - The state struct was freed after the connection FIN'd.`);
    console.log(`  - The signature bytes are wrong for your latest snap_server build.`);
    console.log(`\nNext: try running this script SOONER after Go Online click,`);
    console.log(`or use SaveState approach.`);
    client.close();
    return;
  }

  for (const hAddr of sigHits) {
    console.log(`\n${'='.repeat(70)}`);
    console.log(`Header buffer at 0x${hAddr.toString(16)} — searching for state struct that points to it...`);

    // Scan EE RAM for a u32 LE pointer == hAddr. Aligned 4-byte stride.
    const ptrHits = findU32(ram, hAddr, SCAN_START);
    console.log(`  Found ${ptrHits.length} pointer(s) to 0x${hAddr.toString(16)}:`);
    for (const pAddr of ptrHits) {
      // state struct base = pAddr - 0x30 (since state[0x30] holds the header buf ptr).
      // BUT — state is treated as int*, so state[0xc] in C = offset 0xc * 4 = 0x30.
      // Wait — re-read: in FUN_001c5a20 piVar5[0xc] reads from state base + 0xc*4 = 0x30.
      // So the pointer field IS at offset 0x30. Confirmed.
      const structBase = pAddr - 0x30;
      if (structBase < SCAN_START || structBase + 0x100 > SCAN_END) continue;

      console.log(`\n  → candidate state struct base 0x${structBase.toString(16).padStart(8, '0')}`);
      const buf100 = ram.slice(structBase - SCAN_START, structBase - SCAN_START + 0x100);
      console.log(hex(buf100));
      console.log();
      // The fields we care about:
      const stateD     = buf100[0x0d];                      // state-advance byte
      const offset_28  = buf100.readUInt32LE(0xa0);         // state[0x28]
      const offset_29  = buf100.readUInt32LE(0xa4);         // state[0x29] = HASH LENGTH
      const offset_34  = buf100.readUInt32LE(0xd0);         // state[0x34] payload buf ptr
      const offset_37  = buf100.readUInt32LE(0xdc);         // state[0x37] error code
      console.log(`    state[0xd]   = 0x${stateD.toString(16).padStart(2, '0')}    (state-advance byte; expect 0x17/0x19/0x21/0x23/0x31)`);
      console.log(`    state[0x28]  = 0x${offset_28.toString(16).padStart(8, '0')}  (expected hash buffer ptr — IF valid, dump that buffer)`);
      console.log(`    state[0x29]  = 0x${offset_29.toString(16).padStart(8, '0')}  ★ HASH LENGTH — this is what the LOGIN seed payload needs to satisfy`);
      console.log(`    state[0x34]  = 0x${offset_34.toString(16).padStart(8, '0')}  (payload buffer ptr)`);
      console.log(`    state[0x37]  = 0x${offset_37.toString(16).padStart(8, '0')}  (error code from last handler; -1 = error, 0 = ok)`);

      // If state[0x28] looks like a valid EE pointer, dump the hash too.
      if (offset_28 >= SCAN_START && offset_28 + 0x40 < SCAN_END) {
        const hashBuf = ram.slice(offset_28 - SCAN_START, offset_28 - SCAN_START + Math.min(0x40, offset_29));
        console.log(`\n    hash buffer (first 0x40 bytes at state[0x28]):`);
        console.log(hex(hashBuf));
      }
    }
  }

  client.close();
}

main().catch(e => {
  console.error('FAIL:', e.message);
  console.error(e.stack);
  process.exitCode = 1;
});
