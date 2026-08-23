/**
 * PAL SN@P datagram codec.
 *
 * Wire facts come from SLES_533.19 main-EE functions:
 * - FUN_001e180c: header fields and low-10-bit inner length.
 * - FUN_001d6988: reliable/ACK/aggregate flag consumers.
 * - FUN_001d63b8: 0x6010 transport ACK layout.
 *
 * Resolved names in the corpus are navigation aids, not original symbols.
 */

export const HEADER_LENGTH = 0x10;
export const LENGTH_MASK = 0x03ff;
/**
 * The "string body" bit, and the client's own chat/game discriminator on
 * op-0x0F: `FUN_001d9f78` case 0xc routes 0x0400-SET frames to the chat parser
 * (slots 0x0B/0x0D) and 0x0400-CLEAR frames to the game module (slot 0x12
 * reliable / 0x14 unreliable), regardless of every other flag
 * (`analysis/LOBBY-CHAT-AND-ACTIONS.md` §3.1; RS1-A §6.2, RS1-C §C1). Chat the
 * client emits carries it (T35 `0xb422`, RS1 `0xb421`); a relayed chat frame
 * without it is transport-acked and then dropped by the dispatcher unrendered -
 * there is no branch for `0x1000`-set/`0x0400`-clear.
 */
export const FLAG_STRING = 0x0400;
export const FLAG_AGGREGATE = 0x0800;
export const FLAG_DATA = 0x1000;
export const FLAG_SET = 0x2000;
export const FLAG_ACK = 0x4000;
export const FLAG_RELIABLE = 0x8000;
export const FLAG_MASK = 0xfc00;
export const MAX_INNER_LENGTH = LENGTH_MASK;
export const SNAP_TRAILER = Buffer.from([0xba, 0x47, 0x66, 0x11]);

export class SnapCodecError extends Error {
  constructor(code, message) {
    super(message);
    this.name = 'SnapCodecError';
    this.code = code;
  }
}

function asUInt32(value, field) {
  if (!Number.isInteger(value) || value < 0 || value > 0xffffffff) {
    throw new SnapCodecError('INVALID_U32', `${field} must be a uint32`);
  }
  return value >>> 0;
}

function tokenBuffer(token) {
  if (Buffer.isBuffer(token)) {
    if (token.length !== 4) {
      throw new SnapCodecError('INVALID_TOKEN', 'token buffer must contain exactly four bytes');
    }
    return Buffer.from(token);
  }

  const encoded = Buffer.alloc(4);
  encoded.writeUInt32BE(asUInt32(token ?? 0, 'token'));
  return encoded;
}

function decodeSegmentAt(bytes, offset, limit) {
  if (limit - offset < HEADER_LENGTH) {
    throw new SnapCodecError(
      'TRUNCATED_HEADER',
      `SN@P segment at 0x${offset.toString(16)} has fewer than 16 header bytes`
    );
  }

  const flagsAndLength = bytes.readUInt16BE(offset);
  const innerLength = flagsAndLength & LENGTH_MASK;
  if (innerLength < HEADER_LENGTH) {
    throw new SnapCodecError(
      'INVALID_LENGTH',
      `SN@P inner length ${innerLength} is smaller than the 16-byte header`
    );
  }
  if (offset + innerLength > limit) {
    throw new SnapCodecError(
      'TRUNCATED_SEGMENT',
      `SN@P segment length ${innerLength} exceeds the datagram body`
    );
  }

  const raw = bytes.subarray(offset, offset + innerLength);
  const token = Buffer.from(raw.subarray(4, 8));
  return {
    raw,
    offset,
    innerLength,
    flagsAndLength,
    flags: flagsAndLength & FLAG_MASK,
    reliable: (flagsAndLength & FLAG_RELIABLE) !== 0,
    acknowledges: (flagsAndLength & FLAG_ACK) !== 0,
    set: (flagsAndLength & FLAG_SET) !== 0,
    data: (flagsAndLength & FLAG_DATA) !== 0,
    aggregate: (flagsAndLength & FLAG_AGGREGATE) !== 0,
    subSelector: raw[2],
    opcode: raw[3],
    opcodeWord: raw.readUInt16BE(2),
    token,
    tokenUInt32BE: token.readUInt32BE(0),
    sequence: raw.readUInt32BE(8),
    acknowledgement: raw.readUInt32BE(12),
    payload: Buffer.from(raw.subarray(HEADER_LENGTH))
  };
}

/**
 * Decode one UDP datagram. The fixed trailer is outside the low-10-bit segment length.
 * Aggregate frames are a concatenation of independently headed segments followed by one trailer.
 */
