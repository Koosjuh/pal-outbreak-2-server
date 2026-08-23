# 0x005da500 ui_dialog_state_machine

| field | value |
|---|---|
| Original address | 0x005da500 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005da500 |
| Resolved name | ui_dialog_state_machine |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e7e30
**Callees:** FUN_005da4b0
**Referenced globals:** iRam00701070+0x35: dialog state; iRam00701070+0x33: pending flag; iRam00701070+0x31; iRam00701070+0x57f: input-nonempty flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x35; 0x33; 0x31; 0x57f

## Behavioral explanation
UI dialog/confirm state machine: switch over state 0..8 toggling flags +0x31/+0x33/+0x35 and posting UI events via FUN_005da4b0 (open/confirm/cancel transitions).

## Notes / uncertainty
Confirm/cancel state machine 0..8 over flags +0x31/+0x33/+0x35, posts events; state-1 strcmp(+0x57f,+0x55d)!=0 -> post(4,1). Exact UX intent of strcmp branch uncertain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005da500.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
