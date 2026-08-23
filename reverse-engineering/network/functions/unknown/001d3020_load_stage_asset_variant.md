# 0x001d3020 load_stage_asset_variant

| field | value |
|---|---|
| Original address | 0x001d3020 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d3020 |
| Resolved name | load_stage_asset_variant |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109728, FUN_001d31b0
**Referenced globals:** struct+0xbc8 stage code; 0x24d160/0x24d170/0x24d180 path fmts
**Referenced strings:** (path fmts @0x24d160/70/80)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Chooses one of three path formats by a struct+0xbc8 stage code and loads via 0x1d31b0.

## Notes / uncertainty
3-way path template select on s16 stage code +0xbc8 (0/0x5b/else), sub-id +0xbb0, slot (+3)+4, via helper. Meaning of code 0x5b unresolved. Non-network.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d3020.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
