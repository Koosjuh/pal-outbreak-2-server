# 0x005c60d0 send_op11_word

| field | value |
|---|---|
| Original address | 0x005c60d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c60d0 |
| Resolved name | send_op11_word |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005bb610, FUN_005bbc20
**Callees:** —
**Referenced globals:** 0x6febac net-ctx
**Referenced strings:** —
**Referenced opcodes:** 0x11
**State vars:** —

## Behavioral explanation
Builds and sends a reliable app-opcode 0x11 packet with a 4-byte payload to the target.

## Notes / uncertainty
Reliable app op11 + 4-byte arg (len 8); 2 callers incl. FUN_005bbc20 (after op0c). Role (prepare-ack/commit) inferred from call adjacency, not wire.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c60d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
