# 0x00633350 clear_candidate_state

| field | value |
|---|---|
| Original address | 0x00633350 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00633350 |
| Resolved name | clear_candidate_state |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006345e0, FUN_00634ab0
**Callees:** —
**Referenced globals:** 0x715da8+0x24c (candidate state); 0x715b30 (candidate render grid)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715da8+0x24c

## Behavioral explanation
Zeroes the predictive-candidate state region (state+0x24c, 0x250 bytes) and the candidate render buffer at 0x715b30.

## Notes / uncertainty
memset kbd+0x24c (0x250) + render grid 0x715b30 (0x30). Predictive-text reset.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00633350.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
