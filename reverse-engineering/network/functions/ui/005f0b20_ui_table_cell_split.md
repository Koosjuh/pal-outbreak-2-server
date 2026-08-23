# 0x005f0b20 ui_table_cell_split

| field | value |
|---|---|
| Original address | 0x005f0b20 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f0b20 |
| Resolved name | ui_table_cell_split |
| Subsystem | ui |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ebd20
**Callees:** FUN_005ef850
**Referenced globals:** +0xd892 depth; +0xd894/+0xd898 idx; +0x24e0 pool; +0x2527 span count, +0x2510/+0x2512 cell pad/margin
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0x186; +0xd892; +0xd898

## Behavioral explanation
Splits a table cell across (span-1) extra nodes (span count at +0x2527): allocates each, copies cell attrs, links them, advances flow cursors; pops depth per node.

## Notes / uncertainty
Table colspan materializer: allocates colspan-1 sibling cells, copies attrs in measure pass (0x186==0xF6), pops node stack per span. Element scratch fields +0x24fc/+0x2504/+0x2514 precise meaning unproven; no runtime trace.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f0b20.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
