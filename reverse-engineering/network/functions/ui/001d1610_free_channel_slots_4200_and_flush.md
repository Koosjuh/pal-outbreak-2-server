# 0x001d1610 free_channel_slots_4200_and_flush

| field | value |
|---|---|
| Original address | 0x001d1610 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d1610 |
| Resolved name | free_channel_slots_4200_and_flush |
| Subsystem | ui |
| Relevance | unrelated |
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
Frees/re-registers texture slots at base 0x4200 and flushes.

## Notes / uncertainty
FUN_001cbae0(0x4200,count)+flush; strongest evidence FUN_001cbae0=release (undoes 0x1d1530 fill). Caller must pass matching count.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d1610.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
