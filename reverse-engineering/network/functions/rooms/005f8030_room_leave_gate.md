# 0x005f8030 room_leave_gate

| field | value |
|---|---|
| Original address | 0x005f8030 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005f8030 |
| Resolved name | room_leave_gate |
| Subsystem | rooms |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005f7800
**Callees:** FUN_005f8060
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param+0xf

## Behavioral explanation
Thin guard: when substate +0xf==0, runs the exit-room flow FUN_005f8060.

## Notes / uncertainty
Thin gate: if step +0xf==0 run leave flow 005f8060 (page 3). Assumes sub-flow advances +0xf to self-limit; 005f8060 not decoded.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005f8030.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
