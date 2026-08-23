# 0x005b4860 create_select_confirm_widget

| field | value |
|---|---|
| Original address | 0x005b4860 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b4860 |
| Resolved name | create_select_confirm_widget |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b41b0
**Callees:** FUN_005b09b0, FUN_005b14b0, FUN_005b9110
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** widget+3 phase; widget+0x18 timer; struct+0x43c matched value; struct+0x443/0x43f flags

## Behavioral explanation
Sub-widget for the create/join password-confirm exchange: 6-phase machine that runs the reliable txn (0x5b09b0), matches the entered value against +0x43c, and reports match/mismatch.

## Notes / uncertainty
Renamed from create_password_confirm. 6-phase select-confirm in create flow: spinner (FUN_005b09b0) on parent+0x43c, confirm=input 0x10 / back=0x200, mode param_4 {0 confirm-notify,1 relatch,2 passive}; 0xff=cancelled sentinel. Uncertainty: what value is being selected (scenario/difficulty/password/cap) not pinned — 'password' was a guess, evidence favors an index spinner.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b4860.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
