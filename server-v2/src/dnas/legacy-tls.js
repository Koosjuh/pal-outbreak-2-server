import crypto from 'node:crypto';

import { tls10Prf } from './application-codec.js';

const TLS_VERSION = 0x0301;
const TLS_RSA_WITH_RC4_128_MD5 = 0x0004;
const MAX_TLS_RECORD = 18 * 1024;
const MAX_APPLICATION_REQUEST = 64 * 1024;

export class LegacyTlsError extends Error {
  constructor(code, message) {
    super(message);
    this.name = 'LegacyTlsError';
    this.code = code;
  }
}

class Rc4 {
  constructor(key) {
    if (!Buffer.isBuffer(key) || key.length === 0) {
      throw new TypeError('RC4 key must be a non-empty Buffer');
    }
    this.state = new Uint8Array(256);
    for (let index = 0; index < 256; index += 1) {
      this.state[index] = index;
    }
    let swapIndex = 0;
    for (let index = 0; index < 256; index += 1) {
      swapIndex = (swapIndex + this.state[index] + key[index % key.length]) & 0xff;
      [this.state[index], this.state[swapIndex]] = [this.state[swapIndex], this.state[index]];
    }
    this.index = 0;
    this.swapIndex = 0;
  }

  process(input) {
    const output = Buffer.alloc(input.length);
    for (let offset = 0; offset < input.length; offset += 1) {
      this.index = (this.index + 1) & 0xff;
      this.swapIndex = (this.swapIndex + this.state[this.index]) & 0xff;
      [this.state[this.index], this.state[this.swapIndex]] =
        [this.state[this.swapIndex], this.state[this.index]];
      const keyByte = this.state[(this.state[this.index] + this.state[this.swapIndex]) & 0xff];
      output[offset] = input[offset] ^ keyByte;
    }
    return output;
  }
}

function tlsRecord(type, payload) {
  const header = Buffer.alloc(5);
  header[0] = type;
  header.writeUInt16BE(TLS_VERSION, 1);
  header.writeUInt16BE(payload.length, 3);
  return Buffer.concat([header, payload]);
}

function handshakeMessage(type, body) {
  const header = Buffer.alloc(4);
  header[0] = type;
  header.writeUIntBE(body.length, 1, 3);
  return Buffer.concat([header, body]);
}

function buildServerHello(serverRandom) {
  const body = Buffer.alloc(38);
  body.writeUInt16BE(TLS_VERSION, 0);
  serverRandom.copy(body, 2);
  body[34] = 0;
  body.writeUInt16BE(TLS_RSA_WITH_RC4_128_MD5, 35);
  body[37] = 0;
  return handshakeMessage(0x02, body);
}

function buildCertificate(certificateChain) {
  const encoded = certificateChain.map((certificate) => {
    const length = Buffer.alloc(3);
    length.writeUIntBE(certificate.length, 0, 3);
    return Buffer.concat([length, certificate]);
  });
  const certificates = Buffer.concat(encoded);
  const listLength = Buffer.alloc(3);
  listLength.writeUIntBE(certificates.length, 0, 3);
  return handshakeMessage(0x0b, Buffer.concat([listLength, certificates]));
}

function buildServerHelloDone() {
  return handshakeMessage(0x0e, Buffer.alloc(0));
}

function recordMac(macKey, sequence, type, plaintext) {
  const sequenceBytes = Buffer.alloc(8);
  sequenceBytes.writeBigUInt64BE(sequence);
  const header = Buffer.alloc(5);
  header[0] = type;
  header.writeUInt16BE(TLS_VERSION, 1);
  header.writeUInt16BE(plaintext.length, 3);
  return crypto
    .createHmac('md5', macKey)
    .update(sequenceBytes)
    .update(header)
    .update(plaintext)
    .digest();
}

function handshakeDigest(transcript) {
  return Buffer.concat([
    crypto.createHash('md5').update(transcript).digest(),
    crypto.createHash('sha1').update(transcript).digest()
  ]);
}

function assertBufferLength(value, length, name) {
  if (!Buffer.isBuffer(value) || value.length !== length) {
    throw new TypeError(`${name} must be a ${length}-byte Buffer`);
  }
}

