# Multiplayer server implementation plan

Date: 2026-07-28
Planning basis: evidence audit at `e2ba1a9315639a5a0f10dc45c8741959009f7b2d`

## Delivery rule

The target is a real PAL-client multiplayer server, not a rewrite for its own
sake. Work proceeds in independently testable vertical slices. Each slice must:

1. begin from a named golden or recorded baseline;
2. carry one hypothesis and one protocol behavior change;
3. cite decoded PAL reads/writes/branches or a PAL capture;
4. add deterministic packet and state-machine fixtures;
5. run a full capture-harness client test;
6. record Pi artifact hash, service state, effective environment and journal;
7. update the live session log before another experiment;
8. be promoted only after expected client state and visible behavior agree.

KDDI/Bioserver may guide lifecycle expectations, but no KDDI command or packet
layout enters production without PAL evidence.

## Slice status

| Slice | Current status | Completion meaning |
|---|---|---|
| Initial connection | Demonstrated, needs consolidated regression fixture | Client reaches PAL TCP 10127 and receives a valid challenge without manual intervention. |
| Authentication/session initialization | Demonstrated compatibility, production semantics incomplete | Client completes login/session bootstrap; session identity is deterministic and reconnect-safe. |
| Server selection and player counts | Demonstrated; some records synthetic | Server list shows evidenced name/endpoint/max/current from authoritative state. |
| Area selection and player counts | Demonstrated | Ten PAL areas render; current counts update from active sessions; repeated enter/back remains healthy. |
| Lobby entry | Demonstrated | Selector completion and op49 walk enter an interactive lobby indefinitely without pool/840 failure. |
| Room listing | Demonstrated for vacant and partial registry rooms | Real registry rooms, status/current/max/handle render and update without fixture branches. |
| Room creation | Partial | Creator room is registered and the client visibly converges to creator player 1 with correct rules/counts. |
| Room joining and leaving | Partial join; leave incomplete | Two clients join/leave repeatedly with correct rosters, counts, dissolve behavior and clean navigation. |
| Lobby chat | Missing | A PAL chat send is decoded, broadcast and rendered by all intended recipients. |
| Player roster synchronization | Partial; memory correct, visible creator refresh blocked | op06/op07/op0a/count vehicles converge visibly and in memory for create, join, leave and reconnect. |
| Character selection | Missing/placeholder | Selection from one client is authoritative and visible to peers without synthetic charstats. |
| Room-rule synchronization | Partial decoded routes | Host changes rules/password/scenario/difficulty; all clients converge and invalid changes are rejected. |
| Ready state | Missing | Ready/unready transitions synchronize and start gating matches PAL client behavior. |
| Game-start transition | Missing | Host starts; every client leaves `3.DAT` room state and establishes the expected game session. |
| Gameplay session establishment | Missing | PAL client(s) authenticate/bind to the gameplay channel with a reproducible capture. |
| In-game synchronization | Missing | Movement/actions/state messages are relayed or arbitrated according to decoded `2.DAT` behavior. |
| Disconnect and reconnect handling | Partial local model only | Every phase cleans up promptly; no ghosts; supported resume behavior is proven, unsupported resume fails cleanly. |

### V2 reconstruction progress (2026-08-02)

V2 now has local deterministic coverage for the client-driven TCP
`0x1007 -> 0x6103 -> 0x6212 -> 0x6203 -> 0x6211 -> 0x6213` ladder. Each command is isolated
behind an explicit state and exact fixture; `0x6212` and `0x6211` support explicit
external values but otherwise select their decoded status-`0xff` client defaults. `0x6203`
validates only the decoded dynamic envelope and uses the repeatedly captured
mode-2 response. `0x6213` likewise supports explicit eight-word state or its decoded
payload-less client-default branch. Normal `0x6501`, `0x6502`, and `0x6504` boundaries now use
required neutral providers and decoded branch states. The full V2 suite is 105 pass,
0 fail, with 7 external DNAS fixtures skipped.

This does not complete authentication/session initialization: production
connection-purpose correlation and real-client acceptance remain open; explicit
value meanings are still Unknown but no longer block the ladder. The next testable V2
increment is characterizing the post-`0x1004` FIN/session close and proving session-backed
connection-purpose correlation, followed by the next-page `0x6502` continuation, while retaining
`0x6503` as the separate decoded alternative.

## Slice 1 — Initial connection

Goal: freeze the already-working DNS/HTTP/DNAS/TCP entry as a deterministic
compatibility contract.

Implementation work:

