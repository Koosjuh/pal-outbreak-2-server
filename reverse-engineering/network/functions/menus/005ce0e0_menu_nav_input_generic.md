# 0x005ce0e0 menu_nav_input_generic

| field | value |
|---|---|
| Original address | 0x005ce0e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ce0e0 |
| Resolved name | menu_nav_input_generic |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ce0a0, FUN_005d0a40, FUN_005d5b60, FUN_0061e720, FUN_0061e730, FUN_0061e740
**Referenced globals:** 0x701068+0x4f8a4 buttons; 0x701068+0x4f8a8/0x4f8a9 pad mode; 0x715da8+0x49c keyboard char; 0x701078+2 selection col; 0x701078+0xe repeat ctr; 0x701070+0x38/0x3a timers
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701078+2; 0x701068+0x68e7c; 0x701068+0x68e7d

## Behavioral explanation
Reads pad (0x4f8a4) and keyboard (0x49c) up/down and auto-repeat timing to move the column/selection value (wrapped 1..3), playing nav/confirm/cancel sounds and handling section-change transitions.

## Notes / uncertainty
3-way (cols 1..3) nav/confirm: cancel(0x8000/')'), confirm dispatch col3=scrollreset/col2=pop FUN_005d5b60/col1=commit FUN_005d0a40 (timer-gated scr+0x38/0x3a), up/down with 8-frame auto-repeat via dir table _DAT_00642db0. Pad-bit & keyboard-char names inferred from effect; delta table contents not dumped.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ce0e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
