# 0x00613600 room_name_pw_render

| field | value |
|---|---|
| Original address | 0x00613600 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00613600 |
| Resolved name | room_name_pw_render |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00612d10
**Callees:** FUN_001ae3e0, FUN_006146e0, FUN_006147a0, FUN_00614870, FUN_00616570
**Referenced globals:** ctx+0x4bc (room name buf); ctx+0x6bc (password buf); 0x654100/0x654120 (empty placeholders)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x4bc room name; ctx+0x6bc password

## Behavioral explanation
Renders the room name (ctx+0x4bc, transcoded via FUN_00616570/00614870) and password field (ctx+0x6bc): shows a placeholder string when empty, else masks the password with '*' (capped, '..' overflow).

## Notes / uncertainty
Draws create-panel name (transcode+ellipsis) and password (masked '*', capped 22+'..' at >=25 chars) rows; placeholders when empty. Thresholds/mask bytes exact; placeholder text not fetched.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00613600.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
