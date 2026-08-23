# 0x005b53b0 cmd_handler_02_area_refresh

| field | value |
|---|---|
| Original address | 0x005b53b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b53b0 |
| Resolved name | cmd_handler_02_area_refresh |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005be9a0
**Referenced globals:** 0x6c4b90 cRam006c4b90 area/scenario index; 0x6c50fa refresh flag; 0x6c517c list buffer
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x6c4b90; 0x6c50fa

## Behavioral explanation
Registered lobby command handler (selector id 2): unless area 0x6c4b90==6, sets refresh flag 0x6c50fa and rebuilds a list via 0x5be9a0(0x6c517c).

## Notes / uncertainty
Command-id-2 handler (installed by 005b25c0): unless screen==6, set dirty flag 0x6c50fa and rebuild list 0x6c517c (FUN_005be9a0). On-wire opcode→id-2 mapping not captured; runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b53b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
