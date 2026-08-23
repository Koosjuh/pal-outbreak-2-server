/**
 * Snoop UDP listener — binds on multiple "mystery destination" ports the game
 * tries to talk to during press-X (38745 from DEV9 log 2026-06-01). Captures
 * incoming payload so we can RE the bytes and figure out what game expects.
 *
 * Logs to: C:\dnas\active\captures\snoop\
 * Hands raw bytes per-port so we can compare across sessions.
 *
 * Add ports here as DEV9 log reveals more. Defaults are the observed values.
 */
'use strict';
const dgram = require('dgram');
const fs = require('fs');
const path = require('path');
const { RUN_ID } = require('./run_id');

const ACTIVE_ROOT = path.resolve(__dirname, '..');
const SNOOP_DIR = path.join(ACTIVE_ROOT, 'captures', 'snoop');
if (!fs.existsSync(SNOOP_DIR)) fs.mkdirSync(SNOOP_DIR, { recursive: true });

const PORTS = (process.env.SNOOP_PORTS || '38745,51955,38000,38001,38002,38003,38004,38005,38006,38007,38008,38009,38010')
  .split(',').map(s => parseInt(s.trim(), 10)).filter(Boolean);

let hits = 0;
for (const port of PORTS) {
  const sock = dgram.createSocket({ type: 'udp4', reuseAddr: true });
  sock.on('error', e => {
    console.error(`[snoop:${port}] ${e.message}`);
    try { sock.close(); } catch {}
  });
  sock.on('message', (msg, rinfo) => {
    hits++;
    const t = new Date().toISOString().replace(/[:.]/g, '_');
    const fname = path.join(SNOOP_DIR, `${RUN_ID}_snoop_p${port}_from_${rinfo.address}_${rinfo.port}_${Date.now()}.bin`);
    fs.writeFileSync(fname, msg);
    const hex = msg.toString('hex');
    const ascii = msg.toString('latin1').replace(/[^\x20-\x7e]/g, '.');
    console.log(`[snoop :${port}] ★ HIT from ${rinfo.address}:${rinfo.port} (${msg.length}B)  hex=${hex.slice(0, 60)}${hex.length > 60 ? '...' : ''}`);
    console.log(`          saved: ${fname}`);

    // Auto-reply: every SN@P frame we've seen on 38745 so far is a 20-byte
    // transport-ack (kind 0x60 or 0xb0). Echo back a matching kind=0x60 ACK
    // mirroring the session/seq bytes (4..15) and trailer. This keeps the
    // session alive instead of timing out into Error 839. If frame is a
    // DATA frame (kind != 0x60/0xb0) we still send the ACK as a probe.
    if (process.env.SNOOP_AUTO_ACK !== '0' && msg.length >= 20) {
      const ack = Buffer.alloc(20);
      ack[0] = 0x60; ack[1] = 0x10; ack[2] = 0x00; ack[3] = 0x00;
      msg.copy(ack, 4, 4, 16);          // mirror bytes 4..15
      ack[16] = 0xba; ack[17] = 0x47; ack[18] = 0x66; ack[19] = 0x11;
      sock.send(ack, rinfo.port, rinfo.address, (err) => {
        if (err) console.error(`[snoop :${port}] reply failed: ${err.message}`);
        else console.log(`[snoop :${port}] ← REPLIED transport-ack (20B) to ${rinfo.address}:${rinfo.port}`);
      });
    }
  });
  sock.bind(port, '0.0.0.0', () => {
    const addr = sock.address();
    console.log(`[snoop] listening on UDP ${addr.address}:${addr.port}`);
  });
}

console.log(`[snoop] watching ${PORTS.length} ports: ${PORTS.join(',')}`);
