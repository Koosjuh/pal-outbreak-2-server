# 0x001d1500 init_texture_slots_group1

| field | value |
|---|---|
| Original address | 0x001d1500 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d1500 |
| Resolved name | release_channel_group1_and_flush |
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
Resets channel/texture-slot group 1 and commits. It releases the contiguous slot range `1..15` (`base 1, count 0xf`) through the slot-range primitive `FUN_001cbae0`, then flushes the loader (`FUN_001841d0`). This is the whole-group counterpart to 0x1d13d0 (which resets a subset) — used to clear all of list group 1 before a fresh menu load.

## Input / output
- **Params:** none.
- **Returns:** void.

## Side effects
- Releases channel slots `1..15`; runs a loader flush.

## Important branches
None — straight-line.

## Constants & flags
- `FUN_001cbae0(1, 0xf)` = act on 15 slots from base 1 → channels 1..15.
- Same primitive/direction caveat as 0x1d13d0 / 0x1d1610.

## Corrected reconstruction
```c
void release_channel_group1_and_flush(void)
{
    slot_range_release(1, 0xf);   // channels 1..15
    loader_flush();
}
```

## Evidence
- Raw: `sources/executables/transport-decompile/FUN_001d1500.c` — `FUN_001cbae0(1,0xf); FUN_001841d0();`.
- Same `FUN_001cbae0` + `FUN_001841d0` pattern as 0x1d13d0 and the 0x1d1610 teardown.

## Remaining uncertainty
- Prior name "init_texture_slots_group1" asserted *reserve*; the shared-primitive evidence (0x1d1610 frees exactly what 0x1d1530 filled) points to *release/reset*. Direction remains inferred — renamed to reflect the reset reading but not runtime-proven.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d1500.c`  — untouched decompiler output.