- extract TCP frame parse/build and command fixtures without changing bytes;
- add tests for split header, split payload, two frames in one read, invalid
  length and `err=0xff`;
- record DNS/HTTP/DNAS dependencies and timeouts actually used by PAL;
- keep minimal compatibility authentication explicitly local/research-only.

Proof:

- fresh emulator and real PS2 reach TCP challenge;
- pcap identifies endpoint/port and full first frame;
- no PINE poke or cached session is required.

## Slice 2 — Authentication or session initialization

Goal: make identity/session creation deterministic while preserving the working
PAL bootstrap.

Implementation work:

- fixture the boot `0x6001 → 0x6110 → 0x6101` sequence and the post-lobby
  `0x6110 → 0x6110` resume sequence;
- decode remaining credential/session fields before assigning names;
- bind TCP identity to UDP registration without relying on source IP alone;
- define expiration and duplicate-login behavior.

Proof:

- correct account reaches selection;
- malformed seed/identity produces the decoded PAL error path;
- second connection resumes the same intended session;
- two clients behind one IP remain distinct.

## Slice 3 — Server selection and player counts

Goal: replace synthetic server-list semantics with authoritative fields one at
a time.

Implementation work:

- preserve current byte-compatible `0x6501..0x6510` walk;
- fixture each decoded parser layout;
- source current-player count from active identities and max from configuration;
- remove `OPEN`/`Test Slot` only when exact field consumers are proven.

Proof:

- server name/endpoint/current/max are correct in client memory and UI;
- count changes after a second client connects/disconnects;
- real PS2 and emulator agree or are documented separately.

## Slice 4 — Area selection and player counts

Goal: keep the golden ten-area flow while making op48 context-specific.

Implementation work:

- classify op48 query tag/context rather than `REPLY_ALL`;
- use authoritative area-lobby counts;
- preserve exact ACKing and subpool health;
- fixture selector-6 generation echo and opaque fields.

Proof:

- all ten areas render with intended enabled/disabled state;
- two clients cause the selected-area count to change;
- 20 enter/back cycles preserve pool health, no `0x65`, no error 840.

## Slice 5 — Lobby entry

Goal: turn the g2 transport golden into a permanent regression gate.

Implementation work:

- centralize exact ACK and generation-matched completion tests;
- validate op40 cadence and reliable retransmit with original sequence;
- reject raw parsing of encrypted coalesced subframes;
- remove no-longer-needed establishment probes only after fixture parity.

Proof:

- op49 sends once at the expected transition;
- room-list cursor unlocks;
- client expected sequence, ACK base and pool counters remain healthy.

## Slice 6 — Room listing

Goal: make one registry implementation the authoritative op49 response path.

Implementation work:

- disable fixture/empty/registry overlap in the test configuration;
- preserve room handle bytes opaquely;
- encode current/max/status fields at decoded offsets and endianness;
- distinguish the four LOID/STAT subqueries only when captures prove content.

Proof:

- vacant and occupied rooms render correctly;
- a create/delete/count change appears after the client’s normal refresh;
- no “improper” row and no multiplied count from answering every subquery alike.

## Slice 7 — Room creation

Goal: creator visibly reaches a stable room as host/player 1.

Implementation work:

- represent op0c prepare stages and op04 accept as one explicit transaction;
- use one ordered reliable sender for op28, op06, limits and configuration;
- complete the specific overlay refresh contract identified by Slice 10;
- retain HEAD delayed-op06 behavior only if the controlled test proves it.

Proof:

- visible creator name/character and `1/4P` agree with PINE memory;
- registry has exactly one host/member;
- duplicate/retransmitted create messages do not create duplicate rooms/members.

## Slice 8 — Room joining and leaving

Goal: two real clients repeatedly join and leave one room.

Implementation work:

- validate `op10/sub2 → sub0c` admission and status guards;
- publish op06 deltas, op0a durable list and count in the proven order;
- implement client close/leave ACK, op07 survivor notification and room-list
  update;
- prove whether PAL host exit dissolves, migrates or follows another branch.

Proof:

- creator and joiner see identical two-member roster/count/config;
- non-host leave compacts both clients and registry;
- host leave follows captured PAL behavior;
- five join/leave cycles produce no ghost member or connection error.

## Slice 9 — Lobby chat

Goal: decode and implement PAL chat rather than importing KDDI `0x67xx`.

Implementation work:

- capture one client send and trace dispatcher/handler/render buffer;
- specify sender identity, recipient scope, maximum length and encoding;
- add sanitize/length tests without changing accepted client bytes;
- broadcast through the active room state.

