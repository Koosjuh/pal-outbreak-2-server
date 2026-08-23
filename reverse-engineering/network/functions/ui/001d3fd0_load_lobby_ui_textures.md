# 0x001d3fd0 load_lobby_ui_textures

| field | value |
|---|---|
| Original address | 0x001d3fd0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001d3fd0 |
| Resolved name | load_lobby_ui_textures |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001cb360, FUN_001cb5f0, FUN_001cbcb0, FUN_001cf2b0
**Referenced globals:** 0x3435bc scratch; 0x24d8b0 lobby-texture path table (PTR_s_data_rom_netwk_pal_lobby_01_tm2)
**Referenced strings:** data/rom/netwk/pal/lobby_01.tm2 (and sibling lobby texture paths @0x24d8b0)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Loads the network-lobby UI texture set (lobby_01.tm2 .. 0x18 files) from data/rom/netwk/pal into texture slots 0x4000+.

## Notes / uncertainty
24 lobby UI TM2s -> cache slots 0x4000..0x4017; residency-guarded; 6 indices {0,2,4,5,8,0x16} go through path-variant resolver FUN_001cf2b0. Meaning of flags 0x10001 and cf2b0 (region/compression) unconfirmed. Pure UI.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001d3fd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
