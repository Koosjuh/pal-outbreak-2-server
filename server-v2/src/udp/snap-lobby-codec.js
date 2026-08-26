/**
 * The SN@P UDP :9090 messages of the POST-SELECTION phase: everything the client
 * sends between the 566-byte bind and a visible in-area lobby.
 *
 * This module encodes and decodes PAYLOADS, never whole datagrams. The framing -
 * `who`, the sub byte, the token, the sequence, the trailer - belongs to
 * `transport/reliable-channel.js`, which is the single place that decides whether
 * a message is reliable, which sequence it carries and whether that sequence is
 * mirrored or stamped. A second framing path here is exactly how V1 ended up
 * with two disagreeing sequence counters (`server/game_udp_server.js:826-837`
 * and `:2991-3000`, both shipped, both later fixed).
 *
 * Wire evidence, top rank first. Every layout below was read off the V1 session
 * that reached a rendered Area Select on real PS2 hardware,
 * `C:\dnas\pi-evidence-archive\extracted\captures\udp9090\`
 * `2026_07_30_14_52_53_udp_192_168_2_248_2000.log` (referred to as "the archive"
 * throughout). Decompile citations name the client function that consumes each
 * field, and are there to explain WHY a field matters, not to establish its bytes.
 */

import { HEADER_LENGTH, MAX_INNER_LENGTH } from '../protocol/snap-codec.js';

/** The opcodes this phase uses. The client's dispatcher masks with 0x7f. */
export const LOBBY_OPCODE = Object.freeze({
  /** Post-register bind AND the 566-byte post-lobby snapshot. */
  BIND: 0x01,
  /**
   * The SN@P session CLOSE: reliable, `who = 0xb000`, ZERO body, both
   * directions. `FUN_001dbd0c` sends it client->server as a "type 2" control
   * close (`FUN_001e180c(conn, buf, 0xb000, 0, 2, 0)` - the `2` is this wire
   * opcode), and the exit-contract RE records the 0xb000 close as a
   * BIDIRECTIONAL handshake the dispatcher mirrors
   * (`docs/findings/protocol/G12-exit-contract-RE-2026-07-17.md`, xchain:29337).
   * T37 carried three clean client-side instances at give-up moments
   * (`docs/design/v2-port/B3-LEAVE-TWICE-EVIDENCE.md` §1).
   */
  SESSION_CLOSE: 0x02,
  /** `a1 00 00 0c`, 260 bytes: the connect-screen room/session query. */
  ROOM_QUERY: 0x0c,
  /**
   * INBOUND: the room CREATE request, `0x2c` bytes, built by `func_0x001dc508`.
   * The create pump `FUN_005c3490` sends it in step 1 and then parks in step 2
   * waiting on `0x6CBA7D`, which only this opcode's completion can write.
   */
  CREATE_ROOM: 0x04,
  /**
   * INBOUND op-0x07: LEAVE, zero-length reliable, `who = 0xb000`
   * (`snap_send_leave` 0x001dd07c, corpus `functions/rooms/001dd07c_*`). Sent by
   * `FUN_005bfe00` from `FUN_005c1c80` step 2; the SM then parks in step 3.
   *
   * OUTBOUND op-0x06 is a DIFFERENT message on the same opcode - the member-JOIN
   * record pushed into the client's slot 2. Inbound 0x06 is the area ENTER
   * request. They are distinguished by direction, not by any wire field, and that
   * is why `AREA_ENTER` and `MEMBER_JOIN` are separate names for one number.
   */
  AREA_LEAVE: 0x07,
  /**
   * INBOUND op-0x0a: the MEMBER-LIST query, and one of the three the client
   * batches into a single datagram right after the create accept.
   *
   * Answered as a DIRECT opcode-0x0a message, NOT through op-0x28: the dispatcher
   * routes outer case 7 to `FUN_001d8848`, which byteswaps the header words and
   * then per record `+0x10` and `+0x14`, and hands slot 0x18 (`FUN_005c0ae0`) a
   * body whose record ids are already in host order. Sent via op-0x28 the
   * selector word would occupy body `+0x00` and every field would shift.
   *
   * `sub` MUST be 0. `FUN_001de0c0` returns a literal 0 as the task match key,
   * and `FUN_005c0ae0` early-returns WITHOUT completing the task when `0x2000` is
   * clear and the sub byte is non-zero - so a wrong sub is not a garbled reply,
   * it is a silent permanent hang.
   */
  MEMBER_LIST: 0x0a,
  /**
   * INBOUND op-0x09: a counted query keyed by a 4-char ASCII tag - `"USER"` for
   * the current member count, `"MAXI"` for the maximum. Body is
   * `[BE32 handle][BE32 tag]`; wire-confirmed at T35 22:12:53.
   *
   * Also answered DIRECT (outer case 6 -> `FUN_001d84cc` -> slot 0x16), echoing
   * the request's `sub` byte and its `0x1000` flag bit. An unknown tag stores
   * nothing but still completes the task, which is why a typo here surfaces as
   * wrong numbers rather than a hang.
   */
  AREA_COUNT_QUERY: 0x09,
  /**
   * INBOUND op-0x08: the NAMED-CHANNEL query (`func_0x001dd33c`), tag `"STAT"`.
   *
   * NOT the exit button - that is op-0x07. This one matters more: its reply is
   * the ONLY exit from the roster SM's single unbounded wait (phase 1, driven by
   * `FUN_005c28f0(0, 0x5C6350)`), so silence here is a permanent hang rather than
   * a slow path. Answered with op-0x28 selector 8, which is the only route that
   * reaches reply slot 0x25 (`conn+0x5DC`).
   */
  NAMED_CHANNEL_QUERY: 0x08,
  /**
   * op-0x0F: LOBBY CHAT, both directions - and the area-name probe, which shares
   * the opcode and must NOT be relayed.
   *
   * The owner reported chat as "only local". It is: `FUN_005C4AF0` echoes the line
   * into the sender's own display block BEFORE transmitting, so the sender always
   * sees it, and nobody else did because the server never relayed it. The client
   * has been sending this since the first lobby run; we logged it as an unhandled
   * opcode and dropped it.
   *
   * Wire, T35 22:15:53, 192.168.2.248 -> :9090 - user `test123` typing `abcde`:
   * flags `0xb422`, sub 0, op `0x0f`, body `02 00 07 05 00 00 "test123" "abcde"`.
   *
   * Not TCP. BioServer's CHATIN `0x6701` / CHATOUT `0x6702` both map onto this one
   * UDP opcode; T35's TCP census carries no `0x67xx` at all.
   */
  CHAT: 0x0f,
  /** `xx xx <sub> 10`: the in-room state pushes, discriminated by a SUB at `+0x18`. */
  ROOM_STATE: 0x10,
  /** `a0 14 <sub> 0d`, 24 bytes: the re-entry variant of the room query. */
  REENTRY_QUERY: 0x0d,
  /** `xx xx <sub> 14`, 68 bytes of 0x55: the RTT/bandwidth probe. */
  RTT_PROBE: 0x14,
  /** `B0 18 <sub> 28`: every "request N completed" push, discriminated by selector. */
  COMPLETION: 0x28,
  /** `a0 1c 00 29`: the only clean `conn+0x80` 3 -> 0 transition. Never captured. */
  SUCCESS_TRANSITION: 0x29,
  /** `30/31 xx 00 40`, 296 bytes, NON-reliable: the keepalive that defers 840. */
  KEEPALIVE: 0x40,
  /** `b0 98 00 41`, reliable: the client's answer to the keepalive. Must be acked. */
  KEEPALIVE_RESPONSE: 0x41,
  /** `f0 42 00 48`, 70 bytes: the NAME query that drives Area Select. */
  NAME_QUERY: 0x48,
  /** `xx xx 00 49`: the room list. */
  ROOM_LIST: 0x49,
  /** `xx xx <sub> 06`: area ENTER inbound; the member-JOIN record outbound. */
  AREA_ENTER: 0x06,
  /** The same opcode, outbound: one member record pushed into the client's slot 2. */
  MEMBER_JOIN: 0x06,
  /**
   * `B0 18 <sub> 27`: the op-0x28 family's REJECT, and the only one.
   *
   * The "status" is not a payload field: `param_1` of every app callback is
   * `&cStack_40`, a LOCAL in `FUN_001d9f78` zeroed in the prologue and written
   * `0x27` at exactly the `case 0x24` entry (wire `0x27`), which then FALLS
   * THROUGH into the identical selector dispatch. So the accept/reject
   * discriminator is the WIRE OPCODE BYTE, not a payload edit
   * (`CORRECTIONS.md` C-2, Confirmed).
   *
   * Wire `0x31` also sets that local to `0x27` and is NOT a substitute: its
   * `case 0x2e` has its own body, dispatches unconditionally to slot 0x1c and
   * clears `conn+0x7c`/`conn+0x80`. It never reaches the selector switch
   * (`CORRECTIONS.md` C-8, Confirmed). Do not use it as a generic reject.
   */
  COMPLETION_REJECT: 0x27
});

/**
 * The BE32 at completion payload `+0x00`. The transport byteswaps it and the
 * dispatcher uses it to pick which installed callback slot fires, so it is a
 * ROUTING value, not a status. Getting it wrong means the client's request
 * watchdog (`uRam006c5500`, 3600 frames) expires and draws the error screen -
 * indistinguishable, from the server's side, from having sent nothing.
 */
