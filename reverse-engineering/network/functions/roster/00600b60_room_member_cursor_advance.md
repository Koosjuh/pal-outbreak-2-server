# 0x00600b60 room_member_cursor_advance

| field | value |
|---|---|
| Original address | 0x00600b60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00600b60 |
| Resolved name | room_member_cursor_advance |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fede0, FUN_00600200
**Callees:** FUN_005b14b0, FUN_00600aa0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+0x908 selected slot; param_1+0x44c active slot; param_1+0x3f6c compare key; param_1+0x30ac member id

## Behavioral explanation
Advances the selected member slot 0x908 on L/R input (FUN_005b14b0 0x800/0x400/0x200) using next_occupied_member_slot, returning whether the selection actually moved.

## Notes / uncertainty
L/R (0x800/0x400) member cursor mover; writes ctx+0x908 and mirror ctx+0x44c, move SFX; returns moved flag. Two-level fallback and +0x3f6c mode byte transcribed faithfully; gameplay rationale inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00600b60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
