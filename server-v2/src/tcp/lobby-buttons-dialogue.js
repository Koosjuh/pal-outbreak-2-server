import {
  TCP10127_DIRECTION,
  Tcp10127ProtocolError,
  encodeTcp10127Frame
} from '../protocol/tcp10127-codec.js';
import { decodeSnapField } from '../protocol/snap-field-codec.js';

/**
 * THE LOBBY-BUTTON QUERIES (G6/G7): RANKINGS, GETINFO, BUDDYLIST, CHECKBUDDY,
 * answered per the JP reference server's reply construction.
 *
 * WHY: the owner's RIG-SESSION-1 results (R1): "View the service or national
 * ranking button doesnt work" - and the buddy/friend list is GOALS G6. The
 * client-side machinery behind those buttons exists; nothing on the server has
 * ever answered them.
 *
 * EVIDENCE STATUS - WIRE-UNOBSERVED, stated loudly, per command:
 * `docs/design/v2-port/RS1-TCP-INVENTORY.md` (capture RS1-20260808-172534)
 * parsed EVERY TCP-10127 byte of the session in which those buttons were
 * pressed, and its verdict is explicit: the unanswered set is EMPTY and no
 * 0x61xx/0x67xx/0x68xx button query appeared at all. So there are no captured
 * request bytes and no captured reply to reproduce; whatever those buttons
 * send may ride UDP 9090's SN@P opcodes instead (GOALS G6 notes a UDP
 * op48-NAME / op49 buddy vehicle) or be suppressed client-side. Every handler
 * here is therefore the BioServer reference handler
 * (`references/bioserver/.../bioserv2/bioserver/PacketHandler.java`) translated
 * into the PAL 8-byte framing the same capture grounded, exactly as the
 * create-config dialogue translated the create rows. Until the client sends
 * one of these on TCP, this module changes ZERO bytes on any rig-confirmed
 * path: the frames previously fell into the observed-not-answered branch of
 * the completed-ladder state, which is where this dialogue attaches.
 *
 * | cmd | reference handler | reply |
 * |---|---|---|
 * | `RANKINGS` 0x6145 | `sendRankings` | the reference's own "same (empty)
 *   rankings for every area" record: selector echo, zeroed point words, six
 *   all-spaces rank rows. V2 records no rankings, so the EMPTY variant is the
 *   truthful one - the populated variant in the reference is its authors' test
 *   data ("RANKTEST"). |
 * | `GETINFO` 0x6801 | `sendGetInfo` | `{urlLen:2, url, dataLen:2, data}`,
 *   data = the info page for that URL (reference: file store with a built-in
 *   fallback page; here: injectable resolver with a minimal fallback). |
 * | `BUDDYLIST` 0x6707 | `sendBuddyList` | online `{0,0,0,0,0,0,0}` /
 *   in-game `{0,0,0,0,0,0,1}` / offline markup + err. |
 * | `CHECKBUDDY` 0x6703 | `sendCheckBuddy` | online: length-prefixed id +
 *   status words + markup; in-game / offline: markup + err. |
 *
 * STRING PAYLOADS: the JP transport carries these requests as pid-XOR-shifted
 * strings (`Packet.getDecryptedString`). The PAL transport's one string
 * envelope is the FUN_001c3f40 field codec, so - exactly like the
 * create-config CHARSELECT row - a payload that decodes AND checksums as a
 * field is used decoded, and one that does not is used raw. The checksum makes
 * that choice self-validating rather than guessed.
 *
 * TEXT REPLACEMENTS, stated: the reference's markup strings are Shift-JIS
 * Japanese ("currently playing a game", "is in the GREE area"). The markup
 * ENVELOPE (`{len:2, text}` with `<BODY>/<SIZE=n>/<CENTER>/<END>` tags,
 * contract §2 row 11 and §8) is ported byte-structure-exact; the TEXT is
 * English display content, an operator-owned category like the lbs.jsp
 * welcome message. The reference's hardcoded online CHECKBUDDY id
 * ("0ad601082008", meaning unknown even there) is NOT reproduced: the queried
 * handle is echoed in its place, which is what the contract row's
 * "handle + status words + markup" reading says the field is.
 */