export const COMPLETION_SELECTOR = Object.freeze({
  /** `FUN_005bca90`, the slot-0x1c push that ends the connect spinner. */
  SLOT_1C: 1,
  /**
   * Room CREATE accepted. `selector - 1 = 3` -> `conn + 0x5C4` = `0x548 + 0x1f*4`
   * = slot **0x1f** = `FUN_005c3a40`, the callback `func_0x001dc508` installs
   * when it sends op-0x04. That callback sets `0x6CBA7D = 1` and `0x6FF2B0 = 1`
   * and stores the handle; the pump then sets `0x6FF2B1 = 1` one step later.
   * MUST be 4 (`CORRECTIONS.md` C-3, Confirmed).
   */
  CREATE_ROOM: 4,
  /** Area ENTER accepted -> `FUN_005ad9f0` -> `FUN_005f74d0` -> the lobby is on screen. */
  AREA_ENTER: 6,
  /**
   * LEAVE accepted. `selector - 1 = 6` -> `case 6:` -> with the DATA flag set,
   * `conn + 0x5D4` = `0x548 + 0x23*4` = slot **0x23** - which is exactly the
   * callback `snap_send_leave` (0x001dd07c) installs ("cb 0x23", corpus record
   * `functions/rooms/001dd07c_snap_send_leave.md`), namely `FUN_005bfe90`.
   *
   * Derived from `FUN_001d9f78`'s inner switch by the SAME arithmetic that gives
   * selector 4 -> slot 0x1f and selector 6 -> slot 0x21, both independently
   * corroborated (the corpus for the first, V1's shipped comment for the second).
   */
  AREA_LEAVE: 7,
  /** Slot 0x26, `FUN_005b52e0`: the only exit from connect sub-state 7 step 0. */
  ROOM_QUERY: 0x0c,
  /** `FUN_005bcee0`, the re-entry path. Its payload carries nothing else. */
  REENTRY: 0x0d
});

/**
 * The op-0x10 GAME-CHANNEL sub-selectors: the byte the slot-0x13 dispatcher
 * `FUN_005bba20` switches on, at app payload `+0x00` = message payload `+0x08`
 * (`G12-joiner-tag17-RE-2026-07-16.md`, helper:12366).
 *
 * Distinct from `ROOM_STATE_SUB` below only in provenance: these two are the
 * JOIN handshake pair, decompile-cited on both sides (the joiner's sender
 * `FUN_005c5ff0` payload[0]=2; the host's confirm sender `FUN_005c6050`
 * payload[0]=0xc; receiver cases helper:12450/12526).
 */
export const ROOM_EVENT_SUB = Object.freeze({
  /** The joiner's join-request; a real host answers it with JOIN_CONFIRM. */
  JOIN_REQUEST: 0x02,
  /** Fires `FUN_005bbe00` -> the stored continuation 0x601300 -> major 5->6. */
  JOIN_CONFIRM: 0x0c
});

/** The op-0x10 in-room pushes, discriminated by the byte at wire `+0x18`. */
export const ROOM_STATE_SUB = Object.freeze({
  /**
   * The in-room header "MAX / CURRENT P": max at wire `+0x1c`, current at `+0x1d`.
   * The client ZEROES `0x6ff2b4` on every screen rebuild and this is its sole
   * non-zero writer, so it must be re-asserted after each rebuild rather than
   * sent once.
   */
  ROOM_LIMITS: 0x05,
  /** `FUN_005bbea0` writes `0x6cfb70[room]` from a LE32 count at wire `+0x1c`. */
  MEMBER_COUNT: 0x11
});

/** Payload sizes, so a caller never open-codes one. */
export const COMPLETION_PAYLOAD_BYTES = 8;
/** The extended completion with the send-seq echo at `+0xc` (B3 fix 2). */
export const COMPLETION_ECHO_PAYLOAD_BYTES = 0x10;
export const NAME_QUERY_REPLY_HEADER_BYTES = 12;
export const NAME_QUERY_RECORD_BYTES = 0x24;
export const NAME_QUERY_RECORD_NAME_BYTES = 0x10;
export const ROOM_LIST_HEADER_BYTES = 12;
export const ROOM_LIST_RECORD_BYTES = 0x28;

/**
 * `FUN_001d8c10` -> `FUN_001d81a4` byteswaps `count` records of five words each
 * and refuses the message outright when `count >= 0x37d`. Reproduced as a named
 * constant so the failure is ours and legible rather than the client's and
 * silent - but note it is NOT the binding limit: a SN@P message length is ten
 * bits, so `MAXIMUM_NAME_QUERY_RECORDS` below is 27 and is what actually bites.
 */
export const CLIENT_NAME_QUERY_RECORD_CEILING = 0x37d;

/** `(0x3ff - 16 - 12) / 0x24`, the largest record count one datagram can carry. */
export const MAXIMUM_NAME_QUERY_RECORDS =
  Math.floor((MAX_INNER_LENGTH - HEADER_LENGTH - NAME_QUERY_REPLY_HEADER_BYTES) /
    NAME_QUERY_RECORD_BYTES);

/** The same arithmetic for op-0x49's wider records. */
export const MAXIMUM_ROOM_LIST_RECORDS =
  Math.floor((MAX_INNER_LENGTH - HEADER_LENGTH - ROOM_LIST_HEADER_BYTES) / ROOM_LIST_RECORD_BYTES);

/**
 * The keepalive's plaintext: `0x110` bytes, ALL ZERO.
 *
 * `FUN_001d9b6c` decrypts the body and then reads four length words out of the
 * plaintext to drive a `memcpy`. Zero plaintext means zero lengths means zero
 * bytes copied. A body the client cannot decrypt to zeros produces four garbage
 * lengths and overruns its stack - so a WRONG key here does not degrade, it
 * crashes an unmodified retail console. That is why the key is a required
 * constructor argument rather than something with a convenient default.
 */
export const KEEPALIVE_PLAINTEXT_BYTES = 0x110;

/**
 * The keepalive's body is four bytes LONGER than its ciphertext, and those four
 * are zero.
 *
 * V1 built `total = 0x10 + 0x114 + 4` and copied only `0x110` ciphertext bytes
 * (`game_udp_server.js:1358-1367`), leaving `wire+0x120..0x123` zero. Why 0x114
 * rather than 0x110 is Unknown; it is reproduced rather than tidied, because
 * that shape is the one a real PS2 answered - the archive shows an op-0x41 come
 * back 98 ms after every one of them.
 */
export const KEEPALIVE_BODY_BYTES = 0x114;

export class SnapLobbyCodecError extends Error {
  constructor(code, message) {
    super(message);
    this.name = 'SnapLobbyCodecError';
    this.code = code;
  }
}

function fail(code, message) {
  throw new SnapLobbyCodecError(code, message);
}

function requireUint32(value, field) {
  if (!Number.isInteger(value) || value < 0 || value > 0xffffffff) {
    fail('INVALID_U32', `${field} must be a uint32, not ${value}`);
  }
  return value >>> 0;
}

/* ---- op-0x48, the NAME query ------------------------------------------- */

/** `[BE32 tag][u8 entryCount][3 pad]`, then `entryCount` entries. */
const NAME_QUERY_TAG_OFFSET = 0x00;
const NAME_QUERY_COUNT_OFFSET = 0x04;
const NAME_QUERY_FIRST_ENTRY = 0x08;
/** `[BE32 "NAME"][u8 flag][char[16] value]` - `FUN_001e094c.c:36-79`. */
const NAME_QUERY_ENTRY_BYTES = 21;
const NAME_QUERY_ENTRY_VALUE_OFFSET = 5;
const NAME_QUERY_ENTRY_VALUE_BYTES = 16;

/**
 * Decode the client's NAME query.
 *
 * The two values are `record[0].key + "01"` and `record[0].key + "10"`, where
 * `record[0].key` is the TCP-10127 `0x6504` key - in the archive
 * `"192.168.2.12101"` / `"192.168.2.12110"`. Nothing in the reply is derived
 * from them (the reply enumerates the areas), so this decodes for correlation
 * and for the log: if these two strings are not what the directory published,
 * the TCP half and the UDP half are looking at different records and the later
 * ENTER cannot resolve.
 *
 * Never throws on peer input past the structural checks: `entries` is bounded by
 * what the payload can actually hold, so a lying count cannot make us allocate.
 */
