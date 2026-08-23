# 0x00611fe0 menu_goto_error_prompt

| field | value |
|---|---|
| Original address | 0x00611fe0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00611fe0 |
| Resolved name | menu_goto_error_prompt |
| Subsystem | errors |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00610830
**Callees:** FUN_001b00f0, FUN_006186e0
**Referenced globals:** ctx+0x20/0x21 (state/return-state); ctx+0x4e (message id)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x20 menu state; ctx+0x4e msg id

## Behavioral explanation
Pushes an error/confirm prompt: saves current menu state to +0x21, sets +0x20=param, clears cursor +0x1f, message id +0x4e=1, and signals the UI (thunk_001b00f0).

## Notes / uncertainty
Push error/confirm prompt on ctx iRam0070d1c0: saves state +0x20->+0x21, state=param, cursor+0x1f=0, prompt-active+0x4e=1, ui_notify(001b00f0). One-deep back stack. prompt-id enum unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00611fe0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
