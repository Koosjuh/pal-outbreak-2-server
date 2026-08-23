# 0x005af310 ui_sound_is_idle

| field | value |
|---|---|
| Original address | 0x005af310 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005af310 |
| Resolved name | ui_sound_is_idle |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ade20, FUN_005ae2c0, FUN_005b25c0, FUN_005b2bc0, FUN_005b2e40, FUN_005b3070, FUN_005b33f0, FUN_005b3590, FUN_005b4a50, FUN_005f6b00, FUN_005f6d20, FUN_006075e0, FUN_006076c0
**Callees:** FUN_0061e910
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Boolean query: returns true when FUN_0061e910() == 0 (a sound/resource channel is idle/free).

## Notes / uncertainty
Predicate: returns FUN_0061e910()==0 (SFX channel idle). Per-channel vs global scope depends on undecoded callee.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005af310.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