function parseSsl2ClientHello(record) {
  if (record.length < 13 || (record[0] & 0x80) === 0) {
    throw new LegacyTlsError('INVALID_SSL2_CLIENT_HELLO', 'Expected a two-byte SSLv2-compatible ClientHello');
  }
  const body = record.subarray(2);
  if (body[0] !== 0x01) {
    throw new LegacyTlsError('INVALID_SSL2_MESSAGE', `Expected ClientHello type 1; received ${body[0]}`);
  }
  if (body.readUInt16BE(1) !== TLS_VERSION) {
    throw new LegacyTlsError('UNSUPPORTED_TLS_VERSION', 'The observed PAL DNAS client requires TLS 1.0');
  }

  const cipherLength = body.readUInt16BE(3);
  const sessionIdLength = body.readUInt16BE(5);
  const challengeLength = body.readUInt16BE(7);
  if (cipherLength % 3 !== 0 || challengeLength === 0 || challengeLength > 32) {
    throw new LegacyTlsError('INVALID_SSL2_LENGTHS', 'SSLv2-compatible ClientHello lengths are invalid');
  }
  const expected = 9 + cipherLength + sessionIdLength + challengeLength;
  if (body.length !== expected) {
    throw new LegacyTlsError(
      'SSL2_LENGTH_MISMATCH',
      `SSLv2-compatible ClientHello declares ${expected} bytes; received ${body.length}`
    );
  }

  const cipherBytes = body.subarray(9, 9 + cipherLength);
  let supportsRc4Md5 = false;
  for (let offset = 0; offset < cipherBytes.length; offset += 3) {
    if (cipherBytes.readUIntBE(offset, 3) === TLS_RSA_WITH_RC4_128_MD5) {
      supportsRc4Md5 = true;
      break;
    }
  }
  if (!supportsRc4Md5) {
    throw new LegacyTlsError('REQUIRED_CIPHER_MISSING', 'ClientHello does not offer TLS_RSA_WITH_RC4_128_MD5');
  }

  const challengeOffset = 9 + cipherLength + sessionIdLength;
  const challenge = body.subarray(challengeOffset, challengeOffset + challengeLength);
  return {
    transcriptMessage: Buffer.from(body),
    clientRandom: Buffer.concat([Buffer.alloc(32 - challenge.length), challenge]),
    cipherLength,
    sessionIdLength,
    challengeLength
  };
}

export class LegacyDnasTlsConnection {
  constructor({
    certificateDer,
    caCertificateDer,
    privateKey,
    applicationService,
    serverRandom = crypto.randomBytes(32),
    maximumApplicationRequest = MAX_APPLICATION_REQUEST
  }) {
    if (!Buffer.isBuffer(certificateDer) || certificateDer.length === 0) {
      throw new TypeError('Server certificate DER is required');
    }
    if (!Buffer.isBuffer(caCertificateDer) || caCertificateDer.length === 0) {
      throw new TypeError('CA certificate DER is required');
    }
    if (!privateKey) {
      throw new TypeError('RSA private key is required');
    }
    if (!applicationService || typeof applicationService.handle !== 'function') {
      throw new TypeError('DNAS application service is required');
    }
    assertBufferLength(serverRandom, 32, 'serverRandom');

    this.privateKey = privateKey;
    this.applicationService = applicationService;
    this.serverRandom = Buffer.from(serverRandom);
    this.maximumApplicationRequest = maximumApplicationRequest;
    this.serverHello = buildServerHello(this.serverRandom);
    this.certificate = buildCertificate([certificateDer, caCertificateDer]);
    this.serverHelloDone = buildServerHelloDone();

    this.state = 'WAIT_CLIENT_HELLO';
    this.wireBuffer = Buffer.alloc(0);
    this.handshakeBuffer = Buffer.alloc(0);
    this.applicationBuffer = Buffer.alloc(0);
    this.transcript = [];
    this.clientSequence = 0n;
    this.serverSequence = 0n;
    this.readEncrypted = false;
    this.failed = false;
    this.closedByPeer = false;
    this.events = [];
  }

