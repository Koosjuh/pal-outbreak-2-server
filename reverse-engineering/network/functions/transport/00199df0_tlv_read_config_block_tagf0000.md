# 0x00199df0 tlv_read_config_block_tagf0000

| field | value |
|---|---|
| Original address | 0x00199df0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_00199df0 |
| Resolved name | tlv_read_config_block_tagf0000 |
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
Reads fixed 18-word (0x48) block from tag 0xf0000 under type==4 node; validates word0 high-half magic==0x0001. Ret 0 ok / -1 missing / -2 bad-magic. Likely a net-config descriptor (inferred).

## Raw decompilation
`sources/executables/netstack-decompile/FUN_00199df0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
