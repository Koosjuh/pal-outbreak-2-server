# 0x005b4860 create_select_confirm_widget

| field | value |
|---|---|
| Original address | 0x005b4860 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b4860 |
| Resolved name | create_select_confirm_widget |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b41b0 (create path)
**Callees:** FUN_005b09b0 (spinner/value widget update), FUN_005b14b0 (input poll), FUN_005b9110 (message box)
**Referenced globals:** — (operates on the caller-supplied structs)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** widget `+3` phase (0..5); `+0x18` timer; parent struct `+0x43c` selected value; `+0x43f`/`+0x443` result flags

## Behavioral explanation
A 6-phase confirm widget in the create-room flow: the player scrolls a value (an index 0..N) and confirms or
cancels it. `param_3` is the candidate value (`param_3 - 1` is the stored 0-based index) and `param_4` selects
the widget's operating mode. Phases: (0) arm a `0x10` settle timer; (1) count it down; (2) the active poll —
if neither button is down (poll `0x10` confirm and `0x200` cancel/back both 0) it just runs the spinner
(FUN_005b09b0 on `parent+0x43c`); if `0x10` (confirm) is pressed it advances to a short accept animation
(phase 3), sets `+0x43f=1`, SFX; if `0x200` (back) is pressed the behavior depends on `param_4`
(2 → ignore/return, 0 → go to the cancel path phase 5 with message `0x4c` and `+0x443=1`, 1 → just re-latch the
value if it changed); (3) after a 8-tick dwell → phase 4, set `+0x443=1`, show message `0x4c`; (4) dwell then
return `1` (confirmed done); (5) dwell then set `+0x43c=0xff` (cancelled sentinel) and return `1`.

## Input / output
- `param_1` : parent struct (holds selected value `+0x43c`, flags `+0x43f`/`+0x443`).
- `param_2` : widget struct (`+3` phase, `+0x18` timer).
- `param_3` : `u8` candidate value (stored as `param_3 - 1`).
- `param_4` : `char` mode — `0` = confirm-and-notify, `1` = live re-latch, `2` = passive.
- returns `u32` : `1` when finished (phase 4 confirm-done or phase 5 cancel-done), else `0`.

## Side effects
- Runs the value spinner FUN_005b09b0(`parent+0x43c`, `param_3-1`, 3) each idle frame.
- Writes `parent+0x43c` (selected value; `0xff` = cancelled), `parent+0x43f = 1` (confirmed), `parent+0x443 = 1`
  (notice shown). SFX via func_0x001b0140. Message box `0x4c` (FUN_005b9110).

## Important branches
- phase 2, both polls 0 → spinner update only.
- phase 2, `0x200` (back) down: `param_4==2` → return 0 (passive); `param_4==0` → phase 5 (cancel) + msg 0x4c;
  `param_4==1 && parent+0x43c != param_3-1` → re-latch value + SFX.
- phase 2, `0x10` (confirm) down → phase 3, `+0x43f=1`, timer `8`, SFX.
- phase 3 `--timer<0` → phase 4, `+0x443=1`, timer `6`, msg `0x4c`.
- phase 4 `--timer<0` → return `1` (done, confirmed).
- phase 5 `--timer<0` → `parent+0x43c = 0xff`, return `1` (done, cancelled).

## Constants & flags
- input masks: `0x10` = confirm button, `0x200` = back/cancel button (FUN_005b14b0 poll ids).
- timers: `0x10` settle, `8` accept dwell, `6` notice dwell.
- `parent+0x43c = 0xff` = cancelled sentinel. message id `0x4c` (shared notice box).
- `param_4` mode enum: `0` confirm-and-notify, `1` live re-latch, `2` passive/ignore-back.

## Corrected reconstruction
```c
enum confirm_mode { CM_CONFIRM_NOTIFY = 0, CM_RELATCH = 1, CM_PASSIVE = 2 };

struct confirm_widget { /*+3*/ u8 phase; /*+0x18*/ s32 timer; };
// parent: /*+0x43c*/ u8 value; /*+0x43f*/ u8 confirmed; /*+0x443*/ u8 notice_shown;

u32 create_select_confirm_widget(u8 *parent /*param_1*/, struct confirm_widget *w /*param_2*/,
                                 u8 candidate /*param_3*/, char mode /*param_4*/)
{
    switch (w->phase) {
    case 0: w->phase++; w->timer = 0x10; break;
    case 1: if (--w->timer < 0) w->phase++; break;
    case 2:
        if (!poll(0x10)) {                                   // confirm not pressed
            if (!poll(0x200)) {                              // nor back → just spin the value
                spinner_update(&parent[0x43c], candidate - 1, 3);   // FUN_005b09b0
            } else {                                         // BACK pressed
                if (mode == CM_PASSIVE) return 0;
                if (mode == CM_CONFIRM_NOTIFY) {
                    w->phase = 5; sfx(); parent[0x443] = 1; w->timer = 6; show_message_box(0x4c);
                } else if (mode == CM_RELATCH && parent[0x43c] != (u8)(candidate - 1)) {
                    sfx(); parent[0x43c] = candidate - 1;
                }
            }
        } else {                                             // CONFIRM pressed
            w->phase++; sfx(1); parent[0x43f] = 1; w->timer = 8;
        }
        break;
    case 3: if (--w->timer < 0) { w->phase++; parent[0x443] = 1; w->timer = 6; show_message_box(0x4c); } break;
    case 4: if (--w->timer < 0) return 1;                    // confirmed
            break;
    case 5: if (--w->timer < 0) { parent[0x43c] = 0xff; return 1; }  // cancelled
            break;
    }
    return 0;
}
```

## Evidence
- Raw switch on `*(param_2+3)`; nested `FUN_005b14b0(0x10)` / `FUN_005b14b0(0x200)` polls; `param_4` compared
  to 0/1/2; `parent+0x43c/0x43f/0x443` writes; `0xff` sentinel; msg `0x4c`. Runtime-unvalidated.

## Remaining uncertainty
- The value being selected (scenario? difficulty? password digit? player-count cap) is not pinned — prior
  name "password_confirm" is one hypothesis; FUN_005b09b0 behaves like an index spinner, so "select-confirm"
  is the evidence-safe name. Meaning of flags `+0x43f` vs `+0x443` (confirmed vs notice) is inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b4860.c`  — untouched decompiler output.
