# 0x005f0190 ui_node_size_from_grid

| field | value |
|---|---|
| Original address | 0x005f0190 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f0190 |
| Resolved name | ui_node_size_from_grid |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005eb7d0
**Callees:** —
**Referenced globals:** +0x186 build mode; +0xf10/+0xf12/+0xf14/+0xf15 child-attr; node+0x1c/+0x1e size, +0x30/+0x32 pad/margin, +0x46/+0x47/+0x48 grid
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186

## Behavioral explanation
Computes a node's width/height (+0x1c/+0x1e) from grid attrs (rows +0x48, cols +0x47) and child-attr block +0xf10/+0xf12; distributes available space per cell.

## Notes / uncertainty
Grid sizing: per-row height = (availH - (rows-1)*gutter)/rows clamped to 0; col min-width; non-build stretch-to-parent. pad/margin roles inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f0190.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
