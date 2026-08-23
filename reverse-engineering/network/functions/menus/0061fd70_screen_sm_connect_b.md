# 0x0061fd70 screen_sm_connect_b

| field | value |
|---|---|
| Original address | 0x0061fd70 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061fd70 |
| Resolved name | screen_sm_connect_b |
| Subsystem | menus |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00622180
**Callees:** FUN_0061d6a0, FUN_0061e720, FUN_0061e750, FUN_0061e7f0, FUN_0061e800, FUN_0061e940, FUN_0061ea30, FUN_0061f0f0, FUN_0061f180, FUN_0061f1b0, FUN_0061f1f0, FUN_0061f220, FUN_0061f2d0, FUN_0061f4b0, FUN_0061f680, FUN_0061f760, FUN_0061f8c0, FUN_0061f970, FUN_0061f9d0
**Referenced globals:** 0x7152e1 substate; 0x7152e4 timer; 0x7152ea link dir; 0x3c9580 link buffer
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam007152e1; sRam007152e4; sRam007152ea

## Behavioral explanation
Per-screen state machine for a second connect/retry screen: draws elements, retries on timeout via e7f0/e800, branches on link-direction flag 0x7152ea.

## Notes / uncertainty
Link handshake + Yes/No; stages 16B link buffer 0x3c9580<->0x715280 and clears 0x874f30 session block; gated by link_poll FUN_0061d6a0. Confirm polarity ea==0=proceed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061fd70.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
