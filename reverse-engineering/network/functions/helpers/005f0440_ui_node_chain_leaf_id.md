# 0x005f0440 ui_node_chain_leaf_id

| field | value |
|---|---|
| Original address | 0x005f0440 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f0440 |
| Resolved name | ui_node_chain_leaf_id |
| Subsystem | helpers |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f0480
**Callees:** —
**Referenced globals:** +0x24e0 node pool; node+0x36 next-link; node+0x18 id
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Walks a node's continuation chain via +0x36 to the tail node and returns its id byte at +0x18.

## Notes / uncertainty
Walks +0x36 chain (idx 0 = end) to tail, returns +0x18 id. Confirms pool base 0x24e0 stride 0x5c.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f0440.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
