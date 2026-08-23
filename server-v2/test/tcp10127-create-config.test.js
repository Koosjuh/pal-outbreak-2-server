import assert from 'node:assert/strict';
import net from 'node:net';
import test from 'node:test';

import {
  Tcp10127ProtocolError,
  Tcp10127StreamDecoder,
  decodeTcp10127Frame
} from '../src/protocol/tcp10127-codec.js';
import { encodeSnapField } from '../src/protocol/snap-field-codec.js';
import {
  TCP10127_CREATE_CONFIG,
  Tcp10127CreateConfigDialogue
} from '../src/tcp/create-config-dialogue.js';
import {
  TCP10127_LOBBY_INITIALIZATION_STATE,
  Tcp10127LobbyInitializationSession
} from '../src/tcp/lobby-initialization-session.js';
import { createTcp10127Service } from '../src/tcp/tcp10127-service.js';
import { createV1ObservedAreaTable } from '../src/state/area-table-v1.js';
import { AREA_TABLE_TRANSFER } from '../src/state/area-table.js';
import { ROOM_STATUS, createRoomLifecycleRegistry } from '../src/state/room-lifecycle.js';
import { createPlayerProfileRegistry } from '../src/state/player-profile.js';

/**
 * THE CREATE-CONFIG DIALOGUE (SNAP_CREATE_CONFIG) - BIOSERVER-CONTRACT §6
 * create rows on the PAL 8-byte TCP framing.
 *
 * EVIDENCE STATUS OF THESE BYTES, stated before anything asserts on them: the
 * RS1 TCP inventory (`docs/design/v2-port/RS1-TCP-INVENTORY.md`) parsed every
 * TCP-10127 byte of a capture in which rooms WERE created, and none of the
 * create-dialogue commands appeared on TCP - the create window rode UDP 9090.
 * There are therefore NO captured create-dialogue bytes to replay. Every
 * create-row frame below is CONTRACT-DERIVED SYNTHETIC, built in the captured
 * 8-byte framing (len BE16 / dir / cmd BE16 / seq / err / 0xFF - the framing
 * all 5299 RS1 packets ground) with sequences 0x10..0x18, outside every
 * captured run in this repository so they cannot be mistaken for capture.
 *
 * The LADDER frames that walk a session to LOBBY_INITIALIZATION_COMPLETE are
 * the captured ones (`test/tcp10127-state-backed-ladder.test.js` provenance
 * notes apply), with the same synthetic 0x6204/0x6510 fill-ins that file uses.
 */

const AREA_TABLE = createV1ObservedAreaTable();
const CODEC_BYTE = 0;

function frame({ command, sequence, payload = Buffer.alloc(0), direction = 0x01, error = 0, unknown7 = 0xff }) {
  const header = Buffer.alloc(8);
  header.writeUInt16BE(payload.length, 0);
  header[2] = direction;
  header.writeUInt16BE(command, 3);
  header[5] = sequence;
  header[6] = error;
  header[7] = unknown7;
  return Buffer.concat([header, payload]);
}

/* ---- the create-dialogue frames (contract-derived synthetic) ------------- */

const SLOT_NUMBER = 5;
const SLOT_TYPE = 0x11; // DVD
const SCENARIO = 2;     // Underbelly
const TITLE = Buffer.from('ROOM', 'latin1');
const PASSWORD = Buffer.from('pw', 'latin1');
const CHAR_BLOB = Buffer.alloc(0xd0, 0x5a);

