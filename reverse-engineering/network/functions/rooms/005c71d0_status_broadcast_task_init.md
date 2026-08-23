# 0x005c71d0 status_broadcast_task_init

| field | value |
|---|---|
| Original address | 0x005c71d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c71d0 |
| Resolved name | status_broadcast_task_init |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005af1a0
**Callees:** —
**Referenced globals:** 0x6cbc5c (task active flag); 0x6cbc58 (phase); 0x6cbc3c; 0x6cbc38 (tick fn-ptr)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6cbc5c; 0x6cbc58

## Behavioral explanation
Arms the periodic LOID/STAT broadcast task: sets active flag, clears phase counters, installs tick fn-ptr FUN_005c7210.

## Notes / uncertainty
Idempotent arm of the paginated status-broadcast task; installs tick 0x5c7210 into ctx@0x6cbc38. Established that phase handlers' param_1 base = 0x6cbc38 (ctx+0x20=phase 0x6cbc58, +0x24=active 0x6cbc5c). Semantic (LOID/STAT) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c71d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
