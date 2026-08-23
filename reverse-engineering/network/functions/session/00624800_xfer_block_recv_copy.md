# 0x00624800 xfer_block_recv_copy

| field | value |
|---|---|
| Original address | 0x00624800 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00624800 |
| Resolved name | xfer_block_recv_copy |
| Subsystem | session |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_00623be0
**Callees:** —
**Referenced globals:** 0x715298 struct ptr; 0x3c8a90 stage buffer
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** —

## Behavioral explanation
Checks a received transfer block (func_0x001f3540 on struct+0x174); if ready, copies 0x1d7c bytes into 0x3c8a90 and returns success.

## Notes / uncertainty
Recv-side: poll 001f3540(struct+0x174); if ready(==0) memcpy(global 0x3c8a90 <- recv buf, 0x1d7c); returns false when block delivered, true while pending. Consumed by FUN_00623be0 state 0x05. 001f3540 return space only 0/nonzero observed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00624800.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
