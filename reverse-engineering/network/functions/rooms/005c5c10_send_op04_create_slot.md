# 0x005c5c10 send_op04_create_slot

| field | value |
|---|---|
| Original address | 0x005c5c10 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c5c10 |
| Resolved name | send_op04_create_slot |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bbf20
**Callees:** —
**Referenced globals:** 0x6febac net-ctx
**Referenced strings:** —
**Referenced opcodes:** 0x04
**State vars:** —

## Behavioral explanation
Builds and sends the reliable app-opcode 0x04 create-slot packet (full 0x304-byte body) to the target.

## Notes / uncertainty
Reliable app op04 create-slot; body is 0x304 ZEROS + opcode (no title/scenario fill here). Load-bearing for G12 create blocker: server must accept a zero-filled 0x304 op04.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c5c10.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
