# 0x005effc0 ui_node_clone_style_ordered

| field | value |
|---|---|
| Original address | 0x005effc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005effc0 |
| Resolved name | ui_node_clone_style_ordered |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005eb250
**Callees:** —
**Referenced globals:** +0x186 build mode; +0xf16/+0xf17/+0xf18 pending align/extra; node+0x44-+0x54 style fields
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186; +0xf16; +0xf17; +0xf18

## Behavioral explanation
In build mode copies style/align/order fields from a source node to a new node, assigns an incrementing order id (+0x4d), and computes indented width.

## Notes / uncertainty
Build-pass clone of style/align from template with fetch-and-add order id (+0x4d); indented width = src.w - 2*(border+pad). Style word +0x54 undecoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005effc0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
