# 0x006193e0 presence_list_reset

| field | value |
|---|---|
| Original address | 0x006193e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006193e0 |
| Resolved name | presence_list_reset |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00619330
**Callees:** FUN_005af2f0, FUN_005ba7b0, FUN_00618b60
**Referenced globals:** step byte *(ctx)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Step 0 of the presence machine: resets UI view flags, advances the step, and kicks a refresh timer (FUN_005af2f0 0,10).

## Notes / uncertainty
Phase 0: view reset + advance + start refresh timer(0,10). FUN_005ba7b0/FUN_00618b60 unresolved beyond reset-ish. Domain (buddy/name list) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006193e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
