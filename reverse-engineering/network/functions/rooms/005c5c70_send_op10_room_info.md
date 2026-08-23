# 0x005c5c70 send_op10_room_info

| field | value |
|---|---|
| Original address | 0x005c5c70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c5c70 |
| Resolved name | send_op10_room_info |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bbf20
**Callees:** —
**Referenced globals:** 0x6febac net-ctx
**Referenced strings:** —
**Referenced opcodes:** 0x10
**State vars:** —

## Behavioral explanation
Builds and sends the reliable app-opcode 0x10 room-info packet (0x304-byte body) to the target.

## Notes / uncertainty
Reliable app op10 room-info, 0x304 zero body (sub-selector left 0); paired with op04 in caller FUN_005bbf20. Meaningful op10 sub-selectors set by other emitters.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c5c70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
