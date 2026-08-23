# 0x001c9850 snap_connect_state_machine

| field | value |
|---|---|
| Original address | 0x001c9850 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c9850 |
| Resolved name | snap_connect_state_machine |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001c08e0, FUN_001c3420, FUN_001c3850, FUN_001c9780, FUN_001ee430
**Referenced globals:** 0x35ccb0=server port; 0x35a714=poll status; 0x35ccb3=session-once flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iVar4+0xd=phase; iVar4+0x1c=socket; iVar4+0x10=timeout ticks; iVar4+0xd8=next phase

## Behavioral explanation
TCP connection-establishment sub-SM: phase 0 init, phase 1 resolve (FUN_001c08e0), phase 2 connect to 0x35ccb0 port (FUN_001c3850), phase 3 poll (FUN_001ee430) with 0x708 timeout and retry.

## Notes / uncertainty
Client TCP connect FSM (conn+0xd phase 0..3: init/resolve/connect/poll). 0x35a714==4 ready, port 0x35ccb0, timeout 0x708, error state conn+0xc=7 with subcodes 1-4 in conn+0xdc. FUN_001c9780 retry-gate and FUN_001c3420 trace effects not decompiled.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c9850.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
