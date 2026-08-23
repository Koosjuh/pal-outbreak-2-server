# 0x005ca560 room_name_commit_transition

| field | value |
|---|---|
| Original address | 0x005ca560 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ca560 |
| Resolved name | room_name_commit_transition |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005d5ba0, FUN_005d8340
**Referenced globals:** 0x701068+0x4f97c work buffer; 0x700fe8 edit flag; 0x701078+2 cursor col; 0x701070+2 step
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x700fe8; 0x701070+2

## Behavioral explanation
If the room/name buffer (FUN_005d8340 on 0x4f97c) has data, clears the edit flag and transitions to step 5 via FUN_005d5ba0.

## Notes / uncertainty
If name buf 0x4f97c non-empty: clear edit flag 0x700fe8, FUN_005d5ba0, cursor=1, step=5. Whether 005d5ba0 also queues a wire op unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ca560.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
