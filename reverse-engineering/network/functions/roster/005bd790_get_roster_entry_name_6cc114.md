# 0x005bd790 get_roster_entry_name_6cc114

| field | value |
|---|---|
| Original address | 0x005bd790 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bd790 |
| Resolved name | get_roster_entry_name_6cc114 |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b3070
**Callees:** —
**Referenced globals:** 0x6cc114 (roster field B, stride 0x114)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Accessor: copies roster entry [param&0xff]'s field at 0x6cc114 (stride 0x114) into the caller's buffer.

## Notes / uncertainty
strcpy of name field (+0x10) from same 0x6cc104 roster-entry table. Matches op06 scratch name field.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bd790.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
