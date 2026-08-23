# 0x00633c10 render_candidate_box

| field | value |
|---|---|
| Original address | 0x00633c10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00633c10 |
| Resolved name | render_candidate_box |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00636890
**Callees:** FUN_005af2c0, FUN_00632c00, FUN_006381e0
**Referenced globals:** 0x715da8+0x25c (box x); 0x715da8+0x24c (sel); 0x715da8+0x258 (total); 0x715b30 (cells); 0x68f2d0/0x68f2d8 (fmt strings)
**Referenced strings:** %d/%d style counter (0068f2d8)
**Referenced opcodes:** —
**State vars:** 0x715da8+0x2f; 0x715da8+0x24c

## Behavioral explanation
Draws the predictive-candidate popup box (frame quads) plus the 3 candidate strings and an 'index/total' counter for the current selection.

## Notes / uncertainty
Draws IME popup: 2 frame quads (inner 0xff303030), 3 candidate rows w/ selected-row highlight, 'idx/total' counter. GS selector args (-24/-25) and text-mode 0/1/3 semantics uncertain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00633c10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
