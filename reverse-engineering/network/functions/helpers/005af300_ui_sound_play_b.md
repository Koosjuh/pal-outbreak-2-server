# 0x005af300 ui_sound_play_b

| field | value |
|---|---|
| Original address | 0x005af300 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005af300 |
| Resolved name | ui_sound_play_b |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ac610, FUN_005ac6f0, FUN_005ade20, FUN_005b2bc0, FUN_005b2e40, FUN_005b3070, FUN_005b33f0, FUN_005b3590, FUN_005b3790, FUN_005b4a50, FUN_005f6b00, FUN_005f6d20, FUN_00606fc0, FUN_00607370, FUN_006076c0, FUN_00617030, FUN_00617270, FUN_006176a0, FUN_00617870, FUN_00617910, FUN_00617a50
**Callees:** FUN_0061e960
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Thin wrapper: calls FUN_0061e960(id,arg,1) — plays/queues a UI sound effect (variant 1).

## Notes / uncertainty
Wrapper: sound_dispatch(id,arg,1). Variant of play_a; mode byte semantics undecoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005af300.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
