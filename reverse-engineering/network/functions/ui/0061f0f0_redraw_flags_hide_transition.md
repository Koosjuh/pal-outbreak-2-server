# 0x0061f0f0 redraw_flags_hide_transition

| field | value |
|---|---|
| Original address | 0x0061f0f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061f0f0 |
| Resolved name | redraw_flags_hide_transition |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0061d6a0, FUN_0061f9f0, FUN_0061fd70, FUN_00620250, FUN_006205c0, FUN_00620d60, FUN_00622d60, FUN_00623be0, FUN_00624850, FUN_00625190, FUN_00625ea0, FUN_00627540
**Callees:** —
**Referenced globals:** 0x71530c (UI redraw/visibility mask); 0x71531e/0x71531f (transition flags)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x71530c; 0x71531e; 0x71531f

## Behavioral explanation
Clears given bits from uRam0071530c; for masks 0x200/0x200000 also sets transition bits (0x800000/0x1000000) and toggles 0x71531e/1f — hide-with-transition of a UI element.

## Notes / uncertainty
mask &= ~param; for param 0x200/0x200000 also arms animated hide (0x71531e=0,0x71531f=1, |=0x800000/0x1000000). Bit wiring exact; panel identity inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061f0f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
