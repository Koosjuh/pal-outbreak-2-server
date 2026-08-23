# 0x005bc0e0 inroom_set_player_counts

| field | value |
|---|---|
| Original address | 0x005bc0e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005bc0e0 |
| Resolved name | inroom_set_player_counts |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bba20
**Callees:** —
**Referenced globals:** 0x6ff2b3/0x6ff2b4 (scenario-selection bytes)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006ff2b1

## Behavioral explanation
Sub-event 5: when in-room, copies two scenario-selection bytes (payload+5 and payload+4) into 0x6ff2b3/0x6ff2b4.

## Notes / uncertainty
op0x13 sub-5 == op10 sub-5 count push: gated on 0x6ff2b1, writes 0x6ff2b4=body+4 (max), 0x6ff2b3=body+5 (current). Directly the '1/0p' create-room count path. cur/max byte order follows field labels, not wire-confirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005bc0e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
