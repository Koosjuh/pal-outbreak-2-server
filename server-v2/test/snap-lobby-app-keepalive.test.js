import assert from 'node:assert/strict';
import fs from 'node:fs';
import os from 'node:os';
import path from 'node:path';
import test from 'node:test';

import { TimingWheel } from '../src/transport/timing-wheel.js';
import { createV1ObservedAreaDirectory } from '../src/udp/area-directory.js';
import {
  APP_KEEPALIVE_PAYLOAD_BYTES,
  LOBBY_OPCODE,
  buildAppKeepalivePayload
} from '../src/udp/snap-lobby-codec.js';
import { APP_KEEPALIVE_PERIOD_MS } from '../src/udp/snap-lobby-session.js';
import { SnapLobbySessions } from '../src/udp/snap-lobby-sessions.js';
import { CONFIGURATION_KEYS, loadServerConfig } from '../src/config/server-config.js';

/**
 * THE APPLICATION KEEPALIVE (flag `SNAP_APP_KEEPALIVE`) - the G12 fix for the
 * ~145 s voluntary op-0x02 self-close (`docs/design/v2-port/ROOM-WATCHDOG-RE.md`).
 *
 * The lobby overlay arms an application-liveness watchdog at session establish
 * (`FUN_005bdc70`): 1800 ticks of application silence fire the op-0x14 probe,
 * 1800 more declare the connection lost -> screen 6 -> `snap_close` -> the
 * op-0x02. It is reset ONLY by `FUN_005c7d00`, which every inbound
 * lobby-overlay application message calls - and which op-0x40 never reaches,
 * because op-0x40 is consumed by the main-EE transport. So the op-0x40
 * keepalive alone leaves an idle client dying on a ~145.7 s schedule with a
 * perfect transport, which is exactly what T37 and RS1 measured (7 closes,
 * six within +/-5 ms of 72.84 s probe->close).
 *
 * The fix: every 30 s per open session - the JP reference's HEARTBEAT 0x6202
 * cadence - push op-0x10, who 0xA000 (RELIABLE|SET, DATA clear routes to the
 * establish-installed slot 0x13), app-payload byte 0x00 (`FUN_005bba20` resets
 * the watchdog before its switch, and the switch has no case for 0x00 - a
 * pure reset, no other side effect).
 */

const TOKEN = 0x02f807d0;
const ROUTING_KEY = '192.0.2.248:2000';
const KEEPALIVE_KEY = 'SNAP-SWAN';

/**
 * The exact datagram the flag must produce on the lobby floor, byte for byte:
 * who|len 0xA019 (RELIABLE|SET, DATA clear, inner 0x10+9), sub 0, op 0x10,
 * the token, stamped sequence 1, then `[BE32 1][BE32 handle=0][0x00]` and the
 * SN@P trailer. The BREAK-THE-FIX anchor for the whole feature.
 */
const FIRST_PUSH = Buffer.from(
  'a019001002f807d00000000100000000' + '000000010000000000' + 'ba476611', 'hex');

function reliableDatagram({ opcode, sequence, sub = 0, payload = Buffer.alloc(0), who = 0xb000 }) {
  const inner = 0x10 + payload.length;
  const datagram = Buffer.alloc(inner + 4);
  datagram.writeUInt16BE(who | inner, 0);
  datagram.writeUInt8(sub, 2);
  datagram.writeUInt8(opcode, 3);
  datagram.writeUInt32BE(TOKEN, 4);
  datagram.writeUInt32BE(sequence, 8);
  payload.copy(datagram, 0x10);
  Buffer.from([0xba, 0x47, 0x66, 0x11]).copy(datagram, inner);
  return datagram;
}

