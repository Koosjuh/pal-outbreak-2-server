# 0x001c3380 netbuf_step_dispatch

| field | value |
|---|---|
| Original address | 0x001c3380 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c3380 |
| Resolved name | netbuf_step_dispatch |
| Subsystem | transport |
| Relevance | core |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | Medium |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001069a8
**Referenced globals:** 0x2487c0 step-vtable; 0x365acc state-idx; 0x365b98 status-out
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x365acc

## Behavioral explanation
Per-tick driver of the connection object: syncs (func_0x005c7d00) then dispatches PTR_FUN_002487c0[state 0x365acc] and copies a 0x14-byte status result out.

## Notes / uncertainty
Vtable-driven step driver: sync hook + PTR_FUN_002487c0[cRam00365acc] dispatch + 0x14-byte status copy from 0x365b98. Step-handler signature and status-block meaning inferred; branching lives in the unread vtable targets.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c3380.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **Medium**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
