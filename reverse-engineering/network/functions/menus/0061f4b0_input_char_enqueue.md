# 0x0061f4b0 input_char_enqueue

| field | value |
|---|---|
| Original address | 0x0061f4b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061f4b0 |
| Resolved name | input_char_enqueue |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00619e00, FUN_0061d6a0, FUN_0061f9f0, FUN_0061fd70, FUN_006205c0, FUN_00620d60, FUN_00622d60, FUN_00622f40, FUN_00623800, FUN_00624850, FUN_00625190, FUN_00625ea0, FUN_006265f0, FUN_00626900, FUN_00626e70, FUN_00627400, FUN_00627540
**Callees:** —
**Referenced globals:** 0x715320/0x715328 (queue A + type); 0x715330/0x715338 (queue B + type); 0x715312/0x715313 (queue counts)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715312; 0x715313

## Behavioral explanation
Classifies an input character by ASCII range and enqueues it into one of the on-screen-keyboard render queues (0x715330/0x715338 with type 0/4/5, or 0x715320/0x715328 type 0), capped at 8 entries.

## Notes / uncertainty
Already a deep reconstruction: glyph router into 2x8-slot lists, styles 0/4/5, no default. Style visual meaning unrecovered. Left as-is.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061f4b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