function harness({ tickMs = 100, sessions: sessionOptions = {} } = {}) {
  let nowMs = 1_000;
  let intervalToken = null;
  const wheel = new TimingWheel({
    tickMs,
    clock: () => nowMs,
    setInterval: (fn) => { intervalToken = { fn, unref() {} }; return intervalToken; },
    clearInterval: () => { intervalToken = null; },
    onError: () => {}
  });
  wheel.start();

  const sent = [];
  const table = new SnapLobbySessions({
    wheel,
    areaDirectory: createV1ObservedAreaDirectory(),
    keepaliveKey: KEEPALIVE_KEY,
    ...sessionOptions
  });
  const session = table.open({
    routingKey: ROUTING_KEY,
    loginIdentity: '12345',
    endpointToken: TOKEN,
    outboundSequence: 1,
    inboundReceiveBase: 0,
    latencyTicks: 1600,
    transmit: (datagram, context) => sent.push({ datagram, ...context })
  });

  return {
    wheel,
    table,
    session,
    sent,
    run(ms) {
      for (let step = 0; step < Math.ceil(ms / tickMs); step += 1) {
        nowMs += tickMs;
        intervalToken?.fn();
      }
    }
  };
}

/**
 * The FIRST emission of each app-keepalive push - retransmissions excluded.
 * The 29-byte frame (16 header + 9 body + 4 trailer) is unique to it: the
 * create/join op-0x10 pushes all carry the 16-byte ROOM_STATE body (36 bytes).
 */
function appKeepalives(sent) {
  return sent.filter((entry) =>
    entry.kind === 'reliable' &&
    entry.opcode === LOBBY_OPCODE.ROOM_STATE &&
    entry.retransmission === 0 &&
    entry.datagram.length === 16 + APP_KEEPALIVE_PAYLOAD_BYTES + 4);
}

test('flag ON: the push fires at the 30 s cadence with the exact who-0xA000 no-op bytes', () => {
  const rig = harness({ sessions: { appKeepalive: true } });

  // Nothing before the first period: establish itself just re-armed the
  // client's watchdog with its full 1800-tick idle budget.
  rig.run(29_000);
  assert.equal(appKeepalives(rig.sent).length, 0, 'no push before the first 30 s period');

  rig.run(66_000); // t = 95 s
  const pushes = appKeepalives(rig.sent);
  assert.equal(pushes.length, 3, 't = 30 s, 60 s, 90 s');
  // Stamped reliable stream, seeded at 1 by the open - the client acks each by
  // sequence, so they must rise, never repeat.
  assert.deepEqual(pushes.map((entry) => entry.sequence), [1, 2, 3]);

  // BREAK-THE-FIX ANCHOR, byte for byte. who|len 0xA019: 0x8000 set with
  // 0x1000/0x0400 clear is what the client dispatcher's case 0xd requires to
  // route an op-0x10 to slot 0x13 (a 0xB0xx DATA-set frame routes elsewhere
  // and resets nothing); payload = [BE32 1][BE32 0][0x00] - the app-payload
  // byte at wire+0x18 is 0x00, the sub FUN_005bba20's switch has no case for.
  assert.deepEqual(pushes[0].datagram, FIRST_PUSH);
  assert.equal(rig.session.stats().appKeepalivesSent, 3);
});

test('flag OFF (the default): zero pushes, and every other byte identical to the ON run', () => {
  const on = harness({ sessions: { appKeepalive: true } });
  const off = harness();
  on.run(95_000);
  off.run(95_000);

  const offPushes = off.sent.filter((entry) =>
    entry.kind === 'reliable' && entry.opcode === LOBBY_OPCODE.ROOM_STATE);
  assert.equal(offPushes.length, 0, 'the default sends no op-0x10 at all');
  assert.equal(off.session.stats().appKeepalivesSent, 0);

  // Byte-identical otherwise: strip the app-keepalive frames (and their
  // retransmissions) from the ON run and the two transmit logs must match
  // exactly - the flag adds its own frames and changes nothing else.
  const onWithoutPushes = on.sent
    .filter((entry) => !(entry.kind === 'reliable' && entry.opcode === LOBBY_OPCODE.ROOM_STATE))
    .map((entry) => entry.datagram);
  assert.deepEqual(onWithoutPushes, off.sent.map((entry) => entry.datagram));
});

