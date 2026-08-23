# 0x00617030 room_phase01_tick

| field | value |
|---|---|
| Original address | 0x00617030 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00617030 |
| Resolved name | room_phase01_intro_tick |
| Subsystem | rooms |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00616c40 (room phase dispatcher)
**Callees:** FUN_005af300, FUN_00618b60; far helper `func_0x003adb80` (paged)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** obj+0xe major-state (++); obj+0xf minor-state (0..2); obj+0x16 countdown (short)

## Behavioral explanation
Phase-1 intro/transition tick for the room-scene object. A three-step timed sequence keyed on
minor-state `obj+0xf`: step 0 kicks off a UI element and arms a 10-frame timer; step 1 counts
down, then fires a second UI action (FUN_00618b60) plus a paged far helper and re-arms a 2-frame
timer; step 2 counts down and, on expiry, advances the major phase and resets minor to 0. Pure
timing/presentation — no network I/O, no roster mutation.

## Input / output
- **Params:** `param_1` — room-scene object pointer.
- **Return:** void.
- **Meaning:** drives a short animated intro between phase-0 (roster commit) and the next phase;
  hands control back to the dispatcher via obj+0xe when done.

## Side effects
- **minor 0:** `obj+0xf = 1`, `obj+0x16 = 10`, `FUN_005af300(0)` (UI/element show).
- **minor 1:** `obj+0x16--`; when `< 0`: `FUN_00618b60()`, `obj+0xf++` (→2), `obj+0x16 = 2`,
  `func_0x003adb80()` (paged far call).
- **minor 2:** `obj+0x16--`; when `< 0`: `obj+0xe++` (advance phase), `obj+0xf = 0`.

## Important branches
- `if (minor==2)` / `else if (minor==1)` / `else if (minor==0)` — mutually exclusive. Each
  countdown branch gates its action on `timer < 0` after decrement. No error/bounds paths.

## Constants & flags
- minor states `0`=start, `1`=first-delay(10f), `2`=second-delay(2f). [High]
- `10` and `2` = frame counts loaded into obj+0x16. [inferred frames]

## Corrected reconstruction
```c
enum { RP1_START=0, RP1_DELAY1=1, RP1_DELAY2=2 };

void room_phase01_intro_tick(struct room_scene *obj)
{
    switch (obj->minor /*+0xf*/) {
    case RP1_START:
        obj->minor = RP1_DELAY1;
        obj->timer /*+0x16*/ = 10;
        FUN_005af300(0);                 // show UI element
        break;
    case RP1_DELAY1:
        if (--obj->timer < 0) {
            FUN_00618b60();              // second UI action
            obj->minor++;                // → DELAY2
            obj->timer = 2;
            func_0x003adb80();           // paged far helper
        }
        break;
    case RP1_DELAY2:
        if (--obj->timer < 0) {
            obj->major++;                // advance phase
            obj->minor = 0;
        }
        break;
    }
}
```
(Note: decompiler emits the branches as `if(2) … else if(1) … else if(0)`; behavior is a
disjoint 3-way on minor-state and is preserved above.)

## Evidence
- Raw decompile lines 12-35: three `cVar1 ==` branches on `*(char*)(param_1+0xf)`, timer
  decrements on `param_1+0x16`, `param_1+0xe++`, calls to FUN_005af300/FUN_00618b60/func_0x003adb80.
- Runtime-unvalidated.

## Remaining uncertainty
- Roles of FUN_005af300 / FUN_00618b60 (UI show vs SE) and the paged `func_0x003adb80` are
  inferred, not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00617030.c`  — untouched decompiler output.
