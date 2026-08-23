# 0x005d6920 list_reorder_by_type

| field | value |
|---|---|
| Original address | 0x005d6920 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d6920 |
| Resolved name | list_reorder_by_type |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005d8340
**Callees:** FUN_005d6770, FUN_005d67d0, FUN_005d6810, FUN_005d68e0
**Referenced globals:** 0x701018 current node ptr
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** node+0x10c type

## Behavioral explanation
Reorders the current-node list (0x701018) using type byte +0x10c (0x04-0x06) via the rotate/find/move primitives and copies two payload bytes.

## Notes / uncertainty
Cursor scheduler dispatching on node type byte +0x10c: 0x06=copy meta in place, 0x05=advance-if-next-inuse, 0x04=step to predecessor, default=drain+recycle new front. Type value-space and meta(+0x108/+0x109) semantics not tied to a concrete opcode.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d6920.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
