# 0x001d46a0 snap_session_open

| field | value |
|---|---|
| Original address | 0x001d46a0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d46a0 |
| Resolved name | snap_session_open |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001d46ec
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Thin wrapper: opens a SN@P session by calling the conn-create impl with param_3=0 (no option list).

## Notes / uncertainty
2-arg veneer -> FUN_001d46ec(p1,p2,0) default-options open; impl publishes conn to 0x25b78c. Param meanings depend on impl (not decoded).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d46a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
