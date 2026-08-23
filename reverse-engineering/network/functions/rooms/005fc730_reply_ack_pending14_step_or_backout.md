# 0x005fc730 reply_ack_pending14_step_or_backout

| field | value |
|---|---|
| Original address | 0x005fc730 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fc730 |
| Resolved name | reply_ack_pending14_step_or_backout |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005f6970
**Referenced globals:** cRam006c4fbb pending state; 0x6c4ba0 step ctr
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fbb (==0x14 gate)

## Behavioral explanation
Op-reply handler (pending-state 0x14): on ok increments step 0x6c4ba0, on error backs out via FUN_005f6970(4).

## Notes / uncertainty
Gate 0x14; nonzero=error. OK->step++; err->backout f6970(4). Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fc730.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
