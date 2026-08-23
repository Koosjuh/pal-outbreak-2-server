# 0x00614ad0 modal_text_dialog_poll

| field | value |
|---|---|
| Original address | 0x00614ad0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00614ad0 |
| Resolved name | modal_text_dialog_poll |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00610830
**Callees:** FUN_00634ab0, FUN_00637180
**Referenced globals:** iRam0070d1c0 (+0x54,+0x58); uRam0070d1c8 (busy flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam0070d1c8; iRam0070d1c0+0x54

## Behavioral explanation
Polls the modal op (634ab0): -1=error / 1=confirmed (copies buf back to *(+0x54)) returns done; 0=pending sets busy flag.

## Notes / uncertainty
Tri-state poll (-1 cancel/1 confirm+writeback to *(+0x54)/0 pending sets busy 0x70d1c8); pairs with 6149f0. Input-state globals 3433b8/3433b0 roles unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00614ad0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
