# 0x001f0890 snap_room_transfer (op2d)

| field | value |
|---|---|
| Original address | 0x001f0890 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f0890 |
| Resolved name | snap_room_transfer (op2d) |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ef130
**Callees:** FUN_00109eb8, FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
fno 0x2d = room TRANSFER (named). rsize 0x128: copies ~0x100B block @+0x1c to param_1 plus two u32 @+0x11c/+0x120 to param_2/param_3. Blob length (0x100) and trailing-word meaning inferred.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f0890.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
