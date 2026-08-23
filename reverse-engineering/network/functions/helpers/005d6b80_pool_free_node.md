# 0x005d6b80 pool_free_node

| field | value |
|---|---|
| Original address | 0x005d6b80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d6b80 |
| Resolved name | pool_free_node |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d6c90, FUN_005d6ce0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** node+0x104 in-use flag; node+0x108

## Behavioral explanation
Unlinks a node from a pool free-list, zeroes its 0x100-byte key region, clears in-use flag [0x41] and the 2-byte field at +0x108.

## Notes / uncertainty
Pool free = recycle to tail + clear; byte-identical to list_node_unlink_clear 0x6680.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d6b80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
