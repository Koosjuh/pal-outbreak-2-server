# 0x001cf2b0 build_localized_asset_path

| field | value |
|---|---|
| Original address | 0x001cf2b0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001cf2b0 |
| Resolved name | build_localized_asset_path |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_001cf0b0, FUN_001cf100, FUN_001cf150, FUN_001d1050, FUN_001d1110, FUN_001d1410, FUN_001d1530, FUN_001d33d0, FUN_001d3500, FUN_001d3fd0
**Callees:** FUN_001069a8, FUN_00106b60, FUN_00109728, FUN_0010a6b0
**Referenced globals:** 0x36c2d0 template scratch; 0x24c830 region pointer table; bRam0034359d region index
**Referenced strings:** 0x24cb68 template
**Referenced opcodes:** —
**State vars:** bRam0034359d

## Behavioral explanation
Formats a request/path template into scratch 0x36c2d0 using tmpl 0x24cb68 and a region/locale pointer table (&PTR_DAT_0024c830)[bRam0034359d]; returns 0x36c2d0.

## Notes / uncertainty
strchr('.'), splices region string PTR_0024c830[lang] between stem and extension into shared non-reentrant scratch 0x36c2d0. Exact glue of fmt 0x24cb68 assumed %s%s%s.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001cf2b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
