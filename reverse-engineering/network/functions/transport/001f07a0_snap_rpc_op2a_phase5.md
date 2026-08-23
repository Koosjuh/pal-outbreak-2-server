# 0x001f07a0 snap_rpc_op2a_phase5

| field | value |
|---|---|
| Original address | 0x001f07a0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f07a0 |
| Resolved name | snap_rpc_op2a_phase5 |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001eef50
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
fno 0x2a, parameterless. Wrapper FUN_001eef50 advances SNAP phase var 0x37a288:=5 (parallels op29->2). Concrete phase-5 milestone unknown.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f07a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
