# 0x005b1b10 namelist_widget_update

| field | value |
|---|---|
| Original address | 0x005b1b10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b1b10 |
| Resolved name | namelist_widget_update |
| Subsystem | roster |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005b09b0, FUN_005b14b0, FUN_005b1e30, FUN_005b1e80, FUN_00618c20
**Referenced globals:** 0x638c30 DAT_00638c30 per-index cursor/coord table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** widget+4 sub-state; struct+0x42f selected index; struct+0x438 active; struct+0x42d result task

## Behavioral explanation
State-machine callback for the name-selection list widget: renders the name list (0x5b1e80), advances index +0x42f, reads button input, sets result task type.

## Notes / uncertainty
Name-select list widget state machine (element+4: 0init/1arm/2interactive/3commit/4destroy/10-11 anim). Owner via +0x10; teardown when owner+0x42c==0; nav+pad(0x10/0x200/0x8000)+SFX. State-2 confirm/cancel mask split and state-3 index math transcribed literally (possible decompiler artifact).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b1b10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
