# 0x001eb3b8 list_insert_tail

| field | value |
|---|---|
| Original address | 0x001eb3b8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eb3b8 |
| Resolved name | list_insert_tail |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d5460, FUN_001d6468, FUN_001d6988, FUN_001e16b4, FUN_001e180c, FUN_001e1c10, FUN_001e3a3c, FUN_001ebae0, FUN_001ec9e0, FUN_001ed168
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Links a node at the tail of the circular list and increments the count (+0xc).

## Notes / uncertainty
Unlocked circular-dlist tail splice; header is sentinel, count at +0x0c. Mechanics certain; per-caller list identity varies. No runtime proof.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eb3b8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
