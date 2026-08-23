# 0x001eb4dc list_unlink_locked

| field | value |
|---|---|
| Original address | 0x001eb4dc |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eb4dc |
| Resolved name | list_unlink_locked |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d5460, FUN_001d5ae4, FUN_001e1ac8, FUN_001e1c10
**Callees:** FUN_001ebe64
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Under the list lock, unlinks a given node from the list and decrements the count.

## Notes / uncertainty
Mid-list unlink under lock (op1 acquire/op2 release via FUN_001ebe64), count--. Lock primitive type (mutex vs IRQ mask) unresolved.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eb4dc.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
