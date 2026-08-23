import crypto from 'node:crypto';

const HTTP_HEADER_LIMIT = 16 * 1024;
const V25_REQUEST_LENGTH = 0x134;
const V25_RESPONSE_MINIMUM = 0x148;
const I_CONNECT_PATH = '/eu-gw/v2.5_i-connect';
const OTHERS_PATH = '/eu-gw/v2.5_others';

const ENVELOPE_K1 = Buffer.from('eb711416cb0ab016', 'hex');
const ENVELOPE_K2 = Buffer.from('ae190174b5ce6339', 'hex');
const ENVELOPE_K3 = Buffer.from('7b01b91880145e34', 'hex');
const ENVELOPE_XOR = Buffer.from('c510a6400a9b022f', 'hex');

export class DnasApplicationError extends Error {
  constructor(code, message) {
    super(message);
    this.name = 'DnasApplicationError';
    this.code = code;
  }
}

function requireRange(buffer, offset, length, field) {
  if (!Buffer.isBuffer(buffer)) {
    throw new TypeError(`${field} source must be a Buffer`);
  }
  if (!Number.isSafeInteger(offset) || !Number.isSafeInteger(length) || offset < 0 || length < 0) {
    throw new TypeError(`${field} range is invalid`);
  }
  if (offset + length > buffer.length) {
    throw new DnasApplicationError(
      'TRUNCATED_FIELD',
      `${field} requires bytes 0x${offset.toString(16)}..0x${(offset + length - 1).toString(16)}`
    );
  }
}

export function parseDnasHttpRequest(requestBytes) {
  if (!Buffer.isBuffer(requestBytes)) {
    throw new TypeError('DNAS HTTP request must be a Buffer');
  }

  const headerEnd = requestBytes.indexOf('\r\n\r\n', 0, 'latin1');
  if (headerEnd < 0) {
    throw new DnasApplicationError('INCOMPLETE_HTTP_HEADERS', 'DNAS HTTP header terminator is missing');
  }
  if (headerEnd > HTTP_HEADER_LIMIT) {
    throw new DnasApplicationError('HTTP_HEADERS_TOO_LARGE', 'DNAS HTTP headers exceed the configured limit');
  }

  const headerText = requestBytes.subarray(0, headerEnd).toString('latin1');
  const lines = headerText.split('\r\n');
  const requestLine = lines.shift() ?? '';
  const match = /^POST ([^ ]+) HTTP\/1\.[01]$/.exec(requestLine);
  if (!match) {
    throw new DnasApplicationError('INVALID_REQUEST_LINE', 'DNAS requires a POST request using HTTP/1.x');
  }

  const headers = new Map();
  for (const line of lines) {
    const separator = line.indexOf(':');
    if (separator <= 0) {
      throw new DnasApplicationError('INVALID_HTTP_HEADER', 'DNAS HTTP header line is malformed');
    }
    const name = line.slice(0, separator).trim().toLowerCase();
    const value = line.slice(separator + 1).trim();
    if (headers.has(name)) {
      throw new DnasApplicationError('DUPLICATE_HTTP_HEADER', `Duplicate DNAS HTTP header: ${name}`);
    }
    headers.set(name, value);
  }

  const rawContentLength = headers.get('content-length');
  if (!rawContentLength || !/^[0-9]+$/.test(rawContentLength)) {
    throw new DnasApplicationError('INVALID_CONTENT_LENGTH', 'DNAS Content-Length is required');
  }
  const contentLength = Number(rawContentLength);
  const body = requestBytes.subarray(headerEnd + 4);
  if (body.length !== contentLength) {
    throw new DnasApplicationError(
      'HTTP_BODY_LENGTH_MISMATCH',
      `DNAS body length ${body.length} does not match Content-Length ${contentLength}`
    );
  }

  return {
    path: match[1],
    httpVersion: requestLine.slice(-8),
    headers,
    body
  };
}

