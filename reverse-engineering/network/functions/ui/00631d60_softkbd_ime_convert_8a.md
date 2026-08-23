# 0x00631d60 softkbd_ime_convert_8a

| field | value |
|---|---|
| Original address | 0x00631d60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00631d60 |
| Resolved name | softkbd_ime_convert_8a |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_006300a0
**Callees:** FUN_00630c50, FUN_00631e40, FUN_00632290, FUN_00633390, FUN_006333b0, FUN_00633470, FUN_00633840, FUN_00633930, FUN_00633ab0
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x2f IME state; +0x36 IME-active; +0x260 IME buffer; +0x258 (600) conversion result; +0x248 result code

## Behavioral explanation
IME conversion key (0x8a): drives kana/kanji conversion of the composition buffer (+0x260) across IME states, or confirms/aborts.

## Notes / uncertainty
JP kana->kanji conversion driver; dispatches on is_ime_field/+0x36/+0x2f. Internal roles of FUN_006333b0/00633390/00633840 inferred, not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00631d60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
