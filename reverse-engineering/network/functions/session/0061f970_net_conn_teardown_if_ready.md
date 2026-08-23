# 0x0061f970 net_conn_teardown_if_ready

| field | value |
|---|---|
| Original address | 0x0061f970 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061f970 |
| Resolved name | net_conn_teardown_if_ready |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0061f9f0, FUN_0061fd70, FUN_00620250, FUN_006205c0, FUN_00620b60, FUN_00620d60, FUN_00622c30
**Callees:** FUN_0061e9c0, FUN_0061ea10, FUN_0061ea40, FUN_0061f0d0
**Referenced globals:** 0x7152f1 ready flag; 0x71530c session flag; 0x715270 state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** bRam007152f1; uRam0071530c; uRam00715270

## Behavioral explanation
If ready-flag 0x7152f1 is set, tears down connection/UI (f0d0/ea10/ea40) and clears session state; returns 1 done / 2 not-ready.

## Notes / uncertainty
Common teardown gate for 7 screen SMs. If ready flag 0x7152f1 bit0 clear -> return 2 (wait); else clear UI (f0d0/ea10/ea40), zero 0x71530c + 0x715270, return 1 (done). Complementary to xfer_state_reset which sets 0x7152f1.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061f970.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
