# 0x005bc230 inroom_evt08_set_flag_6ff2af

| field | value |
|---|---|
| Original address | 0x005bc230 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bc230 |
| Resolved name | inroom_evt08_set_flag_6ff2af |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bba20
**Callees:** —
**Referenced globals:** 0x6ff2af (room state flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006ff2af

## Behavioral explanation
Sub-event 8: sets room state flag 0x6ff2af to 1 (a one-shot room-state marker).

## Notes / uncertainty
In-room dispatcher (FUN_005bba20) case 8: sets one-shot flag 0x6ff2af=1. Role/clear-site of the flag unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bc230.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
