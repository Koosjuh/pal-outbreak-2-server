# 0x001ea804 sha1_final

| field | value |
|---|---|
| Original address | 0x001ea804 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ea804 |
| Resolved name | sha1_final |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001ea8e8
**Callees:** FUN_00106b60, FUN_001e5934, FUN_001e5a00
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Finalizes SHA-1 (pad via transform flag=1), copies the 5-word digest to param_1, byteswaps it (0x14 bytes), and clears the context.

## Notes / uncertainty
Finalize: sig is (out_digest=param_1, ctx=param_2); loops finalize passes, copies 5 words, bswap 0x14, memset ctx head. Two-pass overflow path inferred from core return contract, not traced; the memset clears only 4 bytes (likely compiler-folded).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ea804.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
