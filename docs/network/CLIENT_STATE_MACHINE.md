# Client network state machine

Date: 2026-07-28
Target: PAL `SLES_533.19`

This is a protocol-facing state model, not a rename of original client
structures. Numeric client states are included only where reads/writes have been
traced. A visible screen transition does not prove that all underlying network
state is correct.

## Top-level flow

```text
Network setup
  -> HTTP/DNAS/login
  -> TCP 10127 session bootstrap
  -> server-list data walk
  -> server selected
  -> UDP 9090 register/bind
  -> area select
  -> in-area lobby / room list
       -> create prepare -> create accept -> creator room
       -> join request -> join accept -> member room
  -> room configuration / roster / ready
  -> game-start handoff
  -> 2.DAT gameplay
  -> leave/disconnect/reconnect
```

The flow through “member room” is partially demonstrated. Everything after
room configuration is not demonstrated by a complete PAL session.

## State transition matrix

| State | Entry proof | Client activity | Required server action | Success transition | Failure/timeout | Status/evidence |
|---|---|---|---|---|---|---|
| `N0 Network unavailable/setup` | NTGUI/netaq module inventory | Load IOP stack, acquire interface/config | DNS/network reachability | `N1 Pre-login` | Network UI/error | Module boundary decoded; exact global SM unknown (`RE-overlays...:78-82`) |
| `N1 Pre-login HTTP/DNAS` | Working server flow; `netdnas.bin`/`nethttp.bin` roles | HTTP/DNAS requests and account/session steps | Compatible HTTP/DNAS responses | `T0 TCP connected` | Authentication/network error | Runtime-compatible; security semantics unknown |
| `T0 TCP connected/challenge` | TCP connect | Receive/send CONNCHECK and `0x6110` | Return login seed or resume payload for the correct phase | `T1 Login accepted` | FIN/error on header error or bad seed | `server/snap_server.js:855-903` |
| `T1 Login accepted` | Client continues command walk | Request manifests and PAL data | Correct `0x6103/04`, `0x6203/04`, boot-stage replies | `T2 Server records` | D901/early FIN | Both for working path (`GOLDENS.md:112-118`) |
| `T2 Server records` | `0x6501..0x6510` walk | Fill server/header/slot tables | Return batches, endpoint and counts; ACK `0x1004` | `T3 Server select visible` | Empty/broken list or connect failure | Both; synthetic fields remain |
| `T3 Server selected` | User selects record | Resolve endpoint; `FUN_00626900` opens SN@P and polls established bit | Reachable UDP service; valid registration | `U0 UDP registering` | retries; callback maps to 820+code | Decoded connect SM (`function-index.md:11-23`) |
| `U0 UDP registering` | client op2c | Send REGISTER and await op2d | Validate/build op2d with proper crypto/envelope | `U1 Registered` | callback error `0x13` or timeout | Both for working current flow |
| `U1 Registered` | registration state 2 | Send kind31/op01 bind | Associate endpoint/session and ACK reliable frames | `A0 Area select` | pool/retry/840 failure | Runtime demonstrated; bind layout partial |
| `A0 Area select` | Screen byte `0x6c4b90=1` in current watch model | Repeated op48 population queries; select area | Exact ACK each reliable op48; return area records/counts | `A1 Area entry pending` | pool latch / no selection progression | Both (`L1...:342-359`) |
| `A1 Area entry pending` | client op06 | Wait on registered selector-6 callback | Send op28 selector 6 with request generation echoed | `L0 In-area lobby` | callback never fires / 840 | Both; generation echo is golden invariant (`GOLDENS.md:59-69`) |
| `L0 In-area lobby` | Screen byte `0x6c4b90=2` in current model | Send four op49 subqueries | ACK every request; answer valid success records | `L1 Room list usable` | improper/empty/wedged list | Both for vacant list; real-room records partial |
| `L1 Room list usable` | Cursor/list unlocked | Choose vacant create entry or occupied room | Preserve opaque handle and phase | `C0 Create prepare` or `J0 Join pending` | Selection reset/error | Runtime demonstrated |
| `C0 Create prepare` | First op0c | Two staged prepare/query requests | op28 selector 12, matching sub/generation for each | `C1 Rule/create form` | wait/retry/timeout | Both for current create path; body fields partial |
| `C1 Rule/create form` | Create UI | Choose room name/rules/character/scenario | Supply rule/config data required by client gates | `C2 Create registration` | local Finish blocked if fields invalid | Current code can reach/create; complete rule sync not proven |
| `C2 Create registration` | client op04 | Register created slot/room | Create registry entry; op28 selector 4/status 0 using next reliable sequence | `C3 Create accepted` | create callback error/stall | Both |
| `C3 Create accepted` | ownership gate unlocks | Initialize room widget/state | Send creator op06 at the first contiguous post-accept sequence; send limits/config in proven order | `R0 Creator room memory` | below-expected op06 dropped | T13 proves contiguous ordering (`SESSION-LOG...:206-229`) |
| `R0 Creator room memory` | Roster row/count/max correct in PINE | UI should latch/refresh roster/header | Exact client overlay refresh vehicle/order unknown | `R1 Creator room visible` | memory correct, widget stale | Current blocker; class Unknown |
| `J0 Join pending` | client op10/sub2 after room selection | Wait for host/server admission | Validate status/capacity; op10/sub0c count; roster/config pushes | `R2 Joiner room visible` | rejected/full/in-create/timeout | July 16 room screen is runtime-proven; mutual state is not |
| `R1/R2 Room active` | Room screen | op0a pulls, op10 liveness/config, chat/character/rule/ready activity | Maintain authoritative roster/count/config and liveness | `R3 All members synchronized` | stale roster/count, 840, exit failure | Not achieved; individual vehicles partial |
| `R3 All members synchronized` | No reproducible proof yet | Players choose ready/start | Enforce host/start gate and broadcast authoritative start | `G0 Gameplay handoff` | client remains in room | Unknown |
| `G0 Gameplay handoff` | No successful PAL capture | Unload 3.DAT/load 2.DAT; establish game session | Unknown PAL endpoint/session contract | `G1 Gameplay active` | load/connect failure | Unknown |
| `G1 Gameplay active` | No successful PAL capture | `game.bin` synchronization sends/receives | Relay/host/authority behavior unknown | remain `G1` | disconnect/desync | Decoded code exists; wire untraced |
| `X0 Room leave` | client leave/close | reliable close plus op07/08 phase messages | ACK exact close; update registry; op07 survivors; count/list updates; dissolve if host | parent lobby or server select | ~15s fallback or connection error | Partial decoded/local tests; runtime contradictory |
| `X1 Disconnect/reconnect` | socket/timeout | Cleanup and possibly reconnect | Deduplicate old endpoint/player; broadcast leave; issue fresh session | relevant earlier state | ghost room/member | State model implements cleanup; PAL reconnect contract unknown |

