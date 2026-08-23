# 0x001c08a0 dns_cache_clear

| field | value |
|---|---|
| Original address | 0x001c08a0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c08a0 |
| Resolved name | dns_cache_clear |
| Subsystem | initialization |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c0b20
**Callees:** FUN_00106b60
**Referenced globals:** 0x35c3f0 dns-cache; 0x35c3e0 cache-idx
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x35c3e0

## Behavioral explanation
Zeroes the 8-entry hostname->IP resolver cache (0x35c3f0, 0x820 bytes) and resets index 0x35c3e0.

## Notes / uncertainty
Zeros 0x820-byte resolver cache 0x35c3f0 + index 0x35c3e0, returns 0. 8x0x104 entry layout inferred, not proven here.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c08a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
