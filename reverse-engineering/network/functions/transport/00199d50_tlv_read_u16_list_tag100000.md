# 0x00199d50 tlv_read_u16_list_tag100000

| field | value |
|---|---|
| Original address | 0x00199d50 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_00199d50 |
| Resolved name | tlv_read_u16_list_tag100000 |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d1960
**Callees:** FUN_00199f70, FUN_0019a350
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Reads tag 0x100000 list under a type==4 node into count-prefixed u16 buffer (narrows u32->u16). Ret 0 ok / -1 wrong-type or missing. List meaning unknown.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_00199d50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
