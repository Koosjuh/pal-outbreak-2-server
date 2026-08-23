# 0x005f3420 text_measure_wordwrap

| field | value |
|---|---|
| Original address | 0x005f3420 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f3420 |
| Resolved name | text_measure_wordwrap |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f3ac0, FUN_005f3bc0, FUN_005f3cc0
**Callees:** FUN_005ee920, FUN_005ee9a0, FUN_005ee9f0, FUN_005f23c0, FUN_005f3310
**Referenced globals:** iRam007012a0(text ctx: 0x181 advance, 0x16 x-accum, 0x180, 0xd8ce/0xd8d2, 0x2500/0x2502 max-width)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam007012a0+0x186 (mode: -10 measure vs normal)

## Behavioral explanation
Core word-wrap/measure loop over a SJIS string: accumulates glyph widths, handles space/tab/0x80-lead/ctrl-7, triggers line breaks.

## Notes / uncertainty
Core measure/wrap loop over SJIS string; mode 0x186 (0xf6 measure-only vs place vs emit); overflow>rightMargin triggers wrap_break; 3 glyph emitters by class (ctrl-7/single/0x80-lead). Byte 7 = text control code NOT opcode 0x07. Emitter roles inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f3420.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
