# 0x0061f3b0 redraw_flags_set_bit2000

| field | value |
|---|---|
| Original address | 0x0061f3b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061f3b0 |
| Resolved name | redraw_flags_set_bit2000 |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006205c0, FUN_00620d60, FUN_006231b0, FUN_00625670, FUN_00626e70
**Callees:** —
**Referenced globals:** 0x71530c (UI redraw/visibility mask)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x71530c

## Behavioral explanation
Sets bit 0x2000 in uRam0071530c (show an element).

## Notes / uncertainty
Already reconstructed setter (|=0x2000). Element identity unresolved. Left as-is.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061f3b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
