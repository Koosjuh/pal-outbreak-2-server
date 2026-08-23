# 0x00631240 softkbd_shift_page_adjust

| field | value |
|---|---|
| Original address | 0x00631240 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00631240 |
| Resolved name | softkbd_shift_page_adjust |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00631100
**Callees:** —
**Referenced globals:** iRam00715da8 (widget state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x1e layout page; +0x33 flags; +0x20 charset caps

## Behavioral explanation
Helper for the layout cycle: OR-sets bit 8 into layout index +0x1e for certain pages when caps permit.

## Notes / uncertainty
Leaf helper of charset_cycle: OR-sets shift bit 0x08 into +0x1e for base pages 2/6/7 when caps (+0x20 bit page+8) and +0x33 shift-lock permit. Caps bit layout inferred from shared arithmetic.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00631240.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
