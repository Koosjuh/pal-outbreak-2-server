# 0x005d6460 form_dispatch

| field | value |
|---|---|
| Original address | 0x005d6460 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d6460 |
| Resolved name | form_dispatch |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005c9690, FUN_005c9a00
**Callees:** FUN_005d5640, FUN_005d5ba0
**Referenced globals:** 0x701068+0x60dcc counter; 0x701070+0x30 sub-state; 0x701068+0x60dca; 0x701078+2
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+0x30

## Behavioral explanation
Increments a retry counter and dispatches the form via 5640; on failure resets sub-state and opens the dialog (5ba0).

## Notes / uncertainty
One-shot driver of 5640 compose via shared reentry_guard +0x60dcc; success->1, else aborts: substate=0, fail_code +0x60dca=3, opens dialog (5ba0), value=1, ret 2. fail_code meaning and dialog(0) arg (artifact) unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d6460.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
