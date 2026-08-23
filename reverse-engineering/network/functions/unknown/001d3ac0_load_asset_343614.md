# 0x001d3ac0 load_asset_343614

| field | value |
|---|---|
| Original address | 0x001d3ac0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d3ac0 |
| Resolved name | load_asset_343614 |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109728, FUN_001cb360
**Referenced globals:** 0x343577 disc flag; 0x343614 dest; 0x24d450/0x24d470 path fmts
**Referenced strings:** (path fmts @0x24d450/70)
**Referenced opcodes:** —
**State vars:** cRam00343577

## Behavioral explanation
Disc/HDD-gated load into uRam00343614 (path fmt 0x24d450/0x24d470).

## Notes / uncertainty
Minimal media-gated VRAM-stage load into 0x343614 (mode 0x10001), result ignored (no post-check). Non-network.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d3ac0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
