# 0x005d9ea0 ui_store_label_text

| field | value |
|---|---|
| Original address | 0x005d9ea0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d9ea0 |
| Resolved name | ui_store_label_text |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005e67a0
**Callees:** —
**Referenced globals:** iRam00701080: UI label/text table (typed slots)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
UI text-table store: copies a caller string (length-clamped per widget type) into the label buffer iRam00701080 at a per-type/index offset; switch over widget types 1..0x12.

## Notes / uncertainty
strncpy into typed label-table slots (iRam00701080); full type->offset/cap/stride table recovered (stride==cap+1). Which type is room-name vs roster text not proven.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d9ea0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
