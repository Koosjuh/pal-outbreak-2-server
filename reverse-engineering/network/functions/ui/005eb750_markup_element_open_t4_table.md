# 0x005eb750 markup_element_open_t4_table

| field | value |
|---|---|
| Original address | 0x005eb750 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eb750 |
| Resolved name | markup_element_open_t4_table |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005eb7d0, FUN_005ef5e0, FUN_005ef850, FUN_005f0e10
**Referenced globals:** +4
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Type-4 open variant: same as 0x5eb6f0 plus table-layout finalizer FUN_005eb7d0 after commit.

## Notes / uncertainty
Kind-4 open + table finalizer FUN_005eb7d0 (shared with 0x5eb640). Variant rationale unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eb750.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
