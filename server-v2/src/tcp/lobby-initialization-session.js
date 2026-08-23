import {
  TCP10127_DIRECTION,
  Tcp10127ProtocolError,
  encodeTcp10127Frame
} from '../protocol/tcp10127-codec.js';
import { decodeSnapField, encodeSnapField } from '../protocol/snap-field-codec.js';

export const TCP10127_LOBBY_INITIALIZATION = Object.freeze({
  command: 0x1007,
  requestPayloadLength: 49,
  requestUnknown7: 0xff,
  responseMode: 0x00,
  // The 49 payload bytes are one opaque lead byte followed by one variable
  // field. All four captured requests (three emulator, one real PS2) carry lead
  // 0x01 and a 44-byte plaintext whose checksum verifies with codec byte zero.
  identityFieldOffset: 1,
  identityFieldMaximumLength: 44,
  identityCodecByte: 0
});

export const TCP10127_KEYED_MANIFEST = Object.freeze({
  command: 0x6103,
  requestPayloadLength: 0,
  requestUnknown7: 0xff,
  emptyCount: 0
});

export const TCP10127_COMMAND_6212 = Object.freeze({
  command: 0x6212,
  requestPayloadLength: 0,
  requestUnknown7: 0xff,
  clientDefaultResponseError: 0xff,
  responsePayloadLength: 4
});

/**
 * `0x6203` AREACOUNT - the reply that decides whether ANY area is ever enterable.
 *
 * `FUN_001c4960.c:26-29` routes reply mode 2 straight to substate `0x14`: the
 * client asks for nothing more and its area table at `0x361a70` is never written,
 * so `FUN_005ad350.c:31` - which refuses to enter an area unless that table's
 * `+0x14c` byte is 3 - can never pass. V2 answered mode 2 until 2026-08-06, which
 * is why no area could be entered whatever else was fixed.
 *
 * Mode 1 (`:30-91`) makes the client decode a version field bounded to `0x1f`
 * (`FUN_001c3b90(param_1, 0x36844c, 0x1f)`), compare it with its cached copy at
 * `0x36842c`, and - only when they DIFFER - read a BE16 chunk count and one BE32
 * length per chunk, then move to substate `0x12`, the `0x6204` builder. Mode 0
 * and every other value are terminal ladder errors (`:98-121`).
 *
 * V1's exact wire, from the session that rendered Area Select on real PS2
 * hardware (`2026_07_30_14_52_53_snap_session5_trace.log` RAW-OUT #6):
 * `01 000b5631<"OBAREA-V1"> 0001 00001300`.
 */
export const TCP10127_COMMAND_6203 = Object.freeze({
  command: 0x6203,
  requestMinimumPayloadLength: 4,
  requestUnknown7: 0xff,
  responseMode: 0x01,
  // FUN_001c4960.c:32 decodes the version with bound 0x1f; the same bound applies
  // to the client's cached version echoed back in the request.
  maximumVersionLength: 0x1f,
  // FUN_001c4960.c:52 treats a zero count as terminal and :65-67 clamps above 2.
  minimumChunkCount: 1,
  maximumChunkCount: 2,
  // FUN_001c4960.c:76 treats any declared chunk length above this as terminal.
  maximumChunkLength: 0x2000
});

/**
 * `0x6204` AREANAME - the area blob itself, in fixed slices.
 *
 * Request, `FUN_001c4c80.c:8-11`: command index 0x14 then `FUN_001c3e10` (BE16
 * chunk index), `FUN_001c3ea0` (BE32 offset), `FUN_001c3e10(0x2f2)`. Eight bytes,
 * and the length word is the literal 0x2f2 on every request.
 *
 * Reply, `FUN_001c4d40.c:27-65`: BE16 chunk index which must equal the client's
 * own `bRam00368421`, BE32 offset which must equal its own `uRam00368424`, then
 * one encoded field decoded straight into `blobBase[chunk] + offset`.
 *
 * The two hard constraints, both from `:31` and `:41`:
 *   - the client advances its cursor by exactly 0x2f2 whatever the reply carried,
 *     so a short NON-FINAL slice silently leaves a hole in the blob;
 *   - the final slice's decode bound is `declaredLength - offset`, so it must
 *     carry exactly the remainder.
 * Both are enforced by the area table rather than clamped here.
 */
export const TCP10127_COMMAND_6204 = Object.freeze({
  command: 0x6204,
  requestPayloadLength: 8,
  requestUnknown7: 0xff,
  requestSliceLength: 0x2f2,
  maximumSliceLength: 0x2f2
});

export const TCP10127_COMMAND_6211 = Object.freeze({
  command: 0x6211,
  requestPayloadLength: 0,
  requestUnknown7: 0xff,
  clientDefaultResponseError: 0xff,
  responsePayloadLength: 4
});

export const TCP10127_COMMAND_6213 = Object.freeze({
  command: 0x6213,
  requestPayloadLength: 0,
  requestUnknown7: 0xff,
  clientDefaultResponseError: 0xff,
  responseWordCount: 8,
  responsePayloadLength: 16
});

export const TCP10127_COMMAND_6501 = Object.freeze({
  command: 0x6501,
  requestPayloadLength: 4,
  requestUnknown7: 0xff,
  mode0: 0,
  mode1: 1,
  mode0ResponsePayloadLength: 1,
  mode1ResponsePayloadLength: 9
});

export const TCP10127_COMMAND_6502 = Object.freeze({
  command: 0x6502,
  requestMinimumPayloadLength: 8,
  requestUnknown7: 0xff,
  mode0: 0,
  mode1: 1,
  mode1ResponsePayloadLength: 9
});

/**
 * `0x6503` - the server-entry list. The ONLY command that writes the client's
 * entry table at `0x365e20`, and therefore the only thing that can put a
 * non-zero count on Server Select.
 *
 * Request, `FUN_001c7000`: `FUN_001c3c90(ctx, 0x20, 1, 0)` - builder index 0x20,
 * which DAT_002484c0/DAT_00248510 map to wire command 0x6503, direction 1,
 * status 0 - then two BE16 writers (`FUN_001c3e10`) carrying `uRam00365e18`
 * (the offset already received) and `uRam00365e1a` (the count wanted, set to 8
 * by the mode-1 `0x6501` reply). Exactly four payload bytes.
 *
 * Reply, `FUN_001c70b0`: BE16 total -> `0x365e1e`, BE16 batchStart ->
 * `0x365e18`, u8 batchCount -> `0x365e1c`, then per entry, into
 * `(0x365e0c + i) * 0x260 + 0x365e20`, four fields at +0x00 / +0x3f / +0x4f /
 * +0x57 with the bounds below. Every bound is the client's own: `li a2,62`,
 * `li a2,15` and `li a2,255` passed to `FUN_001c3b90`, whose -2 return on an
 * over-long decode is terminal for the whole ladder, and a do-while of exactly
 * eight `FUN_001c3a60` calls for the raw block.
 *
 * `total` is bounded 1..16 here rather than clamped. `total == 0` is an explicit
 * terminal `-1` in the parser, and `total > 0x10` is terminal when the
 * connection's state word is 1 and silently clamped otherwise - V2 does not
 * observe that state word, so it never sends a value whose handling depends on
 * it.
 */
export const TCP10127_COMMAND_6503 = Object.freeze({
  command: 0x6503,
  requestPayloadLength: 4,
  requestUnknown7: 0xff,
  minimumTotal: 1,
  maximumTotal: 0x10,
  maximumHostLength: 0x3e,
  maximumNameLength: 0x0f,
  rawFieldLength: 8,
  maximumDescriptionLength: 0xff
});

export const TCP10127_COMMAND_6504 = Object.freeze({
  command: 0x6504,
  requestMinimumPayloadLength: 8,
  requestUnknown7: 0xff,
  maximumUnknownTotal: 0x40,
  maximumField0Length: 0x0f,
  maximumField1Length: 0x0f,
  rawFieldLength: 8,
  maximumField2Length: 0xff
});

export const TCP10127_COMMAND_6510 = Object.freeze({
  command: 0x6510,
  requestUnknown7: 0xff,
  // FUN_001c85c0 loads the batch size with `li v0,12` at 0x001c85cc and only ever
  // lowers it to the remaining record count, so 12 is the builder's hard ceiling.
  maximumRequestRecordCount: 0x0c,
  // FUN_001c8790 decodes the trailing field with `li a2,62` at 0x001c892c, and
  // FUN_001c3b90 rejects any decoded length above that bound with -2.
  maximumTrailingFieldLength: 0x3e,
  // FUN_001c3f40 writes BE16 decodedLength+2 followed by a BE16 checksum, so the
  // smallest legal field envelope declares two and carries no plaintext.
  minimumFieldLengthWord: 2,
  // The continuations FUN_001c8790 can select once the record list is exhausted.
  followupCommand6203: 0x6203,
  followupCommand1004: 0x1004
});

export const TCP10127_COMMAND_1004 = Object.freeze({
  command: 0x1004,
  // FUN_001c8dd0 builds command index 0x05 and appends no fields, so the terminal
  // request is exactly the eight-byte header.
  requestPayloadLength: 0,
  requestUnknown7: 0xff,
  // FUN_001c8e90 is `jr ra; li v0,1`: it consumes no reply payload at all.
  responsePayloadLength: 0
});

export const TCP10127_LOBBY_INITIALIZATION_STATE = Object.freeze({
  AWAITING_LOBBY_INIT_REQUEST: 'awaiting-0x1007',
  AWAITING_KEYED_MANIFEST_REQUEST: 'awaiting-0x6103',
  AWAITING_COMMAND_6212: 'awaiting-0x6212',
  AWAITING_COMMAND_6203: 'awaiting-0x6203',
  // After the mode-1 0x6203 reply the client either fetches the blob or skips it,
  // because FUN_001c4960.c:46-49 goes straight to substate 0x14 - the 0x6211
  // builder - when the version it was sent equals the one it already cached.
  AWAITING_COMMAND_6204: 'awaiting-0x6204',
  AWAITING_MORE_COMMAND_6204: 'awaiting-more-0x6204',
  AWAITING_COMMAND_6211: 'awaiting-0x6211',
  AWAITING_COMMAND_6213: 'awaiting-0x6213',
  AWAITING_COMMAND_6501: 'awaiting-0x6501',
  AWAITING_POST_COMMAND_6501_MODE_0: 'awaiting-post-0x6501-mode0',
  AWAITING_COMMAND_6503: 'awaiting-0x6503',
  AWAITING_MORE_COMMAND_6503: 'awaiting-more-0x6503',
  AWAITING_POST_COMMAND_6503_COMPLETE: 'awaiting-post-0x6503-complete',
  AWAITING_POST_COMMAND_6502_MODE_0: 'awaiting-post-0x6502-mode0',
  AWAITING_COMMAND_6504: 'awaiting-0x6504',
  AWAITING_MORE_COMMAND_6504: 'awaiting-more-0x6504',
  AWAITING_POST_COMMAND_6504_COMPLETE: 'awaiting-post-0x6504-complete',
  AWAITING_POST_COMMAND_6510: 'awaiting-post-0x6510',
  LOBBY_INITIALIZATION_COMPLETE: 'lobby-initialization-complete'
});

function requireFrameInvariant(condition, code, message) {
  if (!condition) throw new Tcp10127ProtocolError(code, message);
}

