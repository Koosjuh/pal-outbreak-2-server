/**
 * SN@P UDP :9090 datagram framing, and the REGISTER (cmd 0x2c) / REGISTER-REPLY
 * (cmd 0x2d) exchange.
 *
 * Byte-for-byte specification and its evidence:
 * `docs/findings/protocol/UDP9090-REGISTER-RE-2026-08-03.md`.
 *
 * Two receive gates in the client will silently discard an otherwise perfect
 * reply, and both are easy to mistake for a crypto failure:
 *
 *   1. `FUN_001d72a8` drops the datagram unless its source IP:port exactly
 *      match `conn+0x4c`/`conn+0x4a` - serverIP:9090 at register time. So the
 *      service must bind the interface address, NOT 0.0.0.0, or the reply can
 *      leave from a different source address on a multi-homed host.
 *   2. `FUN_001edd9c` walks the datagram's messages and requires every length
 *      to be >= 0x10 and <= remaining, and the lengths to sum to EXACTLY
 *      datagramLength - 4. Any mismatch discards the whole datagram.
 *
 * Length is always derived from the header's own `who & 0x3ff`. Never from
 * `udp.length` (which includes the 8-byte UDP header and has misled a previous
 * session) and never from an assumed constant.
 */

const HEADER_BYTES = 0x10;
const TRAILER_BYTES = 4;
/** Minimum datagram the client's own receive path accepts (`FUN_001d72a8`). */
export const MIN_DATAGRAM_BYTES = 20;

/**
 * Constant framing trailer, appended once per datagram by `FUN_001d6468` as
 * `FUN_001e2304(0xba476611)`. The client validates the top THREE bytes only
 * (`if (uVar9 == 0xba476600)`), so the low byte is not checked. It is not a
 * token and not a checksum - correcting V1's file-header comment, which read
 * `00 30 ba 47 66 11` as a session token when `00 30` is the MR TLV value 48.
 */
export const DATAGRAM_TRAILER = Buffer.from([0xba, 0x47, 0x66, 0x11]);
const TRAILER_MASK = 0xffffff00;
const TRAILER_EXPECTED = 0xba476600;

export const OPCODE_REGISTER = 0x2c;
export const OPCODE_REGISTER_REPLY = 0x2d;

/** `who` flag bits. `0x0800` and `0x4000` are load-bearing on receive. */
export const WHO_RELIABLE = 0x8000;
export const WHO_CARRIES_ACK = 0x4000;
export const WHO_SET = 0x2000;
export const WHO_DATA = 0x1000;
export const WHO_MORE_MESSAGES = 0x0800;
export const WHO_LENGTH_MASK = 0x03ff;

/** Request body field offsets, relative to wire+0x10. */
const BODY_LOGIN_IDENTITY = 0x00;
const BODY_LOGIN_IDENTITY_BYTES = 0x28;
const BODY_AUTH = 0x28;
const BODY_AUTH_BYTES = 0x3c;
const BODY_SELECTOR = 0x64;
const BODY_RESERVED = 0x68;
const BODY_CLIENT_IPV4 = 0x6c;
const BODY_CLIENT_PORT = 0x70;
const BODY_QUANTUM = 0x74;
const BODY_TLV_COUNT = 0x78;
const BODY_TLV_FIRST = 0x7a;
const TLV_STRIDE = 6;

/** Reply plaintext field offsets. The plaintext is 0x80 bytes. */
export const REPLY_PLAINTEXT_BYTES = 0x80;
const PLAIN_LOGIN_IDENTITY = 0x00;
const PLAIN_SERVER_IPV4 = 0x28;
const PLAIN_PORT_AT_BIND = 0x2c;
const PLAIN_PORT_NOW = 0x30;
const PLAIN_TAIL_LENGTH = 0x34;
const PLAIN_SESSION_ID = 0x38;
const PLAIN_TAIL_BLOB = 0x3c;

