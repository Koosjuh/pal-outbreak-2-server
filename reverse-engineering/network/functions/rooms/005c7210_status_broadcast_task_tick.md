# 0x005c7210 status_broadcast_task_tick

| field | value |
|---|---|
| Original address | 0x005c7210 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c7210 |
| Resolved name | status_broadcast_task_tick |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c7290, FUN_005c72d0, FUN_005c7540
**Referenced globals:** 0x6cbc5c (active flag); 0x6cbc58 (phase)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6cbc58

## Behavioral explanation
Per-tick dispatcher for the status-broadcast task; branches on phase (0x6cbc58) to phase-0/1/2 handlers.

## Notes / uncertainty
Per-frame dispatcher on phase byte 0x6cbc58 while active; routes phase 0/1/2 to 7290/72d0/7540. Control flow certain; phase semantic labels inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c7210.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
