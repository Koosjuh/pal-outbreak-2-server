# 0x005add90 screen_obj_init_kind7

| field | value |
|---|---|
| Original address | 0x005add90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005add90 |
| Resolved name | screen_obj_init_kind7 |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f7f30
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Initializes a screen-object struct: tag=7, and clears substate cursors [1]/[0xe..0x11]=0.

## Notes / uncertainty
Widget-header initializer: kind byte(+0x00)=7, clears +0x01/+0xe..+0x11 cursors. Kind byte is the type selector the overlay dispatchers branch on. Meaning of +0x10/+0x11 unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005add90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
