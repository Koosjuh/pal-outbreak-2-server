# 0x0062c580 name_entry_kbd_menu3

| field | value |
|---|---|
| Original address | 0x0062c580 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062c580 |
| Resolved name | name_entry_kbd_menu3 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0062c350
**Callees:** FUN_005b1420, FUN_005b1460, FUN_005b14b0, FUN_005b8cf0, FUN_005b9110
**Referenced globals:** +0x43c/+0x43f/+0x45a dialog flags; 0x6c462a kbd char
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c462a; bRam006c462b

## Behavioral explanation
Another software-keyboard/pad-poll entry state machine (case on +2) with cursor and window flags at +0x43c/+0x43f/+0x45a.

## Notes / uncertainty
Third keyboard-entry variant, driven on aux param_2[2] not substate; reached via FUN_0062c350. Confirm lights highlight (deferred commit); cancel forks on held flag; extra latch +0x45a cleared on repeat; close window 0x34. +0x45a purpose unverified.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062c580.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
