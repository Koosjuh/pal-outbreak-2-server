# 0x001eb2d4 list_count

| field | value |
|---|---|
| Original address | 0x001eb2d4 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eb2d4 |
| Resolved name | list_count |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d5460, FUN_001d5ae4, FUN_001d6468, FUN_001d6dfc, FUN_001d7104, FUN_001d72a8, FUN_001e1c10, FUN_001e3ba8, FUN_001ec1f8, FUN_001ec9e0, FUN_001ecdc0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns the list/queue element count (u16 at +0xc).

## Notes / uncertainty
Accessor: u16 count at +0xc. Certain.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eb2d4.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
