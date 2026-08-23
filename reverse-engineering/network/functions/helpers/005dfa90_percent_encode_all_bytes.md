# 0x005dfa90 percent_encode_all_bytes

| field | value |
|---|---|
| Original address | 0x005dfa90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dfa90 |
| Resolved name | percent_encode_all_bytes |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d7540
**Callees:** —
**Referenced globals:** s_0123456789ABCDEF_006465c0
**Referenced strings:** 0123456789ABCDEF
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Percent-encodes every input byte as '%XX' hex into the output buffer, returning the encoded length.

## Notes / uncertainty
Unconditionally percent-encodes EVERY byte as %XX (uppercase LUT s_..._006465c0); NUL-terminates; returns 3*len. Caller must pre-filter which chars to escape.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dfa90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
