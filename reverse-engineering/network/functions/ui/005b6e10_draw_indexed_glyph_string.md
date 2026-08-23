# 0x005b6e10 draw_indexed_glyph_string

| field | value |
|---|---|
| Original address | 0x005b6e10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b6e10 |
| Resolved name | draw_indexed_string_from_table |
| Subsystem | ui |
| Relevance | helper |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** — (no direct xref found; likely reached via table/indirect dispatch)
**Callees:** FUN_0062fe70 (resolve string-table base by id), FUN_005b7de0 (markup string renderer, extended)
**Referenced globals:** cRam006c4fe4 (text draw-enable gate); DAT_00638e90 / DAT_00638e94 (screen-position table, 8-byte stride: x@+0, y@+4)
**Referenced strings:** — (strings resolved indirectly through the table)
**Referenced opcodes:** —
**State vars:** cRam006c4fe4

## Behavioral explanation
A convenience wrapper that draws one preset localized/markup string at one of a fixed set of screen anchor points. Gated by the global draw-enable flag `cRam006c4fe4` (skips entirely when text drawing is suppressed, e.g. during transitions). It resolves a string-table base pointer for table id `param_1` (`FUN_0062fe70`), picks a screen (x,y) anchor from `DAT_00638e90` using `param_2` as the row index (8-byte entries), reads the string pointer at slot `param_3` within the resolved table, and hands it to the extended markup renderer `FUN_005b7de0` with zeroed layout-override args.

## Input / output
- **Params:** `param_1` (byte) — string-table / group id passed to `FUN_0062fe70`; `param_2` (byte) — anchor-position index into `DAT_00638e90` (masked `& 0xff`, ×8 bytes); `param_3` (byte) — string index within the resolved table (masked `& 0xff`, ×4 bytes = pointer array).
- **Returns:** `void`.

## Side effects
- None to memory; issues a text-draw via `FUN_005b7de0` (renders to the current draw target) when enabled.

## Important branches
- `cRam006c4fe4 == 0` → return immediately (text drawing disabled — nothing rendered).
- else → resolve, index, and render.

## Constants & flags
- `DAT_00638e90` entry stride = 8 bytes: `+0` = x (u32/float), `+4` = y.
- Table slot stride = 4 bytes (array of string pointers).
- Renderer called with `(x, y, 0, 0, 0, str)` — the three zero args are z/layout overrides left at default.

## Corrected reconstruction
```c
extern char     g_text_draw_enabled;                 // cRam006c4fe4
extern uint32_t g_anchor_table[][2];                 // DAT_00638e90: {x, y} per row
extern char*   *resolve_string_table(int id);        // FUN_0062fe70 -> array of str ptrs
extern void     draw_markup_string_ex(uint32_t x, uint32_t y,
                                       uint32_t z, uint32_t wOverride,
                                       uint32_t hOverride, const char *str); // FUN_005b7de0

void draw_indexed_string_from_table(uint8_t table_id, uint8_t anchor_idx, uint8_t str_idx)
{
    if (g_text_draw_enabled == 0)
        return;

    char **table = resolve_string_table(table_id);
    uint32_t x = g_anchor_table[anchor_idx & 0xff][0];
    uint32_t y = g_anchor_table[anchor_idx & 0xff][1];
    const char *str = table[str_idx & 0xff];

    draw_markup_string_ex(x, y, 0, 0, 0, str);
}
```

## Evidence
- Raw: `if (cRam006c4fe4 != '\0') { iVar1 = FUN_0062fe70(param_1); iVar2 = (param_2 & 0xff)*8; FUN_005b7de0(*(&DAT_00638e90+iVar2), *(&DAT_00638e94+iVar2), 0,0,0, *(iVar1 + (param_3 & 0xff)*4)); }`
- `DAT_00638e90`/`e94` at +0/+4 with ×8 index = the two words of one 8-byte anchor entry.
- Callee `FUN_005b7de0` is the extended markup draw (this record set), confirming string rendering.
- Runtime-unvalidated.

## Remaining uncertainty
- No decompiled caller found, so the exact call sites / which screens use it are unknown (name kept generic: "indexed string from table").
- Whether `DAT_00638e90` words are integer pixels or floats depends on `FUN_005b7de0`'s param types (renderer treats x/y as passthrough).
- Resolved name broadened from `draw_indexed_glyph_string` → `draw_indexed_string_from_table` (it renders a full markup string, not a single glyph).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b6e10.c`  — untouched decompiler output.
