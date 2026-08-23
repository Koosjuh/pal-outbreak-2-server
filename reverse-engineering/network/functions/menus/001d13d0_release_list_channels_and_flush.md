# 0x001d13d0 release_list_channels_and_flush

| field | value |
|---|---|
| Original address | 0x001d13d0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d13d0 |
| Resolved name | release_list_channels_and_flush |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001841d0, FUN_001cbae0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sets two channel-slot mappings via FUN_001cbae0(1,7) and FUN_001cbae0(10,1) then flushes via FUN_001841d0.

## Notes / uncertainty
FUN_001cbae0(1,7)+(10,1)+flush = resets exactly 0x1d12c0's channel set. Release-vs-reserve direction inferred (leans release via 0x1d1610 pairing).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d13d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
