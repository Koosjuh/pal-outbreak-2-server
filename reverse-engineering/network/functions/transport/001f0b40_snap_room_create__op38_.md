# 0x001f0b40 snap_room_create (op38)

| field | value |
|---|---|
| Original address | 0x001f0b40 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f0b40 |
| Resolved name | snap_room_create (op38) |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001ee720
**Callees:** FUN_00109eb8, FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
fno 0x38 = CREATE: stages name string @+0x1c (or zeroed if NULL) + two u32 params @+0x11c/+0x120 (ssize 0x128); returns short handle, -1=fail. Wrapper FUN_001ee720 sets created/owner flag 0x37a2a4:=1. Pair op39 close. Directly relevant to create-room roster work; entity (room vs slot) and param0/param1 meaning inferred, unvalidated at runtime.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f0b40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
