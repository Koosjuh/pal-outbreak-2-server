# 0x00623670 screen_handler_leave

| field | value |
|---|---|
| Original address | 0x00623670 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00623670 |
| Resolved name | screen_handler_leave |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00622180
**Callees:** FUN_00606a50, FUN_00606a70, FUN_0061ea10
**Referenced globals:** 0x715298 screen struct ptr
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** substate @ struct+1; timer @ struct+6

## Behavioral explanation
Exit/leave handler for screens '+'/'*'/'(': runs timed leave animation and FUN_00606a50/a70 (unload), returns 1 when the room/screen has been left.

## Notes / uncertainty
4-phase timed exit/unload SM on ctx[1] substate; screen-id '(' (0x28) is the room screen needing extra FUN_00606a50/a70 unload. Returns 1 when fully left. Fade primitives inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00623670.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
