# 0x005c0d30 roster_get_entry_6cdbe6

| field | value |
|---|---|
| Original address | 0x005c0d30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c0d30 |
| Resolved name | roster_get_entry_6cdbe6 |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fa190, FUN_00600de0, FUN_0062f1e0
**Callees:** —
**Referenced globals:** 0x6cdbe6 roster table (name/name2/data)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Accessor: copies roster entry param_1 (0x118 stride) three fields (name +0x6cdbe6, name2 +0x6cdbf6, 0xf0-byte data +0x6cdc0a) into three out-buffers.

## Notes / uncertainty
Roster table #1 accessor: strcpy name(+0x00)/name2(+0x10) + memcpy data[0xf0](+0x24), stride 0x118. 0xf0 = member charstats size.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c0d30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
