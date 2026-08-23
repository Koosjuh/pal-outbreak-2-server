# 0x005c2f40 build_scenario_config

| field | value |
|---|---|
| Original address | 0x005c2f40 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c2f40 |
| Resolved name | build_scenario_config |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005c3190
**Callees:** FUN_005bf1e0, FUN_005c2ad0, FUN_005c2ae0, FUN_005c2b20, FUN_005c2b90, FUN_005c2bc0, FUN_005c2d70, FUN_005c2e90, FUN_005c4f00
**Referenced globals:** 0x6d2294/95/96 (config flags + cast count); 0x6d2297 (cast-config buffer, 0x14a5 stride); 0x6cc044/0x7005d9 (player-slot bytes); 0x7005d0 (player count)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006d2294; uRam006d2295; cRam006d2296

## Behavioral explanation
Assembles the room's scenario/character configuration table into 0x6d2297: reads the scenario sub-record, decodes bitfields, calls the two cast builders, tallies rows into cRam006d2296, and (mode 1) copies the live player list or (mode 0) latches the 0x6d2294/95 config flags.

## Notes / uncertainty
Builds scenario/character config table 0x6d2297 (stride 0x14a5) from the scenario sub-record via cast-row builders; mode1 copies live player chars, mode0 latches config flags 0x6d2294/95. Roles of the three cast-builder passes and the sub-record struct are inferred; no wire send.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c2f40.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
