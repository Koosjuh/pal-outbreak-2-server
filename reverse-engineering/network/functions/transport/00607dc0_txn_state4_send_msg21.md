# 0x00607dc0 txn_state4_send_msg21

| field | value |
|---|---|
| Original address | 0x00607dc0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00607dc0 |
| Resolved name | txn_state4_send_msg21 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00607a10
**Callees:** FUN_005b09b0, FUN_005b14b0, FUN_005b8da0, FUN_005b9110
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Txn sub-state 4: issues FUN_005b8da0(0x21,param+0xb) send, polls 005b14b0(0x10/0x200), retransmit/backoff via counters at +0x18.

## Notes / uncertainty
State-4 phase-2: sends selector 0x21 (payload +0xb), 5-substep reply handling, sets block +0x43f (phase2_ack)/+0x454. Two-phase (0x20 then 0x21) txn. Opcode mapping to create/enter unproven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00607dc0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
