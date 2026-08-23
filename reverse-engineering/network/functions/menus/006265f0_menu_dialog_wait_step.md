# 0x006265f0 menu_dialog_wait_step

| field | value |
|---|---|
| Original address | 0x006265f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006265f0 |
| Resolved name | menu_dialog_wait_step |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00622180
**Callees:** FUN_0061e7f0, FUN_0061e910, FUN_0061e960, FUN_0061f0e0, FUN_0061f1a0, FUN_0061f1d0, FUN_0061f4b0, FUN_0061f760
**Referenced globals:** 0x86f864 gate-flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam007152e1 screen-phase; cRam0086f864 gate; uRam007152e4 timer

## Behavioral explanation
Small menu screen-step: shows a wait/confirm dialog gated on cRam0086f864, advances phases 0->1->2/3 via FUN_0061e910 poll.

## Notes / uncertainty
Show-message-and-wait dialog gated on 0x86f864; phases 0->1->2/3, returns 1/-1. Byte-for-byte sibling of FUN_00627400 (differs only in gate global).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006265f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
