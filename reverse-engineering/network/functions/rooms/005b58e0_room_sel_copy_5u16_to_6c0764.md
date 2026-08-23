# 0x005b58e0 room_sel_copy_5u16_to_6c0764

| field | value |
|---|---|
| Original address | 0x005b58e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b58e0 |
| Resolved name | room_sel_copy_5u16_to_6c0764 |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c0370, FUN_005c0f00
**Referenced globals:** 0x6c0764/0766/0768/076a/076c (5 fields of 0x15c-stride record)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Read selected list index, commit five adjacent fields (0x6c0764..0x6c076c) of the selected 0x15c-stride record via FUN_005c0370.

## Notes / uncertainty
5x u16 copy src 0x6cfa22..2a -> dest 0x6c0764..6c; base computed once. Plausibly a room-parameter vector; individual field roles unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b58e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