export function decodeNameQuery(payload) {
  if (!Buffer.isBuffer(payload)) fail('NOT_A_BUFFER', 'a NAME query payload must be a Buffer');
  if (payload.length < NAME_QUERY_FIRST_ENTRY) {
    fail('NAME_QUERY_TOO_SHORT', `a NAME query needs ${NAME_QUERY_FIRST_ENTRY} bytes of header`);
  }
  const declaredEntryCount = payload.readUInt8(NAME_QUERY_COUNT_OFFSET);
  const room = Math.floor((payload.length - NAME_QUERY_FIRST_ENTRY) / NAME_QUERY_ENTRY_BYTES);
  const entries = [];
  for (let index = 0; index < Math.min(declaredEntryCount, room); index += 1) {
    const at = NAME_QUERY_FIRST_ENTRY + index * NAME_QUERY_ENTRY_BYTES;
    const value = payload.subarray(
      at + NAME_QUERY_ENTRY_VALUE_OFFSET,
      at + NAME_QUERY_ENTRY_VALUE_OFFSET + NAME_QUERY_ENTRY_VALUE_BYTES
    );
    const end = value.indexOf(0);
    entries.push({
      // 'D' (0x44) and 'F' (0x46) in every archived query. The builder derives the
      // chunk size as `flag >> 5`, so both mean a 16-byte string field.
      flag: payload.readUInt8(at + 4),
      value: value.subarray(0, end === -1 ? value.length : end).toString('latin1')
    });
  }
  return {
    tag: payload.readUInt32BE(NAME_QUERY_TAG_OFFSET),
    declaredEntryCount,
    /** True when the payload was too small for the count it declared. */
    truncated: declaredEntryCount > room,
    entries
  };
}

/**
 * Build the op-0x48 reply payload: `[BE32 tag][BE32 word][BE32 count]` then
 * `count` records of `0x24`.
 *
 * Each record is `name[16]` RAW - the transport does not touch it - followed by
 * five BE32 at `+0x10 +0x14 +0x18 +0x1c +0x20`, which `FUN_001d81a4` byteswaps
 * into native order before `FUN_005c1220` reads them.
 *
 * Two of the five are load-bearing and the archive shows V1 shipping ZERO in all
 * five, which is why its Area Select counts were never real:
 *
 *   `+0x10`  the area's player count. `FUN_005bc990` sums `lhu(rec+0x10)` across
 *            every record into `uRam0086f7f8` and compares the sum against
 *            `record[0]+0x12a` - the TCP-10127 `0x6504` "max players". Sum >= max
 *            is the string "Server full. You cannot participate."
 *   `+0x20`  the AREA KEY. `FUN_005c1220` stores it at `0x6fec28 + box*0x24`;
 *            the ~25/s refresh (`FUN_005c70e0` via `FUN_005bf280`) looks the box
 *            up BY THIS VALUE and drops the record on no match; and the ENTER
 *            request sends it straight back (`FUN_005bfa70.c:19-24`). V1 shipped
 *            0 for all ten, so every refresh resolved to box 0.
 *
 * `+0x14 +0x18 +0x1c` are copied to `0x6fec1c/20/24` and no reader has been
 * identified (gap table U4). They are settable, defaulting to zero, which is the
 * value that rendered.
 *
 * The name's last two ASCII digits ARE the box id 1..10 (`FUN_005c1220.c:18-48`
 * reads `name[strlen-2..strlen-1]`), so the name is validated, never padded into
 * something that happens to end in digits.
 */
export function buildNameQueryReplyPayload({ tag, statusWord = 0, records }) {
  requireUint32(tag, 'tag');
  requireUint32(statusWord, 'statusWord');
  if (!Array.isArray(records)) fail('RECORDS_REQUIRED', 'records must be an array');
  if (records.length === 0) {
    // Refused rather than sent: `FUN_005c1220` would un-grey nothing and the
    // screen would sit on a blank grid with no indication why.
    fail('NO_RECORDS', 'an op-0x48 reply with no records leaves every Area-Select box grey');
  }
  if (records.length > MAXIMUM_NAME_QUERY_RECORDS) {
    fail(
      'TOO_MANY_RECORDS',
      `${records.length} records exceed the ${MAXIMUM_NAME_QUERY_RECORDS} a SN@P message can ` +
      'carry; the length field is ten bits'
    );
  }

  const payload = Buffer.alloc(
    NAME_QUERY_REPLY_HEADER_BYTES + records.length * NAME_QUERY_RECORD_BYTES
  );
  payload.writeUInt32BE(tag, 0x00);
  payload.writeUInt32BE(statusWord, 0x04);
  payload.writeUInt32BE(records.length, 0x08);

  records.forEach((record, index) => {
    const at = NAME_QUERY_REPLY_HEADER_BYTES + index * NAME_QUERY_RECORD_BYTES;
    const name = Buffer.isBuffer(record?.name)
      ? record.name
      : Buffer.from(String(record?.name ?? ''), 'latin1');
    if (name.length === 0 || name.length >= NAME_QUERY_RECORD_NAME_BYTES) {
      fail(
        'RECORD_NAME_LENGTH',
        `record ${index} name is ${name.length} bytes; the field holds ` +
        `${NAME_QUERY_RECORD_NAME_BYTES} including the terminating NUL`
      );
    }
    name.copy(payload, at);
    payload.writeUInt32BE(requireUint32(record?.playerCount ?? 0, `record ${index} playerCount`),
      at + 0x10);
    payload.writeUInt32BE(requireUint32(record?.word1 ?? 0, `record ${index} word1`), at + 0x14);
    payload.writeUInt32BE(requireUint32(record?.word2 ?? 0, `record ${index} word2`), at + 0x18);
    payload.writeUInt32BE(requireUint32(record?.word3 ?? 0, `record ${index} word3`), at + 0x1c);
    payload.writeUInt32BE(requireUint32(record?.key ?? 0, `record ${index} key`), at + 0x20);
  });
  return payload;
}

/* ---- op-0x28, the completion push -------------------------------------- */

/**
 * `[BE32 selector][BE32 status]` - and, with `sendSeqEcho`, an extended
 * `0x10`-byte form carrying the request's send-seq at `+0xc`.
 *
 * The status dword is NEVER READ on the op-0x0c path: `FUN_005b52e0` tests
 * `desc[0]`, which the dispatcher fills from its own status char, and accepts
 * both `0x00` and `0xff` (`analysis/FOUR-UNKNOWNS-CLOSED.md` §2, correction C-4).
 * It is still emitted as 0 because that is what the archive carries and because a
 * field whose consumer is unknown is not a field to improvise in.
 *
 * ## The `+0xc` send-seq echo (B3 fix 2, flag `SNAP_COMPLETION_SEQ_ECHO`)
 *
 * The sel-6/sel-7 reply handlers (`FUN_005bfb40`/`FUN_005bfe90`) latch
 * `0x6cbc80 = (u16)*(u32*)(param + 0xc)` and `FUN_005be120` sweeps the 128-slot
 * request pool for `sendSeq == 0x6cbc80 && id == 0x6cbc7c` - only on a match is
 * the slot cleared and the stored continuation fired
 * (`G12-exit-contract-RE-2026-07-17.md:84`,
 * `docs/design/v2-port/B3-LEAVE-TWICE-EVIDENCE.md` §3). Both REs say the real
 * reply carries the REQUEST'S SEND-SEQ echoed at `+0xc`; our 8-byte payload puts
 * that read past the datagram entirely, onto the trailer or beyond - the only
 * observed deviation from the RE'd reply contract in the whole first-leave
 * exchange.
 *
 * BYTE ORDER, derived not guessed: the case-0x25 dispatcher byteswaps exactly
 * TWO payload words - `FUN_001d7f6c` stores at `+0x00` and `+0x04`,
 * straight-line, then `jr ra` - so `+0x08`/`+0x0c` reach the handler RAW, and
 * the little-endian client's `*(u32*)` read must find the send-seq value in LE
 * bytes for the `(u16)` truncation to equal the pool slot's native `sendSeq`.
 * Hence `writeUInt32LE`. Whether the callback's `param` base is really the
 * payload start is gap O3/G3 - which is exactly why the caller gates this
 * behind a flag instead of shipping it as fact.
 *
 * `sendSeqEcho = null` (the default) emits the 8-byte payload BYTE-IDENTICAL
 * to every previous build - the rig-confirmed sel-6/sel-7 accepts must not move
 * while the flag is off.
 */
export function buildCompletionPayload({ selector, status = 0, sendSeqEcho = null }) {
  if (sendSeqEcho === null) {
    const payload = Buffer.alloc(COMPLETION_PAYLOAD_BYTES);
    payload.writeUInt32BE(requireUint32(selector, 'selector'), 0x00);
    payload.writeUInt32BE(requireUint32(status, 'status'), 0x04);
    return payload;
  }
  const payload = Buffer.alloc(COMPLETION_ECHO_PAYLOAD_BYTES);
  payload.writeUInt32BE(requireUint32(selector, 'selector'), 0x00);
  payload.writeUInt32BE(requireUint32(status, 'status'), 0x04);
  // +0x08 stays zero: neither RE names a reader for it, and a field with no
  // identified consumer is not a field to improvise in.
  payload.writeUInt32LE(requireUint32(sendSeqEcho, 'sendSeqEcho'), 0x0c);
  return payload;
}