export const TCP10127_LOBBY_BUTTONS = Object.freeze({
  commandRankings: 0x6145,
  commandGetInfo: 0x6801,
  commandBuddyList: 0x6707,
  commandCheckBuddy: 0x6703,
  // SLES_533.19's one request builder writes 0xff at header byte 7 (the same
  // invariant all 186 RS1-observed queries carried).
  requestUnknown7: 0xff,
  /**
   * The reply status byte for the reference's `setErr()` replies. 0xFF is the
   * one non-zero status ever observed from V2 on this transport (the
   * 0x6211/0x6212/0x6213 default-branch TELLs, RS1 inventory), so the error
   * marker reuses it rather than inventing a second convention.
   */
  errorStatus: 0xff,
  /** BioServer `ClientList.getClientStatus` domain. */
  statusOffline: 0,
  statusOnline: 1,
  statusInGame: 3,
  // Bounds for the request string fields, matching the reference's
  // PacketString ceiling used by the create-config dialogue.
  maximumRequestStringLength: 0xff,
  /** 6 rank rows of `{status,char, len:2, handle[6], len:2, name[16]}`. */
  rankingRowCount: 6,
  rankingHandleLength: 6,
  rankingNameLength: 16
});

const HANDLED_COMMANDS = new Set([
  TCP10127_LOBBY_BUTTONS.commandRankings,
  TCP10127_LOBBY_BUTTONS.commandGetInfo,
  TCP10127_LOBBY_BUTTONS.commandBuddyList,
  TCP10127_LOBBY_BUTTONS.commandCheckBuddy
]);

/**
 * The reference's built-in info page is a full Shift-JIS HTML document served
 * when no file matches. This fallback keeps the same shape (an HTML document
 * the client's embedded browser can show) at minimal size; an operator serves
 * real pages through `resolveInfoPage`.
 */
const DEFAULT_INFO_PAGE = Buffer.from(
  '<HTML><HEAD><TITLE>information</TITLE></HEAD>' +
  '<BODY bgcolor="#000033" text=#FFFFFF>PAL Outbreak V2 server</BODY></HTML>',
  'latin1'
);

/** `PacketString.getData()`: `{len:BE16, text}`, cleartext server->client. */
function packetString(text) {
  const bytes = Buffer.from(text, 'latin1');
  const framed = Buffer.alloc(2 + bytes.length);
  framed.writeUInt16BE(bytes.length, 0);
  bytes.copy(framed, 2);
  return framed;
}

function requireFrameInvariant(condition, code, message) {
  if (!condition) throw new Tcp10127ProtocolError(code, message);
}

export class Tcp10127LobbyButtonsDialogue {
  #resolveBuddyStatus;
  #resolveInfoPage;
  #codecByte;
  #logger;

  constructor({
    /**
     * `(handle: Buffer) => 0 | 1 | 3` - the BioServer `getClientStatus` port:
     * 0 offline, 1 online, 3 in a game. Absent means nobody is ever found,
     * which is the truthful answer for a process with no session registry.
     */
    resolveBuddyStatus = null,
    /** `(url: string) => Buffer | null` - the info-page store. */
    resolveInfoPage = null,
    codecByte = 0,
    logger = () => {}
  } = {}) {
    for (const [name, value] of [
      ['resolveBuddyStatus', resolveBuddyStatus],
      ['resolveInfoPage', resolveInfoPage]
    ]) {
      if (value != null && typeof value !== 'function') {
        throw new TypeError(`${name} must be a function when provided`);
      }
    }
    if (!Number.isSafeInteger(codecByte) || codecByte < 0 || codecByte > 0xff) {
      throw new TypeError('codecByte must be an unsigned byte');
    }
    this.#resolveBuddyStatus = resolveBuddyStatus;
    this.#resolveInfoPage = resolveInfoPage;
    this.#codecByte = codecByte;
    this.#logger = logger;
  }

  /** Which commands this dialogue answers; everything else stays observed. */
  handles(command) {
    return HANDLED_COMMANDS.has(command);
  }

  handleFrame(frame) {
    requireFrameInvariant(
      frame.direction === TCP10127_DIRECTION.CLIENT_REQUEST,
      'LOBBY_BUTTONS_DIRECTION',
      'a lobby-button frame must be a client request'
    );
    requireFrameInvariant(
      frame.error === 0,
      'LOBBY_BUTTONS_STATUS',
      'only the normal-status lobby-button path is implemented'
    );
    requireFrameInvariant(
      frame.unknown7 === TCP10127_LOBBY_BUTTONS.requestUnknown7,
      'LOBBY_BUTTONS_UNKNOWN7',
      'SLES_533.19 request builder writes 0xff at header byte 7'
    );
    switch (frame.command) {
      case TCP10127_LOBBY_BUTTONS.commandRankings:
        return this.#handleRankings(frame);
      case TCP10127_LOBBY_BUTTONS.commandGetInfo:
        return this.#handleGetInfo(frame);
      case TCP10127_LOBBY_BUTTONS.commandBuddyList:
        return this.#handleBuddyList(frame);
      case TCP10127_LOBBY_BUTTONS.commandCheckBuddy:
        return this.#handleCheckBuddy(frame);
      default:
        throw new Tcp10127ProtocolError(
          'LOBBY_BUTTONS_COMMAND',
          `command 0x${frame.command.toString(16)} is not a lobby-button query`
        );
    }
  }