export function decodeDatagram(datagram) {
  if (!Buffer.isBuffer(datagram)) {
    throw new SnapCodecError('INVALID_DATAGRAM', 'SN@P datagram must be a Buffer');
  }
  if (datagram.length < HEADER_LENGTH + SNAP_TRAILER.length) {
    throw new SnapCodecError('TRUNCATED_DATAGRAM', 'SN@P datagram is shorter than 20 bytes');
  }

  const trailerOffset = datagram.length - SNAP_TRAILER.length;
  const trailer = datagram.subarray(trailerOffset);
  if (!trailer.equals(SNAP_TRAILER)) {
    throw new SnapCodecError(
      'INVALID_TRAILER',
      `unexpected SN@P trailer ${trailer.toString('hex')}`
    );
  }

  const segments = [];
  let offset = 0;
  while (offset < trailerOffset) {
    const segment = decodeSegmentAt(datagram, offset, trailerOffset);
    segments.push(segment);
    offset += segment.innerLength;

    if (segments.length === 1 && offset < trailerOffset && !segment.aggregate) {
      throw new SnapCodecError(
        'UNDECLARED_AGGREGATE',
        'datagram contains another segment but the first segment lacks flag 0x0800'
      );
    }
  }

  if (offset !== trailerOffset) {
    throw new SnapCodecError('MISALIGNED_DATAGRAM', 'SN@P segment lengths do not end at the trailer');
  }

  return {
    raw: datagram,
    trailer: Buffer.from(trailer),
    aggregate: segments.length > 1,
    segments
  };
}

/**
 * Encode one inner segment. No checksum/trailer is appended here.
 */
export function encodeSegment({
  flags = FLAG_SET,
  subSelector = 0,
  opcode = 0,
  token = 0,
  sequence = 0,
  acknowledgement = 0,
  payload = Buffer.alloc(0)
} = {}) {
  if (!Buffer.isBuffer(payload)) {
    throw new SnapCodecError('INVALID_PAYLOAD', 'payload must be a Buffer');
  }
  if (!Number.isInteger(flags) || flags < 0 || flags > 0xffff || (flags & LENGTH_MASK) !== 0) {
    throw new SnapCodecError('INVALID_FLAGS', 'flags must be a uint16 with low 10 bits clear');
  }
  if (!Number.isInteger(subSelector) || subSelector < 0 || subSelector > 0xff) {
    throw new SnapCodecError('INVALID_SUBSELECTOR', 'subSelector must be a byte');
  }
  if (!Number.isInteger(opcode) || opcode < 0 || opcode > 0xff) {
    throw new SnapCodecError('INVALID_OPCODE', 'opcode must be a byte');
  }

  const innerLength = HEADER_LENGTH + payload.length;
  if (innerLength > MAX_INNER_LENGTH) {
    throw new SnapCodecError(
      'PAYLOAD_TOO_LARGE',
      `SN@P inner length ${innerLength} exceeds the 10-bit maximum`
    );
  }

  const encoded = Buffer.alloc(innerLength);
  encoded.writeUInt16BE((flags | innerLength) & 0xffff, 0);
  encoded[2] = subSelector;
  encoded[3] = opcode;
  tokenBuffer(token).copy(encoded, 4);
  encoded.writeUInt32BE(asUInt32(sequence, 'sequence'), 8);
  encoded.writeUInt32BE(asUInt32(acknowledgement, 'acknowledgement'), 12);
  payload.copy(encoded, HEADER_LENGTH);
  return encoded;
}

/**
 * Encode one datagram. More than one segment sets the decoded aggregate bit on the first segment.
 */
export function encodeDatagram(segmentDefinitions) {
  if (!Array.isArray(segmentDefinitions) || segmentDefinitions.length === 0) {
    throw new SnapCodecError('EMPTY_DATAGRAM', 'at least one SN@P segment is required');
  }

  const definitions = segmentDefinitions.map((definition) => ({ ...definition }));
  if (definitions.length > 1) {
    definitions[0].flags = (definitions[0].flags ?? FLAG_SET) | FLAG_AGGREGATE;
  }
  const segments = definitions.map(encodeSegment);
  return Buffer.concat([...segments, SNAP_TRAILER]);
}

/**
 * Build the decoded 0x6010 ACK form:
 * token at +4, local non-data sequence at +8, acknowledged peer sequence at +0x0c.
 */
export function encodeTransportAck({ token, acknowledgedSequence, sequence = 0 }) {
  return encodeDatagram([
    {
      flags: FLAG_ACK | FLAG_SET,
      token,
      sequence,
      acknowledgement: acknowledgedSequence
    }
  ]);
}

