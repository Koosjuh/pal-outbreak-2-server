# 0x006352e0 kbd_input_toplevel_dispatch

| field | value |
|---|---|
| Original address | 0x006352e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006352e0 |
| Resolved name | kbd_input_toplevel_dispatch |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006300a0, FUN_00630f20, FUN_00634ab0
**Callees:** FUN_00630420, FUN_00630750, FUN_00632330, FUN_00634970, FUN_006353e0, FUN_006355a0, FUN_00635900
**Referenced globals:** 0x715da8 kbd/text-entry state struct
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x30 active; 0x36; 0x2f mode; 0x26 confirm

## Behavioral explanation
Top-level text-input handler: branches on active(0x30)/preedit(0x2f)/flag(0x36) to route a key event to IME-commit, accent-compose, char-append or raw-append paths.

## Notes / uncertainty
Routes confirmed key to IME-flush / accent-compose / append based on +0x30 active,+0x36 ime-commit,+0x2f mode. preedit-mode values other than 0/1/3 not fully enumerated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006352e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
