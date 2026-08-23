# 0x001ca3a0 snap_socket_close_state6

| field | value |
|---|---|
| Original address | 0x001ca3a0 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001ca3a0 |
| Resolved name | snap_socket_close_state6 |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001ee650, FUN_001ee680
**Referenced globals:** —
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+0xc=topstate; param_1+0x1c=socket

## Behavioral explanation
Closes/frees the socket (FUN_001ee650/680) and sets top-state to 6 (closing), clearing substate.

## Notes / uncertainty
Teardown transition: unconditional socket close/free, top-state(+0xc)=6 closing, sub-state/timer cleared. Unguarded close assumes valid handle on entry.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001ca3a0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