Proof:

- creator and joiner exchange messages in both directions;
- oversized/malformed input fails safely;
- leaving player no longer receives room chat.

## Slice 10 — Player roster synchronization

Goal: make roster state deterministic and visible across create, join, leave and
reconnect. This is the first incomplete slice to finish.

Implementation work:

- establish why the July 26 correct row did not refresh the widget;
- trace `3.DAT` from op06/event `0x1f` and event `0x19` to the node/widget refresh
  state, verifying decompile conclusions against disassembly;
- compare T13 create-self and July 16 second-member transitions;
- represent the proven delta/list/count order in one engine transaction;
- route production messages through the ordered reliable sender.

Proof:

- creator-only room visibly renders creator and `1/4P`;
- join makes both clients visibly render the same two rows and `2/4P`;
- leave makes survivor show one row and `1/4P`;
- PINE buffers, UI, registry and wire trace agree at every boundary.

## Slice 11 — Character selection

Goal: synchronize the actual PAL character/stat record.

Implementation work:

- capture selection change and trace the outbound builder in `3.DAT`;
- type only proven charstats offsets;
- reject duplicate selection according to decoded gate, if any;
- remove synthetic/distinct-char-ID behavior from the production path after
  parity tests.

Proof:

- each client sees both selected characters;
- selection change updates roster/member detail;
- reconnect/leave releases any uniqueness constraint.

## Slice 12 — Room-rule synchronization

Goal: synchronize scenario, difficulty, player cap, password and modifiers.

Implementation work:

- finish op10 sub3/sub5/sub6–9 layouts from reads/writes/callers;
- identify host publication and peer acknowledgement/order;
- separate display max (`0x6cfb66`) from host start gate (`0x6cfa2c`);
- implement password without logging plaintext credentials.

Proof:

- every rule change appears on both clients;
- joiner receives a complete initial snapshot;
- password correct/incorrect paths produce the observed PAL result;
- start gate reflects the selected rules.

## Slice 13 — Ready state

Goal: map and enforce PAL ready/unready.

Implementation work:

- capture both transitions;
- trace dispatcher, handler and memory gate;
- make server state authoritative and host-aware;
- specify behavior when a ready player changes character/rules or leaves.

Proof:

- all clients render identical ready state;
- start remains blocked until decoded condition is true;
- invalid/non-host start attempts do not advance.

## Slice 14 — Game-start transition

Goal: transition all room members from `3.DAT` to the gameplay session.

Implementation work:

- capture the first successful start boundary;
- trace room host gate, start message, overlay unload/load and endpoint/session
  installation;
- identify whether start is broadcast, acknowledged and retransmitted;
- freeze room membership at the proven boundary.

Proof:

- two clients leave room UI, load the same scenario and reach the gameplay
  connection state;
- no player remains in lobby registry incorrectly;
- failed start rolls back cleanly.

## Slice 15 — Gameplay session establishment

Goal: establish the service expected by PAL `2.DAT`.

Implementation work:

- inventory `2.DAT` connection acquisition and first sends with function
  addresses, registers and disassembly;
- capture endpoint/transport and session token exchange;
- compare KDDI GSLOGIN/8590 only as a hypothesis;
- implement the smallest handshake accepted by the PAL client.

Proof:

- two original clients establish gameplay sessions from one room;
- server can correlate each gameplay connection to its room/member;
- malformed/stale token is rejected through an observed-safe path.

## Slice 16 — In-game synchronization

Goal: support interoperable gameplay, initially as the narrowest evidence-backed
relay/authority model.

Implementation work:

- build a `2.DAT` send/receive/dispatch matrix from
  `analysis/claude-game-module-full-2026-05-29.txt` plus fresh disassembly;
- identify framing, length, sender/player ID, ordering and recipient policy;
- capture deterministic actions one at a time;
- implement byte-preserving relay first only if client code/capture proves relay
  semantics; otherwise implement the decoded authority model.

Proof:

- two clients see synchronized idle position, one movement, one interaction and
  one inventory/state change;
- packet loss/reorder tests follow decoded retry/tolerance behavior;
- no invented opcode or field is required.

## Slice 17 — Disconnect and reconnect handling

Goal: eliminate ghost sessions while matching supported PAL recovery behavior.

Implementation work:

- trace disconnect in TCP, area, lobby, room, start and gameplay phases;
- ACK/cleanup transport before deleting authoritative state;
- broadcast proven leave/count/list messages;
- test source-port change, same-IP multi-client and stale reconnect.

