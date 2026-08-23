# 0x005ea090 markup_inline_style_clear

| field | value |
|---|---|
| Original address | 0x005ea090 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ea090 |
| Resolved name | markup_inline_style_clear |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ef040
**Referenced globals:** +0xd892; +0xd894; +0x18b; +0x2530; +0x18c
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xd892; +0x18b; +0x18c

## Behavioral explanation
Inline-style OFF handler: clears bit0 of style byte (+0x18b or per-cell +0x2530) and clears dirty flag +0x18c after a layout flush.

## Notes / uncertainty
Inline style OFF, inverse of 0x9ff0: single flush, clear bit0 of +0x18b/per-cell +0x2530, +0x18c=0.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ea090.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
