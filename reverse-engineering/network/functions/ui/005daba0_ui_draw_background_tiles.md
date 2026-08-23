# 0x005daba0 ui_draw_background_tiles

| field | value |
|---|---|
| Original address | 0x005daba0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005daba0 |
| Resolved name | ui_draw_background_tiles |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ddb40, FUN_005dfee0, FUN_005e00e0, FUN_005e15e0
**Referenced globals:** iRam00701070+0x1a/0x1e: draw origin; iRam00701068+0x68e7e: state; iRam00701068+0x60dc4: cleanup counter
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x68e7e

## Behavioral explanation
UI draw callback: on 'c' cleanup destroys node; otherwise fills the viewport with a tiled sprite grid (nested loops over 640x448 stepping by tile size), capped at 0x200 tiles.

## Notes / uncertainty
Draw cb: full-screen backdrop (640x448) + tiled sprite grid capped at 512, lifecycle 'c'=free. +0x5d scroll-lock and float-field roles inferred; tile-descriptor table format not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005daba0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
