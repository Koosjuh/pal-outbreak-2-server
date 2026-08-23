# 0x001d1d90 load_model_archive

| field | value |
|---|---|
| Original address | 0x001d1d90 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d1d90 |
| Resolved name | load_model_archive |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ccd50
**Callees:** FUN_001889b0, FUN_00189530, FUN_00189db0, FUN_001a9a90, FUN_001a9c30
**Referenced globals:** 0x3435bc scratch base
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Opens a model archive (offset +0x200000) and streams model handles into param buffer.

## Notes / uncertainty
Simplest model-archive loader: open (scratch iRam3435bc+0x200000), stream N element handles into *param_1, finalize. Not network.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d1d90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
