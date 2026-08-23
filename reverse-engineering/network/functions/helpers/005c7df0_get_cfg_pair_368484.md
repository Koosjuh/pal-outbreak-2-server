# 0x005c7df0 get_cfg_pair_368484

| field | value |
|---|---|
| Original address | 0x005c7df0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c7df0 |
| Resolved name | get_cfg_pair_368484 |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b3790
**Callees:** —
**Referenced globals:** 0x368484; 0x368486 (config words)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Copies two config words (0x368484/0x368486) into caller out-params.

## Notes / uncertainty
Copies two u16 config words (0x368484/0x368486) into out[2], returns 0. Meaning of the config words not identified.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c7df0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
