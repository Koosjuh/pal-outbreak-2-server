# 0x005ae8a0 screen_fsm_list_advance

| field | value |
|---|---|
| Original address | 0x005ae8a0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ae8a0 |
| Resolved name | screen_fsm_list_advance |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ae770
**Callees:** FUN_005aeb10, FUN_005b68e0, FUN_005b6900, FUN_005b9110, FUN_005bb0b0, FUN_00618800, FUN_00637180
**Referenced globals:** 0x6c45f8 bRam006c45f8=entry count; 0x3435d4 iRam003435d4
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x5196/+0x5197/+0x5198 screen state; +0x519a countdown

## Behavioral explanation
Per-frame state machine (states 0-3 at +0x5198) for a list/roster overlay screen: on state 3 rebuilds the display list via list_build_from_source, validates the selected entry (bRam006c45f8 count), plays a cue and advances/wraps.

## Notes / uncertainty
Phase-0 of 5197: opens scroll box (table 0x3435d4+0x8000, cb 0x5aebf0), validates selection bRam006c45f8 via FUN_005bb0b0(sel-1); valid -> advance phase, invalid/none -> tear down overlay. sel-1 lookup argues 'selected index' over prior 'count' note; not disambiguated live.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ae8a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
