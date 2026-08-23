# 0x001eb918 list_destroy

| field | value |
|---|---|
| Original address | 0x001eb918 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eb918 |
| Resolved name | list_destroy |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001e2010, FUN_001ebe64
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Destroys a list only if empty: invokes lock callback cmd 3 (destroy) then frees the head; returns -0x1b55 if still populated.

## Notes / uncertainty
Empty-only teardown: refuses with SNAP_ERR_NOT_EMPTY 0xffffe4ab if count!=0; else lock_invoke op3 (destroy) then mem_free. Op3 destroy semantics inferred from ordering.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eb918.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
