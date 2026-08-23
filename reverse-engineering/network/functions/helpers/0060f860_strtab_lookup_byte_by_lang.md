# 0x0060f860 strtab_lookup_byte_by_lang

| field | value |
|---|---|
| Original address | 0x0060f860 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060f860 |
| Resolved name | strtab_lookup_byte_by_lang |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00612fd0, FUN_00613da0, FUN_00613e70, FUN_00613fb0, FUN_00614600
**Callees:** —
**Referenced globals:** bRam0034359d (language index)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** bRam0034359d language

## Behavioral explanation
Localized table accessor: returns byte *(*(base + lang*4) + idx) — per-language count/flag byte.

## Notes / uncertainty
Byte variant of 0x0060f830 (inner index NOT *4). Returns per-lang count/flag byte; confirmed as loop-bound (count) in FUN_00612fd0 with base 0x653fd0.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060f860.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
