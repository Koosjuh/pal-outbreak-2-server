# 0x001eef50 snap_state_enter_5_b

| field | value |
|---|---|
| Original address | 0x001eef50 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eef50 |
| Resolved name | snap_state_enter_5_b |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c2770
**Callees:** FUN_001f07a0
**Referenced globals:** 0x37a288 (state var:=5)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x37a288

## Behavioral explanation
Calls FUN_001f07a0() then sets state var to 5.

## Notes / uncertainty
State-5 (CLOSED) bank-B finalizer: FUN_001f07a0() then state=5. Twin of 001eed60.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eef50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
