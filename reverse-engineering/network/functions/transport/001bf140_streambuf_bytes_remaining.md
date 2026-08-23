# 0x001bf140 streambuf_bytes_remaining

| field | value |
|---|---|
| Original address | 0x001bf140 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001bf140 |
| Resolved name | streambuf_bytes_remaining |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001caf60
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Returns filled(+0xc)-cursor(+4) = unread bytes of the netstack stream buffer. Field roles corroborated by FUN_001bf230/170; offsets exact, names inferred.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001bf140.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
