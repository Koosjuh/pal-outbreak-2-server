# 0x006334f0 commit_predictive_candidate

| field | value |
|---|---|
| Original address | 0x006334f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006334f0 |
| Resolved name | commit_predictive_candidate |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00632330
**Callees:** FUN_006320f0
**Referenced globals:** 0x715da8+0x4c (text buf); 0x715da8+0x47c (candidate); 0x715da8+0x2a (len); 0x715da8+0x2f (mode)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715da8+0x2f; 0x715da8+0x47c

## Behavioral explanation
When a predictive candidate (+0x47c) exists in mode 1, inserts it into the committed text buffer (+0x4c) via FUN_006320f0, updates length, clears predictive state and returns to mode 0.

## Notes / uncertainty
Guard kbd+0x47c!=0 && mode==1: inserts candidate into text buf kbd+0x4c at cursor via FUN_006320f0, advances cursor, clears preview, mode->0.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006334f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