/**
 * Evidence-bounded PAL lobby-initialization exchanges.
 *
 * The 49 request payload bytes remain opaque. Three captures share a stable
 * shape, but neither their prefix nor their XOR-normalized tail has a proven
 * server-side meaning. Do not reject clients by inspecting those unknowns.
 *
 * Response mode 0 is decoded by SLES_533.19 FUN_001c9030 and advances its
 * substate to 0x29 without the two mode-1 fields.
 *
 * The next captured request is payload-less command 0x6103. SLES_533.19
 * FUN_001c5f30 reads a BE u16 record count. Count zero is an explicit branch
 * to substate 2 and reads no key/data records. V2 uses that real empty branch
 * instead of V1's synthetic key and content.
 *
 * From that substate, FUN_001c42d0 emits the canonical payload-less request
 * mapped to wire command 0x6212. FUN_001c4360 consumes one BE u32 reply field
 * and advances to substate 0x10. The PAL corpus does not prove that field's
 * domain meaning. A supplied server-state dependency selects the explicit
 * value branch; otherwise status 0xff selects the decoded client-default
 * branch, which stores zero and reaches the same continuation.
 *
 * FUN_001c48c0 then emits 0x6203, carrying one FUN_001c3f40 field: the version
 * string of the area table the client already holds cached at 0x36842c. V2
 * answers MODE 1 - the area table - and the reasoning, including why the mode-2
 * reply it used to send made every area un-enterable, is on
 * TCP10127_COMMAND_6203 above. The client then fetches the blob with 0x6204, or
 * skips straight to 0x6211 when the version it was sent matches its cache.
 *
 * From substate 0x14, FUN_001c4560 emits payload-less 0x6211 and waits in
 * substate 0x15. FUN_001c45f0 consumes one BE u32 into global 0x0036847c and
 * routes its continuation by the connection's major state. Neither decoded
 * code nor its direct disassembly establishes the value's domain meaning. A
 * supplied dependency selects the explicit value branch; otherwise status
 * 0xff selects the decoded client-default branch, which stores zero and
 * reaches the same major-state-dependent continuation.
 *
 * FUN_001c43c0 emits payload-less 0x6213 and waits in substate 0x0f.
 * FUN_001c4450 consumes eight ordered BE16 words into 0x00368484..0x00368492,
 * then advances unconditionally to substate 0x04, whose scheduler emits 0x6501.
 * Downstream consumers do not establish complete semantic names or the normal
 * server-side source for every word. A supplied dependency selects the eight-
 * word branch. Otherwise status 0xff makes this exact PAL receiver install its
 * executable-owned defaults and advance; this is not generalized to any other
 * handler.
 */
export class Tcp10127LobbyInitializationSession {
  #state = TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_LOBBY_INIT_REQUEST;
  /** True when this connection began at 0x6501, i.e. it is a resume. */
  #resumed = false;
  #areaTable;
  #codecByte;
  // The client's own `bRam00368421` / `uRam00368424`, predicted. Reset by every
  // 0x6203 reply, exactly as FUN_001c4960.c:93-95 resets them.
  #areaChunkIndex = 0;
  #areaOffset = 0;
  /** The chunk table this connection declared in its last 0x6203 reply. */
  #areaChunkLengths = [];
  #resolveCommand6212Value;
  #resolveCommand6211Value;
  #resolveCommand6213Words;
  #resolveCommand6501Response;
  #resolveCommand6503Response;
  #resolveCommand6502Response;
  #resolveCommand6504Response;
  #resolveCommand6510Response;
  #associateDnasToken;
  #associateResumeSession;
  #onInitializationComplete;
  #createConfigDialogue;
  #lobbyButtonsDialogue;

  constructor({
    areaTable,
    /**
     * The connection's field codec word, the low byte of `+0x4c`.
     *
     * Zero, and required to be stated rather than discovered: all four captured
     * `0x1007` identity fields decode and checksum with 0 and with nothing else
     * (`test/connection-identity.test.js`), and the client verifies the SERVER's
     * fields with the same word, so any other value makes `FUN_001c3b90` return
     * -3 and drop the ladder. It is a connection property, not a per-reply choice,
     * which is why the area replies take it from here rather than from a provider
     * selection the way the directory replies do.
     */
    codecByte = 0,
    associateDnasToken,
    associateResumeSession = null,
    onInitializationComplete = null,
    /**
     * The create-config dialogue (SNAP_CREATE_CONFIG), answered only AFTER the
     * 0x1004 completion - the one state whose frames were previously observed
     * and never answered. Optional: without it every post-completion frame
     * keeps the observed-not-answered behaviour, byte for byte.
     */
    createConfigDialogue = null,
    /**
     * The lobby-button dialogue (SNAP_LOBBY_BUTTONS): RANKINGS/GETINFO/
     * BUDDYLIST/CHECKBUDDY, answered in the same post-completion state under
     * the same rules - optional, and without it those frames keep the
     * observed-not-answered behaviour byte for byte.
     */
    lobbyButtonsDialogue = null,
    resolveCommand6212Value,
    resolveCommand6211Value,
    resolveCommand6213Words,
    resolveCommand6501Response,
    resolveCommand6503Response,
    resolveCommand6502Response,
    resolveCommand6504Response,
    resolveCommand6510Response
  } = {}) {
    /*
     * REQUIRED, and required at construction rather than at first use. A session
     * without an area table cannot answer 0x6203 with anything the client can act
     * on, and the failure mode of the alternative is not an error - it is a
     * silent mode-2 reply that renders a lobby nobody can enter. That regression
     * shipped once; a constructor-time TypeError makes it impossible to ship
     * again by omission.
     */
    if (areaTable == null || typeof areaTable.chunkLengths !== 'function' ||
        typeof areaTable.sliceAt !== 'function' || !Buffer.isBuffer(areaTable.version)) {
      throw new TypeError(
        'areaTable is required and must expose version, chunkLengths and sliceAt'
      );
    }
    if (!Number.isSafeInteger(codecByte) || codecByte < 0 || codecByte > 0xff) {
      throw new TypeError('codecByte must be an unsigned byte');
    }
    if (resolveCommand6212Value != null && typeof resolveCommand6212Value !== 'function') {
      throw new TypeError('resolveCommand6212Value must be a function when provided');
    }
    if (resolveCommand6211Value != null && typeof resolveCommand6211Value !== 'function') {
      throw new TypeError('resolveCommand6211Value must be a function when provided');
    }
    if (resolveCommand6213Words != null && typeof resolveCommand6213Words !== 'function') {
      throw new TypeError('resolveCommand6213Words must be a function when provided');
    }
    if (resolveCommand6501Response != null && typeof resolveCommand6501Response !== 'function') {
      throw new TypeError('resolveCommand6501Response must be a function when provided');
    }
    if (resolveCommand6503Response != null && typeof resolveCommand6503Response !== 'function') {
      throw new TypeError('resolveCommand6503Response must be a function when provided');
    }
    if (resolveCommand6502Response != null && typeof resolveCommand6502Response !== 'function') {
      throw new TypeError('resolveCommand6502Response must be a function when provided');
    }
    if (resolveCommand6504Response != null && typeof resolveCommand6504Response !== 'function') {
      throw new TypeError('resolveCommand6504Response must be a function when provided');
    }
    if (resolveCommand6510Response != null && typeof resolveCommand6510Response !== 'function') {
      throw new TypeError('resolveCommand6510Response must be a function when provided');
    }
    if (associateDnasToken != null && typeof associateDnasToken !== 'function') {
      throw new TypeError('associateDnasToken must be a function when provided');
    }
    if (associateResumeSession != null && typeof associateResumeSession !== 'function') {
      throw new TypeError('associateResumeSession must be a function when provided');
    }
    for (const [name, dialogue] of [
      ['createConfigDialogue', createConfigDialogue],
      ['lobbyButtonsDialogue', lobbyButtonsDialogue]
    ]) {
      if (dialogue != null && (
        typeof dialogue.handles !== 'function' ||
        typeof dialogue.handleFrame !== 'function')) {
        throw new TypeError(
          `${name} must expose handles(command) and handleFrame(frame)`
        );
      }
    }
    this.#areaTable = areaTable;
    this.#codecByte = codecByte;
    this.#createConfigDialogue = createConfigDialogue;
    this.#lobbyButtonsDialogue = lobbyButtonsDialogue;
    this.#associateDnasToken = associateDnasToken;
    this.#associateResumeSession = associateResumeSession;
    this.#onInitializationComplete = onInitializationComplete;
    this.#resolveCommand6212Value = resolveCommand6212Value;
    this.#resolveCommand6211Value = resolveCommand6211Value;
    this.#resolveCommand6213Words = resolveCommand6213Words;
    this.#resolveCommand6501Response = resolveCommand6501Response;
    this.#resolveCommand6503Response = resolveCommand6503Response;
    this.#resolveCommand6502Response = resolveCommand6502Response;
    this.#resolveCommand6504Response = resolveCommand6504Response;
    this.#resolveCommand6510Response = resolveCommand6510Response;
  }

  get state() {
    return this.#state;
  }

