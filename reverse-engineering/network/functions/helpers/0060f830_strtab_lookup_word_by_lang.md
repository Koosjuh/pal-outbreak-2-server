# 0x0060f830 strtab_lookup_word_by_lang

| field | value |
|---|---|
| Original address | 0x0060f830 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060f830 |
| Resolved name | strtab_lookup_word_by_lang |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00612ca0, FUN_00612fd0, FUN_00613da0, FUN_00613e70, FUN_00613f40, FUN_00613fb0, FUN_00614600
**Callees:** —
**Referenced globals:** bRam0034359d (language index)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** bRam0034359d language

## Behavioral explanation
Localized table accessor: returns *(*(base + lang*4) + idx*4) — 32-bit entry from a per-language pointer table.

## Notes / uncertainty
Two-level localized accessor base[lang][idx] (32-bit word), base passed by caller (0x653f90/0x653fb0). No bounds check. Reads bRam0034359d.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060f830.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
