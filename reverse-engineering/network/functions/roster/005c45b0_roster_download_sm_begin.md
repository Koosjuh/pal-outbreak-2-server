# 0x005c45b0 roster_download_sm_begin

| field | value |
|---|---|
| Original address | 0x005c45b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c45b0 |
| Resolved name | roster_download_sm_begin |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_00616d30, FUN_006173c0
**Callees:** —
**Referenced globals:** 0x6cbaa4 (SM busy flag); 0x6cba80 (tick fn ptr); 0x6cba84 (completion cb); 0x6cbaa0 (state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006cbaa4

## Behavioral explanation
Starts the member/roster download state machine: guards on 0x6cbaa4, registers tick fn pcRam006cba80=FUN_005c4760 and the completion callback (0x6cba84), enters state 0.

## Notes / uncertainty
Single-instance start guard: if !busy(0x6cbaa4) installs tick FUN_005c4760, state 0, stores completion cb 0x6cba84, returns 0; else -1. Caller create-vs-join mapping untraced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c45b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
