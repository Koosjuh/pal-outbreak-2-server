# 0x00199890 record_get_count_by_key

| field | value |
|---|---|
| Original address | 0x00199890 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_00199890 |
| Resolved name | record_get_count_by_key |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d1e40, FUN_001d2290, FUN_001d26f0
**Callees:** FUN_001999f0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Keyed count getter: FUN_001999f0(key,0) then +4, NULL->0. Plain (no high-bit adjust) counterpart of 199850. Key namespace undetermined.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_00199890.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
