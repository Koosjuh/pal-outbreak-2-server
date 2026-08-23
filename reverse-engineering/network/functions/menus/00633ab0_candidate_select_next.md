# 0x00633ab0 candidate_select_next

| field | value |
|---|---|
| Original address | 0x00633ab0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00633ab0 |
| Resolved name | candidate_select_next |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00630f20, FUN_00631cf0, FUN_00631d60, FUN_00635030
**Callees:** FUN_006336d0, FUN_00637e60
**Referenced globals:** 0x715da8+0x24c; 0x715da8+0x250; 0x715da8+0x258; 0x715da8+0x47c; 0x715da8+0x254
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715da8+0x24c; 0x715da8+0x2f

## Behavioral explanation
Moves candidate selection to next entry (wraps at count), repaginating on page boundary, updating active candidate (+0x47c) and type byte (+0x254).

## Notes / uncertainty
Mirror of prev; wrap at count->0. Note asymmetry: forward page-cross passes raw sel index to FUN_006336d0 vs prev passing page*3.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00633ab0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
