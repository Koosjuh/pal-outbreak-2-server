# 0x005c84e0 net_session_context_teardown

| field | value |
|---|---|
| Original address | 0x005c84e0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_005c84e0 |
| Resolved name | net_session_context_teardown |
| Subsystem | initialization |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005ac380, FUN_00624c70
**Callees:** FUN_005d7090, FUN_00637180
**Referenced globals:** 0x34358b (subsystem-active flag)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** 0x34358b

## Behavioral explanation
Shuts down the network-session subsystem: FUN_005d7090 + FUN_00637180 teardown, clears 0x34358b, releases resource slots.

## Notes / uncertainty
Straight-line net-session shutdown: list layer + netlib thunk + subsystem teardown, clears active flag 0x34358b, frees resource slots 7 and 1. Whether 01212940 issues wire disconnect unconfirmed.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_005c84e0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
