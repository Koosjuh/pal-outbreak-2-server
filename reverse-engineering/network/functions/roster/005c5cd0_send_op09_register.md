# 0x005c5cd0 send_op09_register

| field | value |
|---|---|
| Original address | 0x005c5cd0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c5cd0 |
| Resolved name | send_op09_register |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c6500
**Callees:** —
**Referenced globals:** 0x6febac net-ctx
**Referenced strings:** —
**Referenced opcodes:** 0x09
**State vars:** —

## Behavioral explanation
Builds and sends a 4-byte reliable app-opcode 0x09 register packet to the target.

## Notes / uncertainty
op10-relay of inner op 0x09 (register), body-less. SM emits it only for candidates whose accept flag 0x6ff2b5[i]==0 (not-yet-acked); accepted members get op05 instead.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c5cd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
