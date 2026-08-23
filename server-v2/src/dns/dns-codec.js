import net from 'node:net';

const DNS_HEADER_LENGTH = 12;
const MAX_DNS_MESSAGE = 4_096;
const TYPE_A = 1;
const TYPE_AAAA = 28;
const TYPE_ANY = 255;
const CLASS_IN = 1;

export class DnsProtocolError extends Error {
  constructor(code, message) {
    super(message);
    this.name = 'DnsProtocolError';
    this.code = code;
  }
}

function parseName(message, startOffset) {
  const labels = [];
  const visited = new Set();
  let offset = startOffset;
  let nextOffset = null;
  let expandedLength = 0;

  for (let steps = 0; steps < 128; steps += 1) {
    if (offset >= message.length) {
      throw new DnsProtocolError('TRUNCATED_NAME', 'DNS name extends beyond the message');
    }
    if (visited.has(offset)) {
      throw new DnsProtocolError('COMPRESSION_LOOP', 'DNS compression pointer loop detected');
    }
    visited.add(offset);
    const length = message[offset];
    if (length === 0) {
      return {
        name: labels.join('.').toLowerCase(),
        nextOffset: nextOffset ?? offset + 1
      };
    }
    if ((length & 0xc0) === 0xc0) {
      if (offset + 1 >= message.length) {
        throw new DnsProtocolError('TRUNCATED_POINTER', 'DNS compression pointer is truncated');
      }
      const pointer = ((length & 0x3f) << 8) | message[offset + 1];
      if (pointer >= message.length) {
        throw new DnsProtocolError('INVALID_POINTER', 'DNS compression pointer is out of bounds');
      }
      nextOffset ??= offset + 2;
      offset = pointer;
      continue;
    }
    if ((length & 0xc0) !== 0 || length > 63) {
      throw new DnsProtocolError('INVALID_LABEL_LENGTH', 'DNS label length is invalid');
    }
    const end = offset + 1 + length;
    if (end > message.length) {
      throw new DnsProtocolError('TRUNCATED_LABEL', 'DNS label is truncated');
    }
    expandedLength += length + (labels.length > 0 ? 1 : 0);
    if (expandedLength > 253) {
      throw new DnsProtocolError('NAME_TOO_LONG', 'DNS name exceeds 253 characters');
    }
    labels.push(message.subarray(offset + 1, end).toString('ascii'));
    offset = end;
  }
  throw new DnsProtocolError('NAME_STEP_LIMIT', 'DNS name exceeded parser step limit');
}

export function parseDnsQuery(message) {
  if (!Buffer.isBuffer(message)) throw new TypeError('DNS message must be a Buffer');
  if (message.length < DNS_HEADER_LENGTH) {
    throw new DnsProtocolError('TRUNCATED_HEADER', 'DNS header is truncated');
  }
  if (message.length > MAX_DNS_MESSAGE) {
    throw new DnsProtocolError('MESSAGE_TOO_LARGE', 'DNS message exceeds configured limit');
  }

  const flags = message.readUInt16BE(2);
  const questionCount = message.readUInt16BE(4);
  if ((flags & 0x8000) !== 0) {
    throw new DnsProtocolError('QUERY_REQUIRED', 'DNS request has the response bit set');
  }
  if (((flags >>> 11) & 0x0f) !== 0) {
    throw new DnsProtocolError('UNSUPPORTED_OPCODE', 'Only standard DNS queries are supported');
  }
  if (questionCount !== 1) {
    throw new DnsProtocolError('QUESTION_COUNT', 'V2 DNS requires exactly one question');
  }

  const parsedName = parseName(message, DNS_HEADER_LENGTH);
  if (parsedName.nextOffset + 4 > message.length) {
    throw new DnsProtocolError('TRUNCATED_QUESTION', 'DNS question type/class is truncated');
  }
  const type = message.readUInt16BE(parsedName.nextOffset);
  const dnsClass = message.readUInt16BE(parsedName.nextOffset + 2);
  const questionEnd = parsedName.nextOffset + 4;
  return {
    id: message.readUInt16BE(0),
    flags,
    name: parsedName.name,
    type,
    dnsClass,
    questionBytes: Buffer.from(message.subarray(DNS_HEADER_LENGTH, questionEnd))
  };
}

function ipv4Bytes(address) {
  if (net.isIP(address) !== 4) {
    throw new TypeError(`DNS A record is not a valid IPv4 address: ${address}`);
  }
  return Buffer.from(address.split('.').map(Number));
}

export function normalizeDnsRecords(records) {
  const normalized = new Map();
  const entries = records instanceof Map ? records.entries() : Object.entries(records ?? {});
  for (const [rawName, address] of entries) {
    const name = String(rawName).toLowerCase().replace(/\.$/, '');
    if (!name || name.includes('*')) {
      throw new TypeError('DNS records require explicit non-wildcard hostnames');
    }
    ipv4Bytes(address);
    normalized.set(name, address);
  }
  return normalized;
}

export function buildDnsResponse(queryMessage, records, { ttl = 60 } = {}) {
  if (!Number.isSafeInteger(ttl) || ttl < 0 || ttl > 0xffffffff) {
    throw new TypeError('DNS TTL must be a uint32');
  }
  const query = parseDnsQuery(queryMessage);
  const recordMap = records instanceof Map ? records : normalizeDnsRecords(records);
  const address = recordMap.get(query.name) ?? null;
  const supportedQuestion = query.dnsClass === CLASS_IN && (query.type === TYPE_A || query.type === TYPE_ANY);
  const answerCount = address && supportedQuestion ? 1 : 0;
  const rcode = address ? 0 : 3;
  const header = Buffer.alloc(DNS_HEADER_LENGTH);
  header.writeUInt16BE(query.id, 0);
  header.writeUInt16BE(0x8080 | (query.flags & 0x0100) | rcode, 2);
  header.writeUInt16BE(1, 4);
  header.writeUInt16BE(answerCount, 6);

  const sections = [header, query.questionBytes];
  if (answerCount === 1) {
    const answer = Buffer.alloc(16);
    answer.writeUInt16BE(0xc00c, 0);
    answer.writeUInt16BE(TYPE_A, 2);
    answer.writeUInt16BE(CLASS_IN, 4);
    answer.writeUInt32BE(ttl, 6);
    answer.writeUInt16BE(4, 10);
    ipv4Bytes(address).copy(answer, 12);
    sections.push(answer);
  }
  return {
    bytes: Buffer.concat(sections),
    query,
    address,
    rcode,
    answerCount
  };
}

export const DNS_CONSTANTS = Object.freeze({
  DNS_HEADER_LENGTH,
  MAX_DNS_MESSAGE,
  TYPE_A,
  TYPE_AAAA,
  TYPE_ANY,
  CLASS_IN
});
