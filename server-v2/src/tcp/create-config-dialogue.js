import {
  TCP10127_DIRECTION,
  Tcp10127ProtocolError,
  encodeTcp10127Frame
} from '../protocol/tcp10127-codec.js';
import { decodeSnapField } from '../protocol/snap-field-codec.js';
import { ROOM_STATUS } from '../state/room-lifecycle.js';

/**
 * THE CREATE-CONFIG DIALOGUE (BIOSERVER-CONTRACT §6, create-dialogue rows).
 *
 * WHY: every rule row renders red, the scenario is locked and the cast is
 * locked, because the host's config picks are never acknowledged. The client's
 * receivers are live - `0x6ff2b1` is set to 1 by the op-04 create accept
 * (G12-config-unlock-RE-2026-07-17 §b) - what is missing is a SERVER answering
 * each config query. This module answers them per the contract rows:
 *
 *   CREATESLOT 0x6407 -> SCENESELECT 0x6509 -> SLOTNAME 0x6609 ->
 *   [SLOTPASSWD 0x660A] -> SETRULE 0x660B xN -> UNKN660C 0x660C ->
 *   CHARSELECT 0x6190 -> UNKN6504 0x6504, and ONLY the 0x6504 commit flips the
 *   room INCREATE -> GAMESET and fires the six-broadcast state set + PLAYEROK.
 *
 * EVIDENCE STATUS - WIRE-UNOBSERVED, stated loudly and precisely: the RS1
 * TCP-10127 inventory (`docs/design/v2-port/RS1-TCP-INVENTORY.md`, capture
 * RS1-20260808-172534) parsed every TCP byte of ONE session in which rooms
 * WERE created, and no create-dialogue USAGE appeared in its post-completion
 * window - the create window rode UDP 9090. Two cautions on that sentence
 * (nora, 2026-08-08): 0x6504 the COMMAND is on TCP in every session - as the
 * ladder's record-batch request, answered in the AWAITING states - so what is
 * unobserved is the post-completion create-commit usage, not the byte pair;
 * and one inventoried session is absence of evidence, not proof the client
 * can never send these (corpus methodology: a sweep is discovery, not proof
 * of absence). So there is no captured TELL to reproduce byte-for-byte. Everything here is the
 * BIOSERVER-CONTRACT row translated into the PAL 8-byte framing the same
 * capture grounded ({len BE16, dir, cmd BE16, seq, err, 0xFF}), with TELLs
 * echoing the request sequence exactly as all 186 observed TELLs do. If the
 * client ever does send these on TCP, this module answers; until then it
 * changes nothing on any rig-confirmed path, because frames that never arrive
 * are never answered (they previously fell into the observed-not-answered
 * branch of the completed-ladder state).
 *
 * STATE goes through the existing engine modules and NOWHERE else:
 * - `state/room-lifecycle.js`: INCREATE at create, GAMESET only at the 0x6504
 *   commit (completeCreate), scene/password/wait-timer fields.
 * - `state/rule-set.js`: SETRULE values via the record's own rule set.
 * - `state/player-profile.js`: CHARSELECT 0xD0 blob, store-and-echo.
 *
 * BROADCAST DELIVERY: frames for the requester (the host is inside the
 * audience of every contract broadcast) are RETURNED and written to its own
 * socket by the service, in the reference's PER-ROW order: CREATESLOT and the
 * 0x6504 commit emit broadcasts BEFORE the TELL (`sendCreateSlot`,
 * `send6504`), but SLOTNAME queues its TELL FIRST and only then
 * `broadcastSlotTitle` (`PacketHandler.java:1256-1257`) - so results carry
 * `broadcasts` (pre-TELL) and `broadcastsAfterTell` (post-TELL) and the
 * service writes them on the matching side of the response. Fan-out to OTHER
 * members goes through the injected `broadcast(scope, deliver)` seam (the
 * SnapLobbySessions fan-out signature); a session that exposes
 * `deliverCreateConfigPush` gets the frame, and today none does - the join
 * path rides UDP - so the delivered count is 0 and is logged as such rather
 * than invented.
 */

