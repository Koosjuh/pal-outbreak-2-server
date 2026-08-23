# 0x005f3150 ui_draw_at_cursor

| field | value |
|---|---|
| Original address | 0x005f3150 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f3150 |
| Resolved name | ui_draw_inline_at_cursor |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f3310, FUN_005f3930 (inline content emitters)
**Callees:** FUN_005ef780 (element style push), FUN_005eca10 (draw content at x,y)
**Referenced globals:** ctx+0x186 pass; ctx+0xd894 node idx; ctx+0xd8ce/+0xd8d0/+0xd8d6/+0xd8d8 line cursors; node+0x24e0 element, +0x251a/+0x251c pad, +0x251e indent
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x186; ctx+0xd8ce

## Behavioral explanation
Small **draw-pass leaf** that renders an inline content item (glyph run / decoration) at the current pen
position. It runs only when `ctx->pass == 0` (draw). It computes the pen X from the line H-cursor
(+0xd8ce), the node indent (+0x251e), an alignment offset (+0xd8d6) and the node left pad (+0x251a); the
pen Y from the vertical cursor (+0xd8d0), the node top pad (+0x251c) and the baseline offset (+0xd8d8). It
pushes the node's element style (`FUN_005ef780`) and then calls the content draw primitive `FUN_005eca10`
with the computed position and the caller's payload.

## Input / output
- `param_1` — opaque draw payload forwarded to `FUN_005eca10` (the glyph/content descriptor).
- Returns void.

## Important branches
- `pass != 0` (measure/arrange) → no-op (draw-only leaf).

## Constants & flags
- `pass == 0` = draw pass only.

## Corrected reconstruction
```c
void ui_draw_inline_at_cursor(ctx_t payload /*param_1*/) {
    u8* ctx = (u8*)0x007012a0;
    if (*(char*)(ctx+0x186) != PASS_DRAW) return;

    LayoutNode* n = node_at(ctx, *(u16*)(ctx+0xd894));
    s16 alignX = *(s16*)(ctx+0xd8d6);
    s16 lineX  = *(s16*)(ctx+0xd8ce);

    ui_elem_style_push((u8*)n /*+0x24e0*/);                 // FUN_005ef780
    ui_draw_content(lineX + n->indent/*+0x251e*/ + alignX + n->padLeft/*+0x251a*/,
                    *(s16*)(ctx+0xd8d0) + n->padTop/*+0x251c*/ + *(s16*)(ctx+0xd8d8),
                    payload);                               // FUN_005eca10
}
```

## Evidence
- Raw: `FUN_005f3150.c` (224 bytes). Draw-pass gate (+0x186==0) plus the element-style push (0x5ef780)
  and content draw (0x5eca10) match the inline-draw leaf pattern. Two callers (FUN_005f3310/FUN_005f3930)
  are inline content emitters.

## Remaining uncertainty
- Payload type (`param_1`) opaque; the four cursor terms are inferred to be indent/align/pad/baseline from
  arithmetic parallelism with the placer functions. High confidence on the draw role, no runtime trace,
  no network relevance.
