# 0x001d0e90 load_demo_bg_motion

| field | value |
|---|---|
| Original address | 0x001d0e90 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d0e90 |
| Resolved name | load_demo_bg_motion |
| Subsystem | rooms (MISCLASSIFIED — actually assets/motion) |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109728 (sprintf), FUN_001cb360 (file loader dispatch), FUN_001d09e0 (grid decode, count variant)
**Referenced globals:** demo motion grid `0x4fa740`; `uRam003435bc` work base
**Referenced strings:** `0x24ce20` = `"data\rom\motion\demo\r%03d\b%02d.bin"`
**Referenced opcodes:** — (NOT a network function)
**State vars:** —

## Behavioral explanation
**Single demo-motion loader, not a "one roster" fetch.** For demo scene `param_1` (`r%03d`) and sub-index
`param_2` (`%02d`), it builds `data\rom\motion\demo\r%03d\b%02d.bin` (the `b`-series demo motion — a background
or secondary-actor set complementing FUN_001d0d50's body/face/head), loads it, and — only if the file produced
bytes — decodes it into the motion-handle grid at `0x4fa740` via FUN_001d09e0 (stride 200, max 8 rows). The
lean single-target sibling of FUN_001d0d50.

## Input / output
- `param_1` : demo scene id → `r%03d`.
- `param_2` : sub-index → `%02d`.
- returns `void`.

## Side effects
- Writes the demo motion grid at `0x4fa740` (2 dim bytes + `0` byte + handle table). Registers/releases motion
  handles (FUN_00188a30/ad0). No packets, no SM transition.

## Important branches
- `if (len > 0)` — decode only when the file loaded non-empty; otherwise the grid is left as-is.

## Constants & flags
- Loader flags `1` → length-returning loader call (FUN_001a0e90 via FUN_001cb360).
- FUN_001d09e0 stride `200`, base `0`, max 8 rows.
- `0x24ce20` = motion path string (ELF read, Confirmed).

## Corrected reconstruction
```c
// data\rom\motion\demo\r%03d\b%02d.bin — demo "b"-series motion (single grid)
void load_demo_bg_motion(int scene /*param_1*/, int take /*param_2*/)
{
    char path[128];
    sprintf(path, "data\\rom\\motion\\demo\\r%03d\\b%02d.bin", scene, take);   // FUN_00109728
    long len = load_file(path, g_motion_work_base, 1, 0);                      // FUN_001cb360
    if (len > 0)
        decode_motion_grid_n(g_motion_work_base, (void*)0x4fa740, len, 200, 0);// FUN_001d09e0
}
```

## Evidence
- ELF string read at 0x24ce20 → `"data\rom\motion\demo\r%03d\b%02d.bin"` (Confirmed).
- Identical load→gate→decode shape as FUN_001d0d50's three arms, single target. Runtime-unvalidated.

## Remaining uncertainty
- Semantic role of the `b`-series (background actor? crowd?) vs the d/hd series — inferred from filename only.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d0e90.c`  — untouched decompiler output.
