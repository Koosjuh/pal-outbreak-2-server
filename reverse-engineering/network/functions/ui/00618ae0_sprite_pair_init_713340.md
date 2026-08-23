# 0x00618ae0 sprite_pair_init_713340

| field | value |
|---|---|
| Original address | 0x00618ae0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00618ae0 |
| Resolved name | sprite_pair_init_713340 |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ac610, FUN_005ac6f0
**Callees:** —
**Referenced globals:** 0x713340 sprite/actor struct
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Zeroes and initializes a 0xa8-byte on-screen sprite/actor struct at 0x713340 with default coords/scale sentinels.

## Notes / uncertainty
Renamed from sprite_actor_init. memset(0x713340,0,0xa8)=two adjacent 0x54 sprite records (0x713340/0x713394); seeds anim ids 0/1, white color, tex handle -74, part idx 0. 0xa8=2*0x54 proven; offsets cross-confirmed vs draw/animate.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00618ae0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
