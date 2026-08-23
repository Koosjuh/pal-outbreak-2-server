# 0x001d3b40 load_item_definition_table

| field | value |
|---|---|
| Original address | 0x001d3b40 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d3b40 |
| Resolved name | load_item_definition_table |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109728, FUN_001840d0, FUN_001a0df0, FUN_001cb360
**Referenced globals:** 0x343577 disc flag; 0x3cbe90 item def table (stride 0x78); 0x3435bc scratch; 0x24d480/0x24d490/0x24d4a8 path fmts
**Referenced strings:** (path fmts @0x24d480/90/a8)
**Referenced opcodes:** —
**State vars:** cRam00343577

## Behavioral explanation
Loads a packed file and unpacks up to 0x40 item/weapon definition records (0x78-stride) into the 0x3cbe90 table.

## Notes / uncertainty
Two-level group/entry unpack into 0x3cbe90 records (stride 0x78, cap 0x40). type +0x04 (0x37/0x2f keep subtype), flag bit 0x10, category src[9] {0,1,2} selects extended layout. Offsets exact; item/weapon domain + field widths inferred. Non-network.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d3b40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
