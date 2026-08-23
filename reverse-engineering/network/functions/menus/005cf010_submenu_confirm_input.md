# 0x005cf010 submenu_confirm_input

| field | value |
|---|---|
| Original address | 0x005cf010 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005cf010 |
| Resolved name | submenu_confirm_input |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005d5b60, FUN_005d5c20, FUN_005d5ed0, FUN_005d5f40, FUN_0061e730
**Referenced globals:** 0x701068+0x4f8a4 buttons; 0x715da8+0x49c keyboard; 0x701078+2 selection; 0x870f10 record dst; 0x701088 record src; 0x701e18 result sel
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x701070+0x2e; 0x701078+2

## Behavioral explanation
Sub-menu input handler: FUN_005d5f40(2) refresh, on pad either scrolls (FUN_005d5ed0), copies a 0x1d0 record to 0x870f10 and sends (FUN_005d5c20) / pops (FUN_005d5b60).

## Notes / uncertainty
2-option confirm: cur[2]==1 memcpy's 0x1d0 record *0x701088 -> send buffer 0x870f10 then send FUN_005d5c20 (if scr+0x2e==8) or pop w/ uRam00701e18=1; cur[2]==2 scroll. Which opcode FUN_005d5c20 emits unresolved (record=464B payload).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005cf010.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
