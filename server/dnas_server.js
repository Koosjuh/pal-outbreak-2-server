const net = require('net');
const crypto = require('crypto');
const fs = require('fs');
const path = require('path');

const ACTIVE_ROOT = path.resolve(__dirname, '..');
const ROOT_REF_DIR = path.resolve(__dirname, '..', '..');
const PACKETS_DIR = fs.existsSync(path.join(__dirname, 'packets'))
  ? path.join(__dirname, 'packets')
  : path.join(ACTIVE_ROOT, 'server', 'packets');
const DUMPS_DIR = path.join(ACTIVE_ROOT, 'captures', 'dumps');
const CAPTURES_DIR = path.join(ACTIVE_ROOT, 'captures');
const TLS_LOG_DIR = path.join(CAPTURES_DIR, 'dnas443');
const HEALTH_PATH = path.join(TLS_LOG_DIR, 'dnas_health.json');
const EVENTS_PATH = path.join(TLS_LOG_DIR, 'dnas_events.log');

for (const dir of [PACKETS_DIR, DUMPS_DIR, CAPTURES_DIR, TLS_LOG_DIR]) {
  if (!fs.existsSync(dir)) fs.mkdirSync(dir, { recursive: true });
}

const certPem = fs.readFileSync(
  fs.existsSync(path.join(__dirname, 'server.crt'))
    ? path.join(__dirname, 'server.crt')
    : path.join(ACTIVE_ROOT, 'server', 'server.crt'),
  'utf8'
);
const keyPem = fs.readFileSync(
  fs.existsSync(path.join(__dirname, 'server.key'))
    ? path.join(__dirname, 'server.key')
    : path.join(ACTIVE_ROOT, 'server', 'server.key'),
  'utf8'
);
const caPem = fs.readFileSync(
  fs.existsSync(path.join(__dirname, 'ca-cert.pem'))
    ? path.join(__dirname, 'ca-cert.pem')
    : path.join(ACTIVE_ROOT, 'server', 'ca-cert.pem'),
  'utf8'
);

function pemToDer(pem) {
  const base64 = pem
    .replace(/-----BEGIN CERTIFICATE-----/g, '')
    .replace(/-----END CERTIFICATE-----/g, '')
    .replace(/\s+/g, '');
  return Buffer.from(base64, 'base64');
}

function getSubjectField(subject, fieldName) {
  const match = subject.match(new RegExp(`(?:^|\\n)\\s*${fieldName}=([^\\n]+)`));
  return match ? match[1].trim() : 'unknown';
}

const cert = new crypto.X509Certificate(certPem);
const caCert = new crypto.X509Certificate(caPem);
const certDer = pemToDer(certPem);
const caDer = pemToDer(caPem);
const privateKey = crypto.createPrivateKey(keyPem);

console.log(`Server cert: ${getSubjectField(cert.subject, 'CN')}`);
console.log(`CA cert: ${getSubjectField(caCert.subject, 'O')}`);
console.log(`Packets dir: ${PACKETS_DIR}`);
console.log(`Dumps dir: ${DUMPS_DIR}`);
console.log(`TLS logs: ${TLS_LOG_DIR}\n`);

const health = {
  pid: process.pid,
  startedAt: new Date().toISOString(),
  listening: false,
  listenAddress: null,
  acceptedConnections: 0,
  totalDataEvents: 0,
  totalBytesIn: 0,
  totalBytesOut: 0,
  lastAcceptAt: null,
  lastRemote: null,
  lastDataAt: null,
  lastLifecycleEvent: null,
  lastSocketCloseAt: null,
  lastSocketError: null,
  lastUnhandledError: null,
  lastExitSignal: null
};

function writeHealth(extra = {}) {
  Object.assign(health, extra);
  fs.writeFileSync(HEALTH_PATH, JSON.stringify(health, null, 2));
}

function appendEvent(line) {
  const stamped = `[${new Date().toISOString()}] ${line}`;
  fs.appendFileSync(EVENTS_PATH, stamped + '\n');
}

writeHealth();
appendEvent(`START pid=${process.pid}`);

function hmacSha1(key, data) { return crypto.createHmac('sha1', key).update(data).digest(); }
function hmacMd5(key, data) { return crypto.createHmac('md5', key).update(data).digest(); }

