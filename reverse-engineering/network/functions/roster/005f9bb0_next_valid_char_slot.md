# 0x005f9bb0 next_valid_char_slot

| field | value |
|---|---|
| Original address | 0x005f9bb0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f9bb0 |
| Resolved name | next_valid_char_slot |
| Subsystem | roster |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f9540
**Callees:** —
**Referenced globals:** 0x6970f4 (member count); 0x6970a0/a1 (room flags); 0x6947e8 / +0x137/+0x138 (per-member enable flags, stride 0x14a8)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Pure helper: given current and previous selection, returns the next selectable character/slot index by scanning member records in 0x6970a0 (count 0x6970f4, stride 0x14a8) for enabled flags (+0x138 / 0x6947e8), wrapping across the 1..8 range.

## Notes / uncertainty
Pure: finds nearest enabled char slot in travel direction (param_1<param_2 down / > up), enable byte @slot*0x14a8+0x6947e8, slots 0/1 special flags (0x6970a0/a1), returns 8 sentinel when up-scan exhausts. 0x697138=0x6947e8+2*0x14a8 confirms same column. Slot-0 meaning inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f9bb0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
