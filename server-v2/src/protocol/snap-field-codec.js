const SNAP_FIELD_KEY = Buffer.from('MINAMIOH', 'ascii');

function requireUnsignedByte(value, name) {
  if (!Number.isSafeInteger(value) || value < 0 || value > 0xff) {
    throw new TypeError(`${name} must be an unsigned 8-bit integer`);
  }
}

/**
 * Encode the variable field written by PAL FUN_001c3f40/FUN_001c3650 and
 * consumed by FUN_001c3b90/FUN_001c3750.
 *
 * unknownCodecByte is the low byte of the client connection state word at
 * +0x4c. Runtime evidence observed zero, but the codec accepts the full proven
 * byte domain rather than baking that observation into the transform.
 */
export function encodeSnapField({
  plain,
  maximumDecodedLength,
  sequence,
  unknownCodecByte
}) {
  if (!Buffer.isBuffer(plain)) {
    throw new TypeError('plain must be a Buffer');
  }
  if (!Number.isSafeInteger(maximumDecodedLength) ||
      maximumDecodedLength < 0 || maximumDecodedLength > 0xffff - 2) {
    throw new TypeError('maximumDecodedLength must be an unsigned 16-bit field bound');
  }
  if (plain.length > maximumDecodedLength) {
    throw new RangeError('plain exceeds maximumDecodedLength');
  }
  requireUnsignedByte(sequence, 'sequence');
  requireUnsignedByte(unknownCodecByte, 'unknownCodecByte');

  const output = Buffer.alloc(4 + plain.length);
  output.writeUInt16BE(plain.length + 2, 0);
  let sum = 0;
  for (let index = 0; index < plain.length; index += 1) {
    const byte = plain[index];
    sum += byte;
    output[4 + index] = byte ^ SNAP_FIELD_KEY[index & 7] ^
      ((unknownCodecByte + sequence + index) & 0xff);
  }
  output.writeUInt16BE((sum + sequence * 0x101) & 0x7fff, 2);
  return output;
}

/**
 * Decode one variable field, mirroring PAL FUN_001c3b90/FUN_001c3750.
 *
 * FUN_001c3b90 computes plainLength as lengthWord - 2, returns -1 below zero,
 * -2 when plainLength exceeds the caller's bound, and -3 when the recomputed
 * checksum does not equal the field's second BE16. This returns null in exactly
 * those cases instead of throwing, because the caller decides whether a field it
 * cannot decode is fatal.
 *
 * The checksum makes the decode self-validating: a field that verifies was
 * decoded with the right sequence and codec byte. Callers must therefore treat a
 * null result as "not decodable with these parameters", never as a reason to try
 * other parameters until one fits.
 */
export function decodeSnapField({
  field,
  maximumDecodedLength,
  sequence,
  unknownCodecByte
}) {
  if (!Buffer.isBuffer(field)) {
    throw new TypeError('field must be a Buffer');
  }
  if (!Number.isSafeInteger(maximumDecodedLength) ||
      maximumDecodedLength < 0 || maximumDecodedLength > 0xffff - 2) {
    throw new TypeError('maximumDecodedLength must be an unsigned 16-bit field bound');
  }
  requireUnsignedByte(sequence, 'sequence');
  requireUnsignedByte(unknownCodecByte, 'unknownCodecByte');

  if (field.length < 4) return null;
  const plainLength = field.readUInt16BE(0) - 2;
  if (plainLength < 0) return null;
  if (plainLength > maximumDecodedLength) return null;
  if (field.length < 4 + plainLength) return null;

  const plain = Buffer.alloc(plainLength);
  let sum = 0;
  for (let index = 0; index < plainLength; index += 1) {
    const byte = field[4 + index] ^ SNAP_FIELD_KEY[index & 7] ^
      ((unknownCodecByte + sequence + index) & 0xff);
    plain[index] = byte;
    sum += byte;
  }
  if (((sum + sequence * 0x101) & 0x7fff) !== field.readUInt16BE(2)) return null;
  return plain;
}
