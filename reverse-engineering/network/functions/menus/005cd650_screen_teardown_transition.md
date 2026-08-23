# 0x005cd650 screen_teardown_transition

| field | value |
|---|---|
| Original address | 0x005cd650 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005cd650 |
| Resolved name | screen_teardown_transition |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005dfcf0, FUN_005e0050
**Referenced globals:** 0x701e10 flag; 0x701070+0x2e sub-state; 0x701068+0x6901c exit code; 0x700fe0 flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+0x2e; 0x701070+1; 0x701070+2

## Behavioral explanation
Runs render/flush teardown (FUN_005e0050/FUN_005dfcf0) and, based on sub-state 0x2e (5 or 0), transitions the screen back (screen 2, step 0) and sets exit flags.

## Notes / uncertainty
Step-3: flush + scr+0x2e branch (5=back, 0=exit-code ov+0x6901c=3) -> screen 2/step 0; uRam00700fe0=1 ready. Exit-code/transition value 3 meaning unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005cd650.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
