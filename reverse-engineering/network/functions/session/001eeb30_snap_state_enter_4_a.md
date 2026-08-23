# 0x001eeb30 snap_state_enter_4_a

| field | value |
|---|---|
| Original address | 0x001eeb30 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eeb30 |
| Resolved name | snap_state_enter_4_a |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c2770
**Callees:** —
**Referenced globals:** 0x37a2a3 (mode flag:=0); 0x37a288 (state var:=4)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x37a288; 0x37a2a3

## Behavioral explanation
State transition: clears flag 0x37a2a3, sets state-machine var to 4.

## Notes / uncertainty
State-4 (CLOSING) no-cleanup entry: 0x37a2a3=0, state=4. Pairs with 001eeec0 (same + FUN_001ef5c0 cleanup). Graceful-vs-abort split unconfirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eeb30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
