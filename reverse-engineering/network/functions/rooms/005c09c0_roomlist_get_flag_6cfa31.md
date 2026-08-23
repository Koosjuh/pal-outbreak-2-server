# 0x005c09c0 roomlist_get_flag_6cfa31

| field | value |
|---|---|
| Original address | 0x005c09c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c09c0 |
| Resolved name | roomlist_get_flag_6cfa31 |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b5930, FUN_005fc0c0, FUN_0062e9b0, FUN_0062edc0
**Callees:** —
**Referenced globals:** 0x6cfa31 room-list-table u8 flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Accessor: reads the u8 flag at +0x6cfa31 of room-list entry param_1 into caller pointer.

## Notes / uncertainty
Reads u8 rec+0x31 (row status/lock byte, just before name+0x32). Bit semantics undecoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c09c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
