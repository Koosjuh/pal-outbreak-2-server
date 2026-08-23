# 0x005f23c0 ui_skip_whitespace

| field | value |
|---|---|
| Original address | 0x005f23c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f23c0 |
| Resolved name | ui_skip_whitespace |
| Subsystem | helpers |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f3420
**Callees:** —
**Referenced globals:** +0xd8de line-started flag; +0xd894 node idx; +0x2530 node flags; DAT_006494f0 char-class table
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0xd8de

## Behavioral explanation
Advances a text pointer past whitespace characters (char-class table DAT_006494f0 bit 2) when word-wrap is enabled and the node isn't preformatted.

## Notes / uncertainty
Word-wrap helper: skips collapsible whitespace (char-class DAT_006494f0 bit 0x2) unless line already has content or node preformatted. Node flag bit roles in +0x2530 inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f23c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
