# 0x001eeb00 snap_state_enter_3_a

| field | value |
|---|---|
| Original address | 0x001eeb00 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eeb00 |
| Resolved name | snap_state_enter_3_a |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c0f40
**Callees:** —
**Referenced globals:** 0x37a298 (mode flag:=0); 0x37a288 (state var:=3); 0x37a2a3 (mode flag:=1)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x37a288; 0x37a298; 0x37a2a3

## Behavioral explanation
State transition: clears flag 0x37a298, sets state-machine var to 3, sets flag 0x37a2a3=1.

## Notes / uncertainty
State-3 (ACTIVE) entry: 0x37a298=0, state=3, 0x37a2a3(active)=1. Byte-identical to bank-B twin 001eee90. Flag roles inferred from set/clear pairing across family.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eeb00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
