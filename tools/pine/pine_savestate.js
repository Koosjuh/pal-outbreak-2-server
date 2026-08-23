// Tiny helper: trigger PCSX2 save-state via PINE.
//   node tools/pine_savestate.js save <slot>   → MsgSaveState(slot)
//   node tools/pine_savestate.js load <slot>   → MsgLoadState(slot)
//   node tools/pine_savestate.js status        → query Running/Paused/Shutdown
//   node tools/pine_savestate.js title         → game title

'use strict';
const path = require('path');
const { PineClient } = require(path.resolve(__dirname, 'pine_client'));

const cmd = process.argv[2];
const slot = Number(process.argv[3] || 9);

(async () => {
  const c = new PineClient({ port: 28011, timeoutMs: 8000 });
  await c.connect();
  switch (cmd) {
    case 'save':
      console.log('Triggering MsgSaveState slot', slot, '...');
      try { await c.saveState(slot); console.log('OK — PCSX2 should have written savestate', slot); }
      catch (e) { console.error('save failed:', e.message); process.exit(1); }
      break;
    case 'load':
      console.log('Triggering MsgLoadState slot', slot, '...');
      try { await c.loadState(slot); console.log('OK — PCSX2 should have loaded savestate', slot); }
      catch (e) { console.error('load failed:', e.message); process.exit(1); }
      break;
    case 'status': {
      const s = await c.status();
      console.log('Status:', s.name, '(code', s.code + ')');
      break;
    }
    case 'title': {
      const t = await c.title();
      console.log('Title:', t);
      break;
    }
    default:
      console.error('usage: pine_savestate.js <save|load|status|title> [slot]');
      process.exit(2);
  }
  try { c.close(); } catch {}
})().catch(e => { console.error('error:', e.message); process.exit(1); });
