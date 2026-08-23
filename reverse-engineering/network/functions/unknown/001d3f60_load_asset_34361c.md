# 0x001d3f60 load_asset_34361c

| field | value |
|---|---|
| Original address | 0x001d3f60 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d3f60 |
| Resolved name | load_asset_34361c |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109728, FUN_001cb360
**Referenced globals:** 0x34361c dest ptr; 0x24d578/0x24d590 path fmts
**Referenced strings:** (path fmts @0x24d578/90)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Loads a file into puRam0034361c (fmt 0x24d578/0x24d590); marks 0xff on failure.

## Notes / uncertainty
Disc-only (no HDD branch) VRAM-stage load into 0x34361c, *dest=0xff on fail. Asset identity + why disc-only unresolved. Non-network.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d3f60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
