/**
 * PAL Outbreak File #2 — combined server launcher.
 * Starts DNS (:53), DNAS (:443), HTTP (:80) and SN@P (:10127)
 * in a single Node process so one terminal window shows everything.
 *
 * Must be run as Administrator (ports 53, 80, 443 require it).
 */
'use strict';
const { spawn, spawnSync } = require('child_process');
const path = require('path');
process.chdir(__dirname);

// ── colour helpers ──────────────────────────────────────────────────────────
const C = {
  reset:  '\x1b[0m',
  bold:   '\x1b[1m',
  dim:    '\x1b[2m',
  navy:   '\x1b[34m',
  blue:   '\x1b[94m',
  gold:   '\x1b[93m',
  grey:   '\x1b[37m',
  green:  '\x1b[32m',
  red:    '\x1b[31m',
  yellow: '\x1b[33m',
  cyan:   '\x1b[96m',
};
const bar  = (ch = '═', n = 70) => C.navy + ch.repeat(n) + C.reset;
const tag  = (label, col = C.cyan) => `${col}[${label}]${C.reset}`;
const ok   = name => `${tag('OK ', C.green)} ${C.gold}${name}${C.reset}`;
const fail = (name, msg) => `${tag('ERR', C.red)} ${C.gold}${name}${C.reset}  ${C.dim}${msg}${C.reset}`;

// ── banner ──────────────────────────────────────────────────────────────────
console.log('');
console.log(bar());
console.log(`${C.bold}${C.gold}  RESIDENT EVIL OUTBREAK FILE #2 — PAL SERVER STACK${C.reset}`);
console.log(bar('─'));
console.log(`${C.grey}  DNS :53  DNAS :443  HTTP :80  SN@P :10127  GAME :9090/udp${C.reset}`);
console.log(bar());
console.log('');
console.log(`${C.dim}  Protocol coverage (2026-05-30):${C.reset}`);
console.log(`${C.dim}    SN@P 0x6103/0x6104 chunk-list (SPRITE/IMAGE data, not lobby struct)${C.reset}`);
console.log(`${C.dim}    SN@P 0x6105/0x6320 status/message table (inert, 1 entry)${C.reset}`);
console.log(`${C.dim}    SN@P 0x6401/0x6402 chunk-list-no-key (safety net, major-mode 4)${C.reset}`);
console.log(`${C.dim}    SN@P 0x1004 POST_LOBBY_ACK (empty success)${C.reset}`);
console.log(`${C.dim}    UDP 9090 game-server (register/slot1c-push/op48/post-op48-push)${C.reset}`);
console.log(`${C.dim}  Real blockers (per 2026-05-30 RE):${C.reset}`);
console.log(`${C.red}    Lobby-entry struct comes from disc (NETBIO00.DAT), not SN@P${C.reset}`);
console.log(`${C.red}    Press-X reads struct +0x300 hostname → uRam0035ba98 → DNS resolve${C.reset}`);
console.log(`${C.red}    On-disc hostname unknown; needs pktmon capture during press-X${C.reset}`);
console.log(`${C.red}    DNS UDP 53 owned by UniFi (our dns_server.js EADDRINUSE); UniFi NXDOMAINs unknown hosts${C.reset}`);
console.log(`${C.red}    Press-X connect uses port 0xcaf3 (51955) — not in current listener list${C.reset}`);
console.log('');

// ── load all four servers ───────────────────────────────────────────────────
const modules = [
  { label: 'DNS   :53  ',     file: './dns_server.js'     },
  { label: 'DNAS  :443 ',     file: './dnas_server.js'    },
  { label: 'HTTP  :80  ',     file: './http_server.js'    },
  { label: 'SN@P  :10127',    file: './snap_server.js'    },
  { label: 'GAME  :9090/udp', file: './game_udp_server.js' },
  { label: 'SNOOP :38745+',   file: './snoop_listener.js' },
];

for (const m of modules) {
  try {
    require(m.file);
    // Each server prints its own listen() confirmation; just mark it as loaded.
  } catch (e) {
    console.log(fail(m.label, e.message));
  }
}

// ── auto-start pktmon capture ───────────────────────────────────────────────
// Captures ALL IPv4 + ARP traffic to a rotating ETL/PCAPNG so the user has
// a full LAN-side packet log of every test session without remembering to
// arm pktmon manually. Default ON. Set PKTMON_AUTO=0 to disable.
// On Ctrl-C, the stop script runs to flush + convert to .pcapng.
const PKTMON_AUTO = process.env.PKTMON_AUTO !== '0';
let pktmonStarted = false;
if (PKTMON_AUTO) {
  const startScript = path.join(__dirname, 'start_pktmon_capture.ps1');
  const r = spawnSync('powershell.exe',
    ['-NoProfile', '-ExecutionPolicy', 'Bypass', '-File', startScript],
    { stdio: ['ignore', 'pipe', 'pipe'], windowsHide: true });
  const out = (r.stdout || '').toString().trim();
  const err = (r.stderr || '').toString().trim();
  if (r.status === 0) {
    pktmonStarted = true;
    console.log(`${tag('OK ', C.green)} pktmon: capture started`);
    for (const line of out.split(/\r?\n/)) if (line.trim()) console.log(`${C.dim}    ${line}${C.reset}`);
  } else {
    console.log(`${tag('!! ', C.yellow)} pktmon auto-start failed (need Admin?): ${err || out}`);
  }
}

// ── ready line ──────────────────────────────────────────────────────────────
console.log('');
console.log(bar('─'));
console.log(`${C.gold}  All servers loaded. Press Ctrl-C to stop.${C.reset}`);
console.log(bar('─'));
console.log('');

// ── stop pktmon on exit ─────────────────────────────────────────────────────
function stopPktmonSync() {
  if (!pktmonStarted) return;
  const stopScript = path.join(__dirname, 'stop_pktmon_capture.ps1');
  const r = spawnSync('powershell.exe',
    ['-NoProfile', '-ExecutionPolicy', 'Bypass', '-File', stopScript],
    { stdio: ['ignore', 'pipe', 'pipe'], windowsHide: true });
  const out = (r.stdout || '').toString().trim();
  console.log(`${C.cyan}pktmon: capture stopped${C.reset}`);
  for (const line of out.split(/\r?\n/)) if (line.trim()) console.log(`${C.dim}    ${line}${C.reset}`);
}

// ── keep process alive and handle Ctrl-C cleanly ────────────────────────────
process.on('SIGINT', () => {
  console.log(`\n${bar('─')}`);
  console.log(`${C.yellow}  Shutting down.${C.reset}`);
  console.log(bar('─'));
  stopPktmonSync();
  process.exit(0);
});
process.on('SIGTERM', () => { stopPktmonSync(); process.exit(0); });
process.on('exit', () => { /* sync stop already handled above */ });

process.on('uncaughtException', err => {
  console.log(`${tag('!!', C.red)} Uncaught exception: ${err.message}`);
  console.log(err.stack);
});