/**
 * The op-0x04 CREATE accept payload: `[BE32 4][BE32 handle]`.
 *
 * ## Both words are BIG-endian, and that is a corrected fact
 *
 * `FUN_001d9f78` case `0x25` calls `FUN_001d7f6c(msg + 0x3c)` before dispatching,
 * and that function byteswaps **TWO** 32-bit words in place - `sw v0,0x0(a1)` at
 * `0x1d7fd4` and `sw v0,0x4(a1)` at `0x1d8030`, straight-line, no branch between
 * them, then `jr ra` (`analysis/decompile-fun_001d7f6c-2026-05-25.txt`). So wire
 * `+0x10` AND wire `+0x14` are both BE32 on the wire, and `FUN_005c3a40` reads
 * the handle as `*(u32*)(param_2 + 4)` AFTER the swap.
 *
 * V1 emitted the handle LITTLE-endian (`game_udp_server.js:1717`) and the accept
 * still latched, because on this path the handle is an opaque token nothing
 * compares. That is why the wrong endianness went unnoticed, and it is exactly
 * why it matters now: the moment the server wants the handle it minted to come
 * back recognisable in a later ENTER, the two readings differ.
 *
 * SUPERSEDED: `CREATE-ROOM-GATES-RE.md` section 5 and
 * `CREATE-ROOM-GATES-REVIEW-CORRECTIONS.md` section 1 both record "LE32 handle".
 * Refuted by the disassembly above and by `reverse-engineering/network/`
 * `CORRECTIONS.md` C-7. This is NOT the op-0x49 room-list handle at record
 * `+0x24`, which is a different message on a different parse path
 * (`FUN_005c19d0`) and stays little-endian.
 */
export function buildCreateRoomAcceptPayload({ handle }) {
  const payload = Buffer.alloc(COMPLETION_PAYLOAD_BYTES);
  payload.writeUInt32BE(COMPLETION_SELECTOR.CREATE_ROOM, 0x00);
  payload.writeUInt32BE(requireUint32(handle, 'handle'), 0x04);
  return payload;
}

/* ---- op-0x06 outbound, the member-JOIN record --------------------------- */

/** `name[16] | BE32 memberId @+0x10 | 4 pad | u8[0xf0] charstats @+0x18`. */
export const MEMBER_RECORD_BYTES = 0x108;
export const MEMBER_NAME_BYTES = 0x10;
const MEMBER_ID_OFFSET = 0x10;
const MEMBER_STATS_OFFSET = 0x18;
/** The charstats field is 0xf0 bytes: MEMBER_RECORD_BYTES (0x108) - MEMBER_STATS_OFFSET (0x18). */
export const MEMBER_STATS_BYTES = 0xf0;
/** `charstats + 0xc8`; a distinct value per member is what the dedup admits on. */
const MEMBER_CHARACTER_ID_OFFSET = MEMBER_STATS_OFFSET + 0xc8;

/**
 * One member-JOIN record - the ONLY thing that fills the DRAWN roster.
 *
 * op-0x0a fills the *data* table at `0x6cdbe6`; the table the player actually
 * sees, `0x6c7c2c`, is filled only by the op-0x06 handler `FUN_005bb4d0`, which
 * fires event 0x1f (ADD) and then event 0x19 (repaint). The name at record `+0x00`
 * is rendered verbatim and an EMPTY name is the client's free-row marker, so a
 * blank name here is not a cosmetic default - it draws nothing.
 *
 * This is a DELTA and the client ACCUMULATES on it (`0x6cfb62`, capped at 4), so
 * it may only ever be emitted from a transition, never from a poll handler. V1
 * shipped exactly that bug: it re-fired op-0x06 from inside the op-0x0a poll and
 * inflated the count on every poll (`game_udp_server.js:2117`, the T19 bug).
 */
export function buildMemberJoinPayload({ name, memberId, characterId = 0, charstats = null }) {
  const encoded = Buffer.isBuffer(name) ? name : Buffer.from(String(name ?? ''), 'latin1');
  if (encoded.length === 0) {
    fail('MEMBER_NAME_EMPTY', 'an empty member name is the client\'s free-row marker and draws ' +
      'nothing; a member-JOIN must carry the name to render');
  }
  if (encoded.length > MEMBER_NAME_BYTES) {
    fail('MEMBER_NAME_LENGTH', `member name is ${encoded.length} bytes; the field holds ` +
      `${MEMBER_NAME_BYTES}`);
  }
  const payload = Buffer.alloc(MEMBER_RECORD_BYTES);
  encoded.copy(payload, 0x00);
  // BE32, as V1 shipped for the SELF push. The joiner-broadcast path used LE for
  // a different consumer; only the self push is reproduced here, because only it
  // is rig-confirmed to have populated row 0.
  payload.writeUInt32BE(requireUint32(memberId, 'memberId'), MEMBER_ID_OFFSET);
  /*
   * SNAP_CHARSTATS_SEED (charstats-to-sub7-source RE): fill the 0xf0 charstats
   * field @+0x18 with the member's real captured op-0x0c blob so the host's seat
   * -> sub-7 -> splash render the true character instead of Jim. The blob carries
   * its OWN char-id @+0xc8 and class @+0xca (the dedup keys), so when a blob is
   * supplied it OVERRIDES the synthetic characterId - we do not also stamp
   * characterId, which would clobber the real char-id inside the blob.
   */
  if (Buffer.isBuffer(charstats) && charstats.length > 0) {
    if (charstats.length !== MEMBER_STATS_BYTES) {
      fail('MEMBER_STATS_LENGTH', `charstats is ${charstats.length} bytes; the field holds ` +
        `${MEMBER_STATS_BYTES}`);
    }
    charstats.copy(payload, MEMBER_STATS_OFFSET);
  } else if (characterId !== 0) {
    payload.writeInt16LE(characterId, MEMBER_CHARACTER_ID_OFFSET);
  }
  return payload;
}

/* ---- the three screen-4 queries ----------------------------------------- */

/**
 * The room handle as OPAQUE BYTES.
 *
 * The op-0x28 sel-4 accept writes the handle BE32 at body `+0x04`; `FUN_005c3a40`
 * stores that word verbatim and `FUN_005c0a00` sends the same four bytes straight
 * back. So the round trip is byte-for-byte and the server never needs to agree
 * with the client about endianness - it only needs to not re-encode.
 *
 * The one captured sample reads `01 00 00 00` for handle 1, which is the reverse
 * of what we minted; it came from the emulator, which had NOT created a room in
 * that window, so its handle word most likely came from a room-list record stored
 * unswapped. That attribution is Inference. Rather than bet on it, resolution
 * accepts EITHER order and the reply echoes the request's own bytes verbatim.
 */
export function resolveRoomHandleBytes(bytes) {
  if (!Buffer.isBuffer(bytes) || bytes.length !== 4) {
    fail('HANDLE_FIELD', 'a room handle field is exactly 4 bytes');
  }
  return { forward: bytes.readUInt32BE(0), reversed: bytes.readUInt32LE(0) };
}

/** `[4 handle bytes]` - the whole op-0x0a request body. */
export function decodeMemberListRequest(payload) {
  if (!Buffer.isBuffer(payload) || payload.length < 4) {
    fail('MEMBER_LIST_RUNT', `an op-0x0a body is at least 4 bytes, not ${payload?.length ?? 0}`);
  }
  return { handleBytes: Buffer.from(payload.subarray(0, 4)) };
}

/** `[BE32 handle][BE32 tag]` - the op-0x09 request body, wire-confirmed. */
export function decodeAreaCountRequest(payload) {
  if (!Buffer.isBuffer(payload) || payload.length < 8) {
    fail('AREA_COUNT_RUNT', `an op-0x09 body is at least 8 bytes, not ${payload?.length ?? 0}`);
  }
  return {
    handleBytes: Buffer.from(payload.subarray(0, 4)),
    tag: Buffer.from(payload.subarray(4, 8))
  };
}

export const AREA_COUNT_TAG_CURRENT = Buffer.from('USER', 'latin1');
export const AREA_COUNT_TAG_MAXIMUM = Buffer.from('MAXI', 'latin1');

/**
 * The op-0x0a MEMBER-LIST reply.
 *
 * ```
 * +0x00  handle echo, verbatim   (FUN_005c0ae0 ignores it, but a mismatch is
 *                                 indistinguishable from a bug, so echo it)
 * +0x04  BE32  -> low byte lands in 0x6FB738
 * +0x08  BE32  record count, which the client refuses at >= 0x37D
 * +0x0C  records, stride ((rec[0x14] + 0x1B) & ~3)
 * ```
 * With a 0xF0 payload length the stride is `(0xF0 + 0x1B) & ~3` = `0x108` -
 * the same `MEMBER_RECORD_BYTES` the op-0x06 push already uses, which is the
 * cross-check that the two agree about record shape.
 *
 * This fills the DATA table at `0x6cdbe6`. It does NOT draw the roster - only the
 * op-0x06 handler does that.
 *
 * SUPERSEDED (2026-08-08, RS1-B §5/§6.1): "Answering this is what releases
 * 'Getting information'". Refuted by two nights of wire: T37's emulator and
 * RS1's PS2 each received AND transport-acked this exact reply (count 1,
 * zeroed 0xF0 charstats) and the dialog never released - both clients starved
 * for ~142 s and closed their sessions (op-0x02). The release condition is
 * downstream of the reply's CONTENT: July's V1 answered count 0 with NO
 * records (`join-window-packets-2026-07-16.txt` pkt 516) and that joiner
 * proceeded straight to op-06/op-10-sub-2. The refined model (H-B): the
 * dialog completes when the client holds usable information for the members
 * the list declared - declaring one member and backing it with nothing is the
 * one state no client has survived. `buildMemberListCount0Payload` below is
 * the July V1 shape; `SNAP_OP0A_COUNT0` selects it.
 */
export const MEMBER_LIST_MAXIMUM_RECORDS = 0x37c;
const MEMBER_LIST_HEADER_BYTES = 0x0c;
const MEMBER_LIST_STATS_BYTES = 0xf0;

