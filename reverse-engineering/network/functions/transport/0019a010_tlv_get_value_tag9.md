# 0x0019a010 tlv_get_value_tag9

| field | value |
|---|---|
| Original address | 0x0019a010 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_0019a010 |
| Resolved name | tlv_get_value_tag9 |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d1740
**Callees:** FUN_0019a2f0, FUN_0019a300, FUN_0019a350
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Byte-identical to 199f10 for tag 9. Same search-hit->0 caveat. Tag-9 meaning unknown.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_0019a010.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
