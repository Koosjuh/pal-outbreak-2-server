# 0x00606720 lobby_conn_post_connect

| field | value |
|---|---|
| Original address | 0x00606720 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00606720 |
| Resolved name | lobby_conn_post_connect |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006063c0
**Callees:** —
**Referenced globals:** sRam0070cdc8 (state); uRam006c5520/uRam007012b0 (host cfg); uRam0035a6f4 (socket); uRam0070cdca (timeout)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** sRam0070cdc8

## Behavioral explanation
State-3 step: advances state, refreshes the host config string, arms the socket (func_0x001c0530) and sets a long (0x708) response timeout.

## Notes / uncertainty
Pipeline state-3 single-shot: state++ (->4), refresh host string, arm socket for session send (func_0x001c0530 fd), set 0x708(1800)-tick reply timeout. Exact SN@P payload of func_0x001c0530 + state 4/5 stage behavior unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00606720.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
