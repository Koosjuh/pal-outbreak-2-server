# 0x005d47f0 roster_line_compose

| field | value |
|---|---|
| Original address | 0x005d47f0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005d47f0 |
| Resolved name | roster_line_compose |
| Subsystem | roster |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005d1e80
**Callees:** FUN_005d59f0, FUN_005d5a40, FUN_005d5c20, FUN_005d5cc0, FUN_005d7410, FUN_005d74a0, FUN_005d7540, FUN_005d7690
**Referenced globals:** 0x701068+0x5ffc0 entity array; 0x701070+0x55d/0x56e/0x5b2 name buffers; 0x701070+0x2c/0x2e screen state; 0x701078+0x20 selected
**Referenced strings:** str@0x642f80; str@0x642f88; str@0x642f90; str@0x642f98; str@0x642fa0; str@0x642fa8; str@0x642fb8
**Referenced opcodes:** —
**State vars:** 0x701070+0x2e; 0x701068+0x60dc5

## Behavioral explanation
Concatenates a display line from list entries (kinds 0x06-0x08,0x0b,0x0c,0x14) with separator strings, capturing names into the 0x55d/0x56e/0x5b2 buffers, then sets the label and returns to list.

## Notes / uncertainty
Large event/notification line composer over 500-slot entity ring; aggregate vs single-entity paths, name capture by class, sentinel truncation. Shape solid but several per-kind guards + string literals @0x642f8x unresolved; entity struct inferred. Presentation, not wire.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005d47f0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
