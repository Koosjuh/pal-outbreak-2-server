# 0x0062cb00 room_action_commit

| field | value |
|---|---|
| Original address | 0x0062cb00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062cb00 |
| Resolved name | room_action_commit |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0062c750
**Callees:** FUN_005b68e0, FUN_005c0e30, FUN_00617a00
**Referenced globals:** +0x10b8 id; +0x42b state=0x1f; 0x62cba0 dialog cb
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Commits the room action: resets +0x10b4, sets +0x9a9=0xff and +0x42b=0x1f, then launches the action dialog (FUN_005c0e30 cb 0x62cba0) with the selected id, or FUN_00617a00 when id==0.

## Notes / uncertainty
Commits roster action via FUN_005c0e30(id,arg,0,cb=0x62cba0); id==0 -> abort to lobby; arg>=2 clamped to 0. Exact wire opcode of the send helper not resolved in slice.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062cb00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