function buildCreateDialogueFrames() {
  const createSlotPayload = Buffer.alloc(2);
  createSlotPayload.writeUInt16BE(SLOT_NUMBER, 0);
  const scenePayload = Buffer.alloc(4);
  scenePayload.writeUInt16BE(SLOT_TYPE, 0);
  scenePayload.writeUInt16BE(SCENARIO, 2);
  return [
    { name: 'CREATESLOT', command: 0x6407, sequence: 0x10, payload: createSlotPayload },
    { name: 'SCENESELECT', command: 0x6509, sequence: 0x11, payload: scenePayload },
    {
      name: 'SLOTNAME', command: 0x6609, sequence: 0x12,
      payload: encodeSnapField({
        plain: TITLE, maximumDecodedLength: 0xff, sequence: 0x12, unknownCodecByte: CODEC_BYTE
      })
    },
    {
      name: 'SLOTPASSWD', command: 0x660a, sequence: 0x13,
      payload: encodeSnapField({
        plain: PASSWORD, maximumDecodedLength: 0xff, sequence: 0x13, unknownCodecByte: CODEC_BYTE
      })
    },
    { name: 'SETRULE players', command: 0x660b, sequence: 0x14, payload: Buffer.from([0x00, 0x01]) },
    { name: 'SETRULE difficulty', command: 0x660b, sequence: 0x15, payload: Buffer.from([0x02, 0x00]) },
    { name: 'UNKN660C', command: 0x660c, sequence: 0x16, payload: Buffer.alloc(0) },
    { name: 'CHARSELECT', command: 0x6190, sequence: 0x17, payload: Buffer.from(CHAR_BLOB) },
    { name: 'COMMIT 0x6504', command: 0x6504, sequence: 0x18, payload: Buffer.from([0x01]) }
  ];
}

/** The six-broadcast set the 0x6504 commit fires, in the reference order. */
const COMMIT_BROADCAST_ORDER = [
  0x6403, // SLOTPLRSTATUS
  0x6405, // SLOTPWDPROT
  0x6404, // SLOTSTATUS
  0x650a, // SLOTSCENTYPE
  0x640b, // SLOTATTRIB2
  0x6506  // PLAYEROK
];

function makeEngine() {
  const roomLifecycle = createRoomLifecycleRegistry();
  const profiles = createPlayerProfileRegistry();
  const profile = profiles.open({ accountSessionId: 'as-1', handle: 'HOST01' });
  return { roomLifecycle, profiles, profile };
}

function makeDialogue({ roomLifecycle, profile, ...rest } = {}) {
  return new Tcp10127CreateConfigDialogue({
    roomLifecycle,
    resolveProfile: profile == null ? null : () => profile,
    now: () => 1_000_000,
    ...rest
  });
}

/* ========================================================================== *
 * Engine-level: the GAMESET flip happens at the 0x6504 commit and NOWHERE
 * else. This is the discriminating test for the whole slice: an
 * implementation that flips at CREATESLOT, at SCENESELECT, or at SLOTNAME
 * fails the INCREATE assertions; one that never flips fails the final one.
 * ========================================================================== */

