# 0x005fc7c0 reply_ack_pending11_errctx_dialog14

| field | value |
|---|---|
| Original address | 0x005fc7c0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005fc7c0 |
| Resolved name | reply_ack_pending11_errctx_dialog14 |
| Subsystem | rooms |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_005be9a0, FUN_005f8d00
**Referenced globals:** cRam006c4fbb pending state; 0x6c4ba0 step ctr
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam006c4fbb (==0x11 gate)

## Behavioral explanation
Op-reply handler (pending-state 0x11): on ok increments 0x6c4ba0, on error shows dialog 0x14.

## Notes / uncertainty
Gate 0x11 = pending ENTER (per lobby_state_block). OK->step++; err->reset errctx be9a0(0x6c517c) + dialog f8d00(0x14). Exact enter wire op not proven here; runtime-unvalidated.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005fc7c0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
