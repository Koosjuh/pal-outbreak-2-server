# 0x005bc350 inroom_evt0f_set_state_6ff2b2

| field | value |
|---|---|
| Original address | 0x005bc350 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bc350 |
| Resolved name | inroom_evt0f_set_state_6ff2b2 |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bba20
**Callees:** —
**Referenced globals:** 0x6ff2b2 (room/scenario state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006ff2b2

## Behavioral explanation
Sub-event 0xf: sets room/scenario state field 0x6ff2b2 to 3.

## Notes / uncertainty
Dispatcher case 0x0f: sets in-room state byte 0x6ff2b2=3 (adjacent to host_flag 0x6ff2b0 / unlock_gate 0x6ff2b1). Meaning of value 3 (scenario/cast phase?) inferred from adjacency, unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bc350.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
