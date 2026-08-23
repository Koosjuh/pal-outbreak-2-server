# 0x0060f910 net_menu_screen_tick

| field | value |
|---|---|
| Original address | 0x0060f910 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060f910 |
| Resolved name | net_menu_screen_tick |
| Subsystem | menus |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00623090
**Callees:** FUN_001af020, FUN_001af0a0, FUN_001b00e0, FUN_001b0100, FUN_0060e060, FUN_0060f170, FUN_006101a0, FUN_006101d0, FUN_00610580, FUN_00610830, FUN_00612b70, FUN_00612ca0, FUN_00612d10, FUN_00613c30, FUN_00614600, FUN_00614720, FUN_00614750, FUN_00614790, FUN_006149d0, FUN_00614b80, FUN_00614b90, FUN_00615430, FUN_006154b0, FUN_006186e0, FUN_006187f0, FUN_00634550, FUN_00636890
**Referenced globals:** iRam0070d1d8 (screen state); iRam0070d1c0 (menu/net context base); iRam003435bc (context alloc); uRam003433b0? via subs; iRam0035b9e0 (net handle)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0070d1d8 screen state; ctx+0x4e message id; ctx+0x20/0x2c sub-SM states

## Behavioral explanation
Top-level per-frame driver for the online lobby/create screen: switch(iRam0070d1d8) inits context/teardown, dispatches to the fetch/join/create sub-SMs (FUN_006101d0/00610580/00610830), maps their return codes to next state+message id, then runs the whole render tree.

## Notes / uncertainty
Rewrote from classified stub to full reconstruction. Central create/join/room-list SM (states 0-9) over ctx 0x70d1c0; delegates to list(006101d0)/join(00610580)/create(00610830) sub-SMs, maps return codes to state+msg id+selectors, runs render tree when state!=3. Message-id table and pad-bit meanings inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060f910.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
