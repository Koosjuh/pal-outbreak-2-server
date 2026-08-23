# 0x005c1c10 get_global_6cbcca

| field | value |
|---|---|
| Original address | 0x005c1c10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c1c10 |
| Resolved name | get_global_6cbcca |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fc0c0, FUN_0062e9b0, FUN_0062edc0
**Callees:** —
**Referenced globals:** 0x6cbcca (u16, cleared by enter/roomlist pumps)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6cbcca

## Behavioral explanation
Accessor: returns u16 global 0x6cbcca into caller pointer.

## Notes / uncertainty
Pure getter of u16 0x6cbcca (room-screen counter/state in the 0x6cbc.. UI-status block). Exact meaning count-vs-flag unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c1c10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
