# 0x005f6aa0 connect_flow_router

| field | value |
|---|---|
| Original address | 0x005f6aa0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f6aa0 |
| Resolved name | connect_flow_router |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005acab0
**Callees:** FUN_005f6b00, FUN_005f6d20
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+0x10 (flow selector)

## Behavioral explanation
Top-level router: dispatches on the mode byte *(param+0x10) — modes 0-2 to FUN_005f6b00, modes 3-7 to FUN_005f6d20 (the two connect/join flow state machines).

## Notes / uncertainty
Switch on flow+0x10 phase: 0-2 -> FUN_005f6b00 (early), 3-7 -> FUN_005f6d20 (late); other = idle. Per-phase-value meaning lives in the two sub-pumps, not decoded here.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f6aa0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
