# 0x0061f470 redraw_flags_set_bit10000

| field | value |
|---|---|
| Original address | 0x0061f470 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061f470 |
| Resolved name | redraw_flags_set_bit10000 |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00622d60, FUN_00624850, FUN_00625670, FUN_00625ea0, FUN_00626900
**Callees:** —
**Referenced globals:** 0x71530c (UI redraw/visibility mask)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x71530c

## Behavioral explanation
Sets bit 0x10000 in uRam0071530c (show an element).

## Notes / uncertainty
Already reconstructed setter (|=0x10000). Left as-is.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061f470.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
