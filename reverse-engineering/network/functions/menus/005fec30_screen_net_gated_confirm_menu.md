# 0x005fec30 screen_net_gated_confirm_menu

| field | value |
|---|---|
| Original address | 0x005fec30 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fec30 |
| Resolved name | screen_net_gated_confirm_menu |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fe730
**Callees:** FUN_005b09b0, FUN_005b14b0, FUN_005c0f60, FUN_005f4b80, FUN_005f4be0, FUN_005f54d0
**Referenced globals:** 0x6c4600 menu-context ptr
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+0x97f dirty-flag; param_1+0x992 busy-flag; param_1+0x907 cursor

## Behavioral explanation
Menu screen that polls net/session readiness (FUN_005f4be0==0) and input (FUN_005b14b0), advancing the step or setting busy flag 0x992 accordingly.

## Notes / uncertainty
Net-gated 3-item confirm menu: rebuild-on-dirty, pump net, only accept input when FUN_005f4be0()==0; input 0x10 confirm->advance step, 0x200 cancel->reset cursor, else nav; always draw. Input-mask semantics and which pending txn it waits on inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fec30.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
