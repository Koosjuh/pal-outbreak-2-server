# 0x005d6680 list_node_unlink_clear

| field | value |
|---|---|
| Original address | 0x005d6680 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d6680 |
| Resolved name | list_node_unlink_clear |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d6710
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** node+0x41

## Behavioral explanation
Generic helper: unlinks a target node from a singly-linked list and zeroes its payload/flags.

## Notes / uncertainty
Free = recycle node to tail (if it has a successor) + zero key/alloc/meta. Byte-identical to pool_free_node 0x6b80.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d6680.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
