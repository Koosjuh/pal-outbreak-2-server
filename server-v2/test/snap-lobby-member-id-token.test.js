import assert from 'node:assert/strict';
import test from 'node:test';

import { TimingWheel } from '../src/transport/timing-wheel.js';
import { createV1ObservedAreaDirectory } from '../src/udp/area-directory.js';
import { LOBBY_OPCODE } from '../src/udp/snap-lobby-codec.js';
import { SnapLobbySessions } from '../src/udp/snap-lobby-sessions.js';

/**
 * SNAP_MEMBER_ID_TOKEN (SESSION-LOG T17, wire-confirmed).
 *
 * The host's game-start SM (FUN_005c6500 s6/7) marks a member ACCEPTED only
 * when a roster slot's memberId equals the conn word on the relayed sub-4
 * accept. That conn word is the RECIPIENT's own endpoint token (we stamp the
 * recipient on every relay - RIG f18876: joiner's accept relayed to the host
 * carried conn=02f807d0, the host's own token). With memberIds minted as 1/2
 * the scan never matched -> no accept -> solo start -> the joiner froze at
 * "Stand by" / "Game to begin shortly".
 *
 * The fix: the op-06 record pushed to member R about the joiner carries R's own
 * endpoint token as memberId. memberId and the header token are both
 * writeUInt32BE, so the +0x10 bytes equal the conn word the host scans.
 */

const TOKEN_HOST = 0x02f807d0;   // RIG f18867: the host's endpoint token
const TOKEN_JOINER = 0x028107d0; // RIG f18873: the joiner's own token

function reliableDatagram({ opcode, sequence, sub = 0, payload = Buffer.alloc(0), who = 0xb000, token }) {
  const inner = 0x10 + payload.length;
  const datagram = Buffer.alloc(inner + 4);
  datagram.writeUInt16BE(who | inner, 0);
  datagram.writeUInt8(sub, 2);
  datagram.writeUInt8(opcode, 3);
  datagram.writeUInt32BE(token, 4);
  datagram.writeUInt32BE(sequence, 8);
  payload.copy(datagram, 0x10);
  Buffer.from([0xba, 0x47, 0x66, 0x11]).copy(datagram, inner);
  return datagram;
}

function boxKeyOf(boxId) {
  const { records } = createV1ObservedAreaDirectory().records(() => 0);
  return records.find((entry) => entry.name.endsWith(String(boxId).padStart(2, '0'))).key;
}

function harness(sessions = {}) {
  let nowMs = 1_000;
  let intervalToken = null;
  const wheel = new TimingWheel({
    tickMs: 100, clock: () => nowMs,
    setInterval: (fn) => { intervalToken = { fn, unref() {} }; return intervalToken; },
    clearInterval: () => { intervalToken = null; }, onError: () => {}
  });
  wheel.start();
  const table = new SnapLobbySessions({
    wheel, areaDirectory: createV1ObservedAreaDirectory(),
    keepaliveKey: 'SNAP-SWAN', joinLadder: true, ...sessions
  });
  const open = (routingKey, identity, token) => {
    const sent = [];
    const session = table.open({
      routingKey, loginIdentity: identity, endpointToken: token,
      outboundSequence: 1, inboundReceiveBase: 0, latencyTicks: 1600,
      transmit: (datagram, context) => sent.push({ datagram, ...context })
    });
    return { session, sent, token, seq: 0, next() { this.seq += 1; return this.seq - 1; } };
  };
  return { table, open };
}

function enter(client, boxId) {
  const key = Buffer.alloc(4); key.writeUInt32BE(boxKeyOf(boxId));
  client.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.AREA_ENTER, sequence: client.next(), payload: key, token: client.token
  }));
}

function createRoom(client) {
  const before = client.sent.length;
  client.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CREATE_ROOM, sequence: client.next(), payload: Buffer.alloc(0x2c), token: client.token
  }));
  const accept = client.sent.slice(before).find((e) =>
    e.datagram.length >= 0x1c && e.datagram[3] === LOBBY_OPCODE.COMPLETION &&
    e.datagram.readUInt32BE(0x10) === 4);
  assert.ok(accept, 'create accept left');
  return accept.datagram.readUInt32BE(0x14);
}

function joinRoom(client, handle) {
  const body = Buffer.alloc(0x18);
  body.writeUInt32LE(handle, 0x00);
  client.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.AREA_ENTER, sequence: client.next(), payload: body, who: 0xa000, token: client.token
  }));
}

/** The memberId the HOST received in the op-06 fan-out about the joiner. */
function joinerMemberIdSeenByHost(host, sinceIndex) {
  const rec = host.sent.slice(sinceIndex).find((e) =>
    e.datagram.length >= 0x108 && e.datagram[3] === LOBBY_OPCODE.MEMBER_JOIN);
  assert.ok(rec, 'the host received a member-JOIN for the joiner');
  return rec.datagram.readUInt32BE(0x10 + 0x10); // wire+0x10 hdr .. record+0x10 memberId
}

test('OFF (default): the host sees the joiner memberId as the minted playernum (2), not its token', () => {
  const rig = harness();
  const host = rig.open('192.168.2.248:2000', 'test123', TOKEN_HOST);
  const joiner = rig.open('192.168.2.129:2000', 'real', TOKEN_JOINER);
  enter(host, 1); const handle = createRoom(host); enter(joiner, 1);
  const at = host.sent.length;
  joinRoom(joiner, handle);
  assert.equal(joinerMemberIdSeenByHost(host, at), 2,
    'pre-fix: the shared record carries playernum 2 - the scan never matches the host token');
});

test('ON: the host sees the joiner memberId as the HOST\'s OWN token (the scan will match)', () => {
  const rig = harness({ memberIdToken: true });
  const host = rig.open('192.168.2.248:2000', 'test123', TOKEN_HOST);
  const joiner = rig.open('192.168.2.129:2000', 'real', TOKEN_JOINER);
  enter(host, 1); const handle = createRoom(host); enter(joiner, 1);
  const at = host.sent.length;
  joinRoom(joiner, handle);
  const memberId = joinerMemberIdSeenByHost(host, at);
  assert.equal(memberId, TOKEN_HOST,
    'the joiner record the host holds now carries the host\'s own token = the conn word its ' +
    'sub-4 accept scan compares against (RIG f18876)');
});
