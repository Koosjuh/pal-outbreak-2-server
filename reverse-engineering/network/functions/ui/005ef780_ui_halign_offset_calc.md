# 0x005ef780 ui_halign_offset_calc

| field | value |
|---|---|
| Original address | 0x005ef780 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ef780 |
| Resolved name | ui_halign_offset_calc |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e8750, FUN_005e8c10, FUN_005ea190, FUN_005eb7d0, FUN_005ebd20, FUN_005ecf20, FUN_005f0340, FUN_005f2450, FUN_005f3150, FUN_005f3230, FUN_005f3310, FUN_005f39d0, FUN_005f3bc0, FUN_005f3cc0
**Callees:** —
**Referenced globals:** +0x186 render-pass; +0x188 root idx; +0x1540 root array; +0xd8dc content width; node+0x3a h-offset; node+0x4a halign code
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186; +0xd8dc

## Behavioral explanation
Computes a node's horizontal placement delta (node+0x3a) from halign at +0x4a against available width, in draw mode only.

## Notes / uncertainty
Horizontal offset node+0x3a from halign +0x4a (2/center,3/right,else left) vs span (+0xd8dc - +0x3e); center also forced by +0x51!=0 or +0x1b==3; draw-pass only (+0x186==0); +0x50&1 forces 0. width source (root-array cell) semantics uncertain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ef780.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
