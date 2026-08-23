# 0x00619750 presence_list_net_tick

| field | value |
|---|---|
| Original address | 0x00619750 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00619750 |
| Resolved name | presence_list_net_tick |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00619330
**Callees:** FUN_005af3c0, FUN_005af3e0, FUN_005af400, FUN_0061ded0
**Referenced globals:** ctx+1 substate
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** *(ctx+1)

## Behavioral explanation
Step 4: drives the underlying network session machine (FUN_0061ded0) and maps its result into the presence machine's advance/retry substates.

## Notes / uncertainty
Phase 4: pumps net-session poll FUN_0061ded0 (>0 ok / <0 err / 0 pending), picks ok/err timer, returns 1 at substate 2 (machine complete). Timer-helper roles and poll contract inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00619750.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
