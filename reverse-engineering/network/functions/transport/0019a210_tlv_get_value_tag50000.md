# 0x0019a210 tlv_get_value_tag50000

| field | value |
|---|---|
| Original address | 0x0019a210 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_0019a210 |
| Resolved name | tlv_get_value_tag50000 |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0019aaf0, FUN_001d1960
**Callees:** FUN_00199f70, FUN_0019a350
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Scalar value(+4) getter for tag 0x50000 under FUN_00199f70 node, NULL-safe both levels (no type==4 check). Payload list form is FUN_0019a260 (confirms 0x50000 = u32 list).

## Raw decompilation
`sources/executables/netstack-decompile/FUN_0019a210.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
