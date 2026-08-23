# 0x005bfa20 recordA_strcpy_name_0x6ce616

| field | value |
|---|---|
| Original address | 0x005bfa20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bfa20 |
| Resolved name | recordA_strcpy_name_0x6ce616 |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ad890
**Callees:** —
**Referenced globals:** 0x6ce616 registry-A render struct field (stride 0x144)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
memcpy's per-entry field at (idx-1)*0x144+0x6ce616 (registry-A render struct) out to caller buffer.

## Notes / uncertainty
strcpy of record-A string, 1-based (idx-1)*0x144+0x6ce616. func_0x00109eb8=strcpy inferred from arity.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bfa20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
