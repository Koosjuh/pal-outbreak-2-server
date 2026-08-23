# 0x001f0650 snap_rpc_op27_mode_on

| field | value |
|---|---|
| Original address | 0x001f0650 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f0650 |
| Resolved name | snap_rpc_op27_mode_on |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001eedc0
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
fno 0x27, parameterless. Wrapper FUN_001eedc0 sets mode flag 0x37a2a2:=1; op28 clears it (enable/disable pair). Which IOP mode is gated is unknown.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f0650.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
