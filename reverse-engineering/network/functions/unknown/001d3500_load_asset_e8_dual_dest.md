# 0x001d3500 load_asset_e8_dual_dest

| field | value |
|---|---|
| Original address | 0x001d3500 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d3500 |
| Resolved name | load_asset_e8_dual_dest |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109728, FUN_001a0df0, FUN_001cb360, FUN_001cf2b0
**Referenced globals:** 0x343577 disc flag; 0x3435e8/0x3435dc dest; 0x24d288/0x24d298/0x24d2a8 path fmts
**Referenced strings:** (path fmts @0x24d288/98/a8)
**Referenced opcodes:** —
**State vars:** cRam00343577

## Behavioral explanation
Disc/HDD-gated file load into puRam003435e8 (or scratch +0x10000 when param set).

## Notes / uncertainty
RENAMED from load_asset_e8_scratch: param_1 selects dest (0=0x3435e8 default, else 0x3435dc+0x10000). Always path-resolves via FUN_001cf2b0. *dest=0 on fail. Non-network.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d3500.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
