# 0x005bc370 roster_pack_visible_list

| field | value |
|---|---|
| Original address | 0x005bc370 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bc370 |
| Resolved name | roster_pack_visible_list |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bb670, FUN_005bc430
**Callees:** —
**Referenced globals:** 0x6cdbe6 (source roster, stride 0x118); 0x6ce046 (packed visible roster, stride 0x118)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Compacts the 4-entry source roster (0x6cdbe6, stride 0x118) into the packed/visible roster array (0x6ce046, stride 0x118), including only entries whose active flag (+0x101) == 1; returns the visible count.

## Notes / uncertainty
Compacts 0x6cdbe6->0x6ce046 (stride 0x118) keeping active-flag +0x101==1; returns kept count (stored into 0x6fb746). Return type inferred from caller use.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bc370.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
