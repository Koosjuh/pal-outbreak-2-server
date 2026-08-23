import assert from 'node:assert/strict';
import test from 'node:test';

import { ROOM_STATUS } from '../src/state/room-lifecycle.js';
import { TimingWheel } from '../src/transport/timing-wheel.js';
import { createV1ObservedAreaDirectory } from '../src/udp/area-directory.js';
import {
  COMPLETION_SELECTOR,
  LOBBY_OPCODE,
  ROOM_EVENT_SUB,
  buildJoinConfirmPayload
} from '../src/udp/snap-lobby-codec.js';
import { SnapLobbySessions } from '../src/udp/snap-lobby-sessions.js';

/**
 * THE JOIN LADDER (PORT-PLAN slice 1b, flag SNAP_JOIN_LADDER) - bioserver
 * JOINGAME wired to SN@P.
 *
 * Wire shapes under test are the July rig path, byte for byte:
 *
 *   the room-ENTER is the DATA-clear op-0x06 with the fixed 0x18-byte body
 *   `FUN_001dcdfc` builds, room handle at +0x00 in the op-0x49 record's own LE
 *   bytes (V1 `SNAP_ROOM_ENTER_ACCEPT`, `game_udp_server.js:1755-1786`);
 *
 *   its accept is op-0x28 selector 6 with who 0xA0 - the DATA bit is the ONLY
 *   difference from the area accept, and it is what routes the completion to
 *   the room-enter slot 0x22 `FUN_005c05c0` instead of the area slot 0x21
 *   (`G12-enter-accept-reply-RE-2026-07-11`);
 *
 *   the join-confirm is the op-0x10 app-sub-0x0C push of the rig-proven V1 fix
 *   (`SNAP_JOIN_OP10_SUBC`, Pi cead951e): `[BE32 1][request +0x04 echo]
 *   [0C000000][LE32 count]` (`G12-joiner-tag17-RE-2026-07-16.md`).
 */

const TOKEN_HOST = 0x02f807d0;
const TOKEN_JOINER = 0x02f907d1;

function reliableDatagram({ opcode, sequence, sub = 0, payload = Buffer.alloc(0), who = 0xb000, token = TOKEN_HOST }) {
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

function harness({ sessions = {} } = {}) {
  let nowMs = 1_000;
  let intervalToken = null;
  const wheel = new TimingWheel({
    tickMs: 100,
    clock: () => nowMs,
    setInterval: (fn) => { intervalToken = { fn, unref() {} }; return intervalToken; },
    clearInterval: () => { intervalToken = null; },
    onError: () => {}
  });
  wheel.start();
  const table = new SnapLobbySessions({
    wheel,
    areaDirectory: createV1ObservedAreaDirectory(),
    keepaliveKey: 'SNAP-SWAN',
    joinLadder: true,
    ...sessions
  });
  const open = (routingKey, identity, token = TOKEN_HOST) => {
    const sent = [];
    const session = table.open({
      routingKey,
      loginIdentity: identity,
      endpointToken: token,
      outboundSequence: 1,
      inboundReceiveBase: 0,
      latencyTicks: 1600,
      transmit: (datagram, context) => sent.push({ datagram, ...context })
    });
    return { session, sent, token, seq: 0, next() { this.seq += 1; return this.seq - 1; } };
  };
  return { table, open };
}

function enter(client, boxKey) {
  const key = Buffer.alloc(4);
  key.writeUInt32BE(boxKey);
  client.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.AREA_ENTER, sequence: client.next(), payload: key, token: client.token
  }));
}

/** Create a room through the real op-0x04 path; returns the minted handle. */
function createRoom(client) {
  const before = client.sent.length;
  client.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.CREATE_ROOM, sequence: client.next(), payload: Buffer.alloc(0x2c),
    token: client.token
  }));
  const accept = client.sent.slice(before).find((entry) =>
    entry.datagram.length >= 0x1c && entry.datagram[3] === LOBBY_OPCODE.COMPLETION &&
    entry.datagram.readUInt32BE(0x10) === COMPLETION_SELECTOR.CREATE_ROOM);
  assert.ok(accept, 'the create accept left');
  return accept.datagram.readUInt32BE(0x14);
}

/** The fixed 0x18-byte room-ENTER body: handle LE at +0x00, name at +0x09. */
function roomEnterBody(handle, name = '') {
  const payload = Buffer.alloc(0x18);
  payload.writeUInt32LE(handle, 0x00);
  Buffer.from(name, 'latin1').copy(payload, 0x09);
  return payload;
}

