# 0x005b4da0 screen_element_render

| field | value |
|---|---|
| Original address | 0x005b4da0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005b4da0 |
| Resolved name | screen_element_render |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005af1e0, FUN_005af2c0, FUN_005af2e0, FUN_00618c20, FUN_0062fd60, FUN_0062fea0
**Referenced globals:** 0x6c4634 host/room-name table; 0x6c4674 player-name table; 0x6c5497 cRam006c5497 highlighted slot; 0x6c4fcd layout id; 0x638e58 fmt string
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** element+2 render type; element+4 sub-state

## Behavioral explanation
Per-element render callback (installed via +0xc): draws the various lobby/room screens by element type +2, including case 9 = the 3-slot room roster (host names 0x6c4634 / player names 0x6c4674).

## Notes / uncertainty
Per-element render cb with init/render/teardown SM on +4; type switch at +2. Type 9 = 3-slot room roster (host names 0x6c4634 stride0x10 / player names 0x6c4674 stride0x14, empty->placeholder FUN_0062fea0(8)) — the create-room 1/0p render path. Label-descriptor layout inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005b4da0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