  handleFrame(frame) {
    if (this.#state === TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_LOBBY_INIT_REQUEST) {
      // THE RESUME CONNECTION (R-019) takes a DISTINCT entry path and is never
      // routed through the fresh-initialization handler. After a completed
      // ladder the client resets and reopens on a new source port whose FIRST
      // frame is `0x6501`; there is no second `0x1007`. Observed 2026-08-04:
      // complete at 18:10:26, resume at 18:10:41 with `0x6501` sequence 0xb4,
      // which V2 refused - the player saw "could not connect to lobby server"
      // and then D901.
      //
      // The resume frame differs from the fresh ladder's `0x6501` ONLY in its
      // sequence byte (fresh `0x0a`, resume `0xb4`); the 4-byte payload is
      // `00000000` in both. So the payload carries nothing to resolve on, and
      // the sequence is the only protocol-carried state available. It is passed
      // to the associator, which uses it as a fail-closed REPLAY filter - it is
      // one byte and cannot be an identity.
      if (frame.command === TCP10127_COMMAND_6501.command) {
        requireFrameInvariant(
          this.#associateResumeSession != null,
          'LOBBY_RESUME_UNSUPPORTED',
          '0x6501 opened a connection but no resume associator is configured'
        );
        // VALIDATE BEFORE BINDING. An earlier version associated first and
        // validated afterwards, so a malformed frame claimed a live session
        // before being refused - a resume denial-of-service against the player
        // whose session it briefly took.
        this.#assertCommand6501Frame(frame);
        try {
          this.#associateResumeSession({ sequence: frame.sequence });
        } catch (error) {
          throw new Tcp10127ProtocolError(
            error.code ?? 'LOBBY_RESUME_ASSOCIATION',
            `0x6501 resume could not be attached to a completed session: ${error.message}`
          );
        }
        this.#resumed = true;
        this.#state = TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6501;
        return this.handleFrame(frame);
      }
      return this.#handleLobbyInitialization(frame);
    }
    if (this.#state === TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_KEYED_MANIFEST_REQUEST) {
      return this.#handleKeyedManifest(frame);
    }
    if (this.#state === TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6212) {
      return this.#handleCommand6212(frame);
    }
    if (
      this.#state ===
      TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6203
    ) {
      return this.#handleCommand6203(frame);
    }
    if (this.#state === TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6204) {
      /*
       * THE CACHE HIT IS A REAL BRANCH, not a courtesy. `FUN_001c4960.c:46-49`
       * compares the version just received with the client's cached copy at
       * `0x36842c` and, when they match, sets substate `0x14` - the `0x6211`
       * builder - without reading the chunk table at all. So a client that
       * already holds this exact area table skips straight past `0x6204`, and a
       * server that refused `0x6211` here would drop precisely the connection
       * whose blob is already correct.
       */
      if (frame.command === TCP10127_COMMAND_6211.command) {
        return this.#handleCommand6211(frame);
      }
      return this.#handleCommand6204(frame);
    }
    if (this.#state === TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_MORE_COMMAND_6204) {
      // Mid-transfer there is no cache branch left: FUN_001c4d40.c:37/:44 sets
      // substate 0x12 again for every slice but the last.
      return this.#handleCommand6204(frame);
    }
    if (
      this.#state ===
      TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6211
    ) {
      return this.#handleCommand6211(frame);
    }
    if (
      this.#state ===
      TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6213
    ) {
      return this.#handleCommand6213(frame);
    }
    if (this.#state === TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6501) {
      return this.#handleCommand6501(frame);
    }
    if (
      this.#state ===
      TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_POST_COMMAND_6501_MODE_0
    ) {
      if (frame.command === TCP10127_COMMAND_6502.command) {
        return this.#handleCommand6502(frame);
      }
      if (frame.command === TCP10127_COMMAND_6510.command) {
        return this.#handleCommand6510(frame);
      }
      return this.#preserveExpectedFollowup(frame, [0x6502, 0x6510], 'COMMAND_6501_MODE_0');
    }
    if (this.#state === TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6503 ||
        this.#state === TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_MORE_COMMAND_6503) {
      return this.#handleCommand6503(frame);
    }
    if (
      this.#state ===
      TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_POST_COMMAND_6503_COMPLETE
    ) {
      // FUN_001c70b0 sets phase 8 once `0x365e18 >= 0x365e1e`, and phase 8 is
      // the 0x6502 builder. Deliberately strict: this route has never been
      // exercised against a real client, so anything else here is a divergence
      // worth a named error rather than a silent accommodation.
      if (frame.command === TCP10127_COMMAND_6502.command) {
        return this.#handleCommand6502(frame);
      }
      return this.#preserveExpectedFollowup(frame, [0x6502], 'COMMAND_6503_COMPLETE');
    }
    if (
      this.#state ===
      TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_POST_COMMAND_6502_MODE_0
    ) {
      if (frame.command === TCP10127_COMMAND_6502.command) {
        return this.#handleCommand6502(frame);
      }
      if (frame.command === TCP10127_COMMAND_6510.command) {
        return this.#handleCommand6510(frame);
      }
      return this.#preserveExpectedFollowup(frame, [0x6510], 'COMMAND_6502_MODE_0');
    }
    if (this.#state === TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6504) {
      return this.#handleCommand6504(frame);
    }
    if (this.#state === TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_MORE_COMMAND_6504) {
      return this.#handleCommand6504(frame);
    }
    if (
      this.#state ===
      TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_POST_COMMAND_6504_COMPLETE
    ) {
      if (frame.command === TCP10127_COMMAND_6510.command) {
        return this.#handleCommand6510(frame);
      }
      /*
       * THE NEXT ENTRY. `FUN_001c7a70`'s tail increments `0x365e0c` when an
       * entry's records are complete and, while `0x365e0c < 0x365e1e`, routes to
       * phase 8 - the `0x6502` builder - for the next entry; only when the
       * entries are exhausted does it reset the cursor and go to phase `0x0c`
       * for `0x6510`.
       *
       * This was merely OBSERVED here until T32, and it never showed up as a
       * defect because `0x365e1e` is written only by `0x6503`: with no `0x6503`
       * the total stayed 0, the comparison was never true, and a client could
       * not reach a second entry however many the server held. Answering the
       * entry list is what makes this branch reachable, so it has to be answered
       * too. The projection is already at the next entry - `#finishEntry` moved
       * it - and fails closed if the walk is actually over.
       */
      if (frame.command === TCP10127_COMMAND_6502.command) {
        return this.#handleCommand6502(frame);
      }
      return this.#preserveExpectedFollowup(frame, [0x6502, 0x6510], 'COMMAND_6504_COMPLETE');
    }
    if (
      this.#state === TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_POST_COMMAND_6510
    ) {
      if (frame.command === TCP10127_COMMAND_6510.command) {
        return this.#handleCommand6510(frame);
      }
      if (frame.command === TCP10127_COMMAND_1004.command) {
        return this.#handleCommand1004(frame);
      }
      // Major state 4 selects substate 0x10, whose scheduler case builds 0x6203
      // through FUN_001c48c0 (command index 0x12). Its consumer FUN_001c4960
      // writes substate 0x14 on mode 2 unconditionally, so the client re-enters
      // the same 0x6211 -> 0x6213 -> 0x6501 sub-ladder V2 already implements.
      if (frame.command === TCP10127_COMMAND_6203.command) {
        return this.#handleCommand6203(frame);
      }
      // Every decoded continuation out of FUN_001c8790 is now answered, so there
      // is nothing left to merely preserve in this state.
      throw new Tcp10127ProtocolError(
        'COMMAND_6510_FOLLOWUP_COMMAND',
        `unexpected command 0x${frame.command.toString(16)} after 0x6510; ` +
          'the decoded continuations are 0x6510, 0x6203, and 0x1004'
      );
    }
    if (
      this.#state === TCP10127_LOBBY_INITIALIZATION_STATE.LOBBY_INITIALIZATION_COMPLETE
    ) {
      /*
       * THE CREATE-CONFIG DIALOGUE (SNAP_CREATE_CONFIG). The contract's
       * create rows (CREATESLOT 0x6407 ... commit 0x6504) are answered here
       * when a dialogue is attached; the RS1 inventory's one session shows
       * no such frame in its post-completion window (which is absence of
       * evidence, not proof of absence), so this changes nothing until one
       * arrives. The ladder's OWN 0x6504 usage - the record-batch request
       * that IS on TCP every session - cannot reach this branch: it lives in
       * the AWAITING_* states above, which are unreachable after 0x1004.
       */
      if (this.#createConfigDialogue != null &&
          this.#createConfigDialogue.handles(frame.command)) {
        return this.#dispatchDialogue(this.#createConfigDialogue, frame);
      }
      /*
       * THE LOBBY-BUTTON QUERIES (SNAP_LOBBY_BUTTONS): RANKINGS 0x6145,
       * GETINFO 0x6801, BUDDYLIST 0x6707, CHECKBUDDY 0x6703, per the
       * bioserver reference. Same evidence status as the create rows: the RS1
       * inventory shows none has ever arrived on TCP, so this answers only
       * frames that were previously observed-not-answered. The two dialogues'
       * command sets are disjoint by construction (0x64xx/0x65xx/0x66xx/0x6190
       * vs 0x6145/0x67xx/0x6801), so consult order cannot matter.
       */
      if (this.#lobbyButtonsDialogue != null &&
          this.#lobbyButtonsDialogue.handles(frame.command)) {
        return this.#dispatchDialogue(this.#lobbyButtonsDialogue, frame);
      }
      // Deliberately observed-not-answered rather than fatal. What the client
      // does after the 0x1004 completion is an open question, and destroying the
      // connection here would suppress the very evidence needed to answer it.
      // Captured V1 sessions show the client sends nothing and the connection
      // closes shortly afterwards, but the initiator is not established.
      return {
        response: null,
        state: this.#state,
        unimplemented: true,
        request: {
          command: frame.command,
          sequence: frame.sequence,
          unknown7: frame.unknown7,
          unknownPayload: Buffer.from(frame.payload)
        }
      };
    }
    return {
      response: null,
      state: this.#state,
      unimplemented: true,
      request: {
        command: frame.command,
        sequence: frame.sequence,
        unknown7: frame.unknown7,
        unknownPayload: Buffer.from(frame.payload)
      }
    };
  }

