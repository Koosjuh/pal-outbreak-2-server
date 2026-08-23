# 0x005cd390 screen_step_dispatch

| field | value |
|---|---|
| Original address | 0x005cd390 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005cd390 |
| Resolved name | screen_step_dispatch |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005dd920
**Referenced globals:** PTR_FUN_00642d30 step handler table; 0x701070+2 step index
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+2

## Behavioral explanation
Indirect-call dispatcher: invokes the handler for the current screen step from jump table PTR_FUN_00642d30 indexed by 0x701070+2, then clears the top color bar.

## Notes / uncertainty
Indirect dispatcher over 0x642d30 build-step table indexed by scr+2; then FUN_005dd920(0x14,mask) top-bar clear (inferred). Table length/entries not dumped; FUN_005dd920 semantics assumed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005cd390.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
