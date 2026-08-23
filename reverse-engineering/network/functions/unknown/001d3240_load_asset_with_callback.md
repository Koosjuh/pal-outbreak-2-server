# 0x001d3240 load_asset_with_callback

| field | value |
|---|---|
| Original address | 0x001d3240 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d3240 |
| Resolved name | load_asset_with_callback |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109728, FUN_001a0df0, FUN_001cb360
**Referenced globals:** 0x343577 disc flag; 0x3435d4 dest; 0x24d1d0/0x24d1e0/0x24d1f8 path fmts
**Referenced strings:** (path fmts @0x24d1d0/e0/f8)
**Referenced opcodes:** —
**State vars:** cRam00343577

## Behavioral explanation
Disc/HDD-gated file load; invokes func_0x00707340/007073f0 on failure/success.

## Notes / uncertainty
Media-gated (cRam00343577) load into 0x3435d4, success/fail callbacks 0x7073f0/0x707340. Disc fail predicate <1, HDD ==0. Callback bodies not traced. Non-network.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d3240.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
