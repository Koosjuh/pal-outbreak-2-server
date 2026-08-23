# 0x005e5f80 parse_token_normalize_lookup

| field | value |
|---|---|
| Original address | 0x005e5f80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e5f80 |
| Resolved name | parse_token_normalize_lookup |
| Subsystem | lobby |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e7070
**Callees:** —
**Referenced globals:** DAT_00648090 (byte charmap/case table)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Normalizes a token at the parse cursor (via charmap DAT_00648090) and matches it against a keyword/value table (param_2, entries of stride 8), returning the associated code byte at entry+5.

## Notes / uncertainty
Renamed from parse_token_lookup_code: normalizes token (<=30 chars, charmap DAT_00648090, SJIS-safe, stops at 0x3e '>') then matches 8-byte-stride keyword table, returns code@+5 or 0. Entry fields +5/6/7 not fully characterized.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e5f80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
