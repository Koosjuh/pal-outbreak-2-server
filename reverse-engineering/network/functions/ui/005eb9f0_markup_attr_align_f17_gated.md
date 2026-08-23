# 0x005eb9f0 markup_attr_align_f17_gated

| field | value |
|---|---|
| Original address | 0x005eb9f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eb9f0 |
| Resolved name | markup_attr_keyword_enum_f17 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup attribute-handler dispatch table)
**Callees:** FUN_005ec1b0 (parse_quoted_attr_value), FUN_005ec920 (keyword→enum lookup)
**Referenced globals:** +0x186 (layout pass selector); +0xf17 (pending attr enum slot)
**Referenced strings:** 0x648350 (keyword table)
**Referenced opcodes:** —
**State vars:** +0x186

## Behavioral explanation
Sibling of `markup_attr_keyword_enum_f16` (0x5eb990), byte-for-byte identical except it resolves
against keyword table `0x648350` and stores the enum into `ui_ctx+0xf17`. Tokenizes the attribute
value, and on the `+0x186 == 0xf6` attribute-apply pass performs a keyword→enum lookup, writing one
byte to the pending-element attribute block. The `+0xf16`/`+0xf17` pair are adjacent style attributes
(e.g. two alignment axes) sharing the same handler shape.

## Input / output
- `param_1` (`byte **` [inferred]): attribute cursor.
- Returns 0.

## Side effects
- Advances the attribute cursor; on the `0xf6` pass writes 1 byte to `ui_ctx+0xf17`.

## Important branches
- **`ui_ctx+0x186 == 0xf6`** → lookup + store; **else** → parse-only.

## Constants & flags
- `+0x186 == 0xf6` (-10) — attribute-apply pass. [inferred]
- `0x648350` — keyword→enum table. [inferred]
- `+0xf17` — pending-element attribute byte.

## Corrected reconstruction
```c
undefined8 markup_attr_keyword_enum_f17(unsigned char **cursor)
{
    unsigned char val[0x100];
    parse_quoted_attr_value(cursor, val, 0x100);            // FUN_005ec1b0
    if (ui_ctx->pass == 0xf6) {                             // +0x186
        ui_ctx->pending.enum_f17 =                          // +0xf17
            keyword_lookup(val, KWTAB_648350, 0x20);        // FUN_005ec920
    }
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005eb9f0.c`
  (`FUN_005ec920(auStack_110,0x648350,0x20)` → `iRam007012a0+0xf17`, gated on `+0x186 == -10`).
- Structural twin of 0x5eb990; gated variant of 0x5eb350.
- Confidence **High**; runtime-unvalidated. UI markup, not net.

## Remaining uncertainty
Identity of the attribute and meaning of the `0x648350` enum values; `0x20` arg semantics.
