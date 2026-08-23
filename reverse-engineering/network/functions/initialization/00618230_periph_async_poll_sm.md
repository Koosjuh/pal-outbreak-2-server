# 0x00618230 periph_async_poll_sm

| field | value |
|---|---|
| Original address | 0x00618230 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00618230 |
| Resolved name | periph_async_poll_sm |
| Subsystem | initialization |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Low |
| Runtime validated | no |

**Callers:** FUN_006101d0, FUN_00610830, FUN_00612020, FUN_006120a0
**Callees:** —
**Referenced globals:** 0x3435bc (device base offset)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** +0 state (0/1/2); +2/+3 result bitmask

## Behavioral explanation
Async open->poll->result state machine on a device (0x1f45e0/0x1f4630/0x1f5620/0x1f5630 family): state0 issues open, state1 polls a status and folds result codes into a +2/+3 bitmask, state2 confirms; returns the combined mask.

## Notes / uncertainty
3-state open->issue->poll SM over 0x1f4/0x1f5 async API, reads into iRam003435bc+0x2ff000, folds result codes into +2/+3 mask. Control flow recovered but device (storage/DNAS/memcard?) unidentified; not on SNAP wire.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00618230.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Low**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