/**
 * THE CLIENT'S CAPACITY, AS A PRODUCTION SAFETY INVARIANT.
 *
 * `FUN_001d9678:42-48` reads the BE32 tail length out of OUR decrypted reply
 * and `memcpy`s that many bytes to `conn+0xac` **with no clamp of any kind**.
 * The server is the only thing between a bad length and remote memory
 * corruption in an unmodified retail client, and a crashed retail client is
 * indistinguishable from a protocol bug - which is why this is a safety
 * invariant and not a tuning parameter.
 *
 * | length | consequence in the client |
 * |---|---|
 * | <= 0x100 | inside the echo window `conn+0xac..0x1ab`; safe |
 * | > 0x100 | corrupts the lobby session blob at `conn+0x1ac` |
 * | >= 0x3d8 | overwrites the ACCOUNT PASSWORD at `conn+0x484` |
 * | ~0x578 | overruns the 0x624 connection allocation |
 *
 * These are named and asserted against DIRECTLY. The obvious bound -
 * `REPLY_PLAINTEXT_BYTES - PLAIN_TAIL_BLOB` = 68 - is a bound on OUR buffer,
 * and it is only safe today by the coincidence that our plaintext is small. It
 * would widen silently the moment anyone extended the plaintext, and the
 * client's limit appears nowhere in that arithmetic.
 */
export const CLIENT_TAIL_ECHO_WINDOW_BYTES = 0x100;
export const CLIENT_TAIL_PASSWORD_OVERWRITE_BYTES = 0x3d8;
export const CLIENT_TAIL_ALLOCATION_OVERRUN_BYTES = 0x578;

/**
 * The ONLY tail length V2 emits.
 *
 * 16 bytes = 128 bits of entropy, the attachment nonce. Any other length is
 * refused at construction rather than clamped: a clamp turns a caller's mistake
 * into a silently different wire value, and this is the one field where a
 * mistake reaches into the client's memory.
 */
export const REGISTRATION_NONCE_BYTES = 0x10;

/**
 * The bind echoes the tail back at BODY offsets 0x24 (BE32 length) and 0x28
 * (the bytes). `conn+0xa8`/`conn+0xac` sit at those offsets inside the
 * 0x128-byte connection template that `FUN_001d6ee0:12,17` copies into the bind
 * body, so the echo is structural rather than a field the client rebuilds.
 */
const BIND_TAIL_LENGTH = 0x24;
const BIND_TAIL_BLOB = 0x28;

export class SnapUdpFramingError extends Error {
  constructor(code, message) {
    super(message);
    this.name = 'SnapUdpFramingError';
    this.code = code;
  }
}

const fail = (code, message) => {
  throw new SnapUdpFramingError(code, message);
};

/** Read a NUL-terminated C string out of a fixed-width, NUL-padded field. */
function readPaddedString(buffer, offset, width) {
  const field = buffer.subarray(offset, offset + width);
  const end = field.indexOf(0);
  return field.subarray(0, end === -1 ? field.length : end).toString('latin1');
}

/** Write a NUL-padded fixed-width field, refusing anything that will not fit. */
function writePaddedString(buffer, offset, width, value) {
  const bytes = Buffer.from(String(value ?? ''), 'latin1');
  // The field must hold the string AND a terminator: the client `strcmp`s it.
  if (bytes.length >= width) {
    fail('FIELD_TOO_LONG', `value of ${bytes.length} bytes does not fit a ${width}-byte field`);
  }
  bytes.copy(buffer, offset);
}

/**
 * Split a datagram into its SN@P messages, enforcing exactly the constraints the
 * client's own receive path enforces. Fails closed: any framing violation
 * rejects the whole datagram, which is what the client does.
 */
