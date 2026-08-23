# 0x001e1dd0 blockpool_init

| field | value |
|---|---|
| Original address | 0x001e1dd0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001e1dd0 |
| Resolved name | blockpool_init |
| Subsystem | initialization |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d4de0
**Callees:** FUN_001e1d88
**Referenced globals:** 0x36d758 arena base
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Zeroes the 52000-byte allocator arena at 0x36d758 and lays down the initial free-block sentinel.

## Notes / uncertainty
Zero-fills 52000-byte (0xcb20) arena at 0x36d758 then installs whole-arena free sentinel via FUN_001e1d88. Backs transport queue/reliable-segment allocations. Assumed one-time init.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001e1dd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
