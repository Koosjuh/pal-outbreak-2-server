# 0x001ee810 snap_open_f0cb0

| field | value |
|---|---|
| Original address | 0x001ee810 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ee810 |
| Resolved name | snap_open_f0cb0 |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c08e0
**Callees:** FUN_001f0cb0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Opens/creates a SN@P handle via FUN_001f0cb0(); returns handle or -1.

## Notes / uncertainty
Plain open via 001f0cb0, no flag; sibling of 001ee7c0. c40-vs-cb0 distinction inferred from paired-call pattern only.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ee810.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
