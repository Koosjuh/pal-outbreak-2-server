# 0x005c5ff0 send_op02

| field | value |
|---|---|
| Original address | 0x005c5ff0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c5ff0 |
| Resolved name | send_op02 |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c44a0
**Callees:** —
**Referenced globals:** 0x6febac net-ctx
**Referenced strings:** —
**Referenced opcodes:** 0x02
**State vars:** —

## Behavioral explanation
Builds and sends a 4-byte reliable app-opcode 0x02 packet to the target.

## Notes / uncertainty
Builds+sends a 4-byte reliable app opcode 0x02 (empty body) on 0x6febac with the 0x8000 reliable bit. op02 outside documented set; its handshake role inferred from the sign-in call site.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c5ff0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
