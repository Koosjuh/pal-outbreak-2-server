# 0x005b16c0 input_held

| field | value |
|---|---|
| Original address | 0x005b16c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b16c0 |
| Resolved name | input_held (was: menu_item_available_for_context) |
| Subsystem | menus |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b0cd0, FUN_005b0f00, FUN_005b1190
**Callees:** —
**Referenced globals:** 0x6c4610 `g_padHeld` (buttons currently down / level state); 0x6c462a `g_softKey` (active soft-key code)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4610; 0x6c462a

## Behavioral explanation
Level (held) button predicate — the "is button X currently down" sibling of `input_pressed` (0x5b14b0). Identical bit→soft-key decode ladder, but tests the **held** pad word `g_padHeld` (0x6c4610) instead of the edge/repeat words. Used by `cursor_nav_grid` (0x5b1190) after the auto-repeat delay expires to decide whether to emit a repeat move: press fires once via `input_pressed`, then hold sustains via `input_held`.

The earlier name "menu_item_available_for_context" and the label "capability/permission bitmask" were mis-classifications: 0x6c4610 is the held-button mask, and the ASCII values ('(' ')' 'J'..'R') are the same soft-key codes decoded by `input_pressed`, not menu-context chars.

## Input / output
- `uint param_1` — button bitmask to test.
- returns `undefined4` — 1 if that button is currently held (or its soft-key is active), else 0.

## Side effects
None.

## Important branches
- `(g_padHeld & param_1) != 0` → return 1 (button physically down).
- else fall into the same 12-way decode → compare `g_softKey` to the button's code → 1 on match.
- no match → 0.

## Constants & flags
Same button-bit → soft-key map as 0x5b14b0 (0x10→'(' … 0x100→';'). No `0xf000f` repeat mask here — level state is unfiltered.

## Corrected reconstruction
```c
extern u32 g_padHeld;   // 0x6c4610 — buttons currently down (level)
extern u8  g_softKey;   // 0x6c462a

// Returns 1 if logical button `mask` is currently held.
u32 input_held(u32 mask)
{
    if ((g_padHeld & mask) != 0)
        return 1;

    if (mask & 0x10)      return g_softKey == '(';
    if (mask & 0x200)     return g_softKey == ')';
    if (mask & 0x40004)   return g_softKey == 'P';
    if (mask & 0x80008)   return g_softKey == 'O';
    if (mask & 0x10001)   return g_softKey == 'R';  // UP
    if (mask & 0x20002)   return g_softKey == 'Q';  // DOWN
    if (mask & 0x800)     return g_softKey == 'N';
    if (mask & 0x400)     return g_softKey == 'K';
    if (mask & 0x80)      return g_softKey == 'M';
    if (mask & 0x40)      return g_softKey == 'J';
    if (mask & 0x8000)    return g_softKey == ':';
    if (mask & 0x100)     return g_softKey == ';';
    return 0;
}
```

## Evidence
- Raw `FUN_005b16c0.c`: `(uRam006c4610 & param_1)==0` guard (line 11) then the byte-for-byte identical soft-key ladder shared with 0x5b14b0.
- Usage in `cursor_nav_grid` (0x5b1190 lines 55/60): called only on the auto-repeat path after the 0x6ca080 delay expires — the classic edge-then-held repeat idiom, pinning 0x6c4610 as the held mask.
- Runtime-unvalidated.

## Remaining uncertainty
- Whether 0x6c4610 is strictly "held" vs "held-or-repeat" is inferred from the repeat idiom; not confirmed by a live read.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b16c0.c`  — untouched decompiler output.
