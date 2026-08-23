# 0x001eb1b0 list_create

| field | value |
|---|---|
| Original address | 0x001eb1b0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eb1b0 |
| Resolved name | list_create |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001e1e4c, FUN_001eb22c
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocates a 0x14-byte list/queue head and initializes it via list_init; returns error 0xffffe4a9 on OOM.

## Notes / uncertainty
Alloc 0x14 list head + list_init; returns 0xffffe4a9 OOM sentinel. No recorded callers in this slice.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eb1b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
