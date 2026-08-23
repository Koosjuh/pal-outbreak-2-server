# 0x00633650 load_candidate_row

| field | value |
|---|---|
| Original address | 0x00633650 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00633650 |
| Resolved name | load_candidate_row |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006336d0, FUN_00633840
**Callees:** FUN_00637e60
**Referenced globals:** 0x715da8+0x47c; 0x715da8+0x260; 0x7158f2 (candidate glyphs); 0x715da8+0x24c (cursor)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715da8+0x24c

## Behavioral explanation
Loads the active candidate string (+0x47c) and preview (+0x260) from the dictionary row selected by (state+0x24c %3).

## Notes / uncertainty
Loads highlighted cell ((kbd+0x24c)%3) glyph into active-candidate kbd+0x47c and mirrors to preview kbd+0x260.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00633650.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
