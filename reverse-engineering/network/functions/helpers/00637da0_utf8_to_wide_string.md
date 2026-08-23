# 0x00637da0 utf8_to_wide_string

| field | value |
|---|---|
| Original address | 0x00637da0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637da0 |
| Resolved name | utf8_to_wide_string |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00630c90, FUN_006345e0, FUN_00634ab0, FUN_00635ab0, FUN_006378b0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Decodes a UTF-8 char* into an array of shorts (wide chars) via func_0x001af320, null-terminated.

## Notes / uncertainty
UTF-8 char* -> short[] via func_0x001af320 decode; breaks on negative (invalid). No dst bounds check. Decoder callee not opened.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00637da0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