function sendRoomEnter(client, handle) {
  const before = client.sent.length;
  const [outcome] = client.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.AREA_ENTER,
    sequence: client.next(),
    payload: roomEnterBody(handle),
    who: 0xa000,
    token: client.token
  })).handled;
  return { outcome, sent: client.sent.slice(before) };
}

function pushesOf(sent, opcode) {
  return sent.filter((entry) =>
    entry.datagram.length > 4 && entry.datagram[3] === opcode &&
    entry.kind !== 'ack');
}

/* ---- the accept, and the engine transitions behind it -------------------- */

test('a DATA-clear room ENTER joins the room: allocator playernum, DATA-clear sel-6 accept', () => {
  const rig = harness();
  const host = rig.open('192.0.2.248:2000', 'host', TOKEN_HOST);
  const joiner = rig.open('192.0.2.129:2000', 'joiner', TOKEN_JOINER);
  enter(host, 5);
  enter(joiner, 5);
  const handle = createRoom(host);

  const { outcome, sent } = sendRoomEnter(joiner, handle);

  assert.equal(outcome.joined, true);
  assert.equal(outcome.answered, true);
  assert.equal(outcome.playernum, 2, 'first joiner takes playernum 2 (host is 1)');
  assert.equal(joiner.session.presence.roomHandle, handle, 'presence moved into the room');
  assert.equal(joiner.session.presence.slot, 1, 'presence slot = playernum - 1');
  assert.equal(rig.table.profiles.get('joiner').playernum, 2);
  assert.equal(rig.table.profiles.get('host').playernum, 1, 'assignHost ran at create');
  assert.equal(rig.table.profiles.get('host').hostflag, 1);

  const accept = sent.find((entry) =>
    entry.datagram[3] === LOBBY_OPCODE.COMPLETION &&
    entry.datagram.length >= 0x1c &&
    entry.datagram.readUInt32BE(0x10) === COMPLETION_SELECTOR.AREA_ENTER);
  assert.ok(accept, 'the sel-6 accept left');
  /*
   * who 0xA0: RELIABLE | SET with DATA CLEAR. The client's dispatcher routes
   * sel-6 by the DATA bit - clear reaches the room-enter slot 0x22
   * (FUN_005c05c0, sets 0x6ff2b1=1), set reaches the area slot 0x21. The
   * inner length is 16 + 8 = 0x18, so the whole first byte is 0xa0.
   */
  assert.equal(accept.datagram[0], 0xa0, 'who byte 0xA0 - the slot-0x22 routing');
  assert.equal(accept.datagram.readUInt32BE(0x14), 0, 'status 0');
});

test('the join fans the member record + sub-5 counts to the existing members AND the joiner', () => {
  const rig = harness();
  const host = rig.open('192.0.2.248:2000', 'host', TOKEN_HOST);
  const joiner = rig.open('192.0.2.129:2000', 'joiner', TOKEN_JOINER);
  enter(host, 5);
  enter(joiner, 5);
  const handle = createRoom(host);
  const hostBefore = host.sent.length;

  const { sent } = sendRoomEnter(joiner, handle);

  // The EXISTING member (the host) sees the joiner: one op-0x06 member-JOIN
  // delta carrying the joiner's login handle, plus the sub-5 count refresh.
  const hostJoins = pushesOf(host.sent.slice(hostBefore), LOBBY_OPCODE.MEMBER_JOIN);
  assert.equal(hostJoins.length, 1, 'exactly one delta, from exactly this transition');
  const record = hostJoins[0].datagram.subarray(0x10);
  assert.equal(record.subarray(0, 6).toString('latin1'), 'joiner', 'the login handle, verbatim');
  assert.equal(record.readUInt32BE(0x10), 2, 'memberId = playernum');
  const hostLimits = pushesOf(host.sent.slice(hostBefore), LOBBY_OPCODE.ROOM_STATE);
  assert.equal(hostLimits.length, 1);
  assert.equal(hostLimits[0].datagram[0x18], 0x05, 'sub-5');
  assert.equal(hostLimits[0].datagram[0x1c], 4, 'max');
  assert.equal(hostLimits[0].datagram[0x1d], 2, 'current AFTER the join (rule L1)');

  // The JOINER gets its own pair - the create path's rig-confirmed shape.
  const joinerJoins = pushesOf(sent, LOBBY_OPCODE.MEMBER_JOIN);
  assert.equal(joinerJoins.length, 1, 'B sees B');
  const joinerLimits = pushesOf(sent, LOBBY_OPCODE.ROOM_STATE);
  assert.equal(joinerLimits.length, 1);
  assert.equal(joinerLimits[0].datagram[0x1d], 2);
});

