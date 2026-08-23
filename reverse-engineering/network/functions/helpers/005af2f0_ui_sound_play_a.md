# 0x005af2f0 ui_sound_play_a

| field | value |
|---|---|
| Original address | 0x005af2f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005af2f0 |
| Resolved name | ui_sound_play_a |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acea0, FUN_005ad030, FUN_005addb0, FUN_005ade20, FUN_005ae260, FUN_005b25c0, FUN_005b2bc0, FUN_005b3070, FUN_005b33f0, FUN_005b3590, FUN_005b4a50, FUN_005f6b00, FUN_005f6d20, FUN_005ffbe0, FUN_00606fc0, FUN_00607260, FUN_006076c0, FUN_00617110, FUN_006178a0, FUN_006193e0
**Callees:** FUN_0061e960
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Thin wrapper: calls FUN_0061e960(id,arg,0) — plays/queues a UI sound effect (variant 0).

## Notes / uncertainty
Wrapper: sound_dispatch(id,arg,0). Mode byte 0 vs sibling's 1. Dispatcher FUN_0061e960 internals (mode/arg meaning) not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005af2f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
