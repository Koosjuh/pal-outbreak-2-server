'use strict';
// Build PACKET_INDEX.md + packets.json and MENU_INDEX.md + menus.json from the classified corpus.
const fs = require('fs');
const path = require('path');
const ROOT = path.resolve(__dirname, '../..');
const IDX = path.join(ROOT, 'indexes');
const load = (f) => { try { return JSON.parse(fs.readFileSync(path.join(IDX, f), 'utf8')); } catch { return []; } };
const fns = load('functions.json');
const byName = new Map(fns.map(f => [f.name, f]));
const byAddr = new Map(fns.map(f => [f.address, f]));
const disp = (n) => { const f = byName.get(n) || byAddr.get(n); return f ? `${f.address} ${f.resolved_name || f.name}` : n; };
const s = (f) => (f.summary || '').toLowerCase();

// ---- PACKET_INDEX ----
const ops = load('opcodes_seen.json').sort((a, b) => (a.opcode > b.opcode ? 1 : -1));
const roleOf = (f) => {
  const t = s(f);
  if (/build|emit|send|encode|transmit|writes.*packet|serial|request/.test(t)) return 'builder';
  if (/parse|decode|reads.*packet|reply|recv|receive|deserial|handler|handle/.test(t)) return 'parser/handler';
  if (/dispatch|route|switch on|selector/.test(t)) return 'dispatcher';
  return 'ref';
};
const dirOf = (f) => { const t = s(f); if (/reply|recv|receive|parse|inbound|response/.test(t)) return 'S->C'; if (/build|emit|send|request|transmit|outbound/.test(t)) return 'C->S'; return '?'; };
const packets = [];
let md = `# PACKET_INDEX — opcodes → builder / parser / handler chains\n\n_Auto-generated from the classified corpus (\`gen-protocol-menu.js\`). Roles/direction inferred from behavior summaries; verify per record. This is the client-side protocol contract the server must satisfy._\n\n| Opcode | Dir | Builder (C->S) | Parser/Handler (S->C) | Dispatcher | # fns |\n|---|---|---|---|---|---|\n`;
for (const o of ops) {
  const list = o.functions.map(x => byAddr.get(x.addr)).filter(Boolean);
  const builders = list.filter(f => roleOf(f) === 'builder');
  const parsers = list.filter(f => roleOf(f) === 'parser/handler');
  const dispatchers = list.filter(f => roleOf(f) === 'dispatcher');
  const dir = [...new Set(list.map(dirOf).filter(d => d !== '?'))].join('/') || '?';
  md += `| \`${o.opcode}\` | ${dir} | ${builders.map(f => f.address).join(' ') || '—'} | ${parsers.map(f => f.address).join(' ') || '—'} | ${dispatchers.map(f => f.address).join(' ') || '—'} | ${list.length} |\n`;
  packets.push({ opcode: o.opcode, direction: dir, builders: builders.map(f => ({ addr: f.address, name: f.resolved_name || f.name, summary: f.summary })), parsers_handlers: parsers.map(f => ({ addr: f.address, name: f.resolved_name || f.name, summary: f.summary })), dispatchers: dispatchers.map(f => ({ addr: f.address, name: f.resolved_name || f.name })), all_refs: list.map(f => f.address) });
}
// Detail sections
md += `\n---\n\n## Per-opcode detail\n`;
for (const p of packets) {
  md += `\n### \`${p.opcode}\`  (${p.direction})\n`;
  if (p.builders.length) md += `**Builders (C->S):**\n` + p.builders.map(b => `- ${b.addr} ${b.name} — ${b.summary || ''}`).join('\n') + '\n';
  if (p.parsers_handlers.length) md += `**Parsers/Handlers (S->C):**\n` + p.parsers_handlers.map(b => `- ${b.addr} ${b.name} — ${b.summary || ''}`).join('\n') + '\n';
  if (p.dispatchers.length) md += `**Dispatchers:** ${p.dispatchers.map(d => `${d.addr} ${d.name}`).join(', ')}\n`;
}
fs.writeFileSync(path.join(ROOT, 'protocols/PACKET_INDEX.md'), md);
fs.writeFileSync(path.join(IDX, 'packets.json'), JSON.stringify(packets, null, 1));

// ---- MENU_INDEX ---- from the two screen dispatchers' switch targets
const menus = [];
function screensFrom(dispName, stateVar, label) {
  const d = byName.get(dispName); if (!d) return;
  for (const callee of (d.callees || [])) {
    const f = byName.get(callee); if (!f) continue;
    if (!['menus', 'lobby', 'rooms', 'roster', 'chat', 'session'].includes(f.subsystem)) continue;
    menus.push({ dispatcher: `${d.address} ${d.resolved_name || d.name}`, state_var: stateVar, group: label, handler: f.address, name: f.resolved_name || f.name, subsystem: f.subsystem, summary: f.summary, opcodes: f.opcodes || [] });
  }
}
screensFrom('FUN_005ac8a0', '0x6c4faa (top screen)', 'top-menu');       // menu_top_dispatch
screensFrom('FUN_005acab0', '0x6c4b90 (lobby sub-screen)', 'lobby');    // lobby_screen_dispatch
md = `# MENU_INDEX — network screens & their handlers\n\n_Auto-generated. Screens = switch targets of the two overlay dispatchers: menu_top_dispatch (state 0x6c4faa) and lobby_screen_dispatch (state 0x6c4b90). Each handler is one screen/step._\n\n| Group | State var | Handler | Subsystem | Opcodes | Behavior |\n|---|---|---|---|---|---|\n`;
for (const m of menus) md += `| ${m.group} | ${m.state_var} | ${m.handler} ${m.name} | ${m.subsystem} | ${(m.opcodes||[]).join(' ')||'—'} | ${(m.summary||'').replace(/\|/g,'/').slice(0,90)} |\n`;
fs.writeFileSync(path.join(ROOT, 'menus/MENU_INDEX.md'), md);
fs.writeFileSync(path.join(IDX, 'menus.json'), JSON.stringify(menus, null, 1));

console.log(`PACKET_INDEX: ${packets.length} opcodes; MENU_INDEX: ${menus.length} screen handlers`);