test('the room stays INCREATE through every config row and flips GAMESET only at 0x6504', () => {
  const { roomLifecycle, profile } = makeEngine();
  const dialogue = makeDialogue({ roomLifecycle, profile });

  for (const step of buildCreateDialogueFrames()) {
    const result = dialogue.handleFrame(decodeTcp10127Frame(frame(step)));
    const reply = decodeTcp10127Frame(result.response);
    // Every row is answered: same command, same sequence, err 0 - the shape of
    // all 186 observed RS1 TELLs.
    assert.equal(reply.direction, 0x02, `${step.name} reply direction`);
    assert.equal(reply.command, step.command, `${step.name} reply command`);
    assert.equal(reply.sequence, step.sequence, `${step.name} reply sequence`);
    assert.equal(reply.error, 0, `${step.name} reply error`);
    const expected = step.command === 0x6504 ? ROOM_STATUS.GAMESET : ROOM_STATUS.INCREATE;
    assert.equal(
      roomLifecycle.statusOf(SLOT_NUMBER), expected,
      `after ${step.name} the room must be ${expected === ROOM_STATUS.GAMESET ? 'GAMESET' : 'INCREATE'}`
    );
  }

  // The engine state the dialogue wrote, read back through the engine modules.
  const record = roomLifecycle.get(SLOT_NUMBER);
  assert.equal(record.slotType, SLOT_TYPE);
  assert.equal(record.scenario, SCENARIO);
  assert.equal(record.protection, 1, 'a non-empty SLOTPASSWD flips protection ON');
  assert.equal(record.rules.ruleValue(0), 1, 'SETRULE players value stored');
  assert.equal(record.rules.ruleValue(2), 0, 'SETRULE difficulty value stored');
  assert.equal(record.rules.numberOfPlayers(), 3, 'players value 1 -> three players');
  assert.deepEqual(profile.characterStats, CHAR_BLOB, 'CHARSELECT blob store-and-echo');
  assert.equal(profile.hostflag, 1, 'CREATESLOT sets hostflag');
  assert.equal(profile.playernum, 1, 'CREATESLOT assigns playernum 1');
  // The commit armed the wait timer from the rule set (10 minutes default was
  // not changed above): remaining is a number, not null.
  const timer = roomLifecycle.checkWaitTimer(SLOT_NUMBER, { nowMs: 1_000_000 });
  assert.notEqual(timer.remainingSeconds, null, 'the commit arms the wait timer');
});

test('a non-host 0x6504 answers but never flips the room to GAMESET', () => {
  const { roomLifecycle, profiles } = makeEngine();
  // The room exists from elsewhere (the UDP create path in production).
  roomLifecycle.beginCreate(SLOT_NUMBER, { areaNumber: 0 });
  const joiner = profiles.open({ accountSessionId: 'as-2', handle: 'JOIN01' });
  joiner.setPlayerNum(2); // hostflag stays 0
  const dialogue = makeDialogue({
    roomLifecycle,
    profile: joiner,
    resolveRoomHandle: () => SLOT_NUMBER
  });

  const result = dialogue.handleFrame(decodeTcp10127Frame(frame({
    command: 0x6504, sequence: 0x20, payload: Buffer.from([0x01])
  })));
  const reply = decodeTcp10127Frame(result.response);
  assert.equal(reply.command, 0x6504);
  assert.equal(reply.error, 0);
  assert.deepEqual(reply.payload, Buffer.from([0x01]), 'TELL echoes payload[0]');
  assert.equal(
    roomLifecycle.statusOf(SLOT_NUMBER), ROOM_STATUS.INCREATE,
    'only the HOST commit makes the room joinable'
  );
  // PLAYEROK carries the joiner's own playernum.
  const playerOk = decodeTcp10127Frame(result.broadcasts.at(-1));
  assert.equal(playerOk.command, 0x6506);
  assert.equal(playerOk.payload.readUInt16BE(0), 2);
});

test('TELL payloads carry the contract shapes', () => {
  const { roomLifecycle, profile } = makeEngine();
  const dialogue = makeDialogue({ roomLifecycle, profile });
  const replies = new Map();
  for (const step of buildCreateDialogueFrames()) {
    const result = dialogue.handleFrame(decodeTcp10127Frame(frame(step)));
    replies.set(step.name, decodeTcp10127Frame(result.response));
  }
  assert.deepEqual(
    replies.get('CREATESLOT').payload,
    Buffer.from([0x00, SLOT_NUMBER]),
    'CREATESLOT TELL {0, slot}'
  );
  const scene = replies.get('SCENESELECT').payload;
  assert.equal(scene.length, 6);
  assert.equal(scene.readUInt16BE(0), SLOT_NUMBER);
  assert.equal(scene.readUInt16BE(2), SLOT_TYPE);
  assert.equal(scene.readUInt16BE(4), SCENARIO);
  assert.equal(replies.get('SLOTNAME').payload.length, 0, 'SLOTNAME TELL empty');
  assert.equal(replies.get('SLOTPASSWD').payload.length, 0, 'SLOTPASSWD TELL empty');
  assert.deepEqual(replies.get('SETRULE players').payload, Buffer.from([0x01]), 'SETRULE TELL {1}');
  assert.equal(replies.get('UNKN660C').payload.length, 0);
  assert.equal(replies.get('CHARSELECT').payload.length, 0);
  assert.deepEqual(replies.get('COMMIT 0x6504').payload, Buffer.from([0x01]));
});

