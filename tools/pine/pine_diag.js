#!/usr/bin/env node
// Raw PINE diagnostic: send a single Status request, dump bytes received.
// Catches protocol-version mismatches, slot misconfig, alternate IPC.
'use strict';

const net = require('net');

const HOST = '127.0.0.1';
const PORT = Number(process.env.PINE_PORT || 28011);
const WAIT_MS = 6000;

const t0 = Date.now();
const t = () => `+${(Date.now() - t0).toString().padStart(4)}ms`;

const sock = net.connect({ port: PORT, host: HOST }, () => {
  console.log(`${t()} [connect] tcp ${HOST}:${PORT}`);
  const pkt = Buffer.from([0x05, 0x00, 0x00, 0x00, 0x0F]);
  console.log(`${t()} [send]   ${pkt.toString('hex')}`);
  sock.write(pkt);
});

const chunks = [];
sock.on('data', (d) => {
  console.log(`${t()} [recv]   ${d.length}B: ${d.toString('hex')}`);
  chunks.push(d);
});

sock.on('error', (e) => console.log(`${t()} [error]  ${e.message}`));
sock.on('close', (had) => console.log(`${t()} [close]  hadError=${had} totalRecv=${chunks.reduce((s,b)=>s+b.length,0)}B`));

setTimeout(() => {
  console.log(`[timeout after ${WAIT_MS}ms — closing]`);
  sock.destroy();
  process.exit(0);
}, WAIT_MS);
