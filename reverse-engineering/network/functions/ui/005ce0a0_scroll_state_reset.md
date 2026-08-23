# 0x005ce0a0 scroll_state_reset

| field | value |
|---|---|
| Original address | 0x005ce0a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ce0a0 |
| Resolved name | scroll_state_reset |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ce0e0
**Callees:** —
**Referenced globals:** 0x701068+0x68e83 flag; 0x701068+0x68e86 flag; 0x701078+1 repeat flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701068+0x68e83; 0x701068+0x68e86

## Behavioral explanation
Resets scroll/repeat state: clears 0x68e83, sets 0x68e86=1, clears the cursor repeat flag at 0x701078+1.

## Notes / uncertainty
Resets scroll phase: ov+0x68e83=0, ov+0x68e86=1, cur[1]=0. Phase-value animation meaning inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ce0a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
