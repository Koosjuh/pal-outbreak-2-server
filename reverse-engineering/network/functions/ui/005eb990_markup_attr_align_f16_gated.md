# 0x005eb990 markup_attr_align_f16_gated

| field | value |
|---|---|
| Original address | 0x005eb990 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eb990 |
| Resolved name | markup_attr_keyword_enum_f16 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (dispatched from a markup attribute-handler table; no direct xref)
**Callees:** FUN_005ec1b0 (parse_quoted_attr_value), FUN_005ec920 (keyword→enum lookup)
**Referenced globals:** +0x186 (layout pass selector); +0xf16 (pending attr enum slot)
**Referenced strings:** 0x648320 (keyword table)
**Referenced opcodes:** —
**State vars:** +0x186

## Behavioral explanation
A markup attribute handler. Tokenizes the `="value"` for its attribute into a 256-byte stack buffer,
then — only on the layout pass where `ui_ctx+0x186 == 0xf6` (-10) — resolves the value against keyword
table `0x648320` via `FUN_005ec920` and stores the resulting enum byte into the pending-element
attribute block at `ui_ctx+0xf16`. On other passes the value is parsed but discarded (the tag has
already been formatted). One of a pair (`+0xf16` here, `+0xf17` in 0x5eb9f0) — likely a
horizontal/vertical alignment or similar keyword-valued style attribute.

## Input / output
- `param_1` (`byte **` [inferred]): attribute cursor forwarded to the tokenizer.
- Returns 0.

## Side effects
- Consumes the attribute from the cursor (`FUN_005ec1b0` advances it).
- On the `0xf6` pass: writes 1 byte to `ui_ctx+0xf16`.

## Important branches
- **`ui_ctx+0x186 == 0xf6`** → look up keyword, store enum. **else** → parse only, store nothing.

## Constants & flags
- `+0x186 == 0xf6` (-10) — the attribute-apply layout pass. [inferred: measure/format pass; the value
  that gates attribute application across this family]
- `0x648320` — keyword→enum table consumed by `FUN_005ec920`. [inferred]
- `+0xf16` — one byte in the pending-element attribute struct (`+0xf10..+0xf1c`).

## Corrected reconstruction
```c
// Markup attribute handler: keyword-enum attribute -> ui_ctx.pending_attr.enum_f16
undefined8 markup_attr_keyword_enum_f16(unsigned char **cursor)
{
    unsigned char val[0x100];
    parse_quoted_attr_value(cursor, val, 0x100);              // FUN_005ec1b0
    if (ui_ctx->pass == 0xf6) {                               // +0x186 attribute-apply pass
        ui_ctx->pending.enum_f16 =                            // +0xf16
            keyword_lookup(val, KWTAB_648320, 0x20);          // FUN_005ec920
    }
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005eb990.c`
  (`FUN_005ec920(auStack_110,0x648320,0x20)` → `iRam007012a0+0xf16`, gated on `+0x186 == -10`).
- Twin of 0x5eb9f0 (`0x648350`→`+0xf17`); classified as the gated variant of 0x5eb300.
- Confidence **High**; runtime-unvalidated. UI markup, outside the SN@P net boundary.

## Remaining uncertainty
Which style attribute this is (align/valign/etc.); the `0x20` arg to `FUN_005ec920` (entry count vs
stride). Prior note called it "align"; kept as generic keyword-enum pending keyword-table dump.
