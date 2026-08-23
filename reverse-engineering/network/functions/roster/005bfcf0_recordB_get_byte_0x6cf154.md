# 0x005bfcf0 recordB_get_byte_0x6cf154

| field | value |
|---|---|
| Original address | 0x005bfcf0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bfcf0 |
| Resolved name | recordB_get_byte_0x6cf154 |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ada90, FUN_005f7b30
**Callees:** —
**Referenced globals:** 0x6cf154 render struct byte field (stride 0x144)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Reads 8-bit field at idx*0x144+0x6cf154 (0x6cf1xx render-struct family) into out-ptr.

## Notes / uncertainty
u8 read record-family-B +0x12; twin of FUN_005bf9e0.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bfcf0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
