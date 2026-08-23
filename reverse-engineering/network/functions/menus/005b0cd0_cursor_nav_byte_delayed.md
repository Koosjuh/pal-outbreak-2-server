# 0x005b0cd0 cursor_nav_byte_delayed

| field | value |
|---|---|
| Original address | 0x005b0cd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b0cd0 |
| Resolved name | cursor_nav_byte_delayed |
| Subsystem | menus |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00628210, FUN_006293f0, FUN_006296a0
**Callees:** FUN_005b14b0, FUN_005b16c0
**Referenced globals:** 0x6ca070/0x6ca072 repeat-delay counters; 0x6c462a pad latch; 0x6c4628 pad-held latch
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Cursor navigation with an initial-hold delay before auto-repeat: uses input_pressed for the first edge and input_held (FUN_005b16c0) plus a per-axis delay counter (0x6ca070/72) for repeat, then inc/dec *param_1 with wrap.

## Notes / uncertainty
Typematic cursor: initial 0x14f delay, 10f repeat, via input_held + delay counters 0x6ca070/72 and held latch 0x6c4628. primary=decrement(LAB_005b0e80)/secondary=increment. Room-list callers.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b0cd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
