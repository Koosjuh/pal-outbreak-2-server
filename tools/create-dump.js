// create-dump.js — labeled dump of the create-screen / scenario state via PINE.
//   node tools/create-dump.js
// One command that reads every create-config / scenario address WITH labels, instead of hand-crafting
// probe reads each time. Clears zombie PINE clients first. Addresses per LOBBY-UNIFIED-ARCHITECTURE-RE.
const { execSync } = require('child_process');
const { PineClient } = require('./pine/pine_client');
const PORT = 28011;
const ps = (cmd) => { try { return execSync(`powershell -NoProfile -Command "${cmd}"`, { encoding: 'utf8', stdio: ['ignore', 'pipe', 'ignore'] }).trim(); } catch { return ''; } };
const hex = (b) => [...b].map(x => x.toString(16).padStart(2, '0')).join(' ');
const SCREENS = { 1: 'Area-Select', 2: 'Lobby', 6: 'connecting/transition', 0x0e: 'Room/Slot list' };

(async () => {
  ps(`Get-NetTCPConnection -RemotePort ${PORT} -State Established -ErrorAction SilentlyContinue | ForEach-Object { taskkill /F /PID $_.OwningProcess 2>$null | Out-Null }`);
  await new Promise(r => setTimeout(r, 600));
  const c = new PineClient({ port: PORT, host: '127.0.0.1', timeoutMs: 4000 });
  await c.connect();
  const rd = async (a, n) => hex(await c.readBytes(a, n));
  const s = await c.read8(0x006c4b90);
  console.log('=== CREATE / SCENARIO STATE (labeled) ===');
  console.log(`screen-state  0x6c4b90 = ${s} (${SCREENS[s] || '?'})   sub 0x6c4b9e = ${await c.read8(0x006c4b9e)}`);
  console.log(`area rec0 hdr 0x361a70 (+0x03 = scenario-group bitmask, server-controllable):`);
  console.log(`   ${await rd(0x00361a70, 0x10)}`);
  console.log(`0x341ac8 per-group scenario table (bytes 0-7=groups; nonzero=scenarios present; network-only):`);
  console.log(`   ${await rd(0x00341ac8, 0x10)}`);
  console.log(`0x6c4bac scenario array (FUN_005fe300 output; (group,scenario) entries -> title via func_0x001b6950):`);
  console.log(`   ${await rd(0x006c4bac, 0x30)}`);
  c.close();
  console.log('\nReminder: 0x341ac8/0x6c4bac only meaningful once at the in-area lobby / create RULE screen.');
})().catch(e => { console.error('dump error:', e.message); process.exit(1); });
