# 0x005f9540 room_char_select_sm

| field | value |
|---|---|
| Original address | 0x005f9540 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f9540 |
| Resolved name | room_char_select_sm |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f9150
**Callees:** FUN_005b09b0, FUN_005b14b0, FUN_005f8c20, FUN_005f9bb0, FUN_005f9d40, FUN_005f9e50, FUN_005f9f60, FUN_005fc850, FUN_00618b60
**Referenced globals:** 0x6970a0/0x6970a1 (room flags); param+0x908 (selected char/slot); param+0x10 (step)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+0x908; 0x6970a0

## Behavioral explanation
SM on +0x10: character/slot selection inside the joined room — moves selection +0x908 via FUN_005f9bb0 (valid-slot picker) and FUN_005b09b0 cursor, triggers per-choice actions FUN_005f9d40/9e50/9f60, and sends the pick via FUN_005f8c20/FUN_005fc850.

## Notes / uncertainty
In-room config/character-select input SM; selection +0x908, valid-slot snap FUN_005f9bb0, confirm commits via FUN_005f8c20, init defaults from room flags 0x6970a0/a1. Selection-row roles (2..7 scenario/char, 8/9 aux) and pad-mask->button mapping inferred; committed payload delegated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f9540.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
