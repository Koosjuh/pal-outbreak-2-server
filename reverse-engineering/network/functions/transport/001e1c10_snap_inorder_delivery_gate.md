# 0x001e1c10 snap_inorder_delivery_gate

| field | value |
|---|---|
| Original address | 0x001e1c10 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e1c10 |
| Resolved name | snap_inorder_delivery_gate |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d72a8
**Callees:** FUN_001eb2d4, FUN_001eb3b8, FUN_001eb4dc, FUN_001eb858, FUN_001ebd54, FUN_001ebd7c, FUN_001ed664
**Referenced globals:** conn+0x5c expected-seq struct; conn+0x68 ready list
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** conn+0x5c expected msgSeq

## Behavioral explanation
In-order delivery gate: repeatedly scans the reorder list (conn+0x5c+4) for the node whose seq == expected(*(conn+0x5c)), moves it to the ready list (conn+0x68) and increments expected; stops when a gap remains.

## Notes / uncertainty
Reorder release gate: conn+0x5c -> {expected_seq u32; reorder_list@+4}; releases contiguous run to ready queue conn+0x68, incrementing expected each hit, stops at first gap. Matches confirmed reorder anchor; pairs with 001d6dfc consumer.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e1c10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
