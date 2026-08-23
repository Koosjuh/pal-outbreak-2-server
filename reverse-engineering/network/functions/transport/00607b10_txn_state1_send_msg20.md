# 0x00607b10 txn_state1_send_msg20

| field | value |
|---|---|
| Original address | 0x00607b10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00607b10 |
| Resolved name | txn_state1_send_msg20 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00607a10
**Callees:** FUN_005b7fd0
**Referenced globals:** 0x008744f8 count
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam008744f8

## Behavioral explanation
Txn sub-state 1: 0x15-tick timer, on entry issues FUN_005b7fd0(0x20,...,count) send; advances or branches to state 3 on flag+4.

## Notes / uncertainty
State-1 of reliable-txn SM (dispatcher FUN_00607a10 switches major_state 0-4, passes lobby_state_block 0x6c4b90). Arms 21-tick RTT timer + sends transport selector 0x20. Selector 0x20 not proven to be a SN@P app opcode; +0x454 named pending_ack by inference.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00607b10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
