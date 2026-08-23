# 0x0062bda0 roster_download_dispatch

| field | value |
|---|---|
| Original address | 0x0062bda0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062bda0 |
| Resolved name | roster_download_dispatch |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062ba70
**Callees:** FUN_0062be30, FUN_0062bee0, FUN_0062c030, FUN_0062c160
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sub-dispatcher on the task's +1 state (0..3) into roster fetch-init / per-slot-confirm / record-store handlers.

## Notes / uncertainty
4-way sub-dispatch on task+0x1 (0=init/fetch FUN_0062be30,1,2,3=finalize FUN_0062c160) for the member-list download; called from poll FUN_0062ba70. Per-substate callee roles / op0a binding not traced; substate labels inferred from init->finalize ordering.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062bda0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
