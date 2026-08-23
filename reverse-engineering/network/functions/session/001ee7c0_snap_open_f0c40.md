# 0x001ee7c0 snap_open_f0c40

| field | value |
|---|---|
| Original address | 0x001ee7c0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ee7c0 |
| Resolved name | snap_open_f0c40 |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c08e0
**Callees:** FUN_001f0c40
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Opens/creates a SN@P handle via FUN_001f0c40(); returns handle or -1. Sets no flag.

## Notes / uncertainty
Plain open via 001f0c40, no flag; paired with 001ee810 under caller 001c08e0 (matched resource pair). Resource identity undecoded. (Was Medium; mechanics are trivial pass-through.)

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ee7c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
