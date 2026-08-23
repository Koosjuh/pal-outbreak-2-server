# 0x00618530 net_endpoint_open_close_a

| field | value |
|---|---|
| Original address | 0x00618530 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00618530 |
| Resolved name | net_endpoint_open_close_a |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006101d0
**Callees:** FUN_006186e0
**Referenced globals:** param+1 open-state flag; param+5 mode/slot
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** *(param+1) endpoint-open flag

## Behavioral explanation
Opens/tears down a SN@P/libnet transport endpoint via 0x1f4/0x1f5 syscalls, tracking an open flag and mapping the driver return code through the error translator.

## Notes / uncertainty
Two-phase (idle/in-progress) endpoint open+settle over 0x1f4/0x1f5 syscalls, cfg block A=0x6543b0; returns -1 OK / -2 err / -0xf bad slot / xlated. A-vs-B role (listen vs connect) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00618530.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
