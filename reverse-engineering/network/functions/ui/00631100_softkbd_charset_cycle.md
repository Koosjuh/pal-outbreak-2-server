# 0x00631100 softkbd_charset_cycle

| field | value |
|---|---|
| Original address | 0x00631100 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00631100 |
| Resolved name | softkbd_charset_cycle |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006300a0
**Callees:** FUN_00631240, FUN_00637140, FUN_00637540, FUN_00637690
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x1e layout page; +0x20 charset caps; +0x33 flags; +0x4a flags; +0x248 result code

## Behavioral explanation
Keyboard layout/page cycle (key 0x39): advances +0x1e layout index subject to charset-capability bits, then refreshes the grid.

## Notes / uncertainty
Renamed from layout_cycle. Cycle-charset key (0x39): switch on +0x1e page choosing next available page from caps +0x20, or toggle shift bit ^8. Concrete page->script identities unresolved.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00631100.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
