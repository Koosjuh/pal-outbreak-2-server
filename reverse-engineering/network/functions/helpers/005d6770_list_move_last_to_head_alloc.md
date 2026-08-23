# 0x005d6770 list_move_last_to_head_alloc

| field | value |
|---|---|
| Original address | 0x005d6770 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d6770 |
| Resolved name | list_move_last_to_head_alloc |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d6920
**Callees:** FUN_005dedc0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** node+0x41

## Behavioral explanation
Generic helper: moves the last list node to the head, initializes it and marks it allocated.

## Notes / uncertainty
LRU alloc: recycle tail node to front, init, mark alloc=1. No empty-list guard (relies on caller invariant).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d6770.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
