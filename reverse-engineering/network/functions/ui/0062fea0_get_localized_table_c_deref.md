# 0x0062fea0 get_localized_table_c_deref

| field | value |
|---|---|
| Original address | 0x0062fea0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062fea0 |
| Resolved name | get_localized_table_c_deref |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ae630, FUN_005ae9b0, FUN_005affb0, FUN_005b08f0, FUN_005b20c0, FUN_005b2bc0, FUN_005b3590, FUN_005b4da0, FUN_005b9150, FUN_005ba5b0, FUN_005f6d20, FUN_005f70b0, FUN_005f85e0, FUN_005fcc70, FUN_005fd9e0, FUN_00601ac0, FUN_00601c00, FUN_00601d50, FUN_00602340, FUN_00602700, FUN_00604e70, FUN_00605a90, FUN_006076c0, FUN_006080d0, FUN_00617c30, FUN_00628860, FUN_00628cc0, FUN_00629d60, FUN_0062b2c0, FUN_0062b8b0, FUN_0062f5b0
**Callees:** —
**Referenced globals:** DAT_0068ad40 (lang ptr-table array); bRam0034359d (language index)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** bRam0034359d

## Behavioral explanation
Double-deref accessor into per-language pointer table DAT_0068ad40 (returns *table[param_1]).

## Notes / uncertainty
Triple-indirection getter *(tableC[lang][index]); base 0x68ad40. 31 callers = generic localized-resource helper. Pointed-to entry layout unknown; no bounds.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062fea0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
