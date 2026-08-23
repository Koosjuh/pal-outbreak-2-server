# 0x001f07f0 snap_room_enter (op2b)

| field | value |
|---|---|
| Original address | 0x001f07f0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f07f0 |
| Resolved name | snap_room_enter (op2b) |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ef040
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
fno 0x2b = room ENTER (named in brief). Parameterless commit-join; wrapper FUN_001ef040 sets in-room flag 0x37a2a6:=1. Pair with op2c exit. Status codes unenumerated.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f07f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