  #event(type, details = {}) {
    this.events.push({ type, ...details });
  }

  #fail(code, message) {
    this.failed = true;
    this.state = 'FAILED';
    this.#event('protocol-error', { code, message });
    throw new LegacyTlsError(code, message);
  }

  #deriveKeys(premaster, clientRandom) {
    if (premaster.length !== 48) {
      this.#fail('INVALID_PREMASTER_LENGTH', `RSA premaster must be 48 bytes; received ${premaster.length}`);
    }
    if (premaster.readUInt16BE(0) !== TLS_VERSION) {
      this.#fail('INVALID_PREMASTER_VERSION', 'RSA premaster does not contain TLS 1.0 version bytes');
    }
    const masterSecret = tls10Prf(
      premaster,
      'master secret',
      Buffer.concat([clientRandom, this.serverRandom]),
      48
    );
    const keyBlock = tls10Prf(
      masterSecret,
      'key expansion',
      Buffer.concat([this.serverRandom, clientRandom]),
      64
    );
    this.masterSecret = masterSecret;
    this.clientMacKey = keyBlock.subarray(0, 16);
    this.serverMacKey = keyBlock.subarray(16, 32);
    this.clientCipher = new Rc4(keyBlock.subarray(32, 48));
    this.serverCipher = new Rc4(keyBlock.subarray(48, 64));
  }

  #decryptRecord(type, ciphertext) {
    if (!this.clientCipher || ciphertext.length < 16) {
      this.#fail('INVALID_ENCRYPTED_RECORD', 'Encrypted TLS record is too short or keys are unavailable');
    }
    const decoded = this.clientCipher.process(ciphertext);
    const plaintext = decoded.subarray(0, decoded.length - 16);
    const receivedMac = decoded.subarray(decoded.length - 16);
    const expectedMac = recordMac(this.clientMacKey, this.clientSequence, type, plaintext);
    this.clientSequence += 1n;
    if (!crypto.timingSafeEqual(receivedMac, expectedMac)) {
      this.#fail('BAD_RECORD_MAC', `TLS record type 0x${type.toString(16)} failed HMAC-MD5 verification`);
    }
    this.#event('record-mac-verified', { recordType: type, plaintextLength: plaintext.length });
    return plaintext;
  }

  #encryptRecord(type, plaintext) {
    const mac = recordMac(this.serverMacKey, this.serverSequence, type, plaintext);
    this.serverSequence += 1n;
    return tlsRecord(type, this.serverCipher.process(Buffer.concat([plaintext, mac])));
  }

  #serverFlight() {
    return Buffer.concat([
      tlsRecord(0x16, this.serverHello),
      tlsRecord(0x16, this.certificate),
      tlsRecord(0x16, this.serverHelloDone)
    ]);
  }

  #handleClientHello(record, writes) {
    const hello = parseSsl2ClientHello(record);
    this.clientRandom = hello.clientRandom;
    this.transcript.push(hello.transcriptMessage, this.serverHello, this.certificate, this.serverHelloDone);
    writes.push(this.#serverFlight());
    this.state = 'WAIT_CLIENT_KEY_EXCHANGE';
    this.#event('client-hello', {
      cipherLength: hello.cipherLength,
      sessionIdLength: hello.sessionIdLength,
      challengeLength: hello.challengeLength
    });
  }

  #handleClientKeyExchange(message) {
    if (this.state !== 'WAIT_CLIENT_KEY_EXCHANGE') {
      this.#fail('UNEXPECTED_CLIENT_KEY_EXCHANGE', `ClientKeyExchange received in ${this.state}`);
    }
    const body = message.subarray(4);
    if (body.length < 2) {
      this.#fail('TRUNCATED_CLIENT_KEY_EXCHANGE', 'ClientKeyExchange RSA length is missing');
    }
    const encryptedLength = body.readUInt16BE(0);
    if (encryptedLength === 0 || body.length !== encryptedLength + 2) {
      this.#fail('INVALID_CLIENT_KEY_EXCHANGE_LENGTH', 'ClientKeyExchange RSA ciphertext length is invalid');
    }

    let premaster;
    try {
      premaster = crypto.privateDecrypt(
        {
          key: this.privateKey,
          padding: crypto.constants.RSA_PKCS1_PADDING
        },
        body.subarray(2)
      );
    } catch (error) {
      this.#fail('PREMASTER_DECRYPT_FAILED', `RSA premaster decryption failed: ${error.message}`);
    }

    this.#deriveKeys(premaster, this.clientRandom);
    this.transcript.push(Buffer.from(message));
    this.state = 'WAIT_CLIENT_CHANGE_CIPHER_SPEC';
    this.#event('client-key-exchange', { encryptedLength });
  }

  #handleClientFinished(message, writes) {
    if (this.state !== 'WAIT_CLIENT_FINISHED') {
      this.#fail('UNEXPECTED_CLIENT_FINISHED', `Client Finished received in ${this.state}`);
    }
    const body = message.subarray(4);
    if (body.length !== 12) {
      this.#fail('INVALID_FINISHED_LENGTH', `Client Finished must be 12 bytes; received ${body.length}`);
    }
    const transcript = Buffer.concat(this.transcript);
    const expected = tls10Prf(
      this.masterSecret,
      'client finished',
      handshakeDigest(transcript),
      12
    );
    if (!crypto.timingSafeEqual(body, expected)) {
      this.#fail('BAD_CLIENT_FINISHED', 'Client Finished verify_data does not match the handshake transcript');
    }

    writes.push(tlsRecord(0x14, Buffer.from([0x01])));
    const serverTranscript = Buffer.concat([...this.transcript, message]);
    const serverVerify = tls10Prf(
      this.masterSecret,
      'server finished',
      handshakeDigest(serverTranscript),
      12
    );
    writes.push(this.#encryptRecord(0x16, handshakeMessage(0x14, serverVerify)));
    this.state = 'APPLICATION_DATA';
    this.#event('client-finished-verified');
  }

  #processHandshakeMessages(writes) {
    while (this.handshakeBuffer.length >= 4) {
      const length = this.handshakeBuffer.readUIntBE(1, 3);
      if (length > MAX_TLS_RECORD) {
        this.#fail('HANDSHAKE_MESSAGE_TOO_LARGE', `TLS handshake message length ${length} exceeds limit`);
      }
      if (this.handshakeBuffer.length < length + 4) {
        return;
      }
      const message = this.handshakeBuffer.subarray(0, length + 4);
      this.handshakeBuffer = this.handshakeBuffer.subarray(length + 4);
      if (message[0] === 0x10) {
        this.#handleClientKeyExchange(message);
      } else if (message[0] === 0x14) {
        this.#handleClientFinished(message, writes);
      } else {
        this.#fail(
          'UNSUPPORTED_HANDSHAKE_MESSAGE',
          `Unsupported client handshake type 0x${message[0].toString(16)}`
        );
      }
    }
  }

  async #processApplicationData(plaintext, writes) {
    if (this.state !== 'APPLICATION_DATA') {
      this.#fail('UNEXPECTED_APPLICATION_DATA', `Application data received in ${this.state}`);
    }
    this.applicationBuffer = Buffer.concat([this.applicationBuffer, plaintext]);
    if (this.applicationBuffer.length > this.maximumApplicationRequest) {
      this.#fail('APPLICATION_REQUEST_TOO_LARGE', 'DNAS application request exceeds configured limit');
    }

    const headerEnd = this.applicationBuffer.indexOf('\r\n\r\n', 0, 'latin1');
    if (headerEnd < 0) {
      return;
    }
    const headerText = this.applicationBuffer.subarray(0, headerEnd).toString('latin1');
    const match = /(?:^|\r\n)Content-Length:\s*([0-9]+)\r\n/i.exec(`${headerText}\r\n`);
    if (!match) {
      this.#fail('APPLICATION_CONTENT_LENGTH_MISSING', 'DNAS application request lacks Content-Length');
    }
    const completeLength = headerEnd + 4 + Number(match[1]);
    if (completeLength > this.maximumApplicationRequest) {
      this.#fail('APPLICATION_REQUEST_TOO_LARGE', 'DNAS application request exceeds configured limit');
    }
    if (this.applicationBuffer.length < completeLength) {
      return;
    }
    if (this.applicationBuffer.length !== completeLength) {
      this.#fail('APPLICATION_TRAILING_BYTES', 'Multiple or trailing DNAS requests are not observed on one TLS connection');
    }

    const request = this.applicationBuffer;
    this.applicationBuffer = Buffer.alloc(0);
    const result = await this.applicationService.handle(request);
    const maximumPlaintext = 16_000;
    for (let offset = 0; offset < result.responseBytes.length; offset += maximumPlaintext) {
      writes.push(this.#encryptRecord(0x17, result.responseBytes.subarray(offset, offset + maximumPlaintext)));
    }
    this.#event('application-response', {
      ok: result.ok,
      errorCode: result.errorCode ?? null,
      packetKey: result.query?.packetKey ?? null,
      responseBodyLength: result.responseBody.length
    });
  }

  async #handleTlsRecord(type, version, payload, writes) {
    if (version !== TLS_VERSION) {
      this.#fail('UNSUPPORTED_RECORD_VERSION', `TLS record version 0x${version.toString(16)} is unsupported`);
    }

    if (type === 0x14) {
      if (this.state !== 'WAIT_CLIENT_CHANGE_CIPHER_SPEC' || !payload.equals(Buffer.from([0x01]))) {
        this.#fail('UNEXPECTED_CHANGE_CIPHER_SPEC', `ChangeCipherSpec received in ${this.state}`);
      }
      this.readEncrypted = true;
      this.state = 'WAIT_CLIENT_FINISHED';
      this.#event('change-cipher-spec');
      return;
    }

    if (type === 0x16) {
      const plaintext = this.readEncrypted ? this.#decryptRecord(type, payload) : payload;
      this.handshakeBuffer = Buffer.concat([this.handshakeBuffer, plaintext]);
      this.#processHandshakeMessages(writes);
      return;
    }

    if (type === 0x17) {
      if (!this.readEncrypted) {
        this.#fail('UNENCRYPTED_APPLICATION_DATA', 'DNAS application data arrived before ChangeCipherSpec');
      }
      await this.#processApplicationData(this.#decryptRecord(type, payload), writes);
      return;
    }

    if (type === 0x15) {
      const plaintext = this.readEncrypted ? this.#decryptRecord(type, payload) : payload;
      if (!plaintext.equals(Buffer.from([0x01, 0x00]))) {
        this.#fail('UNEXPECTED_TLS_ALERT', `TLS alert payload ${plaintext.toString('hex')} is unsupported`);
      }
      this.closedByPeer = true;
      this.#event('close-notify');
      return;
    }

    this.#fail('UNSUPPORTED_TLS_RECORD', `Unsupported TLS record type 0x${type.toString(16)}`);
  }

  async feed(chunk) {
    if (this.failed) {
      throw new LegacyTlsError('CONNECTION_FAILED', 'Cannot feed a failed TLS connection');
    }
    if (!Buffer.isBuffer(chunk)) {
      throw new TypeError('TLS input chunk must be a Buffer');
    }
    if (chunk.length === 0) {
      return [];
    }

    const writes = [];
    this.wireBuffer = Buffer.concat([this.wireBuffer, chunk]);
    while (this.wireBuffer.length > 0) {
      if (this.state === 'WAIT_CLIENT_HELLO') {
        if (this.wireBuffer.length < 2) {
          break;
        }
        if ((this.wireBuffer[0] & 0x80) === 0) {
          this.#fail('EXPECTED_SSL2_CLIENT_HELLO', 'First DNAS record is not a two-byte-header SSLv2 ClientHello');
        }
        const length = ((this.wireBuffer[0] & 0x7f) << 8) | this.wireBuffer[1];
        if (length > MAX_TLS_RECORD) {
          this.#fail('SSL2_RECORD_TOO_LARGE', `SSLv2 record length ${length} exceeds limit`);
        }
        if (this.wireBuffer.length < length + 2) {
          break;
        }
        const record = this.wireBuffer.subarray(0, length + 2);
        this.wireBuffer = this.wireBuffer.subarray(length + 2);
        this.#handleClientHello(record, writes);
        continue;
      }

      if (this.wireBuffer.length < 5) {
        break;
      }
      const type = this.wireBuffer[0];
      const version = this.wireBuffer.readUInt16BE(1);
      const length = this.wireBuffer.readUInt16BE(3);
      if (length > MAX_TLS_RECORD) {
        this.#fail('TLS_RECORD_TOO_LARGE', `TLS record length ${length} exceeds limit`);
      }
      if (this.wireBuffer.length < length + 5) {
        break;
      }
      const payload = this.wireBuffer.subarray(5, length + 5);
      this.wireBuffer = this.wireBuffer.subarray(length + 5);
      await this.#handleTlsRecord(type, version, payload, writes);
    }
    return writes;
  }
}

export const LEGACY_DNAS_TLS_CONSTANTS = Object.freeze({
  TLS_VERSION,
  TLS_RSA_WITH_RC4_128_MD5,
  MAX_TLS_RECORD,
  MAX_APPLICATION_REQUEST
});
