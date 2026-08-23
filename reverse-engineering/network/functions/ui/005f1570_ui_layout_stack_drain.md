# 0x005f1570 ui_layout_stack_drain

| field | value |
|---|---|
| Original address | 0x005f1570 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f1570 |
| Resolved name | ui_layout_stack_drain |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e7a30
**Callees:** FUN_005eacd0, FUN_005eb3f0, FUN_005ebd20
**Referenced globals:** +0xd892 stack depth; +0xd894 current node; +0xd89a stack array; +0x24fb node subtype
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xd892; +0x24fb

## Behavioral explanation
Top-level layout/render loop: pops the node-index stack (+0xd892) and dispatches each node by subtype +0x24fb to open(1)/row(2)/cell(3,4) handlers until the stack empties.

## Notes / uncertainty
Terminal balanced-tree flush: pops node stack and finishes each open container/row/cell by subtype until depth 0. Clean; no runtime trace.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f1570.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
