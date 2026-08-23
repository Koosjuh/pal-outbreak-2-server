# 0x00629160 charsel_clamp_index

| field | value |
|---|---|
| Original address | 0x00629160 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00629160 |
| Resolved name | charsel_clamp_index |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00628f70
**Callees:** —
**Referenced globals:** 0x6c555e player-count
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** bRam006c555e

## Behavioral explanation
Clamps/wraps a candidate character-slot index against the current room player count bRam006c555e (values >=8 pass through unchanged).

## Notes / uncertainty
Cursor clamp over [0,bRam006c555e-1] with sentinel 8 (spectator/empty); >=8 passes through. Sentinel exact meaning inferred from usage.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00629160.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
