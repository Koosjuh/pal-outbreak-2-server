# 0x001a1750 asset_load_named_or_indexed

| field | value |
|---|---|
| Original address | 0x001a1750 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001a1750 |
| Resolved name | asset_load_named_or_indexed |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001cfb30, FUN_001d0040, FUN_001d0230, FUN_001d0400
**Callees:** FUN_001069a8, FUN_00109728, FUN_00109ab0, FUN_00109eb8, FUN_0010a050, FUN_0010a6b0, FUN_001841d0, FUN_001a0df0, FUN_001a0e90, FUN_001a79b0, FUN_001cba30, FUN_001cbc20, FUN_001cbc30, FUN_001cc170, FUN_001ce2d0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Sibling loader: param_1==0 derives filename from a freshly allocated slot (strip dir/ext, add suffix, chanA); else explicit key with param_4&0x10000 selecting chanA(0x23ae80) vs chanB(0x23ae88). 0x30 header, length-prefixed block loop (LZ+upload), ce2d0 build with mode=param_4&0x7fffffff. Path-A FUN_001cc170 arg roles uncertain.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001a1750.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
