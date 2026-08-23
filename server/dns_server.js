const dgram = require('dgram');
const net = require('net');
const fs = require('fs');
const path = require('path');
const { HOST_IP } = require('./host_ip');

const LISTEN_IP = '0.0.0.0';
const LISTEN_PORT = 53;
const ANSWER_IP = HOST_IP;
const ACTIVE_ROOT = path.resolve(__dirname, '..');
const CAPTURES_DIR = path.join(ACTIVE_ROOT, 'captures');
const DNS_DIR = path.join(CAPTURES_DIR, 'dns53');
const EVENTS_PATH = path.join(DNS_DIR, 'dns_events.log');
const HEALTH_PATH = path.join(DNS_DIR, 'dns_health.json');

for (const dir of [CAPTURES_DIR, DNS_DIR]) {
  if (!fs.existsSync(dir)) fs.mkdirSync(dir, { recursive: true });
}

const HOST_OVERRIDES = new Map([
  ['gate1.eu.dnas.playstation.org', ANSWER_IP],
  ['stage6.sega.com', ANSWER_IP],
  ['app01.reo.capcom.sf.yav4.com', ANSWER_IP],
  ['snap01.capcom.client.sf.yav4.com', ANSWER_IP]
]);

const health = {
  pid: process.pid,
  startedAt: new Date().toISOString(),
  listening: false,
  listenAddress: null,
  udpQueries: 0,
  tcpQueries: 0,
  udpResponses: 0,
  tcpResponses: 0,
  lastQueryAt: null,
  lastQueryName: null,
  lastQueryType: null,
  lastRemote: null,
  lastEvent: null,
  lastError: null
};

function writeHealth(extra = {}) {
  Object.assign(health, extra);
  fs.writeFileSync(HEALTH_PATH, JSON.stringify(health, null, 2));
}

function appendEvent(line) {
  fs.appendFileSync(EVENTS_PATH, `[${new Date().toISOString()}] ${line}\n`);
}

function hex(buf, max = 256) {
  const slice = buf.slice(0, max);
  const rows = [];
  for (let i = 0; i < slice.length; i += 16) {
    const chunk = slice.slice(i, i + 16);
    const hexPart = [...chunk].map(b => b.toString(16).padStart(2, '0')).join(' ').padEnd(47);
    const asciiPart = [...chunk].map(b => (b >= 0x20 && b < 0x7f) ? String.fromCharCode(b) : '.').join('');
    rows.push(`  ${i.toString(16).padStart(4, '0')}  ${hexPart}  ${asciiPart}`);
  }
  if (buf.length > max) rows.push(`  ... (${buf.length - max} more bytes)`);
  return rows.join('\n');
}

function writeCapture(baseName, payload, summary) {
  fs.writeFileSync(path.join(DNS_DIR, `${baseName}.bin`), payload);
  fs.writeFileSync(path.join(DNS_DIR, `${baseName}.txt`), summary);
}

function parseName(buf, offset) {
  const labels = [];
  let pos = offset;
  let jumped = false;
  let nextOffset = offset;
  let guard = 0;

  while (guard++ < 64) {
    if (pos >= buf.length) throw new Error('name exceeds packet');
    const len = buf[pos];

    if (len === 0) {
      if (!jumped) nextOffset = pos + 1;
      return { name: labels.join('.'), nextOffset };
    }

    if ((len & 0xc0) === 0xc0) {
      if (pos + 1 >= buf.length) throw new Error('bad compression pointer');
      const ptr = ((len & 0x3f) << 8) | buf[pos + 1];
      if (!jumped) nextOffset = pos + 2;
      pos = ptr;
      jumped = true;
      continue;
    }

    const start = pos + 1;
    const end = start + len;
    if (end > buf.length) throw new Error('label exceeds packet');
    labels.push(buf.slice(start, end).toString('ascii'));
    pos = end;
    if (!jumped) nextOffset = pos;
  }

  throw new Error('name parse loop');
}

function parseDnsMessage(buf) {
  if (buf.length < 12) throw new Error('dns header too short');

  const id = buf.readUInt16BE(0);
  const flags = buf.readUInt16BE(2);
  const qdcount = buf.readUInt16BE(4);
  const ancount = buf.readUInt16BE(6);
  const nscount = buf.readUInt16BE(8);
  const arcount = buf.readUInt16BE(10);

  let offset = 12;
  const questions = [];

  for (let i = 0; i < qdcount; i++) {
    const parsed = parseName(buf, offset);
    offset = parsed.nextOffset;
    if (offset + 4 > buf.length) throw new Error('truncated question');
    const qtype = buf.readUInt16BE(offset);
    const qclass = buf.readUInt16BE(offset + 2);
    offset += 4;
    questions.push({ name: parsed.name.toLowerCase(), qtype, qclass });
  }

  return { id, flags, qdcount, ancount, nscount, arcount, questions, questionEndOffset: offset };
}

