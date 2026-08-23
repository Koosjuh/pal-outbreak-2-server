# 0x001caad0 snap_send_unreliable

| field | value |
|---|---|
| Original address | 0x001caad0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001caad0 |
| Resolved name | snap_send_unreliable |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001ca9d0, FUN_001cac50, FUN_001cac60, FUN_001df1d8
**Referenced globals:** 0x35b9e0=snap conn handle; 0x3688d0/d8=busy flags
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x3688d0/d8=in-flight guards

## Behavioral explanation
Guarded unreliable-send: identical to snap_send_reliable but passes size flag 0 (unreliable) to FUN_001df1d8.

## Notes / uncertainty
Unreliable send: identical to 0x1caa30 but flag 0 to FUN_001df1d8. A/B isolates the flag arg (0x8000 vs 0) as the reliable/unreliable selector.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001caad0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
