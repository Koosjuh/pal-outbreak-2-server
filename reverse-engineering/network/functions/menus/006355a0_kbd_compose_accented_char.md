# 0x006355a0 kbd_compose_accented_char

| field | value |
|---|---|
| Original address | 0x006355a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006355a0 |
| Resolved name | kbd_compose_accented_char |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006352e0
**Callees:** FUN_00631ff0, FUN_006320f0, FUN_00634880
**Referenced globals:** 0x715da8 state struct; 0x715b78 accent-class
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715b78 accent-class; 0x2a text-len; 0x2c; 0x2f mode; 0x260 preedit-buf; 0x248 status; 0x4c text-buffer

## Behavioral explanation
Combines a pending dead-key accent class (0x715b78) with a base letter into a precomposed Latin-1 char (0xfc=ü,0xf6=ö,...) and appends it to the text buffer.

## Notes / uncertainty
Combines accent class(0x715b78)+base letter into precomposed Latin-1 char, appends, clears preedit(0x260,0xFA)/deadkey state. Full composition table transcribed; certain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006355a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
