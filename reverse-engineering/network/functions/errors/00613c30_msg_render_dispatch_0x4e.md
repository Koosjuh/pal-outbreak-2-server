# 0x00613c30 msg_render_dispatch_0x4e

| field | value |
|---|---|
| Original address | 0x00613c30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00613c30 |
| Resolved name | msg_render_dispatch_0x4e |
| Subsystem | errors |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060f910
**Callees:** FUN_001af0a0, FUN_00613da0, FUN_00613e70, FUN_00613f40, FUN_00613fb0, FUN_006140d0, FUN_00614750
**Referenced globals:** ctx+0x4e (message id); ctx+0x23 (variant); ctx+0x29 (blink/anim counter)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x4e message id

## Behavioral explanation
Message/dialog text render dispatcher: switch(ctx+0x4e message id) routes to the appropriate body renderer (FUN_00613da0 plain, FUN_00613fb0(n) prompt variants, FUN_00613e70 special, FUN_00613f40 multi-line, FUN_006140d0 list) between viewport clips.

## Notes / uncertainty
Dialog text dispatcher inside clip push/pop(-16/-32); routes ctx+0x4e to list_full/list_minus3(variant3)/entry/list_with_edit_row(0-3)/address_panel. edit-row arg meaning inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00613c30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
