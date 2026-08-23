# 0x005dfbc0 utf8_validate_copy_budgeted

| field | value |
|---|---|
| Original address | 0x005dfbc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dfbc0 |
| Resolved name | utf8_validate_copy_budgeted |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005cab10, FUN_005e2fa0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Copies a UTF-8 string while validating 1-4 byte sequences (continuation-byte range checks), truncating on malformed input.

## Notes / uncertainty
Budgeted UTF-8 validating copy: each glyph costs `step` from `avail`; validates 1/2/3-byte continuations (0x80-0xBF), aborts on malformed. No 4-byte handling (0xF0+ passed as lone byte). Always returns 0; truncation point is the signal. memset-less. Same file has halt_baddata thunk (separate).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dfbc0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
