# 0x001d1610 free_texture_slots_4200

| field | value |
|---|---|
| Original address | 0x001d1610 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d1610 |
| Resolved name | free_channel_slots_4200_and_flush |
| Subsystem | ui |
| Relevance | unrelated |
| Status | reconstructed |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001cbae0 (slot_range_release), FUN_001841d0 (loader_flush)
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Teardown for the `0x4200` channel/texture-slot group that `load_archive_into_channel_slots_4200` (0x1d1530) fills. Releases `param_1` slots starting at base `0x4200` via `FUN_001cbae0`, then flushes the loader. Because 0x1d1530 installs one slot per archive record starting at 0x4200 and returns their handles, this frees exactly that set when the caller passes the record count.

## Input / output
- **Params:** `param_1` = slot count to release (same count 0x1d1530 loaded).
- **Returns:** void.

## Side effects
- Releases channel slots `0x4200 .. 0x4200 + param_1 - 1`; runs a loader flush.

## Important branches
None — straight-line.

## Constants & flags
- Base `0x4200` = the texture/archive channel group loaded by 0x1d1530.
- This call site is the strongest evidence that `FUN_001cbae0(base, count)` is a **release** (it undoes 0x1d1530's fill of the identical range).

## Corrected reconstruction
```c
void free_channel_slots_4200_and_flush(int count)
{
    slot_range_release(0x4200, count);   // frees the group 0x1d1530 loaded
    loader_flush();
}
```

## Evidence
- Raw: `sources/executables/transport-decompile/FUN_001d1610.c` — `FUN_001cbae0(0x4200, param_1); FUN_001841d0();`.
- Pairs with 0x1d1530 (`FUN_001cbc20(0x4200)` reserve + per-record install into `0x4200+i`).

## Remaining uncertainty
- Assumes caller passes the matching count; no internal bookkeeping of how many were loaded. Runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d1610.c`  — untouched decompiler output.
