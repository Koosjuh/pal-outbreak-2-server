# 0x005fc520 reply_ack_pending0f_step_or_dialog48

| field | value |
|---|---|
| Original address | 0x005fc520 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fc520 |
| Resolved name | reply_ack_pending0f_step_or_dialog48 |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005f8d00
**Referenced globals:** cRam006c4fbb pending state; 0x6c4ba0 step ctr
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fbb (==0x0f gate)

## Behavioral explanation
Op-reply handler (pending-state 0x0f): on ok increments 0x6c4ba0, on error shows dialog 0x48.

## Notes / uncertainty
Byte-identical to fc360 with gate tag 0x0f. OK->step++, err(0xff)->dialog 0x48. Concrete op behind 0x0f unproven; runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fc520.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
