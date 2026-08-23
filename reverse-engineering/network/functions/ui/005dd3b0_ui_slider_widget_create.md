# 0x005dd3b0 ui_slider_widget_create

| field | value |
|---|---|
| Original address | 0x005dd3b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005dd3b0 |
| Resolved name | ui_slider_widget_create |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005cd320
**Callees:** FUN_005dfde0
**Referenced globals:** iRam00701068 (overlay/browser context base; sets +0x68e85 active flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00701068+0x68e85 (widget-active flag)

## Behavioral explanation
On param==1, allocates a UI slider/cursor widget (via FUN_005dfde0), wires its update callback to FUN_005dd660 and seeds float screen coords (213.0/128.0) and animation state.

## Notes / uncertainty
Factory kind-6 vertical slider at 213,128; dir(+7)=1, flag 0x68e85=1 (read by cursor hit-test), tick cb FUN_005dd660.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005dd3b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
