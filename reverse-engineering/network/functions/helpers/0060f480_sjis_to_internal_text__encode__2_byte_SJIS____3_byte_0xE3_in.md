# 0x0060f480 sjis_to_internal_text (encode: 2-byte SJIS -> 3-byte 0xE3 internal)

| field | value |
|---|---|
| Original address | 0x0060f480 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060f480 |
| Resolved name | sjis_to_internal_text (encode: 2-byte SJIS -> 3-byte 0xE3 internal) |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060e250
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Inverse of FUN_0060f350: expands internal 16-bit codes back to 3-byte 0xE3-prefixed Shift-JIS sequences with length caps (0xFE/0xFC), ASCII passthrough.

## Notes / uncertainty
DIRECTION MISMATCH: filename says internal_to_sjis but flow is ENCODE. 0xE3 tag byte; length caps 0xFE/0xFC for ~255-byte name field. Inverse of 0x0060f350 verified. File un-renamed; flagged.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060f480.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
