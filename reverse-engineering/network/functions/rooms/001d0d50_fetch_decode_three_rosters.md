# 0x001d0d50 load_demo_motion_triple

| field | value |
|---|---|
| Original address | 0x001d0d50 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d0d50 |
| Resolved name | load_demo_motion_triple |
| Subsystem | rooms (MISCLASSIFIED — actually assets/motion) |
| Relevance | support |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109728 (sprintf), FUN_001cb360 (file loader dispatch), FUN_001d09e0 (grid decode, 8-row/count variant)
**Referenced globals:** demo motion grids `0x4fc060` (body), `0x4fb3d0` (face), `0x528200` (head); flag `cRam004fa64f`; `uRam003435bc` work base
**Referenced strings:** `0x24cd90`=`"data\rom\motion\demo\r%03d\d%02d.bin"`, `0x24cdc0`=`"data\rom\motion\demo\r%03d\d%02dface.bin"`, `0x24cdf0`=`"data\rom\motion\demo\r%03d\hd%02d.bin"`
**Referenced opcodes:** — (NOT a network function)
**State vars:** `cRam004fa64f` (cleared → re-arms FUN_001d0b00's load-once guard)

## Behavioral explanation
**Demo-cutscene motion loader, not a "three rosters" fetch.** For a demo scene `param_1` (`r%03d`) and actor
sub-index `param_2` (`%02d`), it loads and decodes three motion sets — **body** (`d%02d.bin` → `0x4fc060`),
**face** (`d%02dface.bin` → `0x4fb3d0`), and **head** (`hd%02d.bin` → `0x528200`). Each of the three follows
the same load-then-decode pattern, and each decode is skipped if the file loaded empty (`len <= 0`). Before any
of that it clears `cRam004fa64f`, which is FUN_001d0b00's "already loaded once" latch — re-arming it so the
paired player-motion bank reloads on the next opportunity.

Decode uses FUN_001d09e0 (the FUN_001d0510 count-driven variant, max 8 rows) with a per-row stride of `200`.

## Input / output
- `param_1` : demo scene id → `r%03d` directory.
- `param_2` : actor/take sub-index → `%02d` file number.
- returns `void`.

## Side effects
- Writes three demo motion grids: `0x4fc060`, `0x4fb3d0`, `0x528200` (each: 2 dim bytes + a `0` byte + handle
  table, per FUN_001d09e0). Registers/releases motion handles (FUN_00188a30/ad0).
- **Clears `cRam004fa64f`** (side effect on the FUN_001d0b00 load-once guard).
- No packets, no SM transition.

## Important branches
- Three independent `if (len > 0)` gates — a decode runs only when its file actually produced bytes; a
  missing/empty file leaves that grid untouched (previous handles retained).

## Constants & flags
- Loader flags `1` (not `0x20001`) → FUN_001cb360 still routes to FUN_001a0e90, but returns a **byte length**
  (the `lVar2 > 0` test), i.e. the length-returning call form.
- FUN_001d09e0 args `(…, len, 200, 0)`: `200` = per-row destination stride (`param_3` in FUN_001d0510),
  `0` = base offset. Max 8 rows (FUN_001d0510 outer loop `< 8`).
- Strings at 0x24cd90/0x24cdc0/0x24cdf0 (ELF read, Confirmed).

## Corrected reconstruction
```c
// Demo cutscene motion: body + face + head, for scene r%03d take %02d.
void load_demo_motion_triple(int scene /*param_1*/, int take /*param_2*/)
{
    cRam004fa64f = 0;   // re-arm FUN_001d0b00 load-once latch

    char path[128]; long len;

    sprintf(path, "data\\rom\\motion\\demo\\r%03d\\d%02d.bin", scene, take);      // FUN_00109728
    len = load_file(path, g_motion_work_base, 1, 0);                              // FUN_001cb360
    if (len > 0) decode_motion_grid_n(g_motion_work_base, (void*)0x4fc060, len, 200, 0); // body

    sprintf(path, "data\\rom\\motion\\demo\\r%03d\\d%02dface.bin", scene, take);
    len = load_file(path, g_motion_work_base, 1, 0);
    if (len > 0) decode_motion_grid_n(g_motion_work_base, (void*)0x4fb3d0, len, 200, 0); // face

    sprintf(path, "data\\rom\\motion\\demo\\r%03d\\hd%02d.bin", scene, take);
    len = load_file(path, g_motion_work_base, 1, 0);
    if (len > 0) decode_motion_grid_n(g_motion_work_base, (void*)0x528200, len, 200, 0); // head
}
```

## Evidence
- ELF string reads at 0x24cd90/0x24cdc0/0x24cdf0 → the three demo motion paths (Confirmed).
- FUN_001d09e0 → FUN_001d0510: 8-row count-driven handle decode with stride `param_3`. Runtime-unvalidated.

## Remaining uncertainty
- Grid `0x528200` (head) is also written by FUN_001d0b90 (player PC bank) — shared buffer reuse vs collision
  not runtime-checked.
- Exact meaning of the `200` stride (frames? bytes per row?) inferred from the decoder loop.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d0d50.c`  — untouched decompiler output.
