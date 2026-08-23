#!/usr/bin/env node
// Read-only PINE probe for the press-X / auto-connect investigation.
// Dumps the specific EE memory locations we've been speculating about,
// so we can verify or refute claims with ground truth.
//
// Usage:
//   node tools/pine_probe_press_x.js [--watch] [--out <file>]
//
// --watch:    re-poll every 500 ms until Ctrl-C; print only on change
// --out FILE: also append JSON snapshots to FILE
//
// No writes. No side effects. PINE Read* ops only.
'use strict';

const fs = require('fs');
const { PineClient } = require('./pine_client');

const PINE_HOST = '127.0.0.1';
const PINE_PORT = Number(process.env.PINE_PORT || 28011); // PCSX2 default

const args = process.argv.slice(2);
const watchMode = args.includes('--watch');
const outIdx = args.indexOf('--out');
const outFile = outIdx >= 0 ? args[outIdx + 1] : null;

// Critical EE addresses from netwk.bin + SLES decompiles.
const PROBES = [
  // Press-X destination IP chain
  { name: 'uRam0035ba98',      addr: 0x0035ba98, size: 4, why: 'press-X primary IP (socket-create arg, FUN_001d46ec)' },
  { name: 'uRam0035ba90',      addr: 0x0035ba90, size: 4, why: 'secondary IP slot1' },
  { name: 'uRam0035ba88',      addr: 0x0035ba88, size: 4, why: 'tertiary IP slot2' },
  { name: 'uRam0035bed8',      addr: 0x0035bed8, size: 4, why: 'press-X destination IP (used by FUN_001db7e8 register-UDP target)' },
  { name: 'uRam0035bed0',      addr: 0x0035bed0, size: 4, why: 'neighbor of bed8' },
  { name: 'uRam0035bec8',      addr: 0x0035bec8, size: 4, why: 'mode flag set by FUN_006150b0 (0/1/2)' },
  { name: 'uRam0035baa8',      addr: 0x0035baa8, size: 4, why: 'mode int from lobby-entry struct +0x1310' },

  // Socket / subsystem
  { name: 'uRam0035b9e0',      addr: 0x0035b9e0, size: 4, why: 'subsystem ID from func_0x001d46ec (1 on success)' },
  { name: 'uRam0035b9e8',      addr: 0x0035b9e8, size: 4, why: 'press-X local port (init = 100)' },

  // Second DNS chain (SN@P TCP client — already-working baseline)
  { name: '0x35cc70_hostname', addr: 0x0035cc70, size: 64, why: 'second hostname buffer (init = "app01.reo.capcom.sf.yav4.com")' },
  { name: 'sRam0035ccb0_port', addr: 0x0035ccb0, size: 2, why: 'SN@P TCP port (init = 0x278f = 10127)' },
  { name: 'cRam0035ccb3_flag', addr: 0x0035ccb3, size: 1, why: 'connection-target-provisioned flag (set to 1 by FUN_001c91d0)' },

  // Hostname for bed8 chain
  { name: '0x35bee0_hostname', addr: 0x0035bee0, size: 64, why: 'bed8 hostname buffer (init = "snap01.capcom.client.sf.yav4.com")' },

  // Error flag and screen state
  { name: 'cRam0086f7e0_err',  addr: 0x0086f7e0, size: 1, why: 'press-X error flag (1 = error, set by 0x27 event)' },
  { name: 'cRam007152e1_state',addr: 0x007152e1, size: 1, why: 'rt_state_machine_626900 main state byte' },
  { name: 'sRam007152ea_cursor',addr: 0x007152ea, size: 2, why: 'server-select cursor (signed short, 0xFFFF = -1 sentinel)' },

  // Chunk-list count (drives server-select grid bounds)
  { name: 'uRam00365cf0_count',addr: 0x00365cf0, size: 2, why: 'chunk-list manifest count from 0x6103 reply (we send 1)' },

  // SN@P slot pool (0x6504 reply destination)
  { name: '0x35ccd0_record0',  addr: 0x0035ccd0, size: 64, why: 'first slot record (0x6504 reply lands here: name, status, ...)' },
  { name: '0x35cdf8_trailing', addr: 0x0035cdf8, size: 16, why: 'slot0 trailing u16/u32 (sanitized IP c00002c4 was observed here)' },

  // Status table (0x6105 reply destination)
  { name: 'uRam00365bb0_cnt',  addr: 0x00365bb0, size: 2, why: 'status table count (FUN_001c63c0 populates)' },
  { name: 'uRam00365e1a',      addr: 0x00365e1a, size: 2, why: 'expected reply_count for 0x6510 u16 loop' },

  // Disc-loaded entry table (where press-X reads from).
  // CORRECTION 2026-05-30: iRam0070d1c0 is a POINTER stored at 0x0070D1C0
  // (assigned `iRam0070d1c0 = iRam003435bc` in FUN_0060f910). To read
  // `iRam0070d1c0+0x24` properly we need a TWO-STEP probe: read the
  // pointer first, then read from (ptr+offset). The simple-addr probe
  // below just reads the pointer itself, and the table-derived fields
  // are probed via the dynamic `derefProbes` chain in probeOnce().
  { name: 'iRam0070d1c0_PTR', addr: 0x0070d1c0, size: 4, why: 'POINTER to per-screen state struct (set by FUN_0060f910 case 0)' },

  // OUTER state byte for server-select / disc-load orchestrator (FUN_0060f910).
  // SCALAR — fixed address. This is the key one for the save-validation theory:
  // ends in 8 or 9 if FUN_006101d0 returned -2 or -3 (memcard save bad).
  { name: 'iRam0070d1d8_OUTER',addr: 0x0070d1d8, size: 1, why: 'FUN_0060f910 outer state. 0=init,1=disc-poll,2=success,5=variant,8/9=ERROR (save validation fail)' },

  // Static iRam003435bc — companion pointer set by some allocator path.
  { name: 'iRam003435bc_PTR', addr: 0x003435bc, size: 4, why: 'state-struct pointer (companion to iRam0070d1c0)' },

  // SN@P TCP outer-state-machine state byte
  { name: 'outer_state_+0xc',  addr: 0x0035b9d4, size: 1, why: '(guess) +0xc of SN@P TCP client state struct (0=init, 1=DNS, 2=dispatch, ..., 6=FUN_001ca410 bed8 resolve)' },

  // 2026-05-30: lobby data buffer and renderer first record — verify our
  // 0x1007 big snapField actually decodes into memory.
  { name: 'iRam0035ccc8_PTR',    addr: 0x0035ccc8, size: 4,  why: 'scratch buf base ptr (FUN_001c92b0 decode dest)' },
  { name: 'lobbybuf_0x86f864',   addr: 0x0086f864, size: 64, why: 'lobby data buffer (memcpy dest from gate 0x365dcc); first 64b. 2026-05-30: corrected from 0x87F864 — comprehensive doc had typo. Real addr = lui 0x87 + addiu -1948 = 0x86F864.' },
  { name: 'renderer_rec0_0x694700', addr: 0x00694700, size: 56, why: 'renderer record 0 (56b, offset 16-31 = name)' },
  { name: 'renderer_rec1_0x694738', addr: 0x00694738, size: 56, why: 'renderer record 1' },
  { name: 'own_name_0x874fc0',   addr: 0x00874fc0, size: 16, why: 'own-name filter target (16-byte ASCII)' },

  // 2026-05-30 gate probes — see if 0x365dcc transiently holds scratch+0x14
  // before FUN_001c2da0 (via FUN_001c3250 from rt_dispatch_626e70 v1=0 branch)
  // clears it.
  { name: 'mode_0x365dc0',  addr: 0x00365dc0, size: 1, why: 'mode byte from FUN_001c3a60 (1=our reply, 0=skip path)' },
  { name: 'detail_0x365dc4',addr: 0x00365dc4, size: 4, why: 'detail u32 from FUN_001c3a60 (we send 0)' },
  { name: 'gate1_0x365dc8', addr: 0x00365dc8, size: 4, why: 'gate 1 = scratch_ptr (set in delay slot at 0x1c93b4)' },
  { name: 'gate2_0x365dcc', addr: 0x00365dcc, size: 4, why: 'GATE 2 = scratch_ptr+0x14 (set at 0x1c9400 on big-snapField success)' },
  { name: 'gate3_0x365df8', addr: 0x00365df8, size: 4, why: 'gate 3 = scratch_ptr (cmd 0x1005 handler at 0x1c9150)' },
  { name: 'dataready_0x7152d0', addr: 0x007152d0, size: 1, why: 'data-ready flag set by NTGUI state-2 consumer at 0x00627040' },
];