/* ---- the join-confirm: the rig-proven V1 bytes --------------------------- */

test('the op-0x10 sub-0x02 join-request is answered with the exact V1 sub-0x0C bytes', () => {
  const rig = harness();
  const host = rig.open('192.0.2.248:2000', 'host', TOKEN_HOST);
  const joiner = rig.open('192.0.2.129:2000', 'joiner', TOKEN_JOINER);
  enter(host, 5);
  enter(joiner, 5);
  const handle = createRoom(host);
  sendRoomEnter(joiner, handle);
  const before = joiner.sent.length;

  // The July joiner's request body, verbatim: 00000001 <token> 02000000.
  const request = Buffer.alloc(0x0c);
  request.writeUInt32BE(1, 0x00);
  request.writeUInt32BE(TOKEN_HOST, 0x04);
  request[0x08] = ROOM_EVENT_SUB.JOIN_REQUEST;
  const [outcome] = joiner.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.ROOM_STATE, sequence: joiner.next(), payload: request,
    who: 0xa000, token: joiner.token
  })).handled;

  assert.equal(outcome.joinConfirm, true);
  assert.equal(outcome.answered, true);
  const confirm = pushesOf(joiner.sent.slice(before), LOBBY_OPCODE.ROOM_STATE)[0];
  assert.ok(confirm, 'the confirm left on op-0x10');
  assert.equal(confirm.datagram[0], 0xa0, 'who 0xA0, DATA clear -> slot 0x13');
  const body = confirm.datagram.subarray(0x10, confirm.datagram.length - 4);
  // Byte for byte the V1 push body (game_udp_server.js:1889-1899):
  // header word 1, the request's +0x04 word echoed, sub 0x0C, count LE.
  assert.equal(body.readUInt32BE(0x00), 1, 'header word 1, mirroring the proven sub-1 push');
  assert.equal(body.readUInt32BE(0x04), TOKEN_HOST, 'the request +0x04 word, echoed verbatim');
  assert.equal(body[0x08], 0x0c, 'sub 0x0C fires FUN_005bbe00 -> continuation 0x601300');
  assert.equal(body.readUInt32LE(0x0c), 2, 'LE count = the real post-join room population');
  assert.deepEqual(
    body,
    buildJoinConfirmPayload({ requestEcho: request.subarray(4, 8), count: 2 }),
    'and the builder is what shipped'
  );
});

/* ---- the guards: allocator integration ----------------------------------- */

test('a BUSY room refuses the join: nothing accepted, nothing moved, nothing sent', () => {
  const rig = harness();
  const host = rig.open('192.0.2.248:2000', 'host', TOKEN_HOST);
  const joiner = rig.open('192.0.2.129:2000', 'joiner', TOKEN_JOINER);
  enter(host, 5);
  enter(joiner, 5);
  const handle = createRoom(host);
  rig.table.roomLifecycle.markBusy(handle);

  const { outcome, sent } = sendRoomEnter(joiner, handle);

  assert.equal(outcome.joined, false);
  assert.equal(outcome.refused, 'full', 'guard 1: BUSY -> "game is full"');
  assert.equal(outcome.answered, false, 'no wire rejection vehicle exists; do-not-accept');
  assert.equal(joiner.session.presence.roomHandle, null, 'presence never moved');
  assert.equal(pushesOf(sent, LOBBY_OPCODE.COMPLETION).length, 0, 'no accept left');
});

