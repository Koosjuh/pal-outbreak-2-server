# Server gap analysis

Date: 2026-07-28
Compared tree: `e2ba1a9315639a5a0f10dc45c8741959009f7b2d`

## Executive finding

The current server is a compatibility research implementation with a proven
transport and a substantial pre-game path. It is not yet a complete
interoperable multiplayer server. The deepest demonstrated state is:

- creator and real-PS2 joiner can both reach room screens in the July 16 golden;
- on July 26, a creator-only run received a correctly ordered op06 and had the
  right roster row, current count and maximum count in client memory;
- visible creator roster refresh, synchronized room configuration, chat,
  character selection, ready/start, gameplay and robust leave/reconnect are not
  proven.

Evidence: `GOLDENS.md:28-84`;
`docs/findings/protocol/SESSION-LOG-2026-07-25.md:206-229`.

V2 is intentionally much earlier in the real-client path. As of 2026-08-02 it
locally reproduces canonical `0x1007`, empty-manifest `0x6103`, BE32 `0x6212`,
the decoded/runtime-captured `0x6203` mode-2 exchange, and canonical BE32
`0x6211`, canonical/client-default `0x6213`, exact `0x6501`, normal `0x6502` mode boundaries,
normal `0x6504` variable record batches, normal `0x6510` record-key batches, and the terminal
`0x1004` lobby-initialization completion. A real local socket now walks that entire ladder
byte-exactly, including the looped `0x6502`/`0x6504`/`0x6510` batches and the `0x6203`
major-state-4 re-entry. It still stops at the next-entry `0x6502` after a complete `0x6504`
batch and at `0x6503` on the separate `0x6501` mode-1 path; the connection close after `0x1004` is
deliberately not modeled. No V2 real-client run or Pi deployment has occurred
(`SESSION-LOG-2026-08-01.md` T1-T5; `SESSION-LOG-2026-08-02.md` T6-T12).

## Demonstrated capabilities

| Capability | Demonstration level | Evidence |
|---|---|---|
| DNS/HTTP/DNAS compatibility login | Real client reaches later services | Goldens and current server composition; production auth semantics not proven |
| TCP PAL framing and server-data walk | Real client reaches server selection | `server/snap_server.js:284-390,855-1603`; `GOLDENS.md:112-118` |
| UDP registration/bind | Real client reaches area selection | `analysis/snap-focused-callgraph.md:85-155`; goldens |
| Reliable ACKs, ordering, keepalive | Runtime/client-code proof | `L1...:342-359`; `op06-accept-criterion...:42-107` |
| Area list/counts and repeated area entry/back | Owner-witnessed real PS2 + emulator golden | `GOLDENS.md:53-109` |
| Valid vacant room list | Owner-witnessed golden | `GOLDENS.md:53-84` |
| Room creation | Runtime reaches creator room; registry populated | G12 findings; T13 session log |
| Room join | Emulator creator + real PS2 joiner both reached room screens | `GOLDENS.md:28-51` |
| Creator roster/count/max memory | PINE-verified in T13 | `SESSION-LOG...:206-229` |
| Local lobby state/engine logic | Unit/integration tests | `server/*.test.*`, `tests/lobby_lifecycle.test.cjs` |

“Demonstrated” does not mean a complete production slice. For example, room
join is demonstrated only through both clients entering room screens, not
mutual roster/chat/start/gameplay.

## Incorrect or unsafe assumptions

