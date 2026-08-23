# 0x001f0bf0 snap_room_close (op39)

| field | value |
|---|---|
| Original address | 0x001f0bf0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f0bf0 |
| Resolved name | snap_room_close (op39) |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001ee770
**Callees:** FUN_001ef3e0, FUN_001ef3f0, FUN_001ef400
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
fno 0x39 = CLOSE/DESTROY, parameterless counterpart of op38 create. Returns short (-1=fail); wrapper FUN_001ee770 clears created/owner flag 0x37a2a4:=0. Whether it targets the caller's own room implicitly is unproven.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f0bf0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
