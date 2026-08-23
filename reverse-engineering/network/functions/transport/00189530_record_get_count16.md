# 0x00189530 record_get_count16

| field | value |
|---|---|
| Original address | 0x00189530 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_00189530 |
| Resolved name | record_get_count16 |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d1d90
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Returns u16 count at header+2 of current record (NULL->0). +2=count cross-confirmed by 189bb0/189db0 loop bounds. +0 field unknown.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_00189530.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
