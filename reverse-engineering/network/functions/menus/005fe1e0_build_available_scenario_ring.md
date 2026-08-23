# 0x005fe1e0 build_available_scenario_ring

| field | value |
|---|---|
| Original address | 0x005fe1e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fe1e0 |
| Resolved name | build_available_scenario_ring |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f78c0, FUN_005f9280
**Callees:** FUN_005bae80, FUN_005baed0
**Referenced globals:** 0x3424e8 global mask; 0x6c45f8 profile idx; +0x4ba ring flags; +0x53c cursor; +0x53a valid count
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x53c ring cursor

## Behavioral explanation
Builds the selectable scenario ring (up to 11 slots @+0x4ba) from availability bitmasks, sets initial cursor @+0x53c to first valid entry.

## Notes / uncertainty
Builds selectable-scenario ring @+0x4ba from avail=(uRam003424e8>>1 & FUN_005bae80) | FUN_005baed0 over bits 0-10 (bit k -> slot k+1), counts +0x53a, sets cursor +0x53c to first valid. >>1 reason and A-AND vs B-OR mask meaning inferred; dead circular-wrap branch.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fe1e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
