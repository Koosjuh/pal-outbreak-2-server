# 0x00616c40 room_scene_state_dispatch

| field | value |
|---|---|
| Original address | 0x00616c40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00616c40 |
| Resolved name | room_scene_state_dispatch |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acab0
**Callees:** FUN_005aec70, FUN_00616d30, FUN_00617030, FUN_00617110, FUN_00617230, FUN_00617270, FUN_006173c0, FUN_006176a0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xe major-state (0,1,2,3,4,0xa,0xb)

## Behavioral explanation
Per-tick dispatcher for the room scene: on major-state byte +0xe routes to phase handlers 0..4,0x0a,0x0b (setup/countdown/select/broadcast/finalize), gated by FUN_005aec70.

## Notes / uncertainty
Verified line-for-line: gate 005aec70==0 then dispatch scene+0xe {0 setup,1 enter,2 broadcast-selects,3,4,0xa finalize,0xb leave}. Phases 3/4 roles and gate polarity inferred, not runtime-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00616c40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
