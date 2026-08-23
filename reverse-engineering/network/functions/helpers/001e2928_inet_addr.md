# 0x001e2928 inet_addr

| field | value |
|---|---|
| Original address | 0x001e2928 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e2928 |
| Resolved name | inet_addr |
| Subsystem | helpers |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d46ec, FUN_001d9678, FUN_001db7e8
**Callees:** FUN_00102678, FUN_00109eb8, FUN_0010b6f0
**Referenced globals:** 0x25b7b0 '.' delimiter
**Referenced strings:** "." (delimiter table at 0x25b7b0)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Parses a dotted-decimal IP string into a packed 32-bit big-endian address (four FUN_0010b6f0 tokenizations on '.').

## Notes / uncertainty
Dotted-decimal parse via strtok('.')+atoi x4 -> a|b<<8|c<<16|d<<24 (in_addr byte order). No input validation.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e2928.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
