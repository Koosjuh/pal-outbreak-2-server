# 0x005c39e0 room_enter_ack_cb

| field | value |
|---|---|
| Original address | 0x005c39e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c39e0 |
| Resolved name | room_enter_ack_cb |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005c7d00
**Referenced globals:** 0x6cba7d (SM reply flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam006cba7d

## Behavioral explanation
Reply callback for room_enter_commit_sm: status 0x00 -> 0x6cba7d=1 (ok), 0x27 -> 0x6cba7d=2 (fail).

## Notes / uncertainty
Trivial op0c PREPARE completion cb for 3490: status 0x00->signal 0x6cba7d=1, 0x27->2. Fully determined; only wire status codes uncaptured.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c39e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
