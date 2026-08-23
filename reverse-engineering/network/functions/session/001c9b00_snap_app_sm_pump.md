# 0x001c9b00 snap_app_sm_pump

| field | value |
|---|---|
| Original address | 0x001c9b00 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c9b00 |
| Resolved name | snap_app_sm_pump |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001c3420, FUN_001c3450, FUN_001c3880, FUN_001c42d0, FUN_001c43c0, FUN_001c4560, FUN_001c46a0, FUN_001c48c0, FUN_001c4c80, FUN_001c4fb0, FUN_001c51a0, FUN_001c5480, FUN_001c5630, FUN_001c5900, FUN_001c5bd0, FUN_001c5ea0, FUN_001c6060, FUN_001c6330, FUN_001c64f0, FUN_001c67b0, FUN_001c69b0, FUN_001c6b90, FUN_001c6dc0, FUN_001c7000, FUN_001c7580, FUN_001c7980, FUN_001c85c0, FUN_001c8ad0, FUN_001c8af0, FUN_001c8b60, FUN_001c8d30, FUN_001c8dd0, FUN_001c8f50, FUN_001c94c0, FUN_001c9780, FUN_001ee430
**Referenced globals:** 0x35a714=poll status; 0x248560/2485b0/2484c0/248510/248600=dispatch match tables + handler fn-ptr array
**Referenced strings:** —
**Referenced opcodes:** 0x10, 0x1e, 0x1f, 0x11, 0x29, 0x2d, 0x37, 0x47, 0x4a, 0x4b, 0x54, 0x55, 0x59
**State vars:** piVar5[3]=topstate; piVar5+0xd=substate; piVar5[4]=timeout; piVar5[0x37]=error

## Behavioral explanation
The central per-tick app-protocol driver: polls the socket (FUN_001ee430), then on ready dispatches ~40 sub-state handlers (create/list/roster/transfer steps) via a big switch on substate +0xd, arming reply-waits with FUN_001c3450.

## Notes / uncertainty
Central per-tick driver: timeout countdown(+0x10), poll (status==4), read/validate (FUN_001c3880), 0x49-entry inbound match table on cur_msg[2/3/4]->0x248600 handlers, then substate switch arming FUN_001c3450 waits + firing op1c/1e/20/26/2b/0d/0a builders; full substate->builder/marker table documented. Uncertainty: 001c3880/9780 contracts, table byte-8 meaning, 8ad0/8af0/8d30 step roles.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c9b00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
