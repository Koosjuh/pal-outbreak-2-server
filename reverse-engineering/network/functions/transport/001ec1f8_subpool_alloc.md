# 0x001ec1f8 subpool_alloc

| field | value |
|---|---|
| Original address | 0x001ec1f8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ec1f8 |
| Resolved name | subpool_alloc |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d5288, FUN_001d5378, FUN_001d5ae4, FUN_001d6988, FUN_001d72a8, FUN_001e16b4, FUN_001e3a3c
**Callees:** FUN_001eb2d4, FUN_001eb2fc, FUN_001eb33c, FUN_001eb434
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x60/0x66/0x6c low-water; +0x70/0x72/0x74 high-water; +0x3c/0x44/0x4c alloc counters; +0x54/0x58 starvation counters

## Behavioral explanation
Allocates a buffer from the 3-tier pool sized to param_3: picks the smallest tier whose MTU (0x5e/0x64/0x6a header-adjusted) fits, dequeues a node, tracks the low-water mark, bumps starvation counters, and latches the high-water flag when a tier drains past its watermark.

## Notes / uncertainty
Tier alloc sized to param_3; param_4 picks order (0=largest-first,!=0=best-fit), param_5=0 bypasses watermark latch. Sets latch (eb33c) when tier drains below high-water. -0x1f3c none-fit, -0x1b56 tier-empty retry. Core of the op49/enter-back watermark gate.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ec1f8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
