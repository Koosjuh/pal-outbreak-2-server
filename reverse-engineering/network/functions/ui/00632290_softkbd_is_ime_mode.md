# 0x00632290 softkbd_is_ime_mode

| field | value |
|---|---|
| Original address | 0x00632290 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00632290 |
| Resolved name | softkbd_is_ime_mode |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00630910, FUN_00631d60, FUN_006322c0, FUN_00633470, FUN_006379e0
**Callees:** —
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x1d field mode

## Behavioral explanation
Predicate: returns 1 if the field mode (+0x1d) is in the IME-capable range 8..0x0a.

## Notes / uncertainty
Pure predicate: field mode +0x1d in [8,0x0b) -> IME-capable. Unambiguous.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00632290.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
