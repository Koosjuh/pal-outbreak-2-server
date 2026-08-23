# 0x005b3b70 can_enter_room_for_mode

| field | value |
|---|---|
| Original address | 0x005b3b70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b3b70 |
| Resolved name | can_enter_room_for_mode |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b3590
**Callees:** —
**Referenced globals:** 0x874f35 cRam00874f35 mode
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x874f35

## Behavioral explanation
Transition predicate: returns 1 if room-entry sub-state (1-3) is allowed for current mode 0x874f35.

## Notes / uncertainty
Room-entry sibling of 0x5b2aa0; same shape but mode 0 never passes (requires in-lobby mode>=1). Logic exact; mode/level meaning inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b3b70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
