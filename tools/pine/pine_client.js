'use strict';

const net = require('net');

const OP = {
  Read8: 0x00, Read16: 0x01, Read32: 0x02, Read64: 0x03,
  Write8: 0x04, Write16: 0x05, Write32: 0x06, Write64: 0x07,
  Version: 0x08, SaveState: 0x09, LoadState: 0x0A,
  Title: 0x0B, ID: 0x0C, UUID: 0x0D, GameVersion: 0x0E,
  Status: 0x0F,
};

const IPC_OK = 0x00;
const IPC_FAIL = 0xFF;

const STATUS = { 0: 'Running', 1: 'Paused', 2: 'Shutdown' };

class PineError extends Error {
  constructor(msg, opcode) { super(msg); this.opcode = opcode; }
}

function frameOne(opcode, payload = Buffer.alloc(0)) {
  return { opcode, body: Buffer.concat([Buffer.from([opcode]), payload]) };
}

function buildPacket(commands) {
  const bodies = commands.map(c => c.body);
  const totalBody = Buffer.concat(bodies);
  const len = Buffer.alloc(4);
  len.writeUInt32LE(totalBody.length + 4, 0);
  return Buffer.concat([len, totalBody]);
}

function readReplySize(opcode) {
  switch (opcode) {
    case OP.Read8: return 1;
    case OP.Read16: return 2;
    case OP.Read32: return 4;
    case OP.Read64: return 8;
    case OP.Write8: case OP.Write16: case OP.Write32: case OP.Write64: return 0;
    case OP.SaveState: case OP.LoadState: return 0;
    case OP.Status: return 4;
    case OP.Version: case OP.Title: case OP.ID:
    case OP.UUID: case OP.GameVersion: return -1;
    default: throw new PineError(`unknown opcode ${opcode}`, opcode);
  }
}

class PineClient {
  constructor({ port = 28011, host = '127.0.0.1', timeoutMs = 10000 } = {}) {
    this.port = port;
    this.host = host;
    this.timeoutMs = timeoutMs;
    this.sock = null;
    this.rxBuf = Buffer.alloc(0);
    this.queue = [];
    this.connected = false;
  }

  connect() {
    return new Promise((resolve, reject) => {
      const sock = net.connect({ port: this.port, host: this.host });
      const onErr = (err) => { sock.removeAllListeners(); reject(err); };
      sock.once('error', onErr);
      sock.once('connect', () => {
        sock.removeListener('error', onErr);
        sock.on('error', () => this._fail(new PineError('socket error')));
        sock.on('close', () => { this.connected = false; this._fail(new PineError('socket closed')); });
        sock.on('data', (d) => this._onData(d));
        this.sock = sock;
        this.connected = true;
        resolve();
      });
    });
  }

  close() {
    if (this.sock) { try { this.sock.end(); } catch {} this.sock = null; }
    this.connected = false;
  }

  _fail(err) {
    const q = this.queue; this.queue = [];
    for (const item of q) item.reject(err);
  }

  _onData(d) {
    this.rxBuf = Buffer.concat([this.rxBuf, d]);
    while (this.rxBuf.length >= 4) {
      const total = this.rxBuf.readUInt32LE(0);
      if (this.rxBuf.length < total) return;
      const frame = this.rxBuf.slice(4, total);
      this.rxBuf = this.rxBuf.slice(total);
      this._dispatchFrame(frame);
    }
  }

  _dispatchFrame(frame) {
    const item = this.queue.shift();
    if (!item) return;
    try {
      const replies = [];
      let off = 0;
      for (const cmd of item.commands) {
        if (off >= frame.length) {
          // PCSX2 truncated the batch reply — pad remaining commands as failed
          // rather than throwing. Caller can retry the missed addresses.
          replies.push({ ok: false, opcode: cmd.opcode, payload: null, truncated: true });
          continue;
        }
        const result = frame[off]; off += 1;
        if (result !== IPC_OK) {
          replies.push({ ok: false, opcode: cmd.opcode, payload: null });
          continue;
        }
        const sz = readReplySize(cmd.opcode);
        let payload;
        if (sz === -1) {
          const nul = frame.indexOf(0, off);
          if (nul < 0) {
            replies.push({ ok: false, opcode: cmd.opcode, payload: null, truncated: true });
            continue;
          }
          payload = frame.slice(off, nul).toString('utf8');
          off = nul + 1;
        } else {
          if (off + sz > frame.length) {
            replies.push({ ok: false, opcode: cmd.opcode, payload: null, truncated: true });
            continue;
          }
          payload = frame.slice(off, off + sz);
          off += sz;
        }
        replies.push({ ok: true, opcode: cmd.opcode, payload });
      }
      item.resolve(replies);
    } catch (err) { item.reject(err); }
  }

