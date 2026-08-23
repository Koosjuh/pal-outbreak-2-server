# 0x005af1a0 sprite_frame_event

| field | value |
|---|---|
| Original address | 0x005af1a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005af1a0 |
| Resolved name | sprite_frame_event |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ace00, FUN_005f7800, FUN_0062d5e0
**Callees:** FUN_005c7020, FUN_005c71d0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x146a frame-event flag

## Behavioral explanation
On a pending frame-event (+0x146a), clears it and dispatches to one of two frame-event handlers (FUN_005c7020/FUN_005c71d0) selected by param_2 (e.g. sound/effect on frame change).

## Notes / uncertainty
Edge-consumes pending frame event (+0x146a), dispatches FUN_005c7020 (param2==0) or FUN_005c71d0 (else). Exact handler semantics not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005af1a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
