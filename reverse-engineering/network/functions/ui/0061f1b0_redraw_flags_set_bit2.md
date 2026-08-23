# 0x0061f1b0 redraw_flags_set_bit2

| field | value |
|---|---|
| Original address | 0x0061f1b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061f1b0 |
| Resolved name | redraw_flags_set_bit2 |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0061f9f0, FUN_0061fd70, FUN_00622d60, FUN_00624850, FUN_00625190
**Callees:** —
**Referenced globals:** 0x71530c (UI redraw/visibility mask)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x71530c

## Behavioral explanation
Sets bit 0x2 in uRam0071530c (mark an element visible/dirty).

## Notes / uncertainty
mask |= 0x2 (non-destructive OR) — mark secondary element dirty. Element identity of bit0x2 inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061f1b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
