# 0x005c2370 get_active_member_count_6fb746

| field | value |
|---|---|
| Original address | 0x005c2370 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c2370 |
| Resolved name | get_active_member_count_6fb746 |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00601690
**Callees:** —
**Referenced globals:** 0x6fb746 active-member count
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Accessor: returns u16 active-member count 0x6fb746 into caller pointer.

## Notes / uncertainty
Singleton u16 active-roster count feeding table #2; 'active/filtered' vs total inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c2370.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
