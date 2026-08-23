# 0x005c7540 status_bcast_phase2_dispatch

| field | value |
|---|---|
| Original address | 0x005c7540 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c7540 |
| Resolved name | status_bcast_phase2_dispatch |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c7210
**Callees:** FUN_005c75b0, FUN_005c75d0, FUN_005c76e0
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** context+0x21

## Behavioral explanation
Phase-2 sub-dispatch on context+0x21: 0=>init(75b0), 1=>build/send(75d0), 2=>advance(76e0).

## Notes / uncertainty
Phase-2 sub-dispatch on ctx+0x21: 0=init(75b0),1=send(75d0),2=advance(76e0). Send builder 75d0 not decompiled.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c7540.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
