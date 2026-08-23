# 0x001d0fe0 close_op06_join_channel

| field | value |
|---|---|
| Original address | 0x001d0fe0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d0fe0 |
| Resolved name | close_op06_join_channel |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001ccb80
**Referenced globals:** bRam005a9048 channel toggle; cRam00343577 offline-mode
**Referenced strings:** —
**Referenced opcodes:** 0x06
**State vars:** cRam00343577; bRam005a9048

## Behavioral explanation
When online, toggles bRam005a9048 and closes the op06 join channel (toggle*0x80+0x1800) via FUN_001ccb80 with packed routing.

## Notes / uncertainty
Online-only op06 channel close on 0x1800/0x1880 double-buffer toggle; p1/p2/p3 routing-byte roles inferred.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d0fe0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
