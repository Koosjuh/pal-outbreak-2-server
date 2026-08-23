# 0x005fe500 lobby_roomlist_init

| field | value |
|---|---|
| Original address | 0x005fe500 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fe500 |
| Resolved name | lobby_roomlist_init |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f99c0, FUN_005fada0
**Callees:** FUN_005aec20, FUN_005bffa0, FUN_005c02b0, FUN_005c0a00, FUN_005c0f60, FUN_005c2820, FUN_005f4b70
**Referenced globals:** 0x6c4b90 mode(=4); 0x6c4b9e/9f/ba0/ba1 paging; 0x6c4600 selection; 0x6c5514/5518 timers
**Referenced strings:** 0x600de0; 0x600f50; 0x600ff0; 0x601060; 0x601170
**Referenced opcodes:** —
**State vars:** cRam006c4b90 mode

## Behavioral explanation
Initializes/resets the lobby room-list screen: sets mode 0x6c4b90=4, clears paging/selection state, seeds timers, and installs the list widget callbacks.

## Notes / uncertainty
Enter/reset lobby room-list screen: mode 0x6c4b90=4, clears paging/selection, seeds scroll limit 0x1e (0x19 if region flag 0x34363e), page size 0x14, installs 5 list-widget callbacks (0x600xxx). Which builder=which widget by convention only.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fe500.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
