# 0x005f42c0 load_resource_set

| field | value |
|---|---|
| Original address | 0x005f42c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f42c0 |
| Resolved name | load_resource_set |
| Subsystem | helpers |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b2e40, FUN_00621ed0
**Callees:** FUN_005f4250
**Referenced globals:** iRam003435bc(archive base); uRam0034357a(asset lock flag); 0x649630(asset name)
**Referenced strings:** <asset filename @0x649630>
**Referenced opcodes:** —
**State vars:** uRam0034357a

## Behavioral explanation
Loads 9 assets (7 into param_1, 2 into param_2) from an archive into handle arrays; toggles an asset lock.

## Notes / uncertainty
Archive-mount + decompress of 9 handles (0x4000..0x4008; 7->param_1, 2->param_2) under uRam0034357a=0xFFFF lock. Resource-manager primitive semantics (001cb360 mode 0x10001, 001a79b0 LZSS-vs-copy, FUN_005f4250 fixup) inferred, unvalidated. No protocol.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f42c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
