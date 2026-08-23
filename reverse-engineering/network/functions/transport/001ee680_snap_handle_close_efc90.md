# 0x001ee680 snap_handle_close_efc90

| field | value |
|---|---|
| Original address | 0x001ee680 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ee680 |
| Resolved name | snap_handle_close_efc90 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9780, FUN_001ca3a0, FUN_001ca590
**Callees:** FUN_001ee150, FUN_001efc90
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Close/release variant: guards *handle<0, else FUN_001efc90((short)*handle), invalidates slot to -1, post-processes.

## Notes / uncertainty
close+invalidate mirror of ee5f0 but RPC cmd 0x4a (different handle class). Class semantics unconfirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ee680.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
