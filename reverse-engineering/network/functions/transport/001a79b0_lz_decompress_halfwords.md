# 0x001a79b0 lz_decompress_halfwords

| field | value |
|---|---|
| Original address | 0x001a79b0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001a79b0 |
| Resolved name | lz_decompress_halfwords |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001a0eb0, FUN_001a1750, FUN_001cb7f0, FUN_001d1050, FUN_001d1110, FUN_001d12c0, FUN_001d1410, FUN_001d1530
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Missed lower network stack (DNAS/HTTP/socket/DNS/Avetcp) — pending deep reconstruction.

## Notes / uncertainty
LZSS half-word decompressor: 16-bit MSB-first control words; literal on 0, match on 1 with 5-bit len(bits11-15, 0=>extended len in next hword) and 11-bit offset(bits0-10); offset==0 => zero-fill/terminate. Extended-length bias and exact terminator convention untested.

## Raw decompilation
`sources/executables/netstack-decompile/FUN_001a79b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
