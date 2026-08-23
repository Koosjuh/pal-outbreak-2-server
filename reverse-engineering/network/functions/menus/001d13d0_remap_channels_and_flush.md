# 0x001d13d0 remap_channels_and_flush

| field | value |
|---|---|
| Original address | 0x001d13d0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d13d0 |
| Resolved name | release_list_channels_and_flush |
| Subsystem | menus |
| Relevance | helper |
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
Tears down / resets the channel-slot layout populated by `load_two_archives_into_fixed_channels` (0x1d12c0) and commits the change. It releases two slot ranges — channels `1..7` and channel `10` — via the slot-range release primitive `FUN_001cbae0(base, count)`, then flushes the loader (`FUN_001841d0`) so the releases take effect. The exact `{1..7} ∪ {10}` set mirrors the slots that 0x1d12c0 installs into (1,2,3 and the special slot 10), confirming this is that layout's paired reset.

## Input / output
- **Params:** none.
- **Returns:** void.

## Side effects
- Releases channel slots `1,2,3,4,5,6,7` and `10` in the loader's slot table; runs a loader flush.

## Important branches
None — straight-line.

## Constants & flags
- `FUN_001cbae0(1, 7)` = release 7 slots from base 1 → channels 1..7.
- `FUN_001cbae0(10, 1)` = release 1 slot at channel 10.
- Release-vs-reserve direction inferred from the pairing with the `0x4200`-group teardown 0x1d1610 (`FUN_001cbae0(0x4200, count)`), which frees exactly the slots 0x1d1530 fills — the same primitive here frees exactly the slots 0x1d12c0 fills.

## Corrected reconstruction
```c
extern void slot_range_release(int base, int count); // FUN_001cbae0
extern void loader_flush(void);                       // FUN_001841d0

void release_list_channels_and_flush(void)
{
    slot_range_release(1, 7);    // channels 1..7  (0x1d12c0's 1,2,3 + headroom)
    slot_range_release(10, 1);   // channel 10     (0x1d12c0's "last" slot)
    loader_flush();
}
```

## Evidence
- Raw: `sources/executables/transport-decompile/FUN_001d13d0.c` — `FUN_001cbae0(1,7); FUN_001cbae0(10,1); FUN_001841d0();`.
- Slot set matches 0x1d12c0's install targets; same primitive as 0x1d1610 teardown.

## Remaining uncertainty
- `FUN_001cbae0` direction (release vs reserve) is inferred, not proven; if it is "reserve", this is a *prepare* step rather than a teardown. Either way it configures exactly these channel ranges. Runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d13d0.c`  — untouched decompiler output.
