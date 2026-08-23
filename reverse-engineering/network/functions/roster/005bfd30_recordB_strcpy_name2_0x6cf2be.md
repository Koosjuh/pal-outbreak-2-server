# 0x005bfd30 recordB_strcpy_name2_0x6cf2be

| field | value |
|---|---|
| Original address | 0x005bfd30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bfd30 |
| Resolved name | recordB_strcpy_name2_0x6cf2be |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ada90
**Callees:** —
**Referenced globals:** 0x6cf2be render struct field (stride 0x144)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
memcpy's per-entry field at (idx-1)*0x144+0x6cf2be (0x6cf1xx render-struct family) out to caller.

## Notes / uncertainty
strcpy string #2 of record-family-B, 1-based; +0x24 from string #1.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bfd30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
