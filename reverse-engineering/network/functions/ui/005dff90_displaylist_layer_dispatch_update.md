# 0x005dff90 displaylist_layer_dispatch_update

| field | value |
|---|---|
| Original address | 0x005dff90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dff90 |
| Resolved name | displaylist_layer_dispatch_update |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ca6a0, FUN_005cd500
**Callees:** —
**Referenced globals:** iRam00701068+0x5ff70 (layer list heads)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Walks a layer's draw-queue (head @+0x5ff70) and, for each active node (*node!=0), invokes its callback fn-ptr at node+0x14.

## Notes / uncertainty
Walks layer DLL (heads@+0x5ff70), saves next before calling each node's UPDATE callback@+0x14 when flag@+0 set (safe self-removal). Callback ABI (a0 vs global) not fully pinned.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dff90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
