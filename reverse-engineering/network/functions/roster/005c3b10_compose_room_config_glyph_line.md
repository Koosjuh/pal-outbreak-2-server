# 0x005c3b10 compose_room_config_glyph_line

| field | value |
|---|---|
| Original address | 0x005c3b10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c3b10 |
| Resolved name | compose_room_config_glyph_line |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005c4600
**Callees:** FUN_005bf1e0, FUN_005c2ad0, FUN_005c2ae0, FUN_005c2e90, FUN_005c3c40, FUN_005c4f00
**Referenced globals:** 0x6cc044 (player-slot bytes); 0x6d2296 (cast count); 0x6fb76b (display target, via caller)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Builds the room detail/roster display block at param_1 (0x6fb76b): reads the scenario sub-record, gathers the active player-slot bytes (0x6cc044) into a stack buffer, then emits two cast/name sections via FUN_005c3c40.

## Notes / uncertainty
Renamed: composes room-detail config line (player-count/difficulty) as glyph tiles via FUN_005c3c40, NOT member-roster rows. Template record (0x3c) + slot array (0x6cc044) identities inferred; full control flow + glyph blitter preserved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c3b10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
