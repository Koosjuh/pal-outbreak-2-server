'use strict';
// G12 STEP-0 follow-up: snapshot op06 completion state via PINE.
// Reads: screen/objF/stall-tag, conn pointer, op06 send-seq (conn+0x618),
// and scans the 128-slot async completion table (0x6ca980, stride 0x20;
// per-slot keys key32@0x6ca97c+i*0x20, key16@0x6ca97e+i*0x20) for armed slots.
const { PineClient } = require('D:/projects/pal-outbreak-2-server/tools/pine/pine_client.js');

const CONN_PTR = 0x0025b78c;
const SCREEN   = 0x006c4b90;
const OBJF     = 0x006c4b9f;
const STALLTAG = 0x006c4fbb;   // cRam006c4fbb (op06-pending tag)
const SENDSEQ  = 0x0036dd78;   // conn+0x618 (op06 send-seq byte)
const TBL_KEY32 = 0x006ca97c;  // slot i key32 = TBL_KEY32 + i*0x20
const TBL_KEY16 = 0x006ca97e;  // slot i key16 = TBL_KEY16 + i*0x20

(async () => {
  const label = process.argv[2] || 'snapshot';
  const c = new PineClient({ port: 28011 });
  await c.connect();
  const st = await c.status();
  const connp = await c.read32(CONN_PTR);
  const screen = await c.read32(SCREEN);
  const objf = await c.read8(OBJF);
  const stall = await c.read8(STALLTAG);
  const seqByte = await c.read8(SENDSEQ);
  const seq32 = await c.read32(SENDSEQ);
  console.log(`\n=== [${label}] status=${st} ===`);
  console.log(`conn.ptr(0x25b78c)=0x${connp.toString(16).padStart(8,'0')}  screen(0x6c4b90)=${screen}  objF(0x6c4b9f)=${objf}  stallTag(0x6c4fbb)=${stall}`);
  console.log(`send-seq conn+0x618(0x36dd78): u8=0x${seqByte.toString(16)}  u32=0x${(seq32>>>0).toString(16)}`);
  // scan async completion table
  const armed = [];
  for (let i = 0; i < 128; i++) {
    const k32 = await c.read32(TBL_KEY32 + i*0x20) >>> 0;
    const k16 = await c.read16(TBL_KEY16 + i*0x20);
    if (k32 !== 0 || k16 !== 0) armed.push({ i, k32, k16 });
  }
  if (armed.length === 0) console.log('async table: no armed slots (all keys 0)');
  else {
    console.log(`async table: ${armed.length} armed slot(s):`);
    for (const a of armed) console.log(`  slot ${a.i.toString().padStart(3)}: key32=0x${a.k32.toString(16).padStart(8,'0')} key16=0x${a.k16.toString(16).padStart(4,'0')}`);
  }
  await c.close();
})().catch(e => { console.error('ERR', e.message); process.exit(1); });
