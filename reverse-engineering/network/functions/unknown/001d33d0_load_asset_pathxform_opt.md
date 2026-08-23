# 0x001d33d0 load_asset_pathxform_opt

| field | value |
|---|---|
| Original address | 0x001d33d0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d33d0 |
| Resolved name | load_asset_pathxform_opt |
| Subsystem | unknown |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_00109728, FUN_00109eb8, FUN_001a0df0, FUN_001cb360, FUN_001cf2b0
**Referenced globals:** 0x343577 disc flag; 0x34359d compress flag; 0x3435ec dest ptr; 0x24d248/0x24d260/0x24d278 path fmts
**Referenced strings:** (path fmts @0x24d248/60/78)
**Referenced opcodes:** —
**State vars:** cRam00343577; cRam0034359d

## Behavioral explanation
Disc/HDD-gated load into puRam003435ec with an optional compressed-path branch (cRam0034359d).

## Notes / uncertainty
RENAMED from load_asset_compressed_opt: optional pass is a path RESOLVE/redirect (FUN_001cf2b0) gated by cRam0034359d, NOT proven to be decompression. Media-gated into 0x3435ec, *dest=0 on fail. Non-network.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d33d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
