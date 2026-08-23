# 0x005ee470 draw_registered_input_fields

| field | value |
|---|---|
| Original address | 0x005ee470 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ee470 |
| Resolved name | draw_focused_input_field |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005e91f0
**Callees:** FUN_005d9790, FUN_005ed630
**Referenced globals:** iRam007012a0; +0xea80 (field-record array, stride 0x104), +0xea81 (record id string), +0xfac1 (target id to match), +0xeb80/+0xeb82 (record x/y); +0x1538/+0x153a/+0x153c/+0x153e (scroll/viewport offsets x0/y0/x1/y1); +0x1428/+0x1328 (draw palettes); +0x18f (attr); DAT_006494e8 (const draw source); +0x186 (pass); +0xe96b (suppress)
**State vars:** +0x186; +0xe96b

## Behavioral explanation
Redraws the **currently-selected/focused** registered input field. It scans the 16-entry field-record array at +0xea80 (each 0x104 bytes) for the record whose id string (+0xea81) matches the target id at +0xfac1 (via string compare func_0x00109d70 == 0 → match), then draws that field with FUN_005d9790 using its stored rect offset by the viewport scroll (+0x1538..+0x153e) and with attribute bit 0x80 OR'd in (the highlight/focus flag). Draw pass only.

## Input / output
- No parameters. Returns void. Draws at most one field (returns on first match).

## Side effects
- Draw pass only: FUN_005d9790(x0+off, y0+off, x1+off, y1+off, DAT_006494e8, ctx->pal_1428, ctx->pal_1328, attr|0x80).
- No state mutation.

## Important branches
- Gated `if (ctx->pass +0x186 == 0 && ctx->suppress +0xe96b == 0)`.
- Loop `i` in 0..15: `if (strcmp(field[i].id +0xea81, target +0xfac1) == 0)` → draw and **return** (only the matched/focused field). Non-match → continue; loop ends at 16 with no draw.

## Constants & flags
- Record stride 0x104; id at record+1 (+0xea81); rect x at record+0x100 (+0xeb80), y at record+0x102 (+0xeb82) — same layout draw_input_field writes.
- `+0x1538/+0x153a/+0x153c/+0x153e` = viewport/scroll offsets added to the four rect edges (x0,y0,x1,y1).
- `attr | 0x80` — bit 0x80 = focus/highlight attribute.
- 16 = max registered fields (matches `ctx->field_count +0xfac0` cap).

## Corrected reconstruction
```c
void draw_focused_input_field(void)
{
    HtmlCtx *ctx = (HtmlCtx*)iRam007012a0;
    if (ctx->pass != PASS_DRAW || ctx->suppress != 0) return;   // +0x186/+0xe96b

    for (int i = 0; i < 16; i++) {
        InputFieldRec *r = &ctx->fields[i];                     // +0xea80 + i*0x104
        if (strcmp(r->id /*+1 => +0xea81*/, ctx->focus_id /*+0xfac1*/) == 0) {
            u8 attr = FUN_005ed630(&ctx->attr /*+0x18f*/);
            FUN_005d9790(r->x + ctx->view_x0 /*+0x1538*/,
                         r->y + ctx->view_y0 /*+0x153a*/,
                         r->x + ctx->view_x1 /*+0x153c*/,
                         r->y + ctx->view_y1 /*+0x153e*/,
                         (void*)0x6494e8 /*DAT_006494e8*/,
                         ctx->pal_1428, ctx->pal_1328,
                         attr | 0x80);                          // 0x80 = focus highlight
            return;
        }
    }
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_005ee470.c`. Draw gate line 16. Loop over `i*0x104 + 0xea81` string-compared to `+0xfac1` via func_0x00109d70 (line 20), match → draw & return (lines 21–31). Rect read from `+0xeb80/+0xeb82` (lines 24–25), offsets `+0x1538..+0x153e` (lines 26–29), constant source `0x6494e8`, `bVar4 | 0x80` attr.
- Record layout (0x104 stride, id at +1, x at +0x100, y at +0x102) matches the writer FUN_005ee220.

## Remaining uncertainty
- Whether it draws the single focused field or a caret/selection overlay, and the meaning of the two palettes (+0x1428/+0x1328) and DAT_006494e8 glyph, unconfirmed. `+0xfac1` assumed the current-focus id (offset +1 into the id/count region, note +0xfac0 is field_count byte). Not runtime-validated → Medium.
```
