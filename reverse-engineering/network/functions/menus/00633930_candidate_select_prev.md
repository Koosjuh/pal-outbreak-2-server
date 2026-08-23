# 0x00633930 candidate_select_prev

| field | value |
|---|---|
| Original address | 0x00633930 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00633930 |
| Resolved name | candidate_select_prev |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00630f20, FUN_00631c80, FUN_00631d60, FUN_00635030
**Callees:** FUN_006336d0, FUN_00637e60
**Referenced globals:** 0x715da8+0x24c (sel index); 0x715da8+0x250 (page); 0x715da8+0x258 (count); 0x715da8+0x47c; 0x715da8+0x254
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715da8+0x24c; 0x715da8+0x2f

## Behavioral explanation
Moves candidate selection to previous entry (wraps at 0), repaginating when crossing a page, and updates active candidate (+0x47c) and type byte (+0x254).

## Notes / uncertainty
IME candidate nav backward; wrap at 0, repaginate on page-top cross, copy active text (+0x47c) + type byte (+0x254). FUN_006336d0 refill internals not decompiled.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00633930.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
