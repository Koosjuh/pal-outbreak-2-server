# 0x001d4de0 snap_conn_destroy

| field | value |
|---|---|
| Original address | 0x001d4de0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d4de0 |
| Resolved name | snap_conn_destroy |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001e1dd0, FUN_001e3f98
**Referenced globals:** 0x0025b78c conn-ptr (cleared here)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x0025b78c conn-ptr

## Behavioral explanation
Tears down the session: closes the socket (*conn), frees per-module state, and clears the global conn ptr to 0.

## Notes / uncertainty
Destructor/inverse of 46ec: guard param==1 && conn!=0 -> close socket (*conn=+0x00 fd), FUN_001e1dd0 subsys teardown, DAT_0025b78c=0; else -1. Uncertainty: whether 1e1dd0 frees the conn block itself.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d4de0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