export function decodeSnapUdpDatagram(datagram) {
  if (!Buffer.isBuffer(datagram)) fail('NOT_A_BUFFER', 'datagram must be a Buffer');
  if (datagram.length < MIN_DATAGRAM_BYTES) {
    fail('TOO_SHORT', `datagram of ${datagram.length} bytes is below the ${MIN_DATAGRAM_BYTES} minimum`);
  }
  const trailer = datagram.readUInt32BE(datagram.length - TRAILER_BYTES);
  if ((trailer & TRAILER_MASK) >>> 0 !== TRAILER_EXPECTED) {
    fail('BAD_TRAILER', `trailer 0x${trailer.toString(16)} does not match 0xba4766xx`);
  }

  const payloadEnd = datagram.length - TRAILER_BYTES;
  const messages = [];
  let offset = 0;
  while (offset < payloadEnd) {
    if (payloadEnd - offset < HEADER_BYTES) {
      fail('TRUNCATED_HEADER', `${payloadEnd - offset} bytes left, need ${HEADER_BYTES}`);
    }
    const who = datagram.readUInt16BE(offset);
    const length = who & WHO_LENGTH_MASK;
    if (length < HEADER_BYTES) {
      fail('MESSAGE_TOO_SHORT', `message length ${length} is below the ${HEADER_BYTES}-byte header`);
    }
    if (offset + length > payloadEnd) {
      fail('MESSAGE_OVERRUNS', `message length ${length} overruns the datagram`);
    }
    messages.push({
      who,
      flags: who & ~WHO_LENGTH_MASK,
      length,
      subSelector: datagram.readUInt8(offset + 0x02),
      // The client's dispatcher masks the opcode with 0x7f.
      opcode: datagram.readUInt8(offset + 0x03) & 0x7f,
      endpointToken: datagram.readUInt32BE(offset + 0x04),
      sequence: datagram.readUInt32BE(offset + 0x08),
      acknowledgement: datagram.readUInt32BE(offset + 0x0c),
      body: datagram.subarray(offset + HEADER_BYTES, offset + length)
    });
    offset += length;
  }

  // The lengths must close EXACTLY on datagramLength - 4 - the gate that makes
  // a correct-looking datagram vanish without a trace. The per-message overrun
  // check above already guarantees this, so it is a defensive invariant rather
  // than a reachable branch; trailing slack surfaces as TRUNCATED_HEADER or
  // MESSAGE_TOO_SHORT before it can get here.
  /* c8 ignore next 3 */
  if (offset !== payloadEnd) {
    fail('LENGTH_SUM_MISMATCH', `message lengths sum to ${offset}, expected ${payloadEnd}`);
  }
  if (messages.length === 0) fail('NO_MESSAGES', 'datagram carries no messages');
  return messages;
}

/**
 * Decode a REGISTER (cmd 0x2c) message body.
 *
 * `loginIdentity` is the account key: it is what the client's account-creation
 * flow wrote to its memory card, and it is what the register reply must be
 * Blowfish-keyed against. It is NOT a display name.
 */
export function decodeRegisterRequest(message) {
  if (message.opcode !== OPCODE_REGISTER) {
    fail('NOT_A_REGISTER', `opcode 0x${message.opcode.toString(16)} is not 0x2c`);
  }
  const body = message.body;
  // 0x78 fixed fields plus a 2-byte TLV count; TLVs themselves are optional.
  if (body.length < BODY_TLV_COUNT + 2) {
    fail('BODY_TOO_SHORT', `register body of ${body.length} bytes is too short`);
  }

  const tlvCount = body.readUInt16BE(BODY_TLV_COUNT);
  const tlvBytes = tlvCount * TLV_STRIDE;
  if (BODY_TLV_FIRST + tlvBytes > body.length) {
    fail('TLV_OVERRUNS', `${tlvCount} TLVs overrun the ${body.length}-byte body`);
  }
  const tlvs = [];
  for (let index = 0; index < tlvCount; index += 1) {
    const at = BODY_TLV_FIRST + index * TLV_STRIDE;
    tlvs.push({
      // 'LC' = INITIAL_LATENCY, 'MR' = MAX_RETRIES (ELF strings 0x259290/0x2592a0).
      tag: body.subarray(at, at + 2).toString('latin1'),
      value: body.readUInt32BE(at + 2)
    });
  }

  return {
    loginIdentity: readPaddedString(body, BODY_LOGIN_IDENTITY, BODY_LOGIN_IDENTITY_BYTES),
    auth: readPaddedString(body, BODY_AUTH, BODY_AUTH_BYTES),
    // A call-site literal (0xcaf3) the client echoes verbatim; opaque to us.
    selector: body.readUInt32BE(BODY_SELECTOR),
    reserved: body.readUInt32BE(BODY_RESERVED),
    // Already network order in the client's buffer, so kept as raw bytes.
    clientIpv4: Buffer.from(body.subarray(BODY_CLIENT_IPV4, BODY_CLIENT_IPV4 + 4)),
    clientPort: body.readUInt32BE(BODY_CLIENT_PORT),
    quantum: body.readUInt32BE(BODY_QUANTUM),
    tlvs,
    endpointToken: message.endpointToken
  };
}

/**
 * Build the 0x80-byte reply PLAINTEXT. Encrypting it is the caller's job,
 * because only the caller knows the account password.
 *
 * `loginIdentity` must be the string the client sent: after decrypting, the
 * client does `strcmp(plaintext, conn+0x4ac)` against its own value. That
 * comparison IS the authentication - there is no status field in a 0x2d.
 */
