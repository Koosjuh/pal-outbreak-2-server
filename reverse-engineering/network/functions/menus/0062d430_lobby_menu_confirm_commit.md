# 0x0062d430 name_kbd_commit_step

| field | value |
|---|---|
| Original address | 0x0062d430 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062d430 |
| Resolved name | name_kbd_commit_step |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0062d380 (name-entry submachine dispatcher)
**Callees:** FUN_00634ab0 (kbd_input_tick), FUN_00604860 (table_find_by_id), FUN_00637180 (kbd_close_if_flagged), func_0x00106b60 (memset thunk)
**Referenced globals:** 0x694700 persistent member pool (stride 0x38, cap 0x32); 0x6c4610 pad-current mask; 0x6c4618 / 0x6c4620 pad edge/repeat masks
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** text buffer `param_3+0x11`; member scratch `param_1+0x12c2` (0x19e)

## Behavioral explanation
The per-frame "run/commit" step of the name-entry submachine, sibling to the OPEN step
`FUN_0062d3d0`. Each frame it ticks the on-screen keyboard with the current pad state; the keyboard
returns a commit/close code. While still editing (`-1`) it does nothing but the close hook. On a
positive commit (`1`) it takes the entered name at `param_3+0x11`, looks it up in the persistent
member pool `0x694700`, and clears the 0x19e-byte member scratch buffer at `param_1+0x12c2` (resetting
the result/list area for the committed name). Any other code (cancel) returns 0 without closing.

## Input / output
- **param_1** (int -> screen/context): member scratch buffer at `+0x12c2` (0x19e bytes).
- **param_2** (undefined8): unused.
- **param_3** (int -> context): text field at `+0x11` (the name being entered).
- **Returns:** u32 — `1` = handled (still editing OR committed; keyboard advanced/closed);
  `0` = keyboard reported a non-commit, non-active code (cancel) — do not close.

## Side effects
- `kbd_input_tick(param_3+0x11, padCurrent=0x6c4610, padEdge|Repeat = 0x6c4618|0x6c4620)` — advances the
  soft-keyboard, mutating its text/cursor state and returning the commit code (its `+0x32`).
- On commit: `table_find_by_id(0x694700, 0x32, param_3+0x11)` — searches the member pool for the entered id/name.
- On commit: `memset(param_1+0x12c2, 0, 0x19e)` — zero the member/result scratch (0x19e = 414 bytes).
- `kbd_close_if_flagged()` — dismisses the keyboard if its close flag (0x31) is set.
- No packets.

## Important branches
- `code = kbd_input_tick(...)`:
  - `code != -1` (not "still active"):
    - `code != 1` -> `return 0` immediately (cancel; keyboard left as-is, no close hook run).
    - `code == 1` (commit): `table_find_by_id(0x694700, 0x32, name)`; `memset(param_1+0x12c2, 0, 0x19e)`.
  - fall-through (code == -1, i.e. still editing, OR after the commit block): `kbd_close_if_flagged(); return 1`.

## Constants & flags
- `kbd_input_tick` return code enum: `-1` = active/editing; `1` = commit/confirm; other (`0`) = cancel.
- `0x694700` member pool base; `0x32` (50) = scan cap; entry stride 0x38, id at entry `+0x10`.
- `0x12c2` = offset of the member/result scratch in the screen struct (GLOBALS: "member-list buf");
  `0x19e` (414) = its byte length.
- `0x6c4610` pad-current, `0x6c4618` pad-edge, `0x6c4620` pad-repeat (combined edge|repeat passed as arg3).

## Corrected reconstruction
```c
// Name-entry submachine: RUN/COMMIT step. Ticks the on-screen keyboard each frame;
// on commit resolves the typed name against the member pool and clears the result scratch.
uint32_t name_kbd_commit_step(int screen /*param_1*/, uint64_t unused /*param_2*/, int ctx /*param_3*/)
{
    char code = kbd_input_tick((void *)(ctx + 0x11),                 // text buffer
                               g_padCurrent /*0x6c4610*/,
                               g_padEdge /*0x6c4618*/ | g_padRepeat /*0x6c4620*/);
    if (code != -1) {                 // keyboard produced a terminal code
        if (code != 1)
            return 0;                 // cancel: leave keyboard open, report "not done"
        // committed:
        table_find_by_id((void *)0x694700, 0x32, (void *)(ctx + 0x11)); // lookup typed name
        memset((void *)(screen + 0x12c2), 0, 0x19e);                    // clear member/result scratch
    }
    kbd_close_if_flagged();           // dismiss if the keyboard set its close flag
    return 1;
}
```

## Evidence
- Raw: `sources/overlays/overlay-3dat-decompile/FUN_0062d430.c` (size 172).
- Callee records: `00634ab0_kbd_input_tick` (returns commit/close state `+0x32`),
  `00604860_table_find_by_id` (linear search of stride-0x38 pool, id at `+0x10`, returns index or -1),
  `00637180_kbd_close_if_flagged` (clears flag 0x31, deactivates, exit-code 0xff).
- `0x694700` persistent member pool; `0x6c4610/18/20` pad snapshot masks (GLOBALS).
- Runtime-unvalidated.

## Remaining uncertainty
The `table_find_by_id` result is discarded here — its purpose (validate the name exists / find its
slot before a downstream action) is set by the parent SM (`FUN_0062d380`/`FUN_0062d640`), not decoded.
Whether the field is a room title vs a member/search name is unproven — Medium.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062d430.c`  — untouched decompiler output.
