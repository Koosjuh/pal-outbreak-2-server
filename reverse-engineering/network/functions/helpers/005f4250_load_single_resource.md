# 0x005f4250 load_single_resource

| field | value |
|---|---|
| Original address | 0x005f4250 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f4250 |
| Resolved name | load_single_resource |
| Subsystem | helpers |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f42c0
**Callees:** —
**Referenced globals:** uRam003435bc(archive base); 0x649610(asset name string)
**Referenced strings:** <asset filename @0x649610>
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Opens one asset from an archive by name and registers its handle (0x4100) if not already loaded.

## Notes / uncertainty
Idempotent single-asset loader: formats name (tmpl 0x649610), opens (flags 0x10001), registers handle 0x4100 only if not already resident. Resource-manager import roles inferred from query-then-register idiom.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f4250.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
