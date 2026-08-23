'use strict';
// Build protocols/SUBCOMMAND_INDEX.md — op10 sub-selectors + op28 selectors extracted from records.
const fs = require('fs');
const path = require('path');
const ROOT = path.resolve(__dirname, '../..');
const fns = JSON.parse(fs.readFileSync(path.join(ROOT, 'indexes/functions.json'), 'utf8'));

const subs = {};  // key "op10 sub 0x05" -> {opcode, kind, sel, fns:[]}
const push = (opcode, kind, sel, f) => {
  const key = `${opcode} ${kind} ${sel}`;
  (subs[key] = subs[key] || { opcode, kind, sel, fns: [] }).fns.push({ addr: f.address, name: f.resolved_name || f.name, subsystem: f.subsystem, summary: f.summary });
};
const hex = (s) => s.startsWith('0x') ? s : '0x' + parseInt(s, 10).toString(16);

for (const f of fns) {
  const text = `${f.summary || ''} ${f.notes || ''}`;
  const ops = f.opcodes || [];
  // op10 sub-selectors
  for (const m of text.matchAll(/\bop?10[^.]*?sub[- ]?(?:selector[- ]?)?(0x[0-9a-f]+|\d+)/gi)) push('0x10', 'sub', hex(m[1]), f);
  for (const m of text.matchAll(/\bsub[- ]?(?:selector[- ]?)?(0x0c|0x05|0x02|0x01|0x0e|0x03|0x11|0x1)\b/gi)) if (ops.includes('0x10')) push('0x10', 'sub', hex(m[1]), f);
  // op28 selectors
  for (const m of text.matchAll(/\b(?:op)?28[^.]*?selector[- ]?(0x[0-9a-f]+|\d+)/gi)) push('0x28', 'selector', hex(m[1]), f);
  for (const m of text.matchAll(/\bselector[- ]?(0x0a|0x04|4|6|12|0x0c)\b/gi)) if (ops.includes('0x28')) push('0x28', 'selector', hex(m[1]), f);
}

const keys = Object.keys(subs).sort();
let md = `# SUBCOMMAND_INDEX — op10 sub-selectors & op28 selectors\n\n_Auto-extracted from record summaries/notes (\`gen-subcommands.js\`). Verify each against the handler record. These sub-dispatch on the app-payload selector byte within an opcode._\n\n| Opcode | Kind | Sel | Functions | Behavior (first) |\n|---|---|---|---|---|\n`;
for (const k of keys) {
  const s = subs[k];
  const first = s.fns[0];
  md += `| ${s.opcode} | ${s.kind} | ${s.sel} | ${s.fns.map(x => x.addr).join(' ')} | ${(first.summary || '').replace(/\|/g, '/').slice(0, 90)} |\n`;
}
// Write to the AUTO variant — never clobber the hand-curated protocols/SUBCOMMAND_INDEX.md.
fs.writeFileSync(path.join(ROOT, 'protocols/SUBCOMMAND_INDEX_AUTO.md'), md);
fs.writeFileSync(path.join(ROOT, 'indexes/subcommands.json'), JSON.stringify(Object.values(subs), null, 1));
console.log(`SUBCOMMAND_INDEX: ${keys.length} distinct subcommands`);
for (const k of keys) console.log(`  ${k}  (${subs[k].fns.length} fns)`);
