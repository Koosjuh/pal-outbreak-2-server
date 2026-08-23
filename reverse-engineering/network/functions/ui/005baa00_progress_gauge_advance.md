# 0x005baa00 progress_gauge_advance

| field | value |
|---|---|
| Original address | 0x005baa00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005baa00 |
| Resolved name | progress_gauge_advance |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fc0c0
**Callees:** —
**Referenced globals:** 0x006c552c fRam=gauge phase; 0x006c5528 fRam=fill rate
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** fRam006c552c

## Behavioral explanation
Advances the progress gauge: fRam006c552c += rate while <=200, clamping to 100 once reached.

## Notes / uncertainty
phase+=rate while <=200, clamp to 100 at full; leaves >200 teardown sentinel untouched. Behavior fully determined.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005baa00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