export const TCP10127_CREATE_CONFIG = Object.freeze({
  // The contract rows (BIOSERVER-CONTRACT §6 create table).
  commandCreateSlot: 0x6407,
  commandSceneSelect: 0x6509,
  commandSlotName: 0x6609,
  commandSlotPassword: 0x660a,
  commandSetRule: 0x660b,
  commandUnknown660c: 0x660c,
  commandCharSelect: 0x6190,
  commandCreateCommit: 0x6504,
  // The broadcast set those rows fire.
  broadcastSlotTitle: 0x6402,
  broadcastSlotPlayerStatus: 0x6403,
  broadcastSlotStatus: 0x6404,
  broadcastSlotPasswordProtection: 0x6405,
  broadcastSlotAttrib2: 0x640b,
  broadcastPlayerOk: 0x6506,
  broadcastSlotSceneType: 0x650a,
  // SLES_533.19's one request builder writes 0xff at header byte 7; all 186
  // observed queries carry it, so these unobserved ones are required to too.
  requestUnknown7: 0xff,
  // Bounds. Title/password ride the client's one field codec (FUN_001c3f40) on
  // this transport; 0xff matches the reference's PacketString ceiling. The
  // character blob is bounded like `player-profile.js` bounds it: the observed
  // 0xD0 and the noted 0xF0 variant both fit far below 0x200.
  maximumTitleLength: 0xff,
  maximumPasswordLength: 0xff,
  maximumCharacterStatsLength: 0x200
});

const HANDLED_COMMANDS = new Set([
  TCP10127_CREATE_CONFIG.commandCreateSlot,
  TCP10127_CREATE_CONFIG.commandSceneSelect,
  TCP10127_CREATE_CONFIG.commandSlotName,
  TCP10127_CREATE_CONFIG.commandSlotPassword,
  TCP10127_CREATE_CONFIG.commandSetRule,
  TCP10127_CREATE_CONFIG.commandUnknown660c,
  TCP10127_CREATE_CONFIG.commandCharSelect,
  TCP10127_CREATE_CONFIG.commandCreateCommit
]);

function requireFrameInvariant(condition, code, message) {
  if (!condition) throw new Tcp10127ProtocolError(code, message);
}

export class Tcp10127CreateConfigDialogue {
  #roomLifecycle;
  #resolveProfile;
  #resolveRoomHandle;
  #resolveAreaNumber;
  #countMembers;
  #broadcast;
  #onSlotTitle;
  #now;
  #codecByte;
  #logger;
  /** The room this dialogue is configuring, captured at CREATESLOT. */
  #roomHandle = null;
  /** True when THIS dialogue ran the CREATESLOT row (profile may be absent). */
  #createdHere = false;
  /** The slot title, held for the SLOTTITLE broadcast (no engine home yet). */
  #title = Buffer.alloc(0);
  /**
   * Server-initiated frames use the server's own incrementing counter
   * (BIOSERVER-CONTRACT §1); starts past the challenge's fixed 0x01.
   */
  #pushSequence = 0x02;

  constructor({
    roomLifecycle,
    resolveProfile = null,
    resolveRoomHandle = null,
    resolveAreaNumber = null,
    countMembers = null,
    broadcast = null,
    onSlotTitle = null,
    now = null,
    codecByte = 0,
    logger = () => {}
  } = {}) {
    if (roomLifecycle == null || typeof roomLifecycle.beginCreate !== 'function' ||
        typeof roomLifecycle.completeCreate !== 'function') {
      throw new TypeError('roomLifecycle must be the RoomLifecycleRegistry');
    }
    for (const [name, value] of [
      ['resolveProfile', resolveProfile],
      ['resolveRoomHandle', resolveRoomHandle],
      ['resolveAreaNumber', resolveAreaNumber],
      ['countMembers', countMembers],
      ['broadcast', broadcast],
      ['onSlotTitle', onSlotTitle],
      ['now', now]
    ]) {
      if (value != null && typeof value !== 'function') {
        throw new TypeError(`${name} must be a function when provided`);
      }
    }
    if (!Number.isSafeInteger(codecByte) || codecByte < 0 || codecByte > 0xff) {
      throw new TypeError('codecByte must be an unsigned byte');
    }
    this.#roomLifecycle = roomLifecycle;
    this.#resolveProfile = resolveProfile;
    this.#resolveRoomHandle = resolveRoomHandle;
    this.#resolveAreaNumber = resolveAreaNumber;
    this.#countMembers = countMembers;
    this.#broadcast = broadcast;
    this.#onSlotTitle = onSlotTitle;
    this.#now = now ?? (() => 0);
    this.#codecByte = codecByte;
    this.#logger = logger;
  }

