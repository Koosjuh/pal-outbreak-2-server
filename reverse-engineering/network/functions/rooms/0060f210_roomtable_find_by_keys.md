# 0x0060f210 roomtable_find_by_keys

| field | value |
|---|---|
| Original address | 0x0060f210 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060f210 |
| Resolved name | roomtable_find_by_keys |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060e710
**Callees:** —
**Referenced globals:** 0x35c000 (room registry table, 0x1c*0x23); +0x14/+0x18 (room key strings)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x35c000 room table

## Behavioral explanation
Linear-searches the global room table 0x35c000 (0x1c stride, 0..0x22) for a live entry (+0=!-1) whose +0x14 and +0x18 key strings both strcmp-match (param_1,param_2); returns index or -1.

## Notes / uncertainty
Verified line-for-line against raw: 0x22-bounded scan of registry 0x35c000 stride 0x1c, live!=-1 && strcmp(+0x14,k1)==0 && strcmp(+0x18,k2)==0 -> index else -1. key1/key2 identity (name+host vs group+name) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060f210.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
