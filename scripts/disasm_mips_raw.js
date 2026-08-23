#!/usr/bin/env node
// Minimal little-endian MIPS disassembler for raw EE runtime dumps.
// Usage: node scripts/tools/codex/disasm_mips_raw.js <file> <base_hex> <start_hex> <count_hex>

const fs = require('fs');

const [file, baseArg, startArg, countArg] = process.argv.slice(2);
if (!file || !baseArg || !startArg || !countArg) {
  console.error('Usage: node disasm_mips_raw.js <file> <base_hex> <start_hex> <count_hex>');
  process.exit(1);
}

const base = Number(baseArg);
const start = Number(startArg);
const count = Number(countArg);
const buf = fs.readFileSync(file);

const reg = [
  'zero','at','v0','v1','a0','a1','a2','a3',
  't0','t1','t2','t3','t4','t5','t6','t7',
  's0','s1','s2','s3','s4','s5','s6','s7',
  't8','t9','k0','k1','gp','sp','fp','ra'
];

function hex(n, w = 8) {
  return '0x' + (n >>> 0).toString(16).padStart(w, '0');
}

function simm(v) {
  v &= 0xffff;
  return v & 0x8000 ? v - 0x10000 : v;
}

function zimm(v) {
  return v & 0xffff;
}

function offTarget(pc, imm) {
  return (pc + 4 + (simm(imm) << 2)) >>> 0;
}

function jTarget(pc, idx) {
  return (((pc + 4) & 0xf0000000) | ((idx & 0x03ffffff) << 2)) >>> 0;
}

