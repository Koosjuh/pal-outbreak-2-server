# 0x005eacd0 markup_cell_close_layout_commit

| field | value |
|---|---|
| Original address | 0x005eacd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eacd0 |
| Resolved name | markup_cell_close_layout_commit |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005f0e10, FUN_005f10a0, FUN_005f1570
**Callees:** FUN_005ec170, FUN_005ed160, FUN_005f10a0, FUN_005f1da0, FUN_005f21f0
**Referenced globals:** +0xd892 (table depth); +0xd894 (cell idx); +0x186 (mode); +0x24e0.. (cell struct); +0x1540 (grid cell coords); +0x182 (max width); +0xd8be/+0xd8c2 (running height); +0x18b/+0x18c (style/dirty)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xd892; +0xd894; +0x186

## Behavioral explanation
Type-1 element close (table mode only): closes via FUN_005f10a0, recomputes cell width/height metrics (+0x24fc/+0x24fe), positions the cell into the parent grid (+0x1540 / +0x182), updates running layout cursors and, on last cell, commits geometry (FUN_005ec170/005ed160/005f21f0).

## Notes / uncertainty
Table-cell close finalizer; depth<2 commits to doc flow (grid +0x1540, doc height +0xd8c2), depth>=2 rolls into parent obj. Parent-node field labels + region snapshot inferred; exact control flow transcribed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eacd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
