# 0x001d1b80 apply_object_attributes

| field | value |
|---|---|
| Original address | 0x001d1b80 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d1b80 |
| Resolved name | apply_object_attributes |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d1960
**Callees:** FUN_001a7b70
**Referenced globals:** 0x24cf68/0x24cf70/0x24cf80/0x24cfd0.. attribute LUTs
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Maps parsed object fields through 0x24cfxx lookup tables and writes flags/type into a 0x90-stride entity struct.

## Notes / uncertainty
Maps attr record through 0x24cfxx LUTs into 9 render props (0x15/2/0x12/1/0x66/0x62/0xc/0/0x5d) and entity bytes +0x89..0x90; blend==2 and motion 0/5/6 branches. Prop-id GPU meaning undecoded. Not network.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d1b80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
