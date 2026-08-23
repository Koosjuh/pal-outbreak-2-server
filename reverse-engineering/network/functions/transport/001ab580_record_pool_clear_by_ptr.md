# 0x001ab580 record_pool_clear_by_ptr

| field | value |
|---|---|
| Original address | 0x001ab580 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ab580 |
| Resolved name | record_pool_clear_by_ptr |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001cf8e0
**Callees:** FUN_00106b60
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Free-counterpart to ab460: finds slot by ptr in 0x2a4a1c, memsets size*152 bytes, clears type tag; does NOT rewind count/used (soft free, leaves holes).

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001ab580.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
