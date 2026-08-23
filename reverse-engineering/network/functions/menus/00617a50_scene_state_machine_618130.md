# 0x00617a50 scene_state_machine_618130

| field | value |
|---|---|
| Original address | 0x00617a50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00617a50 |
| Resolved name | list_menu_state_machine_618130 |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acab0 (overlay scene pump)
**Callees:** FUN_005aec70 (gate), FUN_005c0e30 (open list), FUN_005b6900 (poll), FUN_005af300 (sfx), FUN_005b2470 (teardown), FUN_005f6970 (action), FUN_005b68e0 (setup)
**Referenced globals:** table 0x618130 (list descriptor); func_0x001a6780 / func_0x001a6910 (libc-style clear/reset)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** obj+0xf minor_state (0..4); obj+0x997 choice result; obj+0x42b=0x1c screen-id; obj+0x16 countdown; obj+0 type

## Behavioral explanation
Per-tick state machine for a **list/confirm menu scene** driven by the descriptor table at `0x618130`. Called every frame from the overlay scene pump, but only runs its body when the global gate `FUN_005aec70()` returns 0 (menu-system idle / not blocked by a modal). The `+0xf` minor-state selects behavior:

- **State 0 (open):** set minor-state to 1, run setup `FUN_005b68e0`, stamp the screen id `+0x42b = 0x1c`, clear the choice result `+0x997 = 0`, and open the selectable list via `FUN_005c0e30(0,0,0, table=0x618130)`.
- **State 1 (poll):** run the list/input poll `FUN_005b6900` each frame. It does not self-advance; the list-select callback (which writes `+0xf` and the choice `+0x997`) drives the scene into states 2/4.
- **State 2 (arm transition):** fire sfx `FUN_005af300(0,10)`, clear a 0x10-byte scratch (`func_0x001a6910(0,0,0x10)`), advance minor-state (`+0xf`++), and arm a 0x10-frame countdown at `+0x16`.
- **State 3 (transition wait):** decrement `+0x16`; when it goes negative, run `func_0x001a6780()` + teardown `FUN_005b2470(3)` and reset minor-state to 0 (reopen the list).
- **State 4 (act on choice):** dispatch on `+0x997`: `1` -> re-stamp the object as a **type-1** scene reset to state 0 (close/hand-off — exit this menu); `2` -> invoke the confirm action `FUN_005f6970()`. Other values: no-op.

Net: an idle-gated list menu that opens a list, waits for a selection, plays a transition, and on confirm either exits (choice 1) or performs an action (choice 2).

## Input / output
- **param_1** (`undefined1 *`): the menu scene object base.
- **returns** `void`.

## Side effects
- Guarded entirely by `FUN_005aec70() == 0`.
- State 0: `obj[0xf]=1`; `FUN_005b68e0()`; `obj[0x42b]=0x1c`; `obj[0x997]=0`; `FUN_005c0e30(0,0,0,0x618130)`.
- State 2: `FUN_005af300(0,10)`; `func_0x001a6910(0,0,0x10)`; `obj[0xf]++`; `obj[0x16]=0x10`.
- State 3: `obj[0x16]--`; on underflow `func_0x001a6780(); FUN_005b2470(3); obj[0xf]=0`.
- State 4/choice==1: `obj[0]=1; obj[1]=0; obj[0xe]=0; obj[0xf]=0; obj[0x10]=0; obj[0x11]=0; obj[0x12]=0` (re-init as type-1 scene).
- State 4/choice==2: `FUN_005f6970()`.

## Important branches
- `if (FUN_005aec70() != 0) return;` — modal/busy gate; whole SM is suppressed while set.
- `switch (obj[0xf])` handled as an `if/else` ladder on values 4,3,2,1,0.
- State 3: `if ((short)(--obj[0x16]) < 0)` — advances on **negative**, so it waits exactly 0x11 (17) frames after the 0x10 arm.
- State 4: `if (obj[0x997]==1) {reset type-1} else if (obj[0x997]==2) {FUN_005f6970}` — else silently stays in state 4.

## Constants & flags
- `0x1c` = screen id stored at `obj+0x42b` (cf. 0x618090 which keys on screen id `0x1a`; different sub-screen).
- `0x618130` = list descriptor table passed to the open call `FUN_005c0e30`.
- Choice-result enum (`obj+0x997`): `0=none, 1=EXIT/close (reset to type-1), 2=CONFIRM (FUN_005f6970)`.
- Transition timer arm `0x10` at `obj+0x16`; sfx cue `(0,10)`.
- `func_0x001a6910(0,0,0x10)` ~ a 16-byte clear/reset; `func_0x001a6780()` ~ paired reset — both libc-style, exact identity unconfirmed.

## Corrected reconstruction
```c
enum list_menu_choice { CHOICE_NONE = 0, CHOICE_EXIT = 1, CHOICE_CONFIRM = 2 }; // obj+0x997

void list_menu_state_machine_618130(menu_scene *obj)
{
    if (menu_gate_busy() /* FUN_005aec70 */ != 0)
        return;                       // suppressed while a modal/blocker is active

    switch (obj->minor_state /* obj+0xf */) {
    case 0: // open the list
        obj->minor_state = 1;
        list_setup();                 // FUN_005b68e0
        obj->screen_id = 0x1c;        // obj+0x42b
        obj->choice    = CHOICE_NONE; // obj+0x997
        list_open(0, 0, 0, /*table*/0x618130); // FUN_005c0e30
        break;

    case 1: // poll input/selection (advanced externally by the select callback)
        list_poll();                  // FUN_005b6900
        break;

    case 2: // arm the transition
        sfx_trigger(0, 10);           // FUN_005af300
        clear16(0, 0, 0x10);          // func_0x001a6910
        obj->minor_state++;           // -> 3
        obj->timer = 0x10;            // obj+0x16
        break;

    case 3: // transition wait
        if ((short)(--obj->timer) < 0) {
            reset_paired();           // func_0x001a6780
            list_teardown(3);         // FUN_005b2470
            obj->minor_state = 0;     // reopen
        }
        break;

    case 4: // act on the confirmed choice
        if (obj->choice == CHOICE_EXIT) {
            obj->type = 1;            // re-init as a type-1 scene (hand-off/close)
            obj->b1 = 0;
            obj->major_state = 0;     // obj+0xe
            obj->minor_state = 0;     // obj+0xf
            obj->f10 = obj->f11 = obj->f12 = 0;
        } else if (obj->choice == CHOICE_CONFIRM) {
            confirm_action();         // FUN_005f6970
        }
        break;
    }
}
```

## Evidence
- Raw decompile: exact gate `if (FUN_005aec70()==0)`, the 5-way `+0xf` ladder, the `0x42b=0x1c` / `0x997=0` writes, `FUN_005c0e30(0,0,0,0x618130)`, and the choice dispatch `+0x997 ==1 / ==2`.
- Screen-id 0x1c and table 0x618130 embedded as immediates; distinct from the 0x1a-keyed confirm flow (0x618090).
- Confidence **High** (control flow fully recovered). Runtime validation pending; state 1→2/4 transition is driven by the (external) list-select callback, not visible here.

## Remaining uncertainty
- Which routine advances `+0xf` from state 1 to states 2/4 and writes `+0x997` (the list-select/confirm callback bound via `FUN_005c0e30`) is not in this batch.
- Exact identities of `func_0x001a6780` / `func_0x001a6910` (assumed libc mem/reset helpers) and `FUN_005f6970` (the confirm action) are inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00617a50.c`  — untouched decompiler output.
