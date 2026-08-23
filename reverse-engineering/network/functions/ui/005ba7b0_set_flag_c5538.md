# 0x005ba7b0 set_flag_c5538

| field | value |
|---|---|
| Original address | 0x005ba7b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ba7b0 |
| Resolved name | set_ui_dirty_flag_c5538 |
| Subsystem | ui |
| Relevance | helper |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers (29):** FUN_005b25c0, FUN_005b2bc0, FUN_005b2e40, FUN_005b3070, FUN_005b33f0, FUN_005b3510, FUN_005b3590, FUN_005b3cb0, FUN_005b3ed0, FUN_005b41b0, FUN_005b45f0, FUN_005f62e0, FUN_005f8340, FUN_005fba80, FUN_005fc850, FUN_00601760, FUN_006018d0, FUN_006020e0, FUN_00602230, FUN_00604af0, FUN_00605430, FUN_00607f70, FUN_006178a0, FUN_00617bb0, FUN_006193e0, FUN_00628760, FUN_00629a40, FUN_0062b670, FUN_0062cd20
**Callees:** —
**Referenced globals:** 0x006c5538 uRam (UI flag, set to 1)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c5538

## Behavioral explanation
Trivial setter: writes `1` to the global byte `uRam006c5538`. Called from 29 sites — the same
family of screen-init / spawn functions that also call `sprite_slot_alloc` (`FUN_00618ba0`) — so the
flag is set when a UI screen or widget group is (re)built. It is a one-way "raise" (never cleared
here); some consumer elsewhere reads and resets it. Most consistent reading: a **UI-dirty / redraw-
requested** (or "screen active") latch.

## Input / output
- No parameters, no return (void).

## Side effects
- `uRam006c5538 = 1`.

## Important branches
None — unconditional single store.

## Constants & flags
- `1` — the raised state of the flag.

## Corrected reconstruction
```c
// Raised by ~29 screen/widget spawn sites; consumer clears it elsewhere.
// [inferred] role: UI-dirty / redraw-requested latch (a.k.a. "screen active").
extern u8 g_ui_dirty_c5538; // 0x006c5538

void set_ui_dirty_flag_c5538(void) {
    g_ui_dirty_c5538 = 1;
}
```

## Evidence
- Raw decompile: single store `uRam006c5538 = 1; return;`.
- Caller set overlaps heavily with `sprite_slot_alloc` spawners → tied to UI (re)build. The consumer
  and clear-site are not in this function; role is inferred, not proven. Runtime-unvalidated.

## Remaining uncertainty
Exact meaning of the flag (redraw request vs. input-consumed vs. screen-active) is unproven; would
need the reader/clear site. Confidence held at Medium.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ba7b0.c`  — untouched decompiler output.
