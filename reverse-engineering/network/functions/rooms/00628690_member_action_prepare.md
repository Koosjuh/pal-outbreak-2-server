# 0x00628690 member_action_prepare

| field | value |
|---|---|
| Original address | 0x00628690 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00628690 |
| Resolved name | member_action_prepare |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00627d60
**Callees:** FUN_0062b9e0
**Referenced globals:** param+0x443 flag; param+0x1045 action-name; param+0x1055 action-id
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sub-step that stages a room-member action: sets msg opcode to 5, copies the selected member's name/id (+0xefb/+0xf0b) into the action buffer (+0x1045/+0x1055) and clears the 0x25-byte text fields.

## Notes / uncertainty
Stages selected member: obj+0x443=1, task selector=5, copies name/id (+0xefb->+0x1045, +0xf0b->+0x1055, 0x10B) and zeroes two 0x25B text buffers. Returns -1 continue. Specific action (kick/msg) not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00628690.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
