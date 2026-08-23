# 0x005bba20 inroom_subevent_dispatcher

| field | value |
|---|---|
| Original address | 0x005bba20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bba20 |
| Resolved name | inroom_subevent_dispatcher |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005bbb90, FUN_005bbc20, FUN_005bbe00, FUN_005bbea0, FUN_005bbf20, FUN_005bbfc0, FUN_005bc050, FUN_005bc0e0, FUN_005bc110, FUN_005bc1c0, FUN_005bc230, FUN_005bc240, FUN_005bc270, FUN_005bc2a0, FUN_005bc2f0, FUN_005bc350, FUN_005c61b0, FUN_005c7d00
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** 0x13
**State vars:** —

## Behavioral explanation
In-room sub-event dispatcher (dispatch code 0x13): switches on the sub-selector byte at msg+8 (cases 1..0x11) to route room title, member add, ready-state, names, chat, scenario, timer and game-event handlers.

## Notes / uncertainty
op0x13 in-room event demux, switch on sub-selector msg+8 (cases 1..0x11). Cases 1/3/5 confirmed via siblings, 0xe=op0f send; cases 2,4,6-0xd,0xf,0x10 roles inferred from summary and need per-selector passes.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bba20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
