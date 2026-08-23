# 0x005dfff0 displaylist_layer_dispatch_render

| field | value |
|---|---|
| Original address | 0x005dfff0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dfff0 |
| Resolved name | displaylist_layer_dispatch_render |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** —
**Referenced globals:** iRam00701068+0x5ff70 (layer list heads)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Walks a layer draw-queue and calls each active node's second callback (node+0x18) when node+1 flag set.

## Notes / uncertainty
Exact mirror of dispatch_update using render flag@+1 and callback@+0x18. Code unambiguous but NO callers in slice (dead here or dispatched out-of-slice) -> held Medium.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dfff0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
