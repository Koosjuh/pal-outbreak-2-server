# UNRESOLVED — central backlog

Open questions, blockers, and low-confidence items. Each entry: `[ADDR/topic] — question — status`.
Items are added as records are written and cleared when evidence resolves them.

## Corpus-setup gaps
- [overlay] 26 of 1929 overlay index functions have no split raw `.c` (thunks / splitter edge cases) —
  CONFIRMED all 26 are 8-byte thunks (thunk_FUN_/thunk_EXT_FUN_ trampolines) — classify as helpers with target link; no decompile body needed.
- [3.DAT-live] The overlay program (0x5bxxxx) is NOT loaded in the live Ghidra MCP (main-EE is). Overlay
  records use the static full-dump corpus; load 3.DAT for fresh live decompiles where a record needs it.

## Protocol
- (populated by packet records)

## Menus / UI render
- [redraw] The roster/header repaint trigger event (0x19) chain terminates in an ntgui draw-list function
  not present in the overlay dump — needs the main-EE ntgui program range. (from prior RE)

## Depth backlog (breadth complete 2026-07-26; see COVERAGE-REPORT)
- Corrected pseudocode reconstruction for ~600 relevance=core fns (records carry classification+behavior; deep C for 2).
- Subcommand index: op10 sub-selectors, op28 selectors — per-subcommand table.
- Structures: send/reorder pool, screen-object, DNAS ctx, area-record.
- Runtime-validation tags (link traces/ per fn); currently 0 formal.
- Second-look (Codex) on 76 `unknown` + 95 `unrelated` to confirm the dependency boundary.
- Load 3.DAT in the live Ghidra MCP for fresh overlay decompiles + xref confirmation.
