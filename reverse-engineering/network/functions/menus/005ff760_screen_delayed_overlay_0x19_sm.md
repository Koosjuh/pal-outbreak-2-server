# 0x005ff760 screen_delayed_overlay_0x19_sm

| field | value |
|---|---|
| Original address | 0x005ff760 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ff760 |
| Resolved name | screen_delayed_overlay_0x19_sm |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fe730
**Callees:** FUN_005b68e0, FUN_005b6900, FUN_005b9060, FUN_005c0750
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+0x10 sub-step; param_1+0x16 timer; param_1+0x42b screen-id=0x19

## Behavioral explanation
4-state screen transition that sets screen-id 0x19, registers render cb 0x601420, and kicks a timed action (FUN_005b9060 0x14).

## Notes / uncertainty
4-state delayed-overlay screen (FUN_005fe730-family twin of 0x5fb790): load list, 76-frame countdown, show overlay 0x19 (cb 0x601420, pending-op-0x19 gated), idle. Content list and backing network op not confirmed here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ff760.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