/**
 * July V1's op-0x0a reply body, byte for byte: TWELVE ZERO BYTES - no handle
 * echo, no records (`join-window-packets-2026-07-16.txt` pkt 516:
 * `a0 1c 00 0a | token | seq | ack | 000000000000000000000000 | trailer`;
 * V1 source `game_udp_server.js:2187-2199`, the SNAP_MODIFIER_REPLY branch of
 * the July golden set). Word2 = count 0 gates FUN_005c3370 without records
 * (`uRam006cba55 = 1`) and the July joiner proceeded down the ladder. Note the
 * July frame's who is 0xA0 - DATA CLEAR - which is also what routes cmd 0x0a
 * to slot 0x18 at all (`FUN_001d9f78` case 7 requires 0x1000 clear; V1
 * comment at `game_udp_server.js:2083-2084`).
 */
export const MEMBER_LIST_COUNT0_BODY_BYTES = 0x0c;

export function buildMemberListCount0Payload() {
  return Buffer.alloc(MEMBER_LIST_COUNT0_BODY_BYTES);
}

export function buildMemberListPayload({ handleBytes, unknownWord = 0, members = [] }) {
  if (!Buffer.isBuffer(handleBytes) || handleBytes.length !== 4) {
    fail('MEMBER_LIST_HANDLE', 'the member-list reply echoes the 4 handle bytes verbatim');
  }
  if (!Array.isArray(members)) fail('MEMBER_LIST_SHAPE', 'members must be an array');
  if (members.length > MEMBER_LIST_MAXIMUM_RECORDS) {
    fail('MEMBER_LIST_COUNT',
      `${members.length} records; the client refuses a count at or above ${MEMBER_LIST_MAXIMUM_RECORDS + 1}`);
  }
  const payload = Buffer.alloc(MEMBER_LIST_HEADER_BYTES + members.length * MEMBER_RECORD_BYTES);
  handleBytes.copy(payload, 0x00);
  payload.writeUInt32BE(requireUint32(unknownWord, 'unknownWord'), 0x04);
  payload.writeUInt32BE(members.length, 0x08);
  members.forEach((member, index) => {
    const at = MEMBER_LIST_HEADER_BYTES + index * MEMBER_RECORD_BYTES;
    const name = Buffer.isBuffer(member.name)
      ? member.name
      : Buffer.from(String(member.name ?? ''), 'latin1');
    if (name.length === 0) {
      fail('MEMBER_LIST_NAME_EMPTY',
        `member ${index} has an empty name; the client zeroes a trailing '-' at strlen() and ` +
        'renders the field verbatim, so an empty name is a blank row');
    }
    if (name.length > MEMBER_NAME_BYTES) {
      fail('MEMBER_LIST_NAME_LENGTH',
        `member ${index} name is ${name.length} bytes; the field holds ${MEMBER_NAME_BYTES}`);
    }
    name.copy(payload, at + 0x00);
    payload.writeUInt32BE(requireUint32(member.memberId, `member ${index} memberId`), at + 0x10);
    // The declared blob length IS the stride input: (0xF0 + 0x1B) & ~3 = 0x108.
    // Writing a different value here silently re-strides every following record.
    payload.writeUInt32BE(MEMBER_LIST_STATS_BYTES, at + 0x14);
    if (Buffer.isBuffer(member.charstats)) {
      member.charstats.copy(payload, at + 0x18, 0, Math.min(member.charstats.length, MEMBER_LIST_STATS_BYTES));
    }
  });
  return payload;
}

/**
 * The op-28 selector-0x0a ROSTER RECORD - half of the member-info supply
 * channel V1's golden set ran and V2 lacked (RS1-B §4, flag SNAP_MEMBER_INFO).
 *
 * Sent ALONGSIDE the sel-0x0c completion on every op-0x0c room query, byte
 * shape from the July wire (`join-window-packets-2026-07-16.txt` pkt 500,
 * `b1 24 00 28 | ... | body`; V1 source: the SNAP_CMD0C_MEMBERLIST branch,
 * `game_udp_server.js:2414-2433`):
 *
 * ```
 * +0x00  BE32 0x0a      the selector - dispatcher case 9, DATA-set -> the
 *                       count-setter FUN_005c2460 (slot 0x19), which fills
 *                       0x6cdbe6 AND sets the count 0x70047c
 * +0x04  BE32 0         unread
 * +0x08  LE32 count     the July-proven byte order (V1 writeUInt32LE)
 * +0x0c  records        name[16] | BE32 id @+0x10 | LE32 0x108 @+0x14 |
 *                       0xf0 data @+0x18  (stride 0x108)
 * ```
 * The frame flags are the caller's default SET|DATA - the July wire's 0xB1xx.
 */
export function buildRosterRecordPayload({ members }) {
  if (!Array.isArray(members) || members.length === 0) {
    fail('ROSTER_RECORD_MEMBERS', 'a roster record declares at least one member');
  }
  if (members.length > 4) {
    fail('ROSTER_RECORD_MEMBERS', `${members.length} members; the client table holds 4`);
  }
  const payload = Buffer.alloc(MEMBER_LIST_HEADER_BYTES + members.length * MEMBER_RECORD_BYTES);
  payload.writeUInt32BE(0x0000000a, 0x00);
  payload.writeUInt32LE(members.length, 0x08);
  members.forEach((member, index) => {
    const at = MEMBER_LIST_HEADER_BYTES + index * MEMBER_RECORD_BYTES;
    const name = Buffer.isBuffer(member.name)
      ? member.name
      : Buffer.from(String(member.name ?? ''), 'latin1');
    if (name.length === 0 || name.length > MEMBER_NAME_BYTES) {
      fail('ROSTER_RECORD_NAME', `member ${index} name must be 1..${MEMBER_NAME_BYTES} bytes`);
    }
    name.copy(payload, at);
    payload.writeUInt32BE(requireUint32(member.memberId, `member ${index} memberId`), at + 0x10);
    payload.writeUInt32LE(0x00000108, at + 0x14);
    // The 0xf0 data blob stays zero - the July-proven content.
  });
  return payload;
}

/**
 * The op-0x10 sub-1 PLAYER-INFO push - the other half of the supply channel,
 * and the message V1 sent (a) proactively after the enter accept and (b) in
 * answer to EVERY inbound game-channel op-0x10 (July pkts 505/534/549/553/561,
 * `a3 14 00 10`; V1 source `sendRoomInfoOp10`, `game_udp_server.js:955-978`).
 *
 * Payload = `[BE32 1][BE32 0][u8 sub=1 + pad][BE32 0][u8 role + pad][zeros]`,
 * 0x304 bytes total (4-byte header word + 0x300 blob), so the frame's inner
 * length is the July wire's 0x314. Client handler: slot 0x13 FUN_005bba20
 * case 1 -> FUN_005bbb90, which flips the room screen 0x6cbc7e -> 0x10 and
 * fires UI event 0xc BUILD ROOM. The role byte at blob+4 (wire +0x20) writes
 * 0x6c5539, the create-screen fork: 1 = HOST/CREATOR (the STAT mint path),
 * 0 = JOINER (member-register burst). Both values are on the July wire
 * (pkt 505 role 1, pkt 534 role 0). Frame flags must leave DATA and 0x0400
 * CLEAR (who 0xA0/0xA3) or the dispatcher routes it to a dead slot.
 */
export const PLAYER_INFO_BLOB_BYTES = 0x300;
export const PLAYER_INFO_PAYLOAD_BYTES = 4 + PLAYER_INFO_BLOB_BYTES;
const PLAYER_INFO_ROLE_OFFSET = 0x10;

export function buildPlayerInfoPayload({ role = 0 } = {}) {
  if (role !== 0 && role !== 1) {
    // 2 is the client's ERROR arm of the 0x6c5539 fork; nothing else is defined.
    fail('PLAYER_INFO_ROLE', `role must be 0 (joiner) or 1 (host/creator), not ${role}`);
  }
  const payload = Buffer.alloc(PLAYER_INFO_PAYLOAD_BYTES);
  payload.writeUInt32BE(1, 0x00);
  payload[ROOM_EVENT_SUB_OFFSET] = 0x01;
  payload[PLAYER_INFO_ROLE_OFFSET] = role;
  return payload;
}

/**
 * The op-0x09 counted reply: `[handle echo][tag echo][BE32 value]`.
 *
 * The handle echo must match the request or `FUN_005c0060` discards the value -
 * and still completes the task, so the screen advances carrying a wrong number
 * rather than hanging. That failure mode is why this echoes verbatim.
 */
export function buildAreaCountReplyPayload({ handleBytes, tag, value }) {
  if (!Buffer.isBuffer(handleBytes) || handleBytes.length !== 4) {
    fail('AREA_COUNT_HANDLE', 'the reply echoes the 4 handle bytes verbatim');
  }
  if (!Buffer.isBuffer(tag) || tag.length !== 4) {
    fail('AREA_COUNT_TAG', 'the reply echoes the 4 tag bytes verbatim');
  }
  const payload = Buffer.alloc(0x0c);
  handleBytes.copy(payload, 0x00);
  tag.copy(payload, 0x04);
  payload.writeUInt32BE(requireUint32(value, 'value'), 0x08);
  return payload;
}

