# 0x001d2900 finalize_model_archive

| field | value |
|---|---|
| Original address | 0x001d2900 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d2900 |
| Resolved name | finalize_model_archive |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ccd50
**Callees:** FUN_00189db0, FUN_001a9c30
**Referenced globals:** struct+0x816 count; struct+0x80c archive handle
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Streams remaining model handles into struct+4 buffer and finalizes the archive (FUN_00189db0).

## Notes / uncertainty
Finalize half of load_model_archive (1d90): NULL-guarded, streams remaining handles into *(ctx+4), calls FUN_00189db0. Not network.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d2900.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