test('the join that FILLS the room flips it BUSY, and the next joiner is refused full', () => {
  const rig = harness();
  const host = rig.open('192.0.2.248:2000', 'host', TOKEN_HOST);
  enter(host, 5);
  const handle = createRoom(host);
  const joiners = [2, 3, 4].map((n) =>
    rig.open(`192.0.2.1${n}:2000`, `joiner${n}`, TOKEN_JOINER + n));
  for (const joiner of joiners) {
    enter(joiner, 5);
    const { outcome } = sendRoomEnter(joiner, handle);
    assert.equal(outcome.joined, true);
  }
  assert.equal(rig.table.presence.countInRoom(handle), 4);
  assert.equal(rig.table.roomLifecycle.statusOf(handle), ROOM_STATUS.BUSY,
    'full -> BUSY (sendJoinGame lines 1683-1686)');

  const fifth = rig.open('192.0.2.99:2000', 'fifth', TOKEN_JOINER + 9);
  enter(fifth, 5);
  const { outcome } = sendRoomEnter(fifth, handle);
  assert.equal(outcome.joined, false);
  assert.equal(outcome.refused, 'full');
});

test('a join into a room in ANOTHER area is refused without moving anything', () => {
  const rig = harness();
  const host = rig.open('192.0.2.248:2000', 'host', TOKEN_HOST);
  const joiner = rig.open('192.0.2.129:2000', 'joiner', TOKEN_JOINER);
  enter(host, 5);
  enter(joiner, 3);
  const handle = createRoom(host);

  const { outcome } = sendRoomEnter(joiner, handle);

  assert.equal(outcome.joined, false);
  assert.equal(outcome.refused, 'room-not-in-this-area');
  assert.equal(joiner.session.presence.roomHandle, null);
});

test('the Vacant-slot CREATE form (zero handle, typed title) takes the pre-branch area path, flag ON', () => {
  /*
   * THE V1 DISCRIMINANT, not the DATA flag (`server/game_udp_server.js:
   * 1649-1651`, the 2026-07-12 correction): a create on a Vacant slot
   * transmits op-0x06 through the SAME `FUN_001dcdfc` builder as the join -
   * declared inner len 0x28, DATA clear - but with handle 0 (`0x6fee68[idx]`
   * unwritten, Ghidra FUN_005c04f0) and the PLAYER-TYPED title at +0x09.
   *
   * An earlier revision routed on `!data` alone, which swept this form into
   * the join ladder: the zero handle resolved to no room and the one-shot
   * ENTER died as a silent 'no-such-room' refusal - a create screen that
   * never advances (nora pre-deploy review, caveat 4). Only a NON-ZERO handle
   * may enter the ladder; the create form must get the pre-branch area
   * accept, byte-identical to the rig-run builds that created rooms.
   */
  const rig = harness();
  const creator = rig.open('192.0.2.248:2000', 'creator', TOKEN_HOST);
  enter(creator, 5);
  const before = creator.sent.length;

  const [outcome] = creator.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.AREA_ENTER,
    sequence: creator.next(),
    payload: roomEnterBody(0, 'MYROOM'),
    who: 0xa000,
    token: creator.token
  })).handled;

  assert.equal(outcome.joined, undefined, 'the ladder never saw it: handle 0 is not a join');
  assert.equal(outcome.answered, true, 'ANSWERED - the silent refusal is the regression');
  const accept = pushesOf(creator.sent.slice(before), LOBBY_OPCODE.COMPLETION)[0];
  assert.ok(accept, 'the pre-branch area accept left');
  assert.equal(accept.datagram[0], 0xb0, 'who 0xB0 - the pre-branch area-accept bytes, unchanged');
  assert.equal(accept.datagram.readUInt32BE(0x10), COMPLETION_SELECTOR.AREA_ENTER, 'selector 6');
  assert.equal(creator.session.presence.roomHandle, null, 'and no phantom membership');
});

test('a handle that names no room is refused, never guessed into an area move', () => {
  const rig = harness();
  const joiner = rig.open('192.0.2.129:2000', 'joiner', TOKEN_JOINER);
  enter(joiner, 5);

  const { outcome } = sendRoomEnter(joiner, 0x77);

  assert.equal(outcome.joined, false);
  assert.equal(outcome.refused, 'no-such-room');
  assert.equal(joiner.session.presence.boxId, 5, 'the area presence is untouched');
  assert.equal(joiner.session.presence.roomHandle, null);
});

