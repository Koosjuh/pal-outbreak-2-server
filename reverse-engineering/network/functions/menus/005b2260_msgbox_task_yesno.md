# 0x005b2260 msgbox_task_yesno

| field | value |
|---|---|
| Original address | 0x005b2260 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b2260 |
| Resolved name | msgbox_task_yesno |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005b1a30
**Callees:** FUN_005b09b0, FUN_005b14b0, FUN_005b1d10, FUN_005b8da0, FUN_005b9110, FUN_005f6970
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** struct+0x430 phase; struct+0x436 timer; struct+0x435 result; struct+0x43f flag

## Behavioral explanation
Modal yes/no confirm task (1a30 case 6): 5-phase machine at +0x430 with short timer +0x436 and result flag +0x435, builds box via 0x5b8da0/9110, reports result via 0x5f6970.

## Notes / uncertainty
Modal yes/no confirm: 5-phase machine, accept=0x10 cancel=0x200, selection/result at +0x435 (default 1), cursor via 0x5b09b0, result reported via on_yesno_result(1) ONLY when selection==0. Yes/No polarity + why result gated on ==0 unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b2260.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
