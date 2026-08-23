# 0x00632ce0 profanity_filter_apply

| field | value |
|---|---|
| Original address | 0x00632ce0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00632ce0 |
| Resolved name | profanity_filter_apply |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f4be0, FUN_005f97c0, FUN_00634ab0
**Callees:** FUN_00632d20
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Runs the bad-word censor over entered text twice (pass 1 then pass 0) via FUN_00632d20.

## Notes / uncertainty
Two-call wrapper over censor_bad_words(text,1)/(text,0). The 1/0 pass flag's exact effect is unconfirmed because the callee decompile drops param_2; unrelated to net protocol.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00632ce0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