  /**
   * Dispatch one post-completion frame to an optional dialogue, and turn a
   * dialogue REFUSAL back into the observed-not-answered behaviour.
   *
   * The dialogues throw named `Tcp10127ProtocolError`s on malformed rows and
   * engine refusals, and until this method an escaped throw reached the
   * service's catch and DESTROYED the socket - which contradicts this state's
   * own stated policy (the observed-not-answered comment below the dispatch
   * sites): post-completion frames are evidence to keep, and killing the
   * connection suppresses exactly that evidence. Before the dialogues existed,
   * every one of these frames was observed-not-answered; a frame a dialogue
   * cannot accept falls back to that same behaviour, carrying the refusal code
   * so the journal says WHY instead of logging a generic unimplemented line.
   *
   * Only `Tcp10127ProtocolError` is absorbed - it is the dialogues' named
   * refusal vehicle. Anything else is a defect in this server and still
   * propagates.
   */
  #dispatchDialogue(dialogue, frame) {
    try {
      return dialogue.handleFrame(frame);
    } catch (error) {
      if (!(error instanceof Tcp10127ProtocolError)) throw error;
      return {
        response: null,
        state: this.#state,
        unimplemented: true,
        refusal: error.code,
        request: {
          command: frame.command,
          sequence: frame.sequence,
          unknown7: frame.unknown7,
          unknownPayload: Buffer.from(frame.payload)
        }
      };
    }
  }

  #handleLobbyInitialization(frame) {
    requireFrameInvariant(
      frame.direction === TCP10127_DIRECTION.CLIENT_REQUEST,
      'LOBBY_INIT_DIRECTION',
      '0x1007 lobby-initialization frame must be a client request'
    );
    requireFrameInvariant(
      frame.command === TCP10127_LOBBY_INITIALIZATION.command,
      'LOBBY_INIT_COMMAND',
      'first lobby-initialization command must be 0x1007'
    );
    requireFrameInvariant(
      frame.payloadLength === TCP10127_LOBBY_INITIALIZATION.requestPayloadLength,
      'LOBBY_INIT_LENGTH',
      'captured PAL 0x1007 request payload length is 49 bytes'
    );
    requireFrameInvariant(
      frame.error === 0,
      'LOBBY_INIT_STATUS',
      'captured PAL 0x1007 client request status is zero'
    );
    requireFrameInvariant(
      frame.unknown7 === TCP10127_LOBBY_INITIALIZATION.requestUnknown7,
      'LOBBY_INIT_UNKNOWN7',
      'SLES_533.19 request builder writes 0xff at header byte 7'
    );

    // The 49 opaque bytes are not entirely opaque after all: byte 0 is a lead
    // byte and bytes 1..48 are one FUN_001c3f40 field. Decoding it with codec
    // byte zero is self-validating, because FUN_001c3750's checksum has to
    // match. All four captured requests yield the same 44-character base64
    // string, which is the 32-byte DNAS token the same client also sends as
    // `?DNAS=` on its first HTTP request (R-020). That makes it the in-band
    // link between the authenticated HTTP session and this TCP connection, with
    // no reliance on the source address.
    //
    // A field that does not decode is left alone rather than guessed at: the
    // lead byte and the field's meaning for other client builds are still
    // Unknown, so an undecodable request is simply not associated.
    if (this.#associateDnasToken != null) {
      const identityField = frame.payload.subarray(
        TCP10127_LOBBY_INITIALIZATION.identityFieldOffset
      );
      const decoded = decodeSnapField({
        field: identityField,
        maximumDecodedLength: TCP10127_LOBBY_INITIALIZATION.identityFieldMaximumLength,
        sequence: frame.sequence,
        unknownCodecByte: TCP10127_LOBBY_INITIALIZATION.identityCodecByte
      });
      requireFrameInvariant(
        decoded != null,
        'LOBBY_INIT_IDENTITY_FIELD',
        '0x1007 identity field did not decode and checksum with the captured parameters'
      );
      try {
        this.#associateDnasToken({
          presentedToken: decoded.toString('latin1'),
          sequence: frame.sequence
        });
      } catch (error) {
        // Fail closed. An unassociable connection must not proceed to serve
        // anything, and must not silently continue as anonymous.
        throw new Tcp10127ProtocolError(
          error.code ?? 'LOBBY_INIT_SESSION_ASSOCIATION',
          `0x1007 could not be associated with an authenticated session: ${error.message}`
        );
      }
    }

    const response = encodeTcp10127Frame({
      direction: TCP10127_DIRECTION.SERVER_RESPONSE,
      command: TCP10127_LOBBY_INITIALIZATION.command,
      sequence: frame.sequence,
      error: 0,
      // Echo is capture/V1-runtime backed; the byte's meaning remains unknown.
      unknown7: frame.unknown7,
      payload: Buffer.from([TCP10127_LOBBY_INITIALIZATION.responseMode])
    });

    this.#state = TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_KEYED_MANIFEST_REQUEST;
    return {
      response,
      state: this.#state,
      unimplemented: false,
      request: {
        command: frame.command,
        sequence: frame.sequence,
        unknown7: frame.unknown7,
        unknownPayload: Buffer.from(frame.payload)
      }
    };
  }

  #handleKeyedManifest(frame) {
    requireFrameInvariant(
      frame.direction === TCP10127_DIRECTION.CLIENT_REQUEST,
      'KEYED_MANIFEST_DIRECTION',
      '0x6103 keyed-manifest frame must be a client request'
    );
    requireFrameInvariant(
      frame.command === TCP10127_KEYED_MANIFEST.command,
      'KEYED_MANIFEST_COMMAND',
      'command following 0x1007 must be the captured 0x6103 request'
    );
    requireFrameInvariant(
      frame.payloadLength === TCP10127_KEYED_MANIFEST.requestPayloadLength,
      'KEYED_MANIFEST_LENGTH',
      'FUN_001c5ea0 emits a payload-less 0x6103 request'
    );
    requireFrameInvariant(
      frame.error === 0,
      'KEYED_MANIFEST_STATUS',
      'captured PAL 0x6103 client request status is zero'
    );
    requireFrameInvariant(
      frame.unknown7 === TCP10127_KEYED_MANIFEST.requestUnknown7,
      'KEYED_MANIFEST_UNKNOWN7',
      'SLES_533.19 request builder writes 0xff at header byte 7'
    );

    const payload = Buffer.alloc(2);
    payload.writeUInt16BE(TCP10127_KEYED_MANIFEST.emptyCount, 0);
    const response = encodeTcp10127Frame({
      direction: TCP10127_DIRECTION.SERVER_RESPONSE,
      command: TCP10127_KEYED_MANIFEST.command,
      sequence: frame.sequence,
      error: 0,
      unknown7: frame.unknown7,
      payload
    });

    this.#state = TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6212;
    return {
      response,
      state: this.#state,
      unimplemented: false,
      request: {
        command: frame.command,
        sequence: frame.sequence,
        unknown7: frame.unknown7,
        unknownPayload: Buffer.from(frame.payload)
      }
    };
  }

  #handleCommand6212(frame) {
    requireFrameInvariant(
      frame.direction === TCP10127_DIRECTION.CLIENT_REQUEST,
      'COMMAND_6212_DIRECTION',
      'canonical 0x6212 frame must be a client request'
    );
    requireFrameInvariant(
      frame.command === TCP10127_COMMAND_6212.command,
      'COMMAND_6212_COMMAND',
      'command following the empty 0x6103 branch must be the observed 0x6212 request'
    );
    requireFrameInvariant(
      frame.payloadLength === TCP10127_COMMAND_6212.requestPayloadLength,
      'COMMAND_6212_LENGTH',
      'FUN_001c42d0 emits a payload-less canonical 0x6212 request'
    );
    requireFrameInvariant(
      frame.error === 0,
      'COMMAND_6212_STATUS',
      'captured PAL 0x6212 client request status is zero'
    );
    requireFrameInvariant(
      frame.unknown7 === TCP10127_COMMAND_6212.requestUnknown7,
      'COMMAND_6212_UNKNOWN7',
      'SLES_533.19 request builder writes 0xff at header byte 7'
    );

    if (this.#resolveCommand6212Value == null) {
      const response = encodeTcp10127Frame({
        direction: TCP10127_DIRECTION.SERVER_RESPONSE,
        command: TCP10127_COMMAND_6212.command,
        sequence: frame.sequence,
        error: TCP10127_COMMAND_6212.clientDefaultResponseError,
        unknown7: frame.unknown7,
        payload: Buffer.alloc(0)
      });
      this.#state = TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6203;
      return this.#handledResult(frame, response);
    }

    let value;
    try {
      value = this.#resolveCommand6212Value({
        command: frame.command,
        sequence: frame.sequence
      });
    } catch (error) {
      throw new Tcp10127ProtocolError(
        'COMMAND_6212_VALUE_PROVIDER',
        `0x6212 value provider failed: ${error.message}`
      );
    }
    requireFrameInvariant(
      value == null || typeof value.then !== 'function',
      'COMMAND_6212_VALUE_PROVIDER',
      'resolveCommand6212Value must be synchronous'
    );
    requireFrameInvariant(
      Number.isSafeInteger(value) && value >= 0 && value <= 0xffffffff,
      'COMMAND_6212_VALUE',
      '0x6212 response value must be an unsigned 32-bit integer'
    );

    const payload = Buffer.alloc(TCP10127_COMMAND_6212.responsePayloadLength);
    payload.writeUInt32BE(value, 0);
    const response = encodeTcp10127Frame({
      direction: TCP10127_DIRECTION.SERVER_RESPONSE,
      command: TCP10127_COMMAND_6212.command,
      sequence: frame.sequence,
      error: 0,
      unknown7: frame.unknown7,
      payload
    });

    this.#state =
      TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6203;
    return {
      response,
      state: this.#state,
      unimplemented: false,
      request: {
        command: frame.command,
        sequence: frame.sequence,
        unknown7: frame.unknown7,
        unknownPayload: Buffer.from(frame.payload)
      }
    };
  }

  #handleCommand6203(frame) {
    requireFrameInvariant(
      frame.direction === TCP10127_DIRECTION.CLIENT_REQUEST,
      'COMMAND_6203_DIRECTION',
      '0x6203 frame must be a client request'
    );
    requireFrameInvariant(
      frame.command === TCP10127_COMMAND_6203.command,
      'COMMAND_6203_COMMAND',
      'command following 0x6212 must be the observed 0x6203 request'
    );
    requireFrameInvariant(
      frame.payloadLength >= TCP10127_COMMAND_6203.requestMinimumPayloadLength,
      'COMMAND_6203_LENGTH',
      'FUN_001c3f40 emits at least two BE16 fields'
    );
    requireFrameInvariant(
      frame.payload.readUInt16BE(0) === frame.payloadLength - 2,
      'COMMAND_6203_ENVELOPE',
      'FUN_001c3f40 writes encoded-field length equal to payload length minus two'
    );
    requireFrameInvariant(
      frame.error === 0,
      'COMMAND_6203_STATUS',
      'captured PAL 0x6203 client request status is zero'
    );
    requireFrameInvariant(
      frame.unknown7 === TCP10127_COMMAND_6203.requestUnknown7,
      'COMMAND_6203_UNKNOWN7',
      'SLES_533.19 request builder writes 0xff at header byte 7'
    );

    /*
     * The request's single field is the client's CACHED version string, the
     * `0x36842c` copy `FUN_001c4960.c:46` compares against. It is decoded for the
     * record and for diagnostics only: the decision to skip belongs to the
     * client, and V2 always sends the full declaration so that either branch of
     * `FUN_001c4960` has what it needs. The captured requests carry a zero-length
     * field (`000253d3` at sequence 0xd3 is the empty field's checksum), which is
     * a client that has cached nothing.
     */
    const cachedVersion = decodeSnapField({
      field: frame.payload,
      maximumDecodedLength: TCP10127_COMMAND_6203.maximumVersionLength,
      sequence: frame.sequence,
      unknownCodecByte: this.#codecByte
    });

    const chunkLengths = this.#areaTable.chunkLengths();
    requireFrameInvariant(
      Array.isArray(chunkLengths) &&
        chunkLengths.length >= TCP10127_COMMAND_6203.minimumChunkCount &&
        chunkLengths.length <= TCP10127_COMMAND_6203.maximumChunkCount,
      'COMMAND_6203_CHUNK_COUNT',
      'the area table must declare 1..2 chunks; FUN_001c4960 treats 0 as terminal and clamps ' +
        'anything above 2, which would desynchronise the transfer'
    );
    for (const length of chunkLengths) {
      requireFrameInvariant(
        Number.isSafeInteger(length) && length > 0 &&
          length <= TCP10127_COMMAND_6203.maximumChunkLength,
        'COMMAND_6203_CHUNK_LENGTH',
        `an area chunk of ${length} bytes is outside the 1..` +
          `${TCP10127_COMMAND_6203.maximumChunkLength} FUN_001c4960 accepts`
      );
    }

    const declaration = Buffer.alloc(2 + chunkLengths.length * 4);
    declaration.writeUInt16BE(chunkLengths.length, 0);
    chunkLengths.forEach((length, index) => declaration.writeUInt32BE(length, 2 + index * 4));
    const response = encodeTcp10127Frame({
      direction: TCP10127_DIRECTION.SERVER_RESPONSE,
      command: TCP10127_COMMAND_6203.command,
      sequence: frame.sequence,
      error: 0,
      unknown7: frame.unknown7,
      payload: Buffer.concat([
        Buffer.from([TCP10127_COMMAND_6203.responseMode]),
        encodeSnapField({
          plain: this.#areaTable.version,
          maximumDecodedLength: TCP10127_COMMAND_6203.maximumVersionLength,
          sequence: frame.sequence,
          unknownCodecByte: this.#codecByte
        }),
        declaration
      ])
    });

    // FUN_001c4960.c:93-95 zeroes the client's chunk index and offset on every
    // mode-1 reply, including the re-fetch reached from 0x6510. Mirror it, or a
    // second transfer would be validated against the first one's cursor.
    this.#areaChunkIndex = 0;
    this.#areaOffset = 0;
    this.#areaChunkLengths = [...chunkLengths];
    this.#state = TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6204;
    return {
      response,
      state: this.#state,
      unimplemented: false,
      request: {
        command: frame.command,
        sequence: frame.sequence,
        unknown7: frame.unknown7,
        unknownPayload: Buffer.from(frame.payload),
        // null when the field will not decode under this connection's codec word.
        // Not fatal: nothing is decided from it.
        cachedAreaTableVersion: cachedVersion
      }
    };
  }

  /**
   * One `0x6204` slice of the area blob.
   *
   * The request is validated against this session's PREDICTION of the client's
   * `bRam00368421` / `uRam00368424`, which is the same pair `FUN_001c4d40.c:28-30`
   * checks the reply against. Both sides holding the same cursor is the whole
   * correctness condition of the transfer, so a mismatch is a named failure, not
   * something to serve past.
   */
  #handleCommand6204(frame) {
    requireFrameInvariant(
      frame.direction === TCP10127_DIRECTION.CLIENT_REQUEST,
      'COMMAND_6204_DIRECTION',
      '0x6204 frame must be a client request'
    );
    requireFrameInvariant(
      frame.command === TCP10127_COMMAND_6204.command,
      'COMMAND_6204_COMMAND',
      'the area-blob transfer must use 0x6204'
    );
    requireFrameInvariant(
      frame.payloadLength === TCP10127_COMMAND_6204.requestPayloadLength,
      'COMMAND_6204_LENGTH',
      'FUN_001c4c80 appends one BE16, one BE32 and one BE16 to 0x6204'
    );
    requireFrameInvariant(
      frame.error === 0,
      'COMMAND_6204_STATUS',
      'only the decoded normal-status 0x6204 path is implemented'
    );
    requireFrameInvariant(
      frame.unknown7 === TCP10127_COMMAND_6204.requestUnknown7,
      'COMMAND_6204_UNKNOWN7',
      'SLES_533.19 request builder writes 0xff at header byte 7'
    );

    const chunkIndex = frame.payload.readUInt16BE(0);
    const offset = frame.payload.readUInt32BE(2);
    const requestedLength = frame.payload.readUInt16BE(6);
    requireFrameInvariant(
      requestedLength === TCP10127_COMMAND_6204.requestSliceLength,
      'COMMAND_6204_SLICE_LENGTH',
      `FUN_001c4c80.c:11 writes the literal 0x${
        TCP10127_COMMAND_6204.requestSliceLength.toString(16)} as the request length word`
    );
    requireFrameInvariant(
      this.#areaChunkLengths.length > 0,
      'COMMAND_6204_NO_DECLARATION',
      '0x6204 arrived with no chunk table declared; only a mode-1 0x6203 reply declares one'
    );
    requireFrameInvariant(
      chunkIndex === this.#areaChunkIndex && offset === this.#areaOffset,
      'COMMAND_6204_CURSOR',
      `0x6204 asked for chunk ${chunkIndex} offset ${offset}; this connection has delivered up ` +
        `to chunk ${this.#areaChunkIndex} offset ${this.#areaOffset}. Either the client diverged ` +
        'or this prediction of its cursor is wrong'
    );

    let slice;
    try {
      slice = this.#areaTable.sliceAt({ chunkIndex, offset });
    } catch (error) {
      throw new Tcp10127ProtocolError(
        error.code ?? 'COMMAND_6204_AREA_TABLE',
        `0x6204 could not be served from the area table: ${error.message}`
      );
    }
    requireFrameInvariant(
      slice.data.length > 0 && slice.data.length <= TCP10127_COMMAND_6204.maximumSliceLength,
      'COMMAND_6204_SLICE_LENGTH',
      'FUN_001c4d40.c:41 bounds the decode to 0x2f2, or to the chunk remainder on the last slice'
    );

    const header = Buffer.alloc(6);
    header.writeUInt16BE(chunkIndex, 0);
    header.writeUInt32BE(offset, 2);
    const response = encodeTcp10127Frame({
      direction: TCP10127_DIRECTION.SERVER_RESPONSE,
      command: TCP10127_COMMAND_6204.command,
      sequence: frame.sequence,
      error: 0,
      unknown7: frame.unknown7,
      payload: Buffer.concat([
        header,
        encodeSnapField({
          plain: slice.data,
          maximumDecodedLength: TCP10127_COMMAND_6204.maximumSliceLength,
          sequence: frame.sequence,
          unknownCodecByte: this.#codecByte
        })
      ])
    });

    /*
     * Advance exactly as FUN_001c4d40.c:31-51 does. The cursor steps by the fixed
     * 0x2f2 whatever the slice carried; when it reaches or passes the chunk's
     * declared length the chunk is finished, the offset resets and the chunk
     * index increments; when the chunks are exhausted the client caches the
     * version and takes substate 0x14, whose scheduler emits 0x6211. V1's
     * session 5 shows exactly that - RAW-OUT #13 is followed by the 0x6211.
     */
    const nextOffset = offset + TCP10127_COMMAND_6204.requestSliceLength;
    if (nextOffset < this.#areaChunkLengths[chunkIndex]) {
      this.#areaOffset = nextOffset;
      this.#state = TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_MORE_COMMAND_6204;
    } else {
      this.#areaChunkIndex = chunkIndex + 1;
      this.#areaOffset = 0;
      this.#state = this.#areaChunkIndex < this.#areaChunkLengths.length
        ? TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_MORE_COMMAND_6204
        : TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6211;
    }
    return this.#handledResult(frame, response);
  }

  #handleCommand6211(frame) {
    requireFrameInvariant(
      frame.direction === TCP10127_DIRECTION.CLIENT_REQUEST,
      'COMMAND_6211_DIRECTION',
      'canonical 0x6211 frame must be a client request'
    );
    requireFrameInvariant(
      frame.command === TCP10127_COMMAND_6211.command,
      'COMMAND_6211_COMMAND',
      'command following 0x6203 mode 2 must be the observed 0x6211 request'
    );
    requireFrameInvariant(
      frame.payloadLength === TCP10127_COMMAND_6211.requestPayloadLength,
      'COMMAND_6211_LENGTH',
      'FUN_001c4560 emits a payload-less canonical 0x6211 request'
    );
    requireFrameInvariant(
      frame.error === 0,
      'COMMAND_6211_STATUS',
      'captured PAL 0x6211 client request status is zero'
    );
    requireFrameInvariant(
      frame.unknown7 === TCP10127_COMMAND_6211.requestUnknown7,
      'COMMAND_6211_UNKNOWN7',
      'SLES_533.19 request builder writes 0xff at header byte 7'
    );

    if (this.#resolveCommand6211Value == null) {
      const response = encodeTcp10127Frame({
        direction: TCP10127_DIRECTION.SERVER_RESPONSE,
        command: TCP10127_COMMAND_6211.command,
        sequence: frame.sequence,
        error: TCP10127_COMMAND_6211.clientDefaultResponseError,
        unknown7: frame.unknown7,
        payload: Buffer.alloc(0)
      });
      this.#state = TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6213;
      return this.#handledResult(frame, response);
    }

    let value;
    try {
      value = this.#resolveCommand6211Value({
        command: frame.command,
        sequence: frame.sequence
      });
    } catch (error) {
      throw new Tcp10127ProtocolError(
        'COMMAND_6211_VALUE_PROVIDER',
        `0x6211 value provider failed: ${error.message}`
      );
    }
    requireFrameInvariant(
      value == null || typeof value.then !== 'function',
      'COMMAND_6211_VALUE_PROVIDER',
      'resolveCommand6211Value must be synchronous'
    );
    requireFrameInvariant(
      Number.isSafeInteger(value) && value >= 0 && value <= 0xffffffff,
      'COMMAND_6211_VALUE',
      '0x6211 response value must be an unsigned 32-bit integer'
    );

    const payload = Buffer.alloc(TCP10127_COMMAND_6211.responsePayloadLength);
    payload.writeUInt32BE(value, 0);
    const response = encodeTcp10127Frame({
      direction: TCP10127_DIRECTION.SERVER_RESPONSE,
      command: TCP10127_COMMAND_6211.command,
      sequence: frame.sequence,
      error: 0,
      unknown7: frame.unknown7,
      payload
    });

    this.#state = TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6213;
    return {
      response,
      state: this.#state,
      unimplemented: false,
      request: {
        command: frame.command,
        sequence: frame.sequence,
        unknown7: frame.unknown7,
        unknownPayload: Buffer.from(frame.payload)
      }
    };
  }

  #handleCommand6213(frame) {
    requireFrameInvariant(
      frame.direction === TCP10127_DIRECTION.CLIENT_REQUEST,
      'COMMAND_6213_DIRECTION',
      'canonical 0x6213 frame must be a client request'
    );
    requireFrameInvariant(
      frame.command === TCP10127_COMMAND_6213.command,
      'COMMAND_6213_COMMAND',
      'command following 0x6211 must be the observed 0x6213 request'
    );
    requireFrameInvariant(
      frame.payloadLength === TCP10127_COMMAND_6213.requestPayloadLength,
      'COMMAND_6213_LENGTH',
      'FUN_001c43c0 emits a payload-less canonical 0x6213 request'
    );
    requireFrameInvariant(
      frame.error === 0,
      'COMMAND_6213_STATUS',
      'captured PAL 0x6213 client request status is zero'
    );
    requireFrameInvariant(
      frame.unknown7 === TCP10127_COMMAND_6213.requestUnknown7,
      'COMMAND_6213_UNKNOWN7',
      'SLES_533.19 request builder writes 0xff at header byte 7'
    );

    if (this.#resolveCommand6213Words == null) {
      const response = encodeTcp10127Frame({
        direction: TCP10127_DIRECTION.SERVER_RESPONSE,
        command: TCP10127_COMMAND_6213.command,
        sequence: frame.sequence,
        error: TCP10127_COMMAND_6213.clientDefaultResponseError,
        unknown7: frame.unknown7,
        payload: Buffer.alloc(0)
      });
      this.#state = TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6501;
      return this.#handledResult(frame, response);
    }

    let words;
    try {
      words = this.#resolveCommand6213Words({
        command: frame.command,
        sequence: frame.sequence
      });
    } catch (error) {
      throw new Tcp10127ProtocolError(
        'COMMAND_6213_WORDS_PROVIDER',
        `0x6213 words provider failed: ${error.message}`
      );
    }
    requireFrameInvariant(
      words == null || typeof words.then !== 'function',
      'COMMAND_6213_WORDS_PROVIDER',
      'resolveCommand6213Words must be synchronous'
    );
    requireFrameInvariant(
      Array.isArray(words) && words.length === TCP10127_COMMAND_6213.responseWordCount,
      'COMMAND_6213_WORDS_SHAPE',
      '0x6213 response provider must return exactly eight words'
    );
    for (let index = 0; index < words.length; index += 1) {
      requireFrameInvariant(
        Number.isSafeInteger(words[index]) && words[index] >= 0 && words[index] <= 0xffff,
        'COMMAND_6213_WORD_VALUE',
        `0x6213 response word ${index} must be an unsigned 16-bit integer`
      );
    }

    const payload = Buffer.alloc(TCP10127_COMMAND_6213.responsePayloadLength);
    for (let index = 0; index < words.length; index += 1) {
      payload.writeUInt16BE(words[index], index * 2);
    }
    const response = encodeTcp10127Frame({
      direction: TCP10127_DIRECTION.SERVER_RESPONSE,
      command: TCP10127_COMMAND_6213.command,
      sequence: frame.sequence,
      error: 0,
      unknown7: frame.unknown7,
      payload
    });

    this.#state = TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6501;
    return {
      response,
      state: this.#state,
      unimplemented: false,
      request: {
        command: frame.command,
        sequence: frame.sequence,
        unknown7: frame.unknown7,
        unknownPayload: Buffer.from(frame.payload)
      }
    };
  }

  /**
   * Frame-level invariants for a `0x6501` client request. Extracted so the
   * RESUME entry can validate BEFORE it binds a session - binding on an
   * unvalidated frame let a malformed one claim a live session.
   */
  #assertCommand6501Frame(frame) {
    requireFrameInvariant(
      frame.direction === TCP10127_DIRECTION.CLIENT_REQUEST,
      'COMMAND_6501_DIRECTION',
      '0x6501 frame must be a client request'
    );
    requireFrameInvariant(
      frame.command === TCP10127_COMMAND_6501.command,
      'COMMAND_6501_COMMAND',
      'command following 0x6213 must be 0x6501'
    );
    requireFrameInvariant(
      frame.payloadLength === TCP10127_COMMAND_6501.requestPayloadLength,
      'COMMAND_6501_LENGTH',
      'FUN_001c6dc0 appends exactly one BE32 to 0x6501'
    );
    requireFrameInvariant(
      frame.error === 0,
      'COMMAND_6501_STATUS',
      'captured PAL 0x6501 client request status is zero'
    );
    requireFrameInvariant(
      frame.unknown7 === TCP10127_COMMAND_6501.requestUnknown7,
      'COMMAND_6501_UNKNOWN7',
      'SLES_533.19 request builder writes 0xff at header byte 7'
    );
  }

  #handleCommand6501(frame) {
    this.#assertCommand6501Frame(frame);
    requireFrameInvariant(
      typeof this.#resolveCommand6501Response === 'function',
      'COMMAND_6501_RESPONSE_PROVIDER',
      'resolveCommand6501Response is required before handling 0x6501'
    );

    const unknownRequestValue = frame.payload.readUInt32BE(0);
    let selection;
    try {
      selection = this.#resolveCommand6501Response({
        command: frame.command,
        sequence: frame.sequence,
        unknownRequestValue,
        /*
         * THE ENTRY PATH, reported rather than re-derived. FUN_001c6e80 routes
         * mode 1 to phase 6 (0x6503) regardless of the connection's own state
         * word, and mode 0 to phase 0x0c (0x6510) when that word is 5 and to
         * phase 8 (0x6502) otherwise. The server never observes that word, so
         * the only thing it can discriminate on is whether this connection
         * presented 0x1007 - which is exactly what #resumed already records.
         * The mode POLICY is the provider's; this is the fact it needs.
         */
        resumed: this.#resumed
      });
    } catch (error) {
      throw new Tcp10127ProtocolError(
        'COMMAND_6501_RESPONSE_PROVIDER',
        `0x6501 response provider failed: ${error.message}`
      );
    }
    requireFrameInvariant(
      selection == null || typeof selection.then !== 'function',
      'COMMAND_6501_RESPONSE_PROVIDER',
      'resolveCommand6501Response must be synchronous'
    );
    requireFrameInvariant(
      selection != null && typeof selection === 'object' && !Array.isArray(selection),
      'COMMAND_6501_RESPONSE_SHAPE',
      '0x6501 response provider must return a tagged object'
    );

    let payload;
    if (selection.mode === TCP10127_COMMAND_6501.mode0) {
      requireFrameInvariant(
        Object.keys(selection).length === 1,
        'COMMAND_6501_RESPONSE_SHAPE',
        '0x6501 mode 0 response accepts only the mode field'
      );
      payload = Buffer.from([TCP10127_COMMAND_6501.mode0]);
      this.#state =
        TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_POST_COMMAND_6501_MODE_0;
    } else if (selection.mode === TCP10127_COMMAND_6501.mode1) {
      requireFrameInvariant(
        Object.keys(selection).length === 3 &&
          Object.hasOwn(selection, 'unknown0') && Object.hasOwn(selection, 'unknown1'),
        'COMMAND_6501_RESPONSE_SHAPE',
        '0x6501 mode 1 response requires exactly unknown0 and unknown1'
      );
      for (const field of ['unknown0', 'unknown1']) {
        requireFrameInvariant(
          Number.isSafeInteger(selection[field]) &&
            selection[field] >= 0 && selection[field] <= 0xffffffff,
          'COMMAND_6501_RESPONSE_VALUE',
          `0x6501 mode 1 ${field} must be an unsigned 32-bit integer`
        );
      }
      payload = Buffer.alloc(TCP10127_COMMAND_6501.mode1ResponsePayloadLength);
      payload[0] = TCP10127_COMMAND_6501.mode1;
      payload.writeUInt32BE(selection.unknown0, 1);
      payload.writeUInt32BE(selection.unknown1, 5);
      this.#state = TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6503;
    } else {
      throw new Tcp10127ProtocolError(
        'COMMAND_6501_RESPONSE_MODE',
        '0x6501 response mode must be 0 or 1'
      );
    }

    const response = encodeTcp10127Frame({
      direction: TCP10127_DIRECTION.SERVER_RESPONSE,
      command: TCP10127_COMMAND_6501.command,
      sequence: frame.sequence,
      error: 0,
      unknown7: frame.unknown7,
      payload
    });
    return this.#handledResult(frame, response);
  }

  /**
   * `0x6503` - the server-entry list batch.
   *
   * The reply carries the server's own `total` and `batchStart`; the client
   * takes both verbatim (`0x365e1e`, `0x365e18`) and then adds the batch count.
   * So `batchStart` is not decoration: it is what decides whether the client
   * asks for another batch or moves on to `0x6502`, and the two must agree or
   * the walk either stalls or skips entries.
   *
   * The batch is bounded to the count the client asked for. `FUN_001c70b0` does
   * not compare the batch count with the requested count, so a larger reply
   * would be parsed - into `(0x365e0c + i)`, past the window the client sized -
   * but nothing proves its receive buffer would hold it, and the provider is
   * the right place to decide what a window contains.
   */
  #handleCommand6503(frame) {
    requireFrameInvariant(
      frame.direction === TCP10127_DIRECTION.CLIENT_REQUEST,
      'COMMAND_6503_DIRECTION',
      '0x6503 frame must be a client request'
    );
    requireFrameInvariant(
      frame.command === TCP10127_COMMAND_6503.command,
      'COMMAND_6503_COMMAND',
      'the mode-1 entry-list walk must use 0x6503'
    );
    requireFrameInvariant(
      frame.payloadLength === TCP10127_COMMAND_6503.requestPayloadLength,
      'COMMAND_6503_LENGTH',
      'FUN_001c7000 appends exactly two BE16 values to 0x6503'
    );
    requireFrameInvariant(
      frame.error === 0,
      'COMMAND_6503_STATUS',
      'only the decoded normal-status 0x6503 path is implemented'
    );
    requireFrameInvariant(
      frame.unknown7 === TCP10127_COMMAND_6503.requestUnknown7,
      'COMMAND_6503_UNKNOWN7',
      'SLES_533.19 request builder writes 0xff at header byte 7'
    );
    requireFrameInvariant(
      typeof this.#resolveCommand6503Response === 'function',
      'COMMAND_6503_RESPONSE_PROVIDER',
      'resolveCommand6503Response is required before handling 0x6503'
    );

    const requestedStart = frame.payload.readUInt16BE(0);
    const requestedCount = frame.payload.readUInt16BE(2);
    let selection;
    try {
      selection = this.#resolveCommand6503Response({
        command: frame.command,
        sequence: frame.sequence,
        requestedStart,
        requestedCount
      });
    } catch (error) {
      throw new Tcp10127ProtocolError(
        'COMMAND_6503_RESPONSE_PROVIDER',
        `0x6503 response provider failed: ${error.message}`
      );
    }
    requireFrameInvariant(
      selection == null || typeof selection.then !== 'function',
      'COMMAND_6503_RESPONSE_PROVIDER',
      'resolveCommand6503Response must be synchronous'
    );
    requireFrameInvariant(
      selection != null && typeof selection === 'object' && !Array.isArray(selection),
      'COMMAND_6503_RESPONSE_SHAPE',
      '0x6503 response provider must return an object'
    );
    requireFrameInvariant(
      Object.keys(selection).length === 4 &&
        Object.hasOwn(selection, 'total') &&
        Object.hasOwn(selection, 'batchStart') &&
        Object.hasOwn(selection, 'unknownCodecByte') &&
        Object.hasOwn(selection, 'entries'),
      'COMMAND_6503_RESPONSE_SHAPE',
      '0x6503 response requires only total, batchStart, unknownCodecByte, and entries'
    );
    requireFrameInvariant(
      Number.isSafeInteger(selection.unknownCodecByte) &&
        selection.unknownCodecByte >= 0 && selection.unknownCodecByte <= 0xff,
      'COMMAND_6503_RESPONSE_CODEC_BYTE',
      '0x6503 unknownCodecByte must be an unsigned byte'
    );
    requireFrameInvariant(
      Number.isSafeInteger(selection.total) &&
        selection.total >= TCP10127_COMMAND_6503.minimumTotal &&
        selection.total <= TCP10127_COMMAND_6503.maximumTotal,
      'COMMAND_6503_RESPONSE_TOTAL',
      '0x6503 total must be 1..16; PAL treats zero as terminal and clamps larger values'
    );
    requireFrameInvariant(
      Number.isSafeInteger(selection.batchStart) &&
        selection.batchStart >= 0 && selection.batchStart <= 0xffff,
      'COMMAND_6503_RESPONSE_START',
      '0x6503 batchStart must be an unsigned 16-bit integer'
    );
    requireFrameInvariant(
      Array.isArray(selection.entries) && selection.entries.length > 0,
      'COMMAND_6503_RESPONSE_ENTRIES',
      'an empty 0x6503 batch would stall the walk with no way for the client to advance'
    );
    requireFrameInvariant(
      selection.entries.length <= 0xff &&
        selection.batchStart + selection.entries.length <= selection.total,
      'COMMAND_6503_RESPONSE_RANGE',
      '0x6503 batch must remain within its server-declared total'
    );

    const parts = [Buffer.alloc(5)];
    parts[0].writeUInt16BE(selection.total, 0);
    parts[0].writeUInt16BE(selection.batchStart, 2);
    parts[0][4] = selection.entries.length;
    for (const entry of selection.entries) {
      requireFrameInvariant(
        entry != null && typeof entry === 'object' && !Array.isArray(entry) &&
          Object.keys(entry).length === 4 &&
          Object.hasOwn(entry, 'host') &&
          Object.hasOwn(entry, 'name') &&
          Object.hasOwn(entry, 'raw8') &&
          Object.hasOwn(entry, 'description'),
        'COMMAND_6503_RESPONSE_ENTRY_SHAPE',
        '0x6503 entries require exactly the four parser-consumed fields'
      );
      for (const field of ['host', 'name', 'raw8', 'description']) {
        requireFrameInvariant(
          Buffer.isBuffer(entry[field]),
          'COMMAND_6503_RESPONSE_ENTRY_BUFFER',
          `0x6503 ${field} must be a Buffer`
        );
      }
      requireFrameInvariant(
        entry.host.length <= TCP10127_COMMAND_6503.maximumHostLength &&
          entry.name.length <= TCP10127_COMMAND_6503.maximumNameLength &&
          entry.description.length <= TCP10127_COMMAND_6503.maximumDescriptionLength,
        'COMMAND_6503_RESPONSE_ENTRY_LENGTH',
        '0x6503 encoded fields exceed PAL parser destination bounds'
      );
      requireFrameInvariant(
        entry.raw8.length === TCP10127_COMMAND_6503.rawFieldLength,
        'COMMAND_6503_RESPONSE_ENTRY_LENGTH',
        '0x6503 raw8 must contain exactly eight bytes'
      );

      parts.push(encodeSnapField({
        plain: entry.host,
        maximumDecodedLength: TCP10127_COMMAND_6503.maximumHostLength,
        sequence: frame.sequence,
        unknownCodecByte: selection.unknownCodecByte
      }));
      parts.push(encodeSnapField({
        plain: entry.name,
        maximumDecodedLength: TCP10127_COMMAND_6503.maximumNameLength,
        sequence: frame.sequence,
        unknownCodecByte: selection.unknownCodecByte
      }));
      parts.push(Buffer.from(entry.raw8));
      parts.push(encodeSnapField({
        plain: entry.description,
        maximumDecodedLength: TCP10127_COMMAND_6503.maximumDescriptionLength,
        sequence: frame.sequence,
        unknownCodecByte: selection.unknownCodecByte
      }));
    }

    const progress = selection.batchStart + selection.entries.length;
    this.#state = progress < selection.total
      ? TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_MORE_COMMAND_6503
      : TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_POST_COMMAND_6503_COMPLETE;
    const response = encodeTcp10127Frame({
      direction: TCP10127_DIRECTION.SERVER_RESPONSE,
      command: TCP10127_COMMAND_6503.command,
      sequence: frame.sequence,
      error: 0,
      unknown7: frame.unknown7,
      payload: Buffer.concat(parts)
    });
    return this.#handledResult(frame, response);
  }

  #handleCommand6502(frame) {
    requireFrameInvariant(
      frame.direction === TCP10127_DIRECTION.CLIENT_REQUEST,
      'COMMAND_6502_DIRECTION',
      '0x6502 frame must be a client request'
    );
    requireFrameInvariant(
      frame.command === TCP10127_COMMAND_6502.command,
      'COMMAND_6502_COMMAND',
      'mode-0 list walk must use 0x6502'
    );
    requireFrameInvariant(
      frame.payloadLength >= TCP10127_COMMAND_6502.requestMinimumPayloadLength,
      'COMMAND_6502_LENGTH',
      'FUN_001c7580 appends one BE32 and one dynamic field'
    );
    requireFrameInvariant(
      frame.payload.readUInt16BE(4) === frame.payloadLength - 6,
      'COMMAND_6502_ENVELOPE',
      'FUN_001c4020 dynamic field length must match the remaining payload'
    );
    requireFrameInvariant(
      frame.error === 0,
      'COMMAND_6502_STATUS',
      'captured PAL 0x6502 client request status is zero'
    );
    requireFrameInvariant(
      frame.unknown7 === TCP10127_COMMAND_6502.requestUnknown7,
      'COMMAND_6502_UNKNOWN7',
      'SLES_533.19 request builder writes 0xff at header byte 7'
    );
    requireFrameInvariant(
      typeof this.#resolveCommand6502Response === 'function',
      'COMMAND_6502_RESPONSE_PROVIDER',
      'resolveCommand6502Response is required before handling 0x6502'
    );

    let selection;
    try {
      selection = this.#resolveCommand6502Response({
        command: frame.command,
        sequence: frame.sequence,
        unknownRequestValue: frame.payload.readUInt32BE(0),
        unknownEncodedField: Buffer.from(frame.payload.subarray(4))
      });
    } catch (error) {
      throw new Tcp10127ProtocolError(
        'COMMAND_6502_RESPONSE_PROVIDER',
        `0x6502 response provider failed: ${error.message}`
      );
    }
    requireFrameInvariant(
      selection == null || typeof selection.then !== 'function',
      'COMMAND_6502_RESPONSE_PROVIDER',
      'resolveCommand6502Response must be synchronous'
    );
    requireFrameInvariant(
      selection != null && typeof selection === 'object' && !Array.isArray(selection),
      'COMMAND_6502_RESPONSE_SHAPE',
      '0x6502 response provider must return a tagged object'
    );

    let payload;
    if (selection.mode === TCP10127_COMMAND_6502.mode0) {
      requireFrameInvariant(
        Object.keys(selection).length === 1,
        'COMMAND_6502_RESPONSE_SHAPE',
        '0x6502 mode 0 response accepts only the mode field'
      );
      payload = Buffer.from([TCP10127_COMMAND_6502.mode0]);
      this.#state =
        TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_POST_COMMAND_6502_MODE_0;
    } else if (selection.mode === TCP10127_COMMAND_6502.mode1) {
      requireFrameInvariant(
        Object.keys(selection).length === 3 &&
          Object.hasOwn(selection, 'unknown0') && Object.hasOwn(selection, 'unknown1'),
        'COMMAND_6502_RESPONSE_SHAPE',
        '0x6502 mode 1 response requires exactly unknown0 and unknown1'
      );
      for (const field of ['unknown0', 'unknown1']) {
        requireFrameInvariant(
          Number.isSafeInteger(selection[field]) &&
            selection[field] >= 0 && selection[field] <= 0xffffffff,
          'COMMAND_6502_RESPONSE_VALUE',
          `0x6502 mode 1 ${field} must be an unsigned 32-bit integer`
        );
      }
      payload = Buffer.alloc(TCP10127_COMMAND_6502.mode1ResponsePayloadLength);
      payload[0] = TCP10127_COMMAND_6502.mode1;
      payload.writeUInt32BE(selection.unknown0, 1);
      payload.writeUInt32BE(selection.unknown1, 5);
      this.#state = TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_COMMAND_6504;
    } else {
      throw new Tcp10127ProtocolError(
        'COMMAND_6502_RESPONSE_MODE',
        '0x6502 normal response mode must be 0 or 1'
      );
    }

    const response = encodeTcp10127Frame({
      direction: TCP10127_DIRECTION.SERVER_RESPONSE,
      command: TCP10127_COMMAND_6502.command,
      sequence: frame.sequence,
      error: 0,
      unknown7: frame.unknown7,
      payload
    });
    return this.#handledResult(frame, response);
  }

  #handleCommand6504(frame) {
    requireFrameInvariant(
      frame.direction === TCP10127_DIRECTION.CLIENT_REQUEST,
      'COMMAND_6504_DIRECTION',
      '0x6504 frame must be a client request'
    );
    requireFrameInvariant(
      frame.command === TCP10127_COMMAND_6504.command,
      'COMMAND_6504_COMMAND',
      '0x6504 record-batch request must use command 0x6504'
    );
    requireFrameInvariant(
      frame.payloadLength >= TCP10127_COMMAND_6504.requestMinimumPayloadLength,
      'COMMAND_6504_LENGTH',
      'FUN_001c7980 appends two BE16 values and one dynamic field'
    );
    requireFrameInvariant(
      frame.payload.readUInt16BE(4) === frame.payloadLength - 6,
      'COMMAND_6504_ENVELOPE',
      'FUN_001c4020 dynamic field must consume the remainder of the request'
    );
    requireFrameInvariant(
      frame.error === 0,
      'COMMAND_6504_STATUS',
      'only the decoded normal-status 0x6504 path is implemented'
    );
    requireFrameInvariant(
      frame.unknown7 === TCP10127_COMMAND_6504.requestUnknown7,
      'COMMAND_6504_UNKNOWN7',
      'SLES_533.19 request builder writes 0xff at header byte 7'
    );
    requireFrameInvariant(
      typeof this.#resolveCommand6504Response === 'function',
      'COMMAND_6504_RESPONSE_PROVIDER',
      'resolveCommand6504Response is required before handling 0x6504'
    );

    let selection;
    try {
      selection = this.#resolveCommand6504Response({
        command: frame.command,
        sequence: frame.sequence,
        unknownRequestWord0: frame.payload.readUInt16BE(0),
        unknownRequestWord1: frame.payload.readUInt16BE(2),
        unknownEncodedField: Buffer.from(frame.payload.subarray(4))
      });
    } catch (error) {
      throw new Tcp10127ProtocolError(
        'COMMAND_6504_RESPONSE_PROVIDER',
        `0x6504 response provider failed: ${error.message}`
      );
    }
    requireFrameInvariant(
      selection == null || typeof selection.then !== 'function',
      'COMMAND_6504_RESPONSE_PROVIDER',
      'resolveCommand6504Response must be synchronous'
    );
    requireFrameInvariant(
      selection != null && typeof selection === 'object' && !Array.isArray(selection),
      'COMMAND_6504_RESPONSE_SHAPE',
      '0x6504 response provider must return an object'
    );
    requireFrameInvariant(
      Object.keys(selection).length === 4 &&
        Object.hasOwn(selection, 'unknownTotal') &&
        Object.hasOwn(selection, 'unknownStart') &&
        Object.hasOwn(selection, 'unknownCodecByte') &&
        Object.hasOwn(selection, 'records'),
      'COMMAND_6504_RESPONSE_SHAPE',
      '0x6504 response requires only unknownTotal, unknownStart, unknownCodecByte, and records'
    );
    requireFrameInvariant(
      Number.isSafeInteger(selection.unknownTotal) &&
        selection.unknownTotal >= 1 &&
        selection.unknownTotal <= TCP10127_COMMAND_6504.maximumUnknownTotal,
      'COMMAND_6504_RESPONSE_TOTAL',
      '0x6504 unknownTotal must be 1..64; PAL rejects zero and clamps larger values'
    );
    requireFrameInvariant(
      Number.isSafeInteger(selection.unknownStart) &&
        selection.unknownStart >= 0 && selection.unknownStart <= 0xffff,
      'COMMAND_6504_RESPONSE_START',
      '0x6504 unknownStart must be an unsigned 16-bit integer'
    );
    requireFrameInvariant(
      Number.isSafeInteger(selection.unknownCodecByte) &&
        selection.unknownCodecByte >= 0 && selection.unknownCodecByte <= 0xff,
      'COMMAND_6504_RESPONSE_CODEC_BYTE',
      '0x6504 unknownCodecByte must be an unsigned byte'
    );
    requireFrameInvariant(
      Array.isArray(selection.records) && selection.records.length > 0,
      'COMMAND_6504_RESPONSE_RECORDS',
      'V2 requires a nonempty 0x6504 batch to make progress'
    );
    requireFrameInvariant(
      selection.records.length <= 0xff &&
        selection.unknownStart + selection.records.length <= selection.unknownTotal,
      'COMMAND_6504_RESPONSE_RANGE',
      '0x6504 batch must remain within its server-declared range'
    );

    const parts = [Buffer.alloc(5)];
    parts[0].writeUInt16BE(selection.unknownTotal, 0);
    parts[0].writeUInt16BE(selection.unknownStart, 2);
    parts[0][4] = selection.records.length;
    for (const record of selection.records) {
      requireFrameInvariant(
        record != null && typeof record === 'object' && !Array.isArray(record) &&
          Object.keys(record).length === 7 &&
          Object.hasOwn(record, 'unknownField0') &&
          Object.hasOwn(record, 'unknownField1') &&
          Object.hasOwn(record, 'unknownRaw8') &&
          Object.hasOwn(record, 'unknownField2') &&
          Object.hasOwn(record, 'unknownWord0') &&
          Object.hasOwn(record, 'unknownWord1') &&
          Object.hasOwn(record, 'unknownDword'),
        'COMMAND_6504_RESPONSE_RECORD_SHAPE',
        '0x6504 records require exactly the seven parser-consumed fields'
      );
      for (const field of ['unknownField0', 'unknownField1', 'unknownRaw8', 'unknownField2']) {
        requireFrameInvariant(
          Buffer.isBuffer(record[field]),
          'COMMAND_6504_RESPONSE_RECORD_BUFFER',
          `0x6504 ${field} must be a Buffer`
        );
      }
      requireFrameInvariant(
        record.unknownField0.length <= TCP10127_COMMAND_6504.maximumField0Length &&
          record.unknownField1.length <= TCP10127_COMMAND_6504.maximumField1Length &&
          record.unknownField2.length <= TCP10127_COMMAND_6504.maximumField2Length,
        'COMMAND_6504_RESPONSE_RECORD_LENGTH',
        '0x6504 encoded fields exceed PAL parser destination bounds'
      );
      requireFrameInvariant(
        record.unknownRaw8.length === TCP10127_COMMAND_6504.rawFieldLength,
        'COMMAND_6504_RESPONSE_RECORD_LENGTH',
        '0x6504 unknownRaw8 must contain exactly eight bytes'
      );
      for (const field of ['unknownWord0', 'unknownWord1']) {
        requireFrameInvariant(
          Number.isSafeInteger(record[field]) && record[field] >= 0 && record[field] <= 0xffff,
          'COMMAND_6504_RESPONSE_RECORD_VALUE',
          `0x6504 ${field} must be an unsigned 16-bit integer`
        );
      }
      requireFrameInvariant(
        Number.isSafeInteger(record.unknownDword) &&
          record.unknownDword >= 0 && record.unknownDword <= 0xffffffff,
        'COMMAND_6504_RESPONSE_RECORD_VALUE',
        '0x6504 unknownDword must be an unsigned 32-bit integer'
      );

      parts.push(encodeSnapField({
        plain: record.unknownField0,
        maximumDecodedLength: TCP10127_COMMAND_6504.maximumField0Length,
        sequence: frame.sequence,
        unknownCodecByte: selection.unknownCodecByte
      }));
      parts.push(encodeSnapField({
        plain: record.unknownField1,
        maximumDecodedLength: TCP10127_COMMAND_6504.maximumField1Length,
        sequence: frame.sequence,
        unknownCodecByte: selection.unknownCodecByte
      }));
      parts.push(Buffer.from(record.unknownRaw8));
      parts.push(encodeSnapField({
        plain: record.unknownField2,
        maximumDecodedLength: TCP10127_COMMAND_6504.maximumField2Length,
        sequence: frame.sequence,
        unknownCodecByte: selection.unknownCodecByte
      }));
      const trailing = Buffer.alloc(8);
      trailing.writeUInt16BE(record.unknownWord0, 0);
      trailing.writeUInt16BE(record.unknownWord1, 2);
      trailing.writeUInt32BE(record.unknownDword, 4);
      parts.push(trailing);
    }

    const progress = selection.unknownStart + selection.records.length;
    this.#state = progress < selection.unknownTotal
      ? TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_MORE_COMMAND_6504
      : TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_POST_COMMAND_6504_COMPLETE;
    const response = encodeTcp10127Frame({
      direction: TCP10127_DIRECTION.SERVER_RESPONSE,
      command: TCP10127_COMMAND_6504.command,
      sequence: frame.sequence,
      error: 0,
      unknown7: frame.unknown7,
      payload: Buffer.concat(parts)
    });
    return this.#handledResult(frame, response);
  }

  /**
   * Normal-status 0x6510 record-key batches.
   *
   * SLES_533.19 command-index tables DAT_002484c0/DAT_00248510 map builder index
   * 0x24 to wire command 0x6510, and receive-dispatch entry 0x25 binds direction
   * 0x02 of that command to FUN_001c8790. Builder FUN_001c85c0 caps its batch at
   * `li v0,12`, lowers it to the remaining record count, writes one count byte
   * through FUN_001c3da0, then that many encoded fields through FUN_001c4020,
   * then one trailing encoded field taken from the page block at +32.
   *
   * FUN_001c8790 reads one count byte and compares it with the batch count the
   * builder stored (`bne s3,v0` at 0x001c8884). Only an equal count makes it read
   * the per-record BE16 values and store each at record offset +0x12c, decimal 300
   * (`sh v0,300(v1)` at 0x001c8900). It then decodes exactly one trailing field
   * bounded to 0x3e decoded bytes (`li a2,62` at 0x001c892c). V2 therefore echoes
   * the request count and supplies exactly that many words; the count-mismatch
   * branch stores nothing and is not implemented.
   *
   * The request's encoded fields stay opaque. FUN_001c3b90 decodes with the
   * client's own connection state at +0x4c, which the server does not observe, so
   * V2 validates only the field envelope and hands the bytes to the provider.
   *
   * Unlike the 0x6212/0x6211/0x6213 receivers, 0x6510 has no safe status-0xff
   * client-default branch: at 0x001c87bc the 0xff path falls through to the cursor
   * block at 0x001c898c with s2/s3 still holding caller-saved values, so V2 always
   * requires an explicit provider and never answers 0x6510 with 0xff.
   *
   * Continuations proved by the same consumer, none of which the server can
   * observe in advance: another 0x6510 while the client cursor has records left or
   * another page remains; 0x6203 when the connection major state is 4 (substate
   * 0x10 -> FUN_001c48c0, builder index 0x12); and 0x1004 when the page list is
   * exhausted (substate 0x31 -> FUN_001c8dd0, builder index 0x05). Those two
   * terminal commands are observed and preserved here, not answered.
   */
  #handleCommand6510(frame) {
    requireFrameInvariant(
      frame.direction === TCP10127_DIRECTION.CLIENT_REQUEST,
      'COMMAND_6510_DIRECTION',
      '0x6510 frame must be a client request'
    );
    requireFrameInvariant(
      frame.command === TCP10127_COMMAND_6510.command,
      'COMMAND_6510_COMMAND',
      '0x6510 record-key batch request must use command 0x6510'
    );
    requireFrameInvariant(
      frame.error === 0,
      'COMMAND_6510_STATUS',
      'only the decoded normal-status 0x6510 path is implemented'
    );
    requireFrameInvariant(
      frame.unknown7 === TCP10127_COMMAND_6510.requestUnknown7,
      'COMMAND_6510_UNKNOWN7',
      'SLES_533.19 request builder writes 0xff at header byte 7'
    );
    requireFrameInvariant(
      frame.payloadLength >= 1,
      'COMMAND_6510_LENGTH',
      'FUN_001c85c0 always writes the batch count byte'
    );

    const requestRecordCount = frame.payload[0];
    requireFrameInvariant(
      requestRecordCount <= TCP10127_COMMAND_6510.maximumRequestRecordCount,
      'COMMAND_6510_REQUEST_COUNT',
      'FUN_001c85c0 never emits a batch larger than twelve records'
    );

    const unknownEncodedRecordFields = [];
    let offset = 1;
    for (let index = 0; index < requestRecordCount; index += 1) {
      const parsed = this.#readEncodedField(
        frame.payload,
        offset,
        'COMMAND_6510_ENVELOPE',
        `0x6510 record field ${index} does not fit its declared envelope`
      );
      unknownEncodedRecordFields.push(parsed.field);
      offset = parsed.next;
    }
    const trailing = this.#readEncodedField(
      frame.payload,
      offset,
      'COMMAND_6510_ENVELOPE',
      '0x6510 trailing field does not fit its declared envelope'
    );
    requireFrameInvariant(
      trailing.next === frame.payloadLength,
      'COMMAND_6510_ENVELOPE',
      '0x6510 count byte, record fields, and trailing field must consume the whole payload'
    );

    requireFrameInvariant(
      typeof this.#resolveCommand6510Response === 'function',
      'COMMAND_6510_RESPONSE_PROVIDER',
      'resolveCommand6510Response is required before handling 0x6510'
    );

    let selection;
    try {
      selection = this.#resolveCommand6510Response({
        command: frame.command,
        sequence: frame.sequence,
        requestRecordCount,
        unknownEncodedRecordFields,
        unknownEncodedTrailingField: trailing.field
      });
    } catch (error) {
      throw new Tcp10127ProtocolError(
        'COMMAND_6510_RESPONSE_PROVIDER',
        `0x6510 response provider failed: ${error.message}`
      );
    }
    requireFrameInvariant(
      selection == null || typeof selection.then !== 'function',
      'COMMAND_6510_RESPONSE_PROVIDER',
      'resolveCommand6510Response must be synchronous'
    );
    requireFrameInvariant(
      selection != null && typeof selection === 'object' && !Array.isArray(selection),
      'COMMAND_6510_RESPONSE_SHAPE',
      '0x6510 response provider must return an object'
    );
    requireFrameInvariant(
      Object.keys(selection).length === 3 &&
        Object.hasOwn(selection, 'unknownCodecByte') &&
        Object.hasOwn(selection, 'recordWords') &&
        Object.hasOwn(selection, 'unknownTrailingField'),
      'COMMAND_6510_RESPONSE_SHAPE',
      '0x6510 response requires only unknownCodecByte, recordWords, and unknownTrailingField'
    );
    requireFrameInvariant(
      Number.isSafeInteger(selection.unknownCodecByte) &&
        selection.unknownCodecByte >= 0 && selection.unknownCodecByte <= 0xff,
      'COMMAND_6510_RESPONSE_CODEC_BYTE',
      '0x6510 unknownCodecByte must be an unsigned byte'
    );
    requireFrameInvariant(
      Array.isArray(selection.recordWords) &&
        selection.recordWords.length === requestRecordCount,
      'COMMAND_6510_RESPONSE_WORD_COUNT',
      '0x6510 response must supply exactly one word per requested record'
    );
    for (let index = 0; index < selection.recordWords.length; index += 1) {
      requireFrameInvariant(
        Number.isSafeInteger(selection.recordWords[index]) &&
          selection.recordWords[index] >= 0 && selection.recordWords[index] <= 0xffff,
        'COMMAND_6510_RESPONSE_WORD_VALUE',
        `0x6510 response word ${index} must be an unsigned 16-bit integer`
      );
    }
    requireFrameInvariant(
      Buffer.isBuffer(selection.unknownTrailingField),
      'COMMAND_6510_RESPONSE_TRAILING_BUFFER',
      '0x6510 unknownTrailingField must be a Buffer'
    );
    requireFrameInvariant(
      selection.unknownTrailingField.length <= TCP10127_COMMAND_6510.maximumTrailingFieldLength,
      'COMMAND_6510_RESPONSE_TRAILING_LENGTH',
      '0x6510 trailing field exceeds the 0x3e decoded bound enforced by FUN_001c3b90'
    );

    const words = Buffer.alloc(selection.recordWords.length * 2);
    for (let index = 0; index < selection.recordWords.length; index += 1) {
      words.writeUInt16BE(selection.recordWords[index], index * 2);
    }
    const payload = Buffer.concat([
      Buffer.from([requestRecordCount]),
      words,
      encodeSnapField({
        plain: selection.unknownTrailingField,
        maximumDecodedLength: TCP10127_COMMAND_6510.maximumTrailingFieldLength,
        sequence: frame.sequence,
        unknownCodecByte: selection.unknownCodecByte
      })
    ]);

    this.#state = TCP10127_LOBBY_INITIALIZATION_STATE.AWAITING_POST_COMMAND_6510;
    const response = encodeTcp10127Frame({
      direction: TCP10127_DIRECTION.SERVER_RESPONSE,
      command: TCP10127_COMMAND_6510.command,
      sequence: frame.sequence,
      error: 0,
      unknown7: frame.unknown7,
      payload
    });
    return this.#handledResult(frame, response);
  }

  /**
   * Terminal 0x1004 lobby-initialization completion.
   *
   * FUN_001c8790 selects substate 0x31 once the 0x6510 cursor reaches the page
   * total with no further page and the connection major state is 5, 1, 7, or 0.
   * Scheduler FUN_001c9b00 case 0x31 calls FUN_001c8dd0, which builds command
   * index 0x05 -- wire command 0x1004 per DAT_002484c0/DAT_00248510 -- with
   * direction 0x01 and appends no fields, so the request is only the eight-byte
   * header. The scheduler then parks at substate 0x33.
   *
   * Receive-dispatch entry 0x06 binds direction 0x02 of 0x1004 to FUN_001c8e90,
   * which disassembles to `jr ra; li v0,1`. It reads no reply payload. In
   * FUN_001c9b00 a handler return of 1 increments the connection top-level state
   * byte at +0x0c rather than selecting another substate, so this reply completes
   * the lobby-initialization phase. Entry 0x07 binds direction 0x10 of the same
   * command to FUN_001c8ea0 (`li v0,-1`, an error return), so V2 answers with
   * direction 0x02 only.
   *
   * FUN_001c8dd0 also guards on cRam0035ccb4: when set it resets to state 7 and
   * sends nothing. Two receivers set it -- the status-0xff major-4 branches of
   * FUN_001c7680 (store at 0x001c7714) and FUN_001c7a70 (store at 0x001c7b14) --
   * and FUN_001c9b00 clears it at 0x001c983c. V2 answers neither 0x6502 nor
   * 0x6504 with 0xff, so the guard stays clear in the V2 flow.
   *
   * What follows this reply -- which side sends FIN and when, the meaning of the
   * incremented top-level state, and whether a further correlated TCP connection
   * opens -- is not established, so V2 answers nothing more on this connection.
   */
  #handleCommand1004(frame) {
    requireFrameInvariant(
      frame.direction === TCP10127_DIRECTION.CLIENT_REQUEST,
      'COMMAND_1004_DIRECTION',
      'terminal 0x1004 frame must be a client request'
    );
    requireFrameInvariant(
      frame.command === TCP10127_COMMAND_1004.command,
      'COMMAND_1004_COMMAND',
      'lobby-initialization completion must use command 0x1004'
    );
    requireFrameInvariant(
      frame.payloadLength === TCP10127_COMMAND_1004.requestPayloadLength,
      'COMMAND_1004_LENGTH',
      'FUN_001c8dd0 appends no fields to the terminal 0x1004 request'
    );
    requireFrameInvariant(
      frame.error === 0,
      'COMMAND_1004_STATUS',
      'FUN_001c3c90 writes status zero into the terminal 0x1004 request'
    );
    requireFrameInvariant(
      frame.unknown7 === TCP10127_COMMAND_1004.requestUnknown7,
      'COMMAND_1004_UNKNOWN7',
      'SLES_533.19 request builder writes 0xff at header byte 7'
    );

    this.#state = TCP10127_LOBBY_INITIALIZATION_STATE.LOBBY_INITIALIZATION_COMPLETE;
    // Only a session that got this far may be RESUMED. Recorded on the account
    // session, not on this object, because the resume arrives on a DIFFERENT
    // connection and this one is about to be reset by the client.
    this.#onInitializationComplete?.({ resumed: this.#resumed });
    const response = encodeTcp10127Frame({
      direction: TCP10127_DIRECTION.SERVER_RESPONSE,
      command: TCP10127_COMMAND_1004.command,
      sequence: frame.sequence,
      error: 0,
      unknown7: frame.unknown7,
      payload: Buffer.alloc(TCP10127_COMMAND_1004.responsePayloadLength)
    });
    return this.#handledResult(frame, response);
  }

  /**
   * Walk one FUN_001c3f40 field envelope: BE16 decodedLength+2, BE16 checksum,
   * then decodedLength encoded bytes. Only the length word is interpreted.
   */
  #readEncodedField(payload, offset, code, message) {
    requireFrameInvariant(offset + 2 <= payload.length, code, message);
    const lengthWord = payload.readUInt16BE(offset);
    requireFrameInvariant(
      lengthWord >= TCP10127_COMMAND_6510.minimumFieldLengthWord,
      code,
      message
    );
    const end = offset + 2 + lengthWord;
    requireFrameInvariant(end <= payload.length, code, message);
    return { field: Buffer.from(payload.subarray(offset, end)), next: end };
  }

  #preserveExpectedFollowup(frame, allowedCommands, codePrefix) {
    requireFrameInvariant(
      frame.direction === TCP10127_DIRECTION.CLIENT_REQUEST,
      `${codePrefix}_FOLLOWUP_DIRECTION`,
      `${codePrefix} follow-up must be a client request`
    );
    requireFrameInvariant(
      allowedCommands.includes(frame.command),
      `${codePrefix}_FOLLOWUP_COMMAND`,
      `unexpected ${codePrefix} follow-up command 0x${frame.command.toString(16)}`
    );
    return {
      response: null,
      state: this.#state,
      unimplemented: true,
      request: {
        command: frame.command,
        sequence: frame.sequence,
        unknown7: frame.unknown7,
        unknownPayload: Buffer.from(frame.payload)
      }
    };
  }

  #handledResult(frame, response) {
    return {
      response,
      state: this.#state,
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
