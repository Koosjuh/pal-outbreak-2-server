# 0x006233e0 screen_reset_lobby

| field | value |
|---|---|
| Original address | 0x006233e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006233e0 |
| Resolved name | screen_reset_lobby |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00622180
**Callees:** FUN_005ac610, FUN_005ac8a0, FUN_005f4440, FUN_00623600
**Referenced globals:** 0x715298 struct ptr; 0x7152e1 screen-state; 0x7152e0 screen-id; 0x86f838/0x86f830 counters; 0x874f30 lobby block
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam007152e1; uRam007152f1; iRam0086f838

## Behavioral explanation
Screen reset/init handler: reinitializes lobby overlay state (clears 0x874f30 block, sets screen-state 0x7152e1 and mode flags), invokes FUN_00623600 teardown+reinit.

## Notes / uncertainty
Lobby (re)init: sets NET-READY 0x7152f1=1 (consumed by 0x61f9d0), clears 0x874f30 (0xac), runs overlay_init_full FUN_005ac610 (0x54dc block), selects next screen 0x7152e0=0x2c/0x31. func_0x001ee370 net-reset unread.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006233e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
