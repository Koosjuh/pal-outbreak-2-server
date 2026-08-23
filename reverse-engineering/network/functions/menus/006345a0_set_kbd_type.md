# 0x006345a0 set_kbd_type

| field | value |
|---|---|
| Original address | 0x006345a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006345a0 |
| Resolved name | set_kbd_type |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00634550
**Callees:** —
**Referenced globals:** 0x715da8+0x34 (kbd type)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715da8+0x34

## Behavioral explanation
Sets keyboard type at state+0x34, defaulting to 1 when the requested type is 0 or 6.

## Notes / uncertainty
Writes kbd_state.type(+0x34); 0 and 6 fold to default type 1. Per-index layout-family meaning not enumerated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006345a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
