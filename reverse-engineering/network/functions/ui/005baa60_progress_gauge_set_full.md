# 0x005baa60 progress_gauge_set_full

| field | value |
|---|---|
| Original address | 0x005baa60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005baa60 |
| Resolved name | progress_gauge_dismiss (was: progress_gauge_set_full) |
| Subsystem | ui |
| Relevance | helper |
| Status | reconstructed |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fc0c0
**Callees:** —
**Referenced globals:** 0x006c552c fRam gauge phase/percent
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** fRam006c552c

## Behavioral explanation
Forces the progress gauge into its teardown state by writing phase = `255.0` (bit pattern
`0x437f0000`) to `fRam006c552c`. Because this is `> 200`, the next tick of `progress_gauge_advance`
skips it and the `progress_gauge_cb` render callback takes its `phase >= 200` branch, which frees the
sprite nodes. Net effect: the gauge is dismissed/removed, not merely "set to 100%". (The prior name
"set_full" is misleading — 255 is the sentinel above the 100% full-scale.)

## Input / output
- No parameters, no return.

## Side effects
- `fRam006c552c = 255.0` — sets the teardown sentinel that causes the gauge sprites to self-free on
  their next callback.

## Important branches
None — unconditional store.

## Constants & flags
- `0x437f0000` = float `255.0` — the teardown sentinel (`> 200` band; see `progress_gauge_advance`
  guard and `progress_gauge_cb` `>=200` free path).

## Corrected reconstruction
```c
extern float g_gauge_phase; // 0x006c552c

void progress_gauge_dismiss(void) {
    g_gauge_phase = 255.0f;  // 0x437f0000: > 200 sentinel -> cb frees the gauge sprites
}
```

## Evidence
- Raw decompile: `uRam006c552c = 0x437f0000;` (float 255.0).
- `progress_gauge_cb`: `if (200.0 <= fRam006c552c) FUN_00618c20(); // free node`.
- `progress_gauge_advance` guard `phase <= 200.0` skips the sentinel. Runtime-unvalidated.

## Remaining uncertainty
Whether the caller `FUN_005fc0c0` uses this on success completion or on cancel is not resolved (both
reach the same teardown). Confidence for the mechanism is High; the "dismiss" naming follows from the
cross-referenced free path.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005baa60.c`  — untouched decompiler output.
