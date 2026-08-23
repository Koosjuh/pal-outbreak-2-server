# 0x005acea0 screen0_init_clear_lists

| field | value |
|---|---|
| Original address | 0x005acea0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005acea0 |
| Resolved name | screen0_init_clear_lists |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ace00
**Callees:** FUN_005af120, FUN_005af2f0, FUN_005b2470, FUN_005b68e0, FUN_005b6900, FUN_005bf340, FUN_005f4b70, FUN_00618b60
**Referenced globals:** 0x6c3860(list A,10x0x15c); 0x6c3030(list B,10x0x15c); 0x6c386e(entry type); 0x6c45f8/0x6c45fc/0x6c4600(sel); 0x6c45f8
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c45f8

## Behavioral explanation
Sub-screen 0 state machine (+0xf): on entry zeroes the two 10-entry list arrays 0x6c3860(0xd98) and 0x6c3030(0x828) and clears each entry's type byte, resetting the room/roster tables.

## Notes / uncertainty
Room-list screen init SM on +0xf: zeroes list tables 0x6c3860(0xd98)/0x6c3030(0x828), clears 10 entry-type bytes (stride 0x15c), installs input map 0x5ad890. List-A vs list-B roles inferred from clear-size.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005acea0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
