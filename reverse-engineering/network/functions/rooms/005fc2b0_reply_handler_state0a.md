# 0x005fc2b0 reply_handler_state0a

| field | value |
|---|---|
| Original address | 0x005fc2b0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fc2b0 |
| Resolved name | reply_handler_state0a |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005be9a0, FUN_005f8d00
**Referenced globals:** cRam006c4fbb pending state; 0x6c550e/0x6c4b9f/0x6c4ba0 result flags; cRam006c4b90 mode
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fbb (==0x0a gate)

## Behavioral explanation
Op-reply handler (pending-state 0x0a): on ok(0) sets room-created/enter flags, on error(-1) shows dialog 0x14.

## Notes / uncertainty
Create/enter-commit reply cb (pending 0x6c4fbb==0x0a): success sets 0x6c550e=1 (creator=player1), 0x6c4b9f=1 (roster repaint), 0x6c4ba0=0; error -> dialog + prompt 0x14. PRIME cross-ref for the G12 create-room 1/0P blocker: if this 0-reply never arrives, count stays 0. Confirm 0x6c550e is the field the in-room header actually reads.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fc2b0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
