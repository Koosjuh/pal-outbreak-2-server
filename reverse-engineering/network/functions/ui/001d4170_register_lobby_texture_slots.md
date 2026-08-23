# 0x001d4170 register_lobby_texture_slots

| field | value |
|---|---|
| Original address | 0x001d4170 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d4170 |
| Resolved name | register_lobby_texture_slots |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001841d0, FUN_001cbae0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Registers the lobby texture-cache slot ranges (0x4000/0x4019/0x4018/0x4100) and flushes.

## Notes / uncertainty
Reserves 4 cache ranges (0x4000x0x18, 0x4019x4, 0x4018x1, 0x4100x1) then finalizes via FUN_001841d0. Purpose of the two single slots (0x4018/0x4100) unconfirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d4170.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
