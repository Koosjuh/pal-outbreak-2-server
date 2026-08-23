# 0x001eb5ac list_insert_after_locked

| field | value |
|---|---|
| Original address | 0x001eb5ac |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eb5ac |
| Resolved name | list_insert_after_locked |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d5ae4
**Callees:** FUN_001ebe64
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Under the list lock, inserts a node after a reference node and increments the count.

## Notes / uncertainty
Insert-after-anchor under lock, count++ (renamed to note positional/after semantics vs tail). Caller must guarantee anchor belongs to list (unchecked).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eb5ac.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
