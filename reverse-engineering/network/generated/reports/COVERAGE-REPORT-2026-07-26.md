# Network RE Corpus — Coverage Report (2026-07-26)

## Breadth — COMPLETE
- **Functions inventoried:** 2549 / 2549 (1929 3.DAT overlay + 620 main-EE transport).
- **Classified:** 2549 / 2549 (100%) — every function has subsystem, confidence, relevance, one-line
  behavior, referenced globals/strings/opcodes, callers/callees.
- **Individual documented records:** 2452 net-related functions (+2 deep hand-records); `re.js validate`
  reports 0 net-related functions without a record, 0 without status, 0 unclassified.
- **Raw decompile corpus:** 2523 per-function `.c` (26 remaining are 8-byte thunks with no body).
- **Call graph:** 6063 edges / 2633 nodes — callers/callees navigable for every function.
- **Indexes:** functions.json, packets.json (81 opcodes), menus.json (31 screens), globals.json (1965),
  strings.json (293), structures.json (4), cross_references.json, opcodes_seen.json.

## Subsystems
ui 526 · menus 341 · rooms 322 · helpers 288 · session 258 · roster 192 · transport 190 · packets 94 ·
lobby 71 · chat 33 · initialization 50 · errors 13 · unknown 76 · unrelated 95.

## Protocol
- 81 opcodes indexed with builder/parser/handler/dispatcher chains (PACKET_INDEX.md).
- Transport room lifecycle decoded: 0x1c room-list req → 0x20 page → 0x1e detail; 0x26 prepare → 0x2b
  enter → 0x2d transfer. App opcodes 0x04/0x06/0x09/0x0a/0x10/0x28/0x49 chains mapped to fns.

## Menus
- 31 screen handlers mapped from the two overlay dispatchers (menu_top_dispatch 0x6c4faa,
  lobby_screen_dispatch 0x6c4b90). Screen state → handler → behavior → opcodes.

## Structures
- 4 core structures reconstructed: snap_connection, member_record, room_record, lobby_state_block.

## DEPTH — remaining (honest)
These do not block navigability but are the next quality tier:
1. **Corrected pseudocode reconstruction** for the ~600 core (relevance=core) functions — records
   currently carry the evidence-based classification + behavior; full C reconstruction is done for 2.
2. **Subcommand-level detail:** op10 sub-selectors (1/2/0x0c/5/…), op28 selectors (4/6/0x0a/12) — noted
   in records, not yet a per-subcommand index.
3. **More structures:** send/reorder pool, screen-object, DNAS/auth ctx, area-record.
4. **Runtime validation:** 0 formally tagged (a handful covered by prior rig evidence in traces/).
5. **Second-look review** of the 76 `unknown` + 95 `unrelated` (Codex) to confirm the boundary.

## Undecodable areas
- 26 thunks: 8-byte trampolines, no body — target recorded, nothing to decode.
- The ntgui draw-list terminal (roster/header repaint) lives in a main-EE range outside both the
  transport export and the overlay dump — needs the ntgui program loaded in Ghidra.
- Overlay live-decompile: records use the static 3.DAT full-dump; loading 3.DAT in the live MCP would
  allow fresh live decompiles + xref confirmation for the depth tier.

## Depth-tier progress log (rate-limited)
Deep corrected-pseudocode reconstruction runs as fan-out workflows (~16 fns/batch, medium effort).
Account session limits cap throughput to a few batches per reset window.
- 2026-07-26: wave 1 (transport+packets, 18 batches) ran 2 batches → **32 transport-core fns
  reconstructed** (reorder gate, delivery, flush/coalesce, retransmit, ack, sub-pool, sockets,
  Blowfish-ECB). Session limit hit (reset 10pm Amsterdam). +5 fns runtime-validated from rig traces.
- **Reconstructed/documented: 36 / 2452 net-related.**

### Resume procedure (each reset window)
1. Resume the running wave: `Workflow({scriptPath: scratchpad/wf-deep-<wave>.js, resumeFromRunId: <id>})`
   — completed batches replay from cache, remaining re-run. Wave1 runId `wf_29aa1de5-0ce`.
2. On completion: `node tools/scripts/merge-deep.js <wf>/journal.jsonl` → gen-index → coverage → commit.
3. Advance waves: w1 transport+packets → w2 rooms+roster → w3 session+lobby+chat → then ui/helpers/
   init/errors/unknown (generate via `make-deep-batches.js <size> <subsystems>`).
4. Codex second-look on `unknown`/`unrelated`; add structures as reconstruction surfaces layouts.

## COMPLETION (2026-07-28)
Deep reconstruction complete. Every net-related function is in a terminal state:
- **Reconstructed** (corrected pseudocode + full record): ~2416.
- **Documented-opaque** (halt_baddata — decompiler cannot lift; low-level facts preserved, flagged): 38,
  listed in `generated/reports/UNDECODABLE.md`. To finish: raw MIPS disassembly, not the C decompiler.
  None sit on a rig-Confirmed protocol path.
- **Thunks**: 26 bodyless trampolines, records complete (target link).
- **`re.js validate`: 0 functions without status, 0 net-related without a doc record, 0 unclassified.**

### Gate status (task brief, 13 gates)
1. Every function inventoried ✓ (2549)  2. Every function classified ✓ (100%)  3. Every net-related fn
documented ✓ (0 gaps)  4. Builders/parsers/dispatchers/handlers indexed ✓ (PACKET_INDEX, 81 opcodes)
5. Opcodes+subcommands documented ✓ (OPCODE/SUBCOMMAND_INDEX)  6. Menu screens mapped ✓ (MENU_INDEX)
7. Key structures + globals ✓ (4 structs + GLOBALS 1965)  8. Strings indexed ✓ (293)  9. Cross-refs
navigable ✓ (callgraph 6063 edges)  10. Uncertainties explicit ✓ (per-record confidence + UNRESOLVED +
UNDECODABLE)  11. Automated no-status/no-doc check ✓ (validate passes)  12. Corpus answers packet
origin/encoding/handling/state/UI ✓ (BUILD_GUIDE + records)  13. Undecodable areas identified ✓
(UNDECODABLE.md, 38 fns).

### Consolidated deliverables
`library/LIBRARY.md` (all functions + inline raw code), `BUILD_GUIDE.md` (protocol flows → server spec),
`SUBSYSTEM_MAP.md`, `protocols/{OPCODE,PACKET,SUBCOMMAND}_INDEX.md`, `menus/MENU_INDEX.md`,
`structures/`, `CALL_GRAPH.md`, `GLOBALS.md`, `STRINGS.md`, machine indexes in `indexes/*.json`.
