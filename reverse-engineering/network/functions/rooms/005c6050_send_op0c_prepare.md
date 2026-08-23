# 0x005c6050 send_op0c_prepare

| field | value |
|---|---|
| Original address | 0x005c6050 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c6050 |
| Resolved name | send_op0c_prepare |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bbc20
**Callees:** —
**Referenced globals:** 0x6febac net-ctx
**Referenced strings:** —
**Referenced opcodes:** 0x0c
**State vars:** —

## Behavioral explanation
Builds and sends the reliable app-opcode 0x0c prepare packet with a 4-byte payload to the target.

## Notes / uncertainty
Reliable app op0c PREPARE + 4-byte arg (len 8); paired with op11 in FUN_005bbc20. Which PREPARE observation maps here is open.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c6050.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
