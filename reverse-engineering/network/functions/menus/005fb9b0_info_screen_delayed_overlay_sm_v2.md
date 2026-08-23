# 0x005fb9b0 info_screen_delayed_overlay_sm_v2

| field | value |
|---|---|
| Original address | 0x005fb9b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fb9b0 |
| Resolved name | info_screen_delayed_overlay_sm_v2 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fb710
**Callees:** FUN_005b68e0, FUN_005b6900, FUN_005b9060, FUN_005c0750
**Referenced globals:** +0x42b overlay id (0x13); +0x5ec buffer; +0x16 timer
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x10 sub-state

## Behavioral explanation
Timed info/list screen SM (peer of FUN_005fb790): show->confirm, shows overlay via FUN_005c0750 (builder 0x5fc6b0, id 0x13).

## Notes / uncertainty
Structural twin of 0x5fb790; overlay id 0x13, show via FUN_005c0750(0x5fc6b0). Difference between the two show routines (layer/z/input-mode) untraced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fb9b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
