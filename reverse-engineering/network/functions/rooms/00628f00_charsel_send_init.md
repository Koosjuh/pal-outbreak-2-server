# 0x00628f00 charsel_send_init

| field | value |
|---|---|
| Original address | 0x00628f00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00628f00 |
| Resolved name | charsel_task_init |
| Subsystem | rooms |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00628e10 (charsel task machine)
**Callees:** FUN_005af400 (SE cue), FUN_00629a40 (widget/list build), FUN_00629d00 (render callback install)
**Referenced globals:** — (reads obj+0x9ce mode flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** task+0x0 substep (++); task+0xa/0xb timer (short); task+0xc..0xf cleared

## Behavioral explanation
Substep 0 of the character-select task machine. It advances the task substep (`task+0x0 += 1`),
then seeds the substep timer at `task+0xa` (a 16-bit little-endian short) based on the object's
mode flag `obj+0x9ce`: if the flag is 0 the timer is `0x0008` (8 frames — a brief delay), else it
is `0x0000` (run immediately). It zeroes the remaining task control words (`task+0xc..+0xf`),
plays an SE cue (FUN_005af400), builds the char-select widget/list (FUN_00629a40), and installs
the render callback (FUN_00629d00). Returns the -1 continue sentinel. This is the setup step that
brings up the character-selection screen inside a room.

## Input / output
- **Params:** `param_1` — room object pointer (holds mode flag +0x9ce); `param_2` — task
  descriptor pointer.
- **Return:** `0xffffffff` (-1) — "continue" sentinel.
- **Meaning:** initializes and displays the charsel screen; subsequent ticks run the confirm SM
  (FUN_00629200).

## Side effects
- `task+0x0 += 1` — advance to the next substep.
- If `obj+0x9ce == 0`: `task+0xa = 8`, `task+0xb = 0` (8-frame delay); else `task+0xa = 0`,
  `task+0xb = 0` (immediate). (bytes 0xa/0xb form the LE short timer.)
- `task+0xc = task+0xd = task+0xe = task+0xf = 0` — clear control words.
- `FUN_005af400()` — SE cue.
- `FUN_00629a40(param_2, 0)` — build char-select widget/list.
- `FUN_00629d00(param_2, 0)` — install render callback.

## Important branches
- `if (obj+0x9ce == 0)` → 8-frame delay; `else` → immediate (0). Single gate on the mode flag.

## Constants & flags
- `0x08` = default charsel intro delay (frames) when +0x9ce == 0. [inferred frames]
- `obj+0x9ce` = mode/skip-delay flag (0 = animate in, nonzero = show now). [inferred]
- return `0xffffffff` = continue sentinel. [High]

## Corrected reconstruction
```c
// Substep 0: bring up the character-select screen (widgets + render cb), arm intro delay.
u32 charsel_task_init(struct room_scene *obj, struct msg_task *t)
{
    t->substep /*+0x0*/ += 1;

    if (obj->charsel_mode_9ce /*+0x9ce*/ == 0) {
        t->timer_lo /*+0xa*/ = 8;    // 8-frame intro delay
        t->timer_hi /*+0xb*/ = 0;
    } else {
        t->timer_lo = 0;             // show immediately
        t->timer_hi = 0;
    }
    t->c = t->d = t->e = t->f = 0;   // +0xc..+0xf

    FUN_005af400();                  // SE cue
    FUN_00629a40(t, 0);              // build charsel widgets
    FUN_00629d00(t, 0);              // install render callback
    return 0xffffffff;
}
```

## Evidence
- Raw decompile lines 12-28: `*pcVar1 += 1;` then `if (*(param_1+0x9ce)==0) { [10]=8;[0xb]=0; }
  else { [10]=0;[0xb]=0; }`, `[0xc..0xf]=0`, `FUN_005af400(); FUN_00629a40(param_2,0);
  FUN_00629d00(param_2,0); return 0xffffffff`.
- Sibling confirm SM FUN_00629200 (same task machine, caller FUN_00628e10).
- Runtime-unvalidated.

## Remaining uncertainty
- Meaning of the +0x9ce mode flag (host vs joiner? re-entry?) is inferred from the delay branch,
  not traced.
- FUN_00629a40 / FUN_00629d00 arg `0` semantics not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00628f00.c`  — untouched decompiler output.
