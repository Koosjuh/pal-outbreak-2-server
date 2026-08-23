# 0x006235e0 screen_state_set_99

| field | value |
|---|---|
| Original address | 0x006235e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006235e0 |
| Resolved name | screen_state_set_99 |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f6d20
**Callees:** —
**Referenced globals:** 0x7152e1 screen-state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam007152e1

## Behavioral explanation
Sets screen-state byte 0x7152e1 = 0x63 (99) — jumps a screen SM to its exit/cleanup state.

## Notes / uncertainty
Sets global 0x7152e1=99, forcing the active global-SM screen to its exit/abort terminal (-1). External abort trigger from FUN_005f6d20.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006235e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