export function buildRegisterReplyPlaintext({
  loginIdentity,
  serverIpv4,
  portNow,
  portAtBind = 0,
  sessionId = 0,
  tailBlob = null
}) {
  const plaintext = Buffer.alloc(REPLY_PLAINTEXT_BYTES);
  writePaddedString(plaintext, PLAIN_LOGIN_IDENTITY, BODY_LOGIN_IDENTITY_BYTES, loginIdentity);

  // Validate BEFORE building a Buffer: Buffer.from coerces NaN to 0 and
  // truncates >255, so '999.1.2.abc' would silently become a different, wrong
  // address at +0x28 - the client would then send every post-register datagram
  // somewhere else, with the crypto looking perfectly fine.
  let address;
  if (Buffer.isBuffer(serverIpv4)) {
    address = serverIpv4;
  } else {
    const parts = String(serverIpv4).split('.');
    const octets = parts.map((part) => (/^[0-9]{1,3}$/.test(part.trim()) ? Number(part) : NaN));
    if (parts.length !== 4 || octets.some((octet) => !Number.isInteger(octet) || octet > 255)) {
      fail('BAD_SERVER_ADDRESS', `serverIpv4 must be dotted-quad IPv4, got ${serverIpv4}`);
    }
    address = Buffer.from(octets);
  }
  if (address.length !== 4) fail('BAD_SERVER_ADDRESS', 'serverIpv4 must be four octets');
  address.copy(plaintext, PLAIN_SERVER_IPV4);

  // +0x30 is applied immediately; +0x2c only at bind time, and the client
  // re-points its socket to it ONLY when non-zero, so 0 keeps the port below.
  plaintext.writeUInt32BE(portNow >>> 0, PLAIN_PORT_NOW);
  plaintext.writeUInt32BE(portAtBind >>> 0, PLAIN_PORT_AT_BIND);
  plaintext.writeUInt32BE(sessionId >>> 0, PLAIN_SESSION_ID);

  /*
   * THE ATTACHMENT NONCE. Length 0 (absent) or exactly 16 bytes - nothing else.
   *
   * Three independent bounds, checked in order of severity so the error names
   * the real problem rather than the first one tripped:
   *   1. the CLIENT's unbounded memcpy (see the invariants above) - the one
   *      that matters, and the one that is not implied by our own buffer size;
   *   2. our own plaintext room, which must also hold;
   *   3. the exact supported length, because a value we did not intend to send
   *      is a defect even when it is safe.
   * Refused, never clamped: a clamp turns a caller's mistake into a silently
   * different wire value.
   */
  if (tailBlob != null && !Buffer.isBuffer(tailBlob)) {
    // Type BEFORE length: otherwise '', [], {length:0} and a Buffer whose
    // `length` was redefined all take the silent no-tail path, and "refused,
    // never clamped" would not hold for them.
    fail('TAIL_BLOB_TYPE', 'tailBlob must be a Buffer');
  }
  if (tailBlob != null && tailBlob.length > 0) {
    if (tailBlob.length >= CLIENT_TAIL_ALLOCATION_OVERRUN_BYTES) {
      fail(
        'TAIL_BLOB_OVERRUNS_CLIENT',
        `tail blob of ${tailBlob.length} bytes would overrun the client's 0x624 connection ` +
        'allocation; refusing to emit it'
      );
    }
    if (tailBlob.length >= CLIENT_TAIL_PASSWORD_OVERWRITE_BYTES) {
      fail(
        'TAIL_BLOB_OVERRUNS_CLIENT',
        `tail blob of ${tailBlob.length} bytes would overwrite the account password at the ` +
        "client's conn+0x484; refusing to emit it"
      );
    }
    if (tailBlob.length > CLIENT_TAIL_ECHO_WINDOW_BYTES) {
      fail(
        'TAIL_BLOB_OVERRUNS_CLIENT',
        `tail blob of ${tailBlob.length} bytes exceeds the client's ` +
        `${CLIENT_TAIL_ECHO_WINDOW_BYTES}-byte echo window and would corrupt the lobby blob`
      );
    }
    const room = REPLY_PLAINTEXT_BYTES - PLAIN_TAIL_BLOB;
    if (tailBlob.length > room) {
      fail('TAIL_BLOB_TOO_LONG', `tail blob of ${tailBlob.length} bytes exceeds ${room}`);
    }
    if (tailBlob.length !== REGISTRATION_NONCE_BYTES) {
      fail(
        'TAIL_BLOB_UNSUPPORTED_LENGTH',
        `V2 emits a tail blob of exactly ${REGISTRATION_NONCE_BYTES} bytes or none at all; ` +
        `refusing ${tailBlob.length}`
      );
    }
    plaintext.writeUInt32BE(REGISTRATION_NONCE_BYTES, PLAIN_TAIL_LENGTH);
    // Copy EXACTLY the length that was validated. `copy` with no end argument
    // uses the buffer's real byte length, which is not necessarily the
    // `.length` the checks above read - and for a field whose entire point is
    // "the checked length is the emitted length", that gap should not exist.
    tailBlob.copy(plaintext, PLAIN_TAIL_BLOB, 0, REGISTRATION_NONCE_BYTES);
  }
  return plaintext;
}

