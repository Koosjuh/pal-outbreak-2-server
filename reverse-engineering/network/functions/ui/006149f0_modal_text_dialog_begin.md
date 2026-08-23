# 0x006149f0 modal_text_dialog_begin

| field | value |
|---|---|
| Original address | 0x006149f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006149f0 |
| Resolved name | modal_text_dialog_begin |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00610830
**Callees:** FUN_006345e0, FUN_006371d0
**Referenced globals:** iRam0070d1c0 (+0x54 result ptr,+0x58 work buf)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0070d1c0+0x54; iRam0070d1c0+0x58

## Behavioral explanation
Starts a modal prompt/operation: memsets work buf iRam+0x58, stores result ptr(+0x54), copies message, sets timeout 300, dispatches action code 8/9/10 per param_1.

## Notes / uncertainty
Opens modal text/soft-keyboard dialog: clears 0x200 buf +0x58, stores target +0x54, variants 8/9/10 by param_1; codes 8/9/10 semantics and 66.0f arg unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006149f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
