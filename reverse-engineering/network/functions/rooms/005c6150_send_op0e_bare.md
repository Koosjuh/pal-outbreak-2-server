# 0x005c6150 send_op0e_bare

| field | value |
|---|---|
| Original address | 0x005c6150 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c6150 |
| Resolved name | send_op0e_bare |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005be330
**Callees:** —
**Referenced globals:** 0x6febac net-ctx
**Referenced strings:** —
**Referenced opcodes:** 0x0e
**State vars:** —

## Behavioral explanation
Builds and sends a 4-byte reliable app-opcode 0x0e packet to the target.

## Notes / uncertainty
Reliable app op0e, bare (len 4, no payload). Twin of op0f. op0e not in wire list; signal role inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c6150.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
