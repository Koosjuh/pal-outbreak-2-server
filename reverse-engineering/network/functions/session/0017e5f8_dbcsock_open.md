# 0x0017e5f8 dbcsock_open

| field | value |
|---|---|
| Original address | 0x0017e5f8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_0017e5f8 |
| Resolved name | dbcsock_open |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00114ac8, FUN_0017eb20, FUN_0017f158
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Allocates+opens dbcman socket: builds open-descriptor from optional 16B addr, calls dbcman_open(fn0x301, type, type+0x80); records type/in-use in slot (0x277c00 stride0x334) and activates via FUN_0017eb20. type must be 0x40-aligned. Descriptor header[2..4] opaque.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_0017e5f8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
