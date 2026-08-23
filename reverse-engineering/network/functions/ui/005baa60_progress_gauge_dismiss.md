# 0x005baa60 progress_gauge_dismiss

| field | value |
|---|---|
| Original address | 0x005baa60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005baa60 |
| Resolved name | progress_gauge_dismiss |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fc0c0
**Callees:** —
**Referenced globals:** 0x006c552c fRam=gauge phase
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** fRam006c552c

## Behavioral explanation
Sets gauge phase uRam006c552c = 255.0 (0x437f0000), forcing the bar past-full (triggers teardown in the callback).

## Notes / uncertainty
RENAMED from set_full: writes phase=255.0 (0x437f0000) teardown sentinel >200 that makes cb free the gauge sprites. Success-vs-cancel caller intent open.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005baa60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