function pHash(hmacFn, secret, seed, length) {
  let out = Buffer.alloc(0);
  let a = hmacFn(secret, seed);
  while (out.length < length) {
    out = Buffer.concat([out, hmacFn(secret, Buffer.concat([a, seed]))]);
    a = hmacFn(secret, a);
  }
  return out.slice(0, length);
}

function tls10PRF(secret, label, seed, length) {
  const half = Math.ceil(secret.length / 2);
  const s1 = secret.slice(0, half);
  const s2 = secret.slice(secret.length - half);
  const labelSeed = Buffer.concat([Buffer.from(label), seed]);
  const md5 = pHash(hmacMd5, s1, labelSeed, length);
  const sha1 = pHash(hmacSha1, s2, labelSeed, length);
  const out = Buffer.alloc(length);
  for (let i = 0; i < length; i++) out[i] = md5[i] ^ sha1[i];
  return out;
}

function tlsRecord(type, data) {
  const hdr = Buffer.alloc(5);
  hdr[0] = type;
  hdr.writeUInt16BE(0x0301, 1);
  hdr.writeUInt16BE(data.length, 3);
  return Buffer.concat([hdr, data]);
}

class RC4 {
  constructor(key) {
    const S = new Uint8Array(256);
    for (let i = 0; i < 256; i++) S[i] = i;
    let j = 0;
    for (let i = 0; i < 256; i++) {
      j = (j + S[i] + key[i % key.length]) & 0xff;
      [S[i], S[j]] = [S[j], S[i]];
    }
    this.S = S;
    this.i = 0;
    this.j = 0;
  }

  process(data) {
    const out = Buffer.alloc(data.length);
    for (let k = 0; k < data.length; k++) {
      this.i = (this.i + 1) & 0xff;
      this.j = (this.j + this.S[this.i]) & 0xff;
      [this.S[this.i], this.S[this.j]] = [this.S[this.j], this.S[this.i]];
      out[k] = data[k] ^ this.S[(this.S[this.i] + this.S[this.j]) & 0xff];
    }
    return out;
  }
}

function desEde3Encrypt(k1, k2, k3, block8) {
  const key24 = Buffer.concat([k1, k2, k3]);
  const cipher = crypto.createCipheriv('des-ede3-ecb', key24, null);
  cipher.setAutoPadding(false);
  return Buffer.concat([cipher.update(block8), cipher.final()]);
}

function encrypt3(data, offset, length, k1, k2, k3, xorSeed) {
  const out = Buffer.from(data);
  let key = Buffer.from(xorSeed);
  for (let i = 0; i < length; i += 8) {
    const dat = Buffer.alloc(8);
    for (let t = 0; t < 8; t++) dat[t] = out[offset + i + t] ^ key[t];
    const enc = desEde3Encrypt(k1, k2, k3, dat);
    enc.copy(out, offset + i);
    key = enc;
  }
  return out;
}

const ENVELOPE_K1 = Buffer.from('eb711416cb0ab016', 'hex');
const ENVELOPE_K2 = Buffer.from('ae190174b5ce6339', 'hex');
const ENVELOPE_K3 = Buffer.from('7b01b91880145e34', 'hex');
const ENVELOPE_XOR = Buffer.from('c510a6400a9b022f', 'hex');

function hex(buf, max = 512) {
  const rows = [];
  const slice = buf.slice(0, max);
  for (let i = 0; i < slice.length; i += 16) {
    const chunk = slice.slice(i, i + 16);
    const hexPart = [...chunk].map(b => b.toString(16).padStart(2, '0')).join(' ').padEnd(47);
    const asciiPart = [...chunk].map(b => (b >= 0x20 && b < 0x7f) ? String.fromCharCode(b) : '.').join('');
    rows.push(`  ${i.toString(16).padStart(4, '0')}  ${hexPart}  ${asciiPart}`);
  }
  if (buf.length > max) rows.push(`  ... (${buf.length - max} more bytes)`);
  return rows.join('\n');
}

function buildResponse(body) {
  const header =
    'HTTP/1.0 200 OK\r\n' +
    'Content-Type: image/gif\r\n' +
    'Content-Length: ' + body.length + '\r\n' +
    '\r\n';
  return Buffer.concat([Buffer.from(header, 'latin1'), body]);
}

