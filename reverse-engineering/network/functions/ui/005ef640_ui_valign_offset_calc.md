# 0x005ef640 ui_valign_offset_calc

| field | value |
|---|---|
| Original address | 0x005ef640 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ef640 |
| Resolved name | ui_valign_offset_calc |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005eb7d0, FUN_005f0340
**Callees:** —
**Referenced globals:** +0xd8d4 v-layout cursor; node+0x3c v-offset; node+0x4b valign code; node+0x50 flags
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xd8d4

## Behavioral explanation
Computes a node's vertical placement delta (node+0x3c) from valign code at +0x4b (2=top/0, 3=bottom, else centered) using the layout-cursor 0xd8d4.

## Notes / uncertainty
Vertical placement offset node+0x3c from valign code +0x4b (2=top,3=bottom,else center) vs extent +0xd8d4; ref height +0x1e/+0x40 selected by +0x48; +0x50&1 forces 0. Mirror of ui_halign. ref-select semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ef640.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
