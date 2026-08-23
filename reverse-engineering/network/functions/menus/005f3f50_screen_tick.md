# 0x005f3f50 screen_tick

| field | value |
|---|---|
| Original address | 0x005f3f50 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f3f50 |
| Resolved name | screen_tick |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f3de0
**Callees:** FUN_005f4770, FUN_005f47a0, FUN_00621f10, FUN_0062ff30, FUN_00637970
**Referenced globals:** iRam00701f30(scene active flag); iRam00701f28(frame counter)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** iRam00701f30; iRam00701f28

## Behavioral explanation
Per-frame scene tick: advances a frame counter (0x1a5e0/0x1a5ea gates) and calls draw/update.

## Notes / uncertainty
Per-frame scene update + timed events at frame counts 0x1a5e0/0x1a5ea (attract/timeout, +10 frames) when active flag=1; then draw trio. Timed-event meaning inferred from large counts.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f3f50.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
