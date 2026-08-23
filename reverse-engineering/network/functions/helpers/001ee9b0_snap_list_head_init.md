# 0x001ee9b0 snap_list_head_init

| field | value |
|---|---|
| Original address | 0x001ee9b0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ee9b0 |
| Resolved name | snap_list_head_init |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001c0f40
**Callees:** —
**Referenced globals:** 0x0024e3b0 (DAT sentinel/default record)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Initializes two list-head pointers to a sentinel (&DAT_0024e3b0) — empty-list/self-referential init.

## Notes / uncertainty
Intrusive-list head init: both link slots set to shared sentinel &DAT_0024e3b0. Pointer arg passed in $t0 (in_t0_lo register artifact), not recovered as a formal param; next/prev vs head/tail ordering inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ee9b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
