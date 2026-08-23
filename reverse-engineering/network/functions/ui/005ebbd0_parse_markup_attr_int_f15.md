# 0x005ebbd0 parse_markup_attr_int_f15

| field | value |
|---|---|
| Original address | 0x005ebbd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ebbd0 |
| Resolved name | markup_attr_byte_f15 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (markup attribute-handler dispatch table)
**Callees:** FUN_005ec1b0 (parse_quoted_attr_value), FUN_005ec650 (parse int)
**Referenced globals:** +0x186 (pass); +0xf15 (pending byte attr)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186

## Behavioral explanation
Byte-valued markup attribute handler, byte-for-byte identical to 0x5ebb50 except it targets
`ui_ctx+0xf15`. Tokenizes the value, and on the `+0x186 == 0xf6` attribute-apply pass parses it with
`FUN_005ec650`, stores the low byte, and clamps a stored `1` back to `0`. The `+0xf14`/`+0xf15` pair
are adjacent byte attributes sharing the same parse-and-clamp shape.

## Input / output
- `param_1` (`byte **` [inferred]): attribute cursor.
- Returns 0.

## Side effects
- Advances cursor; on the `0xf6` pass writes a byte to `ui_ctx+0xf15` (post-clamp).

## Important branches
- **`ui_ctx+0x186 == 0xf6`** → parse + store; **else** → parse-only.
- **stored value == 1** → overwrite with 0.

## Constants & flags
- `+0x186 == 0xf6` — attribute-apply pass.
- `+0xf15` — pending-element byte attribute.
- Clamp: `1 → 0`.

## Corrected reconstruction
```c
undefined8 markup_attr_byte_f15(unsigned char **cursor)
{
    unsigned char val[0x100];
    parse_quoted_attr_value(cursor, val, 0x100);        // FUN_005ec1b0
    if (ui_ctx->pass == 0xf6) {                          // +0x186
        ui_ctx->pending.byte_f15 = (unsigned char)parse_int(val); // FUN_005ec650 -> +0xf15
        if (ui_ctx->pending.byte_f15 == 1)
            ui_ctx->pending.byte_f15 = 0;
    }
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005ebbd0.c`
  (`FUN_005ec650` → `+0xf15`; `if (...+0xf15 == 1) ... = 0`; gated `+0x186 == -10`).
- Structural twin of 0x5ebb50.
- Confidence **High**; runtime-unvalidated. The prior "int" name is corrected to **byte** — the store
  and clamp are single-byte. UI markup, not net.

## Remaining uncertainty
Attribute identity; note the resolved name was upgraded from `..._int_f15` to `..._byte_f15` because
the value is stored/compared as a `char`.
