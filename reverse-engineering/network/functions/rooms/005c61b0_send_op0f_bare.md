# 0x005c61b0 send_op0f_bare

| field | value |
|---|---|
| Original address | 0x005c61b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c61b0 |
| Resolved name | send_op0f_bare |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bba20
**Callees:** —
**Referenced globals:** 0x6febac net-ctx
**Referenced strings:** —
**Referenced opcodes:** 0x0f
**State vars:** —

## Behavioral explanation
Builds and sends a 4-byte reliable app-opcode 0x0f packet to the target.

## Notes / uncertainty
Reliable app op0f, bare (len 4). Raw shows ZERO static callers (table-dispatched or dead); twin of op0e. Liveness in this build uncertain.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c61b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
