# 0x005da420 ui_update_extent

| field | value |
|---|---|
| Original address | 0x005da420 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005da420 |
| Resolved name | ui_update_extent |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e7e30
**Callees:** FUN_005da650
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Trivial UI wrapper: forwards a point to the viewport max-extent tracker FUN_005da650.

## Notes / uncertainty
One-line thunk to ui_track_max_extent(width,height). No uncertainty.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005da420.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
