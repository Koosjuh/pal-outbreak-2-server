# 0x001ee5f0 snap_handle_close_ef770

| field | value |
|---|---|
| Original address | 0x001ee5f0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ee5f0 |
| Resolved name | snap_handle_close_ef770 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c2770
**Callees:** FUN_001ee150, FUN_001ef770
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Closes/releases a SN@P handle: if *handle already <0 no-op-sets -1, else calls FUN_001ef770((short)*handle), invalidates the slot to -1, post-processes.

## Notes / uncertainty
double-close guard + invalidate slot to -1; RPC cmd 0x0b. Exact handle class vs 0x0c/0x4a unconfirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ee5f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
