'use strict';

// Resolve the local LAN IP for this host, once at process start.
// Replaces hardcoded `192.0.2.196` literals across the server stack.
//
// Resolution order:
//   1. env SERVER_HOST_IP (explicit override, e.g. CI / multi-NIC)
//   2. First non-loopback, non-link-local IPv4 from os.networkInterfaces()
//   3. Fallback to 127.0.0.1 (will not work for inbound game traffic
//      but won't crash the process)
//
// Exports:
//   HOST_IP      — string, dotted quad
//   HOST_IP_BE   — number, big-endian u32 (network byte order — what the
//                  game's protocol fields expect for raw IP values)
//   formatBytes  — Buffer (4 bytes) of HOST_IP for raw-byte embedding

const os = require('os');

function pickInterfaceIp() {
  const ifaces = os.networkInterfaces();
  for (const name of Object.keys(ifaces)) {
    for (const i of ifaces[name] || []) {
      if (i.family !== 'IPv4' && i.family !== 4) continue;
      if (i.internal) continue;
      // Skip link-local (169.254.x.x) and APIPA-style addresses
      if (i.address.startsWith('169.254.')) continue;
      return i.address;
    }
  }
  return '127.0.0.1';
}

const HOST_IP = process.env.SERVER_HOST_IP || pickInterfaceIp();

const octets = HOST_IP.split('.').map(o => parseInt(o, 10));
const HOST_IP_BE = ((octets[0] << 24) | (octets[1] << 16) | (octets[2] << 8) | octets[3]) >>> 0;
const HOST_IP_BYTES = Buffer.from(octets);

module.exports = {
  HOST_IP,
  HOST_IP_BE,
  HOST_IP_BYTES,
};
