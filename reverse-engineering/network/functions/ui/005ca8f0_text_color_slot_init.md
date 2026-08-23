# 0x005ca8f0 text_color_slot_init

| field | value |
|---|---|
| Original address | 0x005ca8f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ca8f0 |
| Resolved name | text_color_slot_init |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c80a0
**Callees:** —
**Referenced globals:** 0x701068+0x68f94.. color table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701068+0x68f94

## Behavioral explanation
Initializes two reserved GS color-register slots (indices 0xd/0xe) at the 0x68f94 color table via func_0x001af010.

## Notes / uncertainty
Seeds reserved color-slots 0xd/0xe of the 0x68f94 table (used/key/mode) and programs GS via func_0x001af010. Color-arg semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ca8f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
