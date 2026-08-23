# 0x0061e910 input_sample_read_byte

| field | value |
|---|---|
| Original address | 0x0061e910 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061e910 |
| Resolved name | input_sample_read_byte |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005af310, FUN_00620250, FUN_006205c0, FUN_00620b60, FUN_00620d60, FUN_00624850, FUN_00624c70, FUN_00625190, FUN_00625670, FUN_00625ea0, FUN_006265f0, FUN_00626900, FUN_00626e70, FUN_00627400, FUN_00627540
**Callees:** —
**Referenced globals:** 0x715268 (last input sample)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x715268

## Behavioral explanation
Samples an input/rng source (extern 0x1b3d90) into uRam00715268 and returns its low byte.

## Notes / uncertainty
Samples ext 0x1b3d90 into global 0x715268, returns low byte; exact source (pad/tick/RNG) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061e910.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
