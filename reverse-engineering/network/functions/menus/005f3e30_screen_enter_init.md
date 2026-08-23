# 0x005f3e30 screen_enter_init

| field | value |
|---|---|
| Original address | 0x005f3e30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f3e30 |
| Resolved name | screen_enter_init |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f3de0
**Callees:** FUN_005ac3b0, FUN_005b2400, FUN_005de2a0, FUN_00634550, FUN_006386f0
**Referenced globals:** iRam00337dd0(one-time init guard); bRam0034359d(language/region); 0x6495f0(asset table); 0x874500/0x3c8a90(cleared buffers); uRam00343639
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+0x08; iRam00337dd0

## Behavioral explanation
Initializes a full-screen scene: sets render callback 0x5f4220, loads palette/scene assets, clears buffers, advances phase.

## Notes / uncertainty
One-shot scene bring-up: registers render cb 0x5f4220, one-time init guarded by iRam00337dd0, language-indexed asset load (tbl 0x6495f0), clears work buffers (0xa28/0x1d7c), inits display list, sets scene-ready. func_0x001* import names are role guesses.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f3e30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
