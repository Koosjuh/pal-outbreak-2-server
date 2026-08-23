# 0x0061f340 text_field_reset_show

| field | value |
|---|---|
| Original address | 0x0061f340 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061f340 |
| Resolved name | text_field_reset_show |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006231b0, FUN_00625670, FUN_00626e70
**Callees:** —
**Referenced globals:** 0x71530c (redraw mask); 0x715318-0x71531d (text/entry buffer)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x71530c; 0x715318

## Behavioral explanation
Requests draw bit 0x1000 (param==0) or 0x10000000 (else) and zeroes the 6-byte text/entry buffer at 0x715318-1d — reset an input field.

## Notes / uncertainty
Already reconstructed: clears 6-byte buf 0x715318-1d, |=0x1000 (param==0) else 0x10000000. Buffer layout unconfirmed. Left as-is.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061f340.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
