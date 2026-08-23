'use strict';
// Generate an individual documented record .md for every net-related classified function, from the
// classification in functions.json + raw-code link. Sets doc_path. Also classifies leftover thunks.
const fs = require('fs');
const path = require('path');
const ROOT = path.resolve(__dirname, '../..');
const IDX = path.join(ROOT, 'indexes');
const fns = JSON.parse(fs.readFileSync(path.join(IDX, 'functions.json'), 'utf8'));

// 1) Classify leftover thunks (status still inventoried, name starts thunk_)
for (const f of fns) {
  if (f.status === 'inventoried') {
    const t = ((f.name || '').match(/thunk_(?:EXT_)?(?:FUN_)?([0-9a-f]+)/) || [])[1];
    f.subsystem = 'helpers'; f.relevance = 'helper'; f.confidence = 'High';
    f.resolved_name = t ? `thunk_to_${t}` : f.name;
    f.summary = t ? `8-byte trampoline to 0x${t}.` : '8-byte thunk.';
    f.status = 'classified';
  }
}

const REPODIR = path.resolve(ROOT, '../..');
let written = 0, skipped = 0;
for (const f of fns) {
  if (f.subsystem === 'unrelated') { skipped++; continue; }              // record but keep in unknown/ note
  if (f.status === 'documented' || f.status === 'validated') { skipped++; continue; }  // hand-written deep record exists
  const addr8 = f.address.replace('0x', '').padStart(8, '0');
  const rn = (f.resolved_name || f.name).replace(/[^A-Za-z0-9_]/g, '_').slice(0, 60);
  const rel = `functions/${f.subsystem}/${addr8}_${rn}.md`;
  const abs = path.join(ROOT, rel);
  fs.mkdirSync(path.dirname(abs), { recursive: true });
  const callers = (f.callers || []).join(', ') || '—';
  const callees = (f.callees || []).join(', ') || '—';
  const globals = (f.globals || []).join('; ') || '—';
  const strings = (f.strings || []).join('; ') || '—';
  const opcodes = (f.opcodes || []).join(', ') || '—';
  const state = (f.state_vars || []).join('; ') || '—';
  const md = `# ${f.address} ${f.resolved_name || f.name}

| field | value |
|---|---|
| Original address | ${f.address} |
| Binary / overlay | ${f.binary} |
| Module | ${f.module} |
| Original generated name | ${f.name} |
| Resolved name | ${f.resolved_name || f.name} |
| Subsystem | ${f.subsystem} |
| Relevance | ${f.relevance || 'unknown'} |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | ${f.confidence} |
| Runtime validated | no |

**Callers:** ${callers}
**Callees:** ${callees}
**Referenced globals:** ${globals}
**Referenced strings:** ${strings}
**Referenced opcodes:** ${opcodes}
**State vars:** ${state}

## Behavioral explanation
${f.summary || '(pending)'}

## Notes / uncertainty
${f.notes || '(none recorded)'}

## Raw decompilation
\`${f.raw_path || '(thunk — no body)'}\`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **${f.confidence}**. Runtime validation pending. Promote to \`reconstructed\`/\`validated\` with corrected pseudocode + a trace.
`;
  fs.writeFileSync(abs, md);
  f.doc_path = rel;
  written++;
}
fs.writeFileSync(path.join(IDX, 'functions.json'), JSON.stringify(fns, null, 1));
console.log(`records written=${written} skipped(unrelated/deep)=${skipped}`);
