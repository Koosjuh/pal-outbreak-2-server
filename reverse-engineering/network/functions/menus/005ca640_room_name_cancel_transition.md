# 0x005ca640 room_name_cancel_transition

| field | value |
|---|---|
| Original address | 0x005ca640 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ca640 |
| Resolved name | room_name_cancel_transition |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005d5b60, FUN_005d8340
**Referenced globals:** 0x701068+0x4f97c work buffer; 0x700fe8 edit flag; 0x701070+1 screen; 0x701070+2 step
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x700fe8; 0x701070+1; 0x701070+2

## Behavioral explanation
If the buffer has data, clears the edit flag and transitions back (screen 2, step 0) via FUN_005d5b60.

## Notes / uncertainty
Cancel mirror of 005ca560: same 0x4f97c gate; clears edit flag, FUN_005d5b60, sub-state=2 step=0. Buffer-content prereq for a cancel is unusual, unverified.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ca640.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
