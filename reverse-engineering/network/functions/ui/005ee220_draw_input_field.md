# 0x005ee220 draw_input_field

| field | value |
|---|---|
| Original address | 0x005ee220 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ee220 |
| Resolved name | draw_input_field |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005ee610, FUN_005f2e50
**Callees:** FUN_005d96a0, FUN_005d9790, FUN_005ed630
**Referenced globals:** iRam007012a0; +0x17f (style); +0xdf6/+0xdf8 (field metrics); +0xea80 (field record array); +0xfac0 (field count)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x17f; +0x186; +0xe96b

## Behavioral explanation
Draws an input/select field by border style (+0x17f 0..2) via FUN_005d9790/96a0, and records the field's position+text into the hit-test/entry array at +0xea80 (indexed by +0xfac0).

## Notes / uncertainty
Draws <input> by style(+0x17f 0/1/2) via FUN_005d9790/96a0; style 0 with id registers 0x104-byte hit-record into +0xea80 array, bumps field_count +0xfac0. Buffer roles af6/8f6/9f6/bf6/cf6 inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ee220.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
