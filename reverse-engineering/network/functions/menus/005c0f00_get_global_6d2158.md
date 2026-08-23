# 0x005c0f00 get_global_6d2158

| field | value |
|---|---|
| Original address | 0x005c0f00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c0f00 |
| Resolved name | get_current_area_index (get_global_6d2158) |
| Subsystem | menus |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b57a0, FUN_005b57e0, FUN_005b5820, FUN_005b5860, FUN_005b58a0, FUN_005b58e0, FUN_005b5930, FUN_005b5970, FUN_005b5f60, FUN_00601060, FUN_0062eff0 (11 UI readers)
**Callees:** —
**Referenced globals:** 0x6d2158 (`uRam006d2158`) — current area index (u16)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Out-parameter accessor: writes the u16 global 0x6d2158 into `*param_1` and returns 0. Per GLOBALS
and the create pump, 0x6d2158 is the **current area/lobby index** (published by the create pump as
`uRam006d2158 = FUN_005bf1e0(2)` on room-create commit, and by the enter pump), so this is the
canonical "which area am I in" getter used throughout the room/lobby UI screens.

## Input / output
- **Params:** `param_1` — pointer to a u16 receiving the value. **Returns:** `undefined8` 0.
- **Reads:** 0x6d2158.

## Side effects
- Writes `*param_1`. No global mutation.

## Important branches
- None.

## Constants & flags
- 0x6d2158 — current area index (paired with 0x6d215a per-area count in GLOBALS).

## Corrected reconstruction
```c
// Read the current area/lobby index into the caller's u16.
u64 get_current_area_index(u16 *out /*param_1*/)
{
    *out = g_current_area_index /*0x6d2158*/;
    return 0;
}
```

## Evidence
- Raw decompile: `*param_1 = uRam006d2158; return 0;`.
- 0x6d2158 written by create pump `FUN_005c3490` (`uRam006d2158 = FUN_005bf1e0(2)`) and tagged
  "current area idx" in GLOBALS; 11 UI callers consume it read-only.

## Remaining uncertainty
- None material for behavior; the precise unit (raw area id vs list slot) follows whatever
  `FUN_005bf1e0(2)` returns. Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c0f00.c`  — untouched decompiler output.
