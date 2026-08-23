# 0x005bbe00 inroom_set_member_count_c

| field | value |
|---|---|
| Original address | 0x005bbe00 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bbe00 |
| Resolved name | inroom_set_member_count_c |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bba20
**Callees:** FUN_005bdfe0, FUN_005bf1e0, FUN_005bf230
**Referenced globals:** 0x6cfb70 (per-area member count); 0x6fec00 (callback arg); 0x6cbc84 (UI status)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sub-event 0xc: writes the member count byte (payload+4) into the per-area count field (0x6cfb70), triggers FUN_005bf230(0x6fec00), and enqueues UI refresh (FUN_005bdfe0(0x21)).

## Notes / uncertainty
Sub-event 0xc: write count byte (payload+4) to 0x6cfb70, apply cast/scenario blob FUN_005bf230(0x6fec00), UI 0x21. Heavier sibling of 0x11. Exact FUN_005bf230 effect (cast/scenario apply) inferred from global role.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bbe00.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
