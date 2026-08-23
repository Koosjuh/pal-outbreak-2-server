# 0x005cd710 is_screen_state_idle

| field | value |
|---|---|
| Original address | 0x005cd710 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005cd710 |
| Resolved name | is_screen_state_idle |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006088b0
**Callees:** —
**Referenced globals:** 0x701070+0x2e sub-state
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+0x2e

## Behavioral explanation
Predicate: returns true iff the screen sub-state 0x701070+0x2e == 0 (idle).

## Notes / uncertainty
Predicate scr+0x2e==0 (idle). Trivial; full sub-state enum inferred from call sites (0 idle,5 back,8 busy).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005cd710.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
