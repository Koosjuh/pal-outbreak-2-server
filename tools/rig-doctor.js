// rig-doctor.js — one-call health check for the PCSX2 + PINE rig.
//   node tools/rig-doctor.js
// Reports PCSX2 process/window, PINE listener, auto-clears zombie PINE clients (the recurring
// "connection refused" cause), then does a REAL PINE read (the actual "is it accepting" test) and
// decodes the game screen-state. Exit 0 = HEALTHY (PINE reads), non-zero = not ready.
const { execSync } = require('child_process');
const { PineClient } = require('./pine/pine_client');
const PORT = 28011;
const ps = (cmd) => { try { return execSync(`powershell -NoProfile -Command "${cmd}"`, { encoding: 'utf8', stdio: ['ignore', 'pipe', 'ignore'] }).trim(); } catch { return ''; } };
const SCREENS = { 1: 'Area-Select', 2: 'Lobby', 6: 'connecting/transition', 0x0e: 'Room/Slot list' };

(async () => {
  const out = [];
  const count = ps(`(Get-Process -Name pcsx2-qt -ErrorAction SilentlyContinue | Measure-Object).Count`);
  const pid = ps(`(Get-Process -Name pcsx2-qt -ErrorAction SilentlyContinue | Select-Object -First 1).Id`);
  out.push(`PCSX2 process : ${count === '1' ? `UP (pid ${pid})` : (count === '0' || count === '') ? 'DOWN' : `${count} instances (!!)`}`);
  const win = ps(`(Get-Process -Name pcsx2-qt -ErrorAction SilentlyContinue | Select-Object -First 1).MainWindowTitle`);
  out.push(`PCSX2 window  : ${win || 'none'}`);
  const listener = ps(`(Get-NetTCPConnection -LocalPort ${PORT} -State Listen -ErrorAction SilentlyContinue | Measure-Object).Count`);
  out.push(`PINE listener : ${listener === '1' ? `present (:${PORT})` : `${listener || '0'} (:${PORT})`}`);
  const zc = ps(`(Get-NetTCPConnection -RemotePort ${PORT} -State Established -ErrorAction SilentlyContinue | Measure-Object).Count`);
  if (zc && zc !== '0') {
    ps(`Get-NetTCPConnection -RemotePort ${PORT} -State Established -ErrorAction SilentlyContinue | ForEach-Object { taskkill /F /PID $_.OwningProcess 2>$null | Out-Null }`);
    out.push(`PINE zombies  : ${zc} found -> CLEARED`);
    await new Promise(r => setTimeout(r, 800));
  } else out.push(`PINE zombies  : none`);
  let pineOk = false, screen = null;
  try {
    const c = new PineClient({ port: PORT, host: '127.0.0.1', timeoutMs: 3000 });
    await c.connect();
    screen = await c.read8(0x006c4b90);
    c.close();
    pineOk = true;
    out.push(`PINE read     : OK  |  screen 0x6c4b90 = ${screen} (${SCREENS[screen] || '?'})`);
  } catch (e) { out.push(`PINE read     : FAIL (${e.message})`); }
  console.log('=== RIG DOCTOR ===\n' + out.join('\n'));
  const healthy = count === '1' && pineOk;
  console.log(`\nVERDICT: ${healthy ? 'HEALTHY' : 'NOT READY'}${!healthy && count !== '1' ? '  (run: node tools/rig-launch.js)' : ''}`);
  process.exit(healthy ? 0 : 1);
})().catch(e => { console.error('doctor error:', e.message); process.exit(2); });
