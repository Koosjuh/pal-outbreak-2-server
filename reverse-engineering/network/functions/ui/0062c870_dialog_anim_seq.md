# 0x0062c870 dialog_anim_seq

| field | value |
|---|---|
| Original address | 0x0062c870 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062c870 |
| Resolved name | dialog_anim_seq |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0062c350
**Callees:** FUN_005b8cf0, FUN_005b9060, FUN_005b9110
**Referenced globals:** +0x10b4 result-derived id
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Four-step (case 0..3) window open/close animation timer sequence (FUN_005b9060/8cf0 with id derived from +0x10b4) then returns to idle.

## Notes / uncertainty
4-step aux(param_2[2]) open->hold->finish->re-open dialog anim timer (child of c350); re-open uses result-derived window id (+0x10b4-0x78), initial open FUN_005b9060(0x14,+0x5ec), timer 0x88, SE 0x4c. Base window ids / +0x5ec params not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062c870.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
