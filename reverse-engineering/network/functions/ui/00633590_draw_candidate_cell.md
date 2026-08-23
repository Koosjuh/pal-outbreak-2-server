# 0x00633590 draw_candidate_cell

| field | value |
|---|---|
| Original address | 0x00633590 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00633590 |
| Resolved name | draw_candidate_cell |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006336d0, FUN_00633840
**Callees:** FUN_00637e60
**Referenced globals:** 0x7158f2 (candidate glyph table); 0x715b30 (candidate render grid)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
If candidate slot [param_1] non-empty, blits its glyphs from 0x7158f2 into the on-screen candidate grid cell at 0x715b30.

## Notes / uncertainty
Blits glyph from candidate cell (0x7158f0 stride 0x12, glyph@+2) to render grid (0x715b30 stride 0x10) if non-empty. FUN_00637e60=glyph copy.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00633590.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
