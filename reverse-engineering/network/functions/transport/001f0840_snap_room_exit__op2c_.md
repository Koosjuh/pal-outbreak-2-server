# 0x001f0840 snap_room_exit (op2c)

| field | value |
|---|---|
| Original address | 0x001f0840 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f0840 |
| Resolved name | snap_room_exit (op2c) |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ef070
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
fno 0x2c = room EXIT, counterpart of op2b. Wrapper FUN_001ef070 clears 0x37a2a6:=0 and discards status. Relevant to exit-room stall parking-lot item.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f0840.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
