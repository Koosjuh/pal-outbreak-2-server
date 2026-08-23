# 0x00608760 apply_option_flags

| field | value |
|---|---|
| Original address | 0x00608760 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00608760 |
| Resolved name | apply_option_flags |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005f4480
**Callees:** —
**Referenced globals:** 0x00337de1 config-bits; 0x00337e03 config; 0x006c5037 opt; 0x006c503a opt; 0x006c503b opt
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c5037; cRam006c503a; cRam006c503b

## Behavioral explanation
Maps option flags 6c5037/3a/3b into bitfield 337de1 and copies 6c5039/3c-3f into config bytes 337e03-07.

## Notes / uncertainty
Folds 3 option bytes into bitfield 0x337de1 (bits 0/1/3) + copies 5 bytes to 0x337e03..07. Tail truncated (halt_baddata); concrete settings unmapped, net linkage unproven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00608760.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
