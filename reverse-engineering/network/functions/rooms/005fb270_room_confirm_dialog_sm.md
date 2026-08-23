# 0x005fb270 room_confirm_dialog_sm

| field | value |
|---|---|
| Original address | 0x005fb270 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fb270 |
| Resolved name | room_confirm_dialog_sm |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fb060
**Callees:** FUN_005b1420, FUN_005b1460, FUN_005b14b0, FUN_005b2470, FUN_005b8cf0, FUN_005b8da0, FUN_005b9110, FUN_005fb670
**Referenced globals:** cRam006c462a/bRam006c462b button glyph; +0x43c/+0x43f/+0x45a dialog flags; +0x996 flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x11 dialog sub-state; +0x16 timer

## Behavioral explanation
Confirm/cancel dialog SM for enter/create: reads button glyph cRam006c462a ('P'/'O'/'+'), issues the network action (FUN_005b1420/1460), handles timeouts and rollback.

## Notes / uncertainty
Yes/no confirm dialog + async enter/create commit SM (+0x11 states 0-6); param_2 0=join/!=0=create selects msgs (0xac/0xab/0xad/0xa3/0xa4). Commit via func_0x001b4f40, poll func_0x001b4f70 (-1 err/0 ok/1 busy). The async driver's exact transport opcode (op2b/op26) not resolved in this slice.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fb270.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
