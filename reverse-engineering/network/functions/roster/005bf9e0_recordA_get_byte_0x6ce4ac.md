# 0x005bf9e0 recordA_get_byte_0x6ce4ac

| field | value |
|---|---|
| Original address | 0x005bf9e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bf9e0 |
| Resolved name | recordA_get_byte_0x6ce4ac |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ad890
**Callees:** —
**Referenced globals:** 0x6ce4ac registry-A render struct byte field (stride 0x144)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Reads 8-bit field at idx*0x144+0x6ce4ac (registry-A render struct flag/count) into out-ptr.

## Notes / uncertainty
u8 read at record-A +0x12; mechanical certain, byte semantics (flag/count) unproven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bf9e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
