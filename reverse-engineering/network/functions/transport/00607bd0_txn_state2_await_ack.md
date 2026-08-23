# 0x00607bd0 txn_state2_await_ack

| field | value |
|---|---|
| Original address | 0x00607bd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00607bd0 |
| Resolved name | txn_state2_await_ack |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00607a10
**Callees:** FUN_005b09b0, FUN_005b14b0
**Referenced globals:** 0x008744f8 count; 0x00874f33 flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam008744f8

## Behavioral explanation
Txn sub-state 2: retransmit with countdown at +0x18, polls completion via FUN_005b14b0(0x10/0x200), triggers send func_0x001b0140(1/2), packs list via 005b09b0.

## Notes / uncertainty
State-2 await-ack: polls response class 0x10 (primary->done, ret 0) vs 0x200 (alternate->jump state4); carries terminal codes 0/0xfffffffe. 0x10 vs 0x200 wire meaning unproven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00607bd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
