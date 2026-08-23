# 0x005d8930 txn_abort_active

| field | value |
|---|---|
| Original address | 0x005d8930 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d8930 |
| Resolved name | txn_abort_active |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c85d0, FUN_005d5c20, FUN_005e7e30
**Callees:** —
**Referenced globals:** 0x004f694 txn head
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** node+0x104 state; node+0x125 detail

## Behavioral explanation
Walks the txn queue and force-completes every in-flight record (state 4 or 5) to state 6 with result code 7 (aborted), and for state-3 records marks their send object +0x35=1 (cancel).

## Notes / uncertainty
Walks txn list@net+0x4f694: state 4/5 -> completed(6)/result=7 aborted/detail=0; state 3 -> send-obj(+0x118)+0x35 cancel=1; state 0 ends. Corrected callers to FUN_005c85d0/FUN_005d5c20 (FUN_005e7e30 calls the co-located thunk, not this). State enum inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d8930.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
