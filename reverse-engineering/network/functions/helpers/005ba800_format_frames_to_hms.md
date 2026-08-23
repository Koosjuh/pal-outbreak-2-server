# 0x005ba800 format_frames_to_hms

| field | value |
|---|---|
| Original address | 0x005ba800 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ba800 |
| Resolved name | format_frames_to_hms |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ba8d0
**Callees:** —
**Referenced globals:** 0x0034363e cRam=hours-per-day mode
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam0034363e

## Behavioral explanation
Pure time formatter: converts a seconds count into days/hours/minutes (per-day hours 30 or 25 by cRam0034363e), clamping days to 99 and saturating at 0xa4cb62.

## Notes / uncertainty
RENAMED from format_seconds_to_dhm: it is frames->H:M:S using fps 25(PAL,cRam0034363e==1)/30; 0xa4cb62=30*3600*100 saturation proves hours (not days). PAL-flag meaning inferred, not traced to writer.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ba800.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
