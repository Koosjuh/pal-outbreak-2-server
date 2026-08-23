# 0x00619800 hud_overlay_render

| field | value |
|---|---|
| Original address | 0x00619800 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00619800 |
| Resolved name | hud_overlay_render |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b2e40, FUN_00622130
**Callees:** FUN_00619e00, FUN_0061c9f0, FUN_0061d080, FUN_0061d210, FUN_0061d3a0, FUN_0061eab0, FUN_0061f850, FUN_00636890, FUN_00637170
**Referenced globals:** uRam0071530c status-icon bitmask; 0x715328/0x715338 draw queues; bRam0071530a/0b blink phase
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam0071530c HUD flag bits

## Behavioral explanation
Per-frame HUD/status-overlay render dispatcher: for each bit set in the status-flag word uRam0071530c draws the corresponding icon (FUN_00619e00), then flushes two queued text-draw lists via FUN_0061d080/d210/d3a0/eab0/c9f0.

## Notes / uncertainty
Per-frame HUD pass: blink phase (0071530a/b), ~30-bit status-icon mask uRam0071530c -> FUN_00619e00 per bit w/ GS context toggles, then flush 2 deferred draw queues (A@0x715320/28 cnt 5312, B@0x715330/38 cnt 5313) via type-dispatch to d080/d3a0/eab0/d210/c9f0, zero counts, FUN_0061f850. Structure certain; per-bit icon meanings (in FUN_00619e00) + queue element-type semantics not resolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00619800.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
