# 0x005dda30 gs_draw_gridline

| field | value |
|---|---|
| Original address | 0x005dda30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dda30 |
| Resolved name | gs_draw_line |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e0440, FUN_005e19b0, FUN_005e1a30, FUN_005e1aa0, FUN_005e1da0
**Callees:** FUN_005dd920
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
A 2-D line-draw front-end for the overlay's GS renderer. Takes two endpoints as floats
`(x0,y0)-(x1,y1)` plus a packed color word. Before emitting it nudges each X coordinate off the
5-pixel grid lattice (so a stroked line never lands exactly on a grid boundary and disappears/aliases):
if `(x - 4) mod 5 == 0` it pulls the left endpoint 1px left and pushes the right endpoint 1px right.
It then sets the primitive/blend mode via `FUN_005dd920(1,0)`, packs the four coordinates as `short`s
plus the color into a 10-byte stack record, and kicks the GS draw via `func_0x001a2800`.

## Input / output
- `param_1` float x0 — first endpoint X (screen px).
- `param_2` float y0 — first endpoint Y.
- `param_3` float x1 — second endpoint X.
- `param_4` float y1 — second endpoint Y.
- `param_5` u32 color — packed RGBA/color word passed through verbatim.
- Returns: void.

## Side effects
- No globals written. Renders one line primitive to the current GS target (via `func_0x001a2800`).
- `FUN_005dd920(1,0)` selects primitive/render state (line mode) — a GS register write, not app state.

## Important branches
- `((short)(int)x0 - 4) % 5 == 0` → `x0 -= 1.0` (snap left endpoint off the grid).
- `((short)(int)x1 - 4) % 5 == 0` → `x1 += 1.0` (snap right endpoint off the grid).
- No error/bounds paths; unconditional draw.

## Constants & flags
- `5` — grid pitch (px). `4` — grid phase offset. `1.0` — nudge magnitude.
- `FUN_005dd920(1,0)` — arg `1` = primitive/line mode selector (evidence: same callee used by other
  draw front-ends with different first arg); `0` unused/secondary.

## Corrected reconstruction
```c
/* Draw a 2-D line (x0,y0)->(x1,y1) in `color`, nudged off the 5px grid lattice. */
void gs_draw_line(float x0, float y0, float x1, float y1, u32 color)
{
    struct { s16 x0, y0, x1, y1; u32 color; } line;   /* 10-byte GS line record [inferred layout] */

    if (((s16)(int)x0 - 4) % 5 == 0) x0 -= 1.0f;      /* keep endpoints off grid boundaries */
    if (((s16)(int)x1 - 4) % 5 == 0) x1 += 1.0f;

    gs_set_prim_mode(/*line*/1, 0);                   /* FUN_005dd920 */

    line.x0 = (s16)(int)x0;
    line.y0 = (s16)(int)y0;
    line.x1 = (s16)(int)x1;
    line.y1 = (s16)(int)y1;
    line.color = color;
    gs_kick_line(&line);                              /* func_0x001a2800 */
}
```

## Evidence
- Raw decompile FUN_005dda30.c lines 15-27 (grid-snap arithmetic, short-pack, `func_0x001a2800`).
- Called by five sibling draw routines (FUN_005e0440/19b0/1a30/1aa0/1da0) that render browser chrome.
- Confidence **High** on shape; runtime-unvalidated.

## Remaining uncertainty
- Exact color-word channel order and the meaning of `FUN_005dd920`'s second arg are not proven at
  runtime. The stack record's field boundaries are inferred from the short-store sequence.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dda30.c`  — untouched decompiler output.
