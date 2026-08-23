# 0x00613aa0 optional_string_render

| field | value |
|---|---|
| Original address | 0x00613aa0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00613aa0 |
| Resolved name | optional_string_render |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00612d10
**Callees:** FUN_006146e0, FUN_00614870
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Draws either a fallback string (param_2) when the buffer at param_1 is empty, or the transcoded buffer contents (FUN_00614870, width param_5) at (param_3,param_4).

## Notes / uncertainty
Value-or-placeholder: empty src -> draw fallback; else transcode via 0x614870(width param_5) and draw. 0x614870 exact semantics inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00613aa0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
