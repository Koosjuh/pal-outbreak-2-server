# 0x005c2740 roster2_get_entry_6ce046

| field | value |
|---|---|
| Original address | 0x005c2740 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c2740 |
| Resolved name | roster2_get_entry_6ce046 |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00601580
**Callees:** —
**Referenced globals:** 0x6ce046 active roster table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Accessor: copies active-roster entry param_1 (0x118 stride) three fields (name +0x6ce046, name2 +0x6ce056, 0xf0-byte data +0x6ce06a) into three out-buffers.

## Notes / uncertainty
Identical to 005c0d30 over roster table #2 (base 0x6ce046, active view); count = 0x6fb746.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c2740.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
