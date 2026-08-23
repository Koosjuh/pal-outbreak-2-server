# 0x001eac0c attr_table_set

| field | value |
|---|---|
| Original address | 0x001eac0c |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eac0c |
| Resolved name | attr_table_set |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d6ee0, FUN_001db7e8
**Callees:** FUN_001069a8
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Inserts or updates a {u16 key -> u32 value} entry in the serialized attribute table, appending (and bumping the count) when the key is not already present.

## Notes / uncertainty
Upsert into TLV table; append bumps count. No capacity/overflow guard (caller contract).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eac0c.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