function buildErrorResponse() {
  const body = Buffer.from('ERROR');
  const header =
    'HTTP/1.0 500 Internal Server Error\r\n' +
    'Content-Type: image/gif\r\n' +
    'Content-Length: ' + body.length + '\r\n' +
    '\r\n';
  return Buffer.concat([Buffer.from(header, 'latin1'), body]);
}

function handleOthersRequest(url, body, logLine) {
  const qrytype = body.slice(0, 4);
  const candidates = [0x24, 0x26, 0x2c, 0x1b, 0x10, 0x18, 0x20];

  logLine(`  [others] qrytype=${qrytype.toString('hex')} body=${body.length}b`);

  for (const off of candidates) {
    if (off + 8 > body.length) continue;
    const gameID = body.slice(off, off + 8);
    const fname = gameID.toString('hex') + '_' + qrytype.toString('hex');
    const packetPath = path.join(PACKETS_DIR, fname);
    if (fs.existsSync(packetPath)) {
      const packet = fs.readFileSync(packetPath);
      logLine(`  [others] MATCH offset=0x${off.toString(16)} file=${fname} size=${packet.length}`);
      return buildResponse(packet);
    }
  }

  logLine('  [others] No packet match found');
  return buildErrorResponse();
}

function handleV1Request(url, body, logLine) {
  const qrytype = body.slice(0, 4);
  const gameID = body.slice(0x1b, 0x1b + 8);
  const fname = gameID.toString('hex') + '_' + qrytype.toString('hex');
  const packetPath = path.join(PACKETS_DIR, fname);

  logLine(`  [v1] qrytype=${qrytype.toString('hex')} gameID=${gameID.toString('hex')}`);

  if (fs.existsSync(packetPath)) {
    const packet = fs.readFileSync(packetPath);
    logLine(`  [v1] Matched ${fname} (${packet.length} bytes)`);
    return buildResponse(packet);
  }

  logLine(`  [v1] No packet found for ${fname}`);
  return buildErrorResponse();
}

function handleV25Request(url, body, logLine) {
  const qrytype = body.slice(0, 4);
  const gameID = body.slice(0x2c, 0x2c + 8);
  const fname = gameID.toString('hex') + '_' + qrytype.toString('hex');

  logLine(`  [v2.5] qrytype=${qrytype.toString('hex')} gameID=${gameID.toString('hex')}`);

  if (body.length < 0x48 + 0xec) {
    logLine('  [v2.5] Body too short for key derivation');
    return buildErrorResponse();
  }

  const chksum1 = crypto.createHash('sha1').update(body.slice(0x34, 0x34 + 0x100)).digest();
  const chksum2 = crypto.createHash('sha1').update(body.slice(0x48, 0x48 + 0xec)).digest();
  const fullkey = Buffer.concat([chksum2.slice(0, 0x14), chksum1.slice(0, 0x0c)]);

  const desK1 = fullkey.slice(0x00, 0x08);
  const desK2 = fullkey.slice(0x08, 0x10);
  const desK3 = fullkey.slice(0x10, 0x18);
  const xorSeed = fullkey.slice(0x18, 0x20);

  logLine(`  [v2.5] des_k1=${desK1.toString('hex')}`);
  logLine(`  [v2.5] des_k2=${desK2.toString('hex')}`);
  logLine(`  [v2.5] des_k3=${desK3.toString('hex')}`);
  logLine(`  [v2.5] xor_seed=${xorSeed.toString('hex')}`);

  const packetPath = path.join(PACKETS_DIR, fname);
  if (!fs.existsSync(packetPath)) {
    logLine(`  [v2.5] No packet found for ${fname}`);
    return buildErrorResponse();
  }

  let packet = fs.readFileSync(packetPath);
  packet = encrypt3(packet, 0xc8, 0x20, desK1, desK2, desK3, xorSeed);
  packet = encrypt3(packet, 0x28, 0x120, ENVELOPE_K1, ENVELOPE_K2, ENVELOPE_K3, ENVELOPE_XOR);
  logLine(`  [v2.5] Encrypted response ${packet.length} bytes`);
  return buildResponse(packet);
}

