# 0x00604810 count_leading_occupied_slots

| field | value |
|---|---|
| Original address | 0x00604810 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00604810 |
| Resolved name | count_leading_occupied_slots |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00604e70, FUN_006277a0, FUN_00627ea0, FUN_0062cfd0
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Counts contiguous occupied entries (byte at +0x10 != 0) in a 0x38-stride member table up to a limit — i.e. current player count of a room table.

## Notes / uncertainty
Counts leading contiguous occupied entries (byte+0x10) in 0x38-stride table up to limit; the N in N/4P. Correct only if table is compacted.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00604810.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