function ipToBuffer(ip) {
  return Buffer.from(ip.split('.').map(x => Number(x)));
}

function qtypeName(qtype) {
  switch (qtype) {
    case 1: return 'A';
    case 5: return 'CNAME';
    case 12: return 'PTR';
    case 15: return 'MX';
    case 16: return 'TXT';
    case 28: return 'AAAA';
    default: return `TYPE${qtype}`;
  }
}

function resolveName(name) {
  if (HOST_OVERRIDES.has(name)) return HOST_OVERRIDES.get(name);
  if (name.endsWith('.yav4.com')) return ANSWER_IP;
  if (name.endsWith('.dnas.playstation.org')) return ANSWER_IP;
  // Game's 0x6504 record uses field_a as a hostname; PCSX2 appends ".PCSX2"
  // search domain. pktmon empirically caught queries like "SLOT0001.PCSX2".
  if (name.endsWith('.PCSX2') || name.endsWith('.pcsx2')) return ANSWER_IP;
  return null;
}

function buildResponse(query, rawQuery) {
  const flags = 0x8180;
  const qdcount = query.questions.length;
  const answers = [];

  for (const q of query.questions) {
    const answerIp = resolveName(q.name);
    if (!answerIp) continue;
    if (q.qtype !== 1 && q.qtype !== 255) continue;
    if (q.qclass !== 1) continue;

    const rr = Buffer.alloc(16);
    rr.writeUInt16BE(0xc00c, 0);
    rr.writeUInt16BE(1, 2);
    rr.writeUInt16BE(1, 4);
    rr.writeUInt32BE(60, 6);
    rr.writeUInt16BE(4, 10);
    ipToBuffer(answerIp).copy(rr, 12);
    answers.push(rr);
  }

  const rcode = answers.length > 0 ? 0 : 3;
  const header = Buffer.alloc(12);
  header.writeUInt16BE(query.id, 0);
  header.writeUInt16BE((flags & 0xfff0) | rcode, 2);
  header.writeUInt16BE(qdcount, 4);
  header.writeUInt16BE(answers.length, 6);
  header.writeUInt16BE(0, 8);
  header.writeUInt16BE(0, 10);

  return Buffer.concat([header, rawQuery.slice(12, query.questionEndOffset), ...answers]);
}

function summarizeQuestions(questions) {
  if (questions.length === 0) return '(no questions)';
  return questions.map(q => `${q.name} ${qtypeName(q.qtype)} class=${q.qclass}`).join(' | ');
}

function handlePacket(proto, raw, remoteLabel, respond) {
  let parsed;
  try {
    parsed = parseDnsMessage(raw);
  } catch (e) {
    appendEvent(`${proto} PARSE_ERROR remote=${remoteLabel} message=${e.message}`);
    writeHealth({
      lastError: { at: new Date().toISOString(), proto, remote: remoteLabel, message: e.message },
      lastEvent: { at: new Date().toISOString(), proto, remote: remoteLabel, event: 'parse-error' }
    });
    return;
  }

  const questionsSummary = summarizeQuestions(parsed.questions);
  const firstQuestion = parsed.questions[0];
  const response = buildResponse(parsed, raw);
  const base = `dns_${proto}_${Date.now()}_${remoteLabel.replace(/[:.]/g, '_')}`;
  const summary =
    `Proto    : ${proto}\n` +
    `Remote   : ${remoteLabel}\n` +
    `ID       : 0x${parsed.id.toString(16).padStart(4, '0')}\n` +
    `Flags    : 0x${parsed.flags.toString(16).padStart(4, '0')}\n` +
    `Questions: ${questionsSummary}\n` +
    `AnswerIP : ${firstQuestion ? (resolveName(firstQuestion.name) || '(none)') : '(none)'}\n\n` +
    `Query Hex:\n${hex(raw, 512)}\n\n` +
    `Response Hex:\n${hex(response, 512)}\n`;

  writeCapture(base, raw, summary);
  appendEvent(`${proto} QUERY remote=${remoteLabel} q=${questionsSummary} respBytes=${response.length}`);
  writeHealth({
    lastQueryAt: new Date().toISOString(),
    lastQueryName: firstQuestion ? firstQuestion.name : null,
    lastQueryType: firstQuestion ? qtypeName(firstQuestion.qtype) : null,
    lastRemote: remoteLabel,
    lastEvent: {
      at: new Date().toISOString(),
      proto,
      remote: remoteLabel,
      event: 'query',
      question: firstQuestion ? `${firstQuestion.name} ${qtypeName(firstQuestion.qtype)}` : null,
      responseBytes: response.length
    }
  });

  respond(response);
}

