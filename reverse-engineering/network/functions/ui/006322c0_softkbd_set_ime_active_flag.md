# 0x006322c0 softkbd_set_ime_active_flag

| field | value |
|---|---|
| Original address | 0x006322c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006322c0 |
| Resolved name | softkbd_set_ime_active_flag |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006313a0, FUN_00631560, FUN_00631670, FUN_00634890, FUN_00635bb0, FUN_00635f80, FUN_00636f90, FUN_006375d0
**Callees:** FUN_00632290
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x36 IME-active; +0x1d field mode; +0x1e layout page

## Behavioral explanation
Sets the IME-active flag (+0x36) to 5 when in IME mode and on a kana layout page (+0x1e == 3 or 0x0b), else 0.

## Notes / uncertainty
Sets +0x36=5 when is_ime_mode and layout page +0x1e in {3,0x0b}, else 0. Value 5 treated as opaque active sentinel.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006322c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