test('the 0x6504 commit returns the six broadcasts in the reference order, before the TELL', () => {
  const { roomLifecycle, profile } = makeEngine();
  const dialogue = makeDialogue({ roomLifecycle, profile });
  let commit = null;
  for (const step of buildCreateDialogueFrames()) {
    commit = dialogue.handleFrame(decodeTcp10127Frame(frame(step)));
  }
  const pushes = commit.broadcasts.map((raw) => decodeTcp10127Frame(raw));
  assert.deepEqual(
    pushes.map((push) => push.command),
    COMMIT_BROADCAST_ORDER,
    'SLOTPLRSTATUS, SLOTPWDPROT, SLOTSTATUS, SLOTSCENTYPE, SLOTATTRIB2, PLAYEROK'
  );
  for (const push of pushes) {
    assert.equal(push.direction, 0x10, 'broadcasts are server-push frames');
    assert.equal(push.error, 0);
  }
  const [plrStatus, pwdProt, slotStatus, sceneType, attrib2, playerOk] = pushes;
  assert.equal(plrStatus.payload.length, 10);
  assert.equal(plrStatus.payload.readUInt16BE(0), SLOT_NUMBER);
  assert.equal(plrStatus.payload.readUInt16BE(2), 1, 'one member during create');
  assert.equal(plrStatus.payload.readUInt16BE(6), 3, 'max from the rule set (value 1 -> 3)');
  assert.equal(pwdProt.payload[2], 1, 'protection ON after SLOTPASSWD');
  assert.equal(slotStatus.payload[2], ROOM_STATUS.GAMESET, 'the status broadcast carries GAMESET');
  assert.equal(sceneType.payload.readUInt16BE(2), SLOT_TYPE);
  assert.equal(sceneType.payload.readUInt16BE(4), SCENARIO);
  assert.equal(attrib2.payload.length, 12);
  assert.equal(attrib2.payload.readUInt16BE(2), 3);
  assert.equal(playerOk.payload.readUInt16BE(0), 1, 'PLAYEROK {0,playernum,0,0}');
});

test('CREATESLOT returns SLOTPLRSTATUS + SLOTSTATUS, and SLOTNAME returns SLOTTITLE', () => {
  const { roomLifecycle, profile } = makeEngine();
  const dialogue = makeDialogue({ roomLifecycle, profile });
  const steps = buildCreateDialogueFrames();
  const create = dialogue.handleFrame(decodeTcp10127Frame(frame(steps[0])));
  assert.deepEqual(
    create.broadcasts.map((raw) => decodeTcp10127Frame(raw).command),
    [0x6403, 0x6404]
  );
  assert.equal(decodeTcp10127Frame(create.broadcasts[1]).payload[2], ROOM_STATUS.INCREATE);
  dialogue.handleFrame(decodeTcp10127Frame(frame(steps[1])));
  const slotName = dialogue.handleFrame(decodeTcp10127Frame(frame(steps[2])));
  /*
   * SLOTNAME is the reference's ONE inverted row: `sendSlotName` queues its
   * TELL before `broadcastSlotTitle` (PacketHandler.java:1256-1257), so the
   * SLOTTITLE rides `broadcastsAfterTell`, never the pre-TELL side.
   */
  assert.equal(slotName.broadcasts.length, 0, 'nothing before the SLOTNAME TELL');
  const title = decodeTcp10127Frame(slotName.broadcastsAfterTell[0]);
  assert.equal(title.command, 0x6402);
  assert.equal(title.payload.readUInt16BE(0), SLOT_NUMBER);
  assert.equal(title.payload.readUInt16BE(2), TITLE.length);
  assert.deepEqual(title.payload.subarray(4), TITLE, 'server strings are cleartext');
});

