# 0x005ad030 list_cursor_nav_sm

| field | value |
|---|---|
| Original address | 0x005ad030 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ad030 |
| Resolved name | roomlist_grid_nav_sm |
| Subsystem | rooms |
| Relevance | core |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ace00 (screen dispatcher)
**Callees:** FUN_005af2f0, FUN_005af840, FUN_005b14b0 (pad-edge query), FUN_005ad350 (select entry), FUN_005adc80, FUN_005bfa70, FUN_005b6900, FUN_005b9060, FUN_005b9110, func_0x001b0140 (SFX)
**Referenced globals:** screen_obj +0xf(substate), +0x16(frame timer), +0x907(grid cursor 0..9), +0x992(busy), +0x45a, +0x5ec, +0x10/+0x11(step)
**Referenced opcodes:** —

## Behavioral explanation
Interactive **state machine for the room-list grid screen (sub-screen 1)**. Drives a **5×2 selection grid** (10 slots: indices 0-4 top row, 5-9 bottom row) over the cleared room-list table. Sequence: fade-in with a 10-frame timer (states 0→1), live D-pad navigation (state 2), entry select (state 3 via `FUN_005ad350`), confirm/transition installing the next handler (states 4→6), and a post-action wait that returns to nav on button press (state 7). Movement wraps within each 5-slot row for LEFT/RIGHT and swaps rows for UP/DOWN.

## Input / output
- `param_1` (screen_obj*) — overlay screen object.
- **return** void (state advances in place).

## Side effects
- Moves grid cursor `+0x907`; sets busy `+0x992`; frame timer `+0x16`; panel mode `+0x42b`; plays SFX (`func_0x001b0140`).
- State 3 calls `FUN_005ad350(s, cursor)` to select/enter the highlighted entry.
- State 4 installs next screen handler `FUN_005bfa70(FUN_005adc80(0), 0x5ad9f0)`.

## Important branches
- **case 0**: `FUN_005af2f0(0,10)`; `+0xf++`; timer `+0x16=10`; `FUN_005af840()` (begin fade-in).
- **case 1**: `+0x16--`; when `<0` → `+0xf++`, `+0x16=0`, `+0x45a=1` (fade done).
- **case 2 (navigation)** — `+0x992=1`; poll pad edges in priority order:
  - UP `FUN_005b14b0(0x40004)`: if cursor `>4` → `cursor-=5`, SFX.
  - else DOWN `0x80008`: if cursor `<5` → `cursor+=5`, SFX.
  - else LEFT `0x10001`: `cursor--`; if `<0`→`4`, else if `==4`→`9`; SFX.
  - else RIGHT `0x20002`: `cursor++`; if `==5`→`0`, else if `==10`→`5`; SFX.
  - else CONFIRM `0x10`: `+0xf++` (→state 3), `+0x992=0`.
- **case 3 (select)**: `+0x992=0`; `r=FUN_005ad350(s, cursor)`; `r==-1` → back to nav (`+0xf=2`, SFX 5); `r==1` → advance (`+0xf++`, SFX).
- **case 4**: `FUN_005b68e0()`; `+0x42b=1`; install handler `0x5ad9f0`; `+0xf++`.
- **case 5**: `FUN_005b6900()` (pump).
- **case 6**: `FUN_005b9060(0x14, s+0x5ec)`; `+0xf++`; timer `+0x16=0x10`.
- **case 7**: if `+0x16==0`: on pad `FUN_005b14b0(0x210)` → SFX 1, `+0xf=2`, `FUN_005b9110(0x4c)`; else `+0x16--`.

## Constants & flags
- Pad-edge masks (FUN_005b14b0): `0x40004`=UP, `0x80008`=DOWN, `0x10001`=LEFT, `0x20002`=RIGHT, `0x10`=CONFIRM, `0x210`=back/any (each mask = new-press|held bit pair).
- Grid geometry: 10 slots, row width 5 (wrap), row stride 5 (UP/DOWN).
- `+0x42b` panel-mode 1 (transition).

## Corrected reconstruction
```c
enum pad { PAD_UP=0x40004, PAD_DOWN=0x80008, PAD_LEFT=0x10001,
           PAD_RIGHT=0x20002, PAD_CONFIRM=0x10, PAD_BACK=0x210 };

void roomlist_grid_nav_sm(screen_obj *s)   // param_1
{
    switch (s->substate /*+0xf*/) {
    case 0:
        FUN_005af2f0(0, 10); s->substate++; s->timer /*+0x16*/ = 10; FUN_005af840();
        break;
    case 1:
        if (--s->timer < 0) { s->substate++; s->timer = 0; s->f45a /*+0x45a*/ = 1; }
        break;
    case 2:                                   // 5x2 grid navigation
        s->busy /*+0x992*/ = 1;
        if (pad(PAD_UP))    { if (s->cursor > 4) { s->cursor -= 5; sfx(9); } }
        else if (pad(PAD_DOWN)) { if (s->cursor < 5) { s->cursor += 5; sfx(9); } }
        else if (pad(PAD_LEFT)) {
            if (--s->cursor < 0) s->cursor = 4; else if (s->cursor == 4) s->cursor = 9;
            sfx(9);
        }
        else if (pad(PAD_RIGHT)) {
            if (++s->cursor == 5) s->cursor = 0; else if (s->cursor == 10) s->cursor = 5;
            sfx(9);
        }
        else if (pad(PAD_CONFIRM)) { s->substate++; s->busy = 0; }
        break;
    case 3:                                   // commit selection
        s->busy = 0;
        long r = FUN_005ad350(s, s->cursor /*+0x907*/);
        if (r == -1) { s->substate = 2; s->step10=0; s->step11=0; sfx(5); }
        else if (r == 1) { s->substate++; s->step10=0; s->step11=0; sfx(); }
        break;
    case 4:
        FUN_005b68e0(); s->panel_mode /*+0x42b*/ = 1;
        FUN_005bfa70(FUN_005adc80(0), 0x5ad9f0);   // install next handler
        s->substate++;
        break;
    case 5: FUN_005b6900(); break;
    case 6:
        FUN_005b9060(0x14, (u8*)s + 0x5ec); s->substate++; s->timer = 0x10;
        break;
    case 7:
        if (s->timer == 0) {
            if (pad(PAD_BACK)) { sfx(1); s->substate = 2; FUN_005b9110(0x4c); }
        } else s->timer--;
        break;
    }
}
```

## Evidence
- Raw: `FUN_005ad030.c` (lines 15-122): switch on +0xf; nested `FUN_005b14b0` masks 0x40004/0x80008/0x10001/0x20002/0x10; cursor arithmetic with ±5 row moves and 5-wrap; `FUN_005ad350(param_1,+0x907)` select returning -1/1.
- Sibling: FUN_005ad350 (list_entry_select) is the case-3 callee.

## Remaining uncertainty
- Direction→mask mapping (which bit is up vs down) inferred from the ±5/±1 cursor math, not from a pad-symbol table. `+0x45a`, `+0x5ec` fields and the `0x5ad9f0` handler payload are not fully decoded.
