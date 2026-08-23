# 0x005dfb00 base64_encode

| field | value |
|---|---|
| Original address | 0x005dfb00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dfb00 |
| Resolved name | base64_encode |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d5cc0
**Callees:** —
**Referenced globals:** s_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef_006465e0 (b64 alphabet)
**Referenced strings:** ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Base64-encodes input bytes (3->4 with '=' padding) using the standard alphabet, bounded by an output length limit.

## Notes / uncertainty
Standard RFC4648 base64 w/ '=' padding, 3->4, bit offsets 18/12/6/0, output-capacity-bounded (param_4), may truncate mid-quad. Output NOT NUL-terminated. Alphabet@0x6465e0.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dfb00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
