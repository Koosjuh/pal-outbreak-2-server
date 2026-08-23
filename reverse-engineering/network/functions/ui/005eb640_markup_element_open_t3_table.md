# 0x005eb640 markup_element_open_t3_table

| field | value |
|---|---|
| Original address | 0x005eb640 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005eb640 |
| Resolved name | markup_element_open_t3_table |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005eb7d0, FUN_005ec100, FUN_005ef5e0, FUN_005ef850, FUN_005f0e10
**Referenced globals:** +4; +0xd894; +0x252f
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xd894

## Behavioral explanation
Type-3 open variant: same as 0x5eb5a0 plus a call to table-layout finalizer FUN_005eb7d0 after commit.

## Notes / uncertainty
Kind-3 open + trailing table finalizer FUN_005eb7d0. Reason for plain-vs-table variant unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005eb640.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