test('the fan-out seam receives the room scope; delivery is counted, never invented', () => {
  const { roomLifecycle, profile } = makeEngine();
  const scopes = [];
  const dialogue = makeDialogue({
    roomLifecycle,
    profile,
    broadcast: (scope, deliver) => {
      scopes.push(scope);
      // A fake peer session WITH the delivery method takes the frames.
      const delivered = [];
      deliver({ deliverCreateConfigPush: (push) => (delivered.push(push), true) });
      return delivered.length > 0 ? 1 : 0;
    }
  });
  for (const step of buildCreateDialogueFrames()) {
    dialogue.handleFrame(decodeTcp10127Frame(frame(step)));
  }
  // CREATESLOT, SLOTNAME, and the commit each fanned out once, on the room.
  assert.equal(scopes.length, 3);
  for (const scope of scopes) assert.equal(scope.roomHandle, SLOT_NUMBER);
});

test('CHARSELECT stores the encoded-field form decoded, and works without a room', () => {
  const { roomLifecycle, profile } = makeEngine();
  const dialogue = makeDialogue({ roomLifecycle, profile });
  const encoded = encodeSnapField({
    plain: CHAR_BLOB, maximumDecodedLength: 0x200, sequence: 0x30, unknownCodecByte: CODEC_BYTE
  });
  // No CREATESLOT ran: the contract sends CHARSELECT before area select too.
  const result = dialogue.handleFrame(decodeTcp10127Frame(frame({
    command: 0x6190, sequence: 0x30, payload: encoded
  })));
  assert.equal(decodeTcp10127Frame(result.response).error, 0);
  assert.deepEqual(profile.characterStats, CHAR_BLOB, 'stored DECODED, not the wire envelope');
});

test('engine refusals surface as named protocol errors', () => {
  const { roomLifecycle, profile } = makeEngine();
  const dialogue = makeDialogue({ roomLifecycle, profile });
  const steps = buildCreateDialogueFrames();
  dialogue.handleFrame(decodeTcp10127Frame(frame(steps[0])));
  // Rule 0 (players) has 3 attributes; value 9 is out of bounds.
  assert.throws(
    () => dialogue.handleFrame(decodeTcp10127Frame(frame({
      command: 0x660b, sequence: 0x31, payload: Buffer.from([0x00, 0x09])
    }))),
    (error) => error instanceof Tcp10127ProtocolError && error.code === 'RULESET_VALUE'
  );
  // A config row with no room context is refused by name.
  const bare = makeDialogue({ ...makeEngine() });
  assert.throws(
    () => bare.handleFrame(decodeTcp10127Frame(frame({
      command: 0x660b, sequence: 0x32, payload: Buffer.from([0x00, 0x01])
    }))),
    (error) => error instanceof Tcp10127ProtocolError && error.code === 'SET_RULE_NO_ROOM'
  );
});

/* ========================================================================== *
 * Session-level: the dialogue is reachable ONLY through the completed ladder,
 * and without a dialogue the same frames keep the observed-not-answered
 * behaviour (the pre-change bytes - the break-the-fix control).
 * ========================================================================== */

const LADDER = {
  lobbyInit: Buffer.from(
    '0031011007cf00ff01002e5e18c9d5fea3c4f2f9cfacdcc0d8a5d4d6f1c4f0cdd49cc59c97de91ead8ebcbe493f88df0dec9d3d2e789cbd486',
    'hex'
  ),
  keyedManifest: Buffer.from('0000016103d000ff', 'hex'),
  command6212: Buffer.from('0000016212d100ff', 'hex'),
  command6203: Buffer.from('0004016203d200ff000252d2', 'hex'),
  command6211: Buffer.from('0000016211d300ff', 'hex'),
  command6213: Buffer.from('0000016213d400ff', 'hex'),
  command6501: Buffer.from('0004016501d500ff00000000', 'hex'),
  command1004: Buffer.from('0000011004d900ff', 'hex')
};

