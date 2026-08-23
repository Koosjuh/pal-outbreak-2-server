# 0x005ac4c0 menu_state23_input

| field | value |
|---|---|
| Original address | 0x005ac4c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ac4c0 |
| Resolved name | menu_confirm_dialog_step |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ac8a0 (top-menu dispatcher)
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0
**Referenced globals:** 0x3434a0 (pad new-press bitmask); 0x6c4fab (top_substate); 0x6c4faa (top_screen); 0x6c4ba6 (frame timer); 0x874f35 (skip flag); 0x874f33 (yes/no result); 0x6387e0/0x638800/0x638820 (text ptrs)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fab; uRam006c4faa; sRam006c4ba6; uRam003434a0; uRam00874f33

## Behavioral explanation
Per-frame step for a top-menu confirm/prompt screen (top-state ~0x17 per prior note). It shows a
3-line text prompt every frame and runs a short substate machine: after an intro delay (10 frames)
it samples the pad button bitmask and records a yes/no decision into `0x874f33`, then returns the
dispatcher to top-state 1 (the in-lobby screen). If the pre-set skip flag `0x874f35` is already set
on entry, it bails straight back to state 1 without prompting.

## Input / output
- **Input:** pad new-press bitmask `0x3434a0`; skip flag `0x874f35`.
- **Output:** decision written to `0x874f33` (1 or 0); none returned (`void`).

## Side effects
- Substate 0, skip flag set: `top_screen=1`, `top_substate=0`, early return.
- Substate 0, else: `top_substate=1`, timer `0x6c4ba6 = 10`.
- Substate 1: `timer--`; when it goes below 0, `top_substate=2`, `timer=0`.
- Decision phase: sets `0x874f33` and returns to `top_screen=1`, `top_substate=0`.
- Every frame (except the early-return): draws 3 text lines via `FUN_005af1e0`.

## Important branches
```
top_substate == 0:
    if (0x874f35 != 0)  -> top_screen=1; top_substate=0; return   // skip: already decided
    top_substate = 1; timer(0x6c4ba6) = 10                        // start intro delay
    // fall through into substate-1 body
top_substate == 1:
    timer--
    if (timer >= 0) goto DRAW                                     // still waiting
    top_substate = 2; timer = 0                                   // delay elapsed
top_substate == 2 (or just elapsed):
    if (pad & 0x10)        { 0x874f33 = 1; top_screen=1; top_substate=0; }   // "yes"/accept
    else if (pad & 0x200)  { 0x874f33 = 0; top_screen=1; top_substate=0; }   // "no"/cancel
    // else: no input, stay and keep drawing
DRAW:
    FUN_005af2e0(0x14); FUN_005af2c0(0);
    FUN_005af1e0(0xfa, 0xbf,  2, 0x6387e0);   // line 1
    FUN_005af1e0(0xff, 0xed,  2, 0x638800);   // line 2
    FUN_005af1e0(0x136,0x11b, 2, 0x638820);   // line 3
```

## Constants & flags
| value | meaning |
|---|---|
| pad bit 0x10 | accept/confirm button (new-press) -> result 1 |
| pad bit 0x200 | cancel/decline button (new-press) -> result 0 |
| 0x874f35 | pre-decision skip flag (if set on entry, dialog is bypassed) |
| 0x874f33 | recorded yes/no result consumed downstream |
| 0x6c4ba6 | 10-frame intro delay timer |
| timer=10 | input locked for the first ~10 frames (debounce/animation) |
| `FUN_005af2e0(0x14)` | text/layout setup (size 0x14) |
| `FUN_005af2c0(0)` | text color/mode select |
| `FUN_005af1e0(x,y,mode,strptr)` | draw one text line |

Pad-bit assignment (0x10=accept, 0x200=cancel) is inferred from the two-way branch shape; the exact
physical buttons are unconfirmed (the mask at 0x3434a0 is the game's own normalized new-press bits,
not raw SIO2).

## Corrected reconstruction
```c
// Confirm/prompt screen: 10-frame intro, then read accept(0x10)/cancel(0x200) -> 0x874f33.
void menu_confirm_dialog_step(void)
{
    if (g_lobby.top_substate != 2) {
        if (g_lobby.top_substate != 1) {
            // substate 0 (entry)
            if (g_dialog_skip_874f35 != 0) {        // already decided elsewhere
                g_lobby.top_screen   = 1;
                g_lobby.top_substate = 0;
                return;
            }
            g_lobby.top_substate = 1;
            g_lobby.timer_6c4ba6 = 10;              // intro delay
        }
        // substate 1: count down
        if (--g_lobby.timer_6c4ba6 >= 0)
            goto draw;
        g_lobby.top_substate = 2;
        g_lobby.timer_6c4ba6 = 0;
    }

    // substate 2: sample input
    if (g_pad_newpress_3434a0 & 0x10) {             // accept
        g_dialog_result_874f33 = 1;
        g_lobby.top_screen   = 1;
        g_lobby.top_substate = 0;
    } else if (g_pad_newpress_3434a0 & 0x200) {     // cancel
        g_dialog_result_874f33 = 0;
        g_lobby.top_screen   = 1;
        g_lobby.top_substate = 0;
    }

draw:
    text_setup(0x14);                               // FUN_005af2e0
    text_color(0);                                  // FUN_005af2c0
    draw_text(0xFA,  0xBF,  2, (char*)0x6387E0);    // FUN_005af1e0 line 1
    draw_text(0xFF,  0xED,  2, (char*)0x638800);    // line 2
    draw_text(0x136, 0x11B, 2, (char*)0x638820);    // line 3
}
```

## Evidence
- Raw decompile `FUN_005ac4c0.c`: substate ladder on cRam006c4fab, timer at sRam006c4ba6, pad mask
  tests `& 0x10` / `& 0x200`, three `FUN_005af1e0` draw calls with fixed coords/ptrs.
- 0x3434a0 identified as the pad new-press bitmask in prior menu records.
- Called only from top dispatcher `FUN_005ac8a0`.

## Remaining uncertainty
Physical button behind bit 0x10 vs 0x200, and the strings at 0x6387e0/638800/638820 (the prompt
text), are not decoded. Downstream consumer of 0x874f33 not traced here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ac4c0.c`  — untouched decompiler output.
