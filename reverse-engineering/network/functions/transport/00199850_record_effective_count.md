# 0x00199850 record_effective_count

| field | value |
|---|---|
| Original address | 0x00199850 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_00199850 |
| Resolved name | record_effective_count |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d1e40, FUN_001d2170, FUN_001d2290, FUN_001d26f0
**Callees:** FUN_001999e0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
count(+4) of current TLV record, minus 1 iff type_flags(+0) bit 0x80000000 set (reserved-slot exclusion). No NULL-guard. Reserved-slot meaning unproven.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_00199850.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
