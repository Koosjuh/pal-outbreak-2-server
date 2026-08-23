# 0x006336d0 scroll_candidate_page

| field | value |
|---|---|
| Original address | 0x006336d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006336d0 |
| Resolved name | scroll_candidate_page |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00633930, FUN_00633ab0
**Callees:** FUN_00633590, FUN_006335f0, FUN_00633650
**Referenced globals:** 0x7158f0 (candidate cells); 0x715b30 (grid); 0x715da8+0x258 (total count); 0x715da8+0x36
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715da8+0x36

## Behavioral explanation
Repaginates the 3-cell candidate grid up (param_2==0) or down, filling cells via set/draw helpers when predictive flag set.

## Notes / uncertainty
Repaginate 3-cell grid; clears 32 cells+grid, fills min(3,total-base) cells ascending/descending by dir, loads row, draws 3. Fill-loop counts are Medium: extraout_t0/t1 artifacts + set_candidate_cell modeled as returning next index.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006336d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
