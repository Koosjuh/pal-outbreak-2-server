# 0x006176a0 room_phase0b_finalize_tick

| field | value |
|---|---|
| Original address | 0x006176a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006176a0 |
| Resolved name | room_phase0b_exit_launch_tick |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00616c40 (room phase dispatcher)
**Callees:** FUN_005adc80, FUN_005af300, FUN_005b6900, FUN_00618b60, FUN_00608680, FUN_005ac3e0; far helper `func_0x001a6910` (fade)
**Referenced globals:** `uRam00874f9c` (=1 ui/ready flag); `uRam00874f35` (=3 next-mode); `uRam00874fd4` (result)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** obj+0xf minor-state (0..5, fall-through 0→1); obj+0x16 countdown (short)

## Behavioral explanation
Terminal finalize/launch tick for the 0x0b room variant — the twin of `FUN_00617270`
(phase-4). Minor-state `obj+0xf` 0→5 fades the screen and launches the next scene. It differs
from 0x617270 only in that state 1 does **not** call `FUN_005b24c0` (no extra UI element) and
state 1 unconditionally advances (no timer wait before setting the 10-frame timer). State 5 is
identical: set `0x874f9c=1`, `0x874f35=3`, `0x874fd4 = FUN_005adc80(0)`, then `FUN_00608680(obj)`
scene launch and `FUN_005ac3e0()` overlay teardown.

## Input / output
- **Params:** `param_1` — room-scene object pointer.
- **Return:** void.
- **Meaning:** last phase of the 0x0b room screen; exits to mode 3 (scenario/game).

## Side effects
- **state 0:** `obj+0xf++` (→1), `func_0x001a6910(0,0,0x10)` (start fade). **Falls through to 1.**
- **state 1:** `obj+0xf++` (→2), `obj+0x16 = 10`, `FUN_005af300(0)`.
- **state 2:** `obj+0x16--`; when `<0`: `obj+0xf++` (→3), `FUN_00618b60()`.
- **state 3:** `obj+0x16--`; when `<0`: `obj+0xf = 5` (skip 4).
- **state 4:** `FUN_005b6900()` (render; only if externally set).
- **state 5:** `uRam00874f9c = 1`, `uRam00874f35 = 3`, `uRam00874fd4 = FUN_005adc80(0)`,
  `FUN_00608680(obj)`, `FUN_005ac3e0()`.

## Important branches
- `switch(obj+0xf)`; **state 0 falls through into state 1** (no break). State 1 advances
  immediately (no gate). States 2/3 gate on `timer < 0`. State 3 jumps to 5, bypassing 4.

## Constants & flags
- minor states `0`=fade, `1`=start-delay, `2`=delay+UI, `3`=delay→jump-5, `4`=render(bypassed),
  `5`=launch. [High]
- `10` = obj+0x16 reload. [inferred frames]
- `0x874f9c=1`, `0x874f35=3` (next-mode), `func_0x001a6910(0,0,0x10)` fade — same as 0x617270. [inferred]

## Corrected reconstruction
```c
enum { RPB_FADE=0, RPB_START=1, RPB_D2=2, RPB_D3=3, RPB_RENDER=4, RPB_LAUNCH=5 };

void room_phase0b_exit_launch_tick(struct room_scene *obj)
{
    switch (obj->minor /*+0xf*/) {
    case RPB_FADE:
        obj->minor++;                   // → START
        func_0x001a6910(0, 0, 0x10);    // start fade
        /* fall through */
    case RPB_START:
        obj->minor++;                   // → D2
        obj->timer = 10;
        FUN_005af300(0);
        break;
    case RPB_D2:
        if (--obj->timer < 0) { obj->minor++; FUN_00618b60(); }  // → D3
        break;
    case RPB_D3:
        if (--obj->timer < 0) obj->minor = RPB_LAUNCH;           // skip RENDER
        break;
    case RPB_RENDER:
        FUN_005b6900();
        break;
    case RPB_LAUNCH:
        g_ui_ready_874f9c = 1;
        g_next_mode_874f35 = 3;
        g_launch_result_874fd4 = FUN_005adc80(0);
        FUN_00608680(obj);
        FUN_005ac3e0();
        break;
    }
}
```

## Evidence
- Raw decompile lines 13-46: `switch(*(char*)(iVar2+0xf))`, case 0 no break (fall-through),
  case 1 advances then sets timer=10/FUN_005af300, case 5 sets 0x874f9c/0x874f35/0x874fd4 and
  calls FUN_00608680/FUN_005ac3e0.
- Diff vs 0x617270: no `FUN_005b24c0()` and no timer-wait in the first delay state.
- Runtime-unvalidated.

## Remaining uncertainty
- Which room variant maps to slot 0x0b vs 0x04 (0x617270) is inferred from the dispatcher
  layout, not traced live.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006176a0.c`  — untouched decompiler output.
