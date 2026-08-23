'use strict';
// Generate human-navigable Markdown indexes from the JSON corpus: GLOBALS, STRINGS, OPCODE_INDEX,
// CALL_GRAPH (subsystem entry points), and SUBSYSTEM_MAP (the "what to build" view).
const fs = require('fs');
const path = require('path');
const ROOT = path.resolve(__dirname, '../..');
const IDX = path.join(ROOT, 'indexes');
const load = (f) => { try { return JSON.parse(fs.readFileSync(path.join(IDX, f), 'utf8')); } catch { return []; } };
const fns = load('functions.json');
const nameOf = (n) => { const f = fns.find(x => x.name === n || x.address === n); return f ? (f.resolved_name || f.name) : n; };
const byName = new Map(fns.map(f => [f.name, f]));

// GLOBALS.md — hottest state first
const globals = load('globals.json').map(g => ({ ...g, n: g.referenced_by.length })).sort((a, b) => b.n - a.n);
let md = `# GLOBALS — network state variables\n\n_Auto-generated (\`gen-docs.js\`) from indexes/globals.json. ${globals.length} globals, sorted by reference count._\n\n| Address | #refs | Tags (agent-observed) | Referencing fns (first 8) |\n|---|---|---|---|\n`;
for (const g of globals) md += `| ${g.address} | ${g.n} | ${(g.tags||[]).slice(0,3).join('; ').replace(/\|/g,'/').slice(0,80)} | ${g.referenced_by.slice(0,8).join(' ')} |\n`;
fs.writeFileSync(path.join(ROOT, 'GLOBALS.md'), md);

// STRINGS.md
const strings = load('strings.json');
md = `# STRINGS — network-referenced strings\n\n_Auto-generated from indexes/strings.json. ${strings.length} strings._\n\n| String | Referencing fns |\n|---|---|\n`;
for (const s of strings) md += `| \`${String(s.string).replace(/\|/g,'/').slice(0,60)}\` | ${s.referenced_by.join(' ')} |\n`;
fs.writeFileSync(path.join(ROOT, 'STRINGS.md'), md);

// OPCODE_INDEX.md — builder/parser/handler chain per opcode
const ops = load('opcodes_seen.json').sort((a, b) => (a.opcode > b.opcode ? 1 : -1));
const role = (summary) => {
  const s = (summary || '').toLowerCase();
  if (/build|send|emit|encode|writes.*packet|serial/.test(s)) return 'builder';
  if (/parse|decode|reads.*packet|deserial/.test(s)) return 'parser';
  if (/dispatch|route|switch on|selector/.test(s)) return 'dispatcher';
  if (/handle|handler|process/.test(s)) return 'handler';
  return '';
};
md = `# OPCODE_INDEX — functions touching each opcode\n\n_Auto-generated from indexes/opcodes_seen.json. Role inferred from summary keywords (verify per record)._\n\n`;
for (const o of ops) {
  md += `## ${o.opcode}\n\n| Function | Subsystem | Inferred role | \n|---|---|---|\n`;
  for (const f of o.functions) {
    const rec = fns.find(x => x.address === f.addr);
    md += `| ${f.addr} ${rec?.resolved_name||f.name} | ${f.subsystem} | ${role(rec?.summary)} |\n`;
  }
  md += `\n`;
}
fs.writeFileSync(path.join(ROOT, 'protocols/OPCODE_INDEX.md'), md);

// SUBSYSTEM_MAP.md — the "what to build" view: per subsystem, core functions + summaries
const subs = {};
for (const f of fns) (subs[f.subsystem] = subs[f.subsystem] || []).push(f);
md = `# SUBSYSTEM_MAP — network functions grouped by subsystem\n\n_Auto-generated. Per subsystem: count, then the CORE functions (relevance=core) with one-line behavior. The build guide: to make a protocol path work, satisfy what these core functions expect._\n\n`;
for (const [sub, list] of Object.entries(subs).sort((a,b)=>b[1].length-a[1].length)) {
  const core = list.filter(f => f.relevance === 'core');
  md += `## ${sub}  (${list.length} fns, ${core.length} core)\n\n`;
  for (const f of core.sort((a,b)=>a.address.localeCompare(b.address))) {
    md += `- **${f.address} ${f.resolved_name||f.name}** [${f.confidence}] — ${f.summary||''}\n`;
  }
  md += `\n`;
}
fs.writeFileSync(path.join(ROOT, 'SUBSYSTEM_MAP.md'), md);

// CALL_GRAPH.md — top hubs (most-called + most-calling)
const xr = load('cross_references.json');
const hubs = Object.entries(xr).map(([n, v]) => ({ n, in: (v.callers||[]).length, out: (v.callees||[]).length }))
  .sort((a, b) => (b.in + b.out) - (a.in + a.out)).slice(0, 60);
md = `# CALL_GRAPH — hub functions (most connected)\n\n_Auto-generated from indexes/cross_references.json. Full adjacency there; edges in generated/callgraphs/edges.json._\n\n| Function | Resolved | #callers | #callees |\n|---|---|---|---|\n`;
for (const h of hubs) md += `| ${h.n} | ${nameOf(h.n)} | ${h.in} | ${h.out} |\n`;
fs.writeFileSync(path.join(ROOT, 'CALL_GRAPH.md'), md);

console.log(`docs: GLOBALS(${globals.length}) STRINGS(${strings.length}) OPCODE_INDEX(${ops.length}) SUBSYSTEM_MAP(${Object.keys(subs).length} subs) CALL_GRAPH(60 hubs)`);
