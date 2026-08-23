import assert from 'node:assert/strict';
import test from 'node:test';

import {
  Tcp10127ProtocolError,
  decodeTcp10127Frame
} from '../src/protocol/tcp10127-codec.js';
import { encodeSnapField } from '../src/protocol/snap-field-codec.js';
import {
  TCP10127_LOBBY_BUTTONS,
  Tcp10127LobbyButtonsDialogue
} from '../src/tcp/lobby-buttons-dialogue.js';
import {
  TCP10127_LOBBY_INITIALIZATION_STATE,
  Tcp10127LobbyInitializationSession
} from '../src/tcp/lobby-initialization-session.js';
import { createV1ObservedAreaTable } from '../src/state/area-table-v1.js';
import { AREA_TABLE_TRANSFER } from '../src/state/area-table.js';

/**
 * THE LOBBY-BUTTON QUERIES (SNAP_LOBBY_BUTTONS) - RANKINGS 0x6145,
 * GETINFO 0x6801, BUDDYLIST 0x6707, CHECKBUDDY 0x6703, per the bioserver
 * reference (`bioserv2/bioserver/PacketHandler.java`: sendRankings,
 * sendGetInfo, sendBuddyList, sendCheckBuddy).
 *
 * EVIDENCE STATUS: WIRE-UNOBSERVED. The RS1 TCP inventory
 * (`docs/design/v2-port/RS1-TCP-INVENTORY.md`) shows the session in which the
 * ranking/service buttons were pressed produced NO such TCP query - its
 * unanswered set is empty. Every request frame below is REFERENCE-DERIVED
 * SYNTHETIC in the captured 8-byte framing, sequences 0x40..0x4f, outside
 * every captured run so they cannot be mistaken for capture.
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

function encodedString(text, sequence) {
  return encodeSnapField({
    plain: Buffer.from(text, 'latin1'),
    maximumDecodedLength: 0xff,
    sequence,
    unknownCodecByte: CODEC_BYTE
  });
}

function handleOne(dialogue, step) {
  const result = dialogue.handleFrame(decodeTcp10127Frame(frame(step)));
  return { result, reply: decodeTcp10127Frame(result.response) };
}

/* ========================================================================== *
 * RANKINGS 0x6145 - the reference's empty ranking record.
 * ========================================================================== */

test('RANKINGS answers the reference empty-rankings record: selector echo + six space rows', () => {
  const dialogue = new Tcp10127LobbyButtonsDialogue();
  const { reply } = handleOne(dialogue, {
    command: 0x6145, sequence: 0x40, payload: Buffer.from([0x00, 0x05])
  });
  assert.equal(reply.direction, 0x02);
  assert.equal(reply.command, 0x6145);
  assert.equal(reply.sequence, 0x40);
  assert.equal(reply.error, 0);
  // 2 selector + 37 point/rank bytes + 6 rows of 28.
  assert.equal(reply.payload.length, 207);
  assert.deepEqual(reply.payload.subarray(0, 2), Buffer.from([0x00, 0x05]), 'selector echo');
  assert.ok(
    reply.payload.subarray(2, 39).every((byte) => byte === 0),
    'no recorded rankings: the point words are zero, not test values'
  );
  for (let row = 0; row < 6; row += 1) {
    const base = 39 + row * 28;
    assert.equal(reply.payload[base], 0, `row ${row} status 0 (empty)`);
    assert.equal(reply.payload[base + 1], 0, `row ${row} character 0`);
    assert.equal(reply.payload.readUInt16BE(base + 2), 6, `row ${row} handle length`);
    assert.ok(
      reply.payload.subarray(base + 4, base + 10).every((byte) => byte === 0x20),
      `row ${row} handle is spaces`
    );
    assert.equal(reply.payload.readUInt16BE(base + 10), 16, `row ${row} name length`);
    assert.ok(
      reply.payload.subarray(base + 12, base + 28).every((byte) => byte === 0x20),
      `row ${row} name is spaces`
    );
  }
});