function packetIdentity(body, gameIdOffset) {
  requireRange(body, 0, 4, 'query type');
  requireRange(body, gameIdOffset, 8, 'game ID');
  const queryType = body.subarray(0, 4).toString('hex');
  const gameId = body.subarray(gameIdOffset, gameIdOffset + 8).toString('hex');
  return {
    queryType,
    gameId,
    packetKey: `${gameId}_${queryType}`
  };
}

export function describeDnasRequest({ path, body }) {
  if (path === I_CONNECT_PATH) {
    if (body.length !== V25_REQUEST_LENGTH) {
      throw new DnasApplicationError(
        'UNEXPECTED_I_CONNECT_LENGTH',
        `PAL v2.5_i-connect body must be ${V25_REQUEST_LENGTH} bytes; received ${body.length}`
      );
    }
    return {
      kind: 'v2.5_i-connect',
      gameIdOffset: 0x2c,
      ...packetIdentity(body, 0x2c)
    };
  }

  if (path === OTHERS_PATH) {
    if (body.length !== 184 && body.length !== 44) {
      throw new DnasApplicationError(
        'UNEXPECTED_OTHERS_LENGTH',
        `Observed PAL v2.5_others bodies are 184 or 44 bytes; received ${body.length}`
      );
    }
    return {
      kind: 'v2.5_others',
      gameIdOffset: 0x1b,
      ...packetIdentity(body, 0x1b)
    };
  }

  throw new DnasApplicationError('UNKNOWN_DNAS_PATH', `Unsupported PAL DNAS path: ${path}`);
}

function hmac(name, key, data) {
  return crypto.createHmac(name, key).update(data).digest();
}

function pHash(name, secret, seed, length) {
  let output = Buffer.alloc(0);
  let a = hmac(name, secret, seed);
  while (output.length < length) {
    output = Buffer.concat([output, hmac(name, secret, Buffer.concat([a, seed]))]);
    a = hmac(name, secret, a);
  }
  return output.subarray(0, length);
}

export function tls10Prf(secret, label, seed, length) {
  const half = Math.ceil(secret.length / 2);
  const first = secret.subarray(0, half);
  const second = secret.subarray(secret.length - half);
  const labelSeed = Buffer.concat([Buffer.from(label, 'ascii'), seed]);
  const md5 = pHash('md5', first, labelSeed, length);
  const sha1 = pHash('sha1', second, labelSeed, length);
  const output = Buffer.alloc(length);
  for (let index = 0; index < output.length; index += 1) {
    output[index] = md5[index] ^ sha1[index];
  }
  return output;
}

export function deriveV25ResponseKeys(requestBody) {
  if (requestBody.length !== V25_REQUEST_LENGTH) {
    throw new DnasApplicationError(
      'UNEXPECTED_I_CONNECT_LENGTH',
      `PAL v2.5 key derivation requires ${V25_REQUEST_LENGTH} bytes`
    );
  }
  const checksum1 = crypto.createHash('sha1').update(requestBody.subarray(0x34, 0x134)).digest();
  const checksum2 = crypto.createHash('sha1').update(requestBody.subarray(0x48, 0x134)).digest();
  const fullKey = Buffer.concat([checksum2, checksum1.subarray(0, 0x0c)]);
  return {
    desK1: fullKey.subarray(0x00, 0x08),
    desK2: fullKey.subarray(0x08, 0x10),
    desK3: fullKey.subarray(0x10, 0x18),
    xorSeed: fullKey.subarray(0x18, 0x20)
  };
}

function desEde3Encrypt(k1, k2, k3, block) {
  const cipher = crypto.createCipheriv('des-ede3-ecb', Buffer.concat([k1, k2, k3]), null);
  cipher.setAutoPadding(false);
  return Buffer.concat([cipher.update(block), cipher.final()]);
}

