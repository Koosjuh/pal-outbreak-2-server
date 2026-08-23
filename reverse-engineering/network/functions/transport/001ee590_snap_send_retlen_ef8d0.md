# 0x001ee590 snap_send_retlen_ef8d0

| field | value |
|---|---|
| Original address | 0x001ee590 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ee590 |
| Resolved name | snap_send_retlen_ef8d0 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c4070, FUN_001c4100, FUN_001c42d0, FUN_001c43c0, FUN_001c4560, FUN_001c46a0, FUN_001c48c0, FUN_001c4c80, FUN_001c4fb0, FUN_001c51a0, FUN_001c5480, FUN_001c5630, FUN_001c5900, FUN_001c5bd0, FUN_001c5ea0, FUN_001c6060, FUN_001c6330, FUN_001c64f0, FUN_001c67b0, FUN_001c69b0, FUN_001c6b90, FUN_001c6dc0, FUN_001c7000, FUN_001c7580, FUN_001c7980, FUN_001c85c0, FUN_001c8b60, FUN_001c8d30, FUN_001c8dd0, FUN_001c8f50, FUN_001c94c0
**Callees:** FUN_001ee150, FUN_001ef8d0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
SN@P thunk over FUN_001ef8d0; returns caller-supplied param_3 when the post-processed status is exactly 0 (success-with-default).

## Notes / uncertainty
send wrapper over RPC cmd 0x0f; returns len on success (r==0) else errno. a1/a2 tail-forward inferred from ABI+ef8d0 sig (not visible in frame). Runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ee590.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
