# 0x005de820 heap_find_free_node

| field | value |
|---|---|
| Original address | 0x005de820 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005de820 |
| Resolved name | heap_find_free_node |
| Subsystem | helpers |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005de8d0
**Callees:** —
**Referenced globals:** iRam00701068+0x4db70 (node table)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Scans up to 0x200 fixed 0xc-byte slots at +0x4db70 for a free (size==0) block-descriptor and returns it.

## Notes / uncertainty
Already reconstructed; linear scan of 512 slots for size==0, verified. Complete.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005de820.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
