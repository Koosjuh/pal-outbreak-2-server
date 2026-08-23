# 0x005f2940 ui_place_sized_widget

| field | value |
|---|---|
| Original address | 0x005f2940 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f2940 |
| Resolved name | ui_place_form_control |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005edc40 (form-control element handler)
**Callees:** FUN_005ed6e0 (position/emit control in draw pass)
**Referenced globals:** ctx+0x186 pass; ctx+0x4e4 control-type; ctx+0x16 running height; ctx+0xd8ce/+0xd8d0 line cursors; ctx+0xd8de line-has-content; node+0x2500/+0x2502 extents, +0x251e indent, +0x2530 flags
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x186; ctx+0xd8de

## Behavioral explanation
Reserves layout space for a **form control** (text field / list / gauge / button) whose intrinsic width
depends on the control type in `ctx->controlType` (+0x4e4) and a caller-supplied size `param_1` (character
capacity or item count). In the **measure pass** (`pass==0xF6`) it computes the control's pixel width from
the type switch, adds it to the running height accumulator (+0x16), marks the line as having content
(+0xd8de=1), and grows the node's min/pref content extents (+0x2500/+0x2502) accounting for the node indent
(+0x251e) and the nowrap flag (+0x2530 bit 0x2). In other passes it delegates positioning/emit to
`FUN_005ed6e0` using the current line cursors.

## Input / output
- `param_1` (ushort) — control size parameter: character width for text controls, item count for lists.
- Returns void.

## Important branches (measure pass width from control type +0x4e4)
- type 0,1 (text field): `width = max(param_1,8)*8 + 8`.
- type 2,3 (short text / password): `width = max(param_1,2)*8 + 8`.
- type 4,5 (checkbox / radio): fixed `width = 0x14` (20px).
- type 7 (raw/custom): `width = param_1` (verbatim).
- (type 6 falls through with width 0.)
- After width: `runningHeight(+0x16) += width`; `lineHasContent(+0xd8de)=1`; grow pref extent (+0x2502);
  if node wrappable grow min extent (+0x2500), else clamp min up to pref.
- Non-measure pass: `FUN_005ed6e0(indent + lineX, lineY, &lineX, &lineFlag)` positions/draws the control.

## Constants & flags
- control type (+0x4e4): 0/1 text, 2/3 short text, 4/5 toggle, 7 raw. Char cell = 8px, padding 8px.
- node flag `+0x2530 & 0x2` = nowrap.
- `pass == 0xF6` measure gate.

## Corrected reconstruction
```c
enum CtrlType { CT_TEXT0=0, CT_TEXT1=1, CT_SHORT2=2, CT_SHORT3=3,
                CT_TOGGLE4=4, CT_TOGGLE5=5, CT_RAW=7 };

void ui_place_form_control(u16 size /*param_1*/) {
    u8* ctx = (u8*)0x007012a0;
    LayoutNode* n = node_at(ctx, *(u16*)(ctx+0xd894));

    if (*(char*)(ctx+0x186) == PASS_MEASURE) {
        u16 indent = n->indent /*+0x251e*/;
        u16 w = 0;
        switch (*(u8*)(ctx+0x4e4)) {
            case CT_TEXT0: case CT_TEXT1:   if (size<8) size=8; w = size*8 + 8; break;
            case CT_SHORT2: case CT_SHORT3: if (size<2) size=2; w = size*8 + 8; break;
            case CT_TOGGLE4: case CT_TOGGLE5: w = 0x14; break;
            case CT_RAW:                    w = size; break;
            default:                        w = 0;
        }
        *(s16*)(ctx+0x16) += w;                              // running height/x
        *(u8*)(ctx+0xd8de) = 1;                              // line now has content
        u16 pref = indent + *(u16*)(ctx+0x16);
        if (n->w2502 < pref) n->w2502 = pref;
        if ((n->flags/*+0x2530*/ & 2) == 0) {
            u16 mn = indent + w;
            if (n->w2500 < mn) n->w2500 = mn;
        } else if (n->w2500 < n->w2502) {
            n->w2500 = n->w2502;
        }
    } else {
        ui_control_position(n->indent + *(s16*)(ctx+0xd8ce),  // FUN_005ed6e0
                            *(u16*)(ctx+0xd8d0),
                            (s16*)(ctx+0xd8ce), ctx+0xd8d2);
    }
}
```

## Evidence
- Raw: `FUN_005f2940.c` (452 bytes). The control-type switch (text=8px/char, toggle=20px fixed) is a
  form-widget intrinsic-width table. Caller FUN_005edc40 handles interactive controls; callee FUN_005ed6e0
  positions them in the draw pass.

## Remaining uncertainty
- Control-type→widget mapping (which type is a text box vs list) is inferred from the width formulas, not
  a symbol table. High confidence on the geometry, no runtime trace, no network relevance.
