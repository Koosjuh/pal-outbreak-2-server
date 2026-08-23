# 0x005c7ae0 async_stage_poll_b

| field | value |
|---|---|
| Original address | 0x005c7ae0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c7ae0 |
| Resolved name | async_stage_poll_b |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** FUN_005c7a00
**Callees:** —
**Referenced globals:** 0x700fd0 (stage flag); 0x700fc8/0x700fc0; 0x35bed8
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x700fd0

## Behavioral explanation
Inner async stage: calls func_0x001c08e0 with the room entry ptr, returns pending/done/error, advancing 0x700fd0.

## Notes / uncertainty
3-state poll (0 arm,1 poll,2 done) over lib async-op func_0x001c08e0; returns 1/0/-1. On -1 stage is NOT advanced. What the glue op resolves + the 0x35bed8 template shape unknown.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c7ae0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
