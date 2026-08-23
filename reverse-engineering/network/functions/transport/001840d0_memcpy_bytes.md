# 0x001840d0 memcpy_bytes

| field | value |
|---|---|
| Original address | 0x001840d0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001840d0 |
| Resolved name | memcpy_bytes |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001801b0, FUN_001d2bd0, FUN_001d3b40
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
Forward byte-granular memcpy(dst,src,n); no overlap/alignment handling. Used by request serialiser 0x001801b0. Unambiguous.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001840d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