function buildCommand6204Frames() {
  const frames = [];
  let sequence = 0xe0;
  for (let offset = 0; offset < AREA_TABLE.byteLength;
    offset += AREA_TABLE_TRANSFER.sliceLength) {
    const payload = Buffer.alloc(8);
    payload.writeUInt16BE(0, 0);
    payload.writeUInt32BE(offset, 2);
    payload.writeUInt16BE(AREA_TABLE_TRANSFER.sliceLength, 6);
    frames.push(frame({ command: 0x6204, sequence, payload }));
    sequence = (sequence + 1) & 0xff;
  }
  return frames;
}

/** An empty-batch 0x6510: count 0, then the empty trailing field envelope. */
function buildEmptyCommand6510(sequence) {
  return frame({
    command: 0x6510,
    sequence,
    payload: Buffer.concat([
      Buffer.from([0]),
      encodeSnapField({
        plain: Buffer.alloc(0), maximumDecodedLength: 0x3e, sequence, unknownCodecByte: CODEC_BYTE
      })
    ])
  });
}

/** The mode-0 route: providers for 0x6501 and 0x6510 only. */
function ladderProviders() {
  return {
    resolveCommand6501Response: () => ({ mode: 0 }),
    resolveCommand6510Response: () => ({
      unknownCodecByte: CODEC_BYTE,
      recordWords: [],
      unknownTrailingField: Buffer.alloc(0)
    })
  };
}

function walkLadderToComplete(session) {
  const ladder = [
    LADDER.lobbyInit, LADDER.keyedManifest, LADDER.command6212, LADDER.command6203,
    ...buildCommand6204Frames(),
    LADDER.command6211, LADDER.command6213, LADDER.command6501,
    buildEmptyCommand6510(0xd8), LADDER.command1004
  ];
  for (const raw of ladder) session.handleFrame(decodeTcp10127Frame(raw));
  assert.equal(session.state, TCP10127_LOBBY_INITIALIZATION_STATE.LOBBY_INITIALIZATION_COMPLETE);
}

test('after the completed ladder every create-dialogue row is answered same-cmd same-seq', () => {
  const { roomLifecycle, profile } = makeEngine();
  const session = new Tcp10127LobbyInitializationSession({
    areaTable: AREA_TABLE,
    ...ladderProviders(),
    createConfigDialogue: makeDialogue({ roomLifecycle, profile })
  });
  walkLadderToComplete(session);

  for (const step of buildCreateDialogueFrames()) {
    const result = session.handleFrame(decodeTcp10127Frame(frame(step)));
    assert.equal(result.unimplemented, false, `${step.name} must be ANSWERED, not observed`);
    const reply = decodeTcp10127Frame(result.response);
    assert.equal(reply.command, step.command, `${step.name} reply command`);
    assert.equal(reply.sequence, step.sequence, `${step.name} reply sequence`);
    assert.equal(reply.error, 0, `${step.name} reply status`);
  }
  assert.equal(roomLifecycle.statusOf(SLOT_NUMBER), ROOM_STATUS.GAMESET);
});

test('without a dialogue the same frames keep the observed-not-answered behaviour', () => {
  // THE CONTROL: this is the flag-off / pre-change behaviour. If the dialogue
  // were wired unconditionally, this test is what breaks.
  const session = new Tcp10127LobbyInitializationSession({
    areaTable: AREA_TABLE,
    ...ladderProviders()
  });
  walkLadderToComplete(session);
  for (const step of buildCreateDialogueFrames()) {
    const result = session.handleFrame(decodeTcp10127Frame(frame(step)));
    assert.equal(result.unimplemented, true, `${step.name} must stay observed without the flag`);
    assert.equal(result.response, null);
  }
});

