# 0x005ba800 format_frames_to_hms

| field | value |
|---|---|
| Original address | 0x005ba800 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ba800 |
| Resolved name | format_frames_to_hms (was: format_seconds_to_dhm) |
| Subsystem | helpers |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ba8d0 (clock_widget_cb)
**Callees:** —
**Referenced globals:** 0x0034363e cRam (PAL/50Hz video-mode flag → fps 25 vs 30)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam0034363e

## Behavioral explanation
Pure integer time formatter. Converts a **frame count** into hours / minutes / seconds using the
video frame rate: 25 fps when `cRam0034363e == 1` (PAL / 50Hz), otherwise 30 fps. The name was
previously "seconds→DHM"; the divisor `fps*3600` and the saturation constant prove the input is
frames and the outputs are H:M:S:
- `hours   = frames / (fps*3600)`  (clamped to 99)
- `minutes = (frames - hours*fps*3600) / (fps*60)`
- `seconds = (frames / fps) % 60`

The seconds threshold `0xa4cb62` (10 800 002) is exactly the frame count for 100 hours at 30 fps
(`30*3600*100 = 10 800 000`); at/above it everything saturates to 99:59:59.

## Input / output
- `uint param_1` — frame counter (monotonic, `uRam006c4fb0` at the call site).
- `uint *param_2` — out: hours (0..99).
- `int  *param_3` — out: minutes (0..59).
- `int  *param_4` — out: seconds (0..59).
- Returns: void (results via out-pointers).

## Side effects
Writes the three out-pointers only. Reads global `cRam0034363e`. No other state.

## Important branches
- `param_1 < 0xa4cb62` (below ~100h) → normal decomposition.
  - `cRam0034363e == 1` → `fps = 25` (0x19); else `fps = 30` (0x1e).
  - `hours > 99` → clamp `hours = 99` (but the residual for minutes still uses the un-clamped
    `hours*fps*3600`, preserved below).
- `param_1 >= 0xa4cb62` (saturated) → `hours=99, minutes=0x3b(59), seconds=0x3b(59)`.

## Constants & flags
- `0x1e = 30` fps (NTSC/60Hz default).
- `0x19 = 25` fps (PAL/50Hz; selected by `cRam0034363e == 1`). [inferred: PAL video-mode flag]
- `0xe10 = 3600`, `0x3c = 60` — seconds/hour and seconds/minute (and minutes/hour) factors.
- `0xa4cb62 = 10 800 002` — saturation frame count (~100h @30fps).
- `99`, `0x3b = 59` — output clamps.

## Corrected reconstruction
```c
// cRam0034363e: 1 = PAL/50Hz (25fps), else NTSC/60Hz (30fps).  [inferred meaning]
extern u8 g_is_pal_0034363e; // 0x0034363e

void format_frames_to_hms(uint frames, uint *out_h, int *out_m, int *out_s) {
    if (frames < 0xa4cb62) {
        int fps = (g_is_pal_0034363e == 1) ? 25 : 30;

        uint hours = frames / (fps * 3600);
        int  secs_accounted_by_hours = hours * fps * 3600;   // computed BEFORE the clamp
        if (hours > 99) hours = 99;

        int minutes = (int)(frames - secs_accounted_by_hours) / (fps * 60);
        int seconds = ((int)frames / fps) % 60;

        *out_h = hours;
        *out_m = minutes;
        *out_s = seconds;
    } else {
        *out_h = 99;      // saturate
        *out_m = 59;      // 0x3b
        *out_s = 59;      // 0x3b
    }
}
```

## Evidence
- Raw decompile: `iVar1 = 0x1e; if (cRam0034363e=='\x01') iVar1 = 0x19;` then `param_1/(iVar1*0xe10)`
  for days-slot, `(param_1-rem)/(iVar1*0x3c)`, `(param_1/iVar1)%0x3c`.
- `0xa4cb62 == 30*3600*100 + 2` fixes the input as frames and the top field as hours (not days).
- 25 vs 30 fps = the PAL/NTSC field-rate split; `cRam0034363e` is the video-mode flag. [inferred]
- Sole caller `clock_widget_cb` sprintfs the three outputs into an on-screen HUD. Runtime-unvalidated.

## Remaining uncertainty
The PAL-flag meaning of `cRam0034363e` is inferred from the 25/30 split (not traced to its writer).
The pre-clamp residual for `minutes` is faithfully preserved even though `hours>99` can only occur in
the saturating branch in practice.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ba800.c`  — untouched decompiler output.
