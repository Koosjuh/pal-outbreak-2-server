# 0x005f6a20 play_transition_sfx

| field | value |
|---|---|
| Original address | 0x005f6a20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f6a20 |
| Resolved name | play_transition_sfx |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005f6b00, FUN_005f6d20
**Callees:** FUN_005b8cf0, FUN_005b9060
**Referenced globals:** 0x6c517c
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Small switch(param) that fires a sound/cue via FUN_005b8cf0(id) or FUN_005b9060 for transition codes 1/3/4/6/5/7.

## Notes / uncertainty
Maps overlay transition codes 1/3/4-6/5-7 to SFX cues. Dispatch exact; concrete sound identities inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f6a20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
