# 0x005ca9c0 color_slot_alloc

| field | value |
|---|---|
| Original address | 0x005ca9c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ca9c0 |
| Resolved name | color_slot_alloc |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005cab10
**Callees:** —
**Referenced globals:** 0x701068+0x68f94 color slot table[16]
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701068+0x68f94

## Behavioral explanation
Find-or-allocate a color-register slot (indices 2..0xf, 8-byte stride at 0x68f94) keyed by (RGBA|0xff000000, flag byte), registering it via func_0x001af010.

## Notes / uncertainty
Find-or-alloc GS color register over 16-slot 0x68f94 table keyed by (rgba|0xff000000, mode); alloc from idx2, GS reg=slot+0xd, returns 1 if full. Mode style meaning inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ca9c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