function handleDnasRequest(requestBytes, connTag, logLine) {
  const str = requestBytes.toString('latin1');
  const headerEnd = str.indexOf('\r\n\r\n');
  if (headerEnd < 0) {
    logLine('  [DNAS] No valid HTTP headers');
    return buildErrorResponse();
  }

  const headers = str.substring(0, headerEnd);
  const body = requestBytes.slice(headerEnd + 4);
  const firstLine = headers.split('\r\n')[0];
  const urlMatch = firstLine.match(/POST (\S+)/);
  const url = urlMatch ? urlMatch[1] : '';
  const ts = Date.now();

  logLine('  [DNAS] Headers:');
  headers.split('\r\n').forEach(line => logLine(`    ${line}`));
  logLine(`  [DNAS] Body: ${body.length} bytes`);
  logLine(`  [DNAS] Body hex:\n${hex(body)}`);
  logLine(`  [DNAS] URL: ${url || 'unparsed'}`);

  fs.writeFileSync(path.join(DUMPS_DIR, `${connTag}_req_${ts}.bin`), body);
  fs.writeFileSync(
    path.join(DUMPS_DIR, `${connTag}_req_${ts}.txt`),
    `URL: ${url}\n\nHeaders:\n${headers}\n\nBody hex:\n${body.toString('hex')}\n`
  );

  if (url.includes('v2.5_i-connect')) {
    // DNAS i-connect = fresh boot signal. Don't wipe pending entries — session_store
    // uses TTL-based expiry now, so stale entries time out on their own. Wiping
    // would clobber concurrent users from the same NAT.
    try {
      const { pendingStats } = require('./session_store');
      const stats = pendingStats();
      if (stats.entries > 0) {
        logLine(`  [DNAS] fresh boot from this IP — ${stats.entries} pending entries currently armed across ${stats.ips} IP(s) (TTL will expire stale ones)`);
      }
    } catch (e) { /* ignore */ }
    return handleV25Request(url, body, logLine);
  }
  if (url.includes('v2.5_others')) return handleOthersRequest(url, body, logLine);
  if (url.includes('v2.5')) return handleV25Request(url, body, logLine);
  if (url.includes('v1') || url.match(/\/[a-z]+-gw\/i-connect/)) return handleV1Request(url, body, logLine);

  logLine('  [DNAS] Unknown protocol version');
  return buildErrorResponse();
}

class Session {
  constructor() {
    this.clientSeq = 0n;
    this.serverSeq = 0n;
    this.readEncrypted = false;
    this.clientHelloRaw = null;
    this.serverHello = null;
    this.certificate = null;
    this.serverHelloDone = null;
    this.clientKeyExchange = null;
    this.matchedHandshake = null;
    this.appDataBuffer = Buffer.alloc(0);
  }

  computeKeys() {
    const seed = Buffer.concat([this.clientRandom, this.serverRandom]);
    this.masterSecret = tls10PRF(this.premaster, 'master secret', seed, 48);
    const keySeed = Buffer.concat([this.serverRandom, this.clientRandom]);
    const kb = tls10PRF(this.masterSecret, 'key expansion', keySeed, 64);
    this.clientMacKey = kb.slice(0, 16);
    this.serverMacKey = kb.slice(16, 32);
    this.clientWriteKey = kb.slice(32, 48);
    this.serverWriteKey = kb.slice(48, 64);
    this.clientCipher = new RC4(this.clientWriteKey);
    this.serverCipher = new RC4(this.serverWriteKey);
  }

  encryptRecord(type, plaintext) {
    const seqBuf = Buffer.alloc(8);
    seqBuf.writeBigUInt64BE(this.serverSeq);
    const macHeader = Buffer.alloc(5);
    macHeader[0] = type;
    macHeader.writeUInt16BE(0x0301, 1);
    macHeader.writeUInt16BE(plaintext.length, 3);
    const mac = hmacMd5(this.serverMacKey, Buffer.concat([seqBuf, macHeader, plaintext]));
    const encrypted = this.serverCipher.process(Buffer.concat([plaintext, mac]));
    this.serverSeq++;
    return encrypted;
  }

