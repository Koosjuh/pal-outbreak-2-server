# 0x005c72d0 status_bcast_phase1_dispatch

| field | value |
|---|---|
| Original address | 0x005c72d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c72d0 |
| Resolved name | status_bcast_phase1_dispatch |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c7210
**Callees:** FUN_005c7320, FUN_005c7420
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Phase-1 sub-dispatch on context+0x21: 0=>build/send (7320), 1=>advance/loop (7420).

## Notes / uncertainty
Phase-1 sub-dispatch on ctx+0x21: 0=send page(7320), 1=advance(7420). Send builder 7320 not decompiled.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c72d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
