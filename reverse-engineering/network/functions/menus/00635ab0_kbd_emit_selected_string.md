# 0x00635ab0 kbd_emit_selected_string

| field | value |
|---|---|
| Original address | 0x00635ab0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00635ab0 |
| Resolved name | kbd_emit_selected_string |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00630c90, FUN_006313a0, FUN_00634ab0, FUN_00635940
**Callees:** FUN_00631620, FUN_006320f0, FUN_00637140, FUN_00637da0
**Referenced globals:** 0x715da8 state struct; 0x69240b compare const
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x25 cursor-row; 0x4a bit0; 0x2a text-len; 0x248 status; 0x4c text-buffer

## Behavioral explanation
Formats a string from the current selection source (ptr 0xc,+0x20) via FUN_00637da0 and appends it into the text buffer 0x4c, updating length 0x2a and status.

## Notes / uncertainty
Appends selected key's bound string (src+0x20) into edit buffer +0x4c, status 1/5. func_0x0010a4f0 (bounded copy) and +0x3a append-mode inferred; UI text emit, no net.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00635ab0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