  /** Which commands this dialogue answers; everything else stays observed. */
  handles(command) {
    return HANDLED_COMMANDS.has(command);
  }

  get roomHandle() {
    return this.#roomHandle;
  }

  handleFrame(frame) {
    requireFrameInvariant(
      frame.direction === TCP10127_DIRECTION.CLIENT_REQUEST,
      'CREATE_CONFIG_DIRECTION',
      'a create-config frame must be a client request'
    );
    requireFrameInvariant(
      frame.error === 0,
      'CREATE_CONFIG_STATUS',
      'only the normal-status create-config path is implemented'
    );
    requireFrameInvariant(
      frame.unknown7 === TCP10127_CREATE_CONFIG.requestUnknown7,
      'CREATE_CONFIG_UNKNOWN7',
      'SLES_533.19 request builder writes 0xff at header byte 7'
    );
    switch (frame.command) {
      case TCP10127_CREATE_CONFIG.commandCreateSlot:
        return this.#handleCreateSlot(frame);
      case TCP10127_CREATE_CONFIG.commandSceneSelect:
        return this.#handleSceneSelect(frame);
      case TCP10127_CREATE_CONFIG.commandSlotName:
        return this.#handleSlotName(frame);
      case TCP10127_CREATE_CONFIG.commandSlotPassword:
        return this.#handleSlotPassword(frame);
      case TCP10127_CREATE_CONFIG.commandSetRule:
        return this.#handleSetRule(frame);
      case TCP10127_CREATE_CONFIG.commandUnknown660c:
        return this.#handleUnknown660c(frame);
      case TCP10127_CREATE_CONFIG.commandCharSelect:
        return this.#handleCharSelect(frame);
      case TCP10127_CREATE_CONFIG.commandCreateCommit:
        return this.#handleCreateCommit(frame);
      default:
        throw new Tcp10127ProtocolError(
          'CREATE_CONFIG_COMMAND',
          `command 0x${frame.command.toString(16)} is not a create-config row`
        );
    }
  }

