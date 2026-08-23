# 0x005b1190 cursor_nav_scrolling_list

| field | value |
|---|---|
| Original address | 0x005b1190 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b1190 |
| Resolved name | cursor_nav_scrolling_list (was: cursor_nav_grid) |
| Subsystem | menus |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f60d0, FUN_005f8fc0, FUN_00604180, FUN_00627f20, FUN_0062d1b0 (list-driven menus: room list, area/scenario list, etc.)
**Callees:** FUN_005b14b0 `input_pressed`, FUN_005b16c0 `input_held`
**Referenced globals:** 0x6ca080 `g_navRepeatDelay` (frame countdown for auto-repeat); pad state via callees
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6ca080

## Behavioral explanation
Vertical **scrolling-list** cursor navigator with press-then-hold auto-repeat. It maintains a two-part position: `*scrollTop` (top-visible item index, in item units) and `*cursorRow` (highlighted row within the visible window, 0..`windowRows`-1). The absolute selection index is `scrollTop + cursorRow`. UP is button `0x10001`, DOWN is `0x20002`.

Timing model:
- A fresh UP/DOWN press moves once and arms `g_navRepeatDelay = 0x14` (20 frames).
- While the button stays held, once the delay counts down to 0 the function repeats the move and re-arms `g_navRepeatDelay = 5` (5-frame repeat interval).
- Every actual move plays UI click SFX via `func_0x001b0140(0)`.

`mode` (`param_5`): `< 2` = wrap-around at the ends; `>= 2` = clamp (stop at first/last). The name "grid" was imprecise — there is a single scroll axis with paging, not a 2-D grid.

## Input / output
- `char *scrollTop` (param_1) — top-visible item index (item units); mutated.
- `byte *cursorRow` (param_2) — cursor row within the window (0..windowRows-1); mutated.
- `byte itemCount` (param_3) — total number of items.
- `byte windowRows` (param_4) — visible rows / page size.
- `byte mode` (param_5) — 0/1 = wrap, ≥2 = clamp.
- returns `undefined4` — 1 if the cursor position changed (or a move was consumed) this frame, 0 if nothing happened (idle / waiting out repeat delay).

## Side effects
- Writes `*scrollTop`, `*cursorRow`.
- Writes `g_navRepeatDelay` (0x6ca080).
- Plays click SFX (`func_0x001b0140(0)`) on every move.

## Important branches
UP path (`input_pressed(0x10001)`):
- Arms delay=20, then `--*cursorRow`; if it underflows below 0:
  - at top page (`*scrollTop == 0`) and wrap (`mode<2`):
    - single page (`itemCount < windowRows`): wrap cursor to `itemCount-1`; if `itemCount<2` return 1 (degenerate 1-item list).
    - multi page: jump `scrollTop = itemCount - windowRows`, `cursorRow = windowRows-1` (bottom of last page).
  - at top page, clamp (`mode>=2`): `cursorRow = 0` (pinned).
  - not top page: `--scrollTop`, `cursorRow = 0` (scroll up one).
- return 1.

Repeat gating (only reached if UP not freshly pressed):
- `input_pressed(0x20002)` (DOWN edge) == 0:
  - `g_navRepeatDelay != 0` → decrement, return 0 (still waiting).
  - delay expired: `input_held(0x10001)` (UP still down) → delay=5, redo UP move.
  - else `input_held(0x20002)` (DOWN still down) == 0 → return 0 (nothing held); else delay=5, fall to DOWN move.
- DOWN edge pressed → delay=20, fall to DOWN move.

DOWN move: `++*cursorRow`:
- cursor past last window row (`> windowRows-1`):
  - more items below (`cursorRow + scrollTop < itemCount`): `++scrollTop`, clamp `cursorRow = windowRows-1` (scroll down one).
  - at list end: clamp mode (`mode>1`) → `cursorRow = windowRows-1`, return 1; wrap → `scrollTop=0, cursorRow=0`.
- cursor within window but absolute index past count (`itemCount <= cursorRow + scrollTop`): clamp → `cursorRow--`, return 1; wrap → `scrollTop=0,cursorRow=0`; if `itemCount<2` return 1.
- SFX + return 1.