| Gap | Current implementation | Why it is unsafe/incorrect | Required correction |
|---|---|---|---|
| KDDI/PAL conflation | Command enum and comments retain Bio-Serv names | PAL repurposes IDs (`0x6103`, `0x6211...`) and moves later features to UDP | Keep KDDI names in a separate reference namespace; require PAL function/capture for every wire mapping |
| TCP status fetch `0x6320` | Handler assumes a generic key/offset/size chunk shape | Code explicitly states parser shape was never confirmed | Decode `FUN_001c8ae0` reads/branches and add deterministic fixture before relying on it (`snap_server.js:1536-1561`) |
| Hard-coded/minimal login | Zero token/hash/final and minimal resume fields | Advances current client but is not an authenticated session design | First specify PAL credential/session semantics; retain local compatibility mode separately |
| V1 `0x6212` literal | Always returns BE32 value 1 and labels it player count | Width and advancement are PAL-proven, but the field's PAL domain/source is not | V2 uses `FUN_001c4360`'s payload-less status-`0xff` client default unless an explicit provider exists |
| V1 `0x6211` literal | Always returns BE32 value 0 | Width and state routing are PAL-proven, but no decoded consumer establishes the field's domain/source | V2 uses `FUN_001c45f0`'s scoped client-default branch unless explicitly overridden |
| V1 `0x6213` zeros | Always returns eight zero u16 words and labels them after-game stats | Complete meanings/normal values are unproven and BioServer uses a different layout | V2 uses `FUN_001c4450`'s scoped client-default branch unless explicitly overridden; V1 zeros are not copied |
| Synthetic server records | Strings `OPEN`, `Test Slot`, fixed host and count fallbacks | Useful compatibility scaffolding, not proven server semantics | Replace only field-by-field after decoded/parser/runtime evidence (`snap_server.js:1333-1359`) |
| Broad op48 reply behavior | `SNAP_OP48_REPLY_ALL=1` in tracked config | Can answer tags/contexts without proving the consumer expects the area-record layout | Classify query tag/context and reply only with a proven matching record |
| Multiple simultaneous op49 paths | `ROOMLIST_REGISTRY=1`, `ROOMLIST_ONE=1`, and `ROOMLIST_REPLY=1` are all tracked on | Branch priority hides which implementation is active; fixture and registry semantics coexist | Choose one evidenced registry path per test; retire fixture branches after regression coverage |
| Opaque room handle treatment | Some test/legacy paths inject `0x00010001` | Handle meaning/endianness is not semantically decoded; only round-trip is proven | Keep handle opaque, allocate without interpreting bit fields, fixture-test byte preservation |
| Experimental PINE/runtime pokes in code | Auto-advance and diagnostic branches remain, some default behavior historically on | A server must not depend on emulator memory modification | Keep `SNAP_PINE_AUTO_ADVANCE=0`; separate/delete only after provenance and golden recovery are preserved |
| Reliable send logic is dispersed | Builders/branches select sequences and retries independently | July 26 proved one misordered push can be silently dropped | Funnel production sends through one per-session ordered/retransmit API; do not broad-refactor until fixture parity exists |
| Delayed op06 “settle” | HEAD can resend self op06 after 500 ms | No logged test proves it refreshes; duplicate-delta behavior is unknown | Test exactly once against T13 baseline; if no visible transition, revert/disable and trace overlay event |

## Missing or incomplete handlers

| Feature | Client evidence present | Server status | Gap classification |
|---|---|---|---|
| TCP commands `0x6131/32`, `0x6190`, `0x6202/07`, `0x6210`, `0x6301`, `0x6002` | Names/IDs in enum, incomplete PAL handler traces | No `HANDLERS` entry | Unknown whether current flow legitimately skips them |
| op10 sub3, sub6–9 | Overlay routes/partial memory effects decoded | No complete authoritative builders/order | Missing |
| Lobby chat | KDDI intent only; no PAL opcode | None | Unknown opcode/layout |
| Password | UI/rule structures exist; wire publication/comparison not proven | No authoritative password lifecycle | Missing |
| Character selection/charstats | Buffers and synthetic charstats builders exist | No captured selection publication/roster sync | Placeholder |
| Ready/unready | Start gates partly decoded | No PAL opcode/handler | Missing |
| Start transition | Host gate and KDDI lifecycle are hints | No complete PAL state transition | Missing |
| Gameplay session | `2.DAT` networking decoded as a corpus | No PAL endpoint/session handler | Missing |
| In-game relay/sync | `nbSendPlayerOther` strings/calls exist | No relay or authoritative game state | Missing |
| Reconnect/resume | State model deduplicates endpoints locally | No captured PAL resume contract | Missing |

## Packet length/layout gaps

| Message | Known | Missing/risk |
|---|---|---|
| TCP frame | Exact 8-byte header | Dedicated fragmented/coalesced stream fixture |
| UDP header/trailer | Exact common framing | General `0x2000/0x1000` routing semantics |
| Register op2c/op2d | Request offsets and handler logic | Full optional tail, exact reply length/key derivation |
| Bind op01 | Runtime role and approximate observed size | Complete body fields and response contract |
| op48 | Record stride and active count field | Query variants and meanings of four other numeric fields |
| op49 | Request tags, four subqueries, response stride/current/max/handle | Exact meanings of name/id/status/aux fields and subquery-specific response content |
| op04 | Acceptance callback | Complete create request field layout |
| op06 entry | Selector-6 completion requirement | Complete phase-dependent request body |
| op06 member join | Member ID/name/charstats and total current builder size | Reserved fields, duplicate semantics, correct visible-refresh ordering |
| op07 member leave | LE ID and fixture size | Complete request/response ordering and host-dissolve proof |
| op0a | `0x118` member record model | Outer status/count fields and authoritative byte order for all fields |
| op10 | Subselector offset and several consumers | Exact lengths/layouts for most subcommands |
| close/leave | Transport ACK requirement and timer fallback | Which app messages/ordering produce immediate clean exit |

## Endianness audit

