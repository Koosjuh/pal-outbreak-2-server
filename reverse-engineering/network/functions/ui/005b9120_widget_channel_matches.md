# 0x005b9120 widget_channel_matches

| field | value |
|---|---|
| Original address | 0x005b9120 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b9120 |
| Resolved name | widget_channel_matches |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b9150, FUN_005ba190, FUN_005ba2e0
**Callees:** —
**Referenced globals:** 0x006c4fcd cRam=current channel id
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fcd

## Behavioral explanation
Predicate: returns true when the current channel cRam006c4fcd equals the node's +2 id, or is the wildcard 0x4c ('L'). Used by widget callbacks to gate rendering.

## Notes / uncertainty
Render-gate predicate: current channel == node +2 id, or wildcard 0x4c ('L'). Behavior certain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b9120.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
