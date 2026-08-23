# 0x00635940 kbd_cursor_blink_autorepeat

| field | value |
|---|---|
| Original address | 0x00635940 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00635940 |
| Resolved name | kbd_cursor_autoscan |
| Subsystem | menus |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00634ab0
**Callees:** FUN_00631670, FUN_00635ab0
**Referenced globals:** 0x715da8 (kbd state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x2f preedit mode; +0x20 attr/disabled bits; +0x4a bitflags(bit0); +0x48 scan counter; +0x24/+0x25 cursor; +0x26 confirm; +0x248 status

## Behavioral explanation
Auto-scan / hold-to-sweep behavior for the on-screen cursor, invoked when the "nav-hold" bit (`0x80`) is set in kbd_input_tick. It only runs when the field is in normal mode and the relevant key class is enabled:
- gate: `+0x2f == 0` (normal) AND `(+0x20 & 0x20) == 0` (key-class not restricted) AND `layout[+0x28] != 0` (layout allows it). If any gate fails → set status `+0x248 = 5` (reject tone) and return.
- **First activation** (`(+0x4a & 1) == 0`): clear confirm (`+0x26 = 0`), set the auto-scan active bit (`+0x4a |= 1`), initialize scan counter `+0x48 = 1`, and kick `FUN_00631670` (start scan).
- **Continuing** (`+0x4a & 1` already set): advance the scan counter by 5 (`+0x48 += 5`, wrapping to 1 past 0x3B), then derive the grid cursor from it: `col (+0x24) = (+0x48 + 1) % 0x14`, `row (+0x25) = (+0x48 + 1) / 0x14`. If the derived cell is out of range (`col > 0x13` or `row > 2`) it clamps to `col=5, row=0` and resets the counter to 1.
- Always repaints via `FUN_00635ab0`.

Net: while the player holds the nav button, the cursor sweeps across the 21×3 grid at 5 cells/step, wrapping every ~60 counts — an auto-repeat "scanner". Pure UI.

## Input / output
- No params. Returns void.

## Side effects
- `+0x26 = 0` (first activation), `+0x4a |= 1` (scan-active), `+0x48` scan counter (1 or +=5, wrap), `+0x24`/`+0x25` cursor col/row derived, clamp to (5,0).
- `+0x248 = 5` when gated off.
- Calls FUN_00631670 (scan kick, first time) and FUN_00635ab0 (repaint, always in the active branch).

## Important branches
- Gate fails (`+0x2f != 0` OR `+0x20 & 0x20` OR `layout[+0x28] == 0`) → `+0x248 = 5`, return.
- Gate passes:
  - `(+0x4a & 1) == 0` → `+0x26=0; +0x4a|=1; +0x48=1; FUN_00631670()`.
  - else → `+0x48 += 5; if(+0x48 > 0x3B) +0x48 = 1; col=(+0x48+1)%0x14; row=(+0x48+1)/0x14; if(col>0x13 || row>2){col=5;row=0;+0x48=1;}`.
  - `FUN_00635ab0()` repaint.

## Constants & flags
- `0x14` (20) — grid column modulus (21 cols 0..0x14, but valid col range checked `> 0x13`).
- `0x3B` (59) — scan counter wrap point; `+= 5` step ⇒ ~12 steps/sweep.
- clamp target `col=5, row=0`.
- `+0x20 & 0x20` — the KBD_ATTR_RESTRICT_20 bit set by set_kbd_mode when `layout+0x28==0`; blocks auto-scan.
- `+0x4a bit0` — auto-scan-active flag (shared with kbd_input_tick / compose paths).
- `+0x248 = 5` — reject status.

## Corrected reconstruction
```c
void kbd_cursor_autoscan(void)
{
    kbd_state  *s = (kbd_state*)g_kbd_state;
    layout_cfg *L = s->layout_cfg;      // *(int*)(state+0x10)

    if (s->preedit_mode /*+0x2f*/ != 0 ||
        (s->attr /*+0x20*/ & KBD_ATTR_RESTRICT_20) != 0 ||
        L->f28 /*layout+0x28*/ == 0) {
        s->status /*+0x248*/ = 5;       // not allowed here -> reject tone
        return;
    }

    if ((s->bitflags_4a /*+0x4a*/ & 1) == 0) {   // first activation
        s->confirm_26 /*+0x26*/ = 0;
        s->bitflags_4a |= 1;
        s->scan_ctr /*+0x48*/ = 1;
        FUN_00631670();                 // begin scan
    } else {                            // continue sweep
        s->scan_ctr += 5;
        if (s->scan_ctr > 0x3B) s->scan_ctr = 1;
        s->cursor_col /*+0x24*/ = (u8)((s->scan_ctr + 1) % 0x14);
        s->cursor_row /*+0x25*/ = (u8)((s->scan_ctr + 1) / 0x14);
        if (s->cursor_col > 0x13 || s->cursor_row > 2) {   // out of grid -> clamp
            s->cursor_col = 5;
            s->cursor_row = 0;
            s->scan_ctr   = 1;
        }
    }
    FUN_00635ab0();                     // repaint cursor
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_00635940.c` — gate `+0x2f==0 && (+0x20 & 0x20)==0 && layout[+0x28]!=0`, first-activation `+0x4a|1`/`+0x48=1`/`FUN_00631670`, sweep `+0x48+=5`/wrap `0x3b`/`%0x14`/`/0x14`/clamp `col=5,row=0`, else `+0x248=5`.
- Bit 0x20 defined in set_kbd_mode (FUN_00634890); grid dims match kbd_cursor_move_ime (0x14 cols, 3 rows).
- Runtime-unvalidated.

## Remaining uncertainty
- FUN_00631670 (scan kick) and FUN_00635ab0 (repaint) internals not reconstructed.
- Prior name emphasized "blink"; the counter actually drives an auto-scan sweep, hence renamed `kbd_cursor_autoscan`. Whether it also visually blinks (via 635ab0) is plausible but unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00635940.c`  — untouched decompiler output.
