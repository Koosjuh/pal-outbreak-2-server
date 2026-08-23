# 0x001eaaa8 attr_table_get

| field | value |
|---|---|
| Original address | 0x001eaaa8 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001eaaa8 |
| Resolved name | attr_table_get |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001069a8
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Looks up a short key (param_2) in a serialized attribute table (leading u16 count, then count entries of {u16 key, u32 val}); returns the u32 value or -1 if absent.

## Notes / uncertainty
TLV map lookup {i16 key,u32 val}, 6B stride, hdr 2B; -1 on miss. Empty-table path compares uninit stack (miss in practice). Runtime-unvalidated.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001eaaa8.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
