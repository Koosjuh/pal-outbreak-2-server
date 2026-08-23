# 0x005dfde0 displaylist_element_insert

| field | value |
|---|---|
| Original address | 0x005dfde0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dfde0 |
| Resolved name | displaylist_element_insert |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c9130, FUN_005da8e0, FUN_005dae40, FUN_005db130, FUN_005db6d0, FUN_005dbb10, FUN_005dbf00, FUN_005dc3b0, FUN_005dca70, FUN_005dd3b0
**Callees:** FUN_005dfd50
**Referenced globals:** iRam00701068+0x5ff70 (layer list heads); iRam00701068+0x5ff94 (layer list tails)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocates a display-list node and links it into one of the per-layer doubly-linked draw queues (heads @+0x5ff70, tails @+0x5ff94), by layer index and head/tail flag.

## Notes / uncertainty
Pops node, sets layer@+3, splices into per-layer DLL (heads@+0x5ff70/tails@+0x5ff94, prev+0x1c/next+0x20) head- or tail-insert per flag. Original arg wiring (layer/flag/payload) inferred from extraout_* artifacts; link algebra certain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dfde0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
