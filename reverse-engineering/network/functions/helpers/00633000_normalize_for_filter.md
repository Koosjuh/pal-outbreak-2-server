# 0x00633000 normalize_for_filter

| field | value |
|---|---|
| Original address | 0x00633000 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00633000 |
| Resolved name | normalize_for_filter |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00632d20
**Callees:** —
**Referenced globals:** 0x68f090 (uppercase/width fold table)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Case/width-folds a string and applies leetspeak substitutions (@→A, $→S, 5→S, <(→C, !1→I, 2→Z, 0→O) into a scratch buffer for the word filter.

## Notes / uncertainty
Case/width fold via 16-bit table 0x68f090 + leetspeak cascade (@->A,$/5->S,</( ->C,!/1->I,2->Z,0->O). Wide glyphs (cp>=0x100) passthrough. Fold table not dumped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00633000.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
