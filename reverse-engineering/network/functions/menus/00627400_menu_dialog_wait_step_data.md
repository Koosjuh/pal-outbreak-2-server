# 0x00627400 menu_dialog_wait_step_data

| field | value |
|---|---|
| Original address | 0x00627400 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00627400 |
| Resolved name | menu_dialog_wait_step_data |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00622180
**Callees:** FUN_0061e7f0, FUN_0061e910, FUN_0061e960, FUN_0061f0e0, FUN_0061f1a0, FUN_0061f1d0, FUN_0061f4b0, FUN_0061f760
**Referenced globals:** 0x365dcc gate-data
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam007152e1 screen-phase; uRam007152e4 timer

## Behavioral explanation
Wait/confirm menu screen-step gated on iRam00365dcc (data present), phases 0->1->2/3 via FUN_0061e910 poll.

## Notes / uncertainty
Show-fetched-data-and-wait dialog gated on 0x365dcc (fetched-data ptr); identical phase ladder to FUN_006265f0. Returns 1/-1. Data domain unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00627400.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