  decryptRecord(type, ciphertext) {
    const dec = this.clientCipher.process(ciphertext);
    const plaintext = dec.slice(0, dec.length - 16);
    const mac = dec.slice(dec.length - 16);
    const seqBuf = Buffer.alloc(8);
    seqBuf.writeBigUInt64BE(this.clientSeq);
    const macHeader = Buffer.alloc(5);
    macHeader[0] = type;
    macHeader.writeUInt16BE(0x0301, 1);
    macHeader.writeUInt16BE(plaintext.length, 3);
    const expected = hmacMd5(this.clientMacKey, Buffer.concat([seqBuf, macHeader, plaintext]));
    this.clientSeq++;
    return {
      plaintext,
      macOk: mac.equals(expected)
    };
  }

  buildHandshakeHash() {
    return Buffer.concat([
      this.clientHelloRaw.slice(2),
      this.serverHello,
      this.certificate,
      this.serverHelloDone,
      this.clientKeyExchange
    ]);
  }

  verifyClientFinished(clientFinished) {
    const hs = this.buildHandshakeHash();
    const md5 = crypto.createHash('md5').update(hs).digest();
    const sha1 = crypto.createHash('sha1').update(hs).digest();
    const computed = tls10PRF(this.masterSecret, 'client finished', Buffer.concat([md5, sha1]), 12);
    this.matchedHandshake = hs;
    return computed.equals(clientFinished);
  }

  computeServerFinished(clientFinishedHs) {
    const hsForServer = Buffer.concat([this.matchedHandshake, clientFinishedHs]);
    const md5 = crypto.createHash('md5').update(hsForServer).digest();
    const sha1 = crypto.createHash('sha1').update(hsForServer).digest();
    return tls10PRF(this.masterSecret, 'server finished', Buffer.concat([md5, sha1]), 12);
  }
}

function buildServerHello(serverRandom) {
  const body = Buffer.alloc(38);
  body.writeUInt16BE(0x0301, 0);
  serverRandom.copy(body, 2);
  body[34] = 0x00;
  body.writeUInt16BE(0x0004, 35);
  body[37] = 0x00;
  const hs = Buffer.alloc(4);
  hs[0] = 0x02;
  hs.writeUIntBE(body.length, 1, 3);
  return Buffer.concat([hs, body]);
}

function buildCertificateHs() {
  const serverCertLen = Buffer.alloc(3);
  serverCertLen.writeUIntBE(certDer.length, 0, 3);
  const caCertLen = Buffer.alloc(3);
  caCertLen.writeUIntBE(caDer.length, 0, 3);
  const allCerts = Buffer.concat([serverCertLen, certDer, caCertLen, caDer]);
  const listLen = Buffer.alloc(3);
  listLen.writeUIntBE(allCerts.length, 0, 3);
  const body = Buffer.concat([listLen, allCerts]);
  const hs = Buffer.alloc(4);
  hs[0] = 0x0b;
  hs.writeUIntBE(body.length, 1, 3);
  return Buffer.concat([hs, body]);
}

function buildServerHelloDone() {
  return Buffer.from([0x0e, 0x00, 0x00, 0x00]);
}

let connectionCount = 0;

