# 0x005fe800 lobby_screen_init_state

| field | value |
|---|---|
| Original address | 0x005fe800 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fe800 |
| Resolved name | lobby_screen_init_state |
| Subsystem | lobby |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fe730
**Callees:** FUN_00618b60
**Referenced globals:** +0x97d/+0x97e error flags; 0x6c5497/98/99 cursor/select flags; 0x6c550e mode; +0x984/+0x988 timers
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c5498/5499 selection; cRam006c550e mode

## Behavioral explanation
Init step of the lobby base screen: advances sub-state (or error page 4), resets selection/cursor flags (0x6c5497-99) and screen timers.

## Notes / uncertainty
Screen enter/init: advances substate (+0xf++) or jumps to error page (=4) per +0x97d/+0x97e; seeds selection flags 0x6c5497/98/99 from mode 0x6c550e; arms timers +0x984=0x1e/0x19(region 0x34363e) and +0x988=0x14. Which concrete screen the ctx drives unknown; constants exact.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fe800.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