/* ========================================================================== *
 * GETINFO 0x6801 - {urlLen, url, dataLen, data}, url echoed cleartext.
 * ========================================================================== */

test('GETINFO echoes the decoded URL and serves the resolved page in the reference envelope', () => {
  const pages = new Map([['lbs/05/RANKING.HTM', Buffer.from('<HTML>rank</HTML>', 'latin1')]]);
  const dialogue = new Tcp10127LobbyButtonsDialogue({
    resolveInfoPage: (url) => pages.get(url) ?? null
  });
  const url = 'lbs/05/RANKING.HTM';
  const { reply } = handleOne(dialogue, {
    command: 0x6801, sequence: 0x41, payload: encodedString(url, 0x41)
  });
  assert.equal(reply.error, 0);
  const urlLength = reply.payload.readUInt16BE(0);
  assert.equal(urlLength, url.length);
  assert.equal(
    reply.payload.subarray(2, 2 + urlLength).toString('latin1'), url,
    'the URL is echoed DECODED and cleartext, as the reference echoes its decrypted copy'
  );
  const dataLength = reply.payload.readUInt16BE(2 + urlLength);
  assert.deepEqual(
    reply.payload.subarray(4 + urlLength, 4 + urlLength + dataLength),
    pages.get(url)
  );
  assert.equal(reply.payload.length, 4 + urlLength + dataLength, 'nothing after the data');
});

test('GETINFO without a page store serves the built-in fallback, like the reference file-miss', () => {
  const dialogue = new Tcp10127LobbyButtonsDialogue();
  const { reply } = handleOne(dialogue, {
    command: 0x6801, sequence: 0x42, payload: encodedString('INFOR00.HTM', 0x42)
  });
  const urlLength = reply.payload.readUInt16BE(0);
  const dataLength = reply.payload.readUInt16BE(2 + urlLength);
  assert.ok(dataLength > 0, 'a page is always served');
  const page = reply.payload.subarray(4 + urlLength).toString('latin1');
  assert.ok(page.startsWith('<HTML>'), 'the fallback is an HTML document');
});

/* ========================================================================== *
 * BUDDYLIST 0x6707 - the three getClientStatus branches.
 * ========================================================================== */

function statusDialogue(statusByHandle) {
  return new Tcp10127LobbyButtonsDialogue({
    resolveBuddyStatus: (handle) => statusByHandle.get(handle.toString('latin1')) ?? 0
  });
}

test('BUDDYLIST: online 7 zero bytes, in-game trailing 1, offline markup + error status', () => {
  const dialogue = statusDialogue(new Map([['ALICE1', 1], ['BOB001', 3]]));

  const online = handleOne(dialogue, {
    command: 0x6707, sequence: 0x43, payload: encodedString('ALICE1', 0x43)
  }).reply;
  assert.equal(online.error, 0);
  assert.deepEqual(online.payload, Buffer.from([0, 0, 0, 0, 0, 0, 0]));

  const ingame = handleOne(dialogue, {
    command: 0x6707, sequence: 0x44, payload: encodedString('BOB001', 0x44)
  }).reply;
  assert.equal(ingame.error, 0);
  assert.deepEqual(ingame.payload, Buffer.from([0, 0, 0, 0, 0, 0, 1]));

  const offline = handleOne(dialogue, {
    command: 0x6707, sequence: 0x45, payload: encodedString('NOBODY', 0x45)
  }).reply;
  // The reference sets the packet error flag on the offline branch; the PAL
  // status byte convention for a non-normal TELL is 0xFF (the RS1-observed
  // 0x6211/0x6212/0x6213 default-branch replies). Removing the error status
  // is the break-the-fix mutation this assertion exists for.
  assert.equal(offline.error, TCP10127_LOBBY_BUTTONS.errorStatus);
  const textLength = offline.payload.readUInt16BE(0);
  assert.equal(
    offline.payload.subarray(2, 2 + textLength).toString('latin1'),
    '<BODY><SIZE=3>not connected<END>'
  );
});

