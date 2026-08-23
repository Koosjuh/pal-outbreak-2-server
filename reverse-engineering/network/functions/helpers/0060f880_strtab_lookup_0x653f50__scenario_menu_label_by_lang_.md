# 0x0060f880 strtab_lookup_0x653f50 (scenario/menu label by lang)

| field | value |
|---|---|
| Original address | 0x0060f880 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060f880 |
| Resolved name | strtab_lookup_0x653f50 (scenario/menu label by lang) |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006134b0, FUN_006140d0
**Callees:** —
**Referenced globals:** 0x653f50 (per-lang string table); bRam0034359d (language)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** bRam0034359d language

## Behavioral explanation
Returns *(*(0x653f50 + lang*4) + idx*4): a 32-bit entry (string ptr) from the language-indexed table at 0x653f50.

## Notes / uncertainty
Fixed-base (0x653f50) form of 0x0060f830: g_labelTable[lang][idx] scenario/menu label pointer. Used by scenario_list_render with cursor+row.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060f880.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