| Region | Current conclusion | Server risk |
|---|---|---|
| TCP frame and decoded integer payloads | Big-endian | Mostly consistent |
| UDP length/flags, opcode word, reliable seq/ack | Big-endian serialized fields | Mostly consistent |
| op49 displayed numeric fields | Client byte-swaps; current writer uses BE under `SNAP_OP49_BE` | Flag-off/legacy branch can send wrong values |
| op49 room handle | Opaque/native round-trip; current proven writer uses LE | Do not “fix” to BE based on aesthetics |
| op06/op07 member ID | Native/LE client reads in mapped handlers | Local op07 fixture enforces LE; audit all op06 builders |
| Charstats and opaque blobs | Mixed/native structure; field-level only | `SNAP_DISTINCT_CHARID` writes are experimental and not a full layout proof |

## State-transition gaps

1. The active server path is flag-assembled rather than a single explicit state
   machine. The authoritative `lobby_engine` exists, but tracked runtime config
   disables it (`deploy/.../00-pal-server.conf:27-29`).
2. Create acceptance, member-JOIN, member list, limit update and room info can be
   emitted from separate branches. Their ordering is not represented as one
   tested transaction.
3. July 26 proves client reliable ordering is part of the application contract:
   correct bytes sent at a stale sequence do not reach the handler.
4. Joiner room-screen entry does not imply roster/config convergence.
5. Leave tests prove the local model’s desired emission order, not the PAL
   client’s complete close/ack/transition.

## Hard-coded and placeholder inventory

Representative compatibility scaffolding:

- TCP record labels/host/status: `server/snap_server.js:1333-1359`.
- Zero/minimal login seed: `server/snap_server.js:846-853`.
- Zero/inert chunks and status records: `server/snap_server.js:941-973,1474-1561`.
- Seed/fixture room and constant test handle:
  `server/game_udp_server.js:2257-2269,2315-2337`.
- Default synthetic member names/charstats and distinct-character experiment:
  `server/game_udp_server.js:981-1023,1053-1105,1127-1163`.
- Raw push/test controls (`SNAP_ROOM_PUSH`, `SNAP_CMD0C_TEST`, render probes):
  `server/game_udp_server.js:2443-2719`.
- Explicit `SNAP_TEST_FORCE_GOLIVE` test scaffold:
  `server/game_udp_server.js:1696-1708,1795-1810`.

These must not be deleted merely for cleanliness: several preserve working
compatibility or experimental provenance. Each should move behind a named
fixture/test or be retired only after a golden-equivalent deterministic path is
proven.

## Decoded code not yet incorporated into the protocol

| Decoded area | Repository source | Missing synthesis |
|---|---|---|
| Full `2.DAT/game.bin` corpus | `analysis/claude-game-module-full-2026-05-29.txt` | Sender/receiver inventory, wire offsets, dispatch, gameplay state effects |
| Non-3.DAT overlay/module scan | `RE-overlays-2026-06-15.md` | Current index previously did not expose all module origins |
| op10 subhandlers/rule projection | `docs/spec/client-memory-ui-projection-map.md` | Exact packet layouts and a tested publication sequence |
| Room roster renderer/event chain | `analysis/roster-row-draw-RE-2026-07-25.txt` | The specific event/caller that refreshes an already-populated creator row |
| Close/exit fallback | `SPEC-DECOMPILE-CLOSEOUT-2026-07-18.md` | Controlled runtime branch identification and clean server sequence |
| TCP unhandled enum commands | `server/snap_server.js:79-93` plus Ghidra exports | Decide whether PAL current path skips, defers or requires each command |

## Configuration and runtime drift risk

The tracked consolidated environment is dated July 13 and does not include the
latest `SNAP_MEMBER_JOIN_AT_ACCEPT`, `SNAP_ROOM_LIMITS_OP10SUB5`, or
`SNAP_MEMBER_JOIN_SETTLE` flags. It does include `SNAP_ROOM_ENGINE=0` and
multiple overlapping room-list paths
(`deploy/pal-server.service.d/00-pal-server.conf:1-70`).

No Pi runtime verification was performed in this documentation audit. Therefore
the effective Pi file hash, service state, systemd environment and journal at
2026-07-28 are `Unknown`; repository config must not be described as live
runtime.

## What blocks a complete real-client session

In dependency order:

1. deterministic visible roster/header convergence for the creator;
2. two-client authoritative roster/count convergence;
3. complete room-rule, password, scenario and character synchronization;
4. lobby chat;
5. ready/unready and host-authorized start transition;
6. PAL gameplay session establishment;
7. decoded and implemented in-game synchronization/relay;
8. clean leave, disconnect, ghost cleanup and reconnect across every phase;
9. reproducible full-harness real-PS2/emulator goldens for each slice.

The first blocker should be solved before broad server architecture changes,
because the latest server already places correct data in client memory. The
remaining uncertainty is a specific `3.DAT` state/event transition, not evidence
that the room system should be rewritten.
