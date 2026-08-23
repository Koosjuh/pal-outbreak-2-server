# 0x005c7ff0 lookup_localized_string

| field | value |
|---|---|
| Original address | 0x005c7ff0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c7ff0 |
| Resolved name | lookup_localized_string |
| Subsystem | errors |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c5780, FUN_005c7e30, FUN_005c7f20
**Callees:** —
**Referenced globals:** 0x642bb0 (per-language string-table array); 0x34359d (language select)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x34359d (language)

## Behavioral explanation
Language-indexed string lookup: selects a string-pointer table by language (0x34359d) then indexes it by (code & 0xff).

## Notes / uncertainty
Language-indexed lookup: 5 per-lang tables at PTR_00642bb0 selected by byte 0x34359d(1..5, slot0 default), returns table[code&0xff]. No upper bound. Language ordering unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c7ff0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
