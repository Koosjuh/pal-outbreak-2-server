# 0x005ac4c0 menu_confirm_dialog_step

| field | value |
|---|---|
| Original address | 0x005ac4c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ac4c0 |
| Resolved name | menu_confirm_dialog_step |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ac8a0
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0
**Referenced globals:** 0x3434a0(pad buttons); 0x6c4fab; 0x6c4faa; 0x6c4ba6(timer); 0x874f35; 0x874f33; 0x6387e0/0x638800/0x638820(text ptrs)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fab; uRam006c4faa; uRam003434a0

## Behavioral explanation
Top-state 0x17 step: countdown via fab/timer then reads pad bitmask (0x10,0x200) to branch and draws 3 text lines.

## Notes / uncertainty
Renamed from menu_state23_input. Confirm dialog: 10-frame intro delay then pad bit 0x10=accept(->874f33=1)/0x200=cancel(->0)=result, returns to top_screen 1; skip flag 0x874f35 bypasses. Draws 3 text lines. Which physical buttons + prompt strings unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ac4c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
