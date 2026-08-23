# 0x0061c940 localized_ptr_lookup

| field | value |
|---|---|
| Original address | 0x0061c940 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061c940 |
| Resolved name | localized_ptr_lookup |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0061ea50
**Callees:** —
**Referenced globals:** 0x669b10 per-language table base; bRam0034359d language index
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** bRam0034359d language

## Behavioral explanation
Returns a language-indexed pointer/value: dereferences DAT_00669b10[lang] then indexes by param*4.

## Notes / uncertainty
Two-level table accessor: g_lang_tables[bRam0034359d][index] at 0x669b10. No bounds check. Entry type (str ptr vs value) unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061c940.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
