# 0x0061f8d0 net_conn_start_stop

| field | value |
|---|---|
| Original address | 0x0061f8d0 |
| Binary / overlay | 3.DAT |
| Module | overlay-3dat |
| Original generated name | FUN_0061f8d0 |
| Resolved name | net_conn_start_stop |
| Subsystem | session |
| Relevance | support |
| Status | classified (record from evidence-based classification; corrected pseudocode pending for non-core) |
| Confidence | High |
| Runtime validated | no |

**Callers:** FUN_005c80a0, FUN_006205c0, FUN_00620d60
**Callees:** FUN_0061e9c0, FUN_0061ea10, FUN_0061f0d0, FUN_0061f840
**Referenced globals:** 0x71530c session flag
**Referenced strings:** —
**Referenced opcodes:** —
**State vars:** uRam0071530c

## Behavioral explanation
Starts or stops the network connection by mode arg (0=full teardown+clear 0x71530c, 1/2=call 001a02d0 with 0/1); gated by stub f840.

## Notes / uncertainty
Mode-selected net control gated by busy guard FUN_0061f840: mode2->001a02d0(1), mode1->001a02d0(0), mode0->teardown (f0d0/ea10, clear 0x71530c, 001a0320 shutdown). Always returns 1. Control flow exact; 001a02d0 0/1 flag meaning inferred.

## Raw decompilation
`sources/overlays/overlay-3dat-decompile/FUN_0061f8d0.c`  — untouched decompiler output.

## Evidence
- Classified from the raw decompile via the fan-out pass (callers/callees/globals/strings/control-flow).
- Confidence **High**. Runtime validation pending. Promote to `reconstructed`/`validated` with corrected pseudocode + a trace.
