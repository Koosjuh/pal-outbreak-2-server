# 0x00631560 softkbd_layout_page_select

| field | value |
|---|---|
| Original address | 0x00631560 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00631560 |
| Resolved name | softkbd_layout_page_select |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006314a0
**Callees:** FUN_006322c0, FUN_00633470, FUN_00637140, FUN_00637260, FUN_00637540, FUN_00637690
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x2f IME state; +0x1e layout page; +0x35 flags; +0x4a flags; +0x36 IME-active; +0x248 result code

## Behavioral explanation
Layout page select (keys 0x3a-0x3c): sets layout index +0x1e via table (key-0x3a offset), refreshes grid and IME flag.

## Notes / uncertainty
Keys 0x3a/0x3b/0x3c: select layout page via FUN_00637260(key-0x3a); on success repaint + restart IME if +0x36 active; default result 5. Concrete page indices unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00631560.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
