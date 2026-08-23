# 0x0062c7b0 dialog_result_branch

| field | value |
|---|---|
| Original address | 0x0062c7b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062c7b0 |
| Resolved name | dialog_result_branch |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0062c350
**Callees:** FUN_005b6900, FUN_005b9110
**Referenced globals:** +0x10b4 result code
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Branches on the dialog result code +0x10b4 (0/1/2/other): re-arms window, plays SE and sets the next +1 sub-state accordingly.

## Notes / uncertainty
Post-dialog result router (child of c350): while +0x10b4==0 ticks dialog runtime; on result routes substate 1->4/aux0/fb5, 2->5/aux0/fb4, else->4/aux3/fb5, SE 0x4c. Meaning of result codes/buttons and aux 0-vs-3 branch not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062c7b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
