# 0x00607a10 txn_substate_dispatch

| field | value |
|---|---|
| Original address | 0x00607a10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00607a10 |
| Resolved name | txn_substate_dispatch |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00606fc0, FUN_00607260, FUN_00607370
**Callees:** FUN_00607ac0, FUN_00607b10, FUN_00607bd0, FUN_00607cf0, FUN_00607dc0
**Referenced globals:** 0x006c5490 txn-block
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Reliable-request sub-state dispatcher: switch(*param 0-4) into the retransmit/timeout handlers 00607ac0/b10/bd0/cf0/dc0, returns -1 for unknown.

## Notes / uncertainty
switch(major state 0..4) routing; state4 gets lobby_state_block base (apply stage); default -1. Roles of stages 1-3 inferred by position.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00607a10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
