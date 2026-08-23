# 0x0062d730 lobby_state0_area_select

| field | value |
|---|---|
| Original address | 0x0062d730 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062d730 |
| Resolved name | lobby_state0_area_select |
| Subsystem | menus |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0062d640
**Callees:** FUN_005b09b0, FUN_005b14b0, FUN_005f7610, FUN_0062f500
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0xf/+0x10 sub-state; struct+0xc screen-id; struct+0xa index

## Behavioral explanation
Major-state 0 handler (area/room selection): initializes +0xf/+0x10 and builds UI via f500; on input (FUN_005b14b0 0x200/0x10) navigates list, else advances +0xe and loads next screen id from table at +0x1c.

## Notes / uncertainty
Already full: init-latch + 0x200 back / 0x10 ok edge polls + next-screen-id table read. Pad masks and +0x1c table stride inferred by consequence.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062d730.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
