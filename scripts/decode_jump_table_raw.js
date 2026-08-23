#!/usr/bin/env node
// Decode little-endian 32-bit jump table entries from a raw runtime dump.
// Usage: node scripts/tools/codex/decode_jump_table_raw.js <file> <base_hex> <table_hex> <entries_dec>

const fs = require('fs');

const [file, baseArg, tableArg, entriesArg] = process.argv.slice(2);
if (!file || !baseArg || !tableArg || !entriesArg) {
  console.error('Usage: node decode_jump_table_raw.js <file> <base_hex> <table_hex> <entries_dec>');
  process.exit(1);
}

const base = Number(baseArg);
const table = Number(tableArg);
const entries = Number(entriesArg);
const buf = fs.readFileSync(file);
const offset = table - base;

if (!Number.isFinite(offset) || offset < 0 || offset + entries * 4 > buf.length) {
  console.error(`Table ${hex(table)} is outside ${file} mapped at ${hex(base)} (${buf.length} bytes)`);
  process.exit(1);
}

function hex(n, width = 8) {
  return '0x' + (n >>> 0).toString(16).padStart(width, '0');
}

for (let i = 0; i < entries; i += 1) {
  const entryOff = offset + i * 4;
  const value = buf.readUInt32LE(entryOff);
  console.log(`${i.toString().padStart(2, ' ')}  ${hex(table + i * 4)}  ${hex(value)}`);
}