  send(commands) {
    return new Promise((resolve, reject) => {
      if (!this.connected) return reject(new PineError('not connected'));
      const item = { commands, resolve, reject };
      this.queue.push(item);
      const t = setTimeout(() => {
        const i = this.queue.indexOf(item);
        if (i >= 0) {
          this.queue.splice(i, 1);
          reject(new PineError('timeout'));
        }
      }, this.timeoutMs);
      item._timer = t;
      const orig = item.resolve;
      item.resolve = (v) => { clearTimeout(t); orig(v); };
      const origR = item.reject;
      item.reject = (e) => { clearTimeout(t); origR(e); };
      this.sock.write(buildPacket(commands));
    });
  }

  async _one(opcode, payload) {
    const r = await this.send([frameOne(opcode, payload)]);
    if (!r[0].ok) throw new PineError(`opcode 0x${opcode.toString(16)} failed`, opcode);
    return r[0].payload;
  }

  async status() {
    const buf = await this._one(OP.Status);
    const code = buf.readUInt32LE(0);
    return { code, name: STATUS[code] || `Unknown(${code})` };
  }

  async version() { return this._one(OP.Version); }
  async title() { return this._one(OP.Title); }
  async serial() { return this._one(OP.ID); }
  async crc() { return this._one(OP.UUID); }

  async read8(addr) {
    const p = Buffer.alloc(4); p.writeUInt32LE(addr >>> 0, 0);
    return (await this._one(OP.Read8, p)).readUInt8(0);
  }
  async read16(addr) {
    const p = Buffer.alloc(4); p.writeUInt32LE(addr >>> 0, 0);
    return (await this._one(OP.Read16, p)).readUInt16LE(0);
  }
  async read32(addr) {
    const p = Buffer.alloc(4); p.writeUInt32LE(addr >>> 0, 0);
    return (await this._one(OP.Read32, p)).readUInt32LE(0);
  }
  async read64(addr) {
    const p = Buffer.alloc(4); p.writeUInt32LE(addr >>> 0, 0);
    return (await this._one(OP.Read64, p)).readBigUInt64LE(0);
  }

  async write8(addr, val) {
    const p = Buffer.alloc(5); p.writeUInt32LE(addr >>> 0, 0); p.writeUInt8(val & 0xff, 4);
    return this._one(OP.Write8, p);
  }
  async write32(addr, val) {
    const p = Buffer.alloc(8); p.writeUInt32LE(addr >>> 0, 0); p.writeUInt32LE(val >>> 0, 4);
    return this._one(OP.Write32, p);
  }

  async writeBytes(addr, data) {
    const buf = Buffer.isBuffer(data) ? data : Buffer.from(data);
    let off = 0;
    while (off + 4 <= buf.length) {
      await this.write32(addr + off, buf.readUInt32LE(off));
      off += 4;
    }
    while (off < buf.length) {
      await this.write8(addr + off, buf.readUInt8(off));
      off += 1;
    }
  }

  async readBytes(addr, len) {
    const out = Buffer.alloc(len);
    let off = 0;
    while (off + 8 <= len) {
      const v = await this.read64(addr + off);
      out.writeBigUInt64LE(v, off);
      off += 8;
    }
    while (off + 4 <= len) {
      const v = await this.read32(addr + off);
      out.writeUInt32LE(v, off);
      off += 4;
    }
    while (off < len) {
      const v = await this.read8(addr + off);
      out.writeUInt8(v, off);
      off += 1;
    }
    return out;
  }

  async saveState(slot) {
    const p = Buffer.from([slot & 0xff]);
    return this._one(OP.SaveState, p);
  }
  async loadState(slot) {
    const p = Buffer.from([slot & 0xff]);
    return this._one(OP.LoadState, p);
  }
}

module.exports = { PineClient, OP, IPC_OK, IPC_FAIL, STATUS };

if (require.main === module) {
  (async () => {
    const port = Number(process.argv[2] || 28011);
    const c = new PineClient({ port });
    try {
      await c.connect();
      console.log('connected to PINE on', port);
      const v = await c.version();
      console.log('version:', v);
      const s = await c.status();
      console.log('status:', s);
      try {
        const id = await c.serial();
        const crc = await c.crc();
        console.log('serial:', id, 'crc:', crc);
      } catch (e) { console.log('(no game running yet:', e.message + ')'); }
      const probe = await c.read32(0x0029F280);
      console.log('0x0029F280 (u32):', '0x' + probe.toString(16).padStart(8, '0'));
    } catch (e) {
      console.error('PINE smoke test failed:', e.message);
      process.exitCode = 1;
    } finally {
      c.close();
    }
  })();
}
