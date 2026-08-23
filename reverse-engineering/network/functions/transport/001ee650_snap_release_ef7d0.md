# 0x001ee650 snap_release_ef7d0

| field | value |
|---|---|
| Original address | 0x001ee650 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ee650 |
| Resolved name | snap_release_ef7d0 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c9780, FUN_001ca3a0, FUN_001ca590
**Callees:** FUN_001ee150, FUN_001ef7d0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
SN@P thunk over FUN_001ef7d0(arg) then FUN_001ee150; sets no state.

## Notes / uncertainty
fire-and-forget release by-value, RPC cmd 0x0c, result discarded (void). Object class inferred from teardown callers.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ee650.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
