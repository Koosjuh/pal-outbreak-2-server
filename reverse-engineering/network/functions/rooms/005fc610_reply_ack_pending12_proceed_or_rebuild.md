# 0x005fc610 reply_ack_pending12_proceed_or_rebuild

| field | value |
|---|---|
| Original address | 0x005fc610 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fc610 |
| Resolved name | reply_ack_pending12_proceed_or_rebuild |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005b9110, FUN_005f7610
**Referenced globals:** cRam006c4fbb pending state; 0x6c4b9f/0x6c4ba0/0x6c4ba1 list flags
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fbb (==0x12 gate)

## Behavioral explanation
Op-reply handler (pending-state 0x12): on ok calls FUN_005f7610 (proceed), on error resets the list flags and rebuilds.

## Notes / uncertainty
Gate 0x12; clears tag up-front so any nonzero=error. OK->FUN_005f7610 proceed; err->reset 3 list counters (6c4b9f/ba0/ba1) + overlay rebuild b9110(0x4c). Runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fc610.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