/**
 * The op-0x28 SELECTOR-8 body that answers a named-channel query.
 *
 * ```
 * +0x00  BE32  8       the selector
 * +0x04  BE32  0       swapped by FUN_001d7f6c, unread by both callbacks
 * +0x08  BE32  tag     echoed; FUN_001d861c swaps it
 * +0x0C  BE32  0       swapped because tag != 'NAME', unread
 * ```
 * `FUN_005c29c0` reads only the status and the sub byte. Status 0x27 also
 * completes the task but through the FAILURE path (`FUN_005be9d0`), so this
 * always sends status 0 - the completion status lives in the op-0x28 header,
 * not here.
 */
export const NAMED_CHANNEL_SELECTOR = 8;
export const NAMED_CHANNEL_TAG_STAT = Buffer.from('STAT', 'latin1');

export function decodeNamedChannelRequest(payload) {
  if (!Buffer.isBuffer(payload) || payload.length < 4) {
    fail('NAMED_CHANNEL_RUNT', `an op-0x08 body is at least 4 bytes, not ${payload?.length ?? 0}`);
  }
  return { tag: Buffer.from(payload.subarray(0, 4)) };
}

export function buildNamedChannelCompletionPayload({ tag }) {
  if (!Buffer.isBuffer(tag) || tag.length !== 4) {
    fail('NAMED_CHANNEL_TAG', 'the selector-8 completion echoes the 4 tag bytes verbatim');
  }
  const payload = Buffer.alloc(0x10);
  payload.writeUInt32BE(NAMED_CHANNEL_SELECTOR, 0x00);
  tag.copy(payload, 0x08);
  return payload;
}

/* ---- op-0x0F, chat ------------------------------------------------------ */

/**
 * The chat body, identical in both directions and NOT byteswapped on this path.
 *
 * ```
 * +0x00  u8  type      the SENDER'S screen id (0x6C4B90): 2 lobby, 4 in-room, 0x0C in-game
 * +0x01  u8  selector  0 = chat text; 1 and 2 = the area-name probe, NOT chat
 * +0x02  u8  nameLen
 * +0x03  u8  textLen
 * +0x04  u8  0
 * +0x05  u8  0
 * +0x06      name[nameLen] then text[textLen]
 * ```
 *
 * The same layout decodes the OTHER captured op-0x0F - `00 01 00 09 00 00` then
 * `"OBAREA-V2"`: type 0, selector 1, no name, a 9-byte "text" that is our own area
 * table version. That is the probe. Relaying it would broadcast our version string
 * to every player as though someone had said it, which is why the selector is
 * checked rather than assumed.
 */
export const CHAT_SELECTOR_TEXT = 0;
export const CHAT_NAME_MAXIMUM = 0x10;
export const CHAT_TEXT_MAXIMUM = 0x80;
const CHAT_HEADER_BYTES = 0x06;
/** Anything shorter than the header cannot be a chat line; see the short variant. */
export const CHAT_MINIMUM_BODY_BYTES = CHAT_HEADER_BYTES;

export function decodeChatMessage(payload) {
  if (!Buffer.isBuffer(payload) || payload.length < CHAT_HEADER_BYTES) {
    fail('CHAT_RUNT', `an op-0x0f body is at least ${CHAT_HEADER_BYTES} bytes, not ${payload?.length ?? 0}`);
  }
  const nameLength = payload[0x02];
  const textLength = payload[0x03];
  /*
   * These bounds are memory safety, not tidiness. The receiver `FUN_005BC590`
   * memcpys both fields into fixed globals with NO length check, so an over-long
   * line that we relay is a remote overwrite on every OTHER console in the room -
   * the one place where accepting bad input harms someone who did not send it.
   */
  if (nameLength > CHAT_NAME_MAXIMUM) {
    fail('CHAT_NAME_LENGTH',
      `chat name is ${nameLength}; the client field is ${CHAT_NAME_MAXIMUM} and is memcpyd unchecked`);
  }
  if (textLength > CHAT_TEXT_MAXIMUM) {
    fail('CHAT_TEXT_LENGTH',
      `chat text is ${textLength}; the client field is ${CHAT_TEXT_MAXIMUM} and is memcpyd unchecked`);
  }
  if (payload.length < CHAT_HEADER_BYTES + nameLength + textLength) {
    fail('CHAT_TRUNCATED', 'the declared name and text run past the end of the body');
  }
  return {
    screenType: payload[0x00],
    selector: payload[0x01],
    name: Buffer.from(payload.subarray(CHAT_HEADER_BYTES, CHAT_HEADER_BYTES + nameLength)),
    text: Buffer.from(payload.subarray(
      CHAT_HEADER_BYTES + nameLength, CHAT_HEADER_BYTES + nameLength + textLength
    )),
    /** Only selector 0 is a chat line; 1 and 2 are the area-name probe. */
    isChatText: payload[0x01] === CHAT_SELECTOR_TEXT
  };
}

/**
 * The relay: a fresh op-0x0F carrying the sender's name and text VERBATIM.
 *
 * Verbatim matters more than it looks. `FUN_005B53F0` shows a line on the in-room
 * screen only when its name string matches a populated row of the member table at
 * `0x6C7C2C`, which is filled from the op-0x0a member-list output. Rewriting the
 * name here - prettifying it, trimming it, substituting a display name - makes the
 * line silently invisible to everyone in the room while still looking correct on
 * the wire.
 */
export function buildChatRelayPayload({ screenType, name, text }) {
  const nameBytes = Buffer.isBuffer(name) ? name : Buffer.from(String(name ?? ''), 'latin1');
  const textBytes = Buffer.isBuffer(text) ? text : Buffer.from(String(text ?? ''), 'latin1');
  if (nameBytes.length > CHAT_NAME_MAXIMUM) {
    fail('CHAT_NAME_LENGTH', `relay name is ${nameBytes.length}; the field is ${CHAT_NAME_MAXIMUM}`);
  }
  if (textBytes.length > CHAT_TEXT_MAXIMUM) {
    fail('CHAT_TEXT_LENGTH', `relay text is ${textBytes.length}; the field is ${CHAT_TEXT_MAXIMUM}`);
  }
  const payload = Buffer.alloc(CHAT_HEADER_BYTES + nameBytes.length + textBytes.length);
  payload[0x00] = screenType & 0xff;
  payload[0x01] = CHAT_SELECTOR_TEXT;
  payload[0x02] = nameBytes.length;
  payload[0x03] = textBytes.length;
  nameBytes.copy(payload, CHAT_HEADER_BYTES);
  textBytes.copy(payload, CHAT_HEADER_BYTES + nameBytes.length);
  return payload;
}

/* ---- op-0x10, the in-room state pushes ---------------------------------- */

/** 16 bytes: `[BE32 1][4 zero][u8 sub @+0x08][3 zero][LE32 value @+0x0c]`. */
export const ROOM_STATE_PAYLOAD_BYTES = 0x10;
const ROOM_STATE_SUB_OFFSET = 0x08;
const ROOM_STATE_VALUE_OFFSET = 0x0c;

/**
 * The in-room header push, op-0x10 sub-5: `max` then `current`, both u8.
 *
 * Wire `+0x1c`/`+0x1d` in V1's frame is payload `+0x0c`/`+0x0d` here, because the
 * 16-byte SN@P header is the channel's, not this module's. The leading word is 1,
 * mirroring the proven sub-0x11 push whose frame this shares
 * (`game_udp_server.js:1104-1130`); why 1 rather than 0 is Unknown and it is
 * reproduced rather than tidied.
 *
 * Must be RE-ASSERTED after every screen rebuild: the client zeroes `0x6ff2b4` on
 * each one and this is its only non-zero writer.
 */
export function buildRoomLimitsPayload({ max, current }) {
  if (!Number.isSafeInteger(max) || max < 1 || max > 0xff) {
    fail('ROOM_LIMITS', `max must be 1..255, not ${max}`);
  }
  if (!Number.isSafeInteger(current) || current < 0 || current > 0xff) {
    fail('ROOM_LIMITS', `current must be 0..255, not ${current}`);
  }
  const payload = Buffer.alloc(ROOM_STATE_PAYLOAD_BYTES);
  payload.writeUInt32BE(1, 0x00);
  payload[ROOM_STATE_SUB_OFFSET] = ROOM_STATE_SUB.ROOM_LIMITS;
  payload[ROOM_STATE_VALUE_OFFSET] = max;
  payload[ROOM_STATE_VALUE_OFFSET + 1] = current;
  return payload;
}

/**
 * The room-ENTER request body: the JOIN half of inbound op-0x06.
 *
 * `FUN_001dcdfc` builds a FIXED `0x18`-byte body (declared inner length
 * `0x28`); the area-ENTER form declares `0x14` with a 4-byte body. The room
 * handle sits at body `+0x00` in the SAME LITTLE-endian bytes the op-0x49
 * record advertised at `+0x24` - "the client ENTERs it back in the same LE
 * bytes, so msg.readUInt32LE(0x10) = the registry handle directly"
 * (`server/game_udp_server.js:1780-1786`, the V1 rig path;
 * `G12-create-accept-wireformat-RE-2026-07-12.md` M2). The name field at
 * `+0x09` carried the PLAYER-TYPED title on the one captured create and was
 * EMPTY on the one captured join - so a non-empty name with a zero handle is
 * the Vacant-slot-create form, not a join.
 */