function fmtBuf(name, buf, size) {
  if (size <= 4) {
    const hex = buf.toString('hex');
    let dec;
    if (size === 1) dec = buf[0];
    else if (size === 2) dec = buf.readUInt16LE(0) + ' (BE=' + buf.readUInt16BE(0) + ')';
    else dec = buf.readUInt32LE(0) + ' (BE=' + buf.readUInt32BE(0).toString(16) + ')';
    return `0x${hex.padStart(size*2, '0')}  ${dec}`;
  }
  // For larger buffers, show hex + ascii preview
  const hex = buf.toString('hex').match(/.{1,32}/g).join(' ');
  const ascii = buf.toString('latin1').replace(/[^\x20-\x7e]/g, '.');
  return `\n    hex: ${hex}\n    ascii: ${JSON.stringify(ascii)}`;
}

// Fields accessed via *(iRam0070d1c0 + offset). Each entry says how big the
// field is and what it means.
const DEREF_PROBES = [
  { name: 'state_+0x24_disc_table_count', off: 0x24,  size: 1, why: 'disc table entry count' },
  { name: 'state_+0x25_load_flags',       off: 0x25,  size: 1, why: 'disc-load status flag bits' },
  { name: 'state_+0x2c_inner_substate',   off: 0x2c,  size: 1, why: 'FUN_006101d0 substate (case 0..5)' },
  { name: 'state_+0x4e_anim_byte',        off: 0x4e,  size: 1, why: 'animation/transition byte' },
  { name: 'state_+0x258_first_entry',     off: 0x258, size: 16,why: 'entry-table[0] first 16 bytes (5×u32 layout)' },
  { name: 'state_+0x268_entry_struct_p',  off: 0x268, size: 4, why: 'entry[0]+0x10 = ptr to lobby-entry struct' },
  // Work buffer (state+0x1180 = the 105KB region the memcard save loads into)
  // Mode counts at work_buf+0x19AD0/4/8 → state+0x1AC50/4/8
  { name: 'work_buf_mode0_cnt',           off: 0x1AC50, size: 4, why: 'mode 0 count (must be > 0)' },
  { name: 'work_buf_mode1_cnt',           off: 0x1AC54, size: 4, why: 'mode 1 count (must be > 0)' },
  { name: 'work_buf_mode2_cnt',           off: 0x1AC58, size: 4, why: 'mode 2 count (must be > 0)' },
];

