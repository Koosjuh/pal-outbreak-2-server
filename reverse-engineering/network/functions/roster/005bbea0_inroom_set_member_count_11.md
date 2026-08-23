# 0x005bbea0 inroom_set_member_count_11

| field | value |
|---|---|
| Original address | 0x005bbea0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bbea0 |
| Resolved name | inroom_set_member_count_11 |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bba20
**Callees:** FUN_005bdfe0, FUN_005bf1e0
**Referenced globals:** 0x6cfb70 (per-area member count); 0x6cbc7e/0x6cbc84 (UI status)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sub-event 0x11: writes the member count byte (payload+4) into the per-area count field (0x6cfb70) and enqueues a UI refresh (FUN_005bdfe0(0x21)); a lighter variant of FUN_005bbe00 without the callback.

## Notes / uncertainty
Sub-event 0x11: count-only update (payload+4 -> 0x6cfb70), UI 0x21. Strict subset of 0xc without the cast/scenario apply. Likely 0xc=count+cast, 0x11=count-only heartbeat; not runtime-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bbea0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