export function encryptDnasRange(source, offset, length, { desK1, desK2, desK3, xorSeed }) {
  if (length % 8 !== 0) {
    throw new DnasApplicationError('INVALID_ENCRYPTION_LENGTH', 'DNAS encrypted range must be block aligned');
  }
  requireRange(source, offset, length, 'DNAS encrypted range');
  for (const [name, value] of Object.entries({ desK1, desK2, desK3, xorSeed })) {
    if (!Buffer.isBuffer(value) || value.length !== 8) {
      throw new DnasApplicationError('INVALID_ENCRYPTION_KEY', `${name} must be exactly 8 bytes`);
    }
  }

  const output = Buffer.from(source);
  let chain = Buffer.from(xorSeed);
  for (let relative = 0; relative < length; relative += 8) {
    const plaintext = output.subarray(offset + relative, offset + relative + 8);
    const mixed = Buffer.alloc(8);
    for (let index = 0; index < 8; index += 1) {
      mixed[index] = plaintext[index] ^ chain[index];
    }
    chain = desEde3Encrypt(desK1, desK2, desK3, mixed);
    chain.copy(output, offset + relative);
  }
  return output;
}

export function transformV25Response(packet, requestBody) {
  if (!Buffer.isBuffer(packet) || packet.length < V25_RESPONSE_MINIMUM) {
    throw new DnasApplicationError(
      'V25_PACKET_TOO_SHORT',
      `PAL v2.5 response asset must contain at least ${V25_RESPONSE_MINIMUM} bytes`
    );
  }

  const requestKeys = deriveV25ResponseKeys(requestBody);
  const withRequestEnvelope = encryptDnasRange(packet, 0xc8, 0x20, requestKeys);
  return encryptDnasRange(withRequestEnvelope, 0x28, 0x120, {
    desK1: ENVELOPE_K1,
    desK2: ENVELOPE_K2,
    desK3: ENVELOPE_K3,
    xorSeed: ENVELOPE_XOR
  });
}

export function encodeDnasHttpResponse(body, { success = true } = {}) {
  if (!Buffer.isBuffer(body)) {
    throw new TypeError('DNAS response body must be a Buffer');
  }
  const status = success ? '200 OK' : '500 Internal Server Error';
  const header = Buffer.from(
    `HTTP/1.0 ${status}\r\nContent-Type: image/gif\r\nContent-Length: ${body.length}\r\n\r\n`,
    'latin1'
  );
  return Buffer.concat([header, body]);
}

export class DnasApplicationService {
  constructor({ packetStore }) {
    if (!packetStore || typeof packetStore.get !== 'function') {
      throw new TypeError('DNAS packet store with get(packetKey) is required');
    }
    this.packetStore = packetStore;
  }

  async handle(requestBytes) {
    try {
      const request = parseDnasHttpRequest(requestBytes);
      const query = describeDnasRequest(request);
      const packet = await this.packetStore.get(query.packetKey);
      if (!packet) {
        throw new DnasApplicationError('PACKET_NOT_FOUND', `No DNAS response asset for ${query.packetKey}`);
      }
      const responseBody = query.kind === 'v2.5_i-connect'
        ? transformV25Response(packet, request.body)
        : Buffer.from(packet);
      return {
        ok: true,
        query,
        responseBody,
        responseBytes: encodeDnasHttpResponse(responseBody)
      };
    } catch (error) {
      if (!(error instanceof DnasApplicationError) && error?.code !== 'INVALID_PACKET_KEY') {
        throw error;
      }
      const responseBody = Buffer.from('ERROR', 'ascii');
      return {
        ok: false,
        errorCode: error.code,
        errorMessage: error.message,
        responseBody,
        responseBytes: encodeDnasHttpResponse(responseBody, { success: false })
      };
    }
  }
}

export const DNAS_APPLICATION_CONSTANTS = Object.freeze({
  HTTP_HEADER_LIMIT,
  V25_REQUEST_LENGTH,
  V25_RESPONSE_MINIMUM,
  I_CONNECT_PATH,
  OTHERS_PATH
});
