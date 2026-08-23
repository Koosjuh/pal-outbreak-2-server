# 0x001c3490 base64_decode

| field | value |
|---|---|
| Original address | 0x001c3490 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c3490 |
| Resolved name | base64_decode |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c3650, FUN_001c3750
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Standard base64 decoder (A-Za-z0-9+/, '=' pad) into an output buffer bounded by param_4.

## Notes / uncertainty
RFC4648 base64 decoder, MSB-first, lenient (invalid chars -> 0xFFFFFFFF ORed in), '=' skipped, out_cap-bounded, returns bytes or -1 on overflow. Codec exact; what is decoded is caller-dependent.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c3490.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
