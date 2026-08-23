# 0x00628210 member_refresh_sm

| field | value |
|---|---|
| Original address | 0x00628210 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00628210 |
| Resolved name | member_refresh_sm |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00627d60
**Callees:** FUN_005af3c0, FUN_005af3e0, FUN_005af400, FUN_005b0cd0, FUN_005b1420, FUN_005b1460, FUN_005b8cf0, FUN_005b8e40, FUN_005b9110, FUN_0061ded0, FUN_006278e0
**Referenced globals:** 0x694700 master-roster; 0x6951b8 slot-scratch; param+0x43c/0x443/0x45a flags
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Large member-list refresh/removal state machine (cases 0-6): times a refresh window, polls FUN_0061ded0 for a member event, re-syncs the display roster (FUN_006278e0), and compacts the master roster 0x694700 on leave.

## Notes / uncertainty
Case-3 REFRESH add/remove SM (steps 0-6). Case-4 memmoves master roster 0x694700 (0x38 stride) down over removed slot; FUN_0061ded0 sign = join(>0)/leave(<0). case-6 base/window recompute preserved verbatim; FUN_005b8cf0(-0x7d) target unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00628210.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
