# 0x00620d60 data_xfer_sm

| field | value |
|---|---|
| Original address | 0x00620d60 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00620d60 |
| Resolved name | data_xfer_sm |
| Subsystem | session |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005b2e40, FUN_00625670
**Callees:** FUN_0061e720, FUN_0061e750, FUN_0061e7f0, FUN_0061e800, FUN_0061e910, FUN_0061e940, FUN_0061e960, FUN_0061e9c0, FUN_0061ea10, FUN_0061ea20, FUN_0061f0d0, FUN_0061f0e0, FUN_0061f0f0, FUN_0061f180, FUN_0061f1a0, FUN_0061f1d0, FUN_0061f2d0, FUN_0061f3b0, FUN_0061f3d0, FUN_0061f450, FUN_0061f4b0, FUN_0061f680, FUN_0061f760, FUN_0061f8d0, FUN_0061f970, FUN_0061f9d0, FUN_00620570
**Referenced globals:** 0x715439 xfer state; 0x71543a substate; 0x343650/54/58 buf ptrs; 0x715364 xfer len; 0x715360 handle; 0x7152f5 mode
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** cRam00715439; cRam0071543a; sRam007152e4; sRam007152ea

## Behavioral explanation
Large 0x715439-keyed state machine that streams 0x8000-byte data blocks (buffers 0x380700/0x388700/0x390700) via external send/recv encode primitives, with retry/error branches.

## Notes / uncertainty
Bulk 0x8000-block streamer (triple buffer 0x380700/388700/390700) via codec 0x11e9xxx/0x12307xx; half-duplex direction flips via FUN_0061e750/720. Phase-grouped reconstruction; ~30 watchdog/flush states summarized, payload type not traced.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00620d60.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
