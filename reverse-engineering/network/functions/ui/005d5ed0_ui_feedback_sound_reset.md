# 0x005d5ed0 ui_feedback_sound_reset

| field | value |
|---|---|
| Original address | 0x005d5ed0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d5ed0 |
| Resolved name | ui_feedback_sound_reset |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005cf010, FUN_005cf140
**Callees:** FUN_0061e730, FUN_0061e740
**Referenced globals:** 0x701078+1; 0x701068+0x68e85
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701068+0x68e85

## Behavioral explanation
Helper: plays an on/off UI sound (0061e730/740) per param and resets a couple of menu flags.

## Notes / uncertainty
Plays on/off SFX (61e730/61e740) by param, resets anim_sub +1=0 and dialog_kind 0x68e85=1. Which SFX is on vs off inferred from polarity.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d5ed0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
