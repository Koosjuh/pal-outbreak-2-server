# 0x005bfcb0 recordB_get_short_0x6cf142

| field | value |
|---|---|
| Original address | 0x005bfcb0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bfcb0 |
| Resolved name | recordB_get_short_0x6cf142 |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ada90, FUN_005b57e0, FUN_005f7b30
**Callees:** —
**Referenced globals:** 0x6cf142 render struct base (stride 0x144)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Reads 16-bit field at idx*0x144+0x6cf142 (0x6cf1xx render-struct family) into out-ptr.

## Notes / uncertainty
u16 read record-family-B +0x00, 0-based; same row head (+0x00 u16,+0x12 u8) as record-A.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bfcb0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
