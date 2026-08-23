# 0x001dbdd0 snap_get_peer_id

| field | value |
|---|---|
| Original address | 0x001dbdd0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001dbdd0 |
| Resolved name | snap_get_peer_id |
| Subsystem | session |
| Relevance | helper |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** —
**Referenced globals:** 0x0025b78c(conn-ptr); 0x0025b790(errno); conn+0x508(peer id)
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** DAT_0025b790(errno)

## Behavioral explanation
Getter: returns *(conn+0x508) (peer/session id captured in the connect reply) when session param_1==1, else errno 0x64/-1.

## Notes / uncertainty
Getter for conn+0x508 peer/session id; else errno 0x25b790=100, -1. Which reply writes +0x508 inferred, not confirmed.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001dbdd0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
