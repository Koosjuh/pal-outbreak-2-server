# 0x0061e800 input_bit200_check_act_v2

| field | value |
|---|---|
| Original address | 0x0061e800 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061e800 |
| Resolved name | input_bit200_check_act_v2 |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0061e860, FUN_0061f9f0, FUN_0061fd70, FUN_00620250, FUN_00620d60, FUN_00622d60, FUN_00624850, FUN_00625670, FUN_00625ea0, FUN_00626900
**Callees:** —
**Referenced globals:** 0x29a528 (input/pad context ptr)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x29a528+0x10 (input flag word)

## Behavioral explanation
Tests input bit 0x200, fires FUN_0061e740(0) if set, returns bool — reused menu input predicate.

## Notes / uncertainty
Live bit-0x200 edge check (10 callers), fires e740(0); paired cancel to e7f0 confirm.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061e800.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
