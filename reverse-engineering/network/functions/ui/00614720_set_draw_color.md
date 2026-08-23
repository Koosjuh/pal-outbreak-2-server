# 0x00614720 set_draw_color

| field | value |
|---|---|
| Original address | 0x00614720 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00614720 |
| Resolved name | set_draw_color |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0060f910, FUN_00612ca0, FUN_006130a0, FUN_00613380, FUN_00613530, FUN_006139c0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Alternate draw-element emitter: sets mode 0 (001af0b0) then pushes payload (001af0c0); used by several menu screens.

## Notes / uncertainty
Renamed from draw_element_variant: selects attr slot 0 then loads ARGB via 001af0c0. Constants 0x80808080 enabled / 0x80404040 disabled from 613530. Color role inferred, not runtime-proven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00614720.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
