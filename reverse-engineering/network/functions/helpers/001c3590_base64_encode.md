# 0x001c3590 base64_encode

| field | value |
|---|---|
| Original address | 0x001c3590 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c3590 |
| Resolved name | base64_encode |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c8f50
**Callees:** —
**Referenced globals:** —
**Referenced strings:** ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef... (base64 alphabet)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Standard base64 encoder using the ABCDEF...abcdef/0-9+/ alphabet with '=' padding.

## Notes / uncertainty
RFC4648 base64 encoder, 3-byte->4-char, '=' padding, alphabet @0x2487e0, out_cap-bounded (can stop mid-quad). Codec exact.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c3590.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
