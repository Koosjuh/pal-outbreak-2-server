# 0x005f00b0 ui_node_inherit_attrs

| field | value |
|---|---|
| Original address | 0x005f00b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f00b0 |
| Resolved name | ui_node_inherit_attrs |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005eb7d0, FUN_005f0930, FUN_005f0a10
**Callees:** —
**Referenced globals:** +0x186 build mode; +0x18a flag src; +0xf10/+0xf16/+0xf17/+0xf18 pending; node+0x44-+0x54 style, +0x4c child count
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186; +0x18a; +0xf16; +0xf17

## Behavioral explanation
In build mode copies parent style/align into child, ORs flag bits (+0x50 |= +0x18a), applies pending align overrides, and bumps parent child-count (+0x4c).

## Notes / uncertainty
Build-pass attr inheritance with align-override precedence (ctx+0xf16/f17) and +0x50 flag OR; always bumps parent child-count +0x4c. +0x4c aliases key(child)/count(parent).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f00b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
