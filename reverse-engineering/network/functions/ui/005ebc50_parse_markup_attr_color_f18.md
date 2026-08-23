# 0x005ebc50 parse_markup_attr_color_f18

| field | value |
|---|---|
| Original address | 0x005ebc50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ebc50 |
| Resolved name | markup_attr_color_f18 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup attribute-handler dispatch table)
**Callees:** FUN_005ec1b0 (parse_quoted_attr_value), FUN_005ec4f0 (parse_color_value)
**Referenced globals:** +0x186 (pass); +0xf18 (pending color attr, 32-bit)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186

## Behavioral explanation
Markup attribute handler for a color attribute (e.g. `color=` / `bgcolor=`). Tokenizes the value into a
stack buffer, then — on the `+0x186 == 0xf6` attribute-apply pass AND only when the buffer is non-empty
— converts it to packed `0xRRGGBB` via `parse_color_value` (0x5ec4f0) and stores the 32-bit result at
`ui_ctx+0xf18`. The extra non-empty guard (`buf[0] != 0`) distinguishes it from the numeric handlers:
an empty color value leaves the previous color intact rather than overwriting with a parse of "".

## Input / output
- `param_1` (`byte **` [inferred]): attribute cursor.
- Returns 0.

## Side effects
- Advances cursor; on the `0xf6` pass with a non-empty value writes 32 bits to `ui_ctx+0xf18`.

## Important branches
- **`ui_ctx+0x186 == 0xf6` AND `buf[0] != '\0'`** → `parse_color_value` + store `+0xf18`;
  **else** → nothing stored.

## Constants & flags
- `+0x186 == 0xf6` — attribute-apply pass.
- `+0xf18` — pending-element 32-bit color attribute (`0xRRGGBB`, or `-1` on name-lookup failure via
  `parse_color_value`).

## Corrected reconstruction
```c
undefined8 markup_attr_color_f18(unsigned char **cursor)
{
    char val[0x100];
    parse_quoted_attr_value(cursor, val, 0x100);              // FUN_005ec1b0
    if (ui_ctx->pass == 0xf6 && val[0] != '\0')               // +0x186, non-empty only
        ui_ctx->pending.color_f18 = parse_color_value(val);   // FUN_005ec4f0 -> +0xf18
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005ebc50.c`
  (`(*(char*)(...+0x186) == -10) && (acStack_110[0] != '\0')` → `FUN_005ec4f0` → `*(u32)(...+0xf18)`).
- `FUN_005ec4f0` is the confirmed HTML/CSS color parser.
- Confidence **High**; runtime-unvalidated. UI markup, not net.

## Remaining uncertainty
Whether this is fg vs bg color; how a `-1` (failed name) is later treated by the renderer.
