# 0x005d1e80 lobby_list_activate_dispatch

| field | value |
|---|---|
| Original address | 0x005d1e80 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d1e80 |
| Resolved name | lobby_list_activate_dispatch |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005cf600, FUN_005d1d60, FUN_005d2c20, FUN_005d3930, FUN_005d46a0, FUN_005d47f0, FUN_005d59f0, FUN_005d5b60, FUN_005d5c20, FUN_005d5cc0, FUN_005dc1e0, FUN_0061e730
**Referenced globals:** 0x701068+0x5ffc0 entity array; 0x701078+0x20 selected idx; 0x701078+2/4/5/6 selection state; 0x701068+0x68e78/0x68e84 hover/flag; 0x701068+0x69018 redraw; 0x701070+0x38/0x3a lock
**Referenced strings:** str@0x642e00
**Referenced opcodes:** —
**State vars:** 0x701070+0x38/0x3a; 0x701068+0x69018 redraw

## Behavioral explanation
Central 'click/activate' handler: finds the entity under the cursor and dispatches by entity kind (0x03-0x08,0x0b-0x0d,0x11/0x12) into enter/select/chat/roster handlers.

## Notes / uncertainty
Central click router: gate->bounds->hit-test->dispatch by entity kind. Domain-relevant: kinds 0x06/0x07 call FUN_005dc1e0 = ENTER ROOM (mode arg 5, or 2, or scenario-code-derived {4,3,2}), upstream of transport op26/op2b. dc1e0 arg3 wire-effect not traced; member-sizing/radio loops summarized.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d1e80.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
