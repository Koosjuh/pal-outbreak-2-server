# 0x0061c970 icon_glyph_id_lookup

| field | value |
|---|---|
| Original address | 0x0061c970 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061c970 |
| Resolved name | icon_glyph_id_lookup |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00619e00
**Callees:** —
**Referenced globals:** 0x669b30 key table; 0x669b90 id table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Maps an input code to a HUD glyph/icon id by scanning table DAT_00669b30 and returning the parallel id from DAT_00669b90 (with special cases for -1 and 0x7f).

## Notes / uncertainty
Maps error/status code (iRam00715360) to HUD glyph id: scans negative-encoded key table 0x669b30, indexes parallel id table 0x669b90, with -1-skip and 0x7f special bump. 0x7f=self/no-selection sentinel. No explicit scan bound for unknown codes.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061c970.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
