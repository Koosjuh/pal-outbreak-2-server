# 0x00627540 menu_scroll_confirm_step

| field | value |
|---|---|
| Original address | 0x00627540 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00627540 |
| Resolved name | menu_scroll_confirm_step |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00622180
**Callees:** FUN_0061e7f0, FUN_0061e910, FUN_0061e960, FUN_0061f0e0, FUN_0061f0f0, FUN_0061f1a0, FUN_0061f1d0, FUN_0061f4b0, FUN_0061f680, FUN_0061f760
**Referenced globals:** 0x365cf0 list-length
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam007152e1 screen-phase; cRam007152e2 substate; sRam007152e4 timer; sRam007152ea cursor-idx

## Behavioral explanation
Menu screen-step that auto-advances a cursor sRam007152ea across a uRam00365cf0-length list then confirms; timed display selector 0x11/0xa5.

## Notes / uncertainty
Paged scroll-and-confirm (notice/agreement): advances cursor 0..0x365cf0-1 one page per confirm, done at last page; returns 1/-1/0. Empty list at entry returns 1. Phase 3 cancel path has no in-fn entry (external-set).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00627540.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
