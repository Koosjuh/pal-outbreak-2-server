# 0x0061e7f0 input_bit10_check_act_v2

| field | value |
|---|---|
| Original address | 0x0061e7f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061e7f0 |
| Resolved name | input_bit10_check_act_v2 |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0061d6a0, FUN_0061e860, FUN_0061f9f0, FUN_0061fd70, FUN_00620250, FUN_006205c0, FUN_00620d60, FUN_00622d60, FUN_00623800, FUN_00624850, FUN_00625670, FUN_00625ea0, FUN_006265f0, FUN_00626900, FUN_00626e70, FUN_00627400, FUN_00627540
**Callees:** —
**Referenced globals:** 0x29a528 (input/pad context ptr)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x29a528+0x10 (input flag word)

## Behavioral explanation
Same as e770: tests input bit 0x10, fires FUN_0061e730(0) if set, returns bool — heavily reused (17 callers).

## Notes / uncertainty
Workhorse bit-0x10 edge check (17 callers), fires e730(0); e730 effect opaque.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061e7f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
