# 0x0062a8c0 name_entry_kbd_menu

| field | value |
|---|---|
| Original address | 0x0062a8c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062a8c0 |
| Resolved name | name_entry_kbd_menu |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0062a5e0
**Callees:** FUN_005b1420, FUN_005b1460, FUN_005b14b0, FUN_005b8cf0, FUN_005b8da0, FUN_005b9110, FUN_0062ab50
**Referenced globals:** +0x43c/+0x43f dialog flags; 0x6c462a kbd char; 0x6c462b kbd mods
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c462a; bRam006c462b

## Behavioral explanation
Software-keyboard/name-entry state machine (case 0..5) with timers, pad polling and keyboard-char gating (cRam006c462a 'P'/'O'/'+').

## Notes / uncertainty
6-step (substate 0..5) software-keyboard/name-entry tick handler; directional-vs-keyboard input gating (pad masks 0x40004 UP/0x80008 DOWN, glyph sentinels P/O/+, mod 0x22), held-highlight +0x43c, auto-repeat +0x43f, confirm SE 0x4c. No wire. Pad-mask physical mapping and func_0x001b0140 arg meanings inferred, not runtime-traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062a8c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
