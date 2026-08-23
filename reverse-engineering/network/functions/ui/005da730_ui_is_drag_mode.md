# 0x005da730 ui_is_drag_mode

| field | value |
|---|---|
| Original address | 0x005da730 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005da730 |
| Resolved name | ui_is_active_mode |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005d8ea0, FUN_005d95f0, FUN_005d96a0, FUN_005d9790
**Callees:** —
**Referenced globals:** iRam00701070+0x30: current UI input mode
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x30

## Behavioral explanation
Read-only predicate over the current UI input mode (+0x30, set by `ui_set_input_mode`). Returns 1 when the mode is in the "active" set {1,2,4,5}, else 0. This is exactly the same partition `ui_set_input_mode` writes into the +0x34 active-flag, so this function is the recomputed-on-demand equivalent. Callers (widget draw/emit helpers) use it to gate interactive rendering (e.g. highlight/drag affordances). Note the name `ui_is_drag_mode` was tentative; "active/interactive mode" is more accurate since it covers modes 1,2,4 in addition to 5.

## Input / output
- No parameters.
- Returns `undefined4`: 1 if `+0x30 ∈ {1,2,4,5}`, else 0.

## Side effects
- None (pure read).

## Important branches
- `cVar1 = +0x30`; result defaults to 1.
- `if (cVar1 != 5)`: then `if (cVar1==4 || cVar1==2 || cVar1==1) result = 1; else result = 0;`.
- Net: returns 1 for {1,2,4,5}; 0 for everything else (notably mode 3 and 0 are excluded — matching `ui_set_input_mode`).

## Constants & flags
- Active/interactive mode set {1,2,4,5} (identical to the +0x34 flag computed in FUN_005d9e30).

## Corrected reconstruction
```c
// ui_block base = *iRam00701070
int ui_is_active_mode(void)
{
    char mode = *((char *)iRam00701070 + 0x30);   // +0x30
    if (mode == 5) return 1;
    if (mode == 4 || mode == 2 || mode == 1) return 1;
    return 0;
}
```

## Evidence
- Raw decompile: `sources/overlays/overlay-3dat-decompile/FUN_005da730.c`.
- Mode set {1,2,4,5} matches the active-flag partition in FUN_005d9e30 (`ui_set_input_mode`), cross-corroborating the classification.
- Runtime-unvalidated (static only).

## Remaining uncertainty
- Whether callers treat the result specifically as "drag allowed" vs a broader "interactive" gate is not fully resolved; renamed to `ui_is_active_mode` to avoid over-claiming "drag".

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005da730.c`  — untouched decompiler output.
