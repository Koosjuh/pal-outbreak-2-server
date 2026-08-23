import crypto from 'node:crypto';

const KEY_BYTES = 32;
const NONCE_BYTES = 12;
const TAG_BYTES = 16;
const KEY_VERSION = 1;

export function parseMasterKey(encoded) {
  if (typeof encoded !== 'string' || encoded.length === 0) {
    throw new Error('PAL_V2_MASTER_KEY is required');
  }

  let key;
  if (/^[0-9a-f]{64}$/i.test(encoded)) {
    key = Buffer.from(encoded, 'hex');
  } else {
    key = Buffer.from(encoded, 'base64');
  }
  if (key.length !== KEY_BYTES) {
    throw new Error('PAL_V2_MASTER_KEY must decode to exactly 32 bytes');
  }
  return key;
}

function additionalData(userid, keyVersion) {
  return Buffer.from(`pal-outbreak-v2:account:${keyVersion}:${userid}`, 'utf8');
}

export class SecretVault {
  constructor(masterKey) {
    if (!Buffer.isBuffer(masterKey) || masterKey.length !== KEY_BYTES) {
      throw new Error('SecretVault requires a 32-byte master key');
    }
    this.masterKey = Buffer.from(masterKey);
  }

  seal(userid, secret) {
    const nonce = crypto.randomBytes(NONCE_BYTES);
    const cipher = crypto.createCipheriv('aes-256-gcm', this.masterKey, nonce, {
      authTagLength: TAG_BYTES
    });
    cipher.setAAD(additionalData(userid, KEY_VERSION));
    const ciphertext = Buffer.concat([
      cipher.update(Buffer.from(String(secret), 'latin1')),
      cipher.final()
    ]);
    return {
      keyVersion: KEY_VERSION,
      nonce,
      ciphertext,
      authenticationTag: cipher.getAuthTag()
    };
  }

  open(userid, sealed) {
    if (sealed.keyVersion !== KEY_VERSION) {
      throw new Error(`unsupported account-secret key version ${sealed.keyVersion}`);
    }
    const decipher = crypto.createDecipheriv(
      'aes-256-gcm',
      this.masterKey,
      sealed.nonce,
      { authTagLength: TAG_BYTES }
    );
    decipher.setAAD(additionalData(userid, sealed.keyVersion));
    decipher.setAuthTag(sealed.authenticationTag);
    return Buffer.concat([
      decipher.update(sealed.ciphertext),
      decipher.final()
    ]).toString('latin1');
  }
}

