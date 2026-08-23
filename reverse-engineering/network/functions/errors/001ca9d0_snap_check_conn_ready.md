# 0x001ca9d0 snap_check_conn_ready

| field | value |
|---|---|
| Original address | 0x001ca9d0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ca9d0 |
| Resolved name | snap_check_conn_ready |
| Subsystem | errors |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001caa30, FUN_001caad0
**Callees:** —
**Referenced globals:** 0x25b790=conn state code
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x25b790=conn state

## Behavioral explanation
Validates the global connection-state code against {0x64,0x65,0x66,0x67}; returns -12 for a valid-but-busy state or -16 otherwise.

## Notes / uncertainty
Guard on global conn-state DAT_0025b790: returns -12 (0xFFFFFFF4) if state in {0x64..0x67}, else -16 (0xFFFFFFF0). Band test exact; busy-vs-badstate semantic labels inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ca9d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
