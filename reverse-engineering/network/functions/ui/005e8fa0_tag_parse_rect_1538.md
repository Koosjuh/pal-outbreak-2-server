# 0x005e8fa0 tag_parse_rect_offsets_1538

| field | value |
|---|---|
| Original address | 0x005e8fa0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e8fa0 |
| Resolved name | tag_parse_rect_offsets_1538 |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** — (address-taken; dispatched from the markup tag table)
**Callees:** FUN_005ec1b0 (attribute-value extractor)
**Referenced globals:** markup-ctx base `iRam007012a0`; fields `+0x1538/+0x153a/+0x153c/+0x153e` (4×s16)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x1538 .. +0x153e

## Behavioral explanation
Markup attribute handler that parses a comma-separated tuple of up to four decimal
integers into the four s16 fields `ctx+0x1538/+0x153a/+0x153c/+0x153e`. First it extracts
the raw attribute value into a 256-byte stack buffer via `FUN_005ec1b0`, then walks it:
digits accumulate a decimal value (running `v = v*10 + (c-'0')`), a comma (`0x2c`)
terminates the current field and moves to the next, a NUL (`0x00`) ends parsing early.
These four shorts are added as offsets to a base rectangle in the anchor-draw routine
`FUN_005ee470` (`x0+0x1538, y0+0x153a, x1+0x153c, y1+0x153e` passed to `FUN_005d9790`),
i.e. this is a `rect="x0,y0,x1,y1"` style coordinate-offset attribute.

## Input / output
- Input: `param_1` = `char**` parser cursor pointer.
- Output: `undefined8` 0 (consumed).

## Side effects
- Writes 4 s16 fields at `ctx+0x1538,+0x153a,+0x153c,+0x153e`.
- Advances `*param_1`.

## Important branches
- `c == 0` OR `c == ','` (0x2c) → break the current field's digit loop.
- `'0' <= c <= '9'` (`0x2f < c < 0x3a`) → accumulate the digit into the field.
- After field 1: `if (c != 0)` continue to field 2; else stop. Same gate cascades
  through fields 3 and 4 — each subsequent field parsed only if the previous ended on `,`.
- Non-digit, non-comma, non-NUL chars are skipped (do not accumulate, do not terminate).

## Constants & flags
- `0x2c` = ',' separator; `0x30..0x39` = ASCII digits; `0x100` = extractor scratch size.
- Fields are 16-bit signed (`short`), added to a base rect (no sign handling → non-negative).

## Corrected reconstruction
```c
/* rect="x0,y0,x1,y1" — 4 signed-16 offsets added to base rect by FUN_005ee470 */
undefined8 tag_parse_rect_offsets_1538(char **cursor)
{
    u8 buf[0x100];
    parse_attr_value(cursor, buf, 0x100);           /* FUN_005ec1b0 */

    s16 *field[4] = { (s16*)(g_markup_ctx + 0x1538), /* x0 off */
                      (s16*)(g_markup_ctx + 0x153a), /* y0 off */
                      (s16*)(g_markup_ctx + 0x153c), /* x1 off */
                      (s16*)(g_markup_ctx + 0x153e) };/* y1 off */
    int i = 0;                                      /* buffer index */
    for (int f = 0; f < 4; f++) {
        s16 acc = 0;
        for (;;) {
            u8 c = buf[i];
            if (c == 0 || c == ',') break;
            if (c >= '0' && c <= '9') { acc = acc*10 + (c - '0'); *field[f] = acc; }
            i++;
        }
        if (buf[i] == 0) break;                     /* stop unless we ended on ',' */
        i++;                                        /* skip the comma */
    }
    return 0;
}
```
(Exact decompiler control flow stores `acc` *every* digit iteration so the last write per
field is the full value — preserved above via `*field[f] = acc` inside the loop.)

## Evidence
- Raw: four near-identical digit loops writing to `+0x1538/+0x153a/+0x153c/+0x153e`,
  gated on comma continuation.
- Consumer: `FUN_005ee470` adds these to base coords in the `FUN_005d9790` draw call.
- Runtime-unvalidated.

## Remaining uncertainty
Which coordinate is which axis (x/y ordering) inferred from the draw call arg order; the
parse itself (4 comma-separated decimals) is certain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e8fa0.c`  — untouched decompiler output.
