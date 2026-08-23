# 0x00607ac0 txn_substate0_build

| field | value |
|---|---|
| Original address | 0x00607ac0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00607ac0 |
| Resolved name | txn_substate0_build |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00607a10
**Callees:** FUN_00607f70, FUN_00608090, FUN_00618b60
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Txn sub-state 0: advances state, clears flags/+0x454, builds the request node lists via FUN_00607f70 and FUN_00608090.

## Notes / uncertainty
Build stage: advance state 0->1, clear flags req[7]/[8] and ctx+0x454, assemble payload (07f70/08090), push (18b60); returns -1 (in progress). Payload opcode/fields not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00607ac0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