Proof:

- abrupt cable/socket loss removes the player within the proven timeout;
- survivors converge without restarting;
- reconnect either resumes or fails cleanly according to captured PAL behavior;
- host-disconnect behavior is deterministic and documented.

## First implementation slice to complete

The first incomplete slice is **Slice 10: player roster synchronization**, scoped
initially to the creator-only visible refresh. Initial connection through room
creation is already sufficiently functional to reach this boundary; beginning
again at authentication would not remove the current blocker.

The immediate experiment is not a broad code rewrite. It evaluates the one
untested behavior at HEAD, then either promotes or removes it.

## Test Gate — creator visible roster refresh

Baseline:

`87fb96a8`/T13 behavior: op04 acceptance followed immediately by contiguous
op06; client ACK advances across both; roster row0, current count and maximum are
correct in memory; visible roster is empty and header stale.

Current observation:

HEAD `e2ba1a93` adds a default-off `SNAP_MEMBER_JOIN_SETTLE` resend around
500 ms after acceptance. It has no recorded runtime result.

Specific unknown:

Does a second, in-window op06 after the room node/widget settles fire the
overlay event that relatches the visible roster/header?

Hypothesis:

The first op06 populates data before the room widget is refresh-ready; a second
identical member delta after node settlement triggers the normal event/refresh
path without duplicating the member.

Evidence supporting hypothesis:

T13 proves data correctness but stale widget state
(`SESSION-LOG-2026-07-25.md:206-229`). The July 16 1→2-member transition visibly
rendered a room screen (`GOLDENS.md:28-47`). The renderer/event chain is mapped
in `analysis/roster-row-draw-RE-2026-07-25.txt`.

Exact change or command:

Deploy the exact HEAD artifact only after Pi hash/env verification; enable only
`SNAP_MEMBER_JOIN_SETTLE=1` relative to the T13 flag set; run:

```powershell
node tests/capture.mjs --case GT-003 --platform emulator --idle 15 --watch tests/knowledge/ee-watch-create-boundary.json --force
```

Expected result:

Both op06 frames are accepted/ACKed; exactly one creator exists in registry and
client rows; visible roster shows the creator and header shows `1/4P`.

Alternative result:

The second op06 is ACKed but UI remains stale, is dropped as duplicate, or
creates a duplicate/inconsistent row.

What success proves:

A settled duplicate delta is the missing refresh vehicle and can be encoded as
a bounded create transaction pending real-PS2 confirmation.

What failure proves:

Timing/repetition alone is not the refresh contract. Stop retry variants and
trace the `3.DAT` event/call path that differs between create-self and a real
second-member join.

Rollback:

Disable `SNAP_MEMBER_JOIN_SETTLE` and return to the T13 artifact/flags; no state
migration is involved.

Files/logs that will be captured:

- full pcap;
- Pi file hash, `pal-server.service` state and effective `SNAP_*` environment;
- Pi journal covering register through room settlement;
- PINE watch including screen, reliable expected sequence/ACK, roster rows,
  count/max, widget/node/refresh state;
- DEV9/PCSX2 logs;
- before/after screenshots;
- harness `meta.json`;
- immediate entry in `docs/findings/protocol/SESSION-LOG-YYYY-MM-DD.md`.

## Exact acceptance tests for the slice

1. Local packet fixture: both op06 frames have correct encoded length, trailer,
   token, member ID/name/charstats and distinct contiguous sequences.
2. Local state fixture: applying the same member delta twice is idempotent in
   authoritative registry and emission plan.
3. Transport simulation: first and second op06 are in-window; a below-expected
   replay is not treated as new application state.
4. Emulator baseline control: T13 flag set without settle reproduces correct
   memory plus stale UI.
5. Emulator treatment: only settle enabled; full harness captures ACK, PINE
   row/count/widget and screenshot.
6. Fresh-session repeat: three consecutive clean emulator boots produce the
   same visible `1/4P` result without duplicates.
7. Real PS2 confirmation: same artifact/hash/env and a hardware-labelled
   capture show the same creator row/header.
8. Two-client regression: emulator creator + real PS2 joiner still both reach
   room screens, then converge to two visible rows/`2/4P`.
9. Negative duplicate test: intentional retransmission with the original
   reliable sequence does not add a second member.
10. Rollback test: disabling the flag returns exactly to T13 behavior and does
    not disturb area/lobby/create transport.

Only after tests 1–7 pass should the behavior be merged into an always-on
production create transaction. Tests 8–10 are required before declaring player
roster synchronization complete.
