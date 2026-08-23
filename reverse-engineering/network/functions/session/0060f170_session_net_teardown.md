# 0x0060f170 session_net_teardown

| field | value |
|---|---|
| Original address | 0x0060f170 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0060f170 |
| Resolved name | session_net_teardown |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060f910
**Callees:** —
**Referenced globals:** iRam0035c3d8 (owned-room ptr)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0035c3d8 room-ownership

## Behavioral explanation
Network/session cleanup: if room-owned (iRam0035c3d8!=0) calls func_0x001bf580, then func_0x001bf530/001bf5b0 to release resources.

## Notes / uncertainty
Entry/reinit cleanup: if owned-resource flag 0x35c3d8 set free it (001bf580), then release pair 001bf530/5b0. Whether 0x35c3d8 tracks owned room vs generic alloc inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0060f170.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
