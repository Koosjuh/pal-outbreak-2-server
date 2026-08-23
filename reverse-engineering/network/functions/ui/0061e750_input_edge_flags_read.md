# 0x0061e750 input_edge_flags_read

| field | value |
|---|---|
| Original address | 0x0061e750 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061e750 |
| Resolved name | input_edge_flags_read |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0061e860, FUN_0061f9f0, FUN_0061fd70, FUN_00620250, FUN_00620d60, FUN_00624850, FUN_00625190, FUN_00625ea0
**Callees:** —
**Referenced globals:** 0x3433b0 (input state A); 0x3433c8 (input state B)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x3433b0; 0x3433c8

## Behavioral explanation
Returns OR of two pad/input state globals (0x3433b0 | 0x3433c8) — combined button/input edge mask.

## Notes / uncertainty
Returns 0x3433b0 | 0x3433c8 (combined pad mask); edge-vs-held labeling of the two words inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061e750.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
