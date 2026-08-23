# 0x0062b020 name_entry_kbd_menu2

| field | value |
|---|---|
| Original address | 0x0062b020 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062b020 |
| Resolved name | name_entry_kbd_menu2 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0062a5e0
**Callees:** FUN_005b1420, FUN_005b1460, FUN_005b14b0, FUN_005b8da0, FUN_005b9110
**Referenced globals:** +0x43c/+0x43f dialog flags; 0x6c462a kbd char
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c462a; bRam006c462b

## Behavioral explanation
Second name/keyboard-entry state machine, near-identical to FUN_0062a8c0 (window id -0x88); case 5 clears a roster slot (+0x1044 stride 0x25) instead of committing.

## Notes / uncertainty
Sibling of a8c0; steps 1-4 identical. Diffs: step0 window id 0xff88 (vs 0xff86); step5 memsets one 0x25-byte entry-slot record at +0x1044+row*0x25 instead of confirm. 0x25 slot layout not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062b020.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