/*
 * STARTUP ASSERTION. The serialized reply must stay inside the proven V1
 * layout: a 16-byte nonce at plaintext +0x3c ends at +0x4c, which must remain
 * within the 0x80-byte plaintext AND inside the 128 bytes V1 encrypted and the
 * client provably accepted. If anyone moves an offset, this fails at import
 * rather than on the wire in front of a real client.
 */
if (PLAIN_TAIL_BLOB + REGISTRATION_NONCE_BYTES > REPLY_PLAINTEXT_BYTES) {
  throw new Error(
    `register reply layout is broken: a ${REGISTRATION_NONCE_BYTES}-byte tail at ` +
    `0x${PLAIN_TAIL_BLOB.toString(16)} does not fit the ` +
    `0x${REPLY_PLAINTEXT_BYTES.toString(16)}-byte plaintext`
  );
}
if (REGISTRATION_NONCE_BYTES > CLIENT_TAIL_ECHO_WINDOW_BYTES) {
  throw new Error('the configured nonce length exceeds the client echo window');
}

/**
 * Read the tail the client echoed back in its bind.
 *
 * Returns `null` when the body is too short to carry the field at all, and a
 * zero-length blob when the client echoed length 0 - the two are different, and
 * conflating them would make a truncated bind look like an honest empty one.
 *
 * The declared length is validated against the body the client actually sent
 * before any slice, because this is client-controlled input: a bind claiming a
 * huge tail must be refused, not believed.
 */
export function readBindTailBlob(message) {
  const body = message?.body;
  if (!Buffer.isBuffer(body)) return null;
  if (body.length < BIND_TAIL_BLOB) return null;
  const declaredLength = body.readUInt32BE(BIND_TAIL_LENGTH);
  if (declaredLength === 0) return { declaredLength: 0, blob: Buffer.alloc(0) };
  if (declaredLength > CLIENT_TAIL_ECHO_WINDOW_BYTES) {
    return { declaredLength, blob: null, refusal: 'declared tail exceeds the client echo window' };
  }
  if (BIND_TAIL_BLOB + declaredLength > body.length) {
    return { declaredLength, blob: null, refusal: 'declared tail runs past the bind body' };
  }
  return {
    declaredLength,
    blob: Buffer.from(body.subarray(BIND_TAIL_BLOB, BIND_TAIL_BLOB + declaredLength))
  };
}

/**
 * Frame an encrypted reply body into the 154-byte 0x2d datagram.
 *
 * V1 encrypted only the first 0x80 bytes and left wire 0x90..0x95 as filler,
 * and that is rig-proven, so it is what we do. The client reads
 * `ceil((who & 0x3ff) - 0x10) / 8` = 17 blocks, overrunning two bytes into the
 * trailer. That safety was previously argued from the tail-blob length being
 * ZERO, which T33 makes false - it can now be 16. The conclusion survives on
 * the offset instead: a 16-byte tail at plaintext +0x3c ends at +0x4c, block 9
 * of 17, so the 17th block is still never reached. Restated rather than
 * deleted, because the old premise is exactly the kind that rots silently.
 */