function dis(pc, w) {
  if (w === 0) return 'nop';
  const op = w >>> 26;
  const rs = (w >>> 21) & 31;
  const rt = (w >>> 16) & 31;
  const rd = (w >>> 11) & 31;
  const sh = (w >>> 6) & 31;
  const fn = w & 63;
  const imm = w & 0xffff;
  const idx = w & 0x03ffffff;

  if (op === 0x00) {
    switch (fn) {
      case 0x08: return `jr ${reg[rs]}`;
      case 0x09: return `jalr ${reg[rd]}, ${reg[rs]}`;
      case 0x20: return `add ${reg[rd]}, ${reg[rs]}, ${reg[rt]}`;
      case 0x21: return `addu ${reg[rd]}, ${reg[rs]}, ${reg[rt]}`;
      case 0x22: return `sub ${reg[rd]}, ${reg[rs]}, ${reg[rt]}`;
      case 0x23: return `subu ${reg[rd]}, ${reg[rs]}, ${reg[rt]}`;
      case 0x24: return `and ${reg[rd]}, ${reg[rs]}, ${reg[rt]}`;
      case 0x25: return `or ${reg[rd]}, ${reg[rs]}, ${reg[rt]}`;
      case 0x26: return `xor ${reg[rd]}, ${reg[rs]}, ${reg[rt]}`;
      case 0x27: return `nor ${reg[rd]}, ${reg[rs]}, ${reg[rt]}`;
      case 0x2d: return `daddu ${reg[rd]}, ${reg[rs]}, ${reg[rt]}`;
      case 0x2a: return `slt ${reg[rd]}, ${reg[rs]}, ${reg[rt]}`;
      case 0x00: return `sll ${reg[rd]}, ${reg[rt]}, ${sh}`;
      case 0x02: return `srl ${reg[rd]}, ${reg[rt]}, ${sh}`;
      case 0x03: return `sra ${reg[rd]}, ${reg[rt]}, ${sh}`;
      case 0x04: return `sllv ${reg[rd]}, ${reg[rt]}, ${reg[rs]}`;
      case 0x06: return `srlv ${reg[rd]}, ${reg[rt]}, ${reg[rs]}`;
      case 0x07: return `srav ${reg[rd]}, ${reg[rt]}, ${reg[rs]}`;
      default: return `special_${fn.toString(16)} ${hex(w)}`;
    }
  }

  if (op === 0x01) {
    switch (rt) {
      case 0x00: return `bltz ${reg[rs]}, ${hex(offTarget(pc, imm))}`;
      case 0x01: return `bgez ${reg[rs]}, ${hex(offTarget(pc, imm))}`;
      default: return `regimm_${rt.toString(16)} ${reg[rs]}, ${hex(offTarget(pc, imm))}`;
    }
  }

  switch (op) {
    case 0x02: return `j ${hex(jTarget(pc, idx))}`;
    case 0x03: return `jal ${hex(jTarget(pc, idx))}`;
    case 0x04: return `beq ${reg[rs]}, ${reg[rt]}, ${hex(offTarget(pc, imm))}`;
    case 0x05: return `bne ${reg[rs]}, ${reg[rt]}, ${hex(offTarget(pc, imm))}`;
    case 0x06: return `blez ${reg[rs]}, ${hex(offTarget(pc, imm))}`;
    case 0x07: return `bgtz ${reg[rs]}, ${hex(offTarget(pc, imm))}`;
    case 0x08: return `addi ${reg[rt]}, ${reg[rs]}, ${simm(imm)}`;
    case 0x09: return `addiu ${reg[rt]}, ${reg[rs]}, ${simm(imm)}`;
    case 0x0a: return `slti ${reg[rt]}, ${reg[rs]}, ${simm(imm)}`;
    case 0x0b: return `sltiu ${reg[rt]}, ${reg[rs]}, ${simm(imm)}`;
    case 0x0c: return `andi ${reg[rt]}, ${reg[rs]}, ${hex(zimm(imm), 4)}`;
    case 0x0d: return `ori ${reg[rt]}, ${reg[rs]}, ${hex(zimm(imm), 4)}`;
    case 0x0e: return `xori ${reg[rt]}, ${reg[rs]}, ${hex(zimm(imm), 4)}`;
    case 0x0f: return `lui ${reg[rt]}, ${hex(zimm(imm), 4)}`;
    case 0x19: return `daddiu ${reg[rt]}, ${reg[rs]}, ${simm(imm)}`;
    case 0x1e: return `lq ${reg[rt]}, ${simm(imm)}(${reg[rs]})`;
    case 0x1f: return `sq ${reg[rt]}, ${simm(imm)}(${reg[rs]})`;
    case 0x20: return `lb ${reg[rt]}, ${simm(imm)}(${reg[rs]})`;
    case 0x21: return `lh ${reg[rt]}, ${simm(imm)}(${reg[rs]})`;
    case 0x23: return `lw ${reg[rt]}, ${simm(imm)}(${reg[rs]})`;
    case 0x24: return `lbu ${reg[rt]}, ${simm(imm)}(${reg[rs]})`;
    case 0x25: return `lhu ${reg[rt]}, ${simm(imm)}(${reg[rs]})`;
    case 0x28: return `sb ${reg[rt]}, ${simm(imm)}(${reg[rs]})`;
    case 0x29: return `sh ${reg[rt]}, ${simm(imm)}(${reg[rs]})`;
    case 0x2b: return `sw ${reg[rt]}, ${simm(imm)}(${reg[rs]})`;
    case 0x37: return `ld ${reg[rt]}, ${simm(imm)}(${reg[rs]})`;
    case 0x3f: return `sd ${reg[rt]}, ${simm(imm)}(${reg[rs]})`;
    default: return `op_${op.toString(16)} ${hex(w)}`;
  }
}

const startOff = start - base;
for (let off = startOff; off < startOff + count; off += 4) {
  if (off < 0 || off + 4 > buf.length) break;
  const pc = base + off;
  const w = buf.readUInt32LE(off);
  const bytes = [...buf.slice(off, off + 4)].map(b => b.toString(16).padStart(2, '0')).join(' ');
  console.log(`${hex(pc)}  ${bytes.padEnd(11)}  ${hex(w)}  ${dis(pc, w)}`);
}