test('a dialogue refusal falls back to observed-not-answered - it must not destroy the connection', () => {
  const { roomLifecycle, profile } = makeEngine();
  const session = new Tcp10127LobbyInitializationSession({
    areaTable: AREA_TABLE,
    ...ladderProviders(),
    createConfigDialogue: makeDialogue({ roomLifecycle, profile })
  });
  walkLadderToComplete(session);
  const steps = buildCreateDialogueFrames();
  session.handleFrame(decodeTcp10127Frame(frame(steps[0])));

  // A malformed row the dialogue REFUSES by name (rule 0 value 9 is out of
  // bounds). Pre-fix this throw escaped to the service catch and the socket
  // was destroyed - against this state's own stated observed-not-answered
  // policy. The refusal now becomes the pre-dialogue behaviour, attributably.
  const refused = session.handleFrame(decodeTcp10127Frame(frame({
    command: 0x660b, sequence: 0x31, payload: Buffer.from([0x00, 0x09])
  })));
  assert.equal(refused.unimplemented, true, 'observed-not-answered, never a throw');
  assert.equal(refused.response, null);
  assert.equal(refused.refusal, 'RULESET_VALUE', 'the named refusal survives into the journal');

  // THE POINT of not destroying the socket: the same connection still works.
  const next = session.handleFrame(decodeTcp10127Frame(frame(steps[1])));
  assert.equal(next.unimplemented, false, 'the connection survives the refused frame');
  assert.equal(decodeTcp10127Frame(next.response).command, steps[1].command);

  // A NON-refusal defect must still propagate - the fallback absorbs only the
  // dialogues' named refusal vehicle, never a server bug.
  const broken = new Tcp10127LobbyInitializationSession({
    areaTable: AREA_TABLE,
    ...ladderProviders(),
    createConfigDialogue: {
      handles: () => true,
      handleFrame: () => { throw new TypeError('a defect, not a refusal'); }
    }
  });
  walkLadderToComplete(broken);
  assert.throws(
    () => broken.handleFrame(decodeTcp10127Frame(frame(steps[0]))),
    TypeError
  );
});

test('the dialogue is NOT reachable before the ladder completes', () => {
  const { roomLifecycle, profile } = makeEngine();
  const session = new Tcp10127LobbyInitializationSession({
    areaTable: AREA_TABLE,
    ...ladderProviders(),
    createConfigDialogue: makeDialogue({ roomLifecycle, profile })
  });
  // First frame of a fresh connection: a CREATESLOT instead of 0x1007 must be
  // refused by the ladder, not answered by the dialogue.
  assert.throws(
    () => session.handleFrame(decodeTcp10127Frame(frame({
      command: 0x6407, sequence: 0x10, payload: Buffer.from([0x00, SLOT_NUMBER])
    }))),
    (error) => error instanceof Tcp10127ProtocolError && error.code === 'LOBBY_INIT_COMMAND'
  );
  assert.equal(roomLifecycle.statusOf(SLOT_NUMBER), ROOM_STATUS.FREE, 'no room was created');
});

/* ========================================================================== *
 * Service-level: over a real socket, the commit's pushes precede the TELL -
 * the reference emission order ("six broadcasts ...; finally TELL").
 * ========================================================================== */