export function encodeRegisterReply({
  encryptedBody,
  endpointToken,
  sequence = 0,
  acknowledgement = 0,
  filler = null
}) {
  if (encryptedBody.length !== REPLY_PLAINTEXT_BYTES) {
    fail('BAD_BODY_LENGTH', `encrypted body must be ${REPLY_PLAINTEXT_BYTES} bytes`);
  }
  const fillerBytes = filler ?? Buffer.alloc(6);
  if (fillerBytes.length !== 6) fail('BAD_FILLER_LENGTH', 'filler must be 6 bytes');

  const messageLength = HEADER_BYTES + encryptedBody.length + fillerBytes.length; // 0x96
  const datagram = Buffer.alloc(messageLength + TRAILER_BYTES); // 154

  // RELIABLE | set | DATA, with the length in the low 10 bits. V1 rig-proven.
  datagram.writeUInt16BE((WHO_RELIABLE | WHO_SET | WHO_DATA | messageLength) >>> 0, 0x00);
  datagram.writeUInt8(0x00, 0x02);
  datagram.writeUInt8(OPCODE_REGISTER_REPLY, 0x03);
  // Echoed, not recomputed: the client derives it from its own address and port.
  datagram.writeUInt32BE(endpointToken >>> 0, 0x04);
  datagram.writeUInt32BE(sequence >>> 0, 0x08);
  datagram.writeUInt32BE(acknowledgement >>> 0, 0x0c);
  encryptedBody.copy(datagram, HEADER_BYTES);
  fillerBytes.copy(datagram, HEADER_BYTES + encryptedBody.length);
  DATAGRAM_TRAILER.copy(datagram, messageLength);
  return datagram;
}

/* -------------------------------------------------------------------------
 * Post-register bind (opcode 0x01) and the slot-0x1c push (opcode 0x28).
 * Specification and evidence: docs/findings/protocol/UDP9090-BIND-RE-2026-08-03.md
 * ---------------------------------------------------------------------- */

export const OPCODE_BIND = 0x01;
export const OPCODE_APP_ACK = 0x02;
export const OPCODE_TRANSPORT_ACK = 0x00;
export const OPCODE_SLOT1C_PUSH = 0x28;

/** Bind body offsets, relative to wire+0x10. */
const BIND_CLIENT_IPV4 = 0x00;
const BIND_UNKNOWN_WORD0 = 0x04;
const BIND_UNKNOWN_WORD1 = 0x08;
const BIND_CLIENT_PORT = 0x0c;
const BIND_QUANTUM = 0x0e;
const BIND_ENDPOINT_NAME = 0x10;
// A 16-byte NUL-padded field. Corroborated by the capture (wire 0x50..0x5f holds
// "test123-" then NULs, and the selector's `00 00 ca f3` begins at wire 0x60)
// and by FUN_00626900, which appends the dash only when len < 0xf - i.e. 15
// characters plus a terminator.
const BIND_ENDPOINT_NAME_BYTES = 0x10;
// BE32, encoded exactly like the register's own selector at its body +0x64.
const BIND_SELECTOR = 0x20;
/**
 * The bind's body is a 0x128-byte template followed by a TLV list, so the list
 * sits at the END of the body rather than at a fixed offset. Confirmed in the
 * real capture: the last 14 bytes before the trailer are
 * `0002 4d52 00000030 4c43 00000640` - count 2, then MR=48, then LC=1600, in
 * the REVERSE order of the register's `LC, MR`.
 */
const BIND_TLV_BLOCK_BYTES = 0x0e;

/**
 * Decode the post-register bind.
 *
 * The bind carries NO credential. Its only identity-bearing field is the
 * endpoint name, which is the login identity with a trailing `0x2d` appended by
 * `FUN_00626900` - client-supplied, so it is a correlation hint and never an
 * authenticator. The register is what authenticated.
 *
 * Nothing in the reply depends on any body field, so this validates the shape
 * and surfaces what is useful for correlation and logging, leaving the two
 * unknown words opaque rather than guessing at them (U1).
 */
