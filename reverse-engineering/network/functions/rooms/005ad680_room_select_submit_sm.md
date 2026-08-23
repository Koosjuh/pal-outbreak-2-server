# 0x005ad680 room_select_submit_sm

| field | value |
|---|---|
| Original address | 0x005ad680 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005ad680 |
| Resolved name | room_select_submit_sm |
| Subsystem | rooms |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005ace00
**Callees:** FUN_005ad350, FUN_005adc80, FUN_005b14b0, FUN_005b68e0, FUN_005b6900, FUN_005b9060, FUN_005bf340, FUN_005bfa70
**Referenced globals:** 0x6c3860/0x6c3030(lists); 0x6c386e; 0x6c45fc/0x6c4600; obj +0xf/+0x42b/+0x992/+0x16
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Sub-screen 3 state machine (+0xf): re-clears the list arrays 0x6c3860/0x6c3030, pops a dialog (5bf340 cb 0x5ad890), then on select routes through FUN_005ad350.

## Notes / uncertainty
Genuine room UI. 8-state SM on obj+0xf: clears room-list buffers (0x6c3860/0x6c3030/0x6c386e x10), populates list (cb 0x5ad890), submits selection async (registers reply cb 0x5ad9f0=tag1 — CORRECTS prior 'registered in ad530'), fires reliable submit selector 0x14, polls result 0x210. Uncertainty: whether room/scenario/char selection; FUN_005ad350 semantics.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005ad680.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
