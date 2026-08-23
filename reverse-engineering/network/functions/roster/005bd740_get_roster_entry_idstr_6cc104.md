# 0x005bd740 get_roster_entry_idstr_6cc104

| field | value |
|---|---|
| Original address | 0x005bd740 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bd740 |
| Resolved name | get_roster_entry_idstr_6cc104 |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b3070
**Callees:** —
**Referenced globals:** 0x6cc104 (roster field A, stride 0x114)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Accessor: copies roster entry [param&0xff]'s field at 0x6cc104 (stride 0x114) into the caller's buffer via strcpy-like func_0x00109eb8.

## Notes / uncertainty
strcpy of idstr field (+0x00) from 0x114-stride roster-entry table 0x6cc104 (the table op06 ADD fills). 8-bit index. Table-identity vs drawn 0x3b0 table not runtime-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bd740.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
