# 0x001eda10 snap_hdr_ptr_low_check

| field | value |
|---|---|
| Original address | 0x001eda10 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eda10 |
| Resolved name | snap_hdr_ptr_low_check |
| Subsystem | packets |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_001edbb8, FUN_001edd9c
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns (param_2 & ~3)==0, i.e. true when the frame pointer value is 0..3; used by the frame walkers to decide whether to copy the 0x10-byte header to an aligned scratch buffer before byte-swapping.

## Notes / uncertainty
(ptr & ~3)==0 i.e. ptr<=3 near-null guard, NOT alignment (would be &3). Gates aligned-scratch copy in the byte-swap walkers; why a 0..3 header ptr ever occurs is unknown; param_1 ignored.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eda10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
