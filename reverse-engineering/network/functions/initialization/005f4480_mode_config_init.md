# 0x005f4480 mode_config_init

| field | value |
|---|---|
| Original address | 0x005f4480 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f4480 |
| Resolved name | mode_config_init |
| Subsystem | initialization |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_006063c0, FUN_006064c0
**Callees:** FUN_005adcd0, FUN_005add80, FUN_005f4440, FUN_00608730, FUN_00608760, FUN_00608840
**Referenced globals:** 0x337de0(config block, memset 0x36); uRam00337de2/3/6/8/ec/f0; uRam003433a8; uRam00343592
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam00343592

## Behavioral explanation
Initializes a mode/settings block (0x337de0): reads config values, seeds sub-objects, frees asset handles.

## Notes / uncertainty
One-time constructor for 0x36-byte mode block @0x337de0; seeds fields from cfg accessors, frees stale handles, sets uRam00343592=1/uRam003433a8=0. Accessor roles (005add80/005adcd0) inferred; block semantics unproven. No wire.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f4480.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