### TCP lobby-initialization substate ladder

The current V2 reconstruction makes these descriptive server states explicit:

```text
awaiting-0x1007
  -> awaiting-0x6103
  -> awaiting-0x6212
  -> awaiting-0x6203
  -> awaiting-0x6211
  -> awaiting-0x6213
  -> awaiting-0x6501
  -> awaiting-post-0x6501-mode0 (0x6502 and 0x6510 handled)
     OR awaiting-0x6503 (unimplemented)
  -> awaiting-post-0x6502-mode0 (0x6502 loop and 0x6510 handled)
     OR awaiting-0x6504
        -> awaiting-more-0x6504 (loop handled)
        OR awaiting-post-0x6504-complete (0x6510 handled; 0x6502 unimplemented)
  -> awaiting-post-0x6510 (0x6510 loop, 0x6203 re-entry, and 0x1004 all handled)
  -> lobby-initialization-complete (terminal; nothing further decoded)
```

The matching decoded client transitions are response mode `0` → substate
`0x29`, empty `0x6103` manifest → substate `2`, and `0x6212` BE32 reply
→ substate `0x10`, from which the audited walk emits `0x6203`. Its mode-2
reply writes substate `0x14`, from which the captured walk emits `0x6211`.
Its reply parser stores one BE32 then routes to `0x0e`, `0x2d`, or `0x31`
according to the connection major state; the saved ladder next emits `0x6213`.
The `0x6213` parser consumes eight ordered BE16 words, writes substate `0x04`,
and the scheduler then emits `0x6501`. V2 parses its BE32 request and uses a
required tagged resolver: mode 0 enters a neutral state permitting `0x6502` or
`0x6510`; mode 1 enters `awaiting-0x6503`, which remains unanswered.
When `0x6502` follows, V2 validates its BE32-plus-dynamic-field envelope and a
second tagged resolver selects normal mode 0 (loop/`0x6510`) or mode 1 (`0x6504`).
For `0x6504`, V2 validates the two-BE16-plus-dynamic-field request and requires
neutral record data. The decoded incomplete predicate permits only another `0x6504`;
completion permits the scheduler-proven `0x6502` or `0x6510` alternatives without
guessing the client's major/header-index state.