export const ROOM_ENTER_REQUEST_BYTES = 0x18;
const ROOM_ENTER_NAME_OFFSET = 0x09;

export function decodeRoomEnterRequest(payload) {
  if (!Buffer.isBuffer(payload) || payload.length < ROOM_ENTER_REQUEST_BYTES) {
    fail(
      'ROOM_ENTER_RUNT',
      `a room-ENTER body is the fixed ${ROOM_ENTER_REQUEST_BYTES} bytes FUN_001dcdfc builds, ` +
      `not ${payload?.length ?? 0}`
    );
  }
  const nameField = payload.subarray(ROOM_ENTER_NAME_OFFSET, ROOM_ENTER_REQUEST_BYTES);
  const end = nameField.indexOf(0);
  return {
    /** Opaque, resolved via `resolveRoomHandleBytes` (LE is the proven order). */
    handleBytes: Buffer.from(payload.subarray(0, 4)),
    name: nameField.subarray(0, end === -1 ? nameField.length : end).toString('latin1')
  };
}

/**
 * Decode an inbound op-0x10 game-channel event:
 * `[BE32 count][BE32 senderHandle]...[u8 sub][data...]`.
 *
 * The frame is `func_0x001df380(conn, 0x8000, payload, len, count, handle)` -
 * the count and handle words prefix the app payload (B1-GAME-START-MODEL.md §2
 * item 5, the sender-frame note, which always contained the correct reading).
 *
 * SUPERSEDED (2026-08-08, RS1-B §2/§6.2): the `[nRecipients][recipientId]...`
 * recipient-list interpretation of these words. Both wire instances that exist
 * contradict it - July's `02f807d0` and RS1's `00000003` are each the SENDER'S
 * OWN handle, the value the client holds at `0x6febe8` (the create-path room
 * handle for a creator; the member handle the sub-1 push delivered for a
 * joiner). A "this is me / my room" scope word, never an addressee. A relay
 * that resolved it against roster ids could deliver to nobody by construction
 * (`relayed: 0` was structural), and matching it against presenceId is a live
 * cross-type collision hazard (RS1: PS2 presenceId 3 vs room handle 3). The
 * words are decoded for the journal and for structural validation ONLY; relay
 * scope is the sender's own room, from presence, exactly like chat.
 */
export const ROOM_EVENT_MAXIMUM_WORDS = 8;
export const ROOM_EVENT_SUB_OFFSET = 0x08;

export function decodeRoomEvent(payload) {
  if (!Buffer.isBuffer(payload) || payload.length < 4) {
    fail('ROOM_EVENT_RUNT', `an op-0x10 body carries at least a count word, not ${payload?.length ?? 0}`);
  }
  const wordCount = payload.readUInt32BE(0);
  if (wordCount < 1 || wordCount > ROOM_EVENT_MAXIMUM_WORDS) {
    fail(
      'ROOM_EVENT_RECIPIENTS',
      `${wordCount} handle words; every observed frame carries 1 and the bound here is ` +
      `${ROOM_EVENT_MAXIMUM_WORDS}`
    );
  }
  const subOffset = 4 + 4 * wordCount;
  if (payload.length < subOffset + 1) {
    fail('ROOM_EVENT_RUNT', 'the declared handle words run past the end of the body');
  }
  const words = [];
  for (let index = 0; index < wordCount; index += 1) {
    words.push(payload.readUInt32BE(4 + 4 * index));
  }
  return {
    wordCount,
    /** The sender's own `0x6febe8` handle - diagnostics, never routing. */
    senderHandle: words[0],
    words,
    sub: payload[subOffset],
    subOffset
  };
}

/**
 * The JOIN-CONFIRM push, op-0x10 app sub `0x0c` - the rig-proven V1 fix
 * (`SNAP_JOIN_OP10_SUBC`, Pi cead951e, 2-device), ported byte for byte from
 * `server/game_udp_server.js:1887-1906`:
 *
 * ```
 * +0x00  BE32 1        header word, mirroring the proven sub-1 push
 * +0x04  [4]           the REQUEST's own word at +0x04, echoed verbatim
 *                      (FUN_005bbe00 never reads it; V1 echoed it and that is
 *                      the form that rendered)
 * +0x08  0C 00 00 00   the sub-selector: FUN_005bba20 case 0xc -> FUN_005bbe00
 *                      fires the stored continuation 0x601300 (major 5 -> 6)
 * +0x0c  LE32 count    the displayed member count (payload+4 in FUN_005bbe00)
 * ```
 */
export function buildJoinConfirmPayload({ requestEcho = null, count }) {
  if (!Number.isSafeInteger(count) || count < 1 || count > 0xff) {
    fail('JOIN_CONFIRM_COUNT', `count must be 1..255, not ${count}; any non-zero value advances the SM`);
  }
  if (requestEcho != null && (!Buffer.isBuffer(requestEcho) || requestEcho.length !== 4)) {
    fail('JOIN_CONFIRM_ECHO', 'requestEcho is the request\'s 4 bytes at +0x04, verbatim');
  }
  const payload = Buffer.alloc(ROOM_STATE_PAYLOAD_BYTES);
  payload.writeUInt32BE(1, 0x00);
  if (requestEcho != null) requestEcho.copy(payload, 0x04);
  payload[ROOM_EVENT_SUB_OFFSET] = ROOM_EVENT_SUB.JOIN_CONFIRM;
  payload.writeUInt32LE(count, ROOM_STATE_VALUE_OFFSET);
  return payload;
}

/** The member-count push, op-0x10 sub-0x11: `FUN_005bbea0` reads a LE32 count. */
export function buildMemberCountPayload({ count }) {
  if (!Number.isSafeInteger(count) || count < 0 || count > 0xff) {
    fail('MEMBER_COUNT', `count must be 0..255, not ${count}`);
  }
  const payload = Buffer.alloc(ROOM_STATE_PAYLOAD_BYTES);
  payload.writeUInt32BE(1, 0x00);
  payload[ROOM_STATE_SUB_OFFSET] = ROOM_STATE_SUB.MEMBER_COUNT;
  payload.writeUInt32LE(count, ROOM_STATE_VALUE_OFFSET);
  return payload;
}

/**
 * The SN@P APPLICATION keepalive body, op-0x10 with app-payload byte 0x00:
 * `[BE32 count=1][BE32 handle][u8 0x00]`, 9 bytes
 * (`docs/design/v2-port/ROOM-WATCHDOG-RE.md` §3.2).
 *
 * The sub byte 0x00 is the WHOLE point: the op-0x10 handler `FUN_005bba20`
 * calls the application-liveness watchdog reset `FUN_005c7d00()` as its FIRST
 * statement, before the sub-selector switch, and that switch has no default
 * case (cases 1..0x11 only) - so a sub of 0x00 resets the client's
 * 1800+1800-tick (~145.7 s) self-close watchdog and does nothing else. No
 * UI coupling, no state coupling.
 *
 * The handle word mirrors the client's own `0x6febe8` scope word ("this is
 * me / my room" - RS1-B §2, never routing): the room handle when the session
 * is in a room, 0 on the lobby floor. The sub-0x00 path never consults it;
 * it is carried so the frame stays shaped like every other op-0x10 push.
 */
export const APP_KEEPALIVE_PAYLOAD_BYTES = 9;

export function buildAppKeepalivePayload({ handle = 0 } = {}) {
  const payload = Buffer.alloc(APP_KEEPALIVE_PAYLOAD_BYTES);
  payload.writeUInt32BE(1, 0x00);
  payload.writeUInt32BE(requireUint32(handle, 'handle'), 0x04);
  // payload[ROOM_EVENT_SUB_OFFSET] (0x08) stays 0x00 - the no-op sub byte.
  return payload;
}

/* ---- op-0x10 sub-7, the IN-ROOM text fragment --------------------------- */

/**
 * The in-room chat vehicle (ROOMCHAT-SCENARIO-WIRE-2026-08-24.md §1): the
 * in-room text surface does NOT read the op-0x0F scrollback - `FUN_005bba20`
 * case 7 → `FUN_005bc1c0` memcpys `{slot@app+4, len@app+5, offset@app+6,
 * data@app+8}` into the per-player buffer `0x6fffd1 + slot*0x114`, gated by
 * `0x6ff2b1`. The app payload begins at the sub byte (message payload +0x08),
 * so message-payload offsets are +0x08 higher. Header words mirror the other
 * sub pushes (word0 = 1). Single fragment, offset 0.
 *
 * Grades: the receiver chain is decompile-Confirmed; the exact header-word
 * echo and the 0-based slot (= playernum - 1, the presence-slot identity the
 * allocator documents) are Inference pending one rig render — the PINE
 * falsifier is a watch on `0x6fffd1 + slot*0x114` while a line is sent.
 */
export const ROOM_CHAT_FRAGMENT_MAX_TEXT = 0xff;

