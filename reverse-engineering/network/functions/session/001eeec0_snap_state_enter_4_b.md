# 0x001eeec0 snap_state_enter_4_b

| field | value |
|---|---|
| Original address | 0x001eeec0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eeec0 |
| Resolved name | snap_state_enter_4_b |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c2770
**Callees:** FUN_001ef5c0
**Referenced globals:** 0x37a2a3 (mode flag:=0); 0x37a288 (state var:=4)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x37a288; 0x37a2a3

## Behavioral explanation
Calls FUN_001ef5c0(), clears 0x37a2a3, sets state var to 4.

## Notes / uncertainty
State-4 (CLOSING) cleanup entry: FUN_001ef5c0() then 0x37a2a3=0, state=4. FUN_001ef5c0 exact action (buffer free vs close ctrl) not traced.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eeec0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
