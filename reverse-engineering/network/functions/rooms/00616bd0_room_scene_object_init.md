# 0x00616bd0 room_scene_object_init

| field | value |
|---|---|
| Original address | 0x00616bd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00616bd0 |
| Resolved name | room_scene_object_init |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005aec70
**Callees:** FUN_005aec20, FUN_005b1d10, FUN_005b9110, FUN_00637180
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0(type)=5; +0x443=2

## Behavioral explanation
Constructor for the multiplayer room/scene object: sets type byte=5, clears header/flags, zeroes the 0xec0-byte net-state region at +0x1f5c, and calls sub-init helpers.

## Notes / uncertainty
Constructor for room-scene object (type=5): clears +0xe..+0x11 state quad, sets +0x443=2, memset(+0x1f5c,0,0xec0) net buffer, runs 4 sub-inits. Roles of FUN_005aec20/5b1d10/5b9110/00637180 and the 0x4c selector inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00616bd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
