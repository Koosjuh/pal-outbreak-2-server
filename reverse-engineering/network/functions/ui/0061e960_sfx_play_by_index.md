# 0x0061e960 sfx_play_by_index

| field | value |
|---|---|
| Original address | 0x0061e960 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061e960 |
| Resolved name | sfx_play_by_index |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005af2f0, FUN_005af300, FUN_006205c0, FUN_00620b60, FUN_00620d60, FUN_00624850, FUN_00624c70, FUN_00625190, FUN_00625670, FUN_006265f0, FUN_00626900, FUN_00626e70, FUN_00627400, FUN_00627540
**Callees:** —
**Referenced globals:** 0x669c30 (SE handle table)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Plays a sound/audio sample selected by param index from table DAT_00669c30 via extern 0x1b3b00 (menu SE trigger).

## Notes / uncertainty
Menu SE trigger: table[0x669c30][idx] -> ext 0x1b3b00(voice, id, param/2); signed /2 idiom confirmed; scalar-arg semantics (vol/pan/pitch) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061e960.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
