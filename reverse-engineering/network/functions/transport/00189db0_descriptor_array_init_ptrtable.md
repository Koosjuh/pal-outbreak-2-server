# 0x00189db0 descriptor_array_init_ptrtable

| field | value |
|---|---|
| Original address | 0x00189db0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_00189db0 |
| Resolved name | descriptor_array_init_ptrtable |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d1d90, FUN_001d2900
**Callees:** FUN_00186320, FUN_00189f00, FUN_0018a0b0, FUN_0018a400
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Pointer-table twin of 189bb0 (descriptors via param_1[i] not contiguous); identical field init; finalises via FUN_00189f00/0018a0b0 from element 0.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_00189db0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
