# 0x001bf170 streambuf_read_ptr

| field | value |
|---|---|
| Original address | 0x001bf170 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001bf170 |
| Resolved name | streambuf_read_ptr |
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
Returns base(+8)+cursor(+4) = current read pointer. Same struct as 0x1bf140/230.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001bf170.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