test('a profile-less join is REFUSED with a journalled reason, never a handler-threw', () => {
  /*
   * The bind's profile open is logged-and-tolerated (`snap-lobby-sessions.js
   * open()`), so a live session without a profile is peer-reachable state.
   * The allocator used to throw ALLOCATOR_PROFILE, which the per-message
   * dispatch guard caught and journalled as a misleading generic "snap-lobby
   * handler-threw" (nora pre-deploy fix 3). It must surface as a structured
   * join refusal instead - same journal event as every other refused join,
   * with its reason.
   */
  const logs = [];
  const record = (level) => (message, fields) => logs.push({ level, message, fields });
  const logger = { info: record('info'), warn: record('warn'), error: record('error') };
  const rig = harness({ sessions: { logger } });
  const host = rig.open('192.0.2.248:2000', 'host', TOKEN_HOST);
  const joiner = rig.open('192.0.2.129:2000', 'joiner', TOKEN_JOINER);
  enter(host, 5);
  enter(joiner, 5);
  const handle = createRoom(host);
  // Put the joiner into the tolerated profile-less state directly.
  rig.table.profiles.release('joiner');

  const { outcome } = sendRoomEnter(joiner, handle);

  assert.equal(outcome.joined, false);
  assert.equal(outcome.refused, 'no-profile', 'guard 0: the PAL-side profile-less refusal');
  assert.equal(joiner.session.presence.roomHandle, null, 'nothing moved');
  assert.ok(
    logs.some((entry) => entry.message === 'udp9090 lobby-room-enter-refused' &&
      entry.fields?.reason === 'no-profile'),
    'the journal reads as a join refusal with its reason'
  );
  assert.ok(
    !logs.some((entry) => entry.message === 'snap-lobby handler-threw'),
    'and never as the generic handler-threw'
  );
});

/* ---- flag off: byte-identical to every previous build -------------------- */

test('flag OFF: the DATA-clear ENTER falls through to the area path unchanged', () => {
  const rig = harness({ sessions: { joinLadder: false } });
  const host = rig.open('192.0.2.248:2000', 'host', TOKEN_HOST);
  const joiner = rig.open('192.0.2.129:2000', 'joiner', TOKEN_JOINER);
  enter(host, 5);
  enter(joiner, 5);
  const handle = createRoom(host);
  const hostBefore = host.sent.length;

  const { outcome, sent } = sendRoomEnter(joiner, handle);

  assert.equal(outcome.joined, undefined, 'the area handler answered, not the ladder');
  assert.equal(joiner.session.presence.roomHandle, null, 'nobody joined anything');
  const accept = pushesOf(sent, LOBBY_OPCODE.COMPLETION)[0];
  assert.ok(accept, 'the area path still answers sel-6, as it always did');
  assert.equal(accept.datagram[0], 0xb0, 'who 0xB0 - the DATA-set area form');
  assert.equal(pushesOf(host.sent.slice(hostBefore), LOBBY_OPCODE.MEMBER_JOIN).length, 0,
    'and no fan-out happened');
});

test('flag OFF: the op-0x10 join-request stays an unhandled opcode', () => {
  const rig = harness({ sessions: { joinLadder: false, op10Relay: false } });
  const joiner = rig.open('192.0.2.129:2000', 'joiner', TOKEN_JOINER);
  enter(joiner, 5);
  const before = joiner.sent.length;

  const request = Buffer.alloc(0x0c);
  request.writeUInt32BE(1, 0x00);
  request.writeUInt32BE(TOKEN_HOST, 0x04);
  request[0x08] = ROOM_EVENT_SUB.JOIN_REQUEST;
  const [outcome] = joiner.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.ROOM_STATE, sequence: joiner.next(), payload: request,
    who: 0xa000, token: joiner.token
  })).handled;

  assert.equal(outcome.answered, false);
  assert.equal(pushesOf(joiner.sent.slice(before), LOBBY_OPCODE.ROOM_STATE).length, 0);
});

/* ---- leaving keeps the engine honest ------------------------------------- */

test('when the last member leaves, the engine records close with the room', () => {
  const rig = harness();
  const host = rig.open('192.0.2.248:2000', 'host', TOKEN_HOST);
  enter(host, 5);
  const handle = createRoom(host);
  assert.equal(rig.table.roomLifecycle.statusOf(handle), ROOM_STATUS.GAMESET);
  assert.ok(rig.table.roomLifecycle.get(handle) != null);

  // The op-0x07 LEAVE, exactly as the client sends it: zero body, reliable.
  host.session.accept(reliableDatagram({
    opcode: LOBBY_OPCODE.AREA_LEAVE, sequence: host.next()
  }));

  assert.equal(rig.table.rooms.byHandle(handle), null, 'the room closed');
  assert.equal(rig.table.roomLifecycle.get(handle), null,
    'and the lifecycle record went with it (releaseRoomState via onRoomEmptied)');
});
