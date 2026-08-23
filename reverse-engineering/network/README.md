# Network & Multiplayer Reverse-Engineering Corpus

**PAL Resident Evil Outbreak File #2 (SLES_533.19)** — a complete, structured, searchable,
evidence-backed reconstruction of the game's entire network/multiplayer implementation.

> **The ISO is the source of truth.** The existing private server, the JP Bioserver reference,
> prior findings docs, and previous agent conclusions are *supporting evidence only*. An
> interpretation is never promoted to `Confirmed` merely because it matches the current server.

## Principle
This corpus documents the **client** as the binary actually implements it, one function at a time,
with callers/callees/globals/strings/control-flow evidence and an explicit confidence level. It is
built and maintained separately from server code (branch `re/network-corpus`), and RE commits never
carry speculative server changes.

## Layout
```
sources/        RAW evidence — decompiler output, never hand-edited
  executables/transport-decompile/   620 main-EE SN@P transport fns (0x1c–0x1e), one .c each
  overlays/overlay-3dat-*            1903 3.DAT overlay fns (lobby/room/menu SMs), one .c each + full dump
functions/<subsystem>/  Per-function RECORDS (reconstructed + documented). Filename: <ADDR>_<resolved_name>.md
protocols/      OPCODE_INDEX.md, PACKET_INDEX.md, packet-layouts/<op>.md
menus/          MENU_INDEX.md, screens/, transitions/ (state diagrams)
structures/     structure-layouts/<name>.md
traces/         emulator/, packet-captures/, memory/ (runtime evidence backing records)
generated/      callgraphs/, cross-references/, reports/
indexes/        MACHINE-READABLE: functions.json + packets/menus/structures/globals/strings/cross_references.json
tools/scripts/  re.js (query/coverage/gen-index/validate), build-inventory.js
```
Top-level living docs: `MASTER_INDEX.md` `COVERAGE.md` `CALL_GRAPH.md` `DATA_STRUCTURES.md`
`GLOBALS.md` `CONSTANTS.md` `ENUMS.md` `STRINGS.md` `STATE_MACHINES.md` `UNRESOLVED.md`.

## Function-record schema
Every function gets one record following `RECORD_TEMPLATE.md`. A function is `complete` only when its
corrected reconstruction **and** its documentation are both stored, and its `functions.json` row
carries a status + confidence + doc_path.

### status
`inventoried` (raw only) → `classified` (subsystem assigned, triaged) → `reconstructed`
(corrected pseudocode written) → `documented` (full record) → `validated` (runtime-confirmed).
Plus `unrelated` (proven outside the network dependency boundary, with evidence).

### confidence
`Confirmed` (code + runtime) · `High` (control-flow + xrefs) · `Medium` (plausible, partial) ·
`Low` (hypothesis) · `Unknown` (insufficient evidence). Never `Confirmed` from server-parity alone.

### subsystem taxonomy (functions/<subsystem>/)
`initialization` `transport` `packets` `session` `lobby` `rooms` `roster` `chat` `menus` `ui`
`errors` `helpers` `unknown` (triage pending) · `unrelated` (evidence-backed out-of-scope).

## Navigate (start here)
| Want | Open |
|---|---|
| **Build the server (protocol flows → what to send)** | `BUILD_GUIDE.md` |
| **ONE library of all functions + code** | `library/LIBRARY.md` (record + inline raw decompile per fn) |
| Every function, searchable | `MASTER_INDEX.md` · `indexes/functions.json` |
| "What to build" per subsystem | `SUBSYSTEM_MAP.md` |
| A packet's builder→parser→handler chain | `protocols/PACKET_INDEX.md` · `indexes/packets.json` |
| Which fns touch an opcode | `protocols/OPCODE_INDEX.md` |
| A screen's handler + triggered packets | `menus/MENU_INDEX.md` · `indexes/menus.json` |
| A state variable's readers/writers | `GLOBALS.md` · `indexes/globals.json` |
| Data structure layouts | `DATA_STRUCTURES.md` · `structures/structure-layouts/` |
| Who calls / is called by X | `CALL_GRAPH.md` · `indexes/cross_references.json` |
| One function's full record | `functions/<subsystem>/<addr>_<name>.md` |
| Coverage + what's left | `COVERAGE.md` · `generated/reports/COVERAGE-REPORT-*.md` |
| Open questions | `UNRESOLVED.md` |

## Querying
```
node tools/scripts/re.js search --addr 0x005bb4d0
node tools/scripts/re.js search --subsystem rooms --status documented
node tools/scripts/re.js search --opcode 0x06        # packet builders/parsers for op06
node tools/scripts/re.js search --caller FUN_005f99c0
node tools/scripts/re.js coverage      # regen COVERAGE.md
node tools/scripts/re.js gen-index     # regen MASTER_INDEX.md
node tools/scripts/re.js validate      # completion-gate check
```

## Commit categories (RE branch only)
`Inventory` · `Raw extraction` · `Function reconstruction` · `Packet documentation` ·
`Structure reconstruction` · `Menu mapping` · `Runtime evidence` · `Index generation` · `Tooling`.

## Completion gates
See `COVERAGE.md` (live) and the 13 gates in the task brief: every function inventoried & classified;
every net-related function documented; all builders/parsers/dispatchers/handlers, opcodes, menu
screens, key structures/globals, and strings indexed; cross-references navigable; uncertainties
explicit; `re.js validate` passes; a final coverage report explains any undecoded areas.
