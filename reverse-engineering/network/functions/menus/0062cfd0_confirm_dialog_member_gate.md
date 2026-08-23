# 0x0062cfd0 confirm_dialog_member_gate

| field | value |
|---|---|
| Original address | 0x0062cfd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0062cfd0 |
| Resolved name | confirm_dialog_member_gate |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_0062cf50
**Callees:** FUN_005b09b0, FUN_005b14b0, FUN_005b8da0, FUN_005b9110, FUN_00604810
**Referenced globals:** 0x694700 candidate table; +0x8/+0x10 selection fields
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Selection step of the enter submachine: seeds a choice via FUN_00604810(0x694700,0x32), waits on pad, moves cursor (FUN_005b09b0), advances to the request step.

## Notes / uncertainty
Renamed from enter_select_menu. Yes/No confirm message box (type 0xaf) gated on member-pool 0x694700 occupancy; result enum 1=No/2=Yes. Pad-bit semantics (0x10/0x200) and exact UX meaning unproven; func_0x001b0140 dismiss/SE thunk inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0062cfd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
