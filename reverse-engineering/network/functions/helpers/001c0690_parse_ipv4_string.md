# 0x001c0690 parse_ipv4_string

| field | value |
|---|---|
| Original address | 0x001c0690 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c0690 |
| Resolved name | parse_ipv4_string |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c08e0
**Callees:** FUN_00102678, FUN_0010a050
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Parses a dotted 'a.b.c.d' string into a packed 32-bit address (validates <=4 digits/dots); returns 0 on malformed.

## Notes / uncertainty
Dotted-quad -> packed a-in-low-byte (d<<24|c<<16|b<<8|a); validates digit-group<=3 and dots<=3, no per-octet range check. atoi=FUN_00102678, strlen=FUN_0010a050. Host vs net order left to caller.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c0690.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
