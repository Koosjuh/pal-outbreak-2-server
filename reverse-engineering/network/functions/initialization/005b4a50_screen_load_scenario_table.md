# 0x005b4a50 screen_load_scenario_table

| field | value |
|---|---|
| Original address | 0x005b4a50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b4a50 |
| Resolved name | screen_load_scenario_table |
| Subsystem | initialization |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b24e0
**Callees:** FUN_005ae130, FUN_005af2f0, FUN_005af300, FUN_005af310, FUN_005b14b0, FUN_005b68e0, FUN_005b6900, FUN_005b9060, FUN_005bea90, FUN_00618b60
**Referenced globals:** 0x870f10 source table; 0x6ca090 working copy; struct+0x994/0x993 flags
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0xf sub-state; struct+0x16 timer

## Behavioral explanation
Screen-9 data-load machine: copies a 0x1d0-byte / 29-entry table from 0x870f10 into working RAM 0x6ca090, verifies it, and registers it (0x5bea90); falls back to screen 3 on completion.

## Notes / uncertainty
9-state SM on screen_obj+0xf: async-load, memcpy 29x16B (0x1d0) 0x870f10->0x6ca090, memcmp verify, register 0x5b6860 callback, timer gates (299/0x1d frames), terminal state 8 routes to screen 3. Copy/verify exact; async-load callee semantics and table content (scenario vs area) inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b4a50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
