# 0x00637d10 utf8_encode_codepoint

| field | value |
|---|---|
| Original address | 0x00637d10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00637d10 |
| Resolved name | utf8_encode_codepoint |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00630750, FUN_006320f0, FUN_00632c00, FUN_00633fa0, FUN_00634010, FUN_006340d0, FUN_00634160, FUN_006341d0, FUN_00634280, FUN_00634310
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Encodes a code point (param_1) into 1/2/3-byte UTF-8 at param_2, null-terminates, returns byte length.

## Notes / uncertainty
Textbook BMP UTF-8 encoder (1/2/3 bytes + NUL), returns length. No 4-byte path.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00637d10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
