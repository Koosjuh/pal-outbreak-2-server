# 0x006320f0 softkbd_insert_string_fit_width

| field | value |
|---|---|
| Original address | 0x006320f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_006320f0 |
| Resolved name | softkbd_insert_string_fit_width |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00630750, FUN_00630c90, FUN_00631ff0, FUN_006334f0, FUN_00634ab0, FUN_006353e0, FUN_006355a0, FUN_00635ab0, FUN_006378b0
**Callees:** FUN_00634160, FUN_006341d0, FUN_00634280, FUN_00634310, FUN_00637d10, FUN_00637e10, FUN_00637ed0
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x4a8 width-mode flag

## Behavioral explanation
Inserts a UTF-16 string into a buffer at a cursor, truncating the source to fit a pixel/column width budget (two width modes via +0x4a8) before splicing.

## Notes / uncertainty
Truncates src to width budget (two modes via +0x4a8) then splices dst=prefix+src+tail. Declared void but returns inserted col count via FUN_00634160 (inferred prototype).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_006320f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
