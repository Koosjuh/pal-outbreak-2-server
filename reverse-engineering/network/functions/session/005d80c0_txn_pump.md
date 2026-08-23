# 0x005d80c0 txn_pump

| field | value |
|---|---|
| Original address | 0x005d80c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d80c0 |
| Resolved name | txn_pump |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c8810
**Callees:** FUN_005d7b60, FUN_005d7e00, FUN_005d7f80
**Referenced globals:** 0x004f694 txn head
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** node+0x104 state

## Behavioral explanation
Per-service scan of the txn queue (0x4f694): for state 4 records dispatches to txn_begin_join_roster/txn_begin_enter by subtype 0x10d, and for state 3 records invokes the send vtable (node[0x46]+100) then txn_apply state via txn_recv/reply handler FUN_005d7b60.

## Notes / uncertainty
Outbound driver over queue arena+0x4f694: state 4 dispatches by subtype 0x10d (0x01->txn_begin_enter, 0x02->FUN_005d7f80) & rescans; state 3 fires send vtable[+0x64] then FUN_005d7b60, yields if still sending. FUN_005d7f80 not deep-read.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d80c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
