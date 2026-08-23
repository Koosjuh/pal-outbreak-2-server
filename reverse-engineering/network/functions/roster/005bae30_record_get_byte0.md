# 0x005bae30 record_get_byte0

| field | value |
|---|---|
| Original address | 0x005bae30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bae30 |
| Resolved name | record_get_byte0 |
| Subsystem | roster |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0062c9f0
**Callees:** FUN_005bac60
**Referenced globals:** 0x006c5480 record table base
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Field accessor: returns byte[0] of record (param&0xffff) in table base FUN_005bac60(0), stride 0x1e4.

## Notes / uncertainty
Returns byte+0 of record (index&0xffff) in current buffer get_record_table_base(0), stride 0x1e4. Meaning of byte+0 (type/status) undecoded; caller FUN_0062c9f0 context would resolve.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bae30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
