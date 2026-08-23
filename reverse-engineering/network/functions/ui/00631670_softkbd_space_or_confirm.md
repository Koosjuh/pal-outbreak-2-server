# 0x00631670 softkbd_space_or_confirm

| field | value |
|---|---|
| Original address | 0x00631670 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00631670 |
| Resolved name | softkbd_space_or_confirm |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_006314a0, FUN_00635940, FUN_00636f90
**Callees:** FUN_00631ff0, FUN_006322c0, FUN_00637140, FUN_00637260, FUN_00637540, FUN_00637690
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x2f IME state; +0x10 field-descriptor ptr; +0x35 flags; +0x48 field; +0x248 result code

## Behavioral explanation
Space/confirm handler: when field descriptor allows, commits pending IME and refreshes grid, posting result code 1 (else 5).

## Notes / uncertainty
Space/confirm (0x3d): gated on field_desc(+0x10)->+0x28 whitespace cap; selects layout index 5 + finalize. Whether it inserts a space glyph vs switches to whitespace page (inside FUN_00637260) not resolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00631670.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
