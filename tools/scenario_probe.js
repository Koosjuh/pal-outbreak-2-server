// scenario_probe.js — live PINE read/poke of the create-config to find + unlock the scenario byte.
// Usage (run while at the create RULE screen; STOP the harness sampler first — PINE is single-client):
//   node tools/scenario_probe.js dump 0x006970a0 0x120      # hexdump non-zero rows in a region
//   node tools/scenario_probe.js r8   0x006970a0            # read one byte
//   node tools/scenario_probe.js poke 0x006970a0 1          # write one byte (scenario id 0-6)
//   node tools/scenario_probe.js scan 0x006970a0 0x120 1    # poke each byte in region to val, 200ms apart
const { PineClient } = require('./pine/pine_client');
const H = s => parseInt(s, 16);
(async () => {
  const [, , cmd, a, b, c] = process.argv;
  const cli = new PineClient({ port: 28011, host: '127.0.0.1', timeoutMs: 4000 });
  await cli.connect();
  try {
    if (cmd === 'dump') {
      const addr = H(a), len = b ? H(b) : 0x100;
      const buf = await cli.readBytes(addr, len);
      for (let i = 0; i < len; i += 16) {
        const row = buf.slice(i, i + 16);
        if (row.some(x => x !== 0)) {
          const hex = [...row].map(x => x.toString(16).padStart(2, '0')).join(' ');
          const asc = [...row].map(x => (x >= 32 && x < 127) ? String.fromCharCode(x) : '.').join('');
          console.log((addr + i).toString(16).padStart(8, '0'), hex, '|' + asc + '|');
        }
      }
    } else if (cmd === 'r8') {
      console.log(a, '=', await cli.read8(H(a)));
    } else if (cmd === 'poke') {
      await cli.write8(H(a), parseInt(b, 10));
      console.log('poked', a, '=', b);
    } else if (cmd === 'scan') {
      // poke each byte in [addr, addr+len) to val, pausing so you can watch the screen
      const addr = H(a), len = H(b), val = parseInt(c || '1', 10);
      for (let i = 0; i < len; i++) {
        const orig = await cli.read8(addr + i);
        await cli.write8(addr + i, val);
        console.log('poked', (addr + i).toString(16), `orig=${orig} -> ${val}`);
        await new Promise(r => setTimeout(r, 250));
        await cli.write8(addr + i, orig);  // restore before next (find which one flips Scenario)
      }
    }
  } finally { cli.close(); }
})().catch(e => { console.error('ERR', e.message); process.exit(1); });