test('BUDDYLIST without a resolver answers offline: nobody can be found, so nobody is claimed found', () => {
  const dialogue = new Tcp10127LobbyButtonsDialogue();
  const { reply } = handleOne(dialogue, {
    command: 0x6707, sequence: 0x46, payload: encodedString('ALICE1', 0x46)
  });
  assert.equal(reply.error, TCP10127_LOBBY_BUTTONS.errorStatus);
});

test('a raw (non-field-encoded) handle payload is accepted raw - the self-validating fallback', () => {
  const seen = [];
  const dialogue = new Tcp10127LobbyButtonsDialogue({
    resolveBuddyStatus: (handle) => (seen.push(handle.toString('latin1')), 1)
  });
  const { reply } = handleOne(dialogue, {
    command: 0x6707, sequence: 0x47, payload: Buffer.from('ALICE1', 'latin1')
  });
  assert.equal(reply.error, 0);
  assert.deepEqual(seen, ['ALICE1']);
});

test('a resolver outside the getClientStatus domain {0,1,3} is refused by name', () => {
  const dialogue = new Tcp10127LobbyButtonsDialogue({ resolveBuddyStatus: () => 2 });
  assert.throws(
    () => dialogue.handleFrame(decodeTcp10127Frame(frame({
      command: 0x6707, sequence: 0x48, payload: encodedString('ALICE1', 0x48)
    }))),
    (error) => error instanceof Tcp10127ProtocolError &&
      error.code === 'LOBBY_BUTTONS_STATUS_DOMAIN'
  );
});

/* ========================================================================== *
 * CHECKBUDDY 0x6703 - structured online record; err on in-game and offline.
 * ========================================================================== */

test('CHECKBUDDY online: handle + the reference status words + markup, error clear', () => {
  const dialogue = statusDialogue(new Map([['ALICE1', 1]]));
  const { reply } = handleOne(dialogue, {
    command: 0x6703, sequence: 0x49, payload: encodedString('ALICE1', 0x49)
  });
  assert.equal(reply.error, 0);
  const handleLength = reply.payload.readUInt16BE(0);
  assert.equal(handleLength, 6);
  assert.equal(reply.payload.subarray(2, 8).toString('latin1'), 'ALICE1');
  // The four status words the reference online record carries.
  assert.equal(reply.payload.readUInt16BE(8), 0x0001);
  assert.equal(reply.payload.readUInt16BE(10), 0x0000);
  assert.equal(reply.payload.readUInt16BE(12), 0x0000);
  assert.equal(reply.payload.readUInt16BE(14), 0x0003);
  const markupLength = reply.payload.readUInt16BE(16);
  assert.equal(
    reply.payload.subarray(18, 18 + markupLength).toString('latin1'),
    '<BODY><SIZE=3>online<END>'
  );
});

test('CHECKBUDDY in-game and offline answer markup with the error status, as the reference setErr does', () => {
  const dialogue = statusDialogue(new Map([['BOB001', 3]]));
  const ingame = handleOne(dialogue, {
    command: 0x6703, sequence: 0x4a, payload: encodedString('BOB001', 0x4a)
  }).reply;
  assert.equal(ingame.error, TCP10127_LOBBY_BUTTONS.errorStatus);
  const offline = handleOne(dialogue, {
    command: 0x6703, sequence: 0x4b, payload: encodedString('NOBODY', 0x4b)
  }).reply;
  assert.equal(offline.error, TCP10127_LOBBY_BUTTONS.errorStatus);
  const textLength = offline.payload.readUInt16BE(0);
  assert.equal(
    offline.payload.subarray(2, 2 + textLength).toString('latin1'),
    '<BODY><SIZE=3><CENTER>not connected<END>'
  );
});

