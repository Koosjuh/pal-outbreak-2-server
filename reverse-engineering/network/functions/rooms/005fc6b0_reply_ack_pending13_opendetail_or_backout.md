# 0x005fc6b0 reply_ack_pending13_opendetail_or_backout

| field | value |
|---|---|
| Original address | 0x005fc6b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fc6b0 |
| Resolved name | reply_ack_pending13_opendetail_or_backout |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005f6970, FUN_005f8b50
**Referenced globals:** cRam006c4fbb pending state; 0x6c4600 selection
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fbb (==0x13 gate)

## Behavioral explanation
Op-reply handler (pending-state 0x13): on ok advances via FUN_005f8b50(sel), on error backs out via FUN_005f6970(4).

## Notes / uncertainty
Gate 0x13. OK->open room detail f8b50(selected 0x6c4600); err->backout f6970(4). Which op latched 0x13 unproven; runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fc6b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
