# 0x005bf3a0 get_field_0x6ce5be_u16

| field | value |
|---|---|
| Original address | 0x005bf3a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bf3a0 |
| Resolved name | get_field_0x6ce5be_u16 |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ad890
**Callees:** —
**Referenced globals:** 0x6ce5be roster field (u16)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Reads a 16-bit global roster field (0x6ce5be) into caller out-ptr.

## Notes / uncertainty
Reads single non-indexed u16 at 0x6ce5be (within 0x144-stride registry region, base+0x124). Semantic label unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bf3a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
