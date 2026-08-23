# 0x0061f3d0 text_field_reset_show_multi

| field | value |
|---|---|
| Original address | 0x0061f3d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061f3d0 |
| Resolved name | text_field_reset_show_multi |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006205c0, FUN_00620d60
**Callees:** —
**Referenced globals:** 0x71530c (redraw mask); 0x715318-0x71531d (text/entry buffer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x71530c; 0x715318

## Behavioral explanation
Zeroes the 0x715318-1d entry buffer and requests draw of several elements (0x71530c|=0x200c000).

## Notes / uncertainty
Already reconstructed: clears same 6-byte buf, |=0x200c000 (bits 14/15/25). Left as-is.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061f3d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
