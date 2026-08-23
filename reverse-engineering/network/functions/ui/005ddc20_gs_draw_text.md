# 0x005ddc20 gs_draw_text

| field | value |
|---|---|
| Original address | 0x005ddc20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ddc20 |
| Resolved name | gs_draw_text |
| Subsystem | ui |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005dbca0, FUN_005dc010, FUN_005dd660, FUN_005e2060, FUN_005e2fa0, FUN_005e3a80, FUN_005e4b00, FUN_005e4f10, FUN_005e5200, FUN_005e5650
**Callees:** —
**Referenced globals:** 0x6433a0 (empty/sentinel string skipped)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam0028a450 (screen height clip bound)

## Behavioral explanation
Renders a string at (x,y) with color/size via GS font primitives (func_0x001af0xx), clipping vertically and escaping '%' into a 256-byte scratch buffer.

## Notes / uncertainty
Already fully reconstructed; verified. '%'->'%%' escape, vertical clip, sentinel skip all match raw. u64 param_3/param_5 ABI slots unused (padding/split struct).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ddc20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
