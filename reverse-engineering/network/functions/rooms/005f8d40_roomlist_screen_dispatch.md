# 0x005f8d40 roomlist_screen_dispatch

| field | value |
|---|---|
| Original address | 0x005f8d40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f8d40 |
| Resolved name | roomlist_screen_dispatch |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acab0
**Callees:** FUN_005aec70, FUN_005f8e20, FUN_00603e40, FUN_00627d60, FUN_00628e10, FUN_00628ee0, FUN_0062ba00, FUN_0062ba70
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+1 (screen id)

## Behavioral explanation
Per-frame dispatcher for the room-list screen (busy-gated FUN_005aec70): routes on *(param+1) to FUN_005f8e20 (page router) and the area/scenario handlers.

## Notes / uncertainty
Busy-gated (FUN_005aec70) per-frame dispatcher on +0x01 selector {0,1,2,3,9}; selector 0 -> roomlist_page_router. Sub-screens 1/2/3/9 roles inferred, not traced. -2 return of FUN_00628e10 unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f8d40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