async function probeOnce(client) {
  const ts = Date.now();
  const snapshot = { ts: new Date(ts).toISOString(), values: {} };
  // First pass: scalar probes
  for (const p of PROBES) {
    try {
      const buf = await client.readBytes(p.addr, p.size);
      snapshot.values[p.name] = {
        addr: '0x' + p.addr.toString(16),
        size: p.size,
        hex: buf.toString('hex'),
      };
    } catch (e) {
      snapshot.values[p.name] = { addr: '0x' + p.addr.toString(16), error: e.message };
    }
  }
  // Second pass: deref probes via iRam0070d1c0 pointer
  try {
    const basePtr = await client.read32(0x0070d1c0);
    snapshot.values._deref_base = { ptr: '0x' + basePtr.toString(16) };
    if (basePtr && basePtr >= 0x80000 && basePtr < 0x2000000) {
      for (const p of DEREF_PROBES) {
        try {
          const buf = await client.readBytes(basePtr + p.off, p.size);
          snapshot.values[p.name] = {
            addr: '0x' + (basePtr + p.off).toString(16),
            size: p.size,
            hex: buf.toString('hex'),
          };
        } catch (e) {
          snapshot.values[p.name] = { error: e.message };
        }
      }
    } else {
      snapshot.values._deref_base.note = 'basePtr looks invalid; skipping deref probes';
    }
  } catch (e) {
    snapshot.values._deref_base = { error: e.message };
  }
  // Third pass: deref via 0x35ccc8 (FUN_001c9030 scratch ptr)
  try {
    const scratchPtr = await client.read32(0x0035ccc8);
    snapshot.values._scratch_base = { ptr: '0x' + scratchPtr.toString(16) };
    if (scratchPtr && scratchPtr >= 0x80000 && scratchPtr < 0x2000000) {
      const small = await client.readBytes(scratchPtr, 0x14);
      snapshot.values.scratch_small_field = { addr: '0x' + scratchPtr.toString(16), size: 0x14, hex: small.toString('hex') };
      const big = await client.readBytes(scratchPtr + 0x14, 64);
      snapshot.values.scratch_big_field_start = { addr: '0x' + (scratchPtr + 0x14).toString(16), size: 64, hex: big.toString('hex') };
    }
  } catch (e) {
    snapshot.values._scratch_base = { error: e.message };
  }
  return snapshot;
}

function printSnapshot(snap) {
  console.log('═'.repeat(80));
  console.log('PINE snapshot @ ' + snap.ts);
  console.log('═'.repeat(80));
  for (const p of PROBES) {
    const v = snap.values[p.name];
    if (v.error) {
      console.log(`  ${p.name.padEnd(28)} ERROR: ${v.error}`);
      continue;
    }
    const buf = Buffer.from(v.hex, 'hex');
    console.log(`  ${p.name.padEnd(28)} ${v.addr.padEnd(14)} ${fmtBuf(p.name, buf, p.size)}`);
    console.log(`    why: ${p.why}`);
  }
  console.log('');
}

async function main() {
  console.log('Connecting to PINE @ ' + PINE_HOST + ':' + PINE_PORT + ' ...');
  const client = new PineClient({ host: PINE_HOST, port: PINE_PORT });
  await client.connect();
  try {
    const status = await client.status();
    console.log('PCSX2 status:', status.name);
    try {
      const title = await client.title();
      const serial = await client.serial();
      console.log('Title:', title, ' Serial:', serial);
    } catch (e) { console.log('(no game running)'); }
    console.log('');
    if (!watchMode) {
      const snap = await probeOnce(client);
      printSnapshot(snap);
      if (outFile) fs.appendFileSync(outFile, JSON.stringify(snap) + '\n');
      return;
    }
    let last = null;
    console.log('Watch mode — polling every 500ms. Ctrl-C to stop.');
    while (true) {
      const snap = await probeOnce(client);
      const currentJson = JSON.stringify(snap.values);
      if (currentJson !== last) {
        printSnapshot(snap);
        if (outFile) fs.appendFileSync(outFile, JSON.stringify(snap) + '\n');
        last = currentJson;
      }
      await new Promise(r => setTimeout(r, 500));
    }
  } finally {
    client.close();
  }
}

main().catch(e => { console.error('FATAL:', e.message, e.stack); process.exit(1); });
