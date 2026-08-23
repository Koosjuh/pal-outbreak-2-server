# 0x00629d00 ui_alloc_render_record

| field | value |
|---|---|
| Original address | 0x00629d00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00629d00 |
| Resolved name | ui_alloc_render_record |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00628f00, FUN_006290e0, FUN_0062a680, FUN_0062aeb0, FUN_0062bb20, FUN_0062c1d0
**Callees:** FUN_00618ba0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Allocates a UI/render record (FUN_00618ba0) and wires its draw callback to FUN_00629d60 with the room context pointer and a mode byte.

## Notes / uncertainty
Allocates record, installs FUN_00629d60 draw cb with ctx(+0x10) and mode byte(+3); OOM-guarded. Low uncertainty.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00629d00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
