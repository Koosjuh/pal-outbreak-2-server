# 0x005f8c20 goto_roomlist_substate

| field | value |
|---|---|
| Original address | 0x005f8c20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f8c20 |
| Resolved name | goto_roomlist_substate |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005aec70, FUN_005f8fc0, FUN_005f9540
**Callees:** FUN_005aec20, FUN_005b9110, FUN_00637180
**Referenced globals:** param+0xe/+0xf/+0x10/+0x11 (substate); param+0x443; param+0x992
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+0xe..

## Behavioral explanation
Sets the room-list screen struct into one of four substates (+0xe/+0xf/+0x10/+0x11) by result code param_2 (0-3), re-inits FUN_005aec20, tears down net FUN_005b9110(0x4c), flags +0x443/+0x45c/+0x45d.

## Notes / uncertainty
Result(0..3)->parks lobby_sm=4 with join_step f(result); confirmed param_1=&lobby_state_block(0x6c4b90) since +0xe/+0xf=lobby_sm/screen_major. Msg 0x4c = list re-arm. result->substep semantics runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f8c20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