test('over the socket the create-commit pushes arrive before the TELL, in order', async () => {
  const { roomLifecycle, profile } = makeEngine();
  const service = createTcp10127Service({
    resolveConnectionPurpose: () => 'lobby-initialization',
    createConnectionProviders: () => ({
      ...ladderProviders(),
      createConfigDialogue: makeDialogue({ roomLifecycle, profile })
    })
  });
  await new Promise((resolve) => service.listen(0, '127.0.0.1', resolve));
  const port = service.address().port;

  const socket = net.connect(port, '127.0.0.1');
  await new Promise((resolve, reject) => {
    socket.once('connect', resolve);
    socket.once('error', reject);
  });

  const decoder = new Tcp10127StreamDecoder();
  const received = [];
  let waiters = [];
  socket.on('data', (chunk) => {
    for (const decoded of decoder.push(chunk)) {
      received.push(decoded);
      // Re-check every waiter and KEEP the unsatisfied ones: several frames
      // can arrive before the one a waiter wants.
      waiters = waiters.filter((waiter) => !waiter());
    }
  });
  const waitFor = (predicate, label) => new Promise((resolve, reject) => {
    const timer = setTimeout(
      () => reject(new Error(`timed out waiting for ${label}`)), 4000
    );
    const check = () => {
      if (predicate()) {
        clearTimeout(timer);
        resolve();
        return true;
      }
      return false;
    };
    if (!check()) waiters.push(check);
  });

  try {
    // The server speaks first: the 0x6001 challenge.
    await waitFor(() => received.some((f) => f.command === 0x6001), 'the 0x6001 challenge');

    const conversation = [
      LADDER.lobbyInit, LADDER.keyedManifest, LADDER.command6212, LADDER.command6203,
      ...buildCommand6204Frames(),
      LADDER.command6211, LADDER.command6213, LADDER.command6501,
      buildEmptyCommand6510(0xd8), LADDER.command1004
    ];
    for (const raw of conversation) {
      const request = decodeTcp10127Frame(raw);
      socket.write(raw);
      await waitFor(() => received.some(
        (f) => f.command === request.command && f.sequence === request.sequence
      ), `the 0x${request.command.toString(16)} reply`);
    }

    // The whole dialogue through the socket; the commit is the frame whose
    // write-order matters.
    for (const step of buildCreateDialogueFrames()) {
      socket.write(frame(step));
      await waitFor(() => received.some(
        (f) => f.direction === 0x02 && f.command === step.command && f.sequence === step.sequence
      ), `the ${step.name} TELL`);
    }

    // Everything from the commit's first push onwards, in arrival order.
    const commitStart = received.findIndex(
      (f) => f.direction === 0x10 && f.command === 0x6403 &&
        received.slice(received.indexOf(f)).some((g) => g.command === 0x6506)
    );
    const tail = received.slice(commitStart);
    const pushCommands = tail.filter((f) => f.direction === 0x10).map((f) => f.command);
    assert.deepEqual(
      pushCommands.slice(-6), COMMIT_BROADCAST_ORDER,
      'the six commit pushes, in the reference order'
    );
    const tellIndex = tail.findIndex((f) => f.direction === 0x02 && f.command === 0x6504);
    const lastPushIndex = tail.length - 1 - [...tail].reverse().findIndex(
      (f) => f.direction === 0x10
    );
    assert.ok(lastPushIndex < tellIndex, 'every push precedes the 0x6504 TELL');
    // SLOTNAME's inverted order (PacketHandler.java:1256-1257): its TELL is
    // queued BEFORE broadcastSlotTitle, so on the wire the 0x6609 TELL must
    // precede the 0x6402 SLOTTITLE push.
    const slotNameTell = received.findIndex(
      (f) => f.direction === 0x02 && f.command === 0x6609
    );
    const slotTitlePush = received.findIndex(
      (f) => f.direction === 0x10 && f.command === 0x6402
    );
    assert.ok(slotNameTell !== -1 && slotTitlePush !== -1, 'both SLOTNAME frames arrived');
    assert.ok(slotNameTell < slotTitlePush, 'the SLOTNAME TELL precedes SLOTTITLE');
    assert.equal(roomLifecycle.statusOf(SLOT_NUMBER), ROOM_STATUS.GAMESET);
  } finally {
    socket.destroy();
    await new Promise((resolve) => service.close(resolve));
  }
});
