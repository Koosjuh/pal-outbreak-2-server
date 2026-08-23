# 0x005b8e40 spawn_message_widget_with_data

| field | value |
|---|---|
| Original address | 0x005b8e40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b8e40 |
| Resolved name | spawn_message_widget_with_data |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00628210
**Callees:** FUN_005b8f60, FUN_00618ba0
**Referenced globals:** 0x006c4fcd uRam=msg channel; 0x006c4fce uRam; 0x006c4fcf uRam
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006c4fcd; uRam006c4fce; uRam006c4fcf

## Behavioral explanation
Like spawn_message_widget but also stores a data/payload ptr (param_3) at +0x10, then adds FUN_005b8f60 decorations by type; callback FUN_005b9150.

## Notes / uncertainty
Like spawn_message_widget + payload ptr at +0x10; deco pair only spawned if alloc succeeds. deco_arg role defined by deco spawner.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b8e40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