  /**
   * RANKINGS 0x6145: request `{area/scenario selector: 2 bytes}`, reply the
   * reference's EMPTY ranking record - `sendRankings`' own emptyrankings shape,
   * which it documents as "the same (empty) rankings for every area":
   *
   *   selector echo (2) - both request bytes, as emptyrankings[0..1] echoes
   *   points/rank words (37, all zero here - the populated variant fills them
   *     with the reference authors' test values, not data)
   *   6 rows of {status:1, character:1, 0x0006, handle[6], 0x0010, name[16]}
   *     - status 0, spaces: an empty rank row.
   *
   * Total 2 + 37 + 6*28 = 207 bytes. V2 records no game results (rankings are
   * TODO in the reference too), so empty is the truthful reply, not a stub.
   */
  #handleRankings(frame) {
    requireFrameInvariant(
      frame.payloadLength >= 2,
      'RANKINGS_LENGTH',
      'RANKINGS carries a two-byte area/scenario selector'
    );
    const rows = TCP10127_LOBBY_BUTTONS.rankingRowCount;
    const rowLength = 1 + 1 +
      2 + TCP10127_LOBBY_BUTTONS.rankingHandleLength +
      2 + TCP10127_LOBBY_BUTTONS.rankingNameLength; // 28
    const payload = Buffer.alloc(2 + 37 + rows * rowLength);
    payload[0] = frame.payload[0];
    payload[1] = frame.payload[1];
    for (let row = 0; row < rows; row += 1) {
      const base = 2 + 37 + row * rowLength;
      // status 0, character 0 (already zero), then the two length-prefixed
      // space-filled identity fields the client renders as an empty row.
      payload.writeUInt16BE(TCP10127_LOBBY_BUTTONS.rankingHandleLength, base + 2);
      payload.fill(0x20, base + 4, base + 4 + TCP10127_LOBBY_BUTTONS.rankingHandleLength);
      payload.writeUInt16BE(TCP10127_LOBBY_BUTTONS.rankingNameLength, base + 10);
      payload.fill(0x20, base + 12, base + 12 + TCP10127_LOBBY_BUTTONS.rankingNameLength);
    }
    this.#logger({ type: 'lobby-buttons-rankings', selector: frame.payload.readUInt16BE(0) });
    return this.#result(frame, payload);
  }

  /**
   * GETINFO 0x6801: request = the page URL as a string field; reply
   * `{urlLen:2, url, dataLen:2, data}` (`sendGetInfo` byte for byte, with the
   * URL echoed cleartext exactly as the reference echoes its decrypted copy).
   */
  #handleGetInfo(frame) {
    const url = this.#decodeRequestString(frame);
    let page = null;
    if (this.#resolveInfoPage != null) {
      try {
        page = this.#resolveInfoPage(url.toString('latin1'));
      } catch (error) {
        // The reference logs a failed file read and serves its fallback.
        this.#logger({ type: 'lobby-buttons-info-page-failed', message: error.message });
      }
    }
    const data = Buffer.isBuffer(page) ? page : DEFAULT_INFO_PAGE;
    const payload = Buffer.alloc(2 + url.length + 2 + data.length);
    payload.writeUInt16BE(url.length, 0);
    url.copy(payload, 2);
    payload.writeUInt16BE(data.length, 2 + url.length);
    data.copy(payload, 4 + url.length);
    this.#logger({
      type: 'lobby-buttons-getinfo',
      url: url.toString('latin1'),
      pageBytes: data.length
    });
    return this.#result(frame, payload);
  }

  /**
   * BUDDYLIST 0x6707: request = a handle string field. `sendBuddyList`:
   * online -> 7 bytes `{0,0,0,0,0,0,0}`; in-game -> `{0,0,0,0,0,0,1}`;
   * offline -> markup "not connected" with the error status set.
   */
  #handleBuddyList(frame) {
    const handle = this.#decodeRequestString(frame);
    const status = this.#buddyStatus(handle);
    this.#logger({
      type: 'lobby-buttons-buddylist',
      handle: handle.toString('latin1'),
      status
    });
    if (status === TCP10127_LOBBY_BUTTONS.statusOnline) {
      return this.#result(frame, Buffer.from([0, 0, 0, 0, 0, 0, 0]));
    }
    if (status === TCP10127_LOBBY_BUTTONS.statusInGame) {
      return this.#result(frame, Buffer.from([0, 0, 0, 0, 0, 0, 1]));
    }
    return this.#result(
      frame,
      packetString('<BODY><SIZE=3>not connected<END>'),
      { error: TCP10127_LOBBY_BUTTONS.errorStatus }
    );
  }

  /**
   * CHECKBUDDY 0x6703: request = a handle string field. `sendCheckBuddy`:
   * online -> `{idLen:2, id, 0x0001, 0x0000, 0x0000, 0x0003, markupLen:2,
   * markup}` with err clear; in-game -> markup + err; offline -> markup + err.
   * The id field carries the queried handle (see the module docstring for why
   * the reference's opaque hardcoded id is not reproduced); the four status
   * words are the reference's constants.
   */
  #handleCheckBuddy(frame) {
    const handle = this.#decodeRequestString(frame);
    const status = this.#buddyStatus(handle);
    this.#logger({
      type: 'lobby-buttons-checkbuddy',
      handle: handle.toString('latin1'),
      status
    });
    if (status === TCP10127_LOBBY_BUTTONS.statusOnline) {
      const markup = packetString('<BODY><SIZE=3>online<END>');
      const payload = Buffer.alloc(2 + handle.length + 8 + markup.length);
      payload.writeUInt16BE(handle.length, 0);
      handle.copy(payload, 2);
      payload.writeUInt16BE(0x0001, 2 + handle.length);
      payload.writeUInt16BE(0x0000, 4 + handle.length);
      payload.writeUInt16BE(0x0000, 6 + handle.length);
      payload.writeUInt16BE(0x0003, 8 + handle.length);
      markup.copy(payload, 10 + handle.length);
      return this.#result(frame, payload);
    }
    if (status === TCP10127_LOBBY_BUTTONS.statusInGame) {
      return this.#result(
        frame,
        packetString('<BODY><SIZE=3>currently in a game<END>'),
        { error: TCP10127_LOBBY_BUTTONS.errorStatus }
      );
    }
    return this.#result(
      frame,
      packetString('<BODY><SIZE=3><CENTER>not connected<END>'),
      { error: TCP10127_LOBBY_BUTTONS.errorStatus }
    );
  }

  /* ---- internals --------------------------------------------------------- */

  /**
   * The request string: decoded when the payload verifies as a FUN_001c3f40
   * field with this connection's codec byte, raw otherwise (the create-config
   * CHARSELECT convention - which envelope the PAL client would use here is
   * wire-unobserved, and the field checksum makes the choice self-validating).
   */
  #decodeRequestString(frame) {
    const decoded = decodeSnapField({
      field: frame.payload,
      maximumDecodedLength: TCP10127_LOBBY_BUTTONS.maximumRequestStringLength,
      sequence: frame.sequence,
      unknownCodecByte: this.#codecByte
    });
    const value = decoded ?? frame.payload;
    requireFrameInvariant(
      value.length <= TCP10127_LOBBY_BUTTONS.maximumRequestStringLength,
      'LOBBY_BUTTONS_STRING_LENGTH',
      `request string of ${value.length} bytes exceeds the reference's PacketString ceiling`
    );
    return Buffer.from(value);
  }

  #buddyStatus(handle) {
    if (this.#resolveBuddyStatus == null) return TCP10127_LOBBY_BUTTONS.statusOffline;
    let status;
    try {
      status = this.#resolveBuddyStatus(Buffer.from(handle));
    } catch (error) {
      throw new Tcp10127ProtocolError(
        'LOBBY_BUTTONS_RESOLVER',
        `resolveBuddyStatus failed: ${error.message}`
      );
    }
    requireFrameInvariant(
      status === TCP10127_LOBBY_BUTTONS.statusOffline ||
      status === TCP10127_LOBBY_BUTTONS.statusOnline ||
      status === TCP10127_LOBBY_BUTTONS.statusInGame,
      'LOBBY_BUTTONS_STATUS_DOMAIN',
      `resolveBuddyStatus returned ${status}; the getClientStatus domain is {0, 1, 3}`
    );
    return status;
  }

  /** TELL: same command, same sequence - the shape of all 186 observed TELLs. */
  #result(frame, payload, { error = 0 } = {}) {
    const response = encodeTcp10127Frame({
      direction: TCP10127_DIRECTION.SERVER_RESPONSE,
      command: frame.command,
      sequence: frame.sequence,
      error,
      unknown7: frame.unknown7,
      payload
    });
    return {
      response,
      state: 'lobby-buttons-dialogue',
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
