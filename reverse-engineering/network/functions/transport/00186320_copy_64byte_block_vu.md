# 0x00186320 copy_64byte_block_vu

| field | value |
|---|---|
| Original address | 0x00186320 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_00186320 |
| Resolved name | copy_64byte_block_vu |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00189bb0, FUN_00189db0, FUN_001d1e40, FUN_001d2170, FUN_001d2290
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
4x16B quadword block copy from global 0x27f200 into param_1 via VU lqc2/sqc2. Copy mechanics unambiguous; identity of 64B source (matrix/key/params) unknown.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_00186320.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
