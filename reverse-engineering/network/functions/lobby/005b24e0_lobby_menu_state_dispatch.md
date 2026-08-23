# 0x005b24e0 lobby_menu_state_dispatch

| field | value |
|---|---|
| Original address | 0x005b24e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b24e0 |
| Resolved name | lobby_menu_state_dispatch |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acab0
**Callees:** FUN_005b25c0, FUN_005b29b0, FUN_005b2bc0, FUN_005b2e40, FUN_005b3070, FUN_005b33f0, FUN_005b3510, FUN_005b3590, FUN_005b3790, FUN_005b4a50
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0xe screen id; struct+0xf sub-state

## Behavioral explanation
Top-level lobby/menu screen state machine: switches on screen id +0xe (0-9) to the per-screen handlers (init, connect, entry, room-list, char-select, etc.).

## Notes / uncertainty
Renamed from lobby_screen_dispatch (disambiguated from 005acab0). 2nd-level router: switch on ctx+0xe (0-9) to lobby/room sub-screens; case 0=init/handler-install, 2=entry SM (005b2bc0). State names beyond 0/2 inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b24e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