const server = net.createServer(socket => {
  const id = ++connectionCount;
  const connTag = `dnas_conn${id}`;
  const remote = `${socket.remoteAddress}:${socket.remotePort}`;
  const logPath = path.join(TLS_LOG_DIR, `${connTag}.log`);
  const metaPath = path.join(TLS_LOG_DIR, `${connTag}_meta.json`);
  let state = 'WAIT_CLIENT_HELLO';
  let buffer = Buffer.alloc(0);
  let rawIn = Buffer.alloc(0);
  let rawOut = Buffer.alloc(0);
  const session = new Session();
  const openedAt = new Date().toISOString();
  let dataEvents = 0;
  let sawClientHello = false;
  let closed = false;
  let sawEnd = false;
  let lastDataPreview = null;

  function logLine(line) {
    console.log(line);
    fs.appendFileSync(logPath, line + '\n');
  }

  function saveBuffer(suffix, buf) {
    fs.writeFileSync(path.join(TLS_LOG_DIR, `${connTag}_${suffix}.bin`), buf);
  }

  logLine('\n' + '='.repeat(72));
  logLine(`[${connTag}] OPEN remote=${remote}`);
  logLine(`[${connTag}] log=${logPath}`);
  appendEvent(`${connTag} OPEN remote=${remote}`);
  writeHealth({
    acceptedConnections: connectionCount,
    lastAcceptAt: new Date().toISOString(),
    lastRemote: remote,
    lastLifecycleEvent: {
      at: new Date().toISOString(),
      connection: connTag,
      event: 'open',
      remote
    }
  });

  socket.setTimeout(5000);
  socket.setKeepAlive(true, 1000);

  function writeMeta(reason) {
    fs.writeFileSync(metaPath, JSON.stringify({
      connection: connTag,
      remote,
      openedAt,
      closedAt: closed ? new Date().toISOString() : null,
      closeReason: reason,
      finalState: state,
      dataEvents,
      rawInBytes: rawIn.length,
      rawOutBytes: rawOut.length,
      sawEnd,
      sawClientHello,
      lastDataPreview
    }, null, 2));
  }

  function writeAndTrack(buf, note) {
    rawOut = Buffer.concat([rawOut, buf]);
    socket.write(buf);
    logLine(`[${connTag}] OUT ${buf.length} bytes ${note}`);
    appendEvent(`${connTag} OUT bytes=${buf.length} note=${note}`);
    writeHealth({
      totalBytesOut: health.totalBytesOut + buf.length,
      lastLifecycleEvent: {
        at: new Date().toISOString(),
        connection: connTag,
        event: 'write',
        note,
        bytes: buf.length
      }
    });
  }

  function handleSSLv2Hello(data) {
    sawClientHello = true;
    logLine(`[${connTag}] SSLv2 ClientHello ${data.length} bytes`);
    logLine(hex(data));

    session.clientHelloRaw = Buffer.from(data);
    const cipherSpecLen = data.readUInt16BE(5);
    const sessionIdLen = data.readUInt16BE(7);
    const challengeLen = data.readUInt16BE(9);
    const challenge = data.slice(
      11 + cipherSpecLen + sessionIdLen,
      11 + cipherSpecLen + sessionIdLen + challengeLen
    );

    session.clientRandom = Buffer.concat([Buffer.alloc(32 - challenge.length), challenge]);
    session.serverRandom = crypto.randomBytes(32);
    session.serverHello = buildServerHello(session.serverRandom);
    session.certificate = buildCertificateHs();
    session.serverHelloDone = buildServerHelloDone();

    writeAndTrack(Buffer.concat([
      tlsRecord(0x16, session.serverHello),
      tlsRecord(0x16, session.certificate),
      tlsRecord(0x16, session.serverHelloDone)
    ]), 'server_hello+certificate+done');

    state = 'WAIT_CLIENT_KEY_EXCHANGE';
  }

  function handleTLSRecord(type, payload) {
    logLine(`[${connTag}] TLS record type=0x${type.toString(16).padStart(2, '0')} len=${payload.length} state=${state}`);

    if (type === 0x15) {
      const decoded = session.readEncrypted ? session.decryptRecord(0x15, payload).plaintext : payload;
      logLine(`[${connTag}] ALERT ${decoded.toString('hex')}`);
      return;
    }

    if (type === 0x14) {
      session.readEncrypted = true;
      logLine(`[${connTag}] ChangeCipherSpec received`);
      return;
    }

    if (type === 0x16) {
      const decoded = session.readEncrypted ? session.decryptRecord(0x16, payload) : { plaintext: payload, macOk: true };
      logLine(`[${connTag}] Handshake payload ${decoded.plaintext.length} bytes macOk=${decoded.macOk}`);
      const data = decoded.plaintext;
      const hsType = data[0];
      const hsLen = (data[1] << 16) | (data[2] << 8) | data[3];
      const hsBody = data.slice(4, 4 + hsLen);

      if (hsType === 0x10) {
        session.clientKeyExchange = Buffer.from(data.slice(0, 4 + hsLen));
        const encLen = hsBody.readUInt16BE(0);
        const encrypted = hsBody.slice(2, 2 + encLen);
        try {
          session.premaster = crypto.privateDecrypt(
            { key: privateKey, padding: crypto.constants.RSA_PKCS1_PADDING },
            encrypted
          );
          session.computeKeys();
          logLine(`[${connTag}] ClientKeyExchange processed, keys derived`);
        } catch (e) {
          logLine(`[${connTag}] Premaster decryption failed: ${e.message}`);
        }
      } else if (hsType === 0x14) {
        const clientFinished = Buffer.from(hsBody);
        const clientFinishedHs = Buffer.from(data.slice(0, 4 + hsLen));
        const ok = session.verifyClientFinished(clientFinished);
        logLine(`[${connTag}] Client Finished verified=${ok}`);
        if (!ok) {
          socket.end();
          return;
        }

        writeAndTrack(tlsRecord(0x14, Buffer.from([0x01])), 'change_cipher_spec');
        const serverFinished = session.computeServerFinished(clientFinishedHs);
        const finishedHs = Buffer.concat([Buffer.from([0x14, 0x00, 0x00, 0x0c]), serverFinished]);
        writeAndTrack(tlsRecord(0x16, session.encryptRecord(0x16, finishedHs)), 'server_finished');
        state = 'APPLICATION_DATA';
      } else {
        logLine(`[${connTag}] Unhandled handshake type=0x${hsType.toString(16).padStart(2, '0')}`);
      }
      return;
    }

    if (type === 0x17) {
      const decoded = session.decryptRecord(0x17, payload);
      logLine(`[${connTag}] AppData decrypted len=${decoded.plaintext.length} macOk=${decoded.macOk}`);
      session.appDataBuffer = Buffer.concat([session.appDataBuffer, decoded.plaintext]);

      const str = session.appDataBuffer.toString('latin1');
      const headerEnd = str.indexOf('\r\n\r\n');
      if (headerEnd < 0) return;

      const headers = str.substring(0, headerEnd);
      const clMatch = headers.match(/Content-Length:\s*(\d+)/i);
      const expectedBodyLen = clMatch ? parseInt(clMatch[1], 10) : 0;
      const actualBodyLen = session.appDataBuffer.length - headerEnd - 4;
      logLine(`[${connTag}] HTTP-in-progress body=${actualBodyLen}/${expectedBodyLen}`);
      if (actualBodyLen < expectedBodyLen) return;

      logLine(`[${connTag}] COMPLETE DNAS REQUEST`);
      const response = handleDnasRequest(session.appDataBuffer, connTag, logLine);

      const MAX = 16000;
      for (let off = 0; off < response.length; off += MAX) {
        const chunk = response.slice(off, Math.min(off + MAX, response.length));
        writeAndTrack(tlsRecord(0x17, session.encryptRecord(0x17, chunk)), `appdata_chunk off=${off}`);
      }

      session.appDataBuffer = Buffer.alloc(0);
    }
  }

  function processRecords() {
    while (buffer.length >= 5) {
      if ((buffer[0] & 0x80) && state === 'WAIT_CLIENT_HELLO') {
        const recLen = ((buffer[0] & 0x7f) << 8) | buffer[1];
        if (buffer.length < recLen + 2) return;
        const ssl2Record = buffer.slice(0, recLen + 2);
        buffer = buffer.slice(recLen + 2);
        handleSSLv2Hello(ssl2Record);
        continue;
      }

      const type = buffer[0];
      const len = buffer.readUInt16BE(3);
      if (buffer.length < 5 + len) return;
      const payload = buffer.slice(5, 5 + len);
      buffer = buffer.slice(5 + len);
      handleTLSRecord(type, payload);
    }
  }

  socket.on('data', data => {
    rawIn = Buffer.concat([rawIn, data]);
    dataEvents += 1;
    lastDataPreview = data.slice(0, Math.min(data.length, 32)).toString('hex');
    logLine(`[${connTag}] IN ${data.length} bytes`);
    appendEvent(`${connTag} IN bytes=${data.length} state=${state} preview=${lastDataPreview}`);
    writeHealth({
      totalDataEvents: health.totalDataEvents + 1,
      totalBytesIn: health.totalBytesIn + data.length,
      lastDataAt: new Date().toISOString(),
      lastLifecycleEvent: {
        at: new Date().toISOString(),
        connection: connTag,
        event: 'data',
        state,
        bytes: data.length,
        preview: lastDataPreview
      }
    });
    try {
      buffer = Buffer.concat([buffer, data]);
      processRecords();
    } catch (e) {
      logLine(`[${connTag}] Process error: ${e.message}`);
      logLine(e.stack || '');
    }
  });

  socket.on('end', () => {
    sawEnd = true;
    logLine(`[${connTag}] REMOTE FIN`);
    appendEvent(`${connTag} END remote=${remote}`);
    writeHealth({
      lastLifecycleEvent: {
        at: new Date().toISOString(),
        connection: connTag,
        event: 'end',
        remote
      }
    });
  });

  socket.on('timeout', () => {
    logLine(`[${connTag}] TIMEOUT state=${state} in=${rawIn.length} out=${rawOut.length}`);
    appendEvent(`${connTag} TIMEOUT state=${state} in=${rawIn.length} out=${rawOut.length}`);
    writeHealth({
      lastLifecycleEvent: {
        at: new Date().toISOString(),
        connection: connTag,
        event: 'timeout',
        state,
        inBytes: rawIn.length,
        outBytes: rawOut.length
      }
    });
    socket.destroy();
  });

  socket.on('close', () => {
    closed = true;
    saveBuffer('raw_in', rawIn);
    saveBuffer('raw_out', rawOut);
    logLine(`[${connTag}] CLOSED in=${rawIn.length} out=${rawOut.length}`);
    appendEvent(`${connTag} CLOSE remote=${remote} state=${state} in=${rawIn.length} out=${rawOut.length} clientHello=${sawClientHello}`);
    writeMeta('close');
    writeHealth({
      lastSocketCloseAt: new Date().toISOString(),
      lastLifecycleEvent: {
        at: new Date().toISOString(),
        connection: connTag,
        event: 'close',
        state,
        inBytes: rawIn.length,
        outBytes: rawOut.length,
        sawClientHello
      }
    });
  });

  socket.on('error', e => {
    logLine(`[${connTag}] Socket error: ${e.message}`);
    appendEvent(`${connTag} ERROR remote=${remote} state=${state} message=${e.message}`);
    writeMeta(`error:${e.message}`);
    writeHealth({
      lastSocketError: {
        at: new Date().toISOString(),
        remote,
        message: e.message
      }
    });
  });
});