export function decodeBindRequest(message) {
  if (message.opcode !== OPCODE_BIND) {
    fail('NOT_A_BIND', `opcode 0x${message.opcode.toString(16)} is not 0x01`);
  }
  const body = message.body;
  if (body.length < BIND_SELECTOR + 4) {
    fail('BIND_BODY_TOO_SHORT', `bind body of ${body.length} bytes is too short`);
  }

  const endpointName = readPaddedString(body, BIND_ENDPOINT_NAME, BIND_ENDPOINT_NAME_BYTES);

  // The TLV list trails the body. Decoded because it is proven present in the
  // real capture and because leaving it undecoded invites the next reader to
  // assume the tail is padding.
  const tlvs = [];
  if (body.length >= BIND_TLV_BLOCK_BYTES) {
    const at = body.length - BIND_TLV_BLOCK_BYTES;
    const count = body.readUInt16BE(at);
    if (count * TLV_STRIDE === BIND_TLV_BLOCK_BYTES - 2) {
      for (let index = 0; index < count; index += 1) {
        const entry = at + 2 + index * TLV_STRIDE;
        tlvs.push({
          tag: body.subarray(entry, entry + 2).toString('latin1'),
          value: body.readUInt32BE(entry + 2)
        });
      }
    }
  }

  return {
    tlvs,
    clientIpv4: Buffer.from(body.subarray(BIND_CLIENT_IPV4, BIND_CLIENT_IPV4 + 4)),
    unknownWord0: body.readUInt32BE(BIND_UNKNOWN_WORD0),
    unknownWord1: body.readUInt32BE(BIND_UNKNOWN_WORD1),
    clientPort: body.readUInt16BE(BIND_CLIENT_PORT),
    quantum: body.readUInt16BE(BIND_QUANTUM),
    endpointName,
    // Both roster fillers strip a trailing dash, and `FUN_00626900` appends one
    // for any name shorter than 15. Strip it back off to recover the identity.
    endpointIdentity: endpointName.endsWith('-') ? endpointName.slice(0, -1) : endpointName,
    selector: body.readUInt32BE(BIND_SELECTOR),
    endpointToken: message.endpointToken,
    sequence: message.sequence
  };
}

/**
 * A 20-byte transport ACK.
 *
 * `who = 0x6010`: flags `0x4000` CARRIES_ACK | `0x2000` SET, length 0x10. The
 * RELIABLE bit is deliberately NOT set, so this consumes no sequence number.
 *
 * The ACK field at +0x0c is the ONLY dynamic field, and it is the sequence of
 * the message being acknowledged. Across the 41 archived V1 sessions it takes
 * values 0x00, 0x05, 0x07 ... 0x2c and rises within a session, so emitting a
 * constant here would have been wrong - it only looks right at the bind, whose
 * sequence happens to be 0.
 */
export function encodeTransportAck({ endpointToken, acknowledgedSequence }) {
  const messageLength = HEADER_BYTES;
  const datagram = Buffer.alloc(messageLength + TRAILER_BYTES);
  datagram.writeUInt16BE((WHO_CARRIES_ACK | WHO_SET | messageLength) >>> 0, 0x00);
  datagram.writeUInt8(0x00, 0x02);
  datagram.writeUInt8(OPCODE_TRANSPORT_ACK, 0x03);
  datagram.writeUInt32BE(endpointToken >>> 0, 0x04);
  datagram.writeUInt32BE(0, 0x08);
  datagram.writeUInt32BE(acknowledgedSequence >>> 0, 0x0c);
  DATAGRAM_TRAILER.copy(datagram, messageLength);
  return datagram;
}

/**
 * The 28-byte slot-`0x1c` push: opcode `0x28`, selector 1, status 0.
 *
 * Across all 41 archived V1 sessions this datagram has exactly TWO distinct
 * forms, differing ONLY in the endpoint token (one per test console). Every
 * other byte - including selector 1 and status 0 - is identical everywhere, so
 * they are captured constants rather than anything derived.
 *
 * The sequence is 0. See U2: the register reply and this push both carry 0 while
 * V1's own counter reached 1, so exactly one of them consumes a sequence and the
 * trace cannot say which. Seq 0 is what the client provably accepted.
 */
export function encodeSlot1cPush({ endpointToken, selector = 1, status = 0, sequence = 0 }) {
  const bodyLength = 8;
  const messageLength = HEADER_BYTES + bodyLength; // 0x18
  const datagram = Buffer.alloc(messageLength + TRAILER_BYTES); // 28
  datagram.writeUInt16BE((WHO_RELIABLE | WHO_SET | WHO_DATA | messageLength) >>> 0, 0x00);
  datagram.writeUInt8(0x00, 0x02);
  datagram.writeUInt8(OPCODE_SLOT1C_PUSH, 0x03);
  datagram.writeUInt32BE(endpointToken >>> 0, 0x04);
  datagram.writeUInt32BE(sequence >>> 0, 0x08);
  datagram.writeUInt32BE(0, 0x0c);
  datagram.writeUInt32BE(selector >>> 0, 0x10);
  datagram.writeUInt32BE(status >>> 0, 0x14);
  DATAGRAM_TRAILER.copy(datagram, messageLength);
  return datagram;
}
