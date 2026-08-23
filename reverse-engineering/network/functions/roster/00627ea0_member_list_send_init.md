# 0x00627ea0 member_list_send_init

| field | value |
|---|---|
| Original address | 0x00627ea0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00627ea0 |
| Resolved name | member_list_send_init |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00627d60
**Callees:** FUN_005b7fd0, FUN_00604810, FUN_00618b60, FUN_00627ae0, FUN_00628760
**Referenced globals:** 0x694700 master-roster
**Referenced strings:** —
**Referenced opcodes:** 0x23
**State vars:** —

## Behavioral explanation
Sub-step 0 of the member machine: snapshots current roster count (FUN_00604810 over 0x694700), builds the descriptor list, and sends app opcode 0x23 (member-list request) via FUN_005b7fd0.

## Notes / uncertainty
Case-0 SEND: advances selector, snapshots occupied count via FUN_00604810(0x694700,0x32) into block+8, queues app op 0x23 via FUN_005b7fd0. Descriptor builder FUN_00628760 layout not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00627ea0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
