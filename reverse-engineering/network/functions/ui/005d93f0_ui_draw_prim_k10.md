# 0x005d93f0 ui_draw_prim_k10

| field | value |
|---|---|
| Original address | 0x005d93f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d93f0 |
| Resolved name | ui_draw_prim_k0a_line |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ed1f0, FUN_005f2450
**Callees:** FUN_005cab10 (dl_emit_prim)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** — (`kind 0x0a` is a draw-style selector, NOT SN@P wire opcode 0x0a member-list)
**State vars:** —

## Behavioral explanation
Thin wrapper emitting **display-list kind 0x0a (generic line/rule primitive), subtype 1** across the
caller-supplied rectangle (x0,y0)-(x1,y1). It passes the coordinates straight through, uses the default
colour sentinel, and — unlike most siblings — does **not** call `dl_grow_bounds`, so it does not extend
the layout extents (the caller is expected to have sized the region already). `flags=0`. `kind 0x0a`
falls through the emitter's generic (`else`) emit path — no special group/text handling — producing a
plain styled primitive. The name suffix `_k10` refers to the earlier decimal label (kind 10 = 0x0a),
not screen coordinate 0x10; a clearer alias is `ui_draw_prim_k0a_line`.

## Input / output
- **Params:** `param_1=x0, param_2=y0, param_3=x1, param_4=y1` (screen coords).
- **Returns:** void.
- Hard-wired: `dl_emit_prim(kind=0x0a, sub=1, x0,y0,x1,y1, DL_COLOR_DEFAULT, flags=0)`.

## Side effects
- Appends one generic primitive node to the display list. No bounds growth.
- No-op if `cRam00701f20 != 0`.

## Important branches
- None locally.

## Constants & flags
- `kind = 0x0a` — generic line/rule primitive (draw style, not wire opcode).
- `sub = 1`; `color = 0xff000001`; `flags = 0` (no DL_FLAG_OPAQUE — likely transparent/non-anchored).

## Corrected reconstruction
```c
void ui_draw_prim_k0a_line(short x0, short y0, short x1, short y1) /* FUN_005d93f0 */
{
    /* no dl_grow_bounds: caller owns the extent */
    dl_emit_prim(DK_LINE, 1, x0, y0, x1, y1, DL_COLOR_DEFAULT, /*flags*/0);
}
```

## Evidence
- Raw: single call `FUN_005cab10(10,1,param_1,param_2,param_3,param_4,0xffffffffff000001,0)`.
- Absence of a `FUN_005da650` call distinguishes it from the inset/box siblings.
- `kind 0x0a` is not in the emitter's special-cased kind list (8, 0x0d, 6/7), so it uses the generic node path.

## Remaining uncertainty
- Precise rendered style of kind 0x0a (line vs rule vs underline) not runtime-confirmed. Emission is certain.
- Resolved name changed from `ui_draw_prim_k10` to `ui_draw_prim_k0a_line` to remove the misleading "10" (kind is 0x0a).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d93f0.c`  — untouched decompiler output.
