# 0x0062d4e0 lobby_state_reset_enter

| field | value |
|---|---|
| Original address | 0x0062d4e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062d4e0 |
| Resolved name | lobby_state_reset_enter |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f7f30
**Callees:** FUN_005aec20, FUN_005fe300
**Referenced globals:** 0x6c4b90 lobby phase (=0xe); 0x6c4b91/9e/9f/ba0/ba1 substates; 0x6c45fc/0x6c4600 selected-room
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4b90 phase

## Behavioral explanation
Resets the lobby major-state block at 0x6c4b90 (phase b90=0xe, substates b91/b9e/b9f/ba0/ba1=0), clears 0x6c45fc/4600, then runs FUN_005fe300.

## Notes / uncertainty
Resets lobby block: phase 0x6c4b90=0xe, substates/selected-room (0x6c45fc/4600) cleared, register + list init. 0x6c4b90 is multi-valued screen selector (0xe here vs 4 in FUN_005fe500); full value table not enumerated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062d4e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
