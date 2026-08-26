import assert from 'node:assert/strict';
import test from 'node:test';

import { TimingWheel } from '../src/transport/timing-wheel.js';
import { createV1ObservedAreaDirectory } from '../src/udp/area-directory.js';
import { LOBBY_OPCODE } from '../src/udp/snap-lobby-codec.js';
import { SnapLobbySessions } from '../src/udp/snap-lobby-sessions.js';

/**
 * SNAP_CHARSTATS_SEED (analysis/charstats-to-sub7-source-RE, byte-map Confirmed 1:1).
 * Capture each session's char-select op-0c 0xf0 blob and seed it into the op-06
 * member record rec+0x18 (wire +0x28), char-id @ rec+0x18+0xc8. Both directions:
 * the fanout to existing members carries the joiner's blob (host sees joiner), and
 * the roster-to-joiner carries each existing member's blob (joiner sees host).
 */

const STATS = 0xf0;
const CHARSTATS_OFF = 0x18;      // rec+0x18 within the 0x108 member record
const CHARID_OFF = 0xc8;         // char-id within charstats
const HEADER = 0x10;             // reliable datagram header before the app body

function reliableDatagram({ opcode, sequence, payload = Buffer.alloc(0), who = 0xb000, token }) {
  const inner = HEADER + payload.length;
  const d = Buffer.alloc(inner + 4);
  d.writeUInt16BE(who | inner, 0);
  d.writeUInt8(opcode, 3);
  d.writeUInt32BE(token, 4);
  d.writeUInt32BE(sequence, 8);
  payload.copy(d, HEADER);
  Buffer.from([0xba, 0x47, 0x66, 0x11]).copy(d, inner);
  return d;
}

/** A 0xf0 char-select body with a distinctive char-id at +0xc8. */
function charstatsBody(charId) {
  const b = Buffer.alloc(STATS);
  b.fill(0xab); // non-zero throughout so a zero rec+0x18 is unmistakable
  b.writeUInt16LE(charId, CHARID_OFF);
  return b;
}

function boxKeyOf(boxId) {
  const { records } = createV1ObservedAreaDirectory().records(() => 0);
  return records.find((e) => e.name.endsWith(String(boxId).padStart(2, '0'))).key;
}

function harness(extra = {}) {
  let nowMs = 1_000, iv = null;
  const wheel = new TimingWheel({
    tickMs: 100, clock: () => nowMs,
    setInterval: (fn) => { iv = { fn, unref() {} }; return iv; },
    clearInterval: () => { iv = null; }, onError: () => {}
  });
  wheel.start();
  const table = new SnapLobbySessions({
    wheel, areaDirectory: createV1ObservedAreaDirectory(), keepaliveKey: 'SNAP-SWAN',
    joinLadder: true, rosterToJoiner: true, memberIdToken: true, hostReseat: true,
    memberInfo: true, op10Relay: true, ...extra
  });
  const open = (routingKey, identity, token) => {
    const sent = [];
    const session = table.open({
      routingKey, loginIdentity: identity, endpointToken: token,
      outboundSequence: 1, inboundReceiveBase: 0, latencyTicks: 1600,
      transmit: (d, ctx) => sent.push({ datagram: d, ...ctx })
    });
    return { session, sent, token, seq: 0, next() { this.seq += 1; return this.seq - 1; } };
  };
  return { table, open };
}

function enter(c, boxId) {
  const key = Buffer.alloc(4); key.writeUInt32BE(boxKeyOf(boxId));
  c.session.accept(reliableDatagram({ opcode: LOBBY_OPCODE.AREA_ENTER, sequence: c.next(), payload: key, token: c.token }));
}
function createRoom(c) {
  c.session.accept(reliableDatagram({ opcode: LOBBY_OPCODE.CREATE_ROOM, sequence: c.next(), payload: Buffer.alloc(0x2c), token: c.token }));
}
function joinRoom(c, handle = 1) {
  const body = Buffer.alloc(0x18); body.writeUInt32LE(handle, 0);
  c.session.accept(reliableDatagram({ opcode: LOBBY_OPCODE.AREA_ENTER, sequence: c.next(), payload: body, who: 0xa000, token: c.token }));
}
function charselect(c, charId) {
  // op-0c ROOM_QUERY with a 0xf0 body = the char-select form
  c.session.accept(reliableDatagram({ opcode: LOBBY_OPCODE.ROOM_QUERY, sequence: c.next(), payload: charstatsBody(charId), token: c.token }));
}

/** member-JOIN records in a sent list, with their rec+0x18 char-id. */
function memberJoins(sent, since = 0) {
  return sent.slice(since).filter((e) =>
    e.datagram[3] === LOBBY_OPCODE.MEMBER_JOIN && e.datagram.length >= HEADER + 0x108)
    .map((e) => ({
      charId: e.datagram.readUInt16LE(HEADER + CHARSTATS_OFF + CHARID_OFF),
      // The blob head (rec+0x18+0x00) is 0xab only when a full 0xf0 blob is seeded;
      // OFF leaves it 0 (only the synthetic characterId at +0xc8 is ever written).
      seeded: e.datagram[HEADER + CHARSTATS_OFF] === 0xab
    }));
}

test('OFF (default): member records are NOT seeded (charstats head stays zero = Jim)', () => {
  const rig = harness({ charstatsSeed: false });
  const host = rig.open('192.168.2.248:2000', 'PC', 0x02f807d0);
  const joiner = rig.open('192.168.2.129:2000', 'PS2', 0x028107d0);
  enter(host, 1); charselect(host, 0x0011); createRoom(host);
  enter(joiner, 1); charselect(joiner, 0x0022);
  const at = host.sent.length;
  joinRoom(joiner, 1);
  assert.ok(memberJoins(host.sent, at).every((r) => !r.seeded),
    'pre-fix: no member-JOIN carries a seeded charstats blob');
});

test('ON: fanout to host carries the JOINER charstats; roster-to-joiner carries the HOST charstats', () => {
  const rig = harness({ charstatsSeed: true });
  const host = rig.open('192.168.2.248:2000', 'PC', 0x02f807d0);
  const joiner = rig.open('192.168.2.129:2000', 'PS2', 0x028107d0);
  enter(host, 1); charselect(host, 0x0011); createRoom(host);
  enter(joiner, 1); charselect(joiner, 0x0022);
  const atHost = host.sent.length, atJoiner = joiner.sent.length;
  joinRoom(joiner, 1);
  // host->joiner direction: the host sees the joiner's real char (0x0022)
  const toHost = memberJoins(host.sent, atHost);
  assert.ok(toHost.some((r) => r.seeded && r.charId === 0x0022),
    'the fanout member-JOIN to the host carries the joiner char-id 0x0022 at rec+0x18+0xc8');
  // the host's OWN seat (create-self + host-reseat) carries the host's real char
  // (0x0011) - otherwise the reseat clobbers it with the synthetic id 1 = Mark.
  const hostSelf = memberJoins(host.sent).filter((r) => r.charId === 0x0011);
  assert.ok(hostSelf.length > 0 && hostSelf.every((r) => r.seeded),
    'the host self-seat (reseat/create) carries the host char 0x0011, not the synthetic Mark');
  // joiner->host-view direction: the joiner sees the host's real char (0x0011)
  const toJoiner = memberJoins(joiner.sent, atJoiner);
  assert.ok(toJoiner.some((r) => r.seeded && r.charId === 0x0011),
    'the roster-to-joiner member-JOIN carries the host char-id 0x0011 at rec+0x18+0xc8');
});
