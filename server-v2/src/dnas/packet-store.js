import fs from 'node:fs/promises';
import path from 'node:path';

const PACKET_KEY = /^[0-9a-f]{16}_[0-9a-f]{8}$/;

export class DnasPacketStoreError extends Error {
  constructor(code, message) {
    super(message);
    this.name = 'DnasPacketStoreError';
    this.code = code;
  }
}

export function assertPacketKey(packetKey) {
  if (!PACKET_KEY.test(packetKey)) {
    throw new DnasPacketStoreError('INVALID_PACKET_KEY', 'DNAS packet key must be 16 hex digits, an underscore, and 8 hex digits');
  }
  return packetKey;
}

export class FileDnasPacketStore {
  constructor(directory) {
    if (!directory) {
      throw new TypeError('DNAS packet directory is required');
    }
    this.directory = path.resolve(directory);
  }

  async get(packetKey) {
    assertPacketKey(packetKey);
    const packetPath = path.join(this.directory, packetKey);
    try {
      return await fs.readFile(packetPath);
    } catch (error) {
      if (error?.code === 'ENOENT') {
        return null;
      }
      throw new DnasPacketStoreError('PACKET_READ_FAILED', `Unable to read DNAS packet ${packetKey}: ${error.message}`);
    }
  }
}
