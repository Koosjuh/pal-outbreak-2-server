# 0x005ca290 roomlist_scroll_menu_action

| field | value |
|---|---|
| Original address | 0x005ca290 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ca290 |
| Resolved name | roomlist_scroll_menu_action |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ca6a0, FUN_005cce30, FUN_005d0960, FUN_005d09d0
**Referenced globals:** 0x701070+0x2e sub-state; 0x701070+0x2c selection
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+0x2e; 0x701070+0x2c

## Behavioral explanation
State-10 menu-action handler: on selection field 0x2c ==2/==1 invokes distinct actions (FUN_005d0960/FUN_005d09d0); in state-8 runs the roster pass.

## Notes / uncertainty
Room-menu family member: rebuild_room_softmenu (005ca6a0) then dispatch on menu_ctx+0x2e (ACTION=0x0a/SCAN=0x08). ACTION sub-branches on +0x2c: 2=page-forward (005d0960->has_next), 1=page-back (005d09d0->has_prev). +0x2c=2/1 fwd/back inferred from callee pairing, not runtime-observed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ca290.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
