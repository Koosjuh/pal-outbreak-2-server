/**
 * PAL TCP 10127 application framing.
 *
 * Evidence:
 * - SLES_533.19 FUN_001c3880 reads an eight-byte header and byte-swaps the
 *   uint16 at offset zero before reassembling exactly that many body bytes.
 * - SLES_533.19 FUN_001c3c90 writes direction at +2, command bytes at +3/+4,
 *   sequence at +5, status/error at +6, and 0xff at +7 for client requests.
 * - docs/evidence/logs/2026_06_04_22_25_57_snap_session2_trace.log contains
 *   byte-exact request and response frames using this layout.
 */

export const TCP10127_HEADER_LENGTH = 8;
export const TCP10127_MAX_PAYLOAD_LENGTH = 0xffff;

export const TCP10127_DIRECTION = Object.freeze({
  CLIENT_REQUEST: 0x01,
  SERVER_RESPONSE: 0x02,
  SERVER_PUSH: 0x10
});

export class Tcp10127ProtocolError extends Error {
  constructor(code, message) {
    super(message);
    this.name = 'Tcp10127ProtocolError';
    this.code = code;
  }
}

function byte(value, field) {
  if (!Number.isInteger(value) || value < 0 || value > 0xff) {
    throw new Tcp10127ProtocolError('INVALID_BYTE', `${field} must be a byte`);
  }
  return value;
}

function uint16(value, field) {
  if (!Number.isInteger(value) || value < 0 || value > 0xffff) {
    throw new Tcp10127ProtocolError('INVALID_U16', `${field} must be a uint16`);
  }
  return value;
}

function payloadBuffer(payload) {
  if (!Buffer.isBuffer(payload)) {
    throw new Tcp10127ProtocolError('INVALID_PAYLOAD', 'payload must be a Buffer');
  }
  if (payload.length > TCP10127_MAX_PAYLOAD_LENGTH) {
    throw new Tcp10127ProtocolError(
      'PAYLOAD_TOO_LARGE',
      `payload length ${payload.length} exceeds the uint16 wire limit`
    );
  }
  return payload;
}

export function encodeTcp10127Frame({
  direction,
  command,
  sequence = 0,
  error = 0,
  unknown7 = 0xff,
  payload = Buffer.alloc(0)
}) {
  const body = payloadBuffer(payload);
  const frame = Buffer.alloc(TCP10127_HEADER_LENGTH + body.length);
  frame.writeUInt16BE(body.length, 0);
  frame[2] = byte(direction, 'direction');
  frame.writeUInt16BE(uint16(command, 'command'), 3);
  frame[5] = byte(sequence, 'sequence');
  frame[6] = byte(error, 'error');
  frame[7] = byte(unknown7, 'unknown7');
  body.copy(frame, TCP10127_HEADER_LENGTH);
  return frame;
}

export function decodeTcp10127Frame(frame, { maxPayloadLength = TCP10127_MAX_PAYLOAD_LENGTH } = {}) {
  if (!Buffer.isBuffer(frame)) {
    throw new Tcp10127ProtocolError('INVALID_FRAME', 'frame must be a Buffer');
  }
  if (!Number.isInteger(maxPayloadLength) || maxPayloadLength < 0 || maxPayloadLength > 0xffff) {
    throw new Tcp10127ProtocolError(
      'INVALID_MAX_PAYLOAD_LENGTH',
      'maxPayloadLength must be a uint16'
    );
  }
  if (frame.length < TCP10127_HEADER_LENGTH) {
    throw new Tcp10127ProtocolError('TRUNCATED_HEADER', 'frame has fewer than eight header bytes');
  }

  const payloadLength = frame.readUInt16BE(0);
  if (payloadLength > maxPayloadLength) {
    throw new Tcp10127ProtocolError(
      'PAYLOAD_LIMIT',
      `declared payload length ${payloadLength} exceeds configured limit ${maxPayloadLength}`
    );
  }
  const expectedLength = TCP10127_HEADER_LENGTH + payloadLength;
  if (frame.length !== expectedLength) {
    throw new Tcp10127ProtocolError(
      frame.length < expectedLength ? 'TRUNCATED_PAYLOAD' : 'TRAILING_BYTES',
      `frame length ${frame.length} does not match declared length ${expectedLength}`
    );
  }

  return {
    raw: Buffer.from(frame),
    payloadLength,
    direction: frame[2],
    command: frame.readUInt16BE(3),
    sequence: frame[5],
    error: frame[6],
    unknown7: frame[7],
    payload: Buffer.from(frame.subarray(TCP10127_HEADER_LENGTH))
  };
}

export class Tcp10127StreamDecoder {
  #buffer = Buffer.alloc(0);
  #maxPayloadLength;

  constructor({ maxPayloadLength = TCP10127_MAX_PAYLOAD_LENGTH } = {}) {
    if (!Number.isInteger(maxPayloadLength) || maxPayloadLength < 0 || maxPayloadLength > 0xffff) {
      throw new Tcp10127ProtocolError(
        'INVALID_MAX_PAYLOAD_LENGTH',
        'maxPayloadLength must be a uint16'
      );
    }
    this.#maxPayloadLength = maxPayloadLength;
  }

  get bufferedLength() {
    return this.#buffer.length;
  }

  push(chunk) {
    if (!Buffer.isBuffer(chunk)) {
      throw new Tcp10127ProtocolError('INVALID_CHUNK', 'stream chunk must be a Buffer');
    }
    if (chunk.length !== 0) {
      this.#buffer = this.#buffer.length === 0
        ? Buffer.from(chunk)
        : Buffer.concat([this.#buffer, chunk]);
    }

    const frames = [];
    while (this.#buffer.length >= TCP10127_HEADER_LENGTH) {
      const payloadLength = this.#buffer.readUInt16BE(0);
      if (payloadLength > this.#maxPayloadLength) {
        throw new Tcp10127ProtocolError(
          'PAYLOAD_LIMIT',
          `declared payload length ${payloadLength} exceeds configured limit ${this.#maxPayloadLength}`
        );
      }
      const frameLength = TCP10127_HEADER_LENGTH + payloadLength;
      if (this.#buffer.length < frameLength) break;
      const frame = this.#buffer.subarray(0, frameLength);
      frames.push(decodeTcp10127Frame(frame, { maxPayloadLength: this.#maxPayloadLength }));
      this.#buffer = Buffer.from(this.#buffer.subarray(frameLength));
    }
    return frames;
  }

  finish() {
    if (this.#buffer.length !== 0) {
      throw new Tcp10127ProtocolError(
        this.#buffer.length < TCP10127_HEADER_LENGTH ? 'TRUNCATED_HEADER' : 'TRUNCATED_PAYLOAD',
        `stream ended with ${this.#buffer.length} unconsumed bytes`
      );
    }
  }
}

