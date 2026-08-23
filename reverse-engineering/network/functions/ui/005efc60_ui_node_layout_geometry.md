# 0x005efc60 ui_node_layout_geometry

| field | value |
|---|---|
| Original address | 0x005efc60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005efc60 |
| Resolved name | ui_node_layout_geometry |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005ea900
**Callees:** —
**Referenced globals:** +0x186 render-pass; +0x10/+0x12 viewport; +0xd8bc/+0xd8be/+0xd8d4 layout cursors; +0xe08/+0xe0c color; node+0x28/+0x2a pos, +0x1c/+0x1e size, +0x38-+0x4b align
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186; +0xd8d4

## Behavioral explanation
Computes a node's absolute x/y (node+0x28/+0x2a) from parent geometry and align codes across build/measure/draw passes; the core box-placement routine.

## Notes / uncertainty
Core box placement: root(ctx+0xd892==1) vs child mode; align codes 3=end/2=center, round-toward-zero halving. Vertical-align extent fields (+0x38/+0x40/+0x48) inferred from arithmetic.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005efc60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
