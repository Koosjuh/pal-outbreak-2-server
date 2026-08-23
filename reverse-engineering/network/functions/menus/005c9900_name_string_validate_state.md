# 0x005c9900 name_string_validate_state

| field | value |
|---|---|
| Original address | 0x005c9900 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c9900 |
| Resolved name | name_string_validate_state |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ca6a0, FUN_005d7410, FUN_005de0f0, FUN_005de110, FUN_005dee40
**Referenced globals:** 0x701068+0x68dd0 current-msg id; 0x701068+0x60dc5 name-valid flag; 0x701070+0x37 flag; 0x701070+0x2e sub-state; 0x701070+2 step
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701068+0x60dc5; 0x701070+0x2e; 0x701070+2

## Behavioral explanation
Screen handler that compares the current name/room string (FUN_005d7410) against three constant strings and sets a validity flag (0x60dc5), then advances the step counter.

## Notes / uncertainty
Name-entry frame: draw + strcmp edited string vs 3 reserved consts (0x642cc0/cd0/d00) -> sets flag 0x60dc5, advances step. Valid/invalid POLARITY of 0x60dc5 and const text unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c9900.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
