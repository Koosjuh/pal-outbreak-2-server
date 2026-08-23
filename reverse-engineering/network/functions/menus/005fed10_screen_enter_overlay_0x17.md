# 0x005fed10 screen_enter_overlay_0x17

| field | value |
|---|---|
| Original address | 0x005fed10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fed10 |
| Resolved name | screen_enter_overlay_0x17 |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fe730
**Callees:** FUN_005b68e0, FUN_005c44a0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+0x443 mode; param_1+0x42b screen-id=0x17

## Behavioral explanation
Screen transition that sets screen-id 0x17 and registers render callback 0x601300 via FUN_005c44a0(1,...).

## Notes / uncertainty
One-shot screen-enter stub: advance step, mode +0x443=2, overlay id 0x17, register render cb 0x601300 via FUN_005c44a0(1,..). Mode value and FUN_005c44a0 arg (0 vs 1) inferred as input/render mode.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fed10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
