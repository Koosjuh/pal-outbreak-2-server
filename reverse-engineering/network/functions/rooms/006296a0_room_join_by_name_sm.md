# 0x006296a0 room_join_by_name_sm

| field | value |
|---|---|
| Original address | 0x006296a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006296a0 |
| Resolved name | room_join_by_name_sm |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00628e10
**Callees:** FUN_005af3c0, FUN_005af3e0, FUN_005af400, FUN_005b0cd0, FUN_005b1420, FUN_005b1460, FUN_005b8cf0, FUN_005b8da0, FUN_005b9110, FUN_00604860, FUN_006049b0, FUN_0061ded0, FUN_006278e0
**Referenced globals:** 0x694700 master-roster; param+0xefb name; param+0xf0b id; param+0x45a flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Room-join sub-machine (cases 0-10): finds the target member in master roster 0x694700 by name/id (FUN_00604860 + memcmp), opens a confirm dialog, commits via FUN_006049b0, and re-syncs the display roster (FUN_006278e0).

## Notes / uncertainty
UPGRADED from classified: 11-state member-join-by-name. Finds in pool 0x694700 (find base,count=0x32,key; entries at 0x694710 stride 0x38), memcmp id, inserts via 006049b0, async commit-event wait 0061ded0, resync 006278e0, raises roster-dirty ctx+0x45a. This is the local roster-insert path (create-blocker relevant). 006049b0 insert policy undecoded; efb/f0b name/id ordering inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006296a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
