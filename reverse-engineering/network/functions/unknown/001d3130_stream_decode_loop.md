# 0x001d3130 stream_decode_loop

| field | value |
|---|---|
| Original address | 0x001d3130 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d3130 |
| Resolved name | stream_decode_loop |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001a5440, FUN_001a56f0, FUN_001afc20, FUN_001afc40
**Referenced globals:** 0x3435bc scratch base
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Runs a streaming decode loop (FUN_001afc20/40) and copies decoded output on success.

## Notes / uncertainty
Blocking pump-until-ready decode (0x1afc20/40) over scratch 0x3435bc, commits 0xc-byte result from +0x4000 on r>=0. Decoder domain (audio/movie/LZ) and 0xc size inferred. Non-network.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d3130.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
