# 0x00608680 push_players_to_hud

| field | value |
|---|---|
| Original address | 0x00608680 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00608680 |
| Resolved name | push_players_to_hud |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00617270, FUN_006176a0
**Callees:** —
**Referenced globals:** 0x00874f38 hud; 0x00874f3a hud; 0x00874f37 hud; 0x00874f3b hud
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Iterates a per-entity table (count @+0x990, stride 0x3b0) calling func_0x007df390 per entity, and copies status fields into HUD globals 874f37/38/3a/3b.

## Notes / uncertainty
Resets HUD then per-player (count+0x990, stride 0x3b0) calls func_007df390 + copies status scalars to HUD globals 0x874f37..3b. Likely in-game party->HUD handoff (caller range 0x617xxx), not lobby roster; net linkage unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00608680.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
