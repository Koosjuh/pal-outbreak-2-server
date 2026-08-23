# 0x00606980 lobby_conn_state_advance

| field | value |
|---|---|
| Original address | 0x00606980 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_00606980 |
| Resolved name | lobby_conn_state_advance |
| Subsystem | session |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_006063c0
**Callees:** —
**Referenced globals:** sRam0070cdc8 (state)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** sRam0070cdc8

## Behavioral explanation
State-5 step: trivially increments the connection state counter to proceed.

## Notes / uncertainty
Trivial: increments SM step counter sRam0070cdc8. Which case index in FUN_006063c0 it registers at is undecoded, but the increment is unambiguous.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_00606980.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
