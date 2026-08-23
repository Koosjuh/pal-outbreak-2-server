# 0x005ec4f0 parse_color_value

| field | value |
|---|---|
| Original address | 0x005ec4f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ec4f0 |
| Resolved name | parse_color_value |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e7710, FUN_005eabd0, FUN_005eac40, FUN_005eb3a0, FUN_005ebc50, FUN_005ef220, FUN_005ef3f0
**Callees:** —
**Referenced globals:** DAT_006492b0 (hex nibble table); PTR_s_ALICEBLUE_00648d10 (named-color table); 0x648d14 (rgb entries)
**Referenced strings:** ALICEBLUE (+ X11/CSS color-name table)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Parses a color: '#'-prefixed hex via nibble table 0x6492b0, else looks up a named color in the ALICEBLUE keyword table (0x648d10, ~0x93 entries) and returns packed RGB.

## Notes / uncertainty
HTML/CSS color parser: '#'-hex via nibble table 0x6492b0, else 147-entry X11 name table (0x648d10 ALICEBLUE...) -> packed 0xRRGGBB, -1 on miss. Conclusively UI, string evidence.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ec4f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
