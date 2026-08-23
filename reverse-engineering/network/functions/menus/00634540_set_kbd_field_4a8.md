# 0x00634540 set_kbd_field_4a8

| field | value |
|---|---|
| Original address | 0x00634540 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00634540 |
| Resolved name | set_kbd_field_4a8 |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f4be0, FUN_00634550, FUN_006345e0
**Callees:** —
**Referenced globals:** 0x715da8+0x4a8
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715da8+0x4a8

## Behavioral explanation
Stores a value into keyboard state field +0x4a8 (a mode/flag setter).

## Notes / uncertainty
Trivial setter kbd_state+0x4a8=arg (mode/callback/active-field selector inferred; no reader in batch to pin meaning).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00634540.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
