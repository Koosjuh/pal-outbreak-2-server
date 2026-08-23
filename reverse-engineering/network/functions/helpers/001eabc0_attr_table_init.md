# 0x001eabc0 attr_table_init

| field | value |
|---|---|
| Original address | 0x001eabc0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eabc0 |
| Resolved name | attr_table_init |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d6ee0, FUN_001db7e8
**Callees:** FUN_001069a8
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Initializes an attribute table by writing a zero u16 count into the target buffer.

## Notes / uncertainty
Writes i16 count=0 to buffer. memcpy(dst,src,n) direction confirmed. Trivial.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eabc0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
