# 0x005e9ff0 markup_inline_style_set

| field | value |
|---|---|
| Original address | 0x005e9ff0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9ff0 |
| Resolved name | markup_inline_style_set |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ef040
**Referenced globals:** +0xd892 (table-mode flag); +0xd894 (current cell index); +0x18b (style byte); +0x2530 (per-cell style); +0x18c (dirty)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xd892; +0x18b; +0x18c

## Behavioral explanation
Inline-style ON handler: sets bit0 of style byte (+0x18b global or per-cell +0x2530 when in table mode +0xd892) and dirty flag +0x18c; brackets a layout flush.

## Notes / uncertainty
Inline style ON: pre/post flush (FUN_005ef040), set bit0 of +0x18b (or per-cell +0x2530 stride cell*0x5c in table mode +0xd892), +0x18c=1. Which visual attr bit0 = unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9ff0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
