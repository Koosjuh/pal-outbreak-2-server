# 0x006038f0 emit_display_list_line

| field | value |
|---|---|
| Original address | 0x006038f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006038f0 |
| Resolved name | emit_display_list_line |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00602700
**Callees:** —
**Referenced globals:** 0x6c553a display-line counter
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Appends one formatted line node to the display list: writes selector param_2, copies the string into the node, bumps global line counter cRam006c553a, returns the next node (+0x40 stride).

## Notes / uncertainty
Emits one 0x80-byte display-list node (u16 selector@+0, text@+2), strcpy w/ self-copy guard, bumps line count 0x6c553a, returns next node. Stride cross-confirmed by 0x00603940. Corrected stride to 0x80 bytes.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006038f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
