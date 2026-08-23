# 0x0060f350 internal_to_sjis_text (decode: 3-byte internal -> 2-byte SJIS)

| field | value |
|---|---|
| Original address | 0x0060f350 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060f350 |
| Resolved name | internal_to_sjis_text (decode: 3-byte internal -> 2-byte SJIS) |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060e440
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Text transcoder: copies ASCII (<0x80) verbatim; maps 2-byte Shift-JIS lead (0x81xx-0x83xx ranges) to an internal 16-bit code via range-offset table, terminates NUL.

## Notes / uncertainty
DIRECTION MISMATCH: record filename says sjis_to_internal but byte flow (3-byte 0xE3 group in, 2-byte SJIS out) is DECODE. Exact inverse of 0x0060f480 (verified range-by-range). Fallback 0x815b. File left un-renamed; flagged in title/resolved_name.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060f350.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
