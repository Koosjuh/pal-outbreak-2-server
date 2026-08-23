# 0x005bf940 get_registry_entry_short_0x6ce49a

| field | value |
|---|---|
| Original address | 0x005bf940 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bf940 |
| Resolved name | get_registry_entry_short_0x6ce49a |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ad890, FUN_005b57a0
**Callees:** —
**Referenced globals:** 0x6ce49a registry-A render struct base (stride 0x144)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Reads 16-bit field at idx*0x144+0x6ce49a (registry-A render struct name/id area) into out-ptr.

## Notes / uncertainty
Reads +0x00 u16 head field of 0x144-stride registry table, 0-BASED index (contrast sibling bf3c0 1-based). Same table (0x6ce5f2=base+0x158). Read@0x6ce49a vs SM write@0x6ce49c may be a +2 sub-field split; not runtime-disambiguated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bf940.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
