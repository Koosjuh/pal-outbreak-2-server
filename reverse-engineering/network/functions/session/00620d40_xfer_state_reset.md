# 0x00620d40 xfer_state_reset

| field | value |
|---|---|
| Original address | 0x00620d40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00620d40 |
| Resolved name | xfer_state_reset |
| Subsystem | session |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b2e40, FUN_00625670
**Callees:** —
**Referenced globals:** 0x715439 xfer state; 0x71543a xfer sub; 0x7152f1 ready flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam00715439; cRam0071543a; uRam007152f1

## Behavioral explanation
Resets the data-transfer sub-state: clears 0x715439/0x71543a and sets ready-flag 0x7152f1=1.

## Notes / uncertainty
Init: clears xfer bytes 0x715439/0x71543a and arms ready flag 0x7152f1=1 (the bit net_conn_teardown_if_ready spins on). Exact. Semantics of the two xfer bytes (state+substate) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00620d40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