`0x6504` completion resets the client cursors `0x00365e18`, `0x00365e12`, and
`0x00365e10` to zero and selects substate `0x0c`, whose scheduler case builds
`0x6510` through `FUN_001c85c0` and parks at `0x0d`. V2 validates that batch's
count byte, its `count` encoded record fields, and its single trailing encoded
field as an exact payload consumption, then requires `resolveCommand6510Response`.
It echoes the request count so the consumer's batch-count gate passes, emits one
BE16 per requested record, and appends one trailing field bounded to `0x3e`
decoded bytes. Every reply enters `awaiting-post-0x6510`, which answers another
`0x6510` batch and preserves — without answering — the two other decoded
continuations: `0x6203` when the connection major state is 4, and `0x1004` when
the page list is exhausted. `0x6510` is never answered with status `0xff`,
because that path falls through to the cursor block with caller-saved registers
rather than installing client defaults.

Substate `0x31` calls `FUN_001c8dd0`, which builds command index `0x05` —
wire command `0x1004` — with no fields, and the scheduler parks at `0x33`.
Receive-dispatch entry `0x06` binds direction `0x02` of `0x1004` to
`FUN_001c8e90`, which disassembles to `jr ra; li v0,1`: it consumes no reply
payload, and a handler return of 1 makes `FUN_001c9b00` increment the connection
top-level state byte at `+0x0c` rather than select another substate. V2 answers
the payload-less request with an empty status-zero frame and enters the terminal
`lobby-initialization-complete` state, which decodes nothing further. Which side
sends FIN, when, the meaning of the incremented top state, and whether a further
correlated connection opens are all still Unknown, so the close is not modeled.

The other exhaustion route, major state 4, selects substate `0x10`, whose
scheduler case builds `0x6203` through `FUN_001c48c0` (command index `0x12`).
`FUN_001c4960` writes substate `0x14` on mode 2 unconditionally, so that route
re-enters the same `0x6211` -> `0x6213` -> `0x6501` sub-ladder; V2 answers it with
the existing `0x6203` handler and returns to `awaiting-0x6211`.

This is a genuine cycle, not a one-shot. `FUN_001c6e80`'s mode-0 branch zeroes
`0x365e18`, `0x365e12`, `0x365e10`, and `0x365e0c` at `0x001c6f4c..0x001c6fa8`,
restarting the entire record walk from page zero. If the connection major state
stays 4, the client loops `0x6510 -> 0x6203 -> ... -> 0x6501 -> ... -> 0x6510`
indefinitely and V2 keeps answering. Nothing accumulates server-side, but there is
no proven exit either. No captured session took this route, so what terminates the
loop is **Unknown**; a real-client run that enters it should be treated as a
finding rather than as normal operation.
Evidence: main-EE `FUN_001c9030`, `FUN_001c5f30`, `FUN_001c42d0`, and
`FUN_001c4360`, plus `FUN_001c48c0`/`FUN_001c4960` and
`FUN_001c4560`/`FUN_001c45f0`/`FUN_001c3b10`, plus
`FUN_001c43c0`/`FUN_001c4450`/`FUN_001c3ab0`, and
`FUN_001c7980`/`FUN_001c7a70`/`FUN_001c3b90`/`FUN_001c3750`;
`analysis/claude-lobby-investigation-findings-2026-05-26.md:308-314`;
T1-T5 in `docs/findings/protocol/SESSION-LOG-2026-08-01.md` and T6-T10 in
`docs/findings/protocol/SESSION-LOG-2026-08-02.md`.

