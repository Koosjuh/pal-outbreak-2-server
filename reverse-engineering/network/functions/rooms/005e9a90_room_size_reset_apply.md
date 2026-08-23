# 0x005e9a90 room_size_reset_apply

| field | value |
|---|---|
| Original address | 0x005e9a90 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005e9a90 |
| Resolved name | room_size_reset_apply |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005ed1f0, FUN_005ef0e0
**Referenced globals:** 0x007012a0 (cfg base); cfg+0x8f2 (max, dflt 4); cfg+0x8f4 (count)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cfg+0x8f2; cfg+0x8f4

## Behavioral explanation
Applies arg, sets max=cfg+0x8f2=4 and cur=cfg+0x8f4=0, then FUN_005ed1f0(0).

## Notes / uncertainty
Markup element handler: ui_dialog_close_reset then max(0x8f2)=4, count(0x8f4)=0, redraw bullet. Baseline of the 0-of-4 room capacity display.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005e9a90.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