server.on('error', e => {
  appendEvent(`SERVER_ERROR message=${e.message}`);
  writeHealth({
    lastUnhandledError: {
      at: new Date().toISOString(),
      type: 'server-error',
      message: e.message
    }
  });
  if (e.code === 'EACCES') {
    console.log('Permission denied on port 443. Run with elevation.');
    process.exit(1);
  }
  console.log('Server error:', e.message);
});

server.listen(443, '0.0.0.0', () => {
  appendEvent('LISTEN 0.0.0.0:443');
  writeHealth({
    listening: true,
    listenAddress: '0.0.0.0:443'
  });
  console.log('DNAS capture server ready on port 443');
});

server.on('close', () => {
  appendEvent('SERVER_CLOSE');
  writeHealth({
    listening: false,
    lastLifecycleEvent: {
      at: new Date().toISOString(),
      event: 'server-close'
    }
  });
});

process.on('uncaughtException', e => {
  appendEvent(`UNCAUGHT_EXCEPTION ${String(e && e.message ? e.message : e)}`);
  writeHealth({
    lastUnhandledError: {
      at: new Date().toISOString(),
      type: 'uncaughtException',
      message: e.stack || e.message
    }
  });
  throw e;
});

process.on('unhandledRejection', reason => {
  appendEvent(`UNHANDLED_REJECTION ${String(reason && reason.message ? reason.message : reason)}`);
  writeHealth({
    lastUnhandledError: {
      at: new Date().toISOString(),
      type: 'unhandledRejection',
      message: String(reason && reason.stack ? reason.stack : reason)
    }
  });
});

for (const sig of ['SIGINT', 'SIGTERM', 'SIGHUP']) {
  process.on(sig, () => {
    appendEvent(`SIGNAL ${sig}`);
    writeHealth({
      listening: false,
      lastExitSignal: {
        at: new Date().toISOString(),
        signal: sig
      }
    });
    process.exit(0);
  });
}
