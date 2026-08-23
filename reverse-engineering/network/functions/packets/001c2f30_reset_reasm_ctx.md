# 0x001c2f30 reset_reasm_ctx

| field | value |
|---|---|
| Original address | 0x001c2f30 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c2f30 |
| Resolved name | reset_reasm_ctx |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001c3250, FUN_001c4960, FUN_001c4d40
**Callees:** FUN_00106b60
**Referenced globals:** 0x368420 reasm-ctx
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x368420

## Behavioral explanation
Zeroes the reassembly/counters block at 0x368420 (0x36842c region).

## Notes / uncertainty
Resets reassembly context 0x368420..0x36844c (memset 0x36842c+0x20, then zero f00/f01/f04/f08); per-field semantics (seq/len/flags) not yet distinguished.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c2f30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
