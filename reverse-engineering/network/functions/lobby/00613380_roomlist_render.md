# 0x00613380 roomlist_render

| field | value |
|---|---|
| Original address | 0x00613380 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00613380 |
| Resolved name | roomlist_render |
| Subsystem | lobby |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00612d10
**Callees:** FUN_006146e0, FUN_00614720
**Referenced globals:** 0x35c000 (room registry table); +0x14/+0x18 (room name/id strings); +0x8 (room type); fmt 0x6540f8; ctx+0x1d (scroll)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x35c000 room table

## Behavioral explanation
Renders the lobby room list from the global registry 0x35c000 (0x1c stride, 0x23 entries): for each live entry (+0=!-1, type +0x8) formats '+0x14 / +0x18' key strings (fmt 0x6540f8), colors by state, lists rows past scroll offset ctx+0x1d.

## Notes / uncertainty
Renders room list from registry 0x35c000 (0x1c stride, 35 slots): skip +0=-1, color by +0x8, draw +0=1 past scroll [0070d1c0+0x1d], fmt 0x6540f8(+0x14,+0x18) at (0x65,row*0x1c+0xc4). Created room must land in 0x35c000 to list. +0x14/+0x18 exact fields depend on undumped fmt.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00613380.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
