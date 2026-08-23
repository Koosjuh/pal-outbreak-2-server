# 0x0062f1e0 reply_handler_roster_clear

| field | value |
|---|---|
| Original address | 0x0062f1e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062f1e0 |
| Resolved name | reply_handler_roster_clear |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c0d30
**Referenced globals:** 0x6c79ac roster buffer(0xec0); 0x6c7c2c/3c/50 player-slot fields(4); 0x6c4ba0 substate; 0x6c4b90 phase(==0x0e)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4b90 phase(==0x0e)

## Behavioral explanation
Reply callback (guard cRam006c4b90==0x0e): bumps ba0, zero-fills 0x6c79ac (0xec0), and on status 0 re-seeds up to 4 player slots at 0x6c7c2c/0x6c7c3c/0x6c7c50 via FUN_005c0d30.

## Notes / uncertainty
Room-join reply cb gated on phase 0x6c4b90==0x0e: bumps 0x6c4ba0, clears 0x6c79ac(0xec0), re-seeds 4 roster rows 0x6c7c2c stride 0x3b0 (verified 0/0x3b0/0x760/0xb10) via FUN_005c0d30(id+0x00,name+0x10,state+0x24). FUN_005c0d30 per-row init not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062f1e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
