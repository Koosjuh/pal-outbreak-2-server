# 0x005fe620 lobby_menu_router

| field | value |
|---|---|
| Original address | 0x005fe620 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fe620 |
| Resolved name | lobby_menu_router |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acab0
**Callees:** FUN_005aec70, FUN_005f5ec0, FUN_005f5f80, FUN_005fe730, FUN_00603e40, FUN_006052f0, FUN_00628e10, FUN_00628ee0
**Referenced globals:** +1 menu id; +0xf sub-state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +1 menu id

## Behavioral explanation
Top-level lobby menu router: guarded by FUN_005aec70, dispatches on current menu id (+1) to lobby/join/leave/create sub-flows (join=FUN_005f5f80, leave=FUN_006052f0).

## Notes / uncertainty
Top-level lobby menu router guarded by FUN_005aec70; dispatches menu id +1: 0=base(FUN_005fe730),1,3=confirm,6=ENTER/7=LEAVE via FUN_006052f0(1/0),0x0a=JOIN(+0xf=6). ENTER/LEAVE opcode 0x06/0x07 inferred from opcode map, not live trace.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fe620.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
