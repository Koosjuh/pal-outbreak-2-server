# 0x00630420 softkbd_key_to_glyph_index

| field | value |
|---|---|
| Original address | 0x00630420 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00630420 |
| Resolved name | softkbd_key_to_glyph_index |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_006352e0
**Callees:** FUN_00630c30, FUN_00630c50, FUN_006343b0
**Referenced globals:** iRam00715da8 (widget state); DAT_0068b6b0 / DAT_0068b690 / DAT_0068b068 / DAT_0068ae50 / PTR_LAB_0068af40 / 0x68b130 / 0x68b4c0 (keyboard glyph layout tables)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x1e layout page; +0x1f field state; +0x34 field kind; +0x4a4 key code; +0x49f modifier bits

## Behavioral explanation
Maps the current key code + layout/field/shift state to a glyph/tile short index via nested per-layout lookup tables; returns whether a valid glyph was produced.

## Notes / uncertainty
Maps selected key->glyph short index via parity/field-kind/shift into 7 layout tables; returns valid!=-1. Control flow exact but glyph-table element semantics and FUN_006343b0 selector meaning inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00630420.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
