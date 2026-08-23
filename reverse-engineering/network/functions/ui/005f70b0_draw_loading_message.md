# 0x005f70b0 draw_loading_message

| field | value |
|---|---|
| Original address | 0x005f70b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f70b0 |
| Resolved name | draw_loading_message |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f7270
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_0062fea0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Renders a centered 'please wait' style message string (random line via FUN_0062fea0(0x11)) when the mode byte is 5/3/1; two identical branches on the param_1 pointer.

## Notes / uncertainty
Draws centered localized wait string 0x11 at (320,352) scale 2 for modes {1,3,5}. Two param_1 arms are byte-identical in decompile (folded side effect?); string text not captured.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f70b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
