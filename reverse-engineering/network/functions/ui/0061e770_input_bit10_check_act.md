# 0x0061e770 input_bit10_check_act

| field | value |
|---|---|
| Original address | 0x0061e770 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061e770 |
| Resolved name | input_bit10_check_act |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0061ded0
**Callees:** FUN_0061e730
**Referenced globals:** 0x29a528 (input/pad context ptr)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x29a528+0x10 (input flag word)

## Behavioral explanation
Tests input-context bit 0x10 at (0x29a528+0x10); if set fires FUN_0061e730 and returns the bool.

## Notes / uncertainty
Test bit 0x10 of *(0x29a528+0x10), fire e730, return bool; button meaning + e730 effect inferred/opaque.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061e770.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
