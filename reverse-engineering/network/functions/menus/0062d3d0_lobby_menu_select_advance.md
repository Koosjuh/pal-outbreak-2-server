# 0x0062d3d0 open_name_kbd_step

| field | value |
|---|---|
| Original address | 0x0062d3d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062d3d0 |
| Resolved name | open_name_kbd_step |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0062d380 (name-entry submachine dispatcher)
**Callees:** FUN_006371d0 (kbd_set_params_40_38), FUN_006345e0 (open_name_entry)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** submachine struct at `param_2` (+1 step byte, +2 sub-flag); text buffer at `param_3+0x11`

## Behavioral explanation
The "open the on-screen keyboard" step of the name-entry submachine (dispatched by `FUN_0062d380`
alongside its commit sibling `FUN_0062d430`). It advances the submachine step byte, clears a sub-flag,
configures the keyboard widget geometry, then opens the name-entry widget seeded with the current text
and a max length of 15. Because it runs once at step entry, it is the transition that spawns the
soft-keyboard for entering a name (room title / search string) held at `param_3+0x11`.

## Input / output
- **param_1** (undefined8): unused context handle.
- **param_2** (int -> submachine struct):
  - `+1` u8 `step` — incremented (advance to the poll/commit step).
  - `+2` u8 `sub_flag` — cleared to 0.
- **param_3** (int -> screen/context): text field lives at `param_3+0x11`.
- **Returns:** 0 (always; step handlers return a status the dispatcher ignores here).

## Side effects
- `step++`, `sub_flag=0` on the submachine struct.
- `kbd_set_params_40_38(0x42980000, 0x118)` — stores widget config: `+0x40 = 0x42980000` (float 76.0,
  a layout coordinate/width), `+0x38 = 0x118` (280, field id / pixel width).
- `open_name_entry(1, 0, 0xf, param_3+0x11)` — selects layout config #1, caps max length to 15,
  seeds the entry text from `param_3+0x11`, and clears predictive/cursor state.
- No packets.

## Important branches
None — straight-line entry action (no conditionals). The one-shot nature is enforced by the parent
dispatcher advancing `step` so this handler is not re-entered.

## Constants & flags
- `0x42980000` = IEEE-754 float `76.0` — a keyboard layout coordinate/dimension (`+0x40`).
- `0x118` (280) = `+0x38` widget field id / width.
- `open_name_entry(layout=1, seed_mode=0, maxlen=0xf, text=param_3+0x11)` — `0xf` (15) = max name length.

## Corrected reconstruction
```c
// Name-entry submachine: OPEN step. Spawns the on-screen keyboard for the name field
// at (param_3 + 0x11), max 15 chars. Runs once; dispatcher then advances to the commit step.
uint64_t open_name_kbd_step(void *ctx /*param_1*/, name_sm *sm /*param_2*/, char *screen /*param_3*/)
{
    sm->step++;                 // +1  advance submachine step
    sm->sub_flag = 0;           // +2  clear
    kbd_set_params_40_38(0x42980000 /*76.0f*/, 0x118 /*field id/width*/);
    open_name_entry(1,          // layout config #1
                    0,          // seed mode
                    0xf,        // max length = 15
                    screen + 0x11); // text buffer (name)
    return 0;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_0062d3d0.c` (size 88).
- Callee records: `006371d0_kbd_set_params_40_38` (stores arg1->+0x40, arg2->+0x38),
  `006345e0_open_name_entry` (layout=param1*0x30+0x690b90, maxlen cap 0xfa via param3, seed text param4,
  clears entry/predictive/cursor state).
- Sibling `FUN_0062d430` (commit step) consumes the same `param_3+0x11` text buffer. Runtime-unvalidated.

## Remaining uncertainty
Whether the entered name is a room title, password, or search string is not provable from statics
(the buffer is fed to `table_find_by_id` in the commit sibling, suggesting a name→member lookup) —
Medium. `0x42980000`/`0x118` are keyboard-geometry constants, exact roles inferred from the setter's
field offsets.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062d3d0.c`  — untouched decompiler output.