Only that captured/decoded path is claimed. Alternate tolerated lengths,
alternate session branches, and the domain meaning of the `0x6212` BE32 field
remain unknown. The `0x6203` request's second u16, encoded bytes, and domain
meaning also remain unknown.
The `0x6211` BE32 field meaning/source and the saved ladder's active major-state
branch also remain unknown.
The complete `0x6213` word meanings, production values, and tolerated trailing
response bytes remain unknown.

## Transport substate invariants

The application states above are viable only while these transport invariants
hold:

1. ACK every client reliable message by exact ID.
2. Do not parse coalesced subframes before decryption.
3. Keep client op48/op49 allocations above the subpool-2 hysteresis boundary.
4. Use one contiguous server→client reliable sequence space.
5. Retransmit an unacknowledged frame with its original sequence.
6. Send periodic valid op40 keepalive.
7. Echo the request generation/sub byte in selector completions where the
   callback registration uses it.

Evidence:
`docs/specs/L1-snap-transport-spec.md:83-113,143-175,218-259,342-359`;
`analysis/op06-accept-criterion-RE-2026-07-26.txt:42-107`;
`GOLDENS.md:59-77`.

## Room state and server registry comparison

The repository’s optional model represents:

```text
player:
  identity -> endpoints -> area -> room -> playerNo -> host -> charstats

room:
  handle -> area -> status(FREE/INCREATE/GAMESET/BUSY)
         -> host -> members -> maxPlayers -> flags
```

Create makes the creator host/player 1; go-live moves `INCREATE` to `GAMESET`;
join assigns the lowest free player number; a full room becomes `BUSY`; non-host
leave removes one member; host leave dissolves the room without migration
(`server/lobby_state.js:274-405`;
`server/lobby_engine.js:98-169,238-287`).

Local tests verify this model, but it is not yet the active runtime authority:
the tracked service config sets `SNAP_ROOM_ENGINE=0`
(`deploy/pal-server.service.d/00-pal-server.conf:27-29`). Moreover, KDDI
host-dissolve behavior is only structural evidence for PAL until a PAL leave
trace confirms it.

## Baseline-protection snapshot

Confirmed:

- TCP server selection and UDP registration work.
- Exact reliable ACKing and ordered server sequencing are required.
- Repeated area enter/back and valid vacant room listing have goldens.
- A creator and a second client have both reached room screens.
- The July 26 creator op06 produced correct roster/count/max memory.

Rejected:

- KDDI command numbers as direct PAL wire truth.
- op0a as the visible roster-add vehicle.
- app-handler failure as the cause of the missing op06 ACK.
- a delayed op06 resend as “proven refresh”; it has not been tested.

Unknown:

- overlay event/order that refreshes the creator widget at create acceptance;
- complete leave, chat, config, character, ready/start and gameplay states;
- PAL gameplay topology and reconnect semantics.

Current baseline:

- Recoverable day-to-day transport floor: `g2-solved-transport-2026-07-11`.
- Latest confirmed two-device milestone: `joiner-render-2026-07-16`.
- Latest single-device evidence: T13 on 2026-07-26, not promoted to a golden.
- HEAD adds an untested delayed op06 experiment over T13.

Current blocker:

- deterministic visible roster/header refresh at the create boundary.

Next valid test:

- a single-hypothesis test of the HEAD delayed op06 against a clean T13 baseline,
  with client expected sequence, op06 ACK, roster memory, widget/panel state and
  screenshot captured. If it fails, stop extending retry timing and trace the
  `3.DAT` event/call path that performed the July 16 1→2-member refresh.
