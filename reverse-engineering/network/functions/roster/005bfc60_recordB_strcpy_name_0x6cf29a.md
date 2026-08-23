# 0x005bfc60 recordB_strcpy_name_0x6cf29a

| field | value |
|---|---|
| Original address | 0x005bfc60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bfc60 |
| Resolved name | recordB_strcpy_name_0x6cf29a |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f7b30
**Callees:** —
**Referenced globals:** 0x6cf29a render struct field (stride 0x144)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
memcpy's per-entry field at (idx-1)*0x144+0x6cf29a (second render-struct family) out to caller.

## Notes / uncertainty
strcpy string #1 of record-family-B, 1-based; paired name2 at +0x24 (FUN_005bfd30).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bfc60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
