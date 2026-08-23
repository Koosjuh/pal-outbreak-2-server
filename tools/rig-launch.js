// rig-launch.js — bring up a clean, persistent, PINE-able PCSX2.
//   node tools/rig-launch.js
// Kills stale PCSX2 / PINE zombies / vpad daemon, launches PCSX2 INDEPENDENTLY (detached — survives
// node & harness exits, unlike `--poke`/child launches), then polls until PINE binds + accepts a real
// read. No virtual pad started, so a physical PS4/DS controller enumerates as SDL-0 (= Pad1).
const { execSync, spawn } = require('child_process');
const { PineClient } = require('./pine/pine_client');
const PORT = 28011;
const ps = (cmd) => { try { return execSync(`powershell -NoProfile -Command "${cmd}"`, { encoding: 'utf8', stdio: ['ignore', 'pipe', 'ignore'] }).trim(); } catch { return ''; } };
// Launch via a clean-named hardlink (created once) — the real filename's spaces/#/() mangle through
// the launch arg chain. Recreate with: New-Item -ItemType HardLink C:\dnas\iso\ob2.iso -Target <realiso>
const ISO = 'C:\\dnas\\iso\\ob2.iso';
const EXE = 'D:\\projects\\pal-outbreak-2-server\\vendor\\pcsx2\\pcsx2-qt.exe';
const WORKDIR = 'D:\\projects\\pal-outbreak-2-server\\vendor\\pcsx2';

(async () => {
  console.log('[rig-launch] killing stale PCSX2 / PINE zombies / vpad daemon...');
  ps(`taskkill /F /IM pcsx2-qt.exe 2>$null | Out-Null; taskkill /F /IM dumpcap.exe 2>$null | Out-Null; taskkill /F /IM python.exe 2>$null | Out-Null; Get-NetTCPConnection -RemotePort ${PORT} -ErrorAction SilentlyContinue | ForEach-Object { taskkill /F /PID $_.OwningProcess 2>$null | Out-Null }`);
  await new Promise(r => setTimeout(r, 3000));
  console.log('[rig-launch] launching PCSX2 (independent/detached) via spawn — no shell escaping...');
  // spawn with a clean args array: the ISO path (spaces/#/parens) passes as ONE literal arg with no
  // shell mangling. detached+unref makes PCSX2 survive this process exiting (unlike a plain child).
  const child = spawn(EXE, ['-fastboot', '--', ISO], { detached: true, stdio: 'ignore', cwd: WORKDIR });
  child.unref();
  process.stdout.write('[rig-launch] waiting for PINE to bind + accept');
  for (let i = 0; i < 24; i++) {
    await new Promise(r => setTimeout(r, 5000));
    process.stdout.write('.');
    try {
      const c = new PineClient({ port: PORT, host: '127.0.0.1', timeoutMs: 3000 });
      await c.connect();
      const s = await c.read8(0x006c4b90);
      c.close();
      // Boot sanity check: PINE binds even at a BIOS/ISO-error screen, so confirm the GAME window is up.
      const title = ps(`(Get-Process -Name pcsx2-qt -ErrorAction SilentlyContinue | Select-Object -First 1).MainWindowTitle`);
      const booted = /Resident Evil Outbreak/i.test(title);
      console.log(`\n[rig-launch] PINE up after ~${(i + 1) * 5}s (screen 0x6c4b90=${s}). Window: "${title}"`);
      if (booted) {
        console.log('[rig-launch] BOOTED OK — game window present. RIG HEALTHY. Sign in with your controller; `node tools/rig-doctor.js` re-checks any time.');
        process.exit(0);
      }
      console.log('[rig-launch] WARN: PINE bound but the window is not the game — ISO likely failed to load (check for an error dialog).');
      process.exit(1);
    } catch { /* keep polling; a timed-out connect leaves no zombie */ }
  }
  console.log('\n[rig-launch] PINE did not come up within ~120s — inspect PCSX2 manually.');
  process.exit(1);
})().catch(e => { console.error('launch error:', e.message); process.exit(2); });
