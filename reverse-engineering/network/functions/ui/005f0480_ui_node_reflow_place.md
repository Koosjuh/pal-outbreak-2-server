# 0x005f0480 ui_node_reflow_place

| field | value |
|---|---|
| Original address | 0x005f0480 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f0480 |
| Resolved name | ui_node_reflow_place |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005f0930, FUN_005f0a10
**Callees:** FUN_005f0440
**Referenced globals:** +0x186 render-pass; +0xd892 depth; +0xd898 spare idx; +0x250a cell array; node+0x1c/+0x1e/+0x28-+0x49 geometry
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186; +0xd892; +0xd898

## Behavioral explanation
Reflows/places a spanned cell node across build/measure/draw passes: propagates width, computes running x, advances parent flow cursors (+0x2c/+0x20), pops node depth.

## Notes / uncertainty
3-pass cell placement + parent flow advance; build links span chain, measure closes column height, draw reconciles; decrements depth ctx+0xd892 (0->return -1). Column-extent array records (+0x24fc/+0x2510/+0x2512) structurally inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f0480.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
