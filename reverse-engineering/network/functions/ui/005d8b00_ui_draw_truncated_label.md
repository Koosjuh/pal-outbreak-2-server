# 0x005d8b00 ui_draw_truncated_label

| field | value |
|---|---|
| Original address | 0x005d8b00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d8b00 |
| Resolved name | ui_draw_truncated_label |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c8ed0, FUN_005ef4f0
**Callees:** FUN_005cab10
**Referenced globals:** —
**Referenced strings:** ' ...' (ellipsis bytes 0x20 0x2e 0x2e 0x2e)
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Truncates a label to <=0x3c chars appending ' ...' then draws it via FUN_005cab10 with fixed geometry.

## Notes / uncertainty
Truncates label in place to 60 chars + ' ...' (0x20 2e 2e 2e/NUL at +0x38) then draws style-0 at fixed (0x10,0x1ac). strlen arg elided in decompile (assumed param_1). Non-protocol.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d8b00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
