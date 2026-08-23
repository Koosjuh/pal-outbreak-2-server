# 0x001ead70 attr_table_bytesize

| field | value |
|---|---|
| Original address | 0x001ead70 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ead70 |
| Resolved name | attr_table_bytesize |
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
Returns the serialized byte size of an attribute table: count*6 + 2 (header).

## Notes / uncertainty
Returns count*6+2; canonical confirmation of TLV layout. Signed count unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ead70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
