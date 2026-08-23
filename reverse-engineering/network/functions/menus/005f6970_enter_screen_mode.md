# 0x005f6970 enter_screen_mode

| field | value |
|---|---|
| Original address | 0x005f6970 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f6970 |
| Resolved name | enter_screen_mode |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005aedc0, FUN_005b1a30, FUN_005b2260, FUN_005b2bc0, FUN_005b2e40, FUN_005b6070, FUN_005b6900, FUN_005f8060, FUN_005fc6b0, FUN_005fc730, FUN_00617a50, FUN_0062ed30, FUN_0062f3f0
**Callees:** FUN_005b1d10, FUN_00606da0, FUN_00606de0, FUN_00637180
**Referenced globals:** 0x6c4b90 (screen-state block: mode/cursor/flags); 0x6c50f8; 0x874f36; 0x6c550b
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4b90 (mode=6); 0x6c4ba0 (=param)

## Behavioral explanation
Screen/mode transition init: seeds the 0x6c4b90 UI state block (mode=6, cursor=param), calls FUN_00637180 + FUN_005b1d10, and branches to FUN_00606de0 (param==7) or FUN_00606da0 to load the next screen.

## Notes / uncertainty
Central menu transition primitive (13 callers); resets lobby_state_block, screen_id=6, selection=0xffff, mode mirrored to 0x6c4ba0/0x6c550b; mode 7 special (sets 0x874f36, loader FUN_00606de0). Identity of mode 7 not runtime-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f6970.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
