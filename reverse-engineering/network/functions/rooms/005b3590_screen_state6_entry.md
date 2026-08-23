# 0x005b3590 room_entry_submit_sm

| field | value |
|---|---|
| Original address | 0x005b3590 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b3590 |
| Resolved name | room_entry_submit_sm |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b24e0
**Callees:** FUN_005af1e0/2c0/2e0/2f0/300/310 (anim/text helpers), FUN_005b3b70 (validate value), FUN_005b68e0/6900 (input gate/pump), FUN_005b9060 (reliable submit sel 0x14), FUN_005ba7b0 (commit/close), FUN_005bdb00/bdc30 (panel + field), FUN_0062fea0 (get status string), FUN_00618b60, FUN_005b14b0 (poll result), func_0x001ae3e0 (text width)
**Referenced globals:** screen-object fields `+0xe`(major)/`+0xf`(sub)/`+0x16`(timer)/`+0x4092`(input value byte)/`+0x4096`(submit buffer)
**Referenced strings:** — (status string fetched by index via FUN_0062fea0(0xd))
**Referenced opcodes:** — (reliable submit selector `0x14`)
**State vars:** screen-object `+0xf` substate (states 0..7)

## Behavioral explanation
Full state machine (not just "state 6") for a room-entry submit screen — the value-entry-then-submit flow
(working hypothesis: join-by-password / enter-code). Renamed from the misleading `screen_state6_entry`.
States: (0) disable input, open the panel with populate cb `0x5b6290`; (1) pump input; (2) run the field
widget FUN_005bdc30 on the input byte at `+0x4092`; (3) **validate** that byte with FUN_005b3b70 — on invalid
(`0`) jump straight to exit state 7, on valid advance and arm the submit sequence (FUN_00618b60,
FUN_005ba7b0, anim); (4) once the anim gate FUN_005af310 fires, arm a `0x4c`-tick timeout and fire the
reliable submit selector `0x14` with the buffer at `+0x4096`; (5) wait out the timer, poll the result
(FUN_005b14b0(0x10)); on result advance + SFX, and each frame render a centered status string
(FUN_0062fea0(0xd) → measure width → FUN_005af1e0 draw at x≈320); (6) wait for the close anim then fall
through; (7) set major=7 (leave) and reset sub=0.

## Input / output
- `param_1` : pointer to the screen/overlay control object (`+0xe..+0x4096`).
- returns `void`. Completion signalled by `major (+0xe) = 7`.

## Side effects
- Panel/field UI via FUN_005bdb00/FUN_005bdc30; anim gates via the FUN_005af2xx/3xx cluster.
- Emits reliable submit selector `0x14` (FUN_005b9060) with buffer `+0x4096`.
- Renders a centered status line (FUN_005af1e0) using string index `0xd` (FUN_0062fea0).
- `func_0x001b0140(1)` SFX on result; sets `+0xe = 7`, `+0xf = 0` on exit.

## Important branches
- state3 `FUN_005b3b70(*(+0x4092)) == 0` → invalid → `+0xf = 7` (skip submit, go to exit); else advance + arm.
- state4 gated on `FUN_005af310() != 0` (anim ready) before submitting.
- state5 `+0x16 != 0` → decrement (with underflow clamp to 0); `== 0` → poll `0x10`; advance only if non-zero.
- state6 `FUN_005af310() == 0` → early return (still animating); else close + fall through to 7.

## Constants & flags
- reliable submit selector `0x14` (same as the other room SMs).
- timeout `0x4c` ticks (`+0x16`); poll masks `0x10` (FUN_005b14b0), string index `0xd` (FUN_0062fea0).
- panel populate cb `0x5b6290`; float `0x42980000` not present here (see FUN_005b45f0). Text centered at x `0x140` (320).

## Corrected reconstruction
```c
struct entry_screen { /*+0xe*/ u8 major; /*+0xf*/ u8 sub; /*+0x16*/ s16 timer;
                      /*+0x4092*/ u8 value; /*+0x4096*/ u8 submit_buf[...]; };

void room_entry_submit_sm(struct entry_screen *s /*param_1*/)
{
    switch (s->sub) {
    case 0: s->sub++; input_disable(); open_panel(0x5b6290);           break;   // 68e0, bdb00
    case 1: pump_input();                                             break;   // 6900
    case 2: s->sub++; run_value_field(&s->value /*+0x4092*/);         break;   // bdc30
    case 3:
        if (validate_value(s->value) == 0) { s->sub = 7; }                     // 5b3b70 invalid
        else { s->sub++; begin_submit(); close_field(); anim_arm(0,10); }      // 618b60/ba7b0/af2f0
        break;
    case 4:
        if (anim_ready() /*af310*/) {
            s->sub++; s->timer = 0x4c;
            submit_reliable(0x14, s->submit_buf /*+0x4096*/);                   // b9060
        }
        break;
    case 5:
        if (s->timer == 0) {
            if (poll_result(0x10) /*b14b0*/) { s->sub++; sfx(1); anim_start(0,10); }
            // per-frame centered status text (string idx 0xd), width-measured, drawn at x=320
            draw_centered_status(0xd);                                         // af2c0/af2e0/62fea0/af1e0
        } else { if (--s->timer < 0) s->timer = 0; }
        break;
    case 6:
        if (!anim_ready()) return;                                             // still closing
        begin_submit(); close_field();                                         // fallthrough
        /* fall through */
    case 7:
        s->major = 7;                                                          // leave screen
        s->sub   = 0;
        break;
    }
}
```

## Evidence
- Raw switch on `*(param_1+0xf)` states 0..7 with the explicit fall-through 6→7; submit selector `0x14` and
  buffer offsets `+0x4092`/`+0x4096` are literal; string index `0xd`, center x `0x140`. Runtime-unvalidated.

## Remaining uncertainty
- The exact op this submits (join-by-code vs password confirm) and the meaning of FUN_005b3b70's validation
  are inferred; needs a runtime/wire trace. Prior name "screen_state6_entry" was inaccurate.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b3590.c`  — untouched decompiler output.