## Constants & flags
- `0x10001` = UP, `0x20002` = DOWN (overlay pad codes; see 0x5b14b0 map, 'R'/'Q').
- `g_navRepeatDelay`: `0x14` (20) initial hold delay, `5` repeat interval.
- `mode`: `<2` wrap, `>=2` clamp.
- `func_0x001b0140(0)` — UI move/click SFX cue 0.

## Corrected reconstruction
```c
extern s16 g_navRepeatDelay;   // 0x6ca080 (frames until next auto-repeat)
u32  input_pressed(u32);        // 0x5b14b0 (edge/repeat)
u32  input_held(u32);           // 0x5b16c0 (level)
void sfx_cue(int);              // func_0x001b0140

#define BTN_UP    0x10001
#define BTN_DOWN  0x20002
#define HOLD_DELAY 0x14
#define REPEAT_INT 5

// Scrolling vertical list navigator. absolute index = *scrollTop + *cursorRow.
// mode<2 wraps at the ends; mode>=2 clamps. Returns 1 if a move happened.
u32 cursor_nav_scrolling_list(char *scrollTop, u8 *cursorRow,
                              u8 itemCount, u8 windowRows, u8 mode)
{
    if (input_pressed(BTN_UP)) {
        g_navRepeatDelay = HOLD_DELAY;
    do_up:
        if ((s8)(--*cursorRow) < 0) {                 // underflow past row 0
            if (*scrollTop == 0) {                    // top of list
                if (mode < 2) {                       // wrap
                    if (itemCount < windowRows) {     // single page
                        *scrollTop = 0;
                        *cursorRow = itemCount - 1;
                        if (itemCount < 2) return 1;
                    } else {                          // jump to last page
                        *scrollTop = itemCount - windowRows;
                        *cursorRow = windowRows - 1;
                    }
                    sfx_cue(0);
                } else {
                    *cursorRow = 0;                   // clamp at top
                }
            } else {                                  // scroll up one item
                (*scrollTop)--;
                *cursorRow = 0;
                sfx_cue(0);
            }
        } else {
            sfx_cue(0);                               // normal cursor-up
        }
        return 1;
    }

    if (!input_pressed(BTN_DOWN)) {                    // DOWN not freshly pressed
        if (g_navRepeatDelay != 0) { g_navRepeatDelay--; return 0; }
        if (input_held(BTN_UP))   { g_navRepeatDelay = REPEAT_INT; goto do_up; }
        if (!input_held(BTN_DOWN)) return 0;
        g_navRepeatDelay = REPEAT_INT;                // DOWN auto-repeat
    } else {
        g_navRepeatDelay = HOLD_DELAY;
    }

    // ---- DOWN move ----
    u8 row = ++*cursorRow;
    if ((int)(windowRows - 1) < (int)row) {           // past last visible row
        u8 lastRow = windowRows - 1;
        if ((int)(row + *scrollTop) < (int)itemCount) {
            (*scrollTop)++;                           // scroll down one
            *cursorRow = lastRow;
        } else {
            if (mode > 1) { *cursorRow = lastRow; return 1; }  // clamp
            *scrollTop = 0; *cursorRow = 0;           // wrap to top
        }
    } else if ((int)itemCount <= (int)(row + *scrollTop)) {
        if (mode > 1) { *cursorRow = row - 1; return 1; }      // clamp
        *scrollTop = 0; *cursorRow = 0;               // wrap
        if (itemCount < 2) return 1;
    }
    sfx_cue(0);
    return 1;
}
```

## Evidence
- Raw `FUN_005b1190.c`: UP `input_pressed(0x10001)` line 13, DOWN `input_pressed(0x20002)` line 49, held checks `input_held(0x10001/0x20002)` lines 55/60; delay writes 0x14/5 (lines 15,57,64,67); wrap-vs-clamp `param_5 < 2` / `1 < param_5` (lines 20,78,87,93).
- `absolute = scrollTop + cursorRow` confirmed by `(uint)bVar1 + *param_1` compares against `param_3` (itemCount) at lines 73,86.
- Runtime-unvalidated.

## Remaining uncertainty
- `mode` values other than the wrap/clamp split are not exercised in the decompile.
- Semantic of `param_1` as "top-visible item index" vs "page number" is inferred from `itemCount - windowRows` arithmetic; consistent but unproven on the rig.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b1190.c`  — untouched decompiler output.
