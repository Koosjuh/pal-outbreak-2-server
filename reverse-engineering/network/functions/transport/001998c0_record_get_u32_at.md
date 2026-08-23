# 0x001998c0 record_get_u32_at

| field | value |
|---|---|
| Original address | 0x001998c0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001998c0 |
| Resolved name | record_get_u32_at |
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
Bounds-checked indexed getter: resolve record by key, if index<count(+4) return payload[index](+0xc+i*4), else 0xffffffff sentinel. Element semantics depend on record type.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001998c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
