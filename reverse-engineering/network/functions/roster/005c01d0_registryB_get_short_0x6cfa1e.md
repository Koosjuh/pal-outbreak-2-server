# 0x005c01d0 registryB_get_short_0x6cfa1e

| field | value |
|---|---|
| Original address | 0x005c01d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c01d0 |
| Resolved name | registryB_get_short_0x6cfa1e |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b58a0, FUN_005fc0c0, FUN_00600f50, FUN_0062e9b0, FUN_0062edc0, FUN_0062f2b0
**Callees:** —
**Referenced globals:** 0x6cfa1e registry-B render struct base (stride 0x144)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Reads 16-bit field at idx*0x144+0x6cfa1e (registry-B render-struct family) into out-ptr.

## Notes / uncertainty
u16 read third 0x144 table (registry-B) +0x00, 0-based; 6 callers. Field semantics unproven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c01d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
