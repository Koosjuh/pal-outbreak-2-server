# 0x005b86c0 widget_tick_labeled_item

| field | value |
|---|---|
| Original address | 0x005b86c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b86c0 |
| Resolved name | widget_tick_labeled_item |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_00618c20, FUN_0062fd90
**Referenced globals:** uRam006c45fe (member count); obj+2 (type); obj+3 (index)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fd3; uRam006c45fe

## Behavioral explanation
Per-frame widget update that draws a labeled/selectable item: resolves a per-type resource via FUN_0062fd90(type), highlights when its index matches the selection, and blits label+icon via FUN_005af1e0; type 0x08 gated on member count uRam006c45fe.

## Notes / uncertainty
Labeled/icon row; resolves FUN_0062fd90(type) descriptor (stride 0xc), draws label+icon. Type 0x08 rows past uRam006c45fe draw nothing. Descriptor-table contents opaque.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b86c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
