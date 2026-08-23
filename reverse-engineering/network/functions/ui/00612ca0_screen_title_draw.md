# 0x00612ca0 screen_title_draw

| field | value |
|---|---|
| Original address | 0x00612ca0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00612ca0 |
| Resolved name | screen_title_draw |
| Subsystem | ui |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_0060f910
**Callees:** FUN_0060f830, FUN_006146e0, FUN_00614720, FUN_006147a0
**Referenced globals:** 0x653f90 (per-lang title strings); ctx+0x4c (title id)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** ctx+0x4c title id

## Behavioral explanation
Draws the screen title bar: sets color, looks up localized title string (FUN_0060f830 on table 0x653f90 indexed by ctx+0x4c), centers it (FUN_006147a0 width), blits at y=0x20.

## Notes / uncertainty
Centered title header: color 0x80008080, lookup 0x653f90[lang][ctx+0x4c], center via 006147a0(size 0x16), draw y=0x20, restore 0x80808080. Color channel order unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00612ca0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
