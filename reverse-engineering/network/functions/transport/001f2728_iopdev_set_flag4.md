# 0x001f2728 iopdev_set_flag4

| field | value |
|---|---|
| Original address | 0x001f2728 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001f2728 |
| Resolved name | iopdev_set_flag4 |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001d4380
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Local-only: block[index]+0x04 = value(0..1); bounds index<count, value<=1. Returns 0/-0xb/-0xc. Flag meaning unknown.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001f2728.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
