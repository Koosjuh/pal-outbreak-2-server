# 0x005b47a0 error_notice_timeout_widget

| field | value |
|---|---|
| Original address | 0x005b47a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b47a0 |
| Resolved name | error_notice_timeout_widget |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b3ed0 (enter path), FUN_005b41b0 (create path)
**Callees:** FUN_005b4c80 (panel fade-in), FUN_005ba570 (arm), FUN_005b9110 (message box)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** widget `+3` phase (0..2); `+0x18` timer

## Behavioral explanation
A fire-and-forget 3-phase timeout widget that displays an error/notice panel then a message box, used by both
the enter (FUN_005b3ed0) and create (FUN_005b41b0) flows when an operation fails or needs a fixed dwell.
(0) arm a `0x3c`(60)-tick timer, advance, fade in panel mode `6` (FUN_005b4c80(6)) and arm (FUN_005ba570(0x20));
(1) count down and, when the timer underflows, advance, reload the timer to `0x3c`, and pop message box `0x4c`
(FUN_005b9110(0x4c)); (2) count down again and return `1` (done) when it underflows. Purely time-driven — no
input, no network.

## Input / output
- `param_1` : pointer to the widget struct (`+3` phase, `+0x18` timer).
- returns `u32` : `1` when finished (phase-2 timer elapsed), else `0`.

## Side effects
- UI only: panel fade (FUN_005b4c80(6)), arm (FUN_005ba570(0x20)), message box `0x4c` (FUN_005b9110).

## Important branches
- phase 0 (initial): set timer `0x3c`, advance, open panel — runs once.
- phase 1: `--timer < 0` → advance, timer `= 0x3c`, show message `0x4c`.
- phase 2: `--timer < 0` → return `1`.
- default (`+3` not 0..2) → return `0`.

## Constants & flags
- `0x3c` = 60-tick (~1 s at 60 Hz) dwell for each phase.
- panel mode `6` (FUN_005b4c80); message id `0x4c` (FUN_005b9110) = the shared error/notice box (same id as
  the async error handlers FUN_005adbe0 / FUN_005b3590).

## Corrected reconstruction
```c
struct notice_widget { /*+3*/ u8 phase; /*+0x18*/ s32 timer; };

u32 error_notice_timeout_widget(struct notice_widget *w /*param_1*/)
{
    switch (w->phase) {
    case 0:
        w->timer = 0x3c;
        w->phase++;
        panel_fade_in(6);        // FUN_005b4c80(6)
        arm(0x20);               // FUN_005ba570
        break;
    case 1:
        if (--w->timer < 0) {
            w->phase++;
            w->timer = 0x3c;
            show_message_box(0x4c);   // FUN_005b9110
        }
        break;
    case 2:
        if (--w->timer < 0) return 1; // done
        break;
    default:
        return 0;
    }
    return 0;
}
```

## Evidence
- Raw phase ladder on `*(param_1+3)`; literal timer `0x3c`, panel `6`, message `0x4c`. Callers are the enter
  and create dispatch SMs (FUN_005b3ed0/FUN_005b41b0). Runtime-unvalidated.

## Remaining uncertainty
- Whether phase-0's panel and phase-1's message box carry distinct text (error vs "please wait") is not
  decoded; only the ids are known. Name reflects the error/notice usage inferred from message `0x4c`.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b47a0.c`  — untouched decompiler output.
