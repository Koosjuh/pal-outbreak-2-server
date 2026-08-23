# 0x001d1530 load_archive_into_channel_slots_4200_return_handles

| field | value |
|---|---|
| Original address | 0x001d1530 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d1530 |
| Resolved name | load_archive_into_channel_slots_4200_return_handles |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001a79b0, FUN_001cb360, FUN_001cb5f0, FUN_001cbc20, FUN_001cbcb0, FUN_001cf2b0
**Referenced globals:** 0x3435bc scratch buffer ptr
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Loads an archive file (FUN_001cb360) and decompresses each entry into texture slots 0x4200+.

## Notes / uncertainty
Reserve 0x4200 group, load 0x24cf40, install ALL records into 0x4200+i, return handles in param_2. param_1 unused in body (stale/context tag).

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d1530.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
