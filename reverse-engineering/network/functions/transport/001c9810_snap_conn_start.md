# 0x001c9810 snap_conn_start

| field | value |
|---|---|
| Original address | 0x001c9810 |
| Binary / overlay | SLES_533.19 |
| Module | main-ee |
| Original generated name | FUN_001c9810 |
| Resolved name | snap_conn_start |
| Subsystem | transport |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** —
**Callees:** FUN_001c3420
**Referenced globals:** 0x35ccb4=create flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** param_1+0xc=topstate; param_1+0xd8=phase

## Behavioral explanation
Kicks off a new connection: sets top-state 1, clears the create flag, invalidates the socket handle and calls FUN_001c3420 to arm the transport.

## Notes / uncertainty
Begins connect: phase(+0xd8)=1, top-state(+0xc)=1, arms via FUN_001c3420, invalidates socket, clears create flag 0x35ccb4. extraout_a0_lo is the FUN_001c3420 tail artifact (a0==conn). FUN_001c3420 mode arg 0 not decoded.

## Raw decompilation
`sources/executables/transport-decompile/FUN_001c9810.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
