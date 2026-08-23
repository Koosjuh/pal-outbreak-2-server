# 0x00617270 room_phase04_finalize_tick

| field | value |
|---|---|
| Original address | 0x00617270 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00617270 |
| Resolved name | room_phase04_exit_launch_tick |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00616c40 (room phase dispatcher)
**Callees:** FUN_005adc80, FUN_005af300, FUN_005b6900, FUN_005b24c0, FUN_00618b60, FUN_00608680, FUN_005ac3e0; far helper `func_0x001a6910` (fade/transition)
**Referenced globals:** `uRam00874f9c` (=1 ui/ready flag); `uRam00874f35` (=3 next-mode); `uRam00874fd4` (result of FUN_005adc80)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** obj+0xf minor-state (0..5, fall-through 0→1); obj+0x16 countdown (short)

## Behavioral explanation
Terminal phase-4 sub-state machine that fades the room screen out and hands control to the next
scene (scenario/gameplay launch). Minor-state `obj+0xf` runs 0→5: state 0 starts a fade
(`func_0x001a6910`) and **falls through** into state 1; states 1/2/3 are timed steps with UI/SE
cues; state 4 is a render step; state 5 commits the launch — it sets the shared next-mode/ready
flags (`0x874f9c=1`, `0x874f35=3`), records a result token from FUN_005adc80 into `0x874fd4`,
then invokes `FUN_00608680(obj)` (scene exit/launch) and `FUN_005ac3e0()` (overlay teardown).

## Input / output
- **Params:** `param_1` — room-scene object pointer.
- **Return:** void.
- **Meaning:** the last room phase; on state 5 the client leaves the room UI and enters the next
  mode (mode 3).

## Side effects
- **state 0:** `obj+0xf++` (→1), `func_0x001a6910(0,0,0x10)` (start fade). **Falls through to 1.**
- **state 1:** `obj+0x16--`; when `<0`: `obj+0xf++` (→2), `obj+0x16 = 10`, `FUN_005af300(0)`
  (UI), `FUN_005b24c0()` (element).
- **state 2:** `obj+0x16--`; when `<0`: `obj+0xf++` (→3), `FUN_00618b60()`.
- **state 3:** `obj+0x16--`; when `<0`: `obj+0xf = 5` (skip 4).
- **state 4:** `FUN_005b6900()` (render; reachable only if externally set to 4).
- **state 5:** `uRam00874f9c = 1`, `uRam00874f35 = 3`, `uRam00874fd4 = FUN_005adc80(0)`,
  `FUN_00608680(obj)`, `FUN_005ac3e0()`.

## Important branches
- `switch(obj+0xf)`; **state 0 has no `break`** → intentional fall-through into state 1 (the
  fade starts and the same frame begins counting). States 1/2/3 gate their transition on
  `timer < 0`. State 3 jumps directly to 5 (state 4 is skipped in the normal path).

## Constants & flags
- minor states `0`=fade-start, `1`=delay(10f)+UI, `2`=delay+UI2, `3`=delay→jump-to-5,
  `4`=render(bypassed), `5`=launch. [High]
- `10` = obj+0x16 reload (state 1). [inferred frames]
- `0x874f9c = 1` = ui/ready flag; `0x874f35 = 3` = next-mode selector (mode 3 = scenario/game).
  [inferred]
- `func_0x001a6910(0,0,0x10)` = fade helper, arg 0x10. [inferred]

## Corrected reconstruction
```c
enum { RP4_FADE=0, RP4_D1=1, RP4_D2=2, RP4_D3=3, RP4_RENDER=4, RP4_LAUNCH=5 };

void room_phase04_exit_launch_tick(struct room_scene *obj)
{
    switch (obj->minor /*+0xf*/) {
    case RP4_FADE:
        obj->minor++;                    // → D1
        func_0x001a6910(0, 0, 0x10);     // start fade
        /* fall through */
    case RP4_D1:
        if (--obj->timer < 0) {
            obj->minor++;                // → D2
            obj->timer = 10;
            FUN_005af300(0);
            FUN_005b24c0();
        }
        break;
    case RP4_D2:
        if (--obj->timer < 0) { obj->minor++; FUN_00618b60(); }   // → D3
        break;
    case RP4_D3:
        if (--obj->timer < 0) obj->minor = RP4_LAUNCH;            // skip RENDER
        break;
    case RP4_RENDER:
        FUN_005b6900();
        break;
    case RP4_LAUNCH:
        g_ui_ready_874f9c = 1;
        g_next_mode_874f35 = 3;                 // → mode 3 (scenario/game)
        g_launch_result_874fd4 = FUN_005adc80(0);
        FUN_00608680(obj);                       // scene exit / launch
        FUN_005ac3e0();                          // overlay teardown
        break;
    }
}
```

## Evidence
- Raw decompile lines 13-51: `switch(*(char*)(iVar2+0xf))`, case 0 lacks `break` (fall-through),
  case 5 sets `uRam00874f9c=1`, `uRam00874f35=3`, `uRam00874fd4=FUN_005adc80(0)`,
  `FUN_00608680(param_1)`, `FUN_005ac3e0()`.
- Sibling FUN_006176a0 (phase-0x0b) is the same finalize shape minus the FUN_005b24c0 call.
- Runtime-unvalidated.

## Remaining uncertainty
- Whether "mode 3" (0x874f35) is confirmed as the scenario/gameplay mode is inferred from the
  launch context, not traced. FUN_00608680's exact target scene not decoded here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00617270.c`  — untouched decompiler output.