  /**
   * CREATESLOT 0x6407 (contract row 1): payload is the slot number BE16
   * (`getNumber()` reads the first two payload bytes). `client.slot = nr`,
   * hostflag = 1, playernum = 1, status -> INCREATE; SLOTPLRSTATUS +
   * SLOTSTATUS broadcasts; TELL `{0, slot}`.
   *
   * ROOM-HANDLE RESOLUTION, because the engine's room handles are minted and
   * the wire slot number is not one of them: when the connection's player is
   * ALREADY in a room (the UDP op-04 create accept put the host there, which
   * is the flow the gate model describes), that room IS the slot being
   * configured and its lifecycle record - begun by the UDP create - is reused.
   * Only a connection with no current room falls back to the wire slot number
   * as the handle, which is the pure-TCP flow the contract describes. A
   * collision with a minted handle fails loudly (LIFECYCLE_DUPLICATE), never
   * silently.
   */
  #handleCreateSlot(frame) {
    requireFrameInvariant(
      frame.payloadLength >= 2,
      'CREATE_SLOT_LENGTH',
      'CREATESLOT carries the slot number in its first two payload bytes'
    );
    const slotNumber = frame.payload.readUInt16BE(0);
    const currentRoom = this.#resolveOptional(this.#resolveRoomHandle, 'resolveRoomHandle');
    const handle = currentRoom ?? slotNumber;
    requireFrameInvariant(
      Number.isSafeInteger(handle) && handle >= 1,
      'CREATE_SLOT_NUMBER',
      `CREATESLOT slot number ${slotNumber} cannot name a room`
    );
    const existing = this.#roomLifecycle.get(handle);
    if (existing == null) {
      const areaNumber = this.#resolveOptional(this.#resolveAreaNumber, 'resolveAreaNumber') ?? 0;
      this.#wrapEngine('CREATE_SLOT', () =>
        this.#roomLifecycle.beginCreate(handle, { areaNumber }));
    } else {
      // The UDP op-04 create accept already began this record; the TCP row
      // attaches to it. Anything but INCREATE is a protocol violation.
      requireFrameInvariant(
        existing.status === ROOM_STATUS.INCREATE,
        'CREATE_SLOT_STATE',
        `CREATESLOT for room 0x${handle.toString(16)} in status ${existing.status}; ` +
          'only an in-create room can be configured'
      );
    }
    this.#roomHandle = handle;
    this.#createdHere = true;
    const profile = this.#resolveOptional(this.#resolveProfile, 'resolveProfile');
    if (profile != null) {
      this.#wrapEngine('CREATE_SLOT_PROFILE', () => {
        profile.setHostFlag(1);
        profile.setPlayerNum(1);
      });
    }
    const broadcasts = this.#emitBroadcasts(handle, [
      this.#buildSlotPlayerStatus(handle, slotNumber),
      this.#buildSlotStatus(handle, slotNumber)
    ]);
    const payload = Buffer.alloc(2);
    payload.writeUInt16BE(slotNumber, 0);
    return this.#result(frame, payload, broadcasts);
  }

  /**
   * SCENESELECT 0x6509 (row 2): `{0,type, 0,scenario}` in, stores slotType +
   * scenario and arms the wait timer; TELL `{0,slot, 0,type, 0,scenario}`.
   */
  #handleSceneSelect(frame) {
    requireFrameInvariant(
      frame.payloadLength >= 4,
      'SCENE_SELECT_LENGTH',
      'SCENESELECT carries two BE16 words: slot type and scenario'
    );
    const { handle, slotNumber } = this.#requireRoom('SCENE_SELECT');
    const slotType = frame.payload.readUInt16BE(0);
    const scenario = frame.payload.readUInt16BE(2);
    this.#wrapEngine('SCENE_SELECT', () => {
      this.#roomLifecycle.setScene(handle, { slotType, scenario });
      this.#roomLifecycle.armWaitTimer(handle, { nowMs: this.#now() });
    });
    const payload = Buffer.alloc(6);
    payload.writeUInt16BE(slotNumber, 0);
    payload.writeUInt16BE(slotType, 2);
    payload.writeUInt16BE(scenario, 4);
    return this.#result(frame, payload, []);
  }

  /**
   * SLOTNAME 0x6609 (row 3): the title as the client's one encoded field
   * (FUN_001c3f40; the JP transport's pid-XOR string is the OTHER transport's
   * codec). TELL empty; SLOTTITLE broadcast to slot+room, cleartext
   * `{slot:2, len:2, title}` per the contract's server-string rule.
   *
   * ORDER: TELL FIRST, then the broadcast - `sendSlotName` queues the TELL
   * before calling `broadcastSlotTitle` (`PacketHandler.java:1256-1257`),
   * the one create row whose order is inverted from CREATESLOT/0x6504.
   */
  #handleSlotName(frame) {
    const { handle, slotNumber } = this.#requireRoom('SLOT_NAME');
    const title = decodeSnapField({
      field: frame.payload,
      maximumDecodedLength: TCP10127_CREATE_CONFIG.maximumTitleLength,
      sequence: frame.sequence,
      unknownCodecByte: this.#codecByte
    });
    requireFrameInvariant(
      title != null,
      'SLOT_NAME_FIELD',
      'SLOTNAME title did not decode as a FUN_001c3f40 field with this connection\'s codec byte'
    );
    this.#title = title;
    if (this.#onSlotTitle != null) {
      try {
        this.#onSlotTitle({ handle, title: Buffer.from(title) });
      } catch (error) {
        // Mirroring the title into the room record is best-effort display
        // state; a refusal there must not kill the dialogue.
        this.#logger({ type: 'create-config-title-mirror-refused', message: error.message });
      }
    }
    const broadcasts = this.#emitBroadcasts(handle, [
      this.#buildSlotTitle(slotNumber)
    ]);
    return this.#result(frame, Buffer.alloc(0), broadcasts, { afterTell: true });
  }

  /**
   * SLOTPASSWD 0x660A (row 4): password as an encoded field; non-empty flips
   * protection ON (Slot.setPassword). TELL empty.
   */
  #handleSlotPassword(frame) {
    const { handle } = this.#requireRoom('SLOT_PASSWORD');
    const password = decodeSnapField({
      field: frame.payload,
      maximumDecodedLength: TCP10127_CREATE_CONFIG.maximumPasswordLength,
      sequence: frame.sequence,
      unknownCodecByte: this.#codecByte
    });
    requireFrameInvariant(
      password != null,
      'SLOT_PASSWORD_FIELD',
      'SLOTPASSWD did not decode as a FUN_001c3f40 field with this connection\'s codec byte'
    );
    this.#wrapEngine('SLOT_PASSWORD', () =>
      this.#roomLifecycle.setPassword(handle, password));
    return this.#result(frame, Buffer.alloc(0), []);
  }

  /**
   * SETRULE 0x660B (row 5): `{rulenr:1, value:1}`; the record's own rule set
   * bounds-checks (the changeable mask is advertised, not enforced - the
   * reference applies whatever the host sent). TELL `{1}`.
   */
  #handleSetRule(frame) {
    requireFrameInvariant(
      frame.payloadLength >= 2,
      'SET_RULE_LENGTH',
      'SETRULE carries one rule-number byte and one value byte'
    );
    const { record } = this.#requireRoom('SET_RULE');
    const rulenr = frame.payload[0];
    const value = frame.payload[1];
    this.#wrapEngine('SET_RULE', () => record.rules.setRuleValue(rulenr, value));
    return this.#result(frame, Buffer.from([0x01]), []);
  }

  /** UNKN660C 0x660C (row 6): unknown even to the reference authors. TELL empty. */
  #handleUnknown660c(frame) {
    this.#requireRoom('UNKNOWN_660C');
    return this.#result(frame, Buffer.alloc(0), []);
  }

  /**
   * CHARSELECT 0x6190 (row 7 and §2 row 12): the character/stat blob,
   * store-and-echo - the server never interprets the bytes. On this transport
   * the blob would ride the client's one field codec, so a payload that
   * decodes AND checksums as a field is stored decoded; a payload that does
   * not is stored raw (both are store-and-echo; which envelope the PAL client
   * uses here is wire-unobserved, and the checksum makes the choice
   * self-validating rather than guessed). Contract: sent once before area
   * select AND again when creating/joining - so no room is required.
   */
  #handleCharSelect(frame) {
    const profile = this.#resolveOptional(this.#resolveProfile, 'resolveProfile');
    requireFrameInvariant(
      profile != null,
      'CHAR_SELECT_PROFILE',
      'CHARSELECT needs a player profile to store the character stats on'
    );
    const decoded = decodeSnapField({
      field: frame.payload,
      maximumDecodedLength: TCP10127_CREATE_CONFIG.maximumCharacterStatsLength,
      sequence: frame.sequence,
      unknownCodecByte: this.#codecByte
    });
    const blob = decoded ?? frame.payload;
    requireFrameInvariant(
      blob.length >= 1 && blob.length <= TCP10127_CREATE_CONFIG.maximumCharacterStatsLength,
      'CHAR_SELECT_LENGTH',
      `CHARSELECT blob length ${blob.length} is outside 1..` +
        `${TCP10127_CREATE_CONFIG.maximumCharacterStatsLength}`
    );
    this.#wrapEngine('CHAR_SELECT', () => profile.setCharacterStats(Buffer.from(blob)));
    this.#logger({
      type: 'create-config-charselect-stored',
      encodedField: decoded != null,
      byteLength: blob.length
    });
    return this.#result(frame, Buffer.alloc(0), []);
  }

  /**
   * UNKN6504 0x6504, THE COMMIT (row 8): "last packet from slot creator". If
   * the sender is the host of an in-create room, status -> GAMESET and the
   * wait timer arms - the ONLY transition that makes the room joinable
   * (`completeCreate`). Then the six broadcasts in the reference order -
   * SLOTPLRSTATUS, SLOTPWDPROT (room-wide), SLOTSTATUS, SLOTSCENTYPE,
   * SLOTATTRIB2, PLAYEROK (slot members only) - and finally TELL
   * `{payload[0]}`.
   *
   * A non-host 0x6504 (the joiner's readiness signal, §6 join notes) fires
   * the broadcasts and the TELL but never the flip - the discriminating
   * behaviour the engine test pins.
   *
   * NOT the lobby-initialization ladder's 0x6504: that usage lives in the
   * ladder states and is answered there; this dialogue is only reachable
   * AFTER the 0x1004 completion, where the ladder's 0x6504 cannot occur.
   */
  #handleCreateCommit(frame) {
    requireFrameInvariant(
      frame.payloadLength >= 1,
      'CREATE_COMMIT_LENGTH',
      'the create-commit 0x6504 carries at least its one payload byte'
    );
    const { handle, record, slotNumber } = this.#requireRoom('CREATE_COMMIT');
    const profile = this.#resolveOptional(this.#resolveProfile, 'resolveProfile');
    const isHost = profile != null ? profile.hostflag === 1 : this.#createdHere;
    if (isHost && record.status === ROOM_STATUS.INCREATE) {
      this.#wrapEngine('CREATE_COMMIT', () =>
        this.#roomLifecycle.completeCreate(handle, { nowMs: this.#now() }));
      this.#logger({
        type: 'create-config-gameset',
        roomHandle: handle,
        note: 'INCREATE -> GAMESET at the 0x6504 commit; the room is now joinable'
      });
    }
    const playernum = profile != null && profile.playernum > 0 ? profile.playernum : 1;
    const broadcasts = this.#emitBroadcasts(handle, [
      this.#buildSlotPlayerStatus(handle, slotNumber),
      this.#buildSlotPasswordProtection(handle, slotNumber),
      this.#buildSlotStatus(handle, slotNumber),
      this.#buildSlotSceneType(handle, slotNumber),
      this.#buildSlotAttrib2(handle, slotNumber),
      this.#buildPlayerOk(playernum)
    ]);
    return this.#result(frame, Buffer.from([frame.payload[0]]), broadcasts);
  }

  /* ---- broadcast builders (payload shapes from the contract tables) ------ */

  /** SLOTPLRSTATUS 0x6403: `{slot:2, 0,cur, 0,0, 0,max, 0,cur}` (§5). */
  #buildSlotPlayerStatus(handle, slotNumber) {
    const record = this.#roomLifecycle.get(handle);
    const current = this.#memberCount(handle);
    const maximum = record != null ? record.rules.numberOfPlayers() : 4;
    const payload = Buffer.alloc(10);
    payload.writeUInt16BE(slotNumber, 0);
    payload.writeUInt16BE(current, 2);
    payload.writeUInt16BE(0, 4);
    payload.writeUInt16BE(maximum, 6);
    payload.writeUInt16BE(current, 8);
    return { command: TCP10127_CREATE_CONFIG.broadcastSlotPlayerStatus, payload };
  }

  /** SLOTSTATUS 0x6404: `{slot:2, status:1}`. */
  #buildSlotStatus(handle, slotNumber) {
    const payload = Buffer.alloc(3);
    payload.writeUInt16BE(slotNumber, 0);
    payload[2] = this.#roomLifecycle.statusOf(handle);
    return { command: TCP10127_CREATE_CONFIG.broadcastSlotStatus, payload };
  }

  /** SLOTTITLE 0x6402: `{slot:2, len:2, title}`, server strings cleartext. */
  #buildSlotTitle(slotNumber) {
    const payload = Buffer.alloc(4 + this.#title.length);
    payload.writeUInt16BE(slotNumber, 0);
    payload.writeUInt16BE(this.#title.length, 2);
    this.#title.copy(payload, 4);
    return { command: TCP10127_CREATE_CONFIG.broadcastSlotTitle, payload };
  }

  /** SLOTPWDPROT 0x6405: `{slot:2, protection:1}`. */
  #buildSlotPasswordProtection(handle, slotNumber) {
    const record = this.#roomLifecycle.get(handle);
    const payload = Buffer.alloc(3);
    payload.writeUInt16BE(slotNumber, 0);
    payload[2] = record != null ? record.protection : 0;
    return { command: TCP10127_CREATE_CONFIG.broadcastSlotPasswordProtection, payload };
  }

  /** SLOTSCENTYPE 0x650A: `{slot:2, 0,slotType, 0,scenario}`. */
  #buildSlotSceneType(handle, slotNumber) {
    const record = this.#roomLifecycle.get(handle);
    const payload = Buffer.alloc(6);
    payload.writeUInt16BE(slotNumber, 0);
    payload.writeUInt16BE(record != null ? record.slotType : 0, 2);
    payload.writeUInt16BE(record != null ? record.scenario : 0, 4);
    return { command: TCP10127_CREATE_CONFIG.broadcastSlotSceneType, payload };
  }

  /**
   * SLOTATTRIB2 0x640B: `{slot:2, 0,max, 0,4, 0,1, 0,4, 0,1}` - the trailing
   * four words are the reference's own unexplained constants (flagged TODO in
   * its source), reproduced as-is.
   */
  #buildSlotAttrib2(handle, slotNumber) {
    const record = this.#roomLifecycle.get(handle);
    const payload = Buffer.alloc(12);
    payload.writeUInt16BE(slotNumber, 0);
    payload.writeUInt16BE(record != null ? record.rules.numberOfPlayers() : 4, 2);
    payload.writeUInt16BE(4, 4);
    payload.writeUInt16BE(1, 6);
    payload.writeUInt16BE(4, 8);
    payload.writeUInt16BE(1, 10);
    return { command: TCP10127_CREATE_CONFIG.broadcastSlotAttrib2, payload };
  }

  /** PLAYEROK 0x6506: `{0,playernum, 0,0}`, slot members only. */
  #buildPlayerOk(playernum) {
    const payload = Buffer.alloc(4);
    payload.writeUInt16BE(playernum, 0);
    payload.writeUInt16BE(0, 2);
    return { command: TCP10127_CREATE_CONFIG.broadcastPlayerOk, payload };
  }

  /* ---- internals --------------------------------------------------------- */

  /**
   * Encode one broadcast set: the requester's own copies (returned, written
   * before the TELL) plus the fan-out to other members through the injected
   * seam. Scope is the room handle - a presence fact, never wire bytes.
   */
  #emitBroadcasts(handle, descriptors) {
    const frames = descriptors.map(({ command, payload }) => encodeTcp10127Frame({
      direction: TCP10127_DIRECTION.SERVER_PUSH,
      command,
      sequence: this.#nextPushSequence(),
      error: 0,
      unknown7: 0,
      payload
    }));
    if (this.#broadcast != null) {
      let delivered = 0;
      try {
        delivered = this.#broadcast({ roomHandle: handle }, (session) => {
          let taken = false;
          for (let index = 0; index < descriptors.length; index += 1) {
            if (session.deliverCreateConfigPush?.({
              command: descriptors[index].command,
              payload: Buffer.from(descriptors[index].payload),
              frame: Buffer.from(frames[index])
            }) === true) taken = true;
          }
          return taken;
        }) ?? 0;
      } catch (error) {
        // Fan-out is best-effort by design here: the TELL to the requester is
        // the contract-critical byte stream and must not die with a peer.
        this.#logger({ type: 'create-config-broadcast-failed', message: error.message });
      }
      this.#logger({
        type: 'create-config-broadcast',
        roomHandle: handle,
        commands: descriptors.map(({ command }) => `0x${command.toString(16)}`),
        deliveredToOthers: delivered
      });
    }
    return frames;
  }

  #nextPushSequence() {
    const sequence = this.#pushSequence;
    this.#pushSequence = (this.#pushSequence + 1) & 0xff;
    return sequence;
  }

  #memberCount(handle) {
    if (this.#countMembers == null) return 1;
    const count = this.#wrapEngine('MEMBER_COUNT', () => this.#countMembers(handle));
    return Number.isSafeInteger(count) && count >= 1 ? count : 1;
  }

  /**
   * The room every post-CREATESLOT row targets. The rows after row 1 carry no
   * slot number, so the context is the CREATESLOT capture, falling back to the
   * connection's current room (the UDP-created one) when the dialogue never
   * saw a CREATESLOT on this connection.
   */
  #requireRoom(codePrefix) {
    let handle = this.#roomHandle;
    if (handle == null) {
      handle = this.#resolveOptional(this.#resolveRoomHandle, 'resolveRoomHandle');
      if (handle != null) this.#roomHandle = handle;
    }
    requireFrameInvariant(
      handle != null,
      `${codePrefix}_NO_ROOM`,
      'no room is being configured on this connection: no CREATESLOT was seen and the ' +
        'player is in no room'
    );
    const record = this.#roomLifecycle.get(handle);
    requireFrameInvariant(
      record != null,
      `${codePrefix}_NO_LIFECYCLE`,
      `room 0x${handle.toString(16)} has no lifecycle record`
    );
    /*
     * The wire slot number for broadcast payloads is a BE16 contract field.
     * A UDP-minted handle above 0xffff cannot ride it: a masked value would
     * name a DIFFERENT slot on every receiving client, which is a silent
     * cross-room corruption, not a display blemish. No minted handle has ever
     * exceeded 0xffff (they are small integers from the room registry), so
     * this refusal is unreachable today - it exists so growth in the handle
     * space fails LOUDLY here rather than truncating quietly.
     */
    requireFrameInvariant(
      handle <= 0xffff,
      `${codePrefix}_HANDLE_WIDTH`,
      `room handle 0x${handle.toString(16)} exceeds the BE16 slot-number field; ` +
        'masking it would address a different slot'
    );
    return { handle, record, slotNumber: handle };
  }

  #resolveOptional(resolver, name) {
    if (resolver == null) return null;
    try {
      return resolver();
    } catch (error) {
      throw new Tcp10127ProtocolError(
        'CREATE_CONFIG_RESOLVER',
        `${name} failed: ${error.message}`
      );
    }
  }

  /** Engine refusals become named protocol errors, never silent papering. */
  #wrapEngine(codePrefix, operation) {
    try {
      return operation();
    } catch (error) {
      throw new Tcp10127ProtocolError(
        error.code ?? `${codePrefix}_ENGINE`,
        `${codePrefix.toLowerCase().replace(/_/g, '-')} refused by the engine: ${error.message}`
      );
    }
  }

  /**
   * TELL: same command, same sequence, err 0 - the shape of all 186 observed
   * TELLs. `afterTell` moves the row's broadcasts to the post-TELL side of
   * the write order (only SLOTNAME - the reference's one inverted row).
   */
  #result(frame, payload, broadcasts, { afterTell = false } = {}) {
    const response = encodeTcp10127Frame({
      direction: TCP10127_DIRECTION.SERVER_RESPONSE,
      command: frame.command,
      sequence: frame.sequence,
      error: 0,
      unknown7: frame.unknown7,
      payload
    });
    return {
      response,
      broadcasts: afterTell ? [] : broadcasts,
      broadcastsAfterTell: afterTell ? broadcasts : [],
      state: 'create-config-dialogue',
      unimplemented: false,
      request: {
        command: frame.command,
        sequence: frame.sequence,
        unknown7: frame.unknown7,
        unknownPayload: Buffer.from(frame.payload)
      }
    };
  }
}
