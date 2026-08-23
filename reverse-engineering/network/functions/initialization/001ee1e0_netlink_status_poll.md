# 0x001ee1e0 netlink_status_poll

| field | value |
|---|---|
| Original address | 0x001ee1e0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ee1e0 |
| Resolved name | netlink_status_poll |
| Subsystem | initialization |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001ee160, FUN_001eeb50, FUN_001eef00, FUN_001ef0d0, FUN_001ef1c0
**Referenced globals:** 0x0037a298 status/error; 0x0037a290 flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x0037a298 status/error; 0x0037a290 gate

## Behavioral explanation
Link/connection status state machine: gated on status(0x37a298)==0 && 0x37a290==0 && handle!=0, branches on mode param_1 (2/3 vs 1) querying link (FUN_001eeb50/ef0d0/eef00/ef1c0) and latches error codes 1/2/3 into 0x37a298.

## Notes / uncertainty
Already fully reconstructed. Numeric status-code meanings (1/2/3) and link-state==4 are inferred; netstack lib (DEV9/SMAP vs INET) untraced.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ee1e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
