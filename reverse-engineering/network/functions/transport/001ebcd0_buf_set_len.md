# 0x001ebcd0 buf_set_len

| field | value |
|---|---|
| Original address | 0x001ebcd0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ebcd0 |
| Resolved name | buf_set_len |
| Subsystem | transport |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d6988, FUN_001d72a8, FUN_001ed034, FUN_001ed270, FUN_001ed2c0, FUN_001ed924
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sets the buffer's payload length (u16 at +0xc).

## Notes / uncertainty
Writes payload length +0xc; no internal capacity clamp (caller responsibility).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ebcd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
