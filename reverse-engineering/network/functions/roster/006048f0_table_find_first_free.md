# 0x006048f0 table_find_first_free

| field | value |
|---|---|
| Original address | 0x006048f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006048f0 |
| Resolved name | table_find_first_free |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00603f30, FUN_006049b0, FUN_00604c90
**Callees:** —
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Returns index of the first free slot (byte at +0x10 == 0) in a 0x38-stride table, or -1 if full.

## Notes / uncertainty
First free slot (byte+0x10==0) in 0x38-stride table, else -1. Allocator counterpart to 00604860.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006048f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
