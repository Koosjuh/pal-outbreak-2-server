# 0x001d40e0 load_lobby_player_textures

| field | value |
|---|---|
| Original address | 0x001d40e0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d40e0 |
| Resolved name | load_lobby_player_textures |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001cb360, FUN_001cb5f0
**Referenced globals:** 0x3435bc scratch; 0x24da30 player-texture path table (PTR_s_data_rom_netwk_player_11_tm2)
**Referenced strings:** data/rom/netwk/player_11.tm2 (player texture path table @0x24da30)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Loads up to 4 player-portrait/model textures (data/rom/netwk/player_11.tm2 ...) into lobby texture slots 0x4019+.

## Notes / uncertainty
Up to 4 player-portrait textures -> slots 0x4019..0x401C, keyed by a signed char[4] seat->index array; -1 = empty seat skipped. param_1/param_2 dead. UI only.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d40e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
