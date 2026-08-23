# 0x005c4580 unlock_scenario_select

| field | value |
|---|---|
| Original address | 0x005c4580 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c4580 |
| Resolved name | unlock_scenario_select |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005fede0, FUN_0062e5b0
**Callees:** FUN_005bdf90
**Referenced globals:** 0x6ff2b1 (scenario/title lock state, set=3)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006ff2b1

## Behavioral explanation
Sets the ownership state uRam006ff2b1=3 (unlocks title/pw/scenario/char editing) and triggers bdf90(1,0).

## Notes / uncertainty
Sets lobby unlock_gate 0x6ff2b1=3 (title/pw/scenario/cast editable) + FUN_005bdf90(1,0) redraw. Fully determined; no packet. Uncertainty: which caller = host-create vs joiner-enter.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c4580.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
