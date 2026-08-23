# 0x005f3ff0 screen2_state_dispatch

| field | value |
|---|---|
| Original address | 0x005f3ff0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f3ff0 |
| Resolved name | screen2_state_dispatch |
| Subsystem | menus |
| Relevance | unrelated |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005f4040, FUN_005f41e0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+0x08

## Behavioral explanation
Second screen-object dispatcher: on state byte+8 calls tick (=1) or init (=0).

## Notes / uncertainty
Second scene pump mirroring 005f3de0: phase +0x08 => 1 tick(005f41e0)/0 init-SM(005f4040).

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f3ff0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
