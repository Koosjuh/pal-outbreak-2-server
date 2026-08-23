# 0x005c5eb0 send_op08

| field | value |
|---|---|
| Original address | 0x005c5eb0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c5eb0 |
| Resolved name | send_op08 |
| Subsystem | roster |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c6500
**Callees:** —
**Referenced globals:** 0x6febac net-ctx
**Referenced strings:** —
**Referenced opcodes:** 0x08
**State vars:** —

## Behavioral explanation
Builds and sends a 4-byte reliable app-opcode 0x08 leave packet to the target.

## Notes / uncertainty
Renamed from send_op08_leave: op10-relay of inner op 0x08, body-less, sent per member in the SM finalize phase (a sync-complete/commit marker) right before persisting name/charstats to 0x700710/0x700720/0x700734. 'leave' label loose.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c5eb0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
