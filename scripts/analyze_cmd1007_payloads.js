#!/usr/bin/env node
'use strict';

const fs = require('fs');
const path = require('path');

const defaultDir = 'C:\\dnas\\active\\captures';
const dir = process.argv[2] || defaultDir;
const files = fs.readdirSync(dir)
  .filter(name => /^snap_session[123]_in_1_1779087.*\.bin$/.test(name))
  .sort()
  .map(name => path.join(dir, name));

if (files.length < 3) {
  console.error(`Need three cmd 0x1007 capture files in ${dir}`);
  process.exit(1);
}

const frames = files.slice(0, 3).map(file => ({ file, buf: fs.readFileSync(file) }));
const payloads = frames.map(f => f.buf.subarray(8));

function hex(buf) {
  return [...buf].map(b => b.toString(16).padStart(2, '0')).join(' ');
}

for (const [idx, frame] of frames.entries()) {
  const b = frame.buf;
  console.log(`S${idx + 1}: ${frame.file}`);
  console.log(`  len=0x${b.readUInt16BE(0).toString(16).padStart(4, '0')} dir=0x${b[2].toString(16)} cmd=0x${b.readUInt16BE(3).toString(16)} p5=0x${b[5].toString(16)} err=0x${b[6].toString(16)} p7=0x${b[7].toString(16)}`);
  console.log(`  payload: ${hex(payloads[idx])}`);
}

console.log('\nCounter-XOR decode for payload[5..]: encoded[i] ^ ((p5 + i - 5) & 0xff)');
for (const [idx, frame] of frames.entries()) {
  const p5 = frame.buf[5];
  const decoded = Buffer.from(payloads[idx]);
  for (let i = 5; i < decoded.length; i++) {
    decoded[i] ^= (p5 + i - 5) & 0xff;
  }
  console.log(`S${idx + 1}: ${hex(decoded)}`);
}
