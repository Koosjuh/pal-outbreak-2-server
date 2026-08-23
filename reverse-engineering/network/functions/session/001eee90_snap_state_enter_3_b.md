# 0x001eee90 snap_state_enter_3_b

| field | value |
|---|---|
| Original address | 0x001eee90 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eee90 |
| Resolved name | snap_state_enter_3_b |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c19e0
**Callees:** —
**Referenced globals:** 0x37a298 (mode flag:=0); 0x37a288 (state var:=3); 0x37a2a3 (mode flag:=1)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x37a288; 0x37a298; 0x37a2a3

## Behavioral explanation
State transition: clears 0x37a298, sets state var to 3, sets 0x37a2a3=1 (duplicate of FUN_001eeb00).

## Notes / uncertainty
State-3 (ACTIVE) entry, byte-identical to 001eeb00 (bank-B path via 001c19e0).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eee90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