export function buildRoomChatSub7Payload({ slot, text }) {
  if (!Number.isSafeInteger(slot) || slot < 0 || slot > 3) {
    fail('ROOM_CHAT_SUB7', `slot must be 0..3 (playernum-1), not ${slot}`);
  }
  if (!Buffer.isBuffer(text) || text.length < 1 || text.length > ROOM_CHAT_FRAGMENT_MAX_TEXT) {
    fail('ROOM_CHAT_SUB7', `text must be 1..${ROOM_CHAT_FRAGMENT_MAX_TEXT} bytes`);
  }
  const payload = Buffer.alloc(0x10 + text.length);
  payload.writeUInt32BE(1, 0x00);            // word0 = 1, as the sub-5/keepalive pushes
  // word1 (0x04) stays 0
  payload[0x08] = 0x07;                      // sub-event 7 -> FUN_005bc1c0
  payload[0x0c] = slot;                      // app+4: per-player buffer index
  payload[0x0d] = text.length;               // app+5: fragment length
  // app+6 (0x0e..0x0f): fragment offset, 0 - single fragment
  text.copy(payload, 0x10);                  // app+8: the text bytes
  return payload;
}

/* ---- op-0x04, the CREATE request --------------------------------------- */

/** `0x2c` bytes, per `CORRECTIONS.md` C-4 - offsets Confirmed, roles as marked. */
export const CREATE_ROOM_REQUEST_BYTES = 0x2c;
const CREATE_NAME_OFFSET = 0x00;
const CREATE_NAME_BYTES = 0x10;
const CREATE_MAXIMUM_OFFSET = 0x10;
const CREATE_PASSWORD_OFFSET = 0x14;
const CREATE_PASSWORD_BYTES = 0x10;
const CREATE_UNKNOWN24_OFFSET = 0x24;
const CREATE_OPTIONS_OFFSET = 0x28;

/**
 * Decode the op-0x04 CREATE request.
 *
 * Field OFFSETS are Confirmed from `func_0x001dc508`; the ROLES are not all
 * settled and are named for what the corpus can defend:
 *
 *   `+0x00` `name[16]`, strcpy from `0x6CC01A` - the room title. Confirmed.
 *   `+0x10` BE32 of a u16 from `0x6CA888`. "max players" is **Likely**, not
 *           Confirmed: `0x6CA888` is loaded from `DAT_00640528` alongside two
 *           bytes written `min+1`/`max+1`, which is consistent with a ceiling
 *           and is not proof of one.
 *   `+0x14` `password[16]`, strcpy from `0x6CC03B`, or a SINGLE zero byte when
 *           the pointer is null. Confirmed.
 *   `+0x24` BE32 of a u16 - the literal `1` passed explicitly by the create pump.
 *           Role **unknown**; the older "flags" label is refuted.
 *   `+0x28` BE32 of `*(0x6FEBE4) << 1`, a packed rules/options word
 *           OR-accumulated from rule bits and two constant tables just before the
 *           send. Refuted as a bare scenario id.
 *
 * The 40-byte `name|max|password|flags|scenario` map in
 * `CREATE-ROOM-GATES-RE.md` section 5 is SUPERSEDED - it does not even sum to the
 * `0x2c` the same paragraph names (`CORRECTIONS.md` C-4).
 *
 * Never throws on peer input: a short payload yields nulls for what is missing,
 * because the accept below does not depend on any of these fields and a malformed
 * request must not become an unanswered one.
 */
export function decodeCreateRoomRequest(payload) {
  if (!Buffer.isBuffer(payload)) fail('NOT_A_BUFFER', 'a create request payload must be a Buffer');
  const readString = (at, length) => {
    if (payload.length < at + 1) return null;
    const field = payload.subarray(at, Math.min(at + length, payload.length));
    const end = field.indexOf(0);
    return field.subarray(0, end === -1 ? field.length : end).toString('latin1');
  };
  const readWord = (at) => (payload.length >= at + 4 ? payload.readUInt32BE(at) : null);
  return {
    /** Empty in every observed run so far: the typed title never reached `0x6CC01A`. */
    name: readString(CREATE_NAME_OFFSET, CREATE_NAME_BYTES),
    maximumPlayers: readWord(CREATE_MAXIMUM_OFFSET),
    password: readString(CREATE_PASSWORD_OFFSET, CREATE_PASSWORD_BYTES),
    unknownWord24: readWord(CREATE_UNKNOWN24_OFFSET),
    optionsWord: readWord(CREATE_OPTIONS_OFFSET),
    /** True when the client sent the whole struct the builder allocates. */
    complete: payload.length >= CREATE_ROOM_REQUEST_BYTES
  };
}

/* ---- op-0x40, the keepalive -------------------------------------------- */

/**
 * The keepalive body: `0x110` bytes of Blowfish-ECB ciphertext followed by four
 * zero bytes.
 *
 * `encryptZeroBlock` is injected rather than imported so that this module stays
 * a codec: it takes the ciphertext of `KEEPALIVE_PLAINTEXT_BYTES` zero bytes and
 * checks its length, and the caller owns the key schedule (which is expensive
 * enough - 521 block encryptions - that it must be built once, not per send).
 */
export function buildKeepalivePayload(ciphertext) {
  if (!Buffer.isBuffer(ciphertext) || ciphertext.length !== KEEPALIVE_PLAINTEXT_BYTES) {
    fail(
      'KEEPALIVE_CIPHERTEXT',
      `the keepalive ciphertext must be exactly ${KEEPALIVE_PLAINTEXT_BYTES} bytes, ` +
      `got ${Buffer.isBuffer(ciphertext) ? ciphertext.length : typeof ciphertext}`
    );
  }
  const payload = Buffer.alloc(KEEPALIVE_BODY_BYTES);
  ciphertext.copy(payload, 0);
  return payload;
}

/* ---- op-0x29, the success transition ----------------------------------- */

/**
 * `[BE32 0][BE32 anything][the request's wire+0x04 bytes REVERSED]`.
 *
 * `+0x00` must be zero so `FUN_001d507c` skips the port write; `+0x08` is
 * compared against a byte-reversed copy of the token and, if it does not match,
 * every later client message carries a different token and the session is over.
 *
 * NEVER CAPTURED. This whole message is disassembly-grade only
 * (`1daf7c-1db01c`, gap table X3) and is why the caller gates it behind
 * configuration that defaults to off - the keepalive alone defers 840
 * indefinitely, which is the path the archive proves.
 */
export function buildSuccessTransitionPayload({ endpointToken, freeWord = 0 }) {
  const token = Buffer.alloc(4);
  token.writeUInt32BE(requireUint32(endpointToken, 'endpointToken'), 0);
  const payload = Buffer.alloc(12);
  payload.writeUInt32BE(0, 0x00);
  payload.writeUInt32BE(requireUint32(freeWord, 'freeWord'), 0x04);
  for (let index = 0; index < 4; index += 1) payload[0x08 + index] = token[3 - index];
  return payload;
}

/* ---- op-0x49, the room list -------------------------------------------- */

/**
 * `[BE32 0][BE32 0][BE32 count]` then `count` records of `0x28`.
 *
 * Field placement and endianness are rig-derived, not decompiled: the display
 * fields at `+0x14` (current), `+0x1c` (flags) and `+0x20` (max) are byteswapped
 * by `FUN_001d7d20` before the client reads them, so they go out BIG-endian -
 * V1 shipped them little-endian and the list rendered "0/0" for every room
 * (`SNAP_OP49_BE`, G12 2026-07-17). The handle at `+0x24` is deliberately the
 * exception: it is opaque, it round-trips through the client's `0x6fee68` table
 * and comes back in the ENTER request, and the LITTLE-endian form is the one
 * whose round trip is rig-proven. Flipping it "for consistency" would break a
 * working path to fix nothing.
 */
export function buildRoomListPayload({ rooms }) {
  if (!Array.isArray(rooms)) fail('ROOMS_REQUIRED', 'rooms must be an array');
  if (rooms.length > MAXIMUM_ROOM_LIST_RECORDS) {
    fail(
      'TOO_MANY_ROOMS',
      `${rooms.length} rooms exceed the ${MAXIMUM_ROOM_LIST_RECORDS} a SN@P message can carry`
    );
  }
  const payload = Buffer.alloc(ROOM_LIST_HEADER_BYTES + rooms.length * ROOM_LIST_RECORD_BYTES);
  payload.writeUInt32BE(0, 0x00);
  payload.writeUInt32BE(0, 0x04);
  payload.writeUInt32BE(rooms.length, 0x08);
  rooms.forEach((room, index) => {
    const at = ROOM_LIST_HEADER_BYTES + index * ROOM_LIST_RECORD_BYTES;
    const name = Buffer.isBuffer(room?.name)
      ? room.name
      : Buffer.from(String(room?.name ?? ''), 'latin1');
    // 20 bytes of name, then the numeric fields. A name that reached +0x14 would
    // overwrite the current-players word the row renders.
    if (name.length > 0x14 - 1) {
      fail('ROOM_NAME_LENGTH', `room ${index} name is ${name.length} bytes; the field holds 0x14`);
    }
    name.copy(payload, at);
    payload.writeUInt32BE(requireUint32(room?.current ?? 0, `room ${index} current`), at + 0x14);
    payload.writeUInt32BE(requireUint32(room?.flags ?? 0, `room ${index} flags`), at + 0x1c);
    payload.writeUInt32BE(requireUint32(room?.max ?? 0, `room ${index} max`), at + 0x20);
    payload.writeUInt32LE(requireUint32(room?.handle ?? 0, `room ${index} handle`), at + 0x24);
  });
  return payload;
}
