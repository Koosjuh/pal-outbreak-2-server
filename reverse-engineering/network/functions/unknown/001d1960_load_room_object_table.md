# 0x001d1960 load_room_object_table

| field | value |
|---|---|
| Original address | 0x001d1960 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d1960 |
| Resolved name | load_room_object_table |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001cce80, FUN_001ce090, FUN_001ce2d0
**Callees:** FUN_001801b0, FUN_00184120, FUN_00184140, FUN_00199d50, FUN_00199df0, FUN_00199f10, FUN_0019a210, FUN_0019a260, FUN_0019aaf0, FUN_001a7b70, FUN_001a99c0, FUN_001d1b80
**Referenced globals:** 0x52d620 char table; struct+0x808 object array; 0x24cb70 param table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Loads 0x98-stride object records into struct+0x808 buffer, wiring them to the 0x52d620 stat table.

## Notes / uncertainty
Loads 0x98-stride scene objects into *(ctx+0x808); binds children to entity props 0x3a+j from 0x52d620; three-way spawn branch. Not network.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d1960.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