/* ========================================================================== *
 * Session-level: reachable only after the completed ladder; without the
 * dialogue the frames keep the observed-not-answered behaviour (the flag-off /
 * pre-change bytes - the control).
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

function buttonSteps() {
  return [
    { name: 'RANKINGS', command: 0x6145, sequence: 0x4c, payload: Buffer.from([0x00, 0x01]) },
    { name: 'GETINFO', command: 0x6801, sequence: 0x4d, payload: encodedString('INFOR00.HTM', 0x4d) },
    { name: 'BUDDYLIST', command: 0x6707, sequence: 0x4e, payload: encodedString('ALICE1', 0x4e) },
    { name: 'CHECKBUDDY', command: 0x6703, sequence: 0x4f, payload: encodedString('ALICE1', 0x4f) }
  ];
}

test('after the completed ladder every button query is answered same-cmd same-seq', () => {
  const session = new Tcp10127LobbyInitializationSession({
    areaTable: AREA_TABLE,
    ...ladderProviders(),
    lobbyButtonsDialogue: statusDialogue(new Map([['ALICE1', 1]]))
  });
  walkLadderToComplete(session);
  for (const step of buttonSteps()) {
    const result = session.handleFrame(decodeTcp10127Frame(frame(step)));
    assert.equal(result.unimplemented, false, `${step.name} must be ANSWERED, not observed`);
    const reply = decodeTcp10127Frame(result.response);
    assert.equal(reply.direction, 0x02, `${step.name} reply direction`);
    assert.equal(reply.command, step.command, `${step.name} reply command`);
    assert.equal(reply.sequence, step.sequence, `${step.name} reply sequence`);
  }
});

test('without the dialogue the same frames keep the observed-not-answered behaviour', () => {
  // THE CONTROL: the flag-off / pre-change bytes. If the dialogue were wired
  // unconditionally, this is the test that breaks.
  const session = new Tcp10127LobbyInitializationSession({
    areaTable: AREA_TABLE,
    ...ladderProviders()
  });
  walkLadderToComplete(session);
  for (const step of buttonSteps()) {
    const result = session.handleFrame(decodeTcp10127Frame(frame(step)));
    assert.equal(result.unimplemented, true, `${step.name} must stay observed without the flag`);
    assert.equal(result.response, null);
  }
});

test('the dialogue is NOT reachable before the ladder completes', () => {
  const session = new Tcp10127LobbyInitializationSession({
    areaTable: AREA_TABLE,
    ...ladderProviders(),
    lobbyButtonsDialogue: new Tcp10127LobbyButtonsDialogue()
  });
  assert.throws(
    () => session.handleFrame(decodeTcp10127Frame(frame({
      command: 0x6145, sequence: 0x40, payload: Buffer.from([0x00, 0x01])
    }))),
    (error) => error instanceof Tcp10127ProtocolError && error.code === 'LOBBY_INIT_COMMAND'
  );
});

test('the two post-completion dialogues claim disjoint command sets', async () => {
  // The session consults create-config first; if a command ever appeared in
  // both sets, which dialogue answers would depend on consult order. Pin the
  // disjointness so a future command addition cannot silently collide.
  const { TCP10127_CREATE_CONFIG } = await import('../src/tcp/create-config-dialogue.js');
  const createCommands = [
    TCP10127_CREATE_CONFIG.commandCreateSlot, TCP10127_CREATE_CONFIG.commandSceneSelect,
    TCP10127_CREATE_CONFIG.commandSlotName, TCP10127_CREATE_CONFIG.commandSlotPassword,
    TCP10127_CREATE_CONFIG.commandSetRule, TCP10127_CREATE_CONFIG.commandUnknown660c,
    TCP10127_CREATE_CONFIG.commandCharSelect, TCP10127_CREATE_CONFIG.commandCreateCommit
  ];
  const buttons = new Tcp10127LobbyButtonsDialogue();
  for (const command of createCommands) {
    assert.equal(buttons.handles(command), false, `0x${command.toString(16)} collides`);
  }
});
