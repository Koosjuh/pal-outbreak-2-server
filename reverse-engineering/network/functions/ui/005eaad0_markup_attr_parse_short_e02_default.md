# 0x005eaad0 markup_attr_parse_short_e02_default

| field | value |
|---|---|
| Original address | 0x005eaad0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eaad0 |
| Resolved name | markup_attr_parse_short_e02_celldefault |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ec1b0 (read attr token), FUN_005ec6d0 (parse token with default → value)
**Referenced globals:** +0x186 (cell-mode gate 0xF6); +0xd894 (current cell index, u16); +0x24e0 (per-cell struct ptr array, stride 0x5C); +0xe02 (parsed attr, u16)
**Referenced strings:** —
**Referenced opcodes:** — (UI markup)
**State vars:** +0x186; +0xd894; +0xe02

## Behavioral explanation
Parses a 16-bit cell attribute into `+0xe02`, gated on cell/table mode `+0x186 == 0xF6`. Unlike its plain siblings (0x5eaa10/0x5eaa70), it computes a **default** from the current cell before parsing: it indexes the per-cell struct array at `+0x24e0` (stride 0x5C) by the current cell index `+0xd894`; if that cell pointer is non-null it reads the cell's field at `+0x1c` as the default, else default = 0. It then calls FUN_005ec6d0(token, default) — a parse-with-fallback — and stores the result at `+0xe02`. This lets an attribute inherit the current cell's value when the markup omits it (e.g. a width/span defaulting to the cell's own metric).

## Input / output
- `param_1` — attribute cursor (forwarded to reader). [inferred]
- returns `undefined8` 0 (ignored).

## Side effects
- Writes u16 to `+0xe02`. No effect unless `+0x186 == 0xF6`.

## Important branches
- `mode (+0x186) != 0xF6` → no-op.
- cell pointer at `+0x24e0[cell_index]` `!= 0` → default = `cell->field_0x1c`; `== 0` → default = 0. Guards a null cell entry before dereference.

## Constants & flags
- `0xF6` (signed -10) — cell/table mode gate.
- Cell stride `0x5C` (`(idx*0x18 - idx)*4`); array base `+0x24e0`; default source `cell+0x1c`.

## Corrected reconstruction
```c
undefined8 markup_attr_parse_short_e02_celldefault(void *attr_cursor)
{
    char token[0x100 + 16];
    read_attr_token(attr_cursor, token, 0x100);        // FUN_005ec1b0

    MarkupCtx *c = mkctx;
    if (c->mode == MODE_CELL_ATTR) {                   // +0x186 == 0xF6
        int *cell = *(int **)((char *)c
                    + (c->cell_index * 0x17) * 4 + 0x24e0);  // cell ptr for current index
        uint16_t dflt = 0;
        if (cell != 0)
            dflt = *(uint16_t *)((char *)cell + 0x1c);
        c->attr_e02 = (uint16_t)parse_token_default(token, dflt);  // FUN_005ec6d0 -> +0xe02
    }
    return 0;
}
```

## Evidence
- Raw: `FUN_005eaad0.c` lines 12–23. Gate `+0x186 == -10`; cell index stride `(u16*0x18-u16)*4 + 0x24e0`; null-guard → `*(u16*)(cell+0x1c)` else 0; `+0xe02 = FUN_005ec6d0(buf, dflt)`.
- Cell stride/base cross-confirmed by FUN_005ea190 and FUN_005ea900.
- Runtime-unvalidated.

## Remaining uncertainty
- Identity of the cell field at `+0x1c` used as default (likely a width/size metric) and the parse grammar of FUN_005ec6d0. [inferred].
