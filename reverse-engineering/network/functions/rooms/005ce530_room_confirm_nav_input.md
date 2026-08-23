# 0x005ce530 room_confirm_nav_input

| field | value |
|---|---|
| Original address | 0x005ce530 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ce530 |
| Resolved name | room_confirm_nav_input |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ce4e0, FUN_005d09d0, FUN_005d5c20, FUN_0061e720, FUN_0061e730, FUN_0061e740
**Referenced globals:** 0x701068+0x68e85 phase; 0x701068+0x68e7a result/SFX code; 0x701068+0x4f8a4 buttons; 0x715da8+0x49c keyboard; 0x701078+2 selection; 0x701070+0x2e sub-state; 0x701070+0x2c menu
**Referenced strings:** —
**Referenced opcodes:** 0x07
**State vars:** 0x701068+0x68e85; 0x701068+0x68e7a; 0x701070+0x2e; 0x701070+0x2c

## Behavioral explanation
Input handler for the room confirm/leave dialog (phases 4/5/6 of 0x68e85): on pad it either leaves the room (sends op07 via FUN_005d5c20) or opens the leave sub-screen (FUN_005d09d0), setting a result/SFX code at 0x68e7a; otherwise does normal up/down nav.

## Notes / uncertainty
Room confirm/leave dialog input (phases 4/5/6): confirm/cancel via pad 0x10/0x200 or kbd '('/')' commits selection, opens sub-dialog, or sends op07 leave when in-room (sm+0x2e==8); shared up/down nav with clamp. Result/SFX codes (0x50/0x52/0x3c/0x3d) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ce530.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