writeHealth();
appendEvent(`START pid=${process.pid} answer_ip=${ANSWER_IP}`);

const udp = dgram.createSocket('udp4');

udp.on('message', (msg, rinfo) => {
  writeHealth({ udpQueries: health.udpQueries + 1 });
  handlePacket('udp', msg, `${rinfo.address}:${rinfo.port}`, response => {
    udp.send(response, rinfo.port, rinfo.address);
    appendEvent(`udp RESPONSE remote=${rinfo.address}:${rinfo.port} bytes=${response.length}`);
    writeHealth({ udpResponses: health.udpResponses + 1 });
  });
});

udp.on('listening', () => {
  appendEvent(`UDP_LISTEN ${LISTEN_IP}:${LISTEN_PORT}`);
  writeHealth({
    listening: true,
    listenAddress: `${LISTEN_IP}:${LISTEN_PORT}/udp`
  });
});

udp.on('error', e => {
  appendEvent(`UDP_ERROR ${e.message}`);
  writeHealth({
    lastError: { at: new Date().toISOString(), proto: 'udp', message: e.message },
    lastEvent: { at: new Date().toISOString(), proto: 'udp', event: 'error', message: e.message }
  });
});

const tcp = net.createServer(socket => {
  const remoteLabel = `${socket.remoteAddress}:${socket.remotePort}`;
  let buf = Buffer.alloc(0);

  appendEvent(`tcp OPEN remote=${remoteLabel}`);

  socket.on('data', chunk => {
    buf = Buffer.concat([buf, chunk]);
    while (buf.length >= 2) {
      const len = buf.readUInt16BE(0);
      if (buf.length < 2 + len) return;
      const packet = buf.slice(2, 2 + len);
      buf = buf.slice(2 + len);

      writeHealth({ tcpQueries: health.tcpQueries + 1 });
      handlePacket('tcp', packet, remoteLabel, response => {
        const framed = Buffer.alloc(2 + response.length);
        framed.writeUInt16BE(response.length, 0);
        response.copy(framed, 2);
        socket.write(framed);
        appendEvent(`tcp RESPONSE remote=${remoteLabel} bytes=${response.length}`);
        writeHealth({ tcpResponses: health.tcpResponses + 1 });
      });
    }
  });

  socket.on('end', () => appendEvent(`tcp END remote=${remoteLabel}`));
  socket.on('close', () => appendEvent(`tcp CLOSE remote=${remoteLabel}`));
  socket.on('error', e => {
    appendEvent(`tcp ERROR remote=${remoteLabel} message=${e.message}`);
    writeHealth({
      lastError: { at: new Date().toISOString(), proto: 'tcp', remote: remoteLabel, message: e.message },
      lastEvent: { at: new Date().toISOString(), proto: 'tcp', remote: remoteLabel, event: 'error', message: e.message }
    });
  });
});

tcp.on('listening', () => {
  appendEvent(`TCP_LISTEN ${LISTEN_IP}:${LISTEN_PORT}`);
});

tcp.on('error', e => {
  appendEvent(`TCP_SERVER_ERROR ${e.message}`);
  writeHealth({
    lastError: { at: new Date().toISOString(), proto: 'tcp', message: e.message },
    lastEvent: { at: new Date().toISOString(), proto: 'tcp', event: 'server-error', message: e.message }
  });
});

udp.bind(LISTEN_PORT, LISTEN_IP);
tcp.listen(LISTEN_PORT, LISTEN_IP);

console.log(`DNS logger ready on ${LISTEN_IP}:${LISTEN_PORT}`);
console.log(`Answer IP: ${ANSWER_IP}`);
console.log(`Logs: ${DNS_DIR}`);
console.log('Hosts:');
for (const [name, ip] of HOST_OVERRIDES) {
  console.log(`  ${name} -> ${ip}`);
}
console.log(`  *.yav4.com -> ${ANSWER_IP}`);
console.log(`  *.dnas.playstation.org -> ${ANSWER_IP}`);
console.log(`  *.PCSX2 -> ${ANSWER_IP}  (DEV9 search-domain fallback for slot hostnames)`);
