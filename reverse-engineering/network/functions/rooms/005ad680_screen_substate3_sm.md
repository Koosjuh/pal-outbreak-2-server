# 0x005ad680 room_select_submit_sm

| field | value |
|---|---|
| Original address | 0x005ad680 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ad680 |
| Resolved name | room_select_submit_sm |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005ace00
**Callees:** FUN_005ad350, FUN_005adc80, FUN_005b14b0, FUN_005b68e0, FUN_005b6900, FUN_005b9060, FUN_005bf340, FUN_005bfa70
**Referenced globals:** list buffers `0x6c3860`(0xd98)/`0x6c3030`(0x828); per-entry flag array `0x6c386e` (stride `0x15c`, 10 entries); `0x6c45fc`/`0x6c4600` counters; screen-object fields `+0xe`(major)/`+0xf`(substate)/`+0x10`/`+0x11`(step)/`+0x16`(timer)/`+0x42b`(list draw-mode)/`+0x5ec`(submit buffer)/`+0x992`(flag)
**Referenced strings:** —
**Referenced opcodes:** — (submits via FUN_005b9060 sel 0x14 / FUN_005bfa70 async)
**State vars:** screen-object `+0xf` substate; registers reply cb 0x5ad9f0 (pending tag 1)

## Behavioral explanation
Sub-screen state machine driven by the screen object's `+0xf` counter (states 0..7). It (0) clears the two
list buffers and the 10-entry per-slot flag array, arms list draw-mode 3, and registers the list-populate
dialog callback 0x5ad890; (2) reads the item count and drives a selection via FUN_005ad350, resetting the
whole SM on cancel (`-1`) or advancing on commit (`1`); (3/4) submits the current selection asynchronously
via FUN_005bfa70 with reply callback **0x5ad9f0** (this is where reply_cb tag-1 is registered) and skips two
states; (6) fires the reliable submit selector `0x14` with the buffer at `+0x5ec` and arms a `0x10`-tick
timer; (7) waits out the timer then polls result flag `0x210` (FUN_005b14b0) and, on success, plays an SFX
and resets the SM. States 1 and 5 just pump input (FUN_005b6900).

## Input / output
- `param_1` : pointer to the screen/overlay control object (fields at `+0xe..+0x992`).
- returns `void`. Progress is entirely via the `+0xf` substate and the reset-to-0 on cancel.

## Side effects
- Zeroes `0x6c4600`,`0x6c45fc`; `memset(0x6c3860,0,0xd98)`, `memset(0x6c3030,0,0x828)`; clears
  `*(i*0x15c + 0x6c386e)` for i=0..9.
- Sets obj `+0x42b` list draw-mode (3 in state0, 1 in state3/4), `+0x16` timer, `+0x992=0`.
- Registers dialog/list-populate callback 0x5ad890 (FUN_005bf340) and async reply callback 0x5ad9f0
  (FUN_005bfa70). Emits the reliable submit selector `0x14` (FUN_005b9060).
- On result: `func_0x001b0140(1)` SFX; resets obj `+0xe/+0xf/+0x10(/+0x11)` to 0 (SM restart).

## Important branches
- state2 `FUN_005ad350 == -1` → full reset (`+0xe=+0xf=+0x10=+0x11=0`); `== 1` → advance + clear step; other → hold.
- state3/4 shared body (double `+0xf++`) → skips the paired wait state.
- state7 `+0x16 != 0` → decrement (still waiting); `== 0` → poll `0x210`, act only if non-zero.

## Constants & flags
- `0x14` = reliable enter/submit selector (FUN_005b9060), same selector used across the room SMs.
- `0x210` / `0x10` = result/input poll masks passed to FUN_005b14b0.
- `0x5ad890` list-populate cb; `0x5ad9f0` async reply cb (tag 1); `0x5ad9f0` **[corrects prior note]** is
  registered here, not in FUN_005ad030.

## Corrected reconstruction
```c
// Overlay screen object (partial) — the room selection/submit screen.
struct room_screen { /*+0xe*/ u8 major; /*+0xf*/ u8 sub; /*+0x10*/ u8 step0; /*+0x11*/ u8 step1;
                     /*+0x16*/ s16 timer; /*+0x42b*/ u8 list_mode; /*+0x5ec*/ u8 submit_buf[...];
                     /*+0x992*/ u8 flag; };

void room_select_submit_sm(struct room_screen *s /*param_1*/)
{
    switch (s->sub) {
    case 0:
        g_6c45fc = 0; g_6c4600 = 0;
        memset((void*)0x6c3860, 0, 0xd98);
        memset((void*)0x6c3030, 0, 0x828);
        for (int i = 0; i < 10; i++) *(u8*)(i*0x15c + 0x6c386e) = 0;   // clear per-slot flags
        input_disable();                                              // FUN_005b68e0
        s->list_mode = 3;
        open_list_dialog(0, 0xf, 0x5ad890);                           // FUN_005bf340 (populate cb)
        s->sub++;
        break;
    case 1: pump_input(); break;                                      // FUN_005b6900
    case 2:
        s->flag = 0;
        int n = get_item_count(0);                                    // FUN_005adc80
        long r = run_selection(s, n - 1);                             // FUN_005ad350
        if (r == -1)      { s->major = s->sub = s->step0 = s->step1 = 0; }  // cancel → restart
        else if (r == 1)  { s->sub++; s->step0 = s->step1 = 0; }            // commit
        break;
    case 3: case 4:
        input_disable();
        s->list_mode = 1;
        u16 sel = get_item_count(0);
        submit_async(sel, 0x5ad9f0);                                  // FUN_005bfa70 (reply cb tag1)
        s->sub += 2;                                                  // skip paired wait
        break;
    case 5: pump_input(); break;
    case 6:
        submit_reliable(0x14, s->submit_buf /*+0x5ec*/);              // FUN_005b9060
        s->sub++;
        s->timer = 0x10;
        break;
    case 7:
        if (s->timer == 0) {
            if (poll_result(0x210)) {                                 // FUN_005b14b0
                sfx(1);                                               // func_0x001b0140
                s->major = s->sub = s->step0 = 0;                     // done → restart
            }
        } else s->timer--;
        break;
    }
}
```

## Evidence
- Raw switch on `*(param_1+0xf)`; memset sizes 0xd98/0x828; 10× `0x15c` stride loop; callee set matches the
  overlay room UI cluster. `0x5ad9f0` passed to FUN_005bfa70 in case3/4 (Confirmed cross-ref to reply_cb).
- Selector `0x14` and poll masks are literal args. Runtime-unvalidated.

## Remaining uncertainty
- Exact semantics of FUN_005ad350 (selection driver) and the `0x210`/`0x10` masks not fully decoded.
- Whether this screen is room-list, scenario-select, or character-select selection is inferred from the
  list buffers + `0x14` submit; needs a runtime trace to pin.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ad680.c`  — untouched decompiler output.
