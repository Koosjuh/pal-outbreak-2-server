# 0x00601c00 render_room_timer

| field | value |
|---|---|
| Original address | 0x00601c00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00601c00 |
| Resolved name | render_room_timer |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_00601ac0, FUN_0062fea0
**Referenced globals:** 0x6c5510 timer seconds
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+4 render-step

## Behavioral explanation
Renders the room countdown/elapsed timer: converts iRam006c5510 seconds to mm:ss, formats via FUN_00601ac0, and draws it (FUN_005af1e0) with color/font setup.

## Notes / uncertainty
Draws room timer from 0x6c5510 seconds (confirms unit via /60,%60): mm:ss clock >=11s, localized label id 0x44 for 1-10s, blank at 0; right-aligned. No caller in corpus (render-cb dispatch).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00601c00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