test('in a room, the push carries the room handle at +0x14 - the client\'s own 0x6febe8 scope word', () => {
  const rig = harness({ sessions: { appKeepalive: true } });
  const areaKey = Buffer.alloc(4);
  areaKey.writeUInt32BE(4);
  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.AREA_ENTER, sequence: 0, payload: areaKey
  }));
  rig.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CREATE_ROOM, sequence: 1, payload: Buffer.alloc(0x2c)
  }));
  const room = rig.session.createdRoom;
  assert.ok(room, 'the create minted a room');

  rig.run(31_000);
  const [push] = appKeepalives(rig.sent);
  assert.ok(push, 'the push still fires in a room - the timer is session-scope, not screen-scope');
  assert.equal(push.datagram.readUInt32BE(0x10), 1, 'the count word');
  assert.equal(push.datagram.readUInt32BE(0x14), room.handle, 'the room handle, read at send time');
  assert.equal(push.datagram[0x18], 0x00, 'the no-op app-payload byte survives the handle');
});

test('close() cancels the timer, proves the wheel drained, and nothing is sent after', () => {
  const rig = harness({ sessions: { appKeepalive: true } });
  rig.run(35_000);
  assert.equal(appKeepalives(rig.sent).length, 1);

  rig.session.close();
  rig.session.assertDrained();
  const before = rig.sent.length;
  rig.run(65_000);
  assert.equal(rig.sent.length, before, 'a closed session sends nothing, app keepalive included');
});

test('the payload builder: [BE32 1][BE32 handle][0x00], 9 bytes, handle defaulting to 0', () => {
  const floor = buildAppKeepalivePayload();
  assert.equal(floor.length, APP_KEEPALIVE_PAYLOAD_BYTES);
  assert.deepEqual(floor, Buffer.from('000000010000000000', 'hex'));

  const inRoom = buildAppKeepalivePayload({ handle: 0x02f807d0 });
  assert.deepEqual(inRoom, Buffer.from('0000000102f807d000', 'hex'));
});

test('SNAP_APP_KEEPALIVE: config default ON, rollback = set false, listed for the runbook', () => {
  const root = fs.mkdtempSync(path.join(os.tmpdir(), 'pal-v2-appka-'));
  const directoryFile = path.join(root, 'directory.json');
  fs.writeFileSync(directoryFile, '{}', 'utf8');
  const env = {
    PAL_V2_MASTER_KEY: Buffer.alloc(32, 7).toString('base64'),
    PAL_V2_DATA_DIR: path.join(root, 'data'),
    PAL_V2_SELF_HOST: '127.0.0.1',
    PAL_V2_SNAP_HOST: '127.0.0.1',
    PAL_V2_DIRECTORY_FILE: directoryFile,
    PAL_V2_LOBBY_NAME: 'V2 TEST LOBBY',
    PAL_V2_ENABLE_DNS: 'false',
    PAL_V2_ENABLE_DNAS: 'false'
  };
  try {
    assert.equal(loadServerConfig(env).snapLobby.appKeepalive, true,
      'default ON - the reference server heartbeats unconditionally');
    assert.equal(
      loadServerConfig({ ...env, SNAP_APP_KEEPALIVE: 'false' }).snapLobby.appKeepalive,
      false,
      'the rollback is one environment flip'
    );
    assert.ok(CONFIGURATION_KEYS.optional.includes('SNAP_APP_KEEPALIVE'),
      'a default-ON flag must be visible in the runbook key list');
  } finally {
    try {
      fs.rmSync(root, { recursive: true, force: true, maxRetries: 5, retryDelay: 50 });
    } catch {
      // Temporary directory cleanup is not what this test asserts.
    }
  }
});
