# 0x001d2b30 load_overlay_index

| field | value |
|---|---|
| Original address | 0x001d2b30 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d2b30 |
| Resolved name | load_overlay_index |
| Subsystem | initialization |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001d2bd0
**Callees:** FUN_00109728, FUN_001a0df0, FUN_001cb360
**Referenced globals:** 0x343577 disc flag; 0x24d000/0x24d018/0x24d030 path fmt; 0x3435cc/0x3435d0 handle/dest
**Referenced strings:** (path format strings @0x24d000/0x24d030)
**Referenced opcodes:** —
**State vars:** cRam00343577

## Behavioral explanation
Disc/HDD-gated load of an overlay/index file into uRam003435cc via FUN_001cb360/FUN_001a0df0.

## Notes / uncertainty
Disc/HDD-gated overlay index load: disc path via FUN_001cb360 (fmt 0x24d000/18) vs HDD via FUN_001a0df0 (fmt 0x24d030), result to uRam3435cc. Path template contents undumped. Not network.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d2b30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
