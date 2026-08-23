# 0x00625ea0 menu_scroll_list_nav_step

| field | value |
|---|---|
| Original address | 0x00625ea0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00625ea0 |
| Resolved name | menu_scroll_list_nav_step |
| Subsystem | menus |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00622180
**Callees:** FUN_0061e720, FUN_0061e750, FUN_0061e7f0, FUN_0061e800, FUN_0061e910, FUN_0061f0e0, FUN_0061f0f0, FUN_0061f1d0, FUN_0061f1f0, FUN_0061f2d0, FUN_0061f470, FUN_0061f4b0, FUN_0061f680, FUN_0061f760
**Referenced globals:** 0x365cf0 list-length; 0x66a810 label-table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam007152e1 screen-phase; cRam007152e2 substate; sRam007152e4 frame-timer; sRam007152e8; sRam007152ea cursor-idx

## Behavioral explanation
Per-frame menu-screen state machine (cRam007152e1 phases 0-3) with pad-driven cursor scroll over a uRam00365cf0-length list; drives display selectors, no wire I/O.

## Notes / uncertainty
Already full 2-level phase/substate SM reconstruction. Pad-bit meanings (0x04/0x08 up/down) and substate 0/3 settle-animation intent inferred, not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00625ea0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
