# 0x00622180 screen_dispatch

| field | value |
|---|---|
| Original address | 0x00622180 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00622180 |
| Resolved name | screen_dispatch |
| Subsystem | menus |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00621f10
**Callees:** FUN_0061e8f0, FUN_0061f9f0, FUN_0061fd70, FUN_00620250, FUN_006205c0, FUN_00620b60, FUN_00621fb0, FUN_00622c30, FUN_00622d60, FUN_00622f40, FUN_00623090, FUN_006231b0, FUN_00623360, FUN_006233e0, FUN_00623670, FUN_00624850, FUN_00624c70, FUN_00625190, FUN_00625670, FUN_00625ea0, FUN_006265f0, FUN_00626900, FUN_00626e70, FUN_00627400, FUN_00627540
**Referenced globals:** 0x715298 screen struct ptr; 0x71543c input-lock; 0x715478 flag; 0x715474 flag; 0x3c98a0 role flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** pcRam00715298; uRam0071543c; iRam00715478

## Behavioral explanation
Central screen dispatcher: reads the screen-id byte (*0x715298), calls the matching per-screen handler, and on its return code advances to the next screen via FUN_00621fb0.

## Notes / uncertainty
Already full: exact screen-id->handler->goto_screen graph, struct flag writes, crit-section around net query. Numeric screen-id -> named lobby screen mapping still inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00622180.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
